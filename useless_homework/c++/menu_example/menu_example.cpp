#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

string color(int a) {//花色輸出
	switch (a) {
	case 0:
		return "梅花";
	case 1:
		return "方塊";
	case 2:
		return "紅心";
	case 3:
		return "黑桃";
	}
}

void game1() {
	int you, computer;
	you = rand() % 6 + 1;
	computer = rand() % 6 + 1;
	cout << "     you:" << you << " point\n";
	cout << "computer:" << computer << " point\n";
	if (you > computer)
		cout << "you win\n\n";
	else if (you < computer)
		cout << "you lose\n\n";
	else
		cout << "even\n\n";
}

void game2() {
	int you[3], computer[3];//0->卡號(0~52) 1->花色 2->點數
	you[0] = rand() % 52;
	you[1] = you[0] % 4;
	you[2] = you[0] % 13 + 1;
	do {
		computer[0] = rand() % 52;
	} while (you[0] == computer[0]);
	computer[1] = computer[0] % 4;
	computer[2] = computer[0] % 13 + 1;

	//輸出抽排結果
	cout << "     you:" << color(you[1]) << " " << you[2] << " point\n";
	cout << "computer:" << color(computer[1]) << " " << computer[2] << " point\n";

	//比較結果
	if (computer[2] > you[2])
		cout << "you lose\n";
	else if (computer[2] < you[2])
		cout << "you win\n";
	else {
		if (computer[1] > you[1])
			cout << "you lose\n";
		else if (computer[1] < you[1])
			cout << "you win\n";
		else
			cout << "even\n\n";
	}

}

int menu() {
	int sel;
	cout << "   Menu for Simulation\n";
	cout << "1. Game 1\n";
	cout << "2. Game 2\n";
	cout << "0. Exit\n";
	cout << "   Please Select one:\n";
	cin >> sel;
	return sel;
}

int main() {
	srand(time(NULL));
	int sel = 1;
	while (sel) {
		sel = menu();
		switch (sel) {
		case 0:
			cout << "shuting down";
			break;
		case 1:
			cout << "Game 1 執行中\n\n";
			game1();
			break;
		case 2:
			cout << "Game 2 執行中\n\n";
			game2();
			break;
		default:
			cout << "wrong input, please enter again\n\n";
		}
	}
	return 0;
}
