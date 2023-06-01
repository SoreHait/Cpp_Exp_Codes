#include <iostream>
#include <iomanip>
#include <unistd.h>
using namespace std;

class Timer {
public:
    int hours, minutes, seconds;
    Timer(int h, int m, int s) : hours(h), minutes(m), seconds(s) {};
    Timer operator--();
    friend ostream& operator<<(ostream&, const Timer&);
};

Timer Timer::operator--() {
    seconds--;
    if (seconds < 0) {
        minutes--;
        seconds += 60;
    }
    if (minutes < 0) {
        hours--;
        minutes += 60;
    }
    return *this;
}

ostream& operator<<(ostream& output, const Timer& t) {
    output << setfill('0')
           << setw(2) << t.hours << ":"
           << setw(2) << t.minutes << ":"
           << setw(2) << t.seconds;
    return output;
}

int main() {
    Timer t(0, 1, 30);
    while (1) {
        cout << t << endl;
        sleep(1);
        --t;
        if (t.hours == -1) {
            break;
        }
    }
}
