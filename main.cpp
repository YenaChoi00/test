# include "puzzelhd.h"
#include <iostream>
//#include <fstream>
using namespace std;

int main() {
	Puzzle mypuzzle("D:/mypuzzle.txt");
	char m;
	while (!mypuzzle.isDone()) {
		mypuzzle.print();
		cout << "Give me your decision: ";
		cin >> m;
		try {
			//if (m != 'n' && m != 's' && m != 'e' && m != 'w') throw unexpectedInput();
			mypuzzle.move(m);
		}
		/*catch(unexpectedInput &e){
			cout << "n,w,e,s �� ���� �� �ϳ��� �Է����ּ���." << endl;
		}*/
		catch (notMovable &i) {
			cout << "������ �� ���� �����Դϴ�." << endl;
		}
	}
	mypuzzle.print();
	cout << "** �ϼ�! **" << endl;
}