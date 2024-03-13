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
    while (head) {
        cout << head->get_number() << "->";
        head = head->get_next();
    }
    cout << "||\n";
}

int main()
{
    node* head = NULL;
    node* mid;
    node* find;
    node* p;
    int n;
    while (1) {
        cout << "Please enter number:\n";
        cin >> n;
        if (n<=0)
            break;
        if (!head) {
            head = new node;
            head->set_number(n);
            head->set_next(NULL);
        }
        else {
            p = new node;
            p->set_number(n);
            if (head->get_number() >= n) {
                p->set_next(head);
                head = p;
            }
            else {
                find = head;
                while (find->get_next()) {
                    if ((find->get_next())->get_number() >= n) {
                        mid = find->get_next();
                        find->set_next(p);
                        p->set_next(mid);
                        break;
                    }
                    find = find->get_next();
                }
                if (!(find->get_next())) {
                    find->set_next(p);
                    p->set_next(NULL);
                }
            }           
        }
    }
    print(head);

    return 0;
}

