#ifndef ACTIONTYPES_H
#define ACTIONTYPES_H

enum class ActionType
{
    LoadProcessFile,
    AbortTest,
    RequestPositionInput,
    UpdatePositionInput,
    UpdateState,
    FinishTest,
    UpdateCenterInput,
    UpdateTestConfig
};

#endif
