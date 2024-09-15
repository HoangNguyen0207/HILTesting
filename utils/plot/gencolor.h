#pragma once

#include <vector>
#include <array>
#include <QColor>
class GenColor
{
    public:
        GenColor();
        int genColor(unsigned int usedBy);
        int revertColor(unsigned int usedBy);
    private:
        const std::vector<int> colorPatern{0xFF1744,0x304FFE,
                                           0xEC407A,0x64DD17,
                                           0xFF7043,0xFF7043,
                                           0xC51162,0xAA00FF,
                                           0xFFA726,0x00C853,
                                           0x42A5F5,0xAB47BC,
                                           0xEF5350,0xFFCA28,
                                           0x5C6BC0,0xFFEE58,
                                           0x66BB6A,0x26C6DA,
                                           0x8D6E63,0x78281F};
        std::array<int,20> mColorIsUsed;
        int mNumberUsedColor{0};
};

