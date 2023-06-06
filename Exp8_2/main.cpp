#include <iostream>
#include <fstream>
#define BOOK_COUNT 10
using namespace std;

class Book {
private:
    char title[256]{};
    char publisher[256]{};
    char author[256]{};

public:
    double price = -1;
    friend ostream& operator<<(ostream&, const Book&);
    friend istream& operator>>(istream&, Book&);
};

ostream& operator<<(ostream& output, const Book& b) {
    output << "Title: " << b.title << ";\t"
           << "Author: " << b.author << ";\t"
           << "Publisher: " << b.publisher << ";\t"
           << "Price: " << b.price;
    return output;
}

istream& operator>>(istream& input, Book& b) {
    input >> b.title >> b.publisher >> b.author >> b.price;
    return input;
}

fstream& operator<<(fstream& output, const Book& b) {
    output.write((char*)&b, sizeof(Book));
    return output;
}

fstream& operator>>(fstream& input, Book& b) {
    input.read((char*)&b, sizeof(Book));
    return input;
}

int main() {
    Book books[BOOK_COUNT];
    for (int i = 0; i < BOOK_COUNT; i++) {
        cin >> books[i];
    }

    fstream bookrecord;
    bookrecord.open("book.dat", ios::out | ios::trunc | ios::binary);
    for (int i = 0; i < BOOK_COUNT; i++) {
        bookrecord << books[i];
    }
    bookrecord.close();

    bookrecord.open("book.dat", ios::in | ios::binary);
    for (int i = 0; i < BOOK_COUNT; i++) {
        bookrecord >> books[i];
    }
    bookrecord.close();

    double sum = 0;
    for (int i = 0; i < BOOK_COUNT; i++) {
        sum += books[i].price;
    }
    cout << "Total Price: " << sum << endl;

    for (int i = 0; i < BOOK_COUNT; i++) {
        cout << books[i] << endl;
    }
}
