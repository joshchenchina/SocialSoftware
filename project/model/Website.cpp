#include "Website.h"

void Website::createWebsite(){

    system("cat /auto/bunter_usr11/cs205_2016_Grp00/mediaContent_HarveyRanch/initHTML.txt > index.html");

    //add other stuff
    //author, timestamp, content, path
    std::vector<std::tuple<std::string, std::string, std::string, std::string>> allContent = Group::getAllPosts();

    std::string newPost = "";

    for(int i=0; i<allContent.size(); i++){
        std::string imgPath = std::get<3>(allContent.at(i));
        newPost += "<div id='imageContainer" + imgPath + "' style='float:left;width:32%;margin:0;' class='customContainer'>";
        newPost += "\n<p> " + std::get<0>(allContent.at(i)) + " : " + parseTimeStamp(std::get<1>(allContent.at(i))) + "</p>";
        if(getExtension(imgPath).compare(".jpg")==0){
            newPost += "<div id='insideImageContainer" + imgPath + " 'style='position:relative;margin:5px;'>"
                                                                   "<div class='galleryImageHolder' style='position:relative; width:100%; padding:0 0 75%;overflow:hidden;'>"
                                                                   "<div class='galleryInnerImageHolder'>"
                                                                   "<a href='" + imgPath + "' rel='lightbox[gallery931    942781609375501]' onclick='if (!window.lightboxLoaded) return false'>"
                                                                                           "<img src='" + imgPath + "' class='galleryImage' _width='400' _height='374' style='position:absolute;border:0;width:100%;top:0%;left:2%' />"
                                                                                                                    "</a>"
                                                                                                                    "</div>"
                                                                                                                    "</div>"
                                                                                                                    "</div>";
        }

        newPost += "<p>" + std::get<2>(allContent.at(i)) + "</p>";
        newPost += "</div>";
    }

    std::string command = "echo \"" + newPost + "\" >> index.html";
    system(command.c_str());

    system("cat /auto/bunter_usr11/cs205_2016_Grp00/mediaContent_HarveyRanch/postHTML.txt >> index.html");


}

std::string Website::parseTimeStamp(std::string timestamp){
    return timestamp.substr(0,4) + "-" + timestamp.substr(4,2) + "-" + timestamp.substr(6,2) + " " +
            timestamp.substr(8,2) + ":" + timestamp.substr(10,2) + ":" + timestamp.substr(12,2);
}

std::string Website::getExtension(std::string mediaPath){
    for(int i = mediaPath.length()-1; i>=0; i--){
        if(mediaPath.substr(i,1).compare(".")==0) return mediaPath.substr(i);
    }
    return "";
}
