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
        if (month < 12) {
            month += 12;
            year--;
        }
        day += day_per_month[isLeapyear() ? 1 : 0][month];
    }
    return *this;
}

int Date::operator-(const Date& d) {

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
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
