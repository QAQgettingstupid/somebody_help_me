#include <iostream>

using namespace std;

int main()
{
    int num;
    while (1) {
        cout << "please enter a number: ";
        cin >> num;
        if (num <= 0) {
            cout << "this number must be larger than 0\n";
            continue;
        }
        int ans[55] = { 0 }, flag = 1, count; // flag->陣列ans目前用到的位數 
        ans[0] = 1;                           // count->每一層運算用到的位數

        for (int i = 2; i <= num; i++) {// 1*任何數=自己，故從2開始算
            int sum = 0;
            count = flag;
            for (int j = 0; j < flag; j++) {//與目前陣列ans已有的位數相乘
                int now = sum + ans[j] * i; 
                ans[j] = now % 10;
                sum = now / 10;
            }

            while (sum) {//將剩餘超出目前flag位數的sum另外記錄在陣列ans中
                ans[count] = sum % 10;
                count++;
                sum /= 10;
            }
            flag = max(count, flag); //更新flag大小，取count和原flag中較大的
            //max(a,b) -> 回傳a和b中較大的值
        }
        
        for (int i = flag - 1; i >= 0; i--)
            cout << ans[i];
        cout << '\n';
    }

    return 0;
}

