#ifndef COMMANDPROCESSER_H
#define COMMANDPROCESSER_H

#include <QObject>

class CommandProcesser : public QObject
{
    Q_OBJECT
public:
    explicit CommandProcesser(QObject *parent = nullptr);

    static CommandProcesser *Instance();

signals:

private:
    static CommandProcesser *instance;

};

#endif // COMMANDPROCESSER_H
