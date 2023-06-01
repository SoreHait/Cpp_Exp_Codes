#include <iostream>
using namespace std;

class Date {
private:
    constexpr static const int day_per_month[2][13] = {
            {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
            {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    };
    int year = 0;
    int month = 0;
    int day = 0;
    bool isLeapyear();

public:
    Date operator+(int);
    Date operator-(int);
    int operator-(const Date&);
    friend ostream& operator<<(ostream&, const Date&);
    friend istream& operator>>(istream&, Date&);
};

bool Date::isLeapyear() {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

Date Date::operator+(const int d) {
    day += d;
    int daycount;
    while (day > (daycount = day_per_month[isLeapyear() ? 1 : 0][month])) {
        day -= daycount;
        month++;
        if (month > 12) {
            month -= 12;
            year++;
        }
    }
    return *this;
}

Date Date::operator-(const int d) {
    day -= d;
    while (day < 1) {
        month--;
        if (month < 1) {
            month += 12;
            year--;
        }
        day += day_per_month[isLeapyear() ? 1 : 0][month];
    }
    return *this;
}

int Date::operator-(const Date& d) {
    int y2, m2, d2;
    int y1, m1, d1;
    m1 = (d.month + 9) % 12;
    y1 = d.year - m1/10;
    d1 = 365*y1 + y1/4 - y1/100 + y1/400 + (m1*306 + 5)/10 + (d.day - 1);

    m2 = (month + 9) % 12;
    y2 = year - m2/10;
    d2 = 365*y2 + y2/4 - y2/100 + y2/400 + (m2*306 + 5)/10 + (day - 1);

    return (d2 - d1);
}

ostream &operator<<(ostream& output, const Date& d) {
    output << d.year << "-"
           << d.month << "-"
           << d.day;
    return output;
}

istream &operator>>(istream& input, Date& d) {
    input >> d.year >> d.month >> d.day;
    return input;
}

int main() {
    Date d1, d2;
    cin >> d1 >> d2;
    cout << d1 << endl << d2 << endl;
    cout << d2 - d1 << endl;
    cout << d1 - 72 << endl;
    cout << d2 + 72 << endl;
}
