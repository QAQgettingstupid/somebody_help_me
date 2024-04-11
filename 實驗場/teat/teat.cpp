#include <iostream>

using namespace std;

class node {
    private:
        int number;
    
    public:
        void set_number(int a) {
            number = a;
        }
        int get_number();
};

int node::get_number() {
    return number;
}


void print(node* &head) {
    cout << "函式內地址!!!-> " << head << '\n';
    head = new node;
    cout << "函式內地址!!!-> " << head << '\n';
    head->set_number(5);
    cout << head->get_number() << '\n';
}

int main()
{
    node* head = NULL;
    cout << "函式外地址!!!-> " << head << '\n';
    print(head);
    cout << "函式外地址!!!-> " << head << '\n';
    return 0;
}