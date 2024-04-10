#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a = "Hello World!";
    a.erase(a.size() - 2, 1);
    cout << a;

    return 0;
}
