#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>
#include <string>

#include "./TextGridGameEngine/main.hpp"

#include <fstream>
#include <locale.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

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

	TextEngine::init();

	TextEngine::print();
	
    wstr planetname = L"I don't know yet";
    wstr mountainname = L"Mt. Cheesecutter";

	pos cont = {0,0};
	
	TextEngine::cout << L"On the planet of " << planetname << L',';
    threadDelay(1000000);
    std::cout << " goblins come in many diffent colors!\n";
    threadDelay(2000000);
    std::cout << "But most of the goblins are red or blue. " << std::flush;
    threadDelay(1000000);
    std::cout << "Red and blue goblins hate each other\n";
    threadDelay(2000000);
    std::cout << "But one day a yellow goblin was born, and their name is...\n";
    wstr name;
    std::cout << "Name: ";
    getline(std::wcin >> std::ws, name);
	
    threadDelay(2000000);
    std::array<wstr, 3> pronouns;
    wchar pronoun;
    std::wcout << "Pronouns: he/him[h] she/her[s]  they/them[t]\nPronouns:";
    std::wcin >> pronoun;
    switch (pronoun) {
        case L'h':
        case L'H':
            pronouns[0] = L"he";
            pronouns[1] = L"him";
            pronouns[2] = L"his";
            break;
        case L's':
        case L'S':
            pronouns[0] = L"she";
            pronouns[1] = L"her";
            pronouns[2] = L"her";
            break;
        case L't':
        case L'T':
            pronouns[0] = L"they";
            pronouns[1] = L"them";
            pronouns[2] = L"their";
            break;
        default:
            pronouns[0] = L"he";
            pronouns[1] = L"him";
            pronouns[2] = L"his";
            break;
    }
	
    std::wcout << L"Ok " << pronouns[2] << L" name is " << name << L".\n";
    threadDelay(2000000);
    std::wcout << L"Being yellow " << name << L" was banished from goblin society.\n";
    threadDelay(2000000);
    std::wcout << pronouns[0] << L" is now cold and alone on " << mountainname << L".\n";
    return 0;
}
