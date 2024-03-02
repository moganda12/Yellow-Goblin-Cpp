#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>
#include <string>


using str = std::string;
using wchar = wchar_t;

struct item {
    int id;
    str name;
    str description;
};

void threadDelay(int μs) {
	std::this_thread::sleep_for(std::chrono::microseconds(μs));
};


int main() {
	setlocale( LC_ALL, "" );


	str planetname = "I don't know yet";
	str mountainname = "Mt. Cheescutter";
	
	std::cout << L"On the planet of " << planetname << L',';
    threadDelay(1000000);
    std::cout << " goblins come in many diffent colors!\n";
    threadDelay(2000000);
    std::cout << "But most of the goblins are red or blue. " << std::flush;
    threadDelay(1000000);
    std::cout << "Red and blue goblins hate each other\n";
    threadDelay(2000000);
    std::cout << "But one day a yellow goblin was born, and their name is...\n";
    str name;
    std::cout << "Name: ";
    getline(std::cin >> std::ws, name);
	
    threadDelay(2000000);
    std::array<str, 3> pronouns;
    char pronoun;
    std::wcout << "Pronouns: he/him[h] she/her[s]  they/them[t]\nPronouns:";
    switch (pronoun) {
        case L'h':
        case L'H':
            pronouns[0] = "he";
            pronouns[1] = "him";
            pronouns[2] = "his";
            break;
        case L's':
        case L'S':
            pronouns[0] = "she";
            pronouns[1] = "her";
            pronouns[2] = "her";
            break;
        case L't':
        case L'T':
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
	
    std::cout << "Ok " << pronouns[2] << " name is " << name << ".\n";
    threadDelay(2000000);
    std::cout << "Being yellow " << name << " was banished from goblin society.\n";
    threadDelay(2000000);
    std::cout << pronouns[0] << " is now cold and alone on " << mountainname << ".\n";
    return 0;
};
