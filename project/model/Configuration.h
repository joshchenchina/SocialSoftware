#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include<stddef.h>
#include<string>
#include<iostream>
#include<fstream>
#include<map>

/**
 * @brief The Configuration class will help to handle a lot of the backend work for the program.
 */
class Configuration
{
private:
    static std::string source;  /*!< the source used to load*/
    static std::map<std::string,std::string> map; /*!< the map used to store information*/
public:
    /**
     * @brief format a source with a filename
     * @param filename
     * @return source
     */
    static std::string source_generation_with_filename(std::string);

    /**
     * @brief format a source with a filename and a location
     * @param filename, location
     * @return source
     */
    static std::string source_generation_with_filename_location(std::string, std::string);

    /**
     * @brief load a file
     * @param source used to load
     */
    static bool load();

    /**
     * @brief store the information into the map
     */
    static bool store(std::string);

    /**
     * @brief store two message into the map, one as key, another as value
     * @param two values
     */
    static void setPair(std::string, std::string);

    /**
     * @brief get value from the map
     * @param key
     * @return value
     */
    static std::string getValue(std::string);
};

#endif // CONFIGURATION_H
