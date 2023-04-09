//
// Created by Esilff on 09/04/2023.
//

#ifndef TIME_H
#define TIME_H
#include <chrono>

namespace Time {
    void update();
    double dt();
}

class Timer {
    Timer() {
        m_startTime = std::chrono::high_resolution_clock::now();
        m_endTime = m_startTime;
    }
    Timer(const Timer& c) = delete;
    void operator=(const Timer& timer) = delete;

    std::chrono::high_resolution_clock::time_point m_startTime;
    std::chrono::high_resolution_clock::time_point m_endTime;
public:
    static Timer& getInstance() {
        static Timer instance;
        return instance;
    }

    void update();

    double dt();

    double nanoDt();
};


#endif //TIME_H
