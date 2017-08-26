#include "Upload.h"

Upload::Upload()
{
    timeStamp = cTimeStamp();
}

void Upload::copyMedia(std::string id, std::string mediaPath){
    //Created using the code from www.cplusplus.com/forum/beginner/83836/
    FILE * infile = std::fopen(mediaPath.c_str(),"rb");
    FILE * outfile = std::fopen((id+getExtension(mediaPath)).c_str(), "wb");
    const int size = 16384;
    char buffer[size];

    while (!feof(infile))
    {
        int n = fread(buffer, 1, size, infile);
        fwrite(buffer, 1, n, outfile);
    }

    fflush(outfile);
    std::fclose(infile);
    std::fclose(outfile);
}

std::string Upload::getExtension(std::string mediaPath){
    for(int i = mediaPath.length()-1; i>=0; i--){
        if(mediaPath.substr(i,1).compare(".")==0) return mediaPath.substr(i);
    }
    return "";
}

std::string Upload::getContent(){
    return "Base return";
}

long Upload::getTimeStamp(){
    return timeStamp;
}

long Upload::cTimeStamp(){
    //http://www.cplusplus.com/reference/ctime/strftime/
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];

    std::time(&rawtime);
    timeinfo = localtime (&rawtime);

    std::strftime(buffer,80,"%Y%m%d%H%M%S",timeinfo);
    //std::puts(buffer);
    return std::stol(buffer);
}
