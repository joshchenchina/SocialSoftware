#ifndef THREAD_H
#define THREAD_H
#include<QtCore>
#include <QThread>

class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread(QObject *parent = 0);
    void run();
    bool stop;
    bool ended;

signals:
    void update();

public slots:
};

#endif // THREAD_H
