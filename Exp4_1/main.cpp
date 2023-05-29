#include <iostream>
#include <cmath>
using namespace std;

class Point {
public:
    double x, y;
    Point(double, double);
    virtual void show();
    virtual double area();
};

Point::Point(double _x, double _y) {
    x = _x;
    y = _y;
}

void Point::show() {
    cout << "x: " << x << "; "
         << "y: " << y << ";" << endl;
}

double Point::area() {
    return 0.0;
}

class Circle : public Point {
private:
    double r;

public:
    Circle(double, double, double);
    void show() override;
    double area() override;
};

Circle::Circle(double _x, double _y, double _r) : Point::Point(_x, _y) {
    r = _r;
}

void Circle::show() {
    cout << "x: " << x << "; "
         << "y: " << y << "; "
         << "r: " << r <<endl;
}

double Circle::area() {
    return M_PI * r * r;
}

class Segment {
private:
    Point *p1, *p2;

public:
    Segment(double, double, double, double);
    void show();
    double area();
    double length();
};

Segment::Segment(double x1, double y1, double x2, double y2) {
    p1 = new Point(x1, y1);
    p2 = new Point(x2, y2);
}

void Segment::show() {
    cout << "p1: ";
    p1->show();
    cout << "p2: ";
    p2->show();
}

double Segment::area() {
    return 0.0;
}

double Segment::length() {
    return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}

int main() {
    Point p(1.0, 2.0);
    p.show();
    cout << "area: " << p.area() << endl << endl;

    Circle c(1.0, 2.0, 3.0);
    c.show();
    cout << "area: " << c.area() << endl << endl;

    Segment s(1.0, 2.0, 3.0, 4.0);
    s.show();
    cout << "area: " << s.area() << endl;
    cout << "length: " << s.length() << endl;
}
