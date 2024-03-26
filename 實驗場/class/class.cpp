#include <iostream>

using namespace std;

class node {
    private:
        int number;//成員
    public:

        node(int number) {
            this->number = number;
        }

        int operator+(node a) {
            return a.number + number;
        }

};

int main()
{
    node test(11111),test2(11111);
    cout << test + test2;
    return 0;
}

