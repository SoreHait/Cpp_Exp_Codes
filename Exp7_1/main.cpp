#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define ARR_LEN 5
using namespace std;

template<class T, int LEN> class Array;
template<class T, int LEN> ostream& operator<<(ostream& output, const Array<T, LEN>& arr);

template<class T, int LEN>
class Array {
private:
    T* array;

public:
    Array(T* _array);
    ~Array();
    void sort();
    T max();
    T sum();
    friend ostream& operator<< <>(ostream& output, const Array<T, LEN>& arr);
};

template<class T, int LEN>
Array<T, LEN>::Array(T* _array) {
    array = (T*)malloc(sizeof(T) * LEN);
    memcpy(array, _array, sizeof(T) * LEN);
}

template<class T, int LEN>
Array<T, LEN>::~Array() {
    free(array);
}

template<class T, int LEN>
void Array<T, LEN>::sort() {
    std::sort(array, array + LEN);
}

template<class T, int LEN>
T Array<T, LEN>::max() {
    T max = array[0];
    for (int i = 1; i < LEN; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

template<class T, int LEN>
T Array<T, LEN>::sum() {
    T sum = 0;
    for (int i = 0; i < LEN; i++) {
        sum += array[i];
    }
    return sum;
}

template<class T, int LEN>
ostream& operator<<(ostream& output, const Array<T, LEN>& arr) {
    output << arr.array[0];
    for (int i = 1; i < LEN; i++) {
        output << " " << arr.array[i];
    }
    return output;
}

int main() {
    char arr_char[ARR_LEN] = {'C', 'H', 'E', 'L', 'A'};
    int arr_int[ARR_LEN] = {10, 34, 62, 9, 26};
    double arr_double[ARR_LEN] = {3.5, 6.7, 2.9, 10.3, 7.2};

    cout << "------Array<char>------" << endl;
    Array<char, ARR_LEN> a_char(arr_char);
    cout << a_char << endl;
    cout << "Max: " << a_char.max() << endl;
    a_char.sort();
    cout << a_char << endl;

    cout << "------Array<int>-------" << endl;
    Array<int, ARR_LEN> a_int(arr_int);
    cout << a_int << endl;
    cout << "Max: " << a_int.max() << endl;
    a_int.sort();
    cout << a_int << endl;
    cout << "Sum: " << a_int.sum() << endl;

    cout << "------Array<double>----" << endl;
    Array<double, ARR_LEN> a_double(arr_double);
    cout << a_double << endl;
    cout << "Max: " << a_double.max() << endl;
    a_double.sort();
    cout << a_double << endl;
    cout << "Sum: " << a_double.sum() << endl;
}
