#ifndef FMSMANAGER_H
#define FMSMANAGER_H

#include <QObject>

#include "FmsApi_global.h"
#include "constant.h"
#include "processer/CommandProcesserInterface.h"
#include <QMap>
#include <QQueue>
#include "thirdparty/fms_lib/deploy/linux/include/info/ResponseInfo.h"

class CommandInfo : public QObject
{
    public:
        CommandInfo (MSG_TYPE type, QString cmd);
        MSG_TYPE getType() const;
        void setType(const MSG_TYPE &value);

        QString getCmd() const;
        void setCmd(const QString &value);

    private:
        MSG_TYPE type;
        QString cmd;
};

class FMSAPI_EXPORT FmsManager : public QObject
{
        Q_OBJECT
    public:
        explicit FmsManager(QObject *parent = nullptr);
        void initialize();

        static FmsManager* Instance();
        int processCommand(const MSG_TYPE& type,  const QString& cmd);
        int processCommand(const QString& cmd);
        int detectCommand(const QString& cmd);

        int checkValidCommand(const QString& cmd);

    signals:
        void sigResponseResult(QString result);
    public slots:
        void onContineProcessCommand(ResponseInfo responseInfo);
    private:
        static FmsManager *m_FmsManager;
        QMap<uint8, CommandProcesserInterface*> commandProcessers;
        QQueue <CommandInfo*> qCommanders;
        QMap<MSG_TYPE, QString> mapCommads;
};

#endif // FMSMANAGER_H
