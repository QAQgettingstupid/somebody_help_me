#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class node {
private:
    int number, prg, cmp;
    double total;
    node* next;
    string name;
public:
    //輸入
    void set_number(int a);
    void set_prg();
    void set_cmp();
    void set_total();
    void set_name();
    void set_next(node* p);
    //輸出
    int get_number();
    int get_prg();
    int get_cmp();
    int get_total();
    node* get_next();
    string get_name();
    int operator+(node p) {
        return number + p.get_number();
    }
    node(int a = 0) {
        number = a;
    }
};

void node::set_number(int a) {
    number = a;
}

void node::set_total() {
    total = (prg + cmp) / 2;
}

void node::set_prg() {
    int a;
    cout << "Please enter prg score:\n";
    cin >> a;
    if (a >= 0 && a <= 100)
        prg = a;
    else {
        cout << "wrong input,please enter again\n";
        set_prg();
    }
}

void node::set_cmp() {
    int a;
    cout << "Please enter cmp score:\n";
    cin >> a;
    if (a >= 0 && a <= 100)
        cmp = a;
    else {
        cout << "wrong input,please enter again\n";
        set_cmp();
    }
}

void node::set_name() {
    cout << "Please enter name:\n";
    cin.get();
    getline(cin, name);
    while (name[name.size() - 1] == ' ') {
        name.erase(name.size() - 1, 1);
    }
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

int node::get_total() {
    return total;
}

node* node::get_next() {
    return next;
}

string node::get_name() {
    return name;
}

int menu() {
    int n;
    cout << "0 Exit:\n";
    cout << "1 Insert:\n";
    cout << "2 Delete(by no):\n";
    cout << "3 Delete(by name):\n";
    cout << "4 檢視串列:\n";
    cout << "5 Search(by no):\n";
    cout << "6 Search(by name):\n";
    cout << "7 Transcript(成績單):\n\n";
    cout << "Please select one of it:\n";
    cin >> n;
    cout << '\n';
    return n;
}

void enter(node*& head) {
    int n;
    cout << "Please enter no:\n";
    cin >> n;
    while (n <= 0) {
        cout << "wrong input,please enter again\n";
        cin >> n;
    }
    if (!head) {
        head = new node;
        head->set_number(n);
        head->set_prg();
        head->set_cmp();
        head->set_total();
        head->set_name();
        head->set_next(NULL);
    }
    else {
        node* p = new node;
        p->set_number(n);
        if (head->get_number() == n) {
            cout << "same no exist\n";
            enter(head);
        }
        else if (head->get_number() > n) {
            p->set_next(head);
            p->set_prg();
            p->set_cmp();
            p->set_total();
            p->set_name();
            head = p;
        }
        else {
            node* find = head;
            node* temp;
            while (find->get_next() && find->get_next()->get_number() < n) {
                find = find->get_next();
            }
            if (!(find->get_next())) {
                find->set_next(p);
                p->set_prg();
                p->set_cmp();
                p->set_total();
                p->set_name();
                p->set_next(NULL);
            }
            else if (find->get_next()->get_number() == n) {
                cout << "same no exist\n";
                enter(head);
            }
            else {
                temp = find->get_next();
                find->set_next(p);
                p->set_prg();
                p->set_cmp();
                p->set_total();
                p->set_name();
                p->set_next(temp);
            }
        }
    }
}

int check(node* p) {
    cout << "no:" << p->get_number() << '\n';
    cout << "name:" << p->get_name() << '\n';
    cout << "prg score:" << p->get_prg() << '\n';
    cout << "cmp score:" << p->get_cmp() << "\n";
    cout << "total:" << p->get_total() << "\n\n";

    int n;
    cout << "delete data? (yes -> enter 1 /no -> enter 0)" << '\n';
    cin >> n;
    while (n != 0 && n != 1) {
        cout << "error...Please enter again" << '\n';
        cin >> n;
    }
    if (n)
        return true;
    else
        return false;
}

void Delete_no(node*& head) {
    if (!head)
        cout << "empty list\n\n";
    else {
        int n;
        node* temp;
        bool flag = true;
        cout << "Please enter student no:\n";
        cin >> n;
        if (head->get_number() == n) {
            temp = head;
            head = head->get_next();
            delete temp;
            flag = false;
            cout << "data deleted\n\n";
        }
        else {
            node* find = head;
            while (find->get_next()) {
                if (find->get_next()->get_number() == n) {
                    temp = find->get_next();
                    find->set_next(find->get_next()->get_next());
                    delete temp;
                    flag = false;
                    cout << "data deleted\n\n";
                    break;
                }
                else
                    find = find->get_next();
            }
            if (!find->get_next() && flag)
                cout << "student doesn't exist\n\n";
        }
    }
}

void Delete_name(node*& head) {
    if (!head)
        cout << "empty list\n\n";
    else {
        string n;
        node* temp;
        bool flag = true;
        cout << "Please enter student name:\n";
        cin >> n;
        if (head->get_name() == n && check(head)) {
            temp = head;
            head = head->get_next();
            delete head; //必要!!!
            flag = false;
            cout << "data deleted\n\n";
        }
        else {
            node* find = head;
            while (find->get_next()) {
                if (find->get_next()->get_name() == n && check(find->get_next())) {
                    temp = find->get_next();
                    find->set_next(find->get_next()->get_next());
                    delete temp;
                    flag = false;
                    cout << "data deleted\n\n";
                    break;
                }
                else
                    find = find->get_next();
            }
            if (!find->get_next() && flag)
                cout << "student doesn't exist\n\n";
        }
    }
}

void see_node(node* head) {
    if (!head)
        cout << "empty list\n";
    else {
        int n;
        cout << "Please enter student no:\n";
        cin >> n;
        node* find = head;
        while (find) {
            if (find->get_number() == n) {
                cout << "no:" << find->get_number() << '\n';
                cout << "name:" << find->get_name() << '\n';
                cout << "prg score:" << find->get_prg() << '\n';
                cout << "cmp score:" << find->get_cmp() << "\n";
                cout << "total:" << find->get_total() << "\n\n";
                break;
            }
            else
                find = find->get_next();
        }
        if (!find)
            cout << "student doesn't exist\n\n";
    }
}

void see_name(node* head) {
    if (!head)
        cout << "empty list\n";
    else {
        string name;
        cout << "Please enter student name\n";
        cin.get();
        getline(cin, name);
        node* find = head;
        bool flag = true;
        while (find) {
            if (find->get_name() == name) {
                cout << "no:" << find->get_number() << '\n';
                cout << "name:" << find->get_name() << '\n';
                cout << "prg score:" << find->get_prg() << '\n';
                cout << "cmp score:" << find->get_cmp() << "\n";
                cout << "total:" << find->get_total() << "\n\n";
                flag = false;
            }
            find = find->get_next();
        }
        if (flag) {
            cout << "student doesn't exist\n";
        }
    }
}

bool compare(node a, node b) { //a->後項 b->前項
    if (a.get_total() == b.get_total())
        return a.get_number() < b.get_number();
    return a.get_total() > b.get_total();
}

void Transcript(node* head) {
    if (!head)
        cout << "empty list\n\n";
    else {
        node list[40];
        int i = 0, ranking = 1, count = 0;
        while (head) {
            list[i] = *head;
            i++;
            head = head->get_next();
        }
        sort(list, list + i, compare);

        //第1
        cout << "ranking:" << 1 << '\n';
        cout << "no:" << list[0].get_number() << '\n';
        cout << "name:" << list[0].get_name() << '\n';
        cout << "score:" << list[0].get_total() << '\n';
        cout << '\n';
        //後續
        for (int j = 1; j < i; j++) {
            if (list[j].get_total() == list[j - 1].get_total())
                count++;
            else {
                ranking++;
                ranking += count;
                count = 0;
            }
            cout << "ranking:" << ranking << '\n';
            cout << "no:" << list[j].get_number() << '\n';
            cout << "name:" << list[j].get_name() << '\n';
            cout << "score:" << list[j].get_total() << '\n';
            cout << '\n';
        }
    }
}

void print(node* head) {
    cout << "head->";
    while (head) {
        cout << head->get_number() << "->";
        head = head->get_next();
    }
    cout << "||\n\n";
}

int main()
{
    int n;
    node* head = NULL;
    do {
        n = menu();
        switch (n)
        {
        case 0:
            cout << "shutting down...\n";
            break;
        case 1:
            enter(head);
            break;
        case 2:
            Delete_no(head);
            break;
        case 3:
            Delete_name(head);
            break;
        case 4:
            print(head);
            break;
        case 5:
            see_node(head);
            break;
        case 6:
            see_name(head);
            break;
        case 7:
            Transcript(head);
            break;
        default:
            cout << "error...Please enter again\n";
        }
    } while (n);
    return 0;
}