#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class STNODE {
private:
    int number, prg, english, total;
    STNODE* next;
    string name;
public:
    //輸入
    void set_number(int a);
    void set_prg();
    void set_english();
    void set_total();
    void set_name();
    void set_next(STNODE* p);
    //輸出
    int get_number();
    int get_prg();
    int get_english();
    int get_total();
    STNODE* get_next();
    string get_name();
    STNODE() {
        prg = 0;
        english = 0;
        total = 0;
        next = NULL;
    }
};

void STNODE::set_number(int a) {
    number = a;
}

void STNODE::set_total() {
    total = prg + english;
}

void STNODE::set_prg() {
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

void STNODE::set_english() {
    int a;
    cout << "Please enter english score:\n";
    cin >> a;
    if (a >= 0 && a <= 100)
        english = a;
    else {
        cout << "wrong input,please enter again\n";
        set_english();
    }
}

void STNODE::set_name() {
    cout << "Please enter name:\n";
    cin.get();
    getline(cin, name);
    while (name[name.size() - 1] == ' ') {
        name.erase(name.size() - 1, 1);
    }
}

void STNODE::set_next(STNODE* p) {
    next = p;
}

int STNODE::get_number() {
    return number;
}

int STNODE::get_prg() {
    return prg;
}

int STNODE::get_english() {
    return english;
}

int STNODE::get_total() {
    return total;
}

STNODE* STNODE::get_next() {
    return next;
}

string STNODE::get_name() {
    return name;
}

class linklist {
private:
    STNODE* head;
public:
    bool isempty() {
        return head;
    }
    void enter();
    void Delete_no();
    void Delete_name();
    void see_node();
    void see_name();
    void Transcript();
    void print();
    linklist() {
        head = NULL;
    }
};


class MENU {
private:
    int n;

public:
    void show() {
        cout << "MENU\n\n";
        cout << "1 Insertion:\n";
        cout << "2 Search(by name):\n";
        cout << "3 Search(by no):\n";
        cout << "4 Deletion(by no):\n";
        cout << "5 Deletion(by name):\n";
        cout << "6 Print List Data:\n";
        cout << "7 Print Transcript:\n";
        cout << "0 Exit:\n";
        cout << "Please select one:\n\n";
    }
    int readselect() {
        return n;
    }
    void writeselect(int sl) {
        n = sl;
    }
    MENU() {
        n = 9;
    }
};

void linklist::enter() {
    int n;
    cout << "Please enter no:\n";
    cin >> n;
    if (n <= 0)
        cout << "wrong input\n";
    else {
        if (!isempty()) {
            head = new STNODE;
            head->set_number(n);
            head->set_prg();
            head->set_english();
            head->set_total();
            head->set_name();
            head->set_next(NULL);
        }
        else {
            STNODE* p = new STNODE;
            p->set_number(n);
            if (head->get_number() == n) {
                cout << "same no exist\n\n";
            }
            else if (head->get_number() > n) {
                p->set_next(head);
                p->set_prg();
                p->set_english();
                p->set_total();
                p->set_name();
                head = p;
            }
            else {
                STNODE* find = head;
                STNODE* temp;
                while (find->get_next() && find->get_next()->get_number() < n) {
                    find = find->get_next();
                }
                if (!(find->get_next())) {
                    find->set_next(p);
                    p->set_prg();
                    p->set_english();
                    p->set_total();
                    p->set_name();
                    p->set_next(NULL);
                }
                else if (find->get_next()->get_number() == n) {
                    cout << "same no exist\n";
                    enter();
                }
                else {
                    temp = find->get_next();
                    find->set_next(p);
                    p->set_prg();
                    p->set_english();
                    p->set_total();
                    p->set_name();
                    p->set_next(temp);
                }
            }
        }
    }
}

int check(STNODE* p) {
    cout << "no:" << p->get_number() << '\n';
    cout << "name:" << p->get_name() << '\n';
    cout << "prg score:" << p->get_prg() << '\n';
    cout << "cmp score:" << p->get_english() << "\n";
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

void linklist::Delete_no() {
    if (!isempty())
        cout << "empty list\n\n";
    else {
        int n;
        STNODE* temp;
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
            STNODE* find = head;
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

void linklist::Delete_name() {
    if (!isempty())
        cout << "empty list\n\n";
    else {
        string n;
        STNODE* temp;
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
            STNODE* find = head;
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

void linklist::see_node() {
    if (!isempty())
        cout << "empty list\n\n";
    else {
        int n;
        cout << "Please enter student no:\n";
        cin >> n;
        STNODE* find = head;
        while (find) {
            if (find->get_number() == n) {
                cout << "no:" << find->get_number() << '\n';
                cout << "name:" << find->get_name() << '\n';
                cout << "prg score:" << find->get_prg() << '\n';
                cout << "english score:" << find->get_english() << "\n";
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

void linklist::see_name() {
    if (!isempty())
        cout << "empty list\n\n";
    else {
        string name;
        cout << "Please enter student name\n";
        cin.get();
        getline(cin, name);
        while (name[name.size() - 1] == ' ') {
            name.erase(name.size() - 1, 1);
        }
        STNODE* find = head;
        bool flag = true;
        while (find) {
            if (find->get_name() == name) {
                cout << "no:" << find->get_number() << '\n';
                cout << "name:" << find->get_name() << '\n';
                cout << "prg score:" << find->get_prg() << '\n';
                cout << "cmp score:" << find->get_english() << "\n";
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

bool compare(STNODE a, STNODE b) { //a->後項 b->前項
    if (a.get_total() == b.get_total())
        return a.get_number() < b.get_number();
    return a.get_total() > b.get_total();
}


void linklist::Transcript() {
    if (!isempty())
        cout << "empty list\n\n";
    else {

        int pcount = 0, h = 0;
        STNODE* front = head;
        while (front) {
            pcount++;
            front = front->get_next();
        }
        STNODE* p = new STNODE[pcount];
        front = head;
        while (front) {
            p[h] = *front;
            h++;
            front = front->get_next();
        }
        sort(p, p + h, compare);

        int i = 0, ranking = 1, count = 0;
        //第1
        cout << "ranking:" << 1 << '\n';
        cout << "no:" << p[0].get_number() << '\n';
        cout << "name:" << p[0].get_name() << '\n';
        cout << "total:" << p[0].get_total() << '\n';
        cout << '\n';
        //後續
        for (int j = 1; j < pcount; j++) {
            if (p[j].get_total() == p[j - 1].get_total())
                count++;
            else {
                ranking++;
                ranking += count;
                count = 0;
            }
            cout << "ranking:" << ranking << '\n';
            cout << "no:" << p[j].get_number() << '\n';
            cout << "name:" << p[j].get_name() << '\n';
            cout << "score:" << p[j].get_total() << '\n';
            cout << '\n';
        }
    }
}

void linklist::print() {
    cout << "head->";
    STNODE* p = head;
    while (p) {
        cout << p->get_number() << "->";
        p = p->get_next();
    }
    cout << "||\n\n";
}

int main()
{
    int n;
    linklist list;
    MENU menu;
    while (menu.readselect()) {
        menu.show();
        cin >> n;
        while (n > 7 || n < 0) {
            cout << "wrong input,please enter again\n\n";
            menu.show();
            cin >> n;
        }
        menu.writeselect(n);
        switch (menu.readselect())
        {
        case 0:
            cout << "shutting down...\n";
            break;
        case 1:
            list.enter();
            break;
        case 2:
            list.see_name();
            break;
        case 3:
            list.see_node();
            break;
        case 4:
            list.Delete_no();
            break;
        case 5:
            list.Delete_name();
            break;
        case 6:
            list.print();
            break;
        case 7:
            list.Transcript();
            break;
        }
    }
    return 0;
}