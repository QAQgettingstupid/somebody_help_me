#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class ST {
protected:
	int number;
	string name;

};
class Stnode1 : public ST {
private:
	Stnode1* head = NULL;
	Stnode1* q;
	Stnode1* r;
	Stnode1* p;
	bool k;
	int prg, eng;
	Stnode1* ptr;

public:
	void setdata(int i, string studentName, int prgScore, int engScore) {
		number = i;
		name = studentName;
		prg = prgScore;
		eng = engScore;
	}
	int printnum() {
		return number;
	}
	string printname() {
		return name;
	}
	int printprg() {
		return prg;
	}
	int printeng() {
		return eng;
	}
	void setptr(Stnode1* i) {
		ptr = i;
	}
	Stnode1* printptr() {
		return ptr;
	}
	int totalscore() {
		return (prg + eng);
	}




};
class Stnode2 : public ST {
private:
	Stnode2* head = NULL;
	Stnode2* q;
	Stnode2* r;
	Stnode2* p;
	bool k;
	int run;
	Stnode2* ptr;

public:
	void setdata(int i, string studentName, int runScore) {
		number = i;
		name = studentName;
		run = runScore;
	}
	int printnum() {
		return number;
	}
	string printname() {
		return name;
	}
	int printrun() {
		return run;
	}

	void setptr(Stnode2* i) {
		ptr = i;
	}
	Stnode2* printptr() {
		return ptr;
	}
	int totalscore() {
		return run;
	}




};
class linklist1 {
	Stnode1* head = NULL;
	Stnode1* q;
	Stnode1* r;
	Stnode1* p;
	bool k;
	int prg, eng;
	Stnode1* ptr;
	int number;
	string name;
public:
	void insertData() {
		while (1) {
			k = false;
			q = head;
			cout << "set number: \n";
			cin >> number;


			while (q != NULL && q->printnum() <= number) {
				if (q->printnum() == number) {
					k = true;
					break;
				}
				else {
					r = q;
					q = q->printptr();
				}
			}
			if (number <= 0 || k) {
				cout << "輸入錯誤或輸入重複座號 !\n";
			}
			else {
				break;
			}

		}
		cout << "set name : \n";
		cin.get();
		getline(cin, name);

		cout << "input prg score:\n";
		cin >> prg;
		cout << "input english score:\n";
		cin >> eng;

		p = new Stnode1;
		p->setdata(number, name, prg, eng);

		if (head == NULL || head->printnum() > number) {
			p->setptr(head);
			head = p;
		}
		else {
			r->setptr(p);
			p->setptr(q);
		}
	}
	void deleteData(int deleten) {
		Stnode1* q;
		Stnode1* r = NULL;
		bool k = false;
		string name;
		if (head == NULL) {
			cout << "尚無資料! \n";
		}
		else {
			q = head;
			while (q != NULL) {
				if (q->printnum() == deleten) {
					if (r) {
						r->setptr(q->printptr());
					}
					else {
						q = q->printptr();
						head = q;
					}
					k = true;
					cout << "該筆資料已刪除\n";
					break;
				}
				else {
					r = q;
					q = q->printptr();
				}
			}
			if (deleten <= 0) {
				cout << "輸入錯誤 !\n";
			}
			if (!k) {
				cout << "該筆資料不存在，無法刪除\n";
			}
		}
	}

