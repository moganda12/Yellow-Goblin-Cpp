#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>
#include <iomanip>
#include <stdlib.h>
#include <vector>
#include <random>

#include "grafix sistem/main.h"

using namespace std;
using namespace this_thread;
using namespace chrono;

using str = string;
using list = vector<double>;

struct item {
    int id;
    str name;
    str description;
};

using inventory = vector<item>;

void threadDelay(int microsecs) {
    sleep_for(microseconds(microsecs));
}

void inititem(int id, str name, str description, inventory& items) {
    items[id] = {id, name, description};
}

void printitem(const item& itm) {
    cout << itm.name << '\n' << itm.description << '\n';
}

void printinventory(const inventory& items) {
    for (int i = 0; i < items.size(); i++) {
        cout << items[i].name << '\n';
    }
}

int main() {
    srand(time(NULL));
    str planetname = "I don't know yet";
    str mountainname = "Mt. Cheesecutter";
    vector<str> flavortext = {"Made with love and passion", "Foo 8-bit Chars", "FOCUS on the map", "Mt. WHO CUT THE CHEESE!", "Poke it with color", "The best cheese in the world", "The best cheese in the universe", "A NOT documetary", "Play Dwarf Fortress", "A dragon made this", "YellowGoblin ver WHAT? Look up(If you can)"};
    int flavortextnumber = flavortext.size();
    int flavortextindex = rand() % flavortextnumber;
    cout << "YellowGoblin ver 0.0.0.1\n\n\n\n";
    threadDelay(10000000);
    system("color 06");
    cout << flavortext[flavortextindex] << '\n';
    system("color 07");
    cout << "On the planet of, " << planetname << ',' << flush;
    sleep_for(seconds(1));
    cout << " goblins come in many diffent colors!\n";
    sleep_for(seconds(2));
    cout << "But most of the goblins are red or blue. " << flush;
    sleep_for(seconds(1));
    cout << "Red and blue goblins hate each other\n";
    sleep_for(seconds(2));
    cout << "But one day a yellow goblin was born, and their name is...\n";
    str name;
    cout << "Name: ";
    getline(cin >> ws, name);
    sleep_for(seconds(2));
    array<str, 3> pronouns;
    char pronoun;
    cout << "Pronouns: he/him[h] she/her[s]  they/them[t]\nPronouns:";
    cin >> pronoun;
    switch (pronoun) {
        case 'h':
        case 'H':
            pronouns[0] = "he";
            pronouns[1] = "him";
            pronouns[2] = "his";
            break;
        case 's':
        case 'S':
            pronouns[0] = "she";
            pronouns[1] = "her";
            pronouns[2] = "her";
            break;
        case 't':
        case 'T':
            pronouns[0] = "they";
            pronouns[1] = "them";
            pronouns[2] = "their";
            break;
        default:
            pronouns[0] = "he";
            pronouns[1] = "him";
            pronouns[2] = "his";
            break;
    }
    cout << "Ok " << pronouns[2] << " name is " << name << ".\n";
    sleep_for(seconds(2));
    cout << "Being yellow " << name << " was banished from goblin society.\n";
    sleep_for(seconds(2));
    cout << pronouns[0] << " is now cold and alone on " << mountainname << endl;
    inventory debug_items;
    inititem(0, "focusing lens", "a small and mysterious lens.\n can put in FOCUS slot.", debug_items);
    inititem(1, "rainbow focusing lens", "a small and mysterious lens that seems to change color every second.\n can put in FOCUS slot.", debug_items);
    inititem(2, "Slimy Apple", "An apple covered in nutritios slime.\n FOOD 10 HG", debug_items);
    inititem(3, "Goofy Apple", "Food with a personality! It makes you laugh every time you look at it.\n FOOD 7 HG 1 HP", debug_items);
    return 0;
}