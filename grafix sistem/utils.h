#include <iostream>

using str = std::string;

enum textcolor {black, red, green, yellow, blue, magenta, cyan, white};
enum modifier {normal, bold, underline, blink, reverse, concealed};

str text_style(const textcolor fg, const textcolor bg, const modifier mod) {
    str style = "\033[";
    int len = 0;
    str fgcolor = "";

}