	void printList() {
		Stnode1* p = head;
		cout << "head -> ";
		while (p) {
			cout << p->printnum() << "->";
			p = p->printptr();
		}
		cout << "||\n";
	}
	void printSearchData() {

		Stnode1* q;
		Stnode1* r = NULL;
		bool k;
		if (head == NULL) {
			cout << "尚無資料! \n";
		}
		else {
			string name;
			cout << "輸入名字 : \n";
			cin.get();
			getline(cin, name);

			k = false;
			q = head;
			r = NULL;
			while (q) {
				if (name != q->printname()) {

					k = true;
					cout << "number:\n";
					cout << q->printnum() << endl;
					cout << "prg score:\n";
					cout << q->printprg() << endl;
					cout << "cmp score:\n";
					cout << q->printeng() << endl;
					q = q->printptr();
				}
				else {
					r = q;
					q = q->printptr();
				}
			}

			if (name.size() == 0) {
				cout << "輸入錯誤 !\n";
			}
			if (!k) {
				cout << "該學生不存在 \n";
			}
		}

	}
	void printTranscript() {
		if (head == NULL) {
			cout << "尚無資料! \n";
		}
		else {
			int count = 0;
			Stnode1* q = head;
			while (q) {
				count++;
				q = q->printptr();
			}

			Stnode1** rank = new Stnode1 * [count];
			q = head;
			int i = 0;
			while (q) {
				rank[i] = q;
				i++;
				q = q->printptr();
			}
			for (int i = 0; i < count - 1; i++) {
				for (int j = 0; j < count - i - 1; j++) {
					if (rank[j]->totalscore() < rank[j + 1]->totalscore()) {
						swap(rank[j], rank[j + 1]);
					}
				}
			}

			int cur_rank = 1;
			int prev_score = rank[0]->totalscore();

			cout << "---------\n";
			cout << "rank";
			cout << setw(13) << cur_rank;
			for (int i = 1; i < count; i++) {
				if (i > 0 && rank[i]->totalscore() != prev_score) {
					cur_rank = i + 1;
				}
				cout << setw(12) << cur_rank;
				prev_score = rank[i]->totalscore();
			}
			cout << "\nnumber";
			cout << setw(11) << rank[0]->printnum();
			for (int i = 1; i < count; i++) {

				cout << setw(12) << rank[i]->printnum();

			}
			cout << "\nname";
			cout << setw(13) << rank[0]->printname();
			for (int i = 1; i < count; i++) {

				cout << setw(12) << rank[i]->printname();

			}
			cout << "\nprg score ";
			cout << setw(7) << rank[0]->printprg();
			for (int i = 1; i < count; i++) {

				cout << setw(12) << rank[i]->printprg();

			}
			cout << "\neng score ";
			cout << setw(7) << rank[0]->printeng();
			for (int i = 1; i < count; i++) {

				cout << setw(12) << rank[i]->printeng();

			}
		}

	}
	void writetofile() {
		ofstream outFile("st1_numbers.txt", ios_base::trunc);
		q = head;
		outFile << "--------CS---------\n";
		while (q) {
			outFile << "\n number: ";
			outFile << q->printnum() << endl;
			outFile << "\n name: ";
			outFile << q->printname() << endl;
			outFile << "\n prg score: ";
			outFile << q->printprg() << endl;
			outFile << "\n eng score: ";
			outFile << q->printeng() << endl;
			q = q->printptr();
			outFile << "-------------------\n";

		}
		outFile.close();
	}
	void readfile() {
		ifstream inFile("st1_numbers.txt");
		if (inFile.is_open()) {
			string line;
			getline(inFile, line);
			while (getline(inFile, line) && !inFile.eof()) {
				getline(inFile, line);
				istringstream iss(line);
				int number;
				string trash, s;
				int prgScore;
				int engScore;
				
				iss >> trash; //number
				iss >> s;
				number = stoi(s);

				getline(inFile, line);
				getline(inFile, line); //name
				iss.clear();
				iss.str(line);
				iss >> trash >> name;

				getline(inFile, line);
				getline(inFile, line); //prgScore
				iss.clear();
				iss.str(line);
				iss >> trash >> trash >> s;
				prgScore = stoi(s);

				getline(inFile, line);
				getline(inFile, line); //engScore
				iss.clear();
				iss.str(line);
				iss >> trash >> trash >> s;
				engScore = stoi(s);

				getline(inFile, line);

				Stnode1* newNode = new Stnode1;
				newNode->setdata(number, name, prgScore, engScore);
				insertNode(newNode);
			}
			inFile.close();
		}
		else {
			cout << "Unable to open file\n";
		}
	}
	void insertNode(Stnode1* newnode) {
		if (head == NULL || head->printnum() > newnode->printnum()) {
			newnode->setptr(head);
			head = newnode;
		}
		else {
			Stnode1* current = head;
			while (current->printptr() != NULL && current->printptr()->printnum() < newnode->printnum()) {
				current = current->printptr();
			}
			newnode->setptr(current->printptr());
			current->setptr(newnode);
		}
	}


};
class linklist2 {
	Stnode2* head = NULL;
	Stnode2* q;
	Stnode2* r;
	Stnode2* p;
	bool k;
	int run;
	Stnode2* ptr;
	int number;
	string name;
public:
	void insertData() {
		while (1) {
			k = false;
			q = head;
			cout << "set number: \n";
			cin >> number;
			cout << "set name : \n";


			while (q != NULL && q->printnum() <= number) {
				if (q->printnum() == number) {
					k = true;
					break;
				}
				else {
					r = q;
					q = q->printptr();
				}
			}
			if (number <= 0 || k) {
				cout << "輸入錯誤或輸入重複座號 !\n";
			}
			else {
				break;
			}
		}
		cin.get();
		getline(cin, name);
		cout << "input running score:\n";
		cin >> run;

		p = new Stnode2;
		p->setdata(number, name, run);

		if (head == NULL || head->printnum() > number) {
			p->setptr(head);
			head = p;
		}
		else {
			r->setptr(p);
			p->setptr(q);
		}
	}
	void deleteData(int deleten) {
		Stnode2* q;
		Stnode2* r = NULL;
		bool k = false;

		if (head == NULL) {
			cout << "尚無資料! \n";
		}
		else {
			q = head;
			while (q != NULL) {
				if (q->printnum() == deleten) {
					if (r) {
						r->setptr(q->printptr());
					}
					else {
						q = q->printptr();
						head = q;
					}
					k = true;
					cout << "該筆資料已刪除\n";
					break;
				}
				else {
					r = q;
					q = q->printptr();
				}
			}
			if (deleten <= 0) {
				cout << "輸入錯誤 !\n";
			}
			if (!k) {
				cout << "該筆資料不存在，無法刪除\n";
			}
		}
	}

