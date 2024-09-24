#ifndef RESPONSEOBSERVER_H
#define RESPONSEOBSERVER_H

#include <QString>

class ResponseObserver
{
public:
    virtual ~ResponseObserver() {}
    virtual void processRespose(const QString& responseStr) = 0;
};

#endif // RESPONSEOBSERVER_H
