//
// Created by user on 28/04/15.
//
#define _POSIX_C_SOURCE 200809L

#include "date.h"

#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

long get_time() {
    long ms; // Milliseconds
    long s;  // Seconds
    struct timespec spec;

    clock_gettime(CLOCK_REALTIME, &spec);

    s  = spec.tv_sec;
    ms = spec.tv_nsec / 1.0e6; // Convert nanoseconds to milliseconds
    return (s*1000l) + ms;
}