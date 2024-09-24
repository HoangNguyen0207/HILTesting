#pragma once
#include "fileloader.h"

struct SystemConfig_t
{
    double fmsRollCenterX;
    double fmsRollCenterY;
    double fmsRollCenterZ;
    double fmsYawPitchCenterX;
    double fmsYawPitchCenterY;
    double fmsYawPitchCenterZ;
    double tmsCenterX;
    double tmsCenterY;
    double tmsCenterZ;
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

