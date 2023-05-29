#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char name[20];
    char title[20];
    int hours;

    cin >> name >> title >> hours;
    int salary;
    if (strcmp(title, "教授") == 0) {
        salary = 100;
    }
    else if (strcmp(title, "副教授") == 0) {
        salary = 80;
    }
    else if (strcmp(title, "讲师") == 0) {
        salary = 60;
    }
    else if (strcmp(title, "助教") == 0) {
        salary = 40;
    }
    else {
        cout << "未知职位" << endl;
        return 1;
    }

    cout << name << title << "课酬" << salary * hours << "元" << endl;
    return 0;
}
