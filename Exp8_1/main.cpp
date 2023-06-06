#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream input;
    input.open("input.txt", ios::in);
    ofstream output;
    output.open("output.txt", ios::out | ios::trunc);
    char data;
    while (input >> noskipws >> data) {
        if ('A' <= data && data <= 'Z') {
            data += 32;
        }
        else if ('a' <= data && data <= 'z') {
            data -= 32;
        }
        output << data;
    }
}
