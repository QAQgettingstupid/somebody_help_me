//plaese run the program in visual studio
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class Merch {
protected:
    int no, price, ammount;
    string name;
public:

    //輸入
    void set_no(int a);
    void set_name();
    void set_name(string a);
    void set_price();
    void set_price(int a);
    void set_ammount();
    void set_ammount(int a);

    //輸出
    int get_no();
    string get_name();
    int get_price();
    int get_ammount();

    //功能
    void add_ammount(int a);
    void decrease_ammount(int a);

    Merch() {
        price = 0;
        ammount = 0;
    }
};

void Merch::set_no(int a) {
    no = a;
}

int Merch::get_no() {
    return no;
}

void Merch::set_price() {
    int a;
    cout << "please enter price:\n";
    cin >> a;
    while (a < 0) {
        cout << "wrong input\n";
        cout << "please enter price:\n";
        cin >> a;
    }
    price = a;
}

void Merch::set_price(int a) {
    price = a;
}

int Merch::get_price() {
    return price;
}

void Merch::set_ammount() {
    int a;
    cout << "please enter ammount:\n";
    cin >> a;
    while (a < 0) {
        cout << "wrong input\n";
        cout << "please enter ammount:\n";
        cin >> a;
    }
    ammount = a;
}

void Merch::set_ammount(int a) {
    ammount = a;
}

void Merch::add_ammount(int a) {
    ammount += a;
}

void Merch::decrease_ammount(int a) {
    ammount -= a;
}

int Merch::get_ammount() {
    return ammount;
}

void Merch::set_name() {
    cout << "Please enter name:\n";
    cin.get();
    getline(cin, name);
    while (name[name.size() - 1] == ' ') {
        name.erase(name.size() - 1, 1);
    }
}

void Merch::set_name(string a) {
    name = a;
}

string Merch::get_name() {
    return name;
}


class Food : public Merch {
private:
    double date;
    Food* next;

public:

    //輸入
    void set_date();
    void set_date(double a);
    void set_next(Food* a);

    //輸出
    double get_date();
    Food* get_next();

    Food() {
        date = 0;
        next = NULL;
    }
};

void Food::set_date() {
    double a;
    cout << "please enter date:\n";
    cin >> a;
    while (a < 0) {
        cout << "wrong input\n";
        cout << "please enter date:\n";
        cin >> a;
    }
    date = a;
}

void Food::set_date(double a) {
    date = a;
}

double Food::get_date() {
    return date;
}

void Food::set_next(Food* a) {
    next = a;
}

Food* Food::get_next() {
    return next;
}


class list {
private:
    Food* head;
public:

    //功能
    void enter();
    void see_name();
    void Delete_no();
    void print();
    void purchase();
    void ship();

    //子功能
    void add(Food* a);
    void decrease(Food* a);
    bool isempty();

    //檔案匯入匯出
    void in_file();
    void out_file();

    list() {
        head = NULL;
        in_file();
    }
};

bool list::isempty() {
    return head;
}

void list::enter() {
    int n;
    cout << "Please enter no:\n";
    cin >> n;
    while (n < 0) {
        cout << "wrong input\n";
        cout << "Please enter no:\n";
        cin >> n;
    }
    if (!isempty()) {
        head = new Food;
        head->set_no(n);
        head->set_name();
        head->set_ammount();
        head->set_price();
        head->set_date();
        head->set_next(NULL);
    }
    else {
        Food* p = new Food;
        p->set_no(n);
        if (head->get_no() == n) {
            cout << "same no exist\n\n";
        }
        else if (head->get_no() > n) {
            p->set_next(head);
            p->set_name();
            p->set_ammount();
            p->set_price();
            p->set_date();
            head = p;
        }
        else {
            Food* find = head;
            Food* temp;
            while (find->get_next() && find->get_next()->get_no() < n) {
                find = find->get_next();
            }
            if (!(find->get_next())) {
                find->set_next(p);
                p->set_name();
                p->set_ammount();
                p->set_price();
                p->set_date();
                p->set_next(NULL);
            }
            else if (find->get_next()->get_no() == n) {
                cout << "same no exist\n";
            }
            else {
                temp = find->get_next();
                find->set_next(p);
                p->set_name();
                p->set_ammount();
                p->set_price();
                p->set_date();
                p->set_next(temp);
            }
        }
    }
}

void list::see_name() {
    if (!isempty())
        cout << "目前沒有任何產品\n\n";
    else {
        string name;
        cout << "Please enter name\n";
        cin.get();
        getline(cin, name);
        while (name[name.size() - 1] == ' ') {
            name.erase(name.size() - 1, 1);
        }
        Food* find = head;
        bool flag = true, first = true;
        while (find) {
            if (find->get_name() == name) {

                if (first) {
                    cout << setw(5) << "編號" << setw(22) << "產品名稱 " << setw(10) << "有效期限 " << setw(6) << "價格 " << setw(6) << " 庫存\n";
                    first = false;
                }
                cout << setw(5) << find->get_no() << setw(21) << find->get_name() << setw(10) << find->get_date() << setw(6) << find->get_price() << setw(6) << find->get_ammount() << "\n";
                flag = false;
            }
            find = find->get_next();
        }
        if (flag) {
            cout << "該產品不存在\n";
        }
    }
}

