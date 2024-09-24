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
        check &= mFileLoader.getFromFile("fmsRollCenterX", mSystemConfig.fmsRollCenterX);
        check &= mFileLoader.getFromFile("fmsRollCenterY", mSystemConfig.fmsRollCenterY);
        check &= mFileLoader.getFromFile("fmsRollCenterZ", mSystemConfig.fmsRollCenterZ);
        check &= mFileLoader.getFromFile("fmsYawPitchCenterX", mSystemConfig.fmsYawPitchCenterX);
        check &= mFileLoader.getFromFile("fmsYawPitchCenterY", mSystemConfig.fmsYawPitchCenterY);
        check &= mFileLoader.getFromFile("fmsYawPitchCenterZ", mSystemConfig.fmsYawPitchCenterZ);
        check &= mFileLoader.getFromFile("tmsCenterX", mSystemConfig.tmsCenterX);
        check &= mFileLoader.getFromFile("tmsCenterY", mSystemConfig.tmsCenterY);
        check &= mFileLoader.getFromFile("tmsCenterZ", mSystemConfig.tmsCenterZ);
        return check;
    }
    else return false;
}
