#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class student {
protected:
    int number;
    string name;
public:
    //輸入
    void set_number(int a);
    void set_name();
    //輸出
    int get_number();
    string get_name();
};

void student::set_number(int a) {
    number = a;
}

void student::set_name() {
    cout << "Please enter name:\n";
    cin.get();
    getline(cin, name);
    while (name[name.size() - 1] == ' ') {
        name.erase(name.size() - 1, 1);
    }
}

int student::get_number() {
    return number;
}

string student::get_name() {
    return name;
}

class STNODE1 : public student {
private:
    int prg, english, total;
    STNODE1* next;
public:
    //輸入
    void set_prg();
    void set_english();
    void set_total();
    void set_next(STNODE1* p);
    //輸出
    int get_prg();
    int get_english();
    int get_total();
    STNODE1* get_next();
    STNODE1() {
        prg = 0;
        english = 0;
        total = 0;
        next = NULL;
    }
};




void STNODE1::set_total() {
    total = prg + english;
}

void STNODE1::set_prg() {
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

void STNODE1::set_english() {
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

void STNODE1::set_next(STNODE1* p) {
    next = p;
}

int STNODE1::get_prg() {
    return prg;
}

int STNODE1::get_english() {
    return english;
}

int STNODE1::get_total() {
    return total;
}

STNODE1* STNODE1::get_next() {
    return next;
}

class STNODE2 : public student {//體育
private:
    int pe;
    STNODE2* next;
public:
    //輸入
    void set_pe();
    void set_next(STNODE2* p);
    //輸出
    int get_pe();
    STNODE2* get_next();
    STNODE2() {
        pe = 0;
        next = NULL;
    }
};

void STNODE2::set_pe() {
    int a;
    cout << "Please enter pe score:\n";
    cin >> a;
    if (a >= 0 && a <= 100)
        pe = a;
    else {
        cout << "wrong input,please enter again\n";
        set_pe();
    }
}

void STNODE2::set_next(STNODE2* p) {
    next = p;
}

int STNODE2::get_pe() {
    return pe;
}

STNODE2* STNODE2::get_next() {
    return next;
}


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

class linklist {
private:
    STNODE1* head;
    STNODE2* head_pe;
public:
    bool isempty() {
        return head;
    }
    bool isempty_pe() {
        return head_pe;
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
        head_pe = NULL;
    }
};

void linklist::enter() {
    int type;
    cout << "please select student deparement (CS -> enter 1 /PE -> enter 0)\n";
    cin >> type;
    while (type != 0 && type != 1) {
        cout << "error...Please enter again" << '\n';
        cin >> type;
    }
    if (type) {
        int n;
        cout << "Please enter no:\n";
        cin >> n;
        if (n <= 0)
            cout << "wrong input\n";
        else {
            if (!isempty()) {
                head = new STNODE1;
                head->set_number(n);
                head->set_prg();
                head->set_english();
                head->set_total();
                head->set_name();
                head->set_next(NULL);
            }
            else {
                STNODE1* p = new STNODE1;
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
                    STNODE1* find = head;
                    STNODE1* temp;
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
    else {
        int n;
        cout << "Please enter no:\n";
        cin >> n;
        if (n <= 0)
            cout << "wrong input\n";
        else {
            if (!isempty_pe()) {
                head_pe = new STNODE2;
                head_pe->set_number(n);
                head_pe->set_pe();
                head_pe->set_name();
                head_pe->set_next(NULL);
            }
            else {
                STNODE2* p = new STNODE2;
                p->set_number(n);
                if (head_pe->get_number() == n) {
                    cout << "same no exist\n\n";
                }
                else if (head_pe->get_number() > n) {
                    p->set_next(head_pe);
                    p->set_pe();
                    p->set_name();
                    head_pe = p;
                }
                else {
                    STNODE2* find = head_pe;
                    STNODE2* temp;
                    while (find->get_next() && find->get_next()->get_number() < n) {
                        find = find->get_next();
                    }
                    if (!(find->get_next())) {
                        find->set_next(p);
                        p->set_pe();
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
                        p->set_pe();
                        p->set_name();
                        p->set_next(temp);
                    }
                }
            }
        }
    }
}

int check(STNODE1* p) {
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

int check(STNODE2* p) {
    cout << "no:" << p->get_number() << '\n';
    cout << "name:" << p->get_name() << '\n';
    cout << "pe score:" << p->get_pe() << "\n\n";

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
    int type;
    cout << "please select student deparement (CS -> enter 1 /PE -> enter 0)\n";
    cin >> type;
    while (type != 0 && type != 1) {
        cout << "error...Please enter again" << '\n';
        cin >> type;
    }
    if (type) {
        if (!isempty())
            cout << "empty list\n\n";
        else {
            int n;
            STNODE1* temp;
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
                STNODE1* find = head;
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
    else {
        if (!isempty_pe())
            cout << "empty list\n\n";
        else {
            int n;
            STNODE2* temp;
            bool flag = true;
            cout << "Please enter student no:\n";
            cin >> n;
            if (head_pe->get_number() == n) {
                temp = head_pe;
                head_pe = head_pe->get_next();
                delete temp;
                flag = false;
                cout << "data deleted\n\n";
            }
            else {
                STNODE2* find = head_pe;
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
}

void linklist::Delete_name() {
    int type;
    cout << "please select student deparement (CS -> enter 1 /PE -> enter 0)\n";
    cin >> type;
    while (type != 0 && type != 1) {
        cout << "error...Please enter again" << '\n';
        cin >> type;
    }
    if (type) {
        if (!isempty())
            cout << "empty list\n\n";
        else {
            string n;
            STNODE1* temp;
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
                STNODE1* find = head;
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
    else {
        if (!isempty_pe())
            cout << "empty list\n\n";
        else {
            string n;
            STNODE2* temp;
            bool flag = true;
            cout << "Please enter student name:\n";
            cin >> n;
            if (head_pe->get_name() == n && check(head_pe)) {
                temp = head_pe;
                head_pe = head_pe->get_next();
                delete head_pe; //必要!!!
                flag = false;
                cout << "data deleted\n\n";
            }
            else {
                STNODE2* find = head_pe;
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
}

void linklist::see_node() {
    int type;
    cout << "please select student deparement (CS -> enter 1 /PE -> enter 0)\n";
    cin >> type;
    while (type != 0 && type != 1) {
        cout << "error...Please enter again" << '\n';
        cin >> type;
    }
    if (type) {
        if (!isempty())
            cout << "empty list\n\n";
        else {
            int n;
            cout << "Please enter student no:\n";
            cin >> n;
            STNODE1* find = head;
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
    else {
        if (!isempty_pe())
            cout << "empty list\n\n";
        else {
            int n;
            cout << "Please enter student no:\n";
            cin >> n;
            STNODE2* find = head_pe;
            while (find) {
                if (find->get_number() == n) {
                    cout << "no:" << find->get_number() << '\n';
                    cout << "name:" << find->get_name() << "\n";
                    cout << "pe score:" << find->get_pe() << "\n\n";
                    break;
                }
                else
                    find = find->get_next();
            }
            if (!find)
                cout << "student doesn't exist\n\n";
        }
    }
}

void linklist::see_name() {
    int type;
    cout << "please select student deparement (CS -> enter 1 /PE -> enter 0)\n";
    cin >> type;
    while (type != 0 && type != 1) {
        cout << "error...Please enter again" << '\n';
        cin >> type;
    }
    if (type) {
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
            STNODE1* find = head;
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
    else {
        if (!isempty_pe())
            cout << "empty list\n\n";
        else {
            string name;
            cout << "Please enter student name\n";
            cin.get();
            getline(cin, name);
            while (name[name.size() - 1] == ' ') {
                name.erase(name.size() - 1, 1);
            }
            STNODE2* find = head_pe;
            bool flag = true;
            while (find) {
                if (find->get_name() == name) {
                    cout << "no:" << find->get_number() << '\n';
                    cout << "name:" << find->get_name() << '\n';
                    cout << "pe score:" << find->get_pe() << "\n\n";
                    flag = false;
                }
                find = find->get_next();
            }
            if (flag) {
                cout << "student doesn't exist\n";
            }
        }
    }
}

bool compare(STNODE1 a, STNODE1 b) { //a->後項 b->前項
    if (a.get_total() == b.get_total())
        return a.get_number() < b.get_number();
    return a.get_total() > b.get_total();
}

bool compare_pe(STNODE2 a, STNODE2 b) { //a->後項 b->前項
    if (a.get_pe() == b.get_pe())
        return a.get_number() < b.get_number();
    return a.get_pe() > b.get_pe();
}


void linklist::Transcript() {
    int type;
    cout << "please select student deparement (CS -> enter 1 /PE -> enter 0)\n";
    cin >> type;
    while (type != 0 && type != 1) {
        cout << "error...Please enter again" << '\n';
        cin >> type;
    }
    if (type) {
        if (!isempty())
            cout << "empty list\n\n";
        else {

            int pcount = 0, h = 0;
            STNODE1* front = head;
            while (front) {
                pcount++;
                front = front->get_next();
            }
            STNODE1* p = new STNODE1[pcount];
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
    else {
        if (!isempty_pe())
            cout << "empty list\n\n";
        else {

            int pcount = 0, h = 0;
            STNODE2* front = head_pe;
            while (front) {
                pcount++;
                front = front->get_next();
            }
            STNODE2* p = new STNODE2[pcount];
            front = head_pe;
            while (front) {
                p[h] = *front;
                h++;
                front = front->get_next();
            }
            sort(p, p + h, compare_pe);

            int i = 0, ranking = 1, count = 0;
            //第1
            cout << "ranking:" << 1 << '\n';
            cout << "no:" << p[0].get_number() << '\n';
            cout << "name:" << p[0].get_name() << '\n';
            cout << "pe score:" << p[0].get_pe() << '\n';
            cout << '\n';
            //後續
            for (int j = 1; j < pcount; j++) {
                if (p[j].get_pe() == p[j - 1].get_pe())
                    count++;
                else {
                    ranking++;
                    ranking += count;
                    count = 0;
                }
                cout << "ranking:" << ranking << '\n';
                cout << "no:" << p[j].get_number() << '\n';
                cout << "name:" << p[j].get_name() << '\n';
                cout << "pe score:" << p[j].get_pe() << '\n';
                cout << '\n';
            }
        }
    }
}

void linklist::print() {
    int type;
    cout << "please select student deparement (CS -> enter 1 /PE -> enter 0)\n";
    cin >> type;
    if (type) {
        cout << "head->";
        STNODE1* p = head;
        while (p) {
            cout << p->get_number() << "->";
            p = p->get_next();
        }
        cout << "||\n\n";
    }
    else {
        cout << "head->";
        STNODE2* p = head_pe;
        while (p) {
            cout << p->get_number() << "->";
            p = p->get_next();
        }
        cout << "||\n\n";
    }
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