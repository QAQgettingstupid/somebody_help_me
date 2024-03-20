#include <iostream>

using namespace std;

class node {
private:
    int number;
    node* next;
public:
    void set_number(int number) {
        this->number = number;
    }
    void set_next(node* next) {
        this->next = next;
    }
    int get_number() {
        return number;
    }
    node* get_next() {
        return next;
    }
    int operator+(node p) {
        return number + p.get_number();
    }
    node(int a = 0) {
        number = a;
    }
};

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
        head->set_next(NULL);
    }
    else {
        node* p = new node;
        p->set_number(n);
        if (head->get_number() >= n) {
            p->set_next(head);
            head = p;
        }
        else {
            node* find = head;
            node* temp;
            while (find->get_next()) {
                if (find->get_next()->get_number() >= n) {
                    temp = find->get_next();
                    find->set_next(p);
                    p->set_next(temp);
                    break;
                }
                else
                    find = find->get_next();
            }
            if (!(find->get_next())) {
                find->set_next(p);
                p->set_next(NULL);
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