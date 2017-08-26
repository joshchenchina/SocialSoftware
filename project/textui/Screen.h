#ifndef SCREEN_H
#define SCREEN_H

#include <QCoreApplication>
#include <QtSql>
#include "../model/Command.h"

#include <ncurses.h>
#include <iostream>

#include <vector>
#include <tuple>

#include <string>
#include <string.h>

#include "HelpScreen.h"

class Screen
{

protected:
    /**
     * @brief Inializes screen
     */
    void initialize();

    //Although these were not used in our app they are good to keep available
    int screenHeight; /*!< The height of the screen*/
    int screenWidth; /*!< The width of the screen*/

    /**
     * @brief showHelpScreen This method shows a new HelpScreen with all of the content
     * @param content The content to be displayed to the screen.
     */
    void showHelpScreen(std::vector<std::tuple<int, int, std::string> > *content);

    /**
     * @brief getHelp A virtual function which will allow for customizable HelpScreen creation in each Screen.
     */
    virtual void getHelp() = 0;
};

#endif // SCREEN_H
