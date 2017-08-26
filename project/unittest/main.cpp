#include <iostream>
#include "gtest/gtest.h"
#include "unistd.h"

using namespace std;

int main(int argc, char **argv)
{
//    BlogPost *b = new BlogPost("test","/usr23/lombardc/Desktop/tmp.txt","newTextFile");
//    sleep(2);
//    Message *m = new Message("Hello World");
//    cout << b->getTimeStamp()  << endl;
//    cout << m->getTimeStamp()  << endl;

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}
