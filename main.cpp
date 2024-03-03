
#include <ncurses.h>
#include <string>
#include <sstream>
#include <locale.h>
#include <time.h>
#include <thread>
#include <chrono>


#define BLACK 0
#define DARKRED 1
#define DARKGREEN 2
#define DARKYELLOW 3
#define DARKBLUE 4
#define DARKMAGENTA 5
#define DARKCYAN 6
#define LIGHTGRAY 15
#define DARKGRAY 8
#define LIGHTRED 9
#define LIGHTGREEN 10
#define LIGHTYELLOW 11
#define LIGHTBLUE 12
#define LIGHTMAGENTA 13
#define LIGHTCYAN 14
#define WHITE 7

using str = std::string;

str planetName = "I don't know yet";
str mountainName = "Mt. Cheesecutter";


int termx, termy;

void threaddelay(size_t microseconds) {
	std::this_thread::sleep_for(std::chrono::microseconds(microseconds));
};

int middle(int chars) {
	return termx/2-chars/2;
};

int middle(int chars, int winx) {
	return winx/2-chars/2;
};


void game() {
	clear();
	WINDOW* storyPrompt = newwin(10, 80, middle(10, termy), middle(80));
	refresh();
	wrefresh(storyPrompt);
	wprintw(storyPrompt, "On the planet of %s,", planetName.c_str());
	wgetch(storyPrompt);
	wprintw(storyPrompt, " goblins come in many different colors!");
	wgetch(storyPrompt);
	wprintw(storyPrompt, "\nBut most of them are red or blue.");
	wgetch(storyPrompt);
	wprintw(storyPrompt, " Red and blue goblins hate eachother.");
	wgetch(storyPrompt);
	wprintw(storyPrompt, "\nBut one day a yellow Goblin was born, and their name is...\nName: ");
	str name = "";
	char pchar;
	keypad(storyPrompt, true);
	int key = wgetch(storyPrompt);
	while(key != 10) {
		if(key == KEY_BACKSPACE) {
			if(name.length() > 0) {
			name.pop_back();
			int wx = getmaxx(storyPrompt);
			move(getcury(storyPrompt), 0);
			wclrtoeol(storyPrompt);
			mvwprintw(storyPrompt, getcury(storyPrompt), 6, "%s", name.c_str());
			}
		} else {
			name.push_back((char)key);
			waddch(storyPrompt, (char)key);
		}
		key = wgetch(storyPrompt);
	}

	wprintw(storyPrompt, "\nPronouns: he/him[h] she/her[s]  they/them[t]");
	
chooseNoun:
	int pronoun = wgetch(storyPrompt);

	std::array<str, 4> pronouns;

	switch ((char)pronoun)
	{
	case 'h':
	case 'H':
		pronouns = {"he", "him", "his", "his"};
		break;
	
	case 's':
	case 'S':
		pronouns = {"she", "her", "her", "hers"};
		break;

	case 't':
	case 'T':
		pronouns = {"they", "them", "their", "thiers"};
		break;
	
	default:
		goto chooseNoun;
	}
	
	wprintw(storyPrompt, "\nOk %s name is %s.", pronouns[2].c_str(), name.c_str());
	wgetch(storyPrompt);
	wprintw(storyPrompt, "\nBeing yellow %s was banished from goblin society.", name.c_str());
	wgetch(storyPrompt);
	wprintw(storyPrompt, "\n%s is now cold and alone on %s", pronouns[0].c_str(), mountainName.c_str());
	wgetch(storyPrompt);

};


int main(int argc, char** argv) {

	setlocale(LC_ALL, "");

	initscr();
	cbreak();
	noecho();

	if(!has_colors()) {
		printw("you may not run this program without color support");
		getch();
		endwin();
		return 1;
	};
	start_color();

	refresh();

	getmaxyx(stdscr, termy, termx);

	init_color(BLACK, 0, 0, 0);
	init_color(DARKRED, 658, 0, 0);
	init_color(DARKGREEN, 3, 656, 0);
	init_color(DARKYELLOW, 662, 658, 0);
	init_color(DARKBLUE, 0, 0, 656);
	init_color(DARKMAGENTA, 656, 0, 656);
	init_color(DARKCYAN, 0, 329, 656);
	init_color(LIGHTGRAY, 658, 658, 658);
	init_color(DARKGRAY, 329, 329, 329);
	init_color(LIGHTYELLOW, 992, 988,329);
	init_color(LIGHTCYAN, 329, 992, 992);
	init_color(WHITE, 992, 992, 992);
	

	init_pair(1, LIGHTYELLOW, BLACK);
	init_pair(2, LIGHTCYAN, BLACK);

	printw("Hello User, this program uses ncurses.\nPress any key to continue.\n");

	getch();

	clear();

	const str title =  "YellowGoblin v0.0.0_0v0";
	const str flvrtxts[] = {"A game by Joshua B. Smith", "On the WHOIS domain name datatbase", "A cup of tea", "Cyan", "WHOIS Joshua B. Smith", "You Yumpster", "╠═════════════════╣", "The bee's knees", "CURSE YOU GORGAINA", "The letter \"O\" is pointless"};

title:
	srand(time(NULL));

	str flvrtxt = flvrtxts[rand() % sizeof(flvrtxts)/sizeof(str)];

	attron(A_BOLD);
	attron(COLOR_PAIR(1));

	mvprintw(2, middle(title.length()), "%s", title.c_str());

	attroff(COLOR_PAIR(1));
	attroff(A_BOLD);

	attron(COLOR_PAIR(2));
	
	mvprintw(3, middle(flvrtxt.length()), "%s", flvrtxt.c_str());

	attroff(COLOR_PAIR(2));

	WINDOW* mainmenu = newwin(10, 20, 5, middle(20));
	refresh();
	wrefresh(mainmenu);

	keypad(mainmenu, true);

	str mainmenu_options[] = {"New Game", "Load", "Credits", "Humor", "Quit"};

	int key;
	int choice = 0;

	while(1) {
		for(int i = 0; i < 5; i++) {
			if(i == choice) {
				wattron(mainmenu, A_REVERSE);
			}
			mvwprintw(mainmenu, i, middle(mainmenu_options[i].length(), 20), "%s", mainmenu_options[i].c_str());
			wattroff(mainmenu, A_REVERSE);
		}
		key = wgetch(mainmenu);
		switch(key) {
			case KEY_UP:
				choice--;
				if(choice == -1) {
					choice = 4;
				}
				break;
			case KEY_DOWN:
				choice++;
				if(choice == 5) {
					choice = 0;
				}
				break;
			default:
				break;
		}
		if(key == 10) {
			break;
		}
	}

	clear();

	if(choice == 0) {
		game();
		flvrtxt.clear();
		clear();
		goto title;
	} else if(choice < 3 && choice != 0) {
		mvprintw(middle(1, termy), middle(56), "The functionality of this option is not yet implemented.");
		getch();
		flvrtxt.clear();
		clear();
		goto title;
	} else if(choice == 3) {
		flvrtxt.clear();
		clear();
		goto title;
	} else if(choice == 4) {
		endwin();
		return 0;
	}

	
	getch();


	endwin();

	return 0;
	
}
