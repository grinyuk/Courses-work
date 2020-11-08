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

int GetChoiceNumberMenu()
{
	char string[BUFFERSIZE][BUFFERSIZE] = {
		" 1. Сортувати дані.",
		" 2. Додати нові записи до бази даних.",
		" 3. Редагувати існуючий запис.",
		" 4. Видалити існуючий запис.",
		" 5. Переглянути вміст бінарного файлу.",
		" 6. Операції згідно з варіантом.",
		" 7. Пошук товарів.",
		" 8. Перезапис файлу з .txt в .bin.",
		" 9. Завершити роботу."
	};
	char pointStart[BUFFERSIZE] = ">>";
	char pointFinish[BUFFERSIZE] = "  ";
	unsigned int choice = 0, row;
	do
	{
		system("cls");
		cout << "\n\t\t\tМеню програми" << endl;
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
			" 1. За вартістю: спадання / зростання.",
			" 2. За роком випуску: спадання / зростання.",
			" 3. По назві товару: спадання / зростання.",
			" 4. По назві виробника: спадання / зростання.",
			" 5. Назад."
	};
	char pointStart[BUFFERSIZE] = ">>";
	char pointFinish[BUFFERSIZE] = "  ";
	unsigned int choice = 0, row;
	do
	{
		system("cls");
		cout << endl << "\t\tСортування даних" << endl;
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
			" 1. За спаданням вартості.",
			" 2. За зростанням вартості.",
	};
	char pointStart[BUFFERSIZE] = ">>";
	char pointFinish[BUFFERSIZE] = "  ";
	unsigned int choice = 0, row;
	do
	{
		system("cls");
		cout << endl << "\t\tСортування за вартістю товару" << endl;
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
			" 1. Від найновіших товарів до старіших.",
			" 2. Від старіших товарів до нових.",
	};
	char pointStart[BUFFERSIZE] = ">>";
	char pointFinish[BUFFERSIZE] = "  ";
	unsigned int choice = 0, row;
	do
	{
		system("cls");
		cout << endl << "\t\tСортування за роком випуску" << endl;
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
			" 1. Впорядкування товарів А-Я",
			" 2. Впорядкування товарів Я-А"
	};
	char pointStart[BUFFERSIZE] = ">>";
	char pointFinish[BUFFERSIZE] = "  ";
	unsigned int choice = 0, row;
	do
	{
		system("cls");
		cout << endl << "\t\tСортування за назвою товару" << endl;
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
			" 1. Впорядкування товарів А-Я",
			" 2. Впорядкування товарів Я-А"
	};
	char pointStart[BUFFERSIZE] = ">>";
	char pointFinish[BUFFERSIZE] = "  ";
	unsigned int choice = 0, row;
	do
	{
		system("cls");
		cout << endl << "\t\tСортування за назвою фірми" << endl;
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
		" 1. Дані про телевізори фірми Samsung з наявною гарантією.",
		" 2. Товари, випущені понад два роки тому з ціною понад 1000 грн.",
		" 3. Видалення товарів, випущених п’ять років тому.",
		" 4. Відсортувати за спаданням вартості.",
		" 5. Назад."
	};

	char pointStart[BUFFERSIZE] = ">>";
	char pointFinish[BUFFERSIZE] = "  ";
	unsigned int choice = 0, row;
	do
	{
		system("cls");
		cout << endl << "\t\tІндивідуальний варіант" << endl;
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
		" 1. За кодом товару.",
		" 2. За найменуванням товару.",
		" 3. Товари з / без гарантії.",
		" 4. За роком випуску товару.",
		" 5. За фірмою-виробником.",
		" 6. Назад."
	};

	char pointStart[BUFFERSIZE] = ">>";
	char pointFinish[BUFFERSIZE] = "  ";
	unsigned int choice = 0, row;
	do
	{
		system("cls");
		cout << endl << "\t\tПошук товарів" << endl;
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
		" 1. Товари без гарантії.",
		" 2. Товари з наявною гарантією."
	};

	char pointStart[BUFFERSIZE] = ">>";
	char pointFinish[BUFFERSIZE] = "  ";
	unsigned int choice = 0, row;
	do
	{
		system("cls");
		cout << endl << "\t\tГарантія" << endl;
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