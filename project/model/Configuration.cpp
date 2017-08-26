#include "Configuration.h"


std::string Configuration::source = "./";
std::map<std::string,std::string> Configuration::map;


std::string Configuration::source_generation_with_filename(std::string filename){
    source = "./" + filename;
    return source;
}

std::string Configuration::source_generation_with_filename_location(std::string location, std::string filename){
    source = location + filename;
    return source;
}

bool Configuration::load(){
    if(!source.empty()){
        std::ifstream myfile (source.c_str());
        if (myfile.is_open())
        {
          //Operation of loading
          myfile.close();
          return true;
        }
    }
    else
        return false;
}

bool Configuration::store(std::string filename){
    std::string name = "./" + filename;
    std::ofstream myfile (name.c_str());
    if (myfile.is_open())
    {
        //Operation of storing

        std::cout << "success";
        myfile.close();
        return true;
    }
    else
    {
        std::cout << "fail";
        return false;
    }
}

void Configuration::setPair(std::string key, std::string value){
    map.insert(std::pair<std::string, std::string>(key,value));

}

std::string Configuration::getValue(std::string key){
    return map.at(key);
}
