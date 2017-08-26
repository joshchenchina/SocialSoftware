#ifndef WEBSITE_H
#define WEBSITE_H

#include "Group.h"
#include <string>
#include <tuple>

class Website
{

public:
    static std::string parseTimeStamp(std::string timestamp);
    static void createWebsite();
    static std::string getExtension(std::string mediaPath);
};

#endif // WEBSITE_H
