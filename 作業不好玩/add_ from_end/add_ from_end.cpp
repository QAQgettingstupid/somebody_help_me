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
    node* head= NULL;
    node* p;
    node* end = head;
    int n;
    while (1) {
        cout << "Please enter a number:\n";
        cin >> n;
        if (n<=0)
            break;
        if (!head) {
            head = new node;
            head->set_number(n);
            head->set_next(NULL);
            end = head;
        }
        else {
            p = new node;
            end->set_next(p);
            p->set_number(n);
            p->set_next(NULL);
            end = p;
        }
    }

    /*  以下為中間插入新數字
    node* mid_front = head;
    node* mid_back = head;
    p = new node;
    while (mid_front->get_number() != 3) {
        mid_front = mid_front->get_next();
    }
    mid_back = mid_front->get_next();
    mid_front->set_next(p);
    p->set_number(44444444);
    p->set_next(mid_back);
    */
    printlist(head);

    return 0;
}