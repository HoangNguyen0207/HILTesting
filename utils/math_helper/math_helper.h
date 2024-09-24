#ifndef _MATH_HELPER_H_
#define _MATH_HELPER_H_

#include <vector>

#define PI 3.1415
#define ABS(x) (((x < 0) ? -x : x))

double peak_amplitude_detect(std::vector<double>& signal);
double frequency_detect(std::vector<double>& signal, double sampling_rate);
double getdBGain(double value, double ref);

double getAngle(std::vector<double>& center, std::vector<double>& ref, std::vector<double>& curr);
double getDistance(std::vector<double>& ref, std::vector<double>& curr);

double getInstantVelocity(double dist, double timeInterval);
std::vector<double> getSineTrajectory(double frequency, double amplitude, double fadeTime, double osciTime, double timeInterval);

double getPercentage(double num, double dem);
bool isEqual(double a, double b);

double getPhaseDelay(std::vector<double>& a, std::vector<double>& b, double timeInterval);
#endif
