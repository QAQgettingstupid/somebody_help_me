#include <iostream>

using namespace std;

int main()
{
	const char* num1[] =
	{
		" ","one ","two ","three ","four ","five ","six ","seven ","eight ",
		"nine ","ten ","eleven ","twelve ", "thirteen ","fourteen ",
		"fifteen ","sixteen ","seventeen ","eighteen ","nineteen "
	};

	cout << "num1[19]= " << num1[19] << '\n';//輸出整個字串直到讀到null 字元 ('\0')
	cout << "num1[19]+5= " << num1[19]+5 << '\n';//輸出從第一個字元往後5個字元位置到讀到null 字元 ('\0')
	cout << "*num1[19]= " << *num1[19] << '\n'; //僅輸出第一個字元

    return 0;
}