//
// Created by Randy Deng 12/13/16.
//

// Usage:
/*
 * calling constructor will immediately start the stopwatch
 * calling start will reset the timer and start recording again
 * calling stop returns time elapsed since the "start" time
 * records time in seconds
 *
 * Alternate between start and stop and add the time to calculate score
 */

#pragma once

#include <chrono>

template<typename TimeT = std::chrono::microseconds,
        typename ClockT=std::chrono::high_resolution_clock,
        typename DurationT=double>
class StopWatch
{
private:
    std::chrono::time_point<ClockT> _start, _end;
public:
    StopWatch();
    void start();
    DurationT restart();
    DurationT stop();
    DurationT elapsed() const;
};

template<typename TimeT, typename ClockT, typename DurationT>
StopWatch<TimeT, ClockT, DurationT>::StopWatch()
{
    start();
}

template<typename TimeT, typename ClockT, typename DurationT>
void StopWatch<TimeT, ClockT, DurationT>::start()
{
    _start = _end = ClockT::now();
}

template<typename TimeT, typename ClockT, typename DurationT>
DurationT StopWatch<TimeT, ClockT, DurationT>::stop()
{
    _end = ClockT::now();
    return elapsed()/1000;
}

template<typename TimeT, typename ClockT, typename DurationT>
DurationT StopWatch<TimeT, ClockT, DurationT>::restart()
{
    DurationT ret = stop();
    start();
    return ret/1000;
}

template<typename TimeT, typename ClockT, typename DurationT>
DurationT StopWatch<TimeT, ClockT, DurationT>::elapsed() const
{
    auto delta = std::chrono::duration_cast<TimeT>(_end-_start);
    return delta.count()/1000;
}