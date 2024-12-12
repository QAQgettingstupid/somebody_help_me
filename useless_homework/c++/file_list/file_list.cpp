#include <iostream>
#include <fstream>
#include <iomanip>
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

    //檔案輸入/輸出
    void set_name(string s);

};

void student::set_number(int a) {
    number = a;
}

void student::set_name(string s) {
    name = s;
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
    int prg, cmp, total;
    STNODE1* next;
public:
    //輸入
    void set_prg();
    void set_cmp();
    void set_total();
    void set_next(STNODE1* p);
    //輸出
    int get_prg();
    int get_cmp();
    int get_total();
    STNODE1* get_next();

    //檔案 輸入/輸出
    void set_prg(int a);
    void set_cmp(int a);
    void set_total(int a);

    STNODE1() {
        prg = 0;
        cmp = 0;
        total = 0;
        next = NULL;
    }
};




void STNODE1::set_total() {
    total = prg + cmp;
}

void STNODE1::set_total(int a) {
    total = a;
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

void STNODE1::set_prg(int a) {
    prg = a;
}

void STNODE1::set_cmp() {
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

void STNODE1::set_cmp(int a) {
    cmp = a;
}

void STNODE1::set_next(STNODE1* p) {
    next = p;
}

int STNODE1::get_prg() {
    return prg;
}

int STNODE1::get_cmp() {
    return cmp;
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

    //檔案 輸入/輸出
    void set_pe(int a);

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

void STNODE2::set_pe(int a) {
    pe = a;
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
    void in_file();
    void out_file();
    linklist() {
        head = NULL;
        head_pe = NULL;
        in_file();
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
                head->set_cmp();
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
                    p->set_cmp();
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
                        p->set_cmp();
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
                        p->set_cmp();
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
            cin.get();
            getline(cin, n);
            while (n[n.size() - 1] == ' ') {
                n.erase(n.size() - 1, 1);
            }
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
            cin.get();
            getline(cin, n);
            while (n[n.size() - 1] == ' ') {
                n.erase(n.size() - 1, 1);
            }
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
            cout << left << setw(10) << "ranking " << setw(21) << "name " << setw(5) << "no " << setw(5) << "total" << "\n\n";
            cout << setw(10) << 1 << setw(21) << p[0].get_name() << setw(5) << p[0].get_number() << setw(5) << p[0].get_total() << "\n";
            //後續
            for (int j = 1; j < pcount; j++) {
                if (p[j].get_total() == p[j - 1].get_total())
                    count++;
                else {
                    ranking++;
                    ranking += count;
                    count = 0;
                }
                cout << setw(10) << ranking << setw(21) << p[j].get_name() << setw(5) << p[j].get_number() << setw(5) << p[j].get_total() << "\n";
            }
            cout << '\n';
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
            cout << left << setw(10) << "ranking " << setw(21) << "name " << setw(5) << "no " << setw(5) << "score" << "\n\n";
            cout << setw(10) << 1 << setw(21) << p[0].get_name() << setw(5) << p[0].get_number() << setw(5) << p[0].get_pe() << "\n";
            //後續
            for (int j = 1; j < pcount; j++) {
                if (p[j].get_pe() == p[j - 1].get_pe())
                    count++;
                else {
                    ranking++;
                    ranking += count;
                    count = 0;
                }
                cout << setw(10) << ranking << setw(21) << p[j].get_name() << setw(5) << p[j].get_number() << setw(5) << p[j].get_pe() << "\n";
            }
            cout << '\n';
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

void linklist::in_file() {
    int number, prg, cmp, total, pe;
    string name;
    STNODE1* now = head;
    STNODE2* now_pe = head_pe;
    ifstream in_cs("cs.txt");
    ifstream in_pe("pe.txt");
    while (in_cs >> number && !in_cs.eof()) { //少了!in_cs.eof()會像zerojudge一樣無限輸入不會停止
        // number name prg cmp total
        getline(in_cs, name);
        getline(in_cs, name);
        in_cs >> prg;
        in_cs >> cmp;
        in_cs >> total;
        if (!isempty()) {
            head = new STNODE1;
            head->set_number(number);
            head->set_name(name);
            head->set_prg(prg);
            head->set_cmp(cmp);
            head->set_total(total);
            head->set_next(NULL);
            getline(in_cs, name); //讀掉多餘enter和空白鍵
            now = head;
        }
        else {
            STNODE1* p = new STNODE1;
            now->set_next(p);
            p->set_number(number);
            p->set_name(name);
            p->set_prg(prg);
            p->set_cmp(cmp);
            p->set_total(total);
            getline(in_cs, name); //讀掉多餘enter和空白鍵
            p->set_next(NULL);
            now = p;
        }
    }
    in_cs.close();
    while (in_pe >> number && !in_pe.eof()) { // number name pe
        getline(in_pe, name);
        getline(in_pe, name);
        in_pe >> pe;
        if (!isempty_pe()) {
            head_pe = new STNODE2;
            head_pe->set_number(number);
            head_pe->set_name(name);
            head_pe->set_pe(pe);
            head_pe->set_next(NULL);
            getline(in_pe, name); //讀掉多餘enter和空白鍵
            now_pe = head_pe;
        }
        else {
            STNODE2* p = new STNODE2;
            now_pe->set_next(p);
            p->set_number(number);
            p->set_name(name);
            p->set_pe(pe);
            p->set_next(NULL);
            getline(in_pe, name); //讀掉多餘enter和空白鍵
            now_pe = p;
        }
    }
    in_pe.close();
}

void linklist::out_file() {
    ofstream out_cs("cs.txt", ios_base::trunc);
    ofstream out_pe("pe.txt", ios_base::trunc);
    STNODE1* head_cs = head;
    STNODE2* head__pe = head_pe;
    while (head_cs) { // number name prg cmp total
        out_cs << head_cs->get_number() << "\n";
        out_cs << head_cs->get_name() << "\n";
        out_cs << head_cs->get_prg() << " ";
        out_cs << head_cs->get_cmp() << " ";
        out_cs << head_cs->get_total() << " \n\n";
        head_cs = head_cs->get_next();
    }
    out_cs.close();
    while (head_pe) { // number name pe
        out_pe << head_pe->get_number() << "\n";
        out_pe << head_pe->get_name() << "\n";
        out_pe << head_pe->get_pe() << " \n\n";
        head_pe = head_pe->get_next();
    }
    out_pe.close();
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
            list.out_file();
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