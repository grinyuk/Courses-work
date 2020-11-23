#pragma once
#ifndef MenuNav
#define MenuNav
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <iomanip> 
#include <Windows.h>
using namespace std;

#define BUFFERSIZE 72

void fullConsole()
{
	system("mode con COLS=700");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
}
int GetChoiceNumberMenu()
{
	char string[BUFFERSIZE][BUFFERSIZE] = {
		" 1. ��������� ���.",
		" 2. ������ ��� ������ �� ���� �����.",
		" 3. ���������� �������� �����.",
		" 4. �������� �������� �����.",
		" 5. ����������� ���� �������� �����.",
		" 6. �������� ����� � ��������.",
		" 7. ����� ������.",
		" 8. ��������� ����� � .txt � .bin.",
		" 9. ��������� ������."
	};
	char pointStart[BUFFERSIZE] = ">>";
	char pointFinish[BUFFERSIZE] = "  ";
	unsigned int choice = 0, row;
	do
	{
		system("cls");
		cout << "\n\t\t\t���� ��������" << endl;
		for (row = 0; row < 9; row++)
			printf("%s %s\n",
				row == choice ? pointStart : pointFinish,
				string[row]);
		switch (_getch())
		{
		case 72:
		{
			(choice != 0) ?	choice-- : choice = 8;
			break;
		}
		case 80:
		{
			(choice != 8) ? choice++ : choice = 0;
			break;
		}
		case 13:
			return ++choice;
			break;
		}
	} while (true);
}
int GetChoiceSortNumber()
{
	char string[BUFFERSIZE][BUFFERSIZE] = {		
			" 1. �� �������: �������� / ���������.",
			" 2. �� ����� �������: �������� / ���������.",
			" 3. �� ���� ������: �������� / ���������.",
			" 4. �� ���� ���������: �������� / ���������.",
			" 5. �����."
	};
	char pointStart[BUFFERSIZE] = ">>";
	char pointFinish[BUFFERSIZE] = "  ";
	unsigned int choice = 0, row;
	do
	{
		system("cls");
		cout << endl << "\t\t���������� �����" << endl;
		for (row = 0; row < 5; row++)
			printf("%s %s\n",
				row == choice ? pointStart : pointFinish,
				string[row]);
		switch (_getch())
		{
		case 72:
		{
			(choice != 0) ? choice-- : choice = 4;
			break;
		}
		case 80:
		{
			(choice != 4) ? choice++ : choice = 0;
			break;
		}
		case 13:
			return ++choice;
			break;
		}
	} while (true);
}
int GetChoiceSortPriceMod()
{
	char string[BUFFERSIZE][BUFFERSIZE] = {
			" 1. �� ��������� �������.",
			" 2. �� ���������� �������.",
	};
	char pointStart[BUFFERSIZE] = ">>";
	char pointFinish[BUFFERSIZE] = "  ";
	unsigned int choice = 0, row;
	do
	{
		system("cls");
		cout << endl << "\t\t���������� �� ������� ������" << endl;
		for (row = 0; row < 2; row++)
			printf("%s %s\n",
				row == choice ? pointStart : pointFinish,
				string[row]);
		switch (_getch())
		{
		case 72:
		{
			if (choice != 0)choice--;
			break;
		}
		case 80:
		{
			if (choice != 1)choice++;
			break;
		}
		case 13:
			return choice;
			break;
		}
	} while (true);
}
int GetChoiceSortYearMod()
{
	char string[BUFFERSIZE][BUFFERSIZE] = {
			" 1. ³� ��������� ������ �� �������.",
			" 2. ³� ������� ������ �� �����.",
	};
	char pointStart[BUFFERSIZE] = ">>";
	char pointFinish[BUFFERSIZE] = "  ";
	unsigned int choice = 0, row;
	do
	{
		system("cls");
		cout << endl << "\t\t���������� �� ����� �������" << endl;
		for (row = 0; row < 2; row++)
			printf("%s %s\n",
				row == choice ? pointStart : pointFinish,
				string[row]);
		switch (_getch())
		{
		case 72:
		{
			if (choice != 0)choice--;
			break;
		}
		case 80:
		{
			if (choice != 1)choice++;
			break;
		}
		case 13:
			return choice;
			break;
		}
	} while (true);


}
int GetChoiceSortNameMod()
{
	char string[BUFFERSIZE][BUFFERSIZE] = {
			" 1. ������������� ������ �-�",
			" 2. ������������� ������ �-�"
	};
	char pointStart[BUFFERSIZE] = ">>";
	char pointFinish[BUFFERSIZE] = "  ";
	unsigned int choice = 0, row;
	do
	{
		system("cls");
		cout << endl << "\t\t���������� �� ������ ������" << endl;
		for (row = 0; row < 2; row++)
			printf("%s %s\n",
				row == choice ? pointStart : pointFinish,
				string[row]);
		switch (_getch())
		{
		case 72:
		{
			if (choice != 0)choice--;
			break;
		}
		case 80:
		{
			if (choice != 1)choice++;
			break;
		}
		case 13:
			return choice;
			break;
		}
	} while (true);
}
int GetChoiceSortFirmMod()
{
	char string[BUFFERSIZE][BUFFERSIZE] = {
			" 1. ������������� ������ �-�",
			" 2. ������������� ������ �-�"
	};
	char pointStart[BUFFERSIZE] = ">>";
	char pointFinish[BUFFERSIZE] = "  ";
	unsigned int choice = 0, row;
	do
	{
		system("cls");
		cout << endl << "\t\t���������� �� ������ �����" << endl;
		for (row = 0; row < 2; row++)
			printf("%s %s\n",
				row == choice ? pointStart : pointFinish,
				string[row]);
		switch (_getch())
		{
		case 72:
		{
			if (choice != 0)choice--;
			break;
		}
		case 80:
		{
			if (choice != 1)choice++;
			break;
		}
		case 13:
			return choice;
			break;
		}
	} while (true);
}
int GetChoiseMyVarianMenu()
{
	char string[BUFFERSIZE][BUFFERSIZE] = {
		" 1. ��� ��� ��������� ����� Samsung � ������� �������.",
		" 2. ������, ������� ����� ��� ���� ���� � ����� ����� 1000 ���.",
		" 3. ��������� ������, ��������� ���� ���� ����.",
		" 4. ³���������� �� ��������� �������.",
		" 5. �����."
	};

	char pointStart[BUFFERSIZE] = ">>";
	char pointFinish[BUFFERSIZE] = "  ";
	unsigned int choice = 0, row;
	do
	{
		system("cls");
		cout << endl << "\t\t������������� ������" << endl;
		for (row = 0; row < 5; row++)
			printf("%s %s\n",
				row == choice ? pointStart : pointFinish,
				string[row]);
		switch (_getch())
		{
		case 72:
		{
			(choice != 0) ? choice-- : choice = 4;
			break;
		}
		case 80:
		{
			(choice != 4) ? choice++ : choice = 0;
			break;
		}
		case 13:
			return ++choice;
			break;
		}
	} while (true);
}
int GetChoiseNumberSearchMenu()
{
	char string[BUFFERSIZE][BUFFERSIZE] = {
		" 1. �� ����� ������.",
		" 2. �� ������������� ������.",
		" 3. ������ � / ��� ������.",
		" 4. �� ����� ������� ������.",
		" 5. �� ������-����������.",
		" 6. �����."
	};

	char pointStart[BUFFERSIZE] = ">>";
	char pointFinish[BUFFERSIZE] = "  ";
	unsigned int choice = 0, row;
	do
	{
		system("cls");
		cout << endl << "\t\t����� ������" << endl;
		for (row = 0; row < 6; row++)
			printf("%s %s\n",
				row == choice ? pointStart : pointFinish,
				string[row]);
		switch (_getch())
		{
		case 72:
		{
			(choice != 0) ? choice-- : choice = 5;
			break;
		}
		case 80:
		{
			(choice != 5) ? choice++ : choice = 0;
			break;
		}
		case 13:
			return ++choice;
			break;
		}
	} while (true);
}
int GetChoiseGarantStatus()
{
	char string[BUFFERSIZE][BUFFERSIZE] = {
		" 1. ������ ��� ������.",
		" 2. ������ � ������� �������."
	};

	char pointStart[BUFFERSIZE] = ">>";
	char pointFinish[BUFFERSIZE] = "  ";
	unsigned int choice = 0, row;
	do
	{
		system("cls");
		cout << endl << "\t\t�������" << endl;
		for (row = 0; row < 2; row++)
			printf("%s %s\n",
				row == choice ? pointStart : pointFinish,
				string[row]);
		switch (_getch())
		{
		case 72:
		{
			(choice != 0) ? choice-- : choice = 1;
			break;
		}
		case 80:
		{
			(choice != 1) ? choice++ : choice = 0;
			break;
		}
		case 13:
			return choice;
			break;
		}
	} while (true);
}
int GetChoiceYesOrNot()
{
	char string[BUFFERSIZE][BUFFERSIZE] = {
		" 1. ���.",
		" 2. ͳ."
	};

	char pointStart[BUFFERSIZE] = ">>";
	char pointFinish[BUFFERSIZE] = "  ";
	unsigned int choice = 0, row;
	do
	{
		system("cls");
		cout << " �������� ���� ����� ���� ������� ��� � �����!" << endl;
		cout << " ����������? " << endl;
		for (row = 0; row < 2; row++)
			printf("%s %s\n",
				row == choice ? pointStart : pointFinish,
				string[row]);
		switch (_getch())
		{
		case 72:
		{
			(choice != 0) ? choice-- : choice = 1;
			break;
		}
		case 80:
		{
			(choice != 1) ? choice++ : choice = 0;
			break;
		}
		case 13:
			return choice;
			break;
		}
	} while (true);
}

#endif