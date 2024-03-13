#include <iostream>

using namespace std;

class node {
private:
    int number;
    node* next;

public:
    void set_number(int a) {
        number = a;
    }
    void set_next(node* a) {
        next = a;
    }
    int get_number() {
        return number;
    }
    node* get_next() {
        return next;
    }

};

void printlist(node* p) {
    cout << "head->";
    while (p) {
        cout << p->get_number() << "->";
        p = p->get_next();
    }
    cout << "||\n";
}

int main()
{
    node* head = NULL;
    node* p;
    int n;
    while (1) {
        cout << "Please enter a number:\n";
        cin >> n;
        if (n<=0)
            break;
        p = new node;
        p->set_number(n);
        p->set_next(head);
        head = p;
    }
    printlist(head);

    return 0;
}