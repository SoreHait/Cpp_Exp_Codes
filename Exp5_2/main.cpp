#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double area()=0;
    virtual void show()=0;
};

class Triangle : public Shape {
private:
    double a, b, c;

public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {};
    double area() override;
    void show() override;
};

double Triangle::area() {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void Triangle::show() {
    cout << "Length of each side of triangle: "
         << a << " " << b << " " << c << endl;
}

class Rectangle : public Shape {
private:
    double a, b;

public:
    Rectangle(double a, double b) : a(a), b(b) {};
    double area() override;
    void show() override;
};

double Rectangle::area() {
    return a * b;
}

void Rectangle::show() {
    cout << "Length of each side of rectangle: "
         << a << " " << b << endl;
}

class Circle : public Shape {
private:
    double r;

public:
    Circle(double r) : r(r) {};
    double area() override;
    void show() override;
};

double Circle::area() {
    return M_PI * r * r;
}

void Circle::show() {
    cout << "Radius of circle: " << r << endl;
}

double total(Shape* s[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += s[i]->area();
    }
    return sum;
}

int main() {
    Shape* s[3];
    s[0] = new Triangle(3, 4, 5);
    s[1] = new Rectangle(3, 4);
    s[2] = new Circle(5);
    for (int i = 0; i < 3; i++) {
        s[i]->show();
        cout << "Area: " << s[i]->area() << endl;
    }
    cout << "Total area: " << total(s, 3) << endl;
}
