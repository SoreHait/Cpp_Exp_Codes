#include <iostream>
#include <vector>
using namespace std;

class Counter {
private:
    int num;
    int quantity;
    double price;
    static int n;
    static double sum;
public:
    static double discount;
    Counter(int num_, int quantity_, double price_);
    void calc_sum() const;
    static double average();
    static void display();
};
int Counter::n = 0;
double Counter::sum = 0.0;
double Counter::discount = 1.0;

Counter::Counter(int num_, int quantity_, double price_) {
    num = num_;
    quantity = quantity_;
    price = price_;
}

void Counter::calc_sum() const {
    if (quantity > 10) {
        sum += quantity * price * discount * 0.98;
        n += quantity;
    }
    else {
        sum += quantity * price * discount;
        n += quantity;
    }
}

double Counter::average() {
    return sum / n;
}

void Counter::display() {
    cout << "Average price: " << Counter::average() << endl;
    cout << "Grand total: " << sum << endl;
}

int main() {
    cout << "Today's discount? ";
    cin >> Counter::discount;
    int n_seller;
    cout << "Number of sellers? ";
    cin >> n_seller;
    vector<Counter> counters;
    for (int i = 0; i < n_seller; i++) {
        int num, quantity;
        double price;
        cout << "Seller " << i + 1 << ":" << endl;
        cout << "num = ";
        cin >> num;
        cout << "quantity = ";
        cin >> quantity;
        cout << "price = ";
        cin >> price;
        Counter counter = Counter(num, quantity, price);
        counters.push_back(counter);
    }

    for (int i = 0; i < n_seller; i++) {
        counters[i].calc_sum();
    }

    Counter::display();
}
