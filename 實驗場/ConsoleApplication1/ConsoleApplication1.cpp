#include <iostream>

using namespace std;

int main()
{
    int a;
    cin >> a;
    int* head = NULL;
    int* b = head;
    head= &a;
    b = head;
    cout << *b;

    return 0;
}