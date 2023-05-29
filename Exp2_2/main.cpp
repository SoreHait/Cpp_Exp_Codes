#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Student_Shallow {
private:
    int sno;
    char name[20]{};
    char sex;

public:
    Student_Shallow(int _sno, char* _name, char _sex);
    void show();
};

Student_Shallow::Student_Shallow(int _sno, char *_name, char _sex) {
    sno = _sno;
    strcpy(name, _name);
    sex = _sex;
}

void Student_Shallow::show() {
    cout << "学号: " << sno << endl
         << "姓名: " << name << endl
         << "性别: " << sex << endl;
}

class Student_Deep {
private:
    int sno;
    char* name;
    char sex;

public:
    Student_Deep(int _sno, char* _name, char _sex);
    Student_Deep(const Student_Deep& s);
    ~Student_Deep();
    void show();
};

Student_Deep::Student_Deep(int _sno, char *_name, char _sex) {
    sno = _sno;
    name = (char*)malloc(sizeof(char) * 20);
    strcpy(name, _name);
    sex = _sex;
}

Student_Deep::Student_Deep(const Student_Deep &s) {
    sno = s.sno;
    name = (char*)malloc(sizeof(char) * 20);
    strcpy(name, s.name);
    sex = s.sex;
}

Student_Deep::~Student_Deep() {
    free(name);
}

void Student_Deep::show() {
    cout << "学号: " << sno << endl
         << "姓名: " << name << endl
         << "性别: " << sex << endl;
}

int main() {
    char name[] = "abc";
    Student_Shallow ss = Student_Shallow(1, name, 'M');
    Student_Shallow ssc = Student_Shallow(ss);
    ss.show();
    ssc.show();

    Student_Deep sd = Student_Deep(1, name, 'M');
    Student_Deep sdc = Student_Deep(sd);
    sd.show();
    sdc.show();
}
