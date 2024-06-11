#include <iostream>

using namespace std;

class aua {

    private:
        int a, b;

    public:

        friend ostream& operator<<(ostream& os, aua n) {
            os << "aua(a=" << n.a << ", b=" << n.b << ")";
            return os;
        }


        aua() {
            a = 66;   
            b = 77;
        }
};

template<class t>
void sort(t a) {
    cout << a << '\n';
}

int main()
{
    aua num;

    sort<string>("5.5"); // 呼叫-> sort<型態>(型態, 5);
    sort<aua>(num);
    return 0;
}
