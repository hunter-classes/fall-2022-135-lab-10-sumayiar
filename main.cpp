#include <iostream>
#include <string>
#include "funcs.h"
using namespace std;

int main(){
    //Task A
    int hourOne, hourTwo, minuteOne, minuteTwo;
    Time firstTime = {hourOne, minuteOne};
    Time secondTime = {hourTwo, minuteTwo};

    cout << "Enter first time: " << endl;
    cin >> hourOne >> minuteOne;
    cout << "Enter second time: " << endl;
    cin >> hourTwo >> minuteTwo;

    cout << "These moments of time are " << minutesSinceMidnight(firstTime) << " and " << minutesSinceMidnight(secondTime) << " minutes after midnight. The interval between them is " << minutesUntil(firstTime, secondTime) << " minutes." << endl;
    
    //Task B
    Time old = {8,10};
    cout << "The new time is "; printTime(addMinutes(old, 75));
    cout << endl;

    //Task C
    Movie movie1 = {"White Chicks", COMEDY, 109};
    Movie movie2 = {"Me Before You", ROMANCE, 106};
    Movie movie3 = {"The Last Song", DRAMA, 107};
    Movie movie4 = {"No Strings Attached", COMEDY, 108};

    TimeSlot morning = {movie1, {10,30}};
    TimeSlot daytime = {movie2, {14,45}};
    TimeSlot evening = {movie3, {19,15}};
    TimeSlot afternoon = {movie4, {13,5}};
    TimeSlot night = {movie1, {21,30}};

    getTimeSlot(morning);
    getTimeSlot(daytime);
    getTimeSlot(evening);
    getTimeSlot(afternoon);
    getTimeSlot(night);

    //Task D
    Movie movie5 = {"Murder mystery", ACTION, 97};
    getTimeSlot(scheduleAfter(afternoon, movie5));
    
    //Task E
    if(timeOverlap(morning, afternoon)){
        cout << "True." << endl;
    }
    else{
        cout << "False." << endl;
    }
    return 0;
}