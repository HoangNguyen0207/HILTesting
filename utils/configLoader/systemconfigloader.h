#pragma once
#include "fileloader.h"

struct SystemConfig_t
{

};
class SystemConfigLoader
{
    public:
        SystemConfigLoader();
        SystemConfig_t getSystemConfig() const;
        bool loadSystemConfig(const std::string& filepath);
    private:
        FileLoader mFileLoader;
        SystemConfig_t mSystemConfig;
};

