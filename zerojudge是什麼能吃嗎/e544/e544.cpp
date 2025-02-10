#include <iostream>

using namespace std;

class sort_string {

public:
    string s;
    int sequence;

    void setsequence() {
        sequence = 0;
        int length = s.size();

        for (int i = 0; i < length; i++)
            for (int j = i + 1; j < length; j++)
                if (s[i] > s[j])
                    sequence++;
    }
};

void sort(sort_string input[],int lines) {
    for (int i = 0; i < lines; i++)
        for (int j = 0; j < lines - i - 1; j++)
            if (input[j].sequence > input[j + 1].sequence)
                swap(input[j], input[j + 1]);
}

int main()
{
    int T, n, m;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        sort_string input[110];
        for (int i = 0; i < m; i++) {
            cin >> input[i].s;
            input[i].setsequence();
        }

        sort(input,m);

        for (int i = 0; i < m; i++)
            cout << input[i].s << '\n';

        cout << '\n';
    }

}
