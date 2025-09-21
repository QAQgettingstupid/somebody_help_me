#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // 早,傍晚,晚
    double list[5][3] = { {0.10,0.06,0.02},{0.25,0.15,0.05},
                          {0.53,0.33,0.13},{0.87,0.47,0.17},
                          {1.44,0.80,0.30} };
    // 晚,早,傍晚
    int time_list[6][2] = { {0,8 * 60} ,{8 * 60,18 * 60},{18 * 60,22 * 60},
                            {22 * 60,32 * 60},{32 * 60,42 * 60},{42 * 60,46 * 60} };
    char charging_step;
    string phone;

	// start_hour, start_minute, end_hour, end_minute
    int sh, sm, eh, em, d, e, n;
    double total;

    while (cin >> charging_step) {
        
        if (charging_step == '#')
            break;
        else {
            cin >> phone >> sh >> sm >> eh >> em;
            d = 0;
            e = 0;
            n = 0;
            total = 0;
			sm += sh * 60;
			em += eh * 60;

            //有換日
            if (sm > em)
                em += 24 * 60;

            for (int i = 0; i < 6; i++) {
                if (em <= time_list[i][0])
                    break;
                else if(sm >= time_list[i][1])
					continue;
                // 晚上
                if (i % 3 == 0) 
                    n += min(em, time_list[i][1]) - max(sm, time_list[i][0]);
                // 早上
                else if(i%3==1)
                    d += min(em, time_list[i][1]) - max(sm, time_list[i][0]);
                // 傍晚
                else
					e += min(em, time_list[i][1]) - max(sm, time_list[i][0]);
            }
        }

        switch (charging_step) {
            case 'A':
                total = d * list[0][0] + e * list[0][1] + n * list[0][2];
				break;
            case 'B':
				total = d * list[1][0] + e * list[1][1] + n * list[1][2];
                break;
			case 'C':
                total = d * list[2][0] + e * list[2][1] + n * list[2][2];
				break;
            case 'D':
				total = d * list[3][0] + e * list[3][1] + n * list[3][2];
                break;
			case 'E':  
				total = d * list[4][0] + e * list[4][1] + n * list[4][2];
				break;
        }
        
        cout << phone;
        cout << setfill(' ') << setw(6) << d;
        cout << setw(6) << e;
        cout << setw(6) << n;
        cout << setw(3) << charging_step;
        cout << setw(8) << fixed << setprecision(2) << total << '\n';
    }
}
