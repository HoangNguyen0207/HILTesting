#include "math_helper.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include "utils/math_helper/math_helper.h"

static int count_zero_crossings(const std::vector<double>& signal) {
    int zero_crossings = 0;
    for (size_t i = 1; i < signal.size(); ++i) {
        if ((signal[i - 1] > 0 && signal[i] < 0) || (signal[i - 1] < 0 && signal[i] > 0)) {
            zero_crossings++;
        }
    }
    return zero_crossings;
}

double peak_amplitude_detect(std::vector<double>& signal) {
    return *std::max_element(signal.begin(), signal.end());
}

//Sampling Rate (Hz)
double frequency_detect(std::vector<double>& signal, double sampling_rate)
{
    int zero_crossings = count_zero_crossings(signal);
    double estimated_frequency = (zero_crossings / 2.0) * (sampling_rate / sizeof(signal));
    return estimated_frequency;
}

double getdBGain(double value, double ref)
{
    return 10.0f*log10(value/ref);
}

double getAngle(std::vector<double>& center, std::vector<double>& ref, std::vector<double>& curr)
{
    double cr_x = ref.at(0) - center.at(0);
    double cr_y = ref.at(1) - center.at(1);
    double cr_z = ref.at(2) - center.at(2);

    double cc_x = curr.at(0) - center.at(0);
    double cc_y = ref.at(1) - center.at(1);
    double cc_z = ref.at(2) - center.at(2);

    double length = sqrt(cr_x*cr_x + cr_y*cr_y + cr_z*cr_z) *
                    (cc_x*cc_x + cc_y*cc_y + cc_z*cc_z);

    double dot_product = cr_x*cc_x + cr_y*cc_y + cr_z*cc_z;

    double angle = acos(dot_product/length) * 360 / PI;

    if(angle > 90)
    {
        angle -= 180;
    }
    else if(angle < (-90))
    {
        angle += 180;
    }
    return angle;
}

//Note that axis value: 0 = x, 1 = y, 2 = z
double getDistance(std::vector<double>& ref, std::vector<double>& curr)
{
    double cr_x = curr.at(0) - ref.at(0) ;
    double cr_y = curr.at(1) - ref.at(1) ;
    double cr_z = curr.at(2) - ref.at(2) ;

    double length = sqrt(cr_x*cr_x + cr_y*cr_y + cr_z*cr_z);

    return length;
}

double getInstantVelocity(double dist, double timeInterval)
{
    return dist/timeInterval;
}

std::vector<double> getSineTrajectory(double frequency, double amplitude, double fadeTime, double osciTime, double timeInterval)
{
    double omega = 2 * PI * frequency;
    double mTimeCount = 0;
    std::vector<double> mData;
    do {
        double amp = amplitude * (mTimeCount / fadeTime) * sin(omega * mTimeCount);
        mData.push_back(amp);
        mTimeCount += timeInterval;
    } while(mTimeCount < fadeTime);

    do {
        double amp = amplitude * sin(omega * mTimeCount);
        mData.push_back(amp);
        mTimeCount += timeInterval;
    } while(mTimeCount < (fadeTime + osciTime));

    double offsetTime = fadeTime + osciTime;
    do {
        double calcTime = mTimeCount - offsetTime;
        double amp = amplitude * (fadeTime - calcTime) * sin(omega * mTimeCount) / fadeTime;
        mData.push_back(amp);
        mTimeCount += timeInterval;
    } while(mTimeCount < (fadeTime + osciTime + fadeTime));

    return mData;
}

double getPercentage(double num, double dem)
{
    return (num/dem) * 100.0f;
}

bool isEqual(double a, double b)
{
    if(fabs(a - b) < 0.001)
        return true;
    else return false;
}

double getPhaseDelay(std::vector<double>& a, std::vector<double>& b, double timeInterval)
{
    int dataSize = (a.size() > b.size()) ? b.size() : a.size();
    std::vector<int> zero_delay;
    for(int i = 0; i < (dataSize - 1); i++)
    {
        if(a.at(i) > 0 && a.at(i+1) < 0)
        {
            for(int j = i; j < (dataSize-1); j++)
            {
                if(b.at(j) > 0 && b.at(j+1) < 0)
                {
                    zero_delay.push_back(j-i);
                }
            }
        }
        else if(a.at(i) < 0 && a.at(i+1) > 0)
        {
            for(int j = i; j < (dataSize-1); j++)
            {
                if(b.at(j) < 0 && b.at(j+1) > 0)
                {
                    zero_delay.push_back(j-i);
                }
            }
        }
    }
    int sumDelay = 0;
    for(std::vector<int>::iterator it = zero_delay.begin();
         it != zero_delay.end(); it++)
    {
        sumDelay += *it;
    }
    sumDelay /= zero_delay.size();
    double realDelay = sumDelay * timeInterval;
    return realDelay;
}
