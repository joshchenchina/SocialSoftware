#include "Thread.h"

Thread::Thread(QObject *parent):QThread(parent)
{
    stop = false;

}

void Thread::run(){
    bool startup = true; //bool to check if its the first loop
    while(true){


        //to check if the thread is told to stop
        QMutex mutex;
        mutex.lock();
        if(this->stop){
            break;
        }
        mutex.unlock();

        //emit the signal every 2 seconds
        if(!startup){
            emit update();
        }else{
            startup = false;
        }
        this->sleep(2);

    }
}
