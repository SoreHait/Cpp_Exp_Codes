#include <iostream>
using namespace std;

class Point {
protected:
    float x, y;

public:
    Point(float, float);

    virtual void show();
    float area();
};

Point::Point(float _x, float _y) {
    x = _x;
    y = _y;
}

void Point::show() {
    cout << "x: " << x << "; "
         << "y: " << y << ";" << endl;
}

float Point::area() {
    return 0.0;
}

class Circle : public Point {
private:
    float r;

public:
    Circle(float, float, float);
    void show();
    float area();
};

Circle::Circle(float _x, float _y, float _r) : Point::Point(_x, _y) {
    r = _r;
}

void Circle::show() {
    cout << "x: " << x << "; "
         << "y: " << y << "; "
         << "r; " << r <<endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
