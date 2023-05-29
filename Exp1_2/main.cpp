#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

char* dupchar(char c, int n) {
    char* dupc = (char*)calloc(n + 1, sizeof(char));
    for (int i = 0; i < n; i++) {
        dupc[i] = c;
    }
    return dupc;
}

int main() {
    for (int i = 0; i <= 3; i++) {
        char* dupc = dupchar('*', i);
        cout << setw(4) << dupc << '*' << dupc << setw(4) << endl;
        free(dupc);
    }
    for (int i = 2; i >= 0; i--) {
        char* dupc = dupchar('*', i);
        cout << setw(4) << dupc << '*' << dupc << setw(4) << endl;
        free(dupc);
    }
}