void list::Delete_no() {
    if (!isempty())
        cout << "目前沒有任何產品\n\n";
    else {
        int n;
        Food* temp;
        bool flag = true;
        cout << "請輸入產品編號:\n";
        cin >> n;
        if (head->get_no() == n) {
            temp = head;
            head = head->get_next();
            delete temp;
            flag = false;
            cout << "該筆資料已刪除\n\n";
        }
        else {
            Food* find = head;
            while (find->get_next()) {
                if (find->get_next()->get_no() == n) {
                    temp = find->get_next();
                    find->set_next(find->get_next()->get_next());
                    delete temp;
                    flag = false;
                    cout << "該筆資料已刪除\n\n";
                    break;
                }
                else
                    find = find->get_next();
            }
            if (!find->get_next() && flag)
                cout << "該產品不存在\n\n";
        }
    }
}

void list::add(Food* node) {
    int a;
    cout << "請輸入要進的數量:\n\n";
    cin >> a;
    while (a < 0) {
        cout << "輸入錯誤請再試一次\n\n";
        cout << "請輸入要進的數量:\n\n";
        cin >> a;
    }
    node->add_ammount(a);
}

void list::purchase() {
    if (!isempty())
        cout << "目前沒有任何產品\n\n";
    else {
        int n;
        bool flag = true;
        cout << "請輸入產品編號:\n";
        cin >> n;
        if (head->get_no() == n) {
            add(head);
            flag = false;
        }
        else {
            Food* find = head;
            while (find) {
                if (find->get_no() == n) {
                    add(find);
                    break;
                }
                else
                    find = find->get_next();
            }
            if (!find && flag)
                cout << "該產品不存在，無法進貨\n\n";
        }
    }
}

void list::decrease(Food* node) {
    int a;
    cout << "請輸入要出貨的數量:\n\n";
    cin >> a;
    while (a < 0) {
        cout << "輸入錯誤請再試一次\n\n";
        cout << "請輸入要出貨的數量:\n\n";
        cin >> a;
    }
    if (a > node->get_ammount())
        cout << "該產品存量不足，無法出貨\n\n";
    else
        node->decrease_ammount(a);

}

void list::ship() {
    if (!isempty())
        cout << "目前沒有任何產品\n\n";
    else {
        int n;
        bool flag = true;
        cout << "請輸入產品編號:\n";
        cin >> n;
        if (head->get_no() == n) {
            decrease(head);
            flag = false;
        }
        else {
            Food* find = head;
            while (find) {
                if (find->get_no() == n) {
                    decrease(find);
                    break;
                }
                else
                    find = find->get_next();
            }
            if (!find && flag)
                cout << "該產品不存在，無法出貨\n\n";
        }
    }
}


void list::print() {
    if (!isempty()) {
        cout << "目前沒有產品\n";
    }
    else {
        cout << setw(5) << "編號" << setw(22) << "產品名稱 " << setw(10) << "有效期限 " << setw(6) << "價格 " << setw(6) << " 庫存\n ";
        Food* p = head;
        while (p) {
            cout << setw(4) << p->get_no() << setw(21) << p->get_name() << setw(10) << p->get_date() << setw(6) << p->get_price() << setw(6) << p->get_ammount() << "\n ";
            p = p->get_next();
        }
    }
}

void list::in_file() {
    int no, price, ammount;
    double date;
    string name;
    Food* now = head;
    ifstream in_shop("product.txt");
    while (in_shop >> no && !in_shop.eof()) { //少了!in_cs.eof()會像zerojudge一樣無限輸入不會停止
        // no name date price ammount
        getline(in_shop, name);
        getline(in_shop, name);
        in_shop >> date;
        in_shop >> price;
        in_shop >> ammount;
        if (!isempty()) {
            head = new Food;
            head->set_no(no);
            head->set_name(name);
            head->set_date(date);
            head->set_price(price);
            head->set_ammount(ammount);
            head->set_next(NULL);
            getline(in_shop, name); //讀掉多餘enter和空白鍵
            now = head;
        }
        else {
            Food* p = new Food;
            now->set_next(p);
            p->set_no(no);
            p->set_name(name);
            p->set_date(date);
            p->set_price(price);
            p->set_ammount(ammount);
            getline(in_shop, name); //讀掉多餘enter和空白鍵
            p->set_next(NULL);
            now = p;
        }
    }
    in_shop.close();
}

void list::out_file() {
    ofstream out_shop("product.txt", ios_base::trunc);
    Food* find = head;
    while (find) { // no name date price ammount
        out_shop << find->get_no() << "\n";
        out_shop << find->get_name() << "\n";
        out_shop << find->get_date() << " ";
        out_shop << find->get_price() << " ";
        out_shop << find->get_ammount() << " \n\n";
        find = find->get_next();
    }
    out_shop.close();
}

class MENU {
private:
    int n;

public:
    void show() {
        cout << "Final MENU\n\n";
        cout << "1 Insertion:\n";
        cout << "2 Search:\n";
        cout << "3 Deletion:\n";
        cout << "4 Print Data:\n";
        cout << "5 Purchace:\n";
        cout << "6 Ship:\n";
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



int main()
{
    int n;
    list list;
    MENU menu;
    while (menu.readselect()) {
        menu.show();
        cin >> n;
        while (n > 6 || n < 0) {
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
            list.Delete_no();
            break;
        case 4:
            list.print();
            break;
        case 5:
            list.purchase();
            break;
        case 6:
            list.ship();
            break;
        }
    }


    return 0;
}
