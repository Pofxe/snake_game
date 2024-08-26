#include "Result.h"

void Result::resultGameIn(string n, int s)
{
	ofstream in(FILE, ios_base::app);

	if (in.is_open() != true) { cout << "������ �������� �����!" << endl; exit(0); } // ���� ���� �� ��������,�� ������� ��������� � ������� �� ���������
	if (in.is_open() == true) { in << n << " " << s << endl; } // ���� ���� ��������,�� ���������� � ���� ������

	in.close(); // ��������� ����
}

void Result::resultGameOut()
{
	ifstream out(FILE);
	string str = "";

	if (out.is_open() == true) // ��������� �� ���������� �����
	{
		while (getline(out, str)) // ��������� ��������� �� ����� � ���������� � ����������
		{
			string n = "";
			int s = 0;
			
			for (int i = 0; i < str.size(); i++) // ���������� ������ �� ���������� �������
			{
				if (str[i] != ' ') // ���� �� ������
				{
					n += str[i]; // ���������� � ���������� ��� ����� 
				}
				else // � ��������� ������
				{
					s = stoi(str.substr(i + 1)); // ���������� � ���������� �����
					break;
				}
			}
			table.push_back({ n, s }); // ������� ���� � ���������� �� � ����� �������
		}
	}
	out.close(); // ��������� ����

	sort(table.begin(), table.end(), [](const pair<string, int>& p1, const pair<string, int>& p2)
		{
			if (p1.second != p2.second)
			{
				// ���������� ������ ��������
				return p1.second > p2.second;
			}
			// ���������� ������, ���� ������ �������� �����
			return p1.first < p2.first;
		}
	);

	for (const auto& [n, s] : table) // ���������� �� ���������
	{
		cout << n << " " << s << endl; // � ������� �
	}
}