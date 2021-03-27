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
			cout << "n,w,e,s 네 문자 중 하나를 입력해주세요." << endl;
		}*/
		catch (notMovable &i) {
			cout << "움직일 수 없는 방향입니다." << endl;
		}
	}
	mypuzzle.print();
	cout << "** 완성! **" << endl;
}