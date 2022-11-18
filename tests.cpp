#include <iostream>
#include <string>
using namespace std;

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};
class Time { 
public:
    int h;
    int m;
};

class Movie { 
public: 
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};

int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
Time addMinutes(Time time0, int min);
void printTime(Time time);
void printMovie(Movie mv);
void printTimeSlot(TimeSlot ts);
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
bool timeOverlap(TimeSlot ts1, TimeSlot ts2); 

void printTime(Time time) {
    cout << time.h << ":" << time.m;
}

int minutesSinceMidnight(Time time){
    return (time.h * 60 + time.m);
}

int minutesUntil(Time earlier, Time later){
    return (minutesSinceMidnight(later) - minutesSinceMidnight(earlier));
}

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

void printTimeSlot(TimeSlot ts){
    printMovie(ts.movie); 
    cout << "[starts at "; printTime(ts.startTime); 
    cout << ", ends by "; printTime(addMinutes(ts.startTime, ts.movie.duration));
    cout << "]";
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    TimeSlot reschedule;
    reschedule.startTime = addMinutes(ts.startTime, ts.movie.duration);
    reschedule.movie = nextMovie;
    return reschedule; 
}

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

    printTimeSlot(morning);
    printTimeSlot(daytime);
    printTimeSlot(evening);
    printTimeSlot(afternoon);
    printTimeSlot(night);

    //Task D
    Movie movie5 = {"Murder mystery", ACTION, 97};
    printTimeSlot(scheduleAfter(afternoon, movie5));
    
    //Task E
    if(timeOverlap(morning, afternoon)){
        cout << "True." << endl;
    }
    else{
        cout << "False." << endl;
    }
    return 0;
}