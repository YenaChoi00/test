#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Puzzle {
	char myarray[3][3] = { 0 }; //2차원 int arry
	int zeroCol = 0 ;//현재 0의 위치 저장하는 변수
	int zeroRow = 0;
	string filename;
public:
	Puzzle(string txt);
	void move(char d);
	bool isDone();
	void print();
};

class notMovable {};
class unexpectedInput {};