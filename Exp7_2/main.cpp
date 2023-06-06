#include <iostream>
#define MAX_LEN 10
using namespace std;

template<class T> class Queue;
template<class T> ostream& operator<<(ostream&, const Queue<T>&);

class CapacityExceedException : public exception {
public:
    const char* what() const noexcept override {
        return "This queue only holds up to 10 elements.";
    }
};

class EmptyQueueException : public exception {
public:
    const char* what() const noexcept override {
        return "This queue has no element at this time.";
    }
};

template<class T>
class QueueNode {
private:
    QueueNode<T>* prev;
    QueueNode<T>* next;
    T data;

public:
    QueueNode();
    QueueNode(T element);
    friend class Queue<T>;
    friend ostream& operator<< <>(ostream& out, const Queue<T>& q);
};

template<class T>
QueueNode<T>::QueueNode() {
    prev = nullptr;
    next = nullptr;
    T empty;
    data = empty;
}

template<class T>
QueueNode<T>::QueueNode(T element) {
    prev = nullptr;
    next = nullptr;
    data = element;
}

template<class T>
class Queue {
private:
    QueueNode<T>* head;
    QueueNode<T>* tail;
    int length;

public:
    Queue();
    ~Queue();
    void enqueue(T element);
    T dequeue();
    friend ostream& operator<< <>(ostream& out, const Queue<T>& q);
};

template<class T>
Queue<T>::Queue() {
    length = 0;
    head = new QueueNode<T>();
    tail = new QueueNode<T>();
    head->next = tail;
    tail->prev = head;
}

template<class T>
Queue<T>::~Queue() {
    QueueNode<T>* nextnode = head->next;
    QueueNode<T>* currentnode;
    for (int i = 0; i < length; i++) {
        currentnode = nextnode;
        nextnode = currentnode->next;
        delete currentnode;
    }
    delete head;
    delete tail;
}

template<class T>
void Queue<T>::enqueue(T element) {
    if (length >= MAX_LEN) {
        throw CapacityExceedException();
    }
    QueueNode<T>* newnode = new QueueNode<T>(element);
    head->next->prev = newnode;
    newnode->next = head->next;
    head->next = newnode;
    newnode->prev = head;
    length++;
}

template<class T>
T Queue<T>::dequeue() {
    if (length <= 0) {
        throw EmptyQueueException();
    }
    QueueNode<T>* delnode = tail->prev;
    T element = delnode->data;
    delnode->prev->next = tail;
    tail->prev = delnode->prev;
    delete delnode;
    length--;
    return element;
}

template<class T>
ostream& operator<<(ostream& out, const Queue<T>& q) {
    if (q.length <= 0) {
        out << "Empty Queue";
    }
    else {
        QueueNode<T> *ptr = q.head->next;
        out << ptr->data;
        for (int i = 1; i < q.length; i++) {
            ptr = ptr->next;
            out << " " << ptr->data;
        }
    }
    return out;
}

int main() {
    Queue<int> queue;
    cout << queue << endl;
    try {
        queue.dequeue();
    } catch (EmptyQueueException& e) {
        cout << e.what() << endl;
    }
    for (int i = 0; i < MAX_LEN; i++) {
        int tmp = i + 1;
        queue.enqueue(tmp);
    }
    cout << queue << endl;
    try {
        queue.enqueue(123);
    } catch (CapacityExceedException& e) {
        cout << e.what() << endl;
    }
}
