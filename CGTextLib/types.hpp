#pragma once

using str = std::string;
using window = WINDOW*;

inline void colorate(window win, short pair, int attr) {
	wattr_set(win, attr, pair, NULL);
}

inline void colorate(window win, short pair) {
	wattr_set(win, NULL, pair, NULL);
}

struct pos2 {
	int x, y;
};

struct Tile {
	int tile, state;
};

struct TileChar {
	str c;
	int pair;
};

struct Pair {
    unsigned short color;
    unsigned short background;
    short number;
};
