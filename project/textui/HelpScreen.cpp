#include "HelpScreen.h"

HelpScreen::HelpScreen(){
}

HelpScreen::HelpScreen(std::vector<std::tuple<int, int, std::string>> *content){
    initialize();
    printContent(content);
    endwin();
}

void HelpScreen::printContent(std::vector<std::tuple<int, int, std::string> > *content){
    do {
        clear();
        refresh();

        mvprintw(3,8,"Press any key to return to the last screen.");

        for(std::tuple<int, int, std::string> tup : *content)
          mvprintw(std::get<0>(tup), std::get<1>(tup), std::get<2>(tup).c_str());


        int ch = getch();

        if(ch!=0) break;


    } while(true);

    }

void HelpScreen::initialize(){
    initscr();
    curs_set(0);
    cbreak();
    noecho();
    erase();
    keypad(stdscr, TRUE);
}
