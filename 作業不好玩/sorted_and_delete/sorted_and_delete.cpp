#include <iostream>

using namespace std;

class node {
private:
    int number, prg, cmp;
    node* next;
    char name[10]; // 裡面有結束字元/0 故只能存9個char
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

void node::set_prg() {
    int a;
    cout << "請輸入程設分數:\n";
    cin >> a;
    prg = a;
}

void node::set_cmp() {
    int a;
    cout << "請輸入計概分數:\n";
    cin >> a;
    cmp = a;
}

void node::set_name() {
    cout << "請輸入名字:\n";
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

int menu() {
    int n;
    cout << "0 離開:\n";
    cout << "1 新增:\n";
    cout << "2 刪除:\n";
    cout << "3 檢視串列:\n";
    cout << "4 檢視串列總和:\n\n";
    cout << "請從中選一個:\n";
    cin >> n;
    cout << '\n';
    return n;
}

void enter(node*& head) {
    int n;
    cout << "請輸入要新增的數字:\n";
    cin >> n;
    if (!head) {
        head = new node;
        head->set_number(n);
        head->set_prg();
        head->set_cmp();
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
                p->set_name();
                p->set_next(temp);
            }
        }
    }
}

void Delete(node*& head) { 
    if (!head)
        cout << "此串列為空\n\n";
    else {
        int n;
        node* temp;
        cout << "請輸入要刪除的數字:\n";
        cin >> n;
        while (head && head->get_number() == n) {
            temp = head;
            head = head->get_next();
            delete temp;
        }
        node* find = head;
        while (find && find->get_next()) {
            if (find->get_next()->get_number() == n) {
                temp = find->get_next();
                find->set_next(find->get_next()->get_next());
                delete temp;
            }
            else
                find = find->get_next();
        }
    }

}

void add(node* head) {
    if (!head)
        cout << "串列數字和: " << 0 << '\n';
    else {
        node* sum = new node;
        sum->set_number(0);
        while (head) {
            sum->set_number(*head + *sum);
            head = head->get_next();
        }
        cout << "串列數字和: " << sum->get_number() << '\n';
        delete sum;
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
            cout << "關機中...\n";
            break;
        case 1:
            enter(head);
            break;
        case 2:
            Delete(head);
            break;
        case 3:
            print(head);
            break;
        case 4:
            add(head);
            break;
        default:
            cout << "錯誤...請再輸入一次\n";
        }
    } while (n);
    return 0;
}