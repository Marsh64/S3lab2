//
// Created by adm on 27.11.2021.
//
#ifndef S3_LABORATORY_WORK_2_ITIMER_CPP
#define S3_LABORATORY_WORK_2_ITIMER_CPP
#include <chrono>
#include "ITimer.h"
using namespace std::chrono;

ITimer::ITimer(){
    time = system_clock::now();
}

ITimer::ITimer(const ITimer &timer) {
    time = timer.time;
}

void ITimer::Reset() {
    time = system_clock::now();
}

double ITimer::Time() {
    return duration_cast<second_t>(clock_t::now() - time).count();
}

#endif //S3_LABORATORY_WORK_2_TIMER_CPP