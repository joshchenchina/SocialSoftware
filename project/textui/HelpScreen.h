#ifndef HELPSCREEN_H
#define HELPSCREEN_H

#include <ncurses.h>
#include <vector>
#include <tuple>
#include <string>

/**
 * @brief The HelpScreen class will serve to aid any users should they forget what they can do on a screen
 */
class HelpScreen
{
private:
    /**
     * @brief printContent This method will print all of the content passed in to the screen
     * @param content The content to be printed
     */
    void printContent(std::vector<std::tuple<int, int, std::string>> *content);

public:
    /**
     * @brief HelpScreen The basic constructor for a HelpScreen, note calling this will do nothing.
     */
    HelpScreen();

    /**
     * @brief HelpScreen This constructor will create a usable help screen
     * @param content The content to be printed to the screen in the form of <y,x,content>
     */
    HelpScreen(std::vector<std::tuple<int, int, std::string>> *content);

    /**
     * @brief Initializes the HelpScreen
     */
    void initialize();
};

#endif // HELPSCREEN_H
