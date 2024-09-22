#pragma once
#include <QObject>

#define DELETE(ptr) delete ptr; \
                    ptr = nullptr; \

namespace DataSize {
    constexpr int IODeviceBufferSize = 2048;
}

namespace ProcessorName {
    const QString BUS_ADDR_CONFIG = "VTX.HIL.CONFIG";
    const QString BUS_ADDR_LOGGER = "VTX.HIL.LOGGER";
}

namespace FilePath {
    const QString SystemConfigFilePath = "../../config/SystemConfig.yaml";
}

namespace ProcessFilePath {
    const QString Process_1_1_1 = "../../config/ProcessFiles/Process_1_1_1.json";
    const QString Process_1_1_2 = "../../config/ProcessFiles/Process_1_1_2.json";
    const QString Process_1_1_11 = "../../config/ProcessFiles/Process_1_1_11.json";
    const QString Process_1_2_1 = "../../config/ProcessFiles/Process_1_2_1.json";
    const QString Process_1_2_2 = "../../config/ProcessFiles/Process_1_2_2.json";
    const QString Process_1_2_3 = "../../config/ProcessFiles/Process_1_2_3.json";
    const QString Process_1_2_4 = "../../config/ProcessFiles/Process_1_2_4.json";
    const QString Process_1_2_5 = "../../config/ProcessFiles/Process_1_2_5.json";
    const QString Process_1_2_6_7 = "../../config/ProcessFiles/Process_1_2_6_7.json";
    const QString Process_1_2_8 = "../../config/ProcessFiles/Process_1_2_8.json";
    const QString Process_1_2_9 = "../../config/ProcessFiles/Process_1_2_9.json";
    const QString Process_1_2_10 = "../../config/ProcessFiles/Process_1_2_10.json";
    const QString Process_1_2_11 = "../../config/ProcessFiles/Process_1_2_11.json";
    const QString Process_1_2_12 = "../../config/ProcessFiles/Process_1_2_12.json";
    const QString Process_1_2_13 = "../../config/ProcessFiles/Process_1_2_13.json";
    const QString Process_1_2_14 = "../../config/ProcessFiles/Process_1_2_14.json";
    const QString Process_2_1_10 = "../../config/ProcessFiles/Process_2_1_10.json";
    const QString Process_2_1_11 = "../../config/ProcessFiles/Process_2_1_11.json";
    const QString Process_2_2_1 = "../../config/ProcessFiles/Process_2_2_1.json";
    const QString Process_2_2_2 = "../../config/ProcessFiles/Process_2_2_2.json";
    const QString Process_2_2_3 = "../../config/ProcessFiles/Process_2_2_3.json";
    const QString Process_2_2_4 = "../../config/ProcessFiles/Process_2_2_4.json";
    const QString Process_2_2_5 = "../../config/ProcessFiles/Process_2_2_5.json";
    const QString Process_2_2_6 = "../../config/ProcessFiles/Process_2_2_6.json";
    const QString Process_2_2_8 = "../../config/ProcessFiles/Process_2_2_8.json";
    const QString Process_2_2_9 = "../../config/ProcessFiles/Process_2_2_9.json";
    const QString Process_2_2_10 = "../../config/ProcessFiles/Process_2_2_10.json";
    const QString Process_2_2_13_1 = "../../config/ProcessFiles/Process_2_2_13_1.json";
    const QString Process_2_2_13_2 = "../../config/ProcessFiles/Process_2_2_13_2.json";
    const QString Process_2_2_15 = "../../config/ProcessFiles/Process_2_2_15.json";
}

enum class ProcessType
{
    Process_1_1_1,
    Process_1_1_2,
    Process_1_1_11,
    Process_1_2_1,
    Process_1_2_2,
    Process_1_2_3,
    Process_1_2_4,
    Process_1_2_5,
    Process_1_2_6_7,
    Process_1_2_8,
    Process_1_2_9,
    Process_1_2_10,
    Process_1_2_11,
    Process_1_2_12,
    Process_1_2_13,
    Process_1_2_14,
    Process_2_1_10,
    Process_2_1_11,
    Process_2_2_1,
    Process_2_2_2,
    Process_2_2_3,
    Process_2_2_4,
    Process_2_2_5,
    Process_2_2_6,
    Process_2_2_8,
    Process_2_2_9,
    Process_2_2_10,
    Process_2_2_13_1,
    Process_2_2_13_2,
    Process_2_2_15,
};
