#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Puzzle {
	char myarray[3][3] = { 0 }; //2���� int arry
	int zeroCol = 0 ;//���� 0�� ��ġ �����ϴ� ����
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