#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>

using namespace std;
using namespace this_thread;
using namespace chrono;

using str = string;

struct item {
    int id;
    str name;
    str description;
};

int main() {
    str planetname = "I don't know yet";
    str mountainname = "Mt. Cheesecutter";
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
    cout << pronouns[0] << " is now cold and alone on " << mountainname << ".\n";
    return 0;
}