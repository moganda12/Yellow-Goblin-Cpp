
#include <ncurses.h>
#include <string>
#include <sstream>
#include <locale.h>
#include <time.h>
#include <thread>
#include <chrono>
#include <vector>


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

//defines constants
const str planetName = "I don't know yet";
const str mountainName = "Mt. Cheesecutter";

int termx, termy;

//defines po2 struct
struct pos2 {
	int x, y;
};

pos2 cursorpos = {0, 0};

//defines middle function and it's overloads
inline int middle(int chars) {
	return termx/2-chars/2;
};

inline int middle(int chars, int winx) {
	return winx/2-chars/2;
};


//defines tile struct
struct Tile {
	int tile, state;
};

//defines TileChar struct
struct TileChar {
	str c;
	int pair;
};


//defines static tile conversion matrix
std::vector<std::vector<TileChar>> tileChars = {{{" ", 0},{"█",0},{",",0}}};


//defines Layer class
class Layer {
public:
	//defines tile buffer
	std::array<std::array<Tile, 80>, 35> tiles;

	//constructor for Layey class
	Layer() {
		//fills tile buffer with debug tile in the floor state
		for(int y = 0; y < 35; y++) {
			for(int x = 0; x < 80; x++)  {
				tiles[y][x].tile = 0;
				tiles[y][x].state = 2;
			}
		}
	}

	//gets tile at position
	inline Tile gettl(int y, int x) {
		return tiles[y][x];
	}

	//gets TileChar for tile at position
	inline TileChar gettlch(int y, int x) {
		Tile tile = gettl(y,x);
		return tileChars[tile.tile][tile.state];
	}

	//prints tile at position
	void PrintTile(WINDOW* win, int y, int x) {
		//gets TileChar for tile at position
		TileChar tile = gettlch(y,x);

		//enable tiles color pair
		if(tile.pair != 0) {
			wattron(win, COLOR_PAIR(tile.pair));
		}

		//prints tile at position
		mvwprintw(win,y,x, "%s", tile.c.c_str());

		//disables tiles color pair
		if(tile.pair != 0) {
			wattroff(win, COLOR_PAIR(tile.pair));
		}
	}

	void PrintGrid(WINDOW* win) {
		//prints whole grid of tiles in selected window
		for(int y = 0; y < 35; y++) {
			for(int x = 0; x < 80; x++)  {
				PrintTile(win, y, x);
			}
		}
	}

	void setState(int state, int y, int x) {
		tiles[y][x].state = state;
	}

	void setTile(int tile, int y, int x) {
		tiles[y][x].tile = tile;
	}
};


inline void c2p() {
	move(cursorpos.y, cursorpos.x);
}


void game() {
	clear();
	//creates storyPrompt
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

	keypad(storyPrompt, true);

	int key = wgetch(storyPrompt);

	while(key != 10) {
		//backspace logic
		if(key == KEY_BACKSPACE) {
			//is the string empty
			if(name.length() > 0) {
			//Deletes charachter
			name.pop_back();
			//reprints name
			int wx = getmaxx(storyPrompt);

			move(getcury(storyPrompt), 0);

			wclrtoeol(storyPrompt);
			mvwprintw(storyPrompt, getcury(storyPrompt), 6, "%s", name.c_str());
			}
		} else {
			//adds char
			name.push_back((char)key);
			waddch(storyPrompt, (char)key);
		}
		//gets key
		key = wgetch(storyPrompt);
	}

	//propmts user to select pronouns
	wprintw(storyPrompt, "\nPronouns: he/him[h] she/her[s]  they/them[t]");
	
chooseNoun:
	//gets pronoun
	int pronoun = wgetch(storyPrompt);

	//pronnoun array
	std::array<str, 4> pronouns;

	//pronoun select
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
		//requests them to chose valid pronoun
		goto chooseNoun;
	}
	
	wprintw(storyPrompt, "\nOk %s name is %s.", pronouns[2].c_str(), name.c_str());
	wgetch(storyPrompt);
	wprintw(storyPrompt, "\nBeing yellow %s was banished from goblin society.", name.c_str());
	wgetch(storyPrompt);
	wprintw(storyPrompt, "\n%s is now cold and alone on %s", pronouns[0].c_str(), mountainName.c_str());
	wgetch(storyPrompt);

	//enters game
	delwin(storyPrompt);
	refresh();

	//displays regoin
	WINDOW* reJinView = newwin(35, 80, 0, middle(80));
	refresh();
	wrefresh(reJinView);

	Layer SpamtonGSpamton;

	SpamtonGSpamton.setState(1, 20, 34);

	SpamtonGSpamton.PrintGrid(reJinView);
	c2p();
	wgetch(reJinView);
};


