#include <iostream>
using namespace std;

class LinkListNode {
    friend class LinkList;

private:
    int data;
    LinkListNode* next;
};

class LinkList {
private:
    LinkListNode* head;
    int length;

public:
    LinkList();
    void insert(int data);
    void append(int data);
    void concat(LinkList list);
    void print();
    void print_reverse();
    int get_len() const;
};

LinkList::LinkList() {
    head = new LinkListNode;
    head->next = nullptr;
    length = 0;
}

void LinkList::insert(int data) {
    LinkListNode* node = new LinkListNode;
    node->data = data;
    node->next = head->next;
    head->next = node;
    length++;
}

void LinkList::append(int data) {
    LinkListNode* node = new LinkListNode;
    node->data = data;
    node->next = nullptr;
    LinkListNode* p = head;
    while (p->next != nullptr) {
        p = p->next;
    }
    p->next = node;
    length++;
}

void LinkList::concat(LinkList list) {
    LinkListNode* p = head;
    while (p->next != nullptr) {
        p = p->next;
    }
    p->next = list.head->next;
    length += list.length;
}

void LinkList::print() {
    LinkListNode* p = head->next;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void LinkList::print_reverse() {
    int* arr = new int[length];
    LinkListNode* p = head->next;
    for (int i = 0; i < length; i++) {
        arr[i] = p->data;
        p = p->next;
    }
    for (int i = length - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int LinkList::get_len() const {
    return length;
}

int main() {
    LinkList list1 = LinkList();
    LinkList list2 = LinkList();
    int n;
    cout << "Length of list1: ";
    cin >> n;
    cout << "Input list1: ";
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        list1.append(data);
    }
    cout << "Length of list2: ";
    cin >> n;
    cout << "Input list2: ";
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        list2.append(data);
    }
    list1.print();
    list2.print_reverse();
    list1.concat(list2);
    list1.insert(30);
    list1.append(40);
    list1.print();
    cout << list1.get_len() << endl;
    return 0;
}
