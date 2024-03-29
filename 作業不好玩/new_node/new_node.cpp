#include <iostream>

using namespace std;

class node {
private:
    int number, prg, cmp;
    char name[10];
    node* next;
public:
    //輸入
    void set_number(int a);
    void set_prg();
    void set_cmp();
    void set_name();
    void set_next(node* p);
    //輸出
    int get_number();
    int get_prg();
    int get_cmp();
    node* get_next();
    char* get_name();

};

void node::set_number(int a) {
    number = a;
}

void node::set_prg() {
    int a;
    cout << "Please enter prg score:\n";
    cin >> a;
    prg = a;
}

void node::set_cmp() {
    int a;
    cout << "Please enter cmp score:\n";
    cin >> a;
    cmp = a;
}

void node::set_name() {
    cout << "Please enter name:\n";
    cin >> name;
}

void node::set_next(node* p) {
    next = p;
}

int node::get_number() {
    return number;
}

int node::get_prg() {
    return prg;
}

int node::get_cmp() {
    return cmp;
}

node* node::get_next() {
    return next;
}

char* node::get_name() {
    return name;
}

void print(node* head) {
    cout << "head->";
    while (head) {
        cout << head->get_number() << "->";
        head = head->get_next();
    }
    cout << "||\n";
}

int main(){
    node* head = NULL;
    node* mid;
    node* find;
    node* p;
    int n;
    while (1) {
        cout << "Please enter number:\n";
        cin >> n;
        if (n <= 0)
            break;
        if (!head) {
            head = new node;
            head->set_number(n);
            head->set_prg();
            head->set_cmp();
            head->set_name();
            head->set_next(NULL);
        }
        else {
            bool flag = false;
            p = new node;
            p->set_number(n);
            if (head->get_number() == n)
                flag = true;
            else if (head->get_number() > n) {
                p->set_next(head);
                p->set_prg();
                p->set_cmp();
                p->set_name();
                head = p;
            }
            else {
                find = head;
                while (find->get_next() && find->get_next()->get_number() < n) {
                    find = find->get_next();
                }
                if (!(find->get_next())) {
                    find->set_next(p);
                    p->set_prg();
                    p->set_cmp();
                    p->set_name();
                    p->set_next(NULL);
                }
                else if (find->get_next()->get_number() == n)
                    flag = true;
                else {
                    mid = find->get_next();
                    find->set_next(p);
                    p->set_next(mid);
                    p->set_prg();
                    p->set_cmp();
                    p->set_name();
                }
            }
            if (flag) {
                cout << "same no exist\n";
            }
        }
    }
    print(head);

    return 0;
}
