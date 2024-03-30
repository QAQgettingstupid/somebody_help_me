#include <iostream>
using namespace std;

class node {
	private:
		int no;
		node* ptr;
		char name[10];
		int prg;
		int cmp;

	public:
		void num(int i) {
			no = i;
		}
		int readno() {
			return no;
		}
		void pointer(node* i) {
			ptr = i;
		}
		node* readptr() {
			return ptr;
		}
		void writename() {
			cout << "輸入名字：\n";
			cin >> name;
		}
		char* readname() {
			return name;
		}
		void writeprg() {
			int x;
			cout << "輸入 prg 成績：\n";
			cin >> x;
			prg = x;
		}
		int readprg() {
			return prg;
		}
		void writecmp() {
			int y;
			cout << "輸入 cmp 成績：\n";
			cin >> y;
			cmp = y;
		}
		int readcmp() {
			return cmp;
		}
};
void printlist(node* p) {
	cout << "head ->";
	while (p) {
		cout << p->readno() << "->";
		cout << "名字!!!" << p->readname() << "->";
		p = p->readptr();
	}
	cout << "||\n";
}
int main() {
	node* head = NULL;
	node* p;
	node* r = NULL;
	node* q = NULL;
	int n, x, y;
	char a[10];

	while (1) {
		cout << "輸入座號 : ( 跳出按 0 ) \n";
		cin >> n;
		if (n <= 0)
			break;
		if (head == NULL) {
			head = new node;
			head->num(n);
			head->writename();
			head->writeprg();
			head->writecmp();
			head->pointer(NULL);
		}
		else {
			p = new node;
			p->num(n);
			if (head->readno() > n) {
				p->pointer(head);
				p->writename();
				p->writeprg();
				p->writecmp();
				head = p;
			}
			else {
				q = head;
				while (q && q->readno() <= n) {
					r = q;
					q = q->readptr();
				}
				if (p->readno() == r->readno())
					cout << "輸入重複座號，請重新輸入\n";
				else {
					r->pointer(p);
					p->pointer(q);
					p->writename();
					p->writeprg();
					p->writecmp();
				}
			}
		}
	}
	printlist(head);
}


