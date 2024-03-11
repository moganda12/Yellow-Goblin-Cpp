#pragma once

#include "./types.hpp"

class Entity {
private:
	TileChar tile;

public:
	int y;
	int x;

	Entity(int starty, int startx, TileChar representation) {
		this->y = starty;
		this->x = startx;
		this->tile = representation;
	};

	void draw(window win) {
		colorate(win, tile.pair);

		mvwprintw(win, y,x, "%s", tile.c.c_str());
	}

    	void move(int y, int x) {
		this->y += y;
		this->x += x;
		if(this->y < 0) {
			this->y = 0;
		} else if(this->y > 39) {
			this->y = 39;
		};
		if(this->x < 0) {
			this->x = 0;
		} else if(this->x > 79) {
			this->x = 79;
		};
	}
};

class Player : public Entity {
public:

	int regionx, regiony = 0;
	int worldx, worldy = 0;

	Player(int starty, int startx) : Entity(starty, startx, {"☺", 1}) {}
};
