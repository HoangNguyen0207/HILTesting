#include "gencolor.h"

GenColor::GenColor()
{
    mColorIsUsed.fill(-1);
}

int GenColor::genColor(unsigned int usedBy)
{
    int color = -1;
    for(unsigned int i = 0; i < colorPatern.size(); i++)
    {
        if(mColorIsUsed[i] == -1 || mColorIsUsed[i] == static_cast<int>(usedBy))
        {
            mColorIsUsed[i] = static_cast<int>(usedBy);
            color = colorPatern[i];
            break;
        }else
        {
            color = QColor::fromHsl(rand()%240, rand()%140+100, rand()%140+100).value();
        }
    }
}

int GenColor::revertColor(unsigned int usedBy)
{
    for(unsigned int i = 0; i < colorPatern.size(); i++)
    {
        if(mColorIsUsed[i] == static_cast<int>(usedBy))
        {
            mColorIsUsed[i] = -1;
            break;
        }
    }
    return -1;
}
