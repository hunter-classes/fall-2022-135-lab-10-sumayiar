#include <iostream>
#include <string>
#include "funcs.h"
#include "movie.h"
#include "timeslot.h"
#include "time.h"
using namespace std;

//Printing functions
void printMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

void printTime(Time time) {
    cout << time.h << ":" << time.m;
}

//Task A
int minutesSinceMidnight(Time time){
    return (time.h * 60 + time.m);
}

int minutesUntil(Time earlier, Time later){
    return (minutesSinceMidnight(later) - minutesSinceMidnight(earlier));
}

//Task B
Time addMinutes(Time time0, int min){
    Time newTime;
    newTime.h = time0.h;
    newTime.m = time0.m;
    int addedMinutes = min;
    
    while(addedMinutes >= 60){
        newTime.h++; //counts the hours by grouping minutes into 60
        addedMinutes -= 60;
    }
    if (time0.m + addedMinutes >= 60){
        newTime.h++;
        addedMinutes = newTime.m + addedMinutes - 60;
        newTime.m = addedMinutes;
    }
    else{
        newTime.m = newTime.m + addedMinutes;
    }
    return newTime;
}

//Task C
void getTimeSlot(TimeSlot ts){
    printMovie(ts.movie); 
    cout << "[starts at "; printTime(ts.startTime); 
    cout << ", ends by "; printTime(addMinutes(ts.startTime, ts.movie.duration));
    cout << "]";
}

//Task D
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    TimeSlot reschedule;
    reschedule.startTime = addMinutes(ts.startTime, ts.movie.duration);
    reschedule.movie = nextMovie;
    return reschedule; 
}

//Task E
bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
    if(minutesUntil(ts1.startTime, ts2.startTime) > 0){
        if (ts1.movie.duration > minutesUntil(ts1.startTime, ts2.startTime)){
            return true;
        }
    }
    else{
        if (ts2.movie.duration > minutesUntil(ts2.startTime, ts1.startTime)){
            return true;
        }
    }
    return false;
}


