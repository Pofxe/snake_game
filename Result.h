#pragma once

#include "Snake.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>

class Result
{
private:

#define FILE "D:\\resultGame.txt" // ���� ��� ������
	vector<pair<string, int>> table; // ���� ��� �����������

public:

	Result() = default;
	void resultGameIn(string, int);
	void resultGameOut();
	~Result() {};

};

