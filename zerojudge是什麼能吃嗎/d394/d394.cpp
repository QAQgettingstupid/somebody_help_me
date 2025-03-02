#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//實際執行乘法
void times(int num[], int R_num[], int R_dot, int &dot, int R_size, int &right) {
    
    int carry = 0, now, temp_right = right;
    int ans_num[130] = {0};
    dot += R_dot;

    //乘法
    for (int i = 0; i < R_size; i++) {

        if (right < temp_right + i);
            right = temp_right + i;
        
        for (int j = 0; j < temp_right; j++) {
            now = num[j] * R_num[i] + carry;
            ans_num[j + i] += now % 10;
            carry = now / 10;
        }

        while (carry) {
            ans_num[right] = carry % 10;
            carry /= 10;
            right++;
        }
    }

    //整理運算
    for (int i = 0; i < right - 1; i++) {
        ans_num[i + 1] += ans_num[i] / 10;
        ans_num[i] %= 10;
    }

    while (ans_num[right - 1] >= 10) {
        ans_num[right]= ans_num[right - 1] / 10;
        ans_num[right - 1] %= 10;
        right++;
    }

    copy(begin(ans_num), end(ans_num), num);
}


int main()
{
    string R,ans;
    int n, num[130], R_num[10], R_dot, dot, right;
    while (cin >> R) {
        
        cin >> n;
        ans = "";
        dot = R_dot = 0;
        //去'0'尾數
        while (R[R.size() - 1] == '0')
            R.erase(R.size() - 1);

        reverse(R.begin(), R.end());
        
        //紀錄目前右側實際位數
        right = R.size() - 1;
        int overdot = 0;

        //反向放入
        for (int i = 0; i < R.size(); i++) {

            if (R[i] == '.') {
                R_dot = dot = i;
                overdot = 1;
            }
            else
                num[i - overdot] = R_num[i - overdot] = R[i] - '0';
        }

        //狂乘次方
        while (n > 1) {
            times(num, R_num, R_dot, dot, R.size() - 1, right);
            n--;
        }

        for (int i = 0; i < right; i++) {
            ans += '0' + num[i];

            if (i + 1 == dot)
                ans += '.';
        }

        reverse(ans.begin(), ans.end());

        //去'0'尾數
        while (ans[ans.size() - 1] == '0' && dot)
            ans.erase(ans.size() - 1);

        //去前面的'0'
        if(ans[0] == '0')
            ans.erase(0,1);

        cout << ans << '\n';
    }
}