int main(int argc, char** argv) {

	//wchar boilerplate
	setlocale(LC_ALL, "");

	//ncurses boilerplate
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

	printw("Hello User, this program uses ncurses.\nPress any key to continue.\n");

	getch();

	clear();

	init_pair(1, LIGHTYELLOW, BLACK);
	init_pair(2, LIGHTCYAN, BLACK);

	//title screen stuff
	const str title =  "YellowGoblin v0.0.0_0v0";
	const str flvrtxts[] = {"A game by Joshua B. Smith", "On the WHOIS domain name datatbase", "A cup of tea", "Cyan", "WHOIS Joshua B. Smith", "You Yumpster", "╠═════════════════╣", "The bee's knees", "CURSE YOU GORGAINA", "The letter \"O\" is pointless"};

title:
	//selects flavortext
	srand(time(NULL));

	str flvrtxt = flvrtxts[rand() % sizeof(flvrtxts)/sizeof(str)];

	//prints title in bold yellow
	attron(A_BOLD); //bold
	attron(COLOR_PAIR(1)); // yellow

	mvprintw(2, middle(title.length()), "%s", title.c_str());

	attroff(COLOR_PAIR(1)); // unbold
	attroff(A_BOLD); // unyellow

	//prints flavortext in cyan
	attron(COLOR_PAIR(2)); // cyan
	
	mvprintw(3, middle(flvrtxt.length()), "%s", flvrtxt.c_str());

	attroff(COLOR_PAIR(2)); // uncyan

	//main menu window
	WINDOW* mainmenu = newwin(10, 20, 5, middle(20));
	refresh();
	wrefresh(mainmenu);

	//keyinput stuff
	keypad(mainmenu, true);

	//defines menu options
	str mainmenu_options[] = {"New Game", "Load", "Credits", "Humor", "Quit"};

	// menu tracking variables
	int key;
	int choice = 0;

	//menu logic
	while(1) {
		//prints menu
		for(int i = 0; i < 5; i++) {
			if(i == choice) {
				wattron(mainmenu, A_REVERSE);
			}
			mvwprintw(mainmenu, i, middle(mainmenu_options[i].length(), 20), "%s", mainmenu_options[i].c_str());
			wattroff(mainmenu, A_REVERSE);
		}
		//gets user input
		key = wgetch(mainmenu);

		//procceses input
		switch(key) {
			//moves menu option select up
			case KEY_UP:
				choice--;
				//checks if you need to loop
				if(choice == -1) {
					//loops
					choice = 4;
				}
				break;
			//moves menu option select down
			case KEY_DOWN:
				choice++;
				//checks if you need to loop
				if(choice == 5) {
					//loops
					choice = 0;
				}
				break;
			default:
				break;
		}
		//detects if user selects option
		if(key == 10) {
			break;
		}
	}

	//preps screen
	clear();

	//detects selected option
	if(choice == 0) {
		//starts game
		game();
		//go's to main menu
		flvrtxt.clear();
		clear();
		goto title;
	} else if(choice < 3 && choice != 0) {
		//informs user of the games inclopleteness
		mvprintw(middle(1, termy), middle(56), "The functionality of this option is not yet implemented.");
		getch();
		//returns to main menu
		flvrtxt.clear();
		clear();
		goto title;
	} else if(choice == 3) {
		//returns to the main menu in order to cycle the flavortext
		flvrtxt.clear();
		clear();
		goto title;
	} else if(choice == 4) {
		//exits the game
		endwin();
		return 0;
	}

	
	getch();


	endwin();

	return 0;
	
}
