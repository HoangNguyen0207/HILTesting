#include "systemconfigloader.h"

SystemConfigLoader::SystemConfigLoader()
{

}

SystemConfig_t SystemConfigLoader::getSystemConfig() const
{
    return mSystemConfig;
}

bool SystemConfigLoader::loadSystemConfig(const std::string &filepath)
{
    if(mFileLoader.loadFromFile(filepath))
    {
        bool check = true;
        return check;
    }
    else return false;
}
