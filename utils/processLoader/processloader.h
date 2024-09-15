#pragma once
#include <QObject>

class ProcessLoader
{
    public:
        ProcessLoader();
        virtual ~ProcessLoader();
        virtual bool loadProcessFile(const QString& filePath) = 0;
};

