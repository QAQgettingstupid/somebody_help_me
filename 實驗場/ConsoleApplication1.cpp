#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int a[10];
    
    /*
        fstream 檔案串流
        ifstream 輸入檔案串流
        ofstream 輸出檔案串流
        (以上皆屬類別)
    */
    //輸入
    ifstream f1("imput.txt");
    int i = 0;
    while (!f1.eof()) {
        f1 >> a[i];
        i++;
    }
    f1.close();
    cout << "!!!\n";
    for (int i = 0; i < 5; i++)
        cout << a[i] << '\n';
    //或 ifstream f1;
    //   f1.open("imput.txt");
    
    //輸出
    ofstream f2("output.txt",ios_base::app);

    //或 ofstream f2;
    //   f2.open("output.txt");
    for (int i = 0; i < 5; i++)
        f2 <<a[i] << '\n';
    f2.close();
    /*
        ios_base::in 唯讀檔案
        ios_base::out 輸出檔案
        ios_base::app 寫入檔案最後
        ios_base::trunc 清空檔案

         ofstream f2("output.txt",ios_base::app|ios_base::out); 多重參數以"|"隔開
    */

    return 0;
}
