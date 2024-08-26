#include "Snake.h"
#include "Result.h"


inline void cursor() // ��� ���� ��� �� ������ �� ����� �� ������
{
	auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
}

inline void gotoxy(int x, int y) // ��������� ������� � ������ �������
{
	COORD scrn;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	scrn.X = x;
	scrn.Y = y;

	SetConsoleCursorPosition(hOutput, scrn);
}

inline void title() // �������� � ���������� 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	cout << "���������� : " << endl;
	cout << "+=======+==========+\n"
		"|a      |�����     |\n"
		"|d      |������    |\n"
		"|s      |����      |\n"
		"|w      |�����     |\n"
		"|p      |�����     |\n"
		"|m      |�����     |\n"
		"+=======+==========+\n\n";

	cout << "�� ������ ��������� ����� �� ��������� 1 ���� � � ������ ����������� ���� �������." << endl;
	cout << "��� ��������������� � �������� ���� ������ �������� � ���� �������������." << endl;
	cout << "��� ���� ���������� ��������,��� ������� ����� ��������� ������." << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int user = 0; // ����� ������������
	bool menu = true; // ��� ������ � ����
	string name = ""; // ��� ������
	int sc = 0; // ���������� ����� 

	Snake s; // ������ ������ ������
	Result r; // ������ ������ �������� �����������

	cout << "������� ��� : ";
	cin >> name;
	cout << endl;

	do
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		cout << "    ����" << endl;
		cout << "1.������ ����" << endl;
		cout << "2.�������� ����������" << endl;
		cout << "3.��������" << endl;
		cout << "4.����� �� ����" << endl;
		cin >> user;

		system("cls");

		switch (user)
		{
		case 1:
		{
			cursor();
			gotoxy(0, 0);

			s.run(); // �������� ����

		    sc = s.score; // �������� ���������� �����
			
			r.resultGameIn(name, sc); // ���������� ��������� ����

			system("pause");
		}
		break;

		case 2:
		{
			r.resultGameOut(); // ������� ��������������� ��������� ����

			system("pause");
		}
		break;

		case 3:
		{
			title(); // ���������� ������� � ����������
			system("pause");
		}
		break;

		case 4:
		{
			menu = false; // ����� �� ����
		}
		break;

		} 
	}while (menu); // ���� ������������ ���� �� ������ ������� ������ �� ����
}