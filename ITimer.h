//
// Created by adm on 27.11.2021.
//

#ifndef S3_LABORATORY_WORK_2_ITIMER_H
#define S3_LABORATORY_WORK_2_ITIMER_H
#include <chrono>

class ITimer {
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1>>;

    std::chrono::time_point<clock_t> time;
public:
    ITimer();
    ITimer(const ITimer& timer);
    void Reset();
    double Time();
};


#endif //S3_LABORATORY_WORK_2_TIMER_H
