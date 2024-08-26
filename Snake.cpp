#include "Snake.h"

Snake::Snake() // ����������� �� ���������
{
	headXPos = mapWidth / 2 - 1; // ������ ������������� ���������� �����
	headYPos = mapHeigth / 2 - 1;

	direction = 0; // �������� ���������� �����

	food = 1; // 1 ������� � ������ � ������ ����(������ ������)

	score = 0; // ���������� 0 �����

	speed = 600; // ��������� ��������

	running = true; // ���� ��������

	fruitX = 0;
	fruitY = 0;
}

void Snake::printMap() // ����� �����
{
	for (int i = 0; i < mapWidth; ++i)
	{
		for (int j = 0; j < mapHeigth; ++j)
		{
			cout << getMapValue(map[i + j * mapWidth]); // ������������ ��������,��� �� �������� �� ����� ������ ������
		}
		cout << endl;
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << endl << "���������� ������ : " << '(' << headXPos << ';' << headYPos << ")\t"; // ���������� ���������� ������
	cout << "���������� ���: " << '(' << fruitX << ';' << fruitY << ")" << endl;
	cout << "���� : " << score << endl;
	cout << "������� �������� : " << speed << endl;
}

void Snake::initMap() // ������������� �����
{
	map[headXPos + headYPos * mapWidth] = 1; // ������ ����� �� �������

	for (int i = 0; i < mapWidth; ++i) // �������������� ������� � ������ �������
	{
		map[i] = -1;
		map[i + (mapHeigth - 1) * mapWidth] = -1;
	}

	for (int j = 0; j < mapHeigth; j++) // ������������� ������ � ����� �������
	{
		map[0 + j * mapWidth] = -1;
		map[(mapWidth - 1) + j * mapWidth] = -1;
	}

	generateFood(); // ���������� �����
}

void Snake::move(int dx, int dy) // ����������� 
{
	int newX = headXPos + dx; // ����� ��������� ������ �� �
	int newY = headYPos + dy; // ����� ��������� ������ �� �

	if (map[newX + newY * mapWidth] == -2) // ��������� ��� ��� �������
	{
		food++; // ����������� ���� �� �������
		score += 10; // ��������� 10 �����
		speed -= 3; // ����������� ��������

		generateFood(); // ���������� ����� �����
	}

	else if (map[newX + newY * mapWidth] != 0) // ���� ������ �������� � ����������
	{
		running = false; // ����� ����
	}

	headXPos = newX; // �������������� ��������� ������ �� �
	headYPos = newY; // �������������� ��������� ������ �� �
	map[headXPos + headYPos * mapWidth] = food + 1; // ��������� �� ����� ����� ������� ������
}

void Snake::update() // ���������� �����
{
	switch (direction) // �������� � ��������� �����������
	{
	case 0: move(-1, 0); break;

	case 1: move(0, 1); break;

	case 2: move(1, 0); break;

	case 3: move(0, -1); break;
	}

	for (int i = 0; i < size; i++) // ���������� ���� �� �����
	{
		if (map[i] > 0)
		{
			map[i]--;
		}
	}
}

void Snake::changeDirection(char key) // ����������
{
	switch (key)
	{
	case 'w': if (direction != 2) { direction = 0; } break;
	case 'd': if (direction != 3) { direction = 1; } break;
	case 's': if (direction != 4) { direction = 2; } break;
	case 'a': if (direction != 5) { direction = 3; } break;

	case 'p': system("pause"); break; // �����
	case 'm': running = false; break; // �����
	}
}

void Snake::generateFood() // ��������� ���
{
	do // ����� ���� ��� ���������� ���������
	{
		fruitX = rand() % (mapWidth - 2) + 1; // ���������� � ��������� ��������
		fruitY = rand() % (mapHeigth - 2) + 1;

	} while (map[fruitX + fruitY * mapWidth] != 0); // ���� ����� �� ������

	map[fruitX + fruitY * mapWidth] = -2; // ��������� ����� ��� �� �����
}

char Snake::getMapValue(int value) // ��������� �������� ��� ��������
{
	if (value > 0) // ���� �������� ������ ���� �� ���� ����
	{ 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 36); 
		return 'O';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	} 

	switch (value) // ��������� ��������
	{
	case -1: // ���� -1 �� ������� ����
	{ 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
		return '#';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	} 
	case -2: // ���� -2 �� ���
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 37);
		return 'o';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	} 
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 34);
	return ' '; // ���� ���������� ���������
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void Snake::run() // ���� ����
{
	initMap(); // �������������� �����

	while (running) // ���� ���� �������
	{

		if (_kbhit()) // ��������� ������� �������
		{
			changeDirection(_getch()); // ����� �� ������������ ������� �������
		}

		update(); // ��������� �����
		system("cls"); // ������� �����
		printMap(); // ������� �����
		Sleep(speed); // ������ ��������� ���e����
	}
}
