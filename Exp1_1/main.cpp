#include <iostream>
using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int max(int a, int b, int c) {
    return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

int main() {
    cout << max(1, 2) << endl;
    cout << max(1, 2, 3) << endl;
}
