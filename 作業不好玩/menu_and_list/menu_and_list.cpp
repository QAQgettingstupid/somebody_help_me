#include <iostream>
#include <cstring>

using namespace std;

class node {
private:
    int number, prg, cmp, total;
    node* next;
    char name[20];
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
    char* get_name();
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
    total = prg + cmp;
}

void node::set_prg() {
    int a;
    cout << "請輸入程設分數:\n";
    cin >> a;
    if (a >= 0 && a <= 100)
        prg = a;
    else {
        cout << "沒有這種分數,請重新輸入\n";
        set_prg();
    }
}

void node::set_cmp() {
    int a;
    cout << "請輸入計概分數:\n";
    cin >> a;
    if (a >= 0 && a <= 100)
        cmp = a;
    else {
        cout << "沒有這種分數,請重新輸入\n";
        set_cmp();
    }
}

void node::set_name() {
    cout << "請輸入名字:\n";
    cin.get();
    cin.getline(name, 20);
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

char* node::get_name() {
    return name;
}

class menu {
private:
    int select;
public:
    void show() {
        cout << "0 離開:\n";
        cout << "1 新增:\n";
        cout << "2 檢視節點資料(以姓名):\n\n";
        cout << "請從中選一個:\n";
    }
    void cin_select() {
        cin >> select;
    }
    int show_select() {
        return select;
    }
    menu() {
        select = 1;
    }
};

void enter(node*& head) {
    int n;
    cout << "請輸入要新增的座號:\n";
    cin >> n;
    while (n <= 0) {
        cout << "座號要大於0,請重新輸入\n";
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
            cout << "已存在相同號碼\n";
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
                cout << "已存在相同號碼\n";
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

int main()
{
    menu m;
    int n;
    node* head = NULL;
    while (m.show_select()) {
        m.show();
        m.cin_select();
        switch (m.show_select()) {
        case 0:
            cout << "關機中...";
            break;
        case 1:
            enter(head);
            break;
        case 2:
            cout << "查詢中...(目前沒有用)\n\n";
            break;
        default:
            cout << "錯誤...請再輸入一次\n\n";
        }
    }
    return 0;
}
