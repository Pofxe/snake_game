#pragma once

#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

class Snake
{
private:
	static const int mapWidth = 20; // ������
	static const int mapHeigth = 40; // ������
	static const int size = mapWidth * mapHeigth; // ������ �����
	int map[size]{}; // ���� �����

	int headXPos; // ������� ������ �� �
	int headYPos; // ������� ������ �� �
	int direction; // ����������� ��������

	int speed; // �������� ����

    int food; // ���������� ��������� ������� � �� ���������������� ����� ������

	bool running; // �������� �� ����

	int fruitX;
	int fruitY;

public:

	int score; // ���������� �����

	Snake();

	void printMap();
	void initMap();
	void move(int, int);
	void update();
	void changeDirection(char);
	void generateFood();
	char getMapValue(int);
	void run();
};