	void printList() {
		Stnode2* p = head;
		cout << "head -> ";
		while (p) {
			cout << p->printnum() << "->";
			p = p->printptr();
		}
		cout << "||\n";
	}
	void printSearchData() {

		Stnode2* q;
		Stnode2* r = NULL;
		bool k;
		if (head == NULL) {
			cout << "尚無資料! \n";
		}
		else {
			string name;
			cout << "輸入名字 : \n";
			cin.get();
			getline(cin, name);

			k = false;
			q = head;
			r = NULL;
			while (q) {
				if (name != q->printname()) {

					k = true;
					cout << "number:\n";
					cout << q->printnum() << endl;
					cout << "running score:\n";
					cout << q->printrun() << endl;

					q = q->printptr();
				}
				else {
					r = q;
					q = q->printptr();
				}
			}

			if (name.size() == 0) {
				cout << "輸入錯誤 !\n";
			}
			if (!k) {
				cout << "該學生不存在 \n";
			}
		}
	}
	void printTranscript() {
		if (head == NULL) {
			cout << "尚無資料! \n";
		}
		else {
			int count = 0;
			Stnode2* q = head;
			while (q) {
				count++;
				q = q->printptr();
			}

			Stnode2** rank = new Stnode2 * [count];
			q = head;
			int i = 0;
			while (q) {
				rank[i] = q;
				i++;
				q = q->printptr();
			}
			for (int i = 0; i < count - 1; i++) {
				for (int j = 0; j < count - i - 1; j++) {
					if (rank[j]->totalscore() < rank[j + 1]->totalscore()) {
						swap(rank[j], rank[j + 1]);
					}
				}
			}

			int cur_rank = 1;
			int prev_score = rank[0]->totalscore();

			cout << "---------\n";
			cout << "rank";
			cout << setw(13) << cur_rank;
			for (int i = 1; i < count; i++) {
				if (i > 0 && rank[i]->totalscore() != prev_score) {
					cur_rank = i + 1;
				}
				cout << setw(12) << cur_rank;
				prev_score = rank[i]->totalscore();
			}
			cout << "\nnumber";
			cout << setw(11) << rank[0]->printnum();
			for (int i = 1; i < count; i++) {

				cout << setw(12) << rank[i]->printnum();

			}
			cout << "\nname";
			cout << setw(13) << rank[0]->printname();
			for (int i = 1; i < count; i++) {

				cout << setw(12) << rank[i]->printname();

			}
			cout << "\nrunning score ";
			cout << setw(3) << rank[0]->printrun();
			for (int i = 1; i < count; i++) {

				cout << setw(12) << rank[i]->printrun();
				prev_score = rank[i]->totalscore();
			}
		}
	}
	void writetofile() {
		ofstream outFile("st2_numbers.txt", ios_base::trunc);
		q = head;
		outFile << "--------PE---------\n";
		while (q) {
			outFile << "\nnumber: ";
			outFile << q->printnum() << endl;
			outFile << "\nname: ";
			outFile << q->printname() << endl;
			outFile << "\nrunning score: ";
			outFile << q->printrun() << endl;
			q = q->printptr();
			outFile << "-------------------\n";

		}
		outFile.close();
	}
	void readfile() {
		ifstream inFile("st2_numbers.txt");
		if (inFile.is_open()) {
			string line;
			getline(inFile, line);
			while (getline(inFile, line) && !inFile.eof()) {
				getline(inFile, line);
				istringstream iss(line);
				int number;
				string read_name, s, trash; 
				int runScore;
				
				//以下trash都是存不必要的格式
				iss >> trash >> s; //number 
				number = stoi(s); 
				


				getline(inFile, line);
				getline(inFile, line); //name
				iss.clear();
				iss.str(line);
				
				iss >> trash >> name;

				getline(inFile, line);
				getline(inFile, line); //runScore
				iss.clear();
				iss.str(line);
				iss >> trash >> trash >> s;
				runScore = stoi(s);

				getline(inFile, line);//線

				Stnode2* newNode = new Stnode2;
				newNode->setdata(number, name, runScore);
				insertNode(newNode);
			}
			inFile.close();
		}
		else {
			cout << "Unable to open file\n";
		}
	}
	void insertNode(Stnode2* newnode) {
		if (head == NULL || head->printnum() > newnode->printnum()) {
			newnode->setptr(head);
			head = newnode;
		}
		else {
			Stnode2* current = head;
			while (current->printptr() != NULL && current->printptr()->printnum() < newnode->printnum()) {
				current = current->printptr();
			}
			newnode->setptr(current->printptr());
			current->setptr(newnode);
		}
	}
};




