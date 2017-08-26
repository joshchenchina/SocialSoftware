#include "Screen.h"

void Screen::initialize(){
    //General ncurses setup
    initscr();
    curs_set(0);
    cbreak();
    noecho();
    erase();
    keypad(stdscr, TRUE);
}

void Screen::showHelpScreen(std::vector<std::tuple<int, int, std::string> > *content){
    HelpScreen *h = new HelpScreen(content);
}
