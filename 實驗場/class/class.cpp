#include <iostream>

using namespace std;

class node {
    private:
        int number;//成員
    public:

        node(int number) {
            this->number = number;
        }

        int get_number() {
            return number;
        }

        int operator+(node a);

};

int node::operator+(node a) {
    return a.number + number;
}

int main()
{
    node test(11111),test2(11111);
    char name[10] = "abcd";
    cout << sizeof(name);
    return 0;
}

