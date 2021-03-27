#include "puzzelhd.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/* 1117 ����
Puzzle::Puzzle(const char* filename) {

}

ifstream& operator >>(istream &is, Puzzle &x){
	for (int i = 0; i <3 ; i ++)
		for (int j = 0; j <3 ; j++)
			is >> x.myarray[i][j];
	return is;
}

void Puzzle::setSpace(){ //0�� ��ġ ã�� �Լ�
}
*/
Puzzle::Puzzle(string txt) {
	char c;
	int row = 0;
	int col = 0;
	ifstream File(txt);
	while (File.get(c)) {
		if (c != ' ' && c != '\n') {
			if (c == '0') { //ó�� 0�� ��ġ ����
				zeroRow = row; zeroCol = col;
			}
			myarray[row][col] = c;
			col++;
		}
		if (c == '\n') {
			col = 0;
			row++;
		}
	}
	File.close();
}

void Puzzle::move(char d) {
	switch (d) {
		case 'n': //��
			if (zeroRow == 0) throw notMovable();
			myarray[zeroRow][zeroCol] = myarray[zeroRow - 1][zeroCol];
			myarray[zeroRow - 1][zeroCol] = '0';	//myarray[--zeroRow][zeroCol] = 0;
			zeroRow--;
			break;
		case 's': //�Ʒ�
			if (zeroRow == 2) throw notMovable();
			myarray[zeroRow][zeroCol] = myarray[zeroRow + 1][zeroCol];
			myarray[zeroRow + 1][zeroCol] = '0';
			zeroRow++;
			break;
		case 'w': //��
			if (zeroCol == 0) throw notMovable();
			myarray[zeroRow][zeroCol] = myarray[zeroRow][zeroCol - 1];
			myarray[zeroRow][zeroCol - 1] = '0';
			zeroCol--;
			break;
		case 'e': //��
			if (zeroCol == 2) throw notMovable();
			myarray[zeroRow][zeroCol] = myarray[zeroRow][zeroCol + 1];
			myarray[zeroRow][zeroCol+1] = '0';
			zeroCol++;
			break;
		default:
			throw notMovable();
	}
}

void Puzzle::print() {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			cout << myarray[row][col] << ' ';
		}
		cout << endl;
	}
}

bool Puzzle::isDone() {
	char answer[3][3] = { {'1', '2', '3'},{'8', '0', '4'}, {'7', '6', '5'} };
	
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (myarray[row][col] == answer[row][col]) { }
			else { return false; }
		}
	}
	return true;
}