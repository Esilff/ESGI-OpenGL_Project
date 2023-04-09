//
// Created by Esilff on 09/04/2023.
//

#include "Time.h"

void Time::update() {
    Timer::getInstance().update();
}

double Time::dt() {
    return Timer::getInstance().dt();
}


void Timer::update()  {
    m_endTime = m_startTime;
    m_startTime = std::chrono::high_resolution_clock::now();
}

double Timer::dt()  {
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(m_startTime - m_endTime);
    return static_cast<double>(duration.count()) /1000000.0; //in seconds
}

double Timer::nanoDt()  {
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(m_startTime - m_endTime);
    return static_cast<double>(duration.count());
}