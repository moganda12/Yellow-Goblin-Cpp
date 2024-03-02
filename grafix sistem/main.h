#include <iostream>
#include <array>
#include <stdlib.h>
#include <chrono>
#include <thread>

using namespace std;
using namespace this_thread;
using namespace chrono;
using screen = array<array<string, 80>, 40>;

void draw_screen(screen &screen) {
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 80; j++) {
            cout << screen[i][j];
        }
        cout << '\n';
    }
}