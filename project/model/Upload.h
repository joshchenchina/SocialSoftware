#ifndef UPLOADS_H
#define UPLOADS_H

#include <string>
#include <ctime>

/**
 * @brief The Uploads class will serve as a generic representation of our different types of posts.
 */
class Upload
{
private:
    long cTimeStamp();
    long timeStamp;
    int id;

protected:
    void copyMedia(std::string id, std::string mediaPath);
    std::string getExtension(std::string mediaPath);

public:
    static int id_cnt;
    /**
     * @brief Uploads The generic constructor for an Upload
     */
    Upload();

    /**
     * @brief getContent This method will get the string content stored in an upload
     * @return std::string The content stored in an Upload
     */
    virtual std::string getContent();

    /**
     * @brief getTimeStamp This method returns the time stamp of the Upload
     * @return std::string The time stamp of the Upload
     */
    long getTimeStamp();

    /**
     * @brief getID This method returns the ID of the Upload
     * @return The ID associated with the Upload
     */
    int getID();

};

#endif // UPLOADS_H
