#pragma once

#include <string>
#include <iostream>
#include <array>
#include <sstream>

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#include "./chars.hpp"


using wchar = wchar_t;
using wstr = std::basic_string<wchar>;


struct pos {
    int x;
    int y;
};


namespace TextEngine {
	std::array<std::array<wchar, 40>, 140> textGrid;
	bool initilized = false;

	pos ptr = {0,0};

	std::wstringstream cout;
	
	void init() {
		if (initilized) {
			std::cout << "TextEngine already initilized YA GOOSE ON THE LOOSE!\n";
			exit(1);
		};
		for(int i = 0; i < 40; i++) {
			for(int j = 0; j < 100; j++) {
				textGrid[j][i] = L' ';
			};
		};
		initilized = true;
		return;
	};

	void print() {
		system("clear");

		for(int i = 0; i < 40; i++) {
			for(int j = 0; j < 100; j++) {
				std::wcout << textGrid[j][i];
			};
			std::wcout << '\n';
		};
		return;
	};

	void set(size_t x, size_t y, wchar to) {
		textGrid[x][y] = to;
		return;
	};

	pos prntstr(wstr string, int lineX, int startLineY, pos start = {0,0}, bool cont = false) {
		size_t ptrx = lineX;
		size_t ptry = startLineY;
		if(cont) {
			ptrx = start.x;
			ptry = start.y;
		}
		for(int i = 0; i < string.length(); i++) {
			wchar chr = string.at(i);
			if (chr == L'\n') {
				ptrx = lineX;
				ptry++;
			}
			set(ptrx, ptry, chr);
			ptrx++;
		};
		return {ptrx, ptry};
	};
};
