#include <iostream>

using namespace std;

class node{
    private:
        int number;
        node* next;
    public:
        void set_number(int a) {
            number = a;
        }
        void set_next(node* p) {
            next = p;
        }
        int get_number() {
            return number;
        }
        node* get_next() {
            return next;
        }

};

void print(node* head) {
    cout << "head->";
    if (!head) {
        cout << head->get_number() << "->";
        head = head->get_next();
    }
    cout << "||\n";
}

int main()
{
    node* head = NULL;
    node* mid;
    node* p;
    int n;
    while (1) {
        cin >> n;
        if (!n)
            break;
        if (!head) {
            head = new node;
            head->set_number(n);
            head->set_next(NULL);
        }
        else {
            p = new node;
            if (head->get_number() >= 1) {
                mid = head;
            }
        }
    }
    print(head);

    return 0;
}