// linklist2




class MENU {
private:
	int select;
	int n;
public:
	void show() {
		cout << "\n       選單MENU\n";
		cout << "1.新增學生資料 Insertion\n";
		cout << "2.查詢資料 Search\n";
		cout << "3.刪除資料 Deletion\n";
		cout << "4.列印串列資料 Print List Data\n";
		cout << "5.列印成績單 Print Transcript\n";
		cout << "0.離開 Exit\n";
	}
	void writrselect() {
		cin >> select;
	}

	int readselect() {
		return select;
	}
	void showclass() {
		cout << "CS : 1\n";
		cout << "PE : 2\n";
		cin >> n;
	}
	int writeclass() {
		return n;
	}
};

int main() {
	MENU m;
	ST st;
	linklist1 st1;
	linklist2 st2;
	st1.readfile();
	st2.readfile();
	while (1) {
		m.show();
		m.writrselect();
		switch (m.readselect()) {
		case 1:
			m.showclass();
			if (m.writeclass() == 1) {
				st1.insertData();
			}
			else {
				st2.insertData();
			}
			break;
		case 2:
			m.showclass();
			if (m.writeclass() == 1) {
				st1.printSearchData();
			}
			else {
				st2.printSearchData();
			}
			break;
		case 3:
			m.showclass();
			if (m.writeclass() == 1) {
				int deleten;
				cout << "輸入座號 : \n";
				cin >> deleten;
				st1.deleteData(deleten);
			}
			else {
				int deleten;
				cout << "輸入座號 : \n";
				cin >> deleten;
				st2.deleteData(deleten);
			}
			break;
		case 4:
			m.showclass();
			if (m.writeclass() == 1) {
				st1.printList();
			}
			else {
				st2.printList();
			}
			break;
		case 5:
			m.showclass();
			if (m.writeclass() == 1) {
				st1.printTranscript();
			}
			else {
				st2.printTranscript();
			}
			break;
		}
		if (m.readselect() == 0) {
			st1.writetofile();
			st2.writetofile();


			break;
		}
	}
}
