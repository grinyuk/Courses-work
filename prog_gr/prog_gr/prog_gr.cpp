/*
	треба написати функцію для натиску довільної клавіші
*/
#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include "ElShopLib.h"
#include "MenuNav.h"
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <iomanip> 
#include <Windows.h>
#define MAX 100
using namespace std;

FILE *f, *fb;

struct ElShop
{
	int number;
	int id;
	char name[20];
	char firm[15];
	int year;
	float price;
	char garant[5];
};

enum Colors
{
	GREEN = 10,
	BLUE,
	RED,
	PINK,
	YELLOW,
	WHITE
};

void validation(ElShop shop[], int i)//Рекурсивна функція валідації введених даних
{
	if (shop[i].id < 1000 || 9999 < shop[i].id)
	{
		SetConsoleTextAttribute(hConsole, RED);
		cout << " Невірний код товару" << endl;
		SetConsoleTextAttribute(hConsole, WHITE);
		cout << " Введіть число з 4-х цифр: ";
		cin >> shop[i].id;
		validation(shop, i);
	}
	if (strpbrk(shop[i].name, "/\?!,.;:@#$%^&*()-=_+<>|0123456789") != NULL)
	{
		SetConsoleTextAttribute(hConsole, RED);
		cout << " Найменування товару містить сторонні символи!" << endl;
		SetConsoleTextAttribute(hConsole, WHITE);
		cout << " Введіть назву правильно: ";
		cin >> shop[i].name;
		validation(shop, i);
	}
	if (strpbrk(shop[i].firm, "/\?!,.;:@#$%^&*()-=_+<>|0123456789") != NULL)
	{
		SetConsoleTextAttribute(hConsole, RED);
		cout << " Назва фірми містить сторонні символи!" << endl;
		SetConsoleTextAttribute(hConsole, WHITE);
		cout << " Введіть назву правильно: ";
		cin >> shop[i].firm;
		validation(shop, i);
	}
	if (shop[i].year > 2020 || shop[i].year < 2000)
	{
		SetConsoleTextAttribute(hConsole, RED);
		cout << " Не коректний рік виробництва товару" << endl;
		SetConsoleTextAttribute(hConsole, WHITE);
		cout << " Введіть рік ще раз: ";
		cin >> shop[i].year;
		validation(shop, i);
	}
	if (shop[i].price < 0)
	{
		SetConsoleTextAttribute(hConsole, RED);
		cout << " Ціна не може бути від'ємною!" << endl;
		SetConsoleTextAttribute(hConsole, WHITE);
		cout << " Введіть ціну ще раз: ";
		cin >> shop[i].price;
		validation(shop, i);
	}
	if (strcmp(shop[i].garant, "так") != 0 && strcmp(shop[i].garant, "ні") != 0)
	{
		SetConsoleTextAttribute(hConsole, RED);
		cout << " Не відомий статус гарантії!" << endl;
		SetConsoleTextAttribute(hConsole, WHITE);
		cout << " Введіть статус ще раз: ";
		cin >> shop[i].garant;
		validation(shop, i);
	}
}
void search_validation(int sid, char *sname, char *sfirm, int syear)
{

	if (sname != NULL)
	{
		if (strpbrk(sname, "/\?!,.;:@#$%^&*()-=_+<>|0123456789") != NULL)
		{
			SetConsoleTextAttribute(hConsole, 12);
			cout << " Найменування шуканого товару містить сторонні символи!" << endl;
			SetConsoleTextAttribute(hConsole, 15);
			cout << " Введіть назву правильно: ";
			cin >> sname;
			search_validation(0, sname, NULL, 0);
		}
	}
	if (sfirm != NULL)
	{
		if (strpbrk(sfirm, "/\?!,.;:@#$%^&*()-=_+<>|0123456789") != NULL)
		{
			SetConsoleTextAttribute(hConsole, 12);
			cout << " Назва шуканої фірми містить сторонні символи!" << endl;
			SetConsoleTextAttribute(hConsole, 15);
			cout << " Введіть назву правильно: ";
			cin >> sfirm;
			search_validation(0, NULL, sfirm, 0);
		}
	}
}
int search_id_validation(int id)
{
	if (id < 1000 || 9999 < id)
	{
		SetConsoleTextAttribute(hConsole, RED);
		cout << " Невірний код шуканого товару" << endl;
		SetConsoleTextAttribute(hConsole, WHITE);
		cout << " Введіть число з 4-х цифр: ";
		cin >> id;
		search_id_validation(id);
	}
	return id;
}
int search_year_validation(int year)
{
	if (year > 2020 || year < 2000)
	{
		SetConsoleTextAttribute(hConsole, RED);
		cout << " Не коректний рік виробництва шуканого товару" << endl;
		SetConsoleTextAttribute(hConsole, WHITE);
		cout << " Введіть рік ще раз: ";
		cin >> year;
		search_year_validation(year);
	}
	return year;
}
void print_file(ElShop shop[], int last)
{
	system("cls");
	fb = fopen("Base.bin", "rb");
	opening_error(fb);
	cout << " №    Код      Найменування   Фірма      Рік     Ціна     Гарантія" << endl;
	for (int i = 0; i < last; i++)
	{
		fread(&shop[i], sizeof(ElShop), 1, fb);
		if (shop[i].number < 10)
		{
			cout << left << " " << setw(5) << shop[i].number << setw(9) << shop[i].id << setw(15) << shop[i].name << setw(11) << shop[i].firm << setw(8) << shop[i].year << setw(9) << shop[i].price << shop[i].garant << endl;
			continue;
		}
		cout << left << setw(6) << shop[i].number << setw(9) << shop[i].id << setw(15) << shop[i].name << setw(11) << shop[i].firm << setw(8) << shop[i].year << setw(9) << shop[i].price << shop[i].garant << endl;
	}
	fclose(fb);
}
void add_row(int last)
{
	int c;
	ElShop shopp[MAX];
	fb = fopen("Base.bin", "r+b");
	opening_error(fb);
	fseek(fb, 0, SEEK_END);
	system("cls");
	cout << "Скільки записів ви хочете додати?" << endl << "--> ";
	cin >> c;
	cout << "\t\t Введіть дані через пробіл/Tab і натисніть Enter" << endl;
	cout << " Код -> Найменування -> Фірма -> Рік -> Ціна - > Гарантія" << endl;
	for (int i = 0; i < c; i++)
	{
		shopp[i].number = num_of_last_row() + 1 + i;
		cin >> ws >> shopp[i].id >> shopp[i].name >> shopp[i].firm >> shopp[i].year >> shopp[i].price >> shopp[i].garant;
		validation(shopp, i);
		fwrite(&shopp[i], sizeof(ElShop), 1, fb);
	}
	fclose(fb);
}
void del_row(ElShop shop[], int last)
{
	system("cls");
	fb = fopen("Base.bin", "r+b");
	opening_error(fb);
	int del_num;
	cout << endl << " Введіть номер видаляємого запису: ";
	cin >> del_num;
	for (int i = 0; i < last; i++)
	{
		fread(&shop[i], sizeof(ElShop), 1, fb);
	}
	if (del_num == shop[last - 1].number)//окреме видалення останнього запису
	{
		fb = fopen("Base.bin", "w+b");
		opening_error(fb);
		for (int i = 0; i < last - 1; i++)
		{
			fwrite(&shop[i], sizeof(ElShop), 1, fb);
		}
		system("cls");
		SetConsoleTextAttribute(hConsole, GREEN);
		cout << endl << " Видалення успішне!" << endl;
		SetConsoleTextAttribute(hConsole, WHITE);
		fclose(fb);
		return;
	}
	fclose(fb);
	fb = fopen("Base.bin", "w+b");
	opening_error(fb);
	for (int i = 0; i < last; i++)//головне видалення
	{
		if (i == del_num - 1)
		{
			i++;
		}
		if (del_num - 1 <= i)
		{
			shop[i].number -= 1;
		}
		fwrite(&shop[i], sizeof(ElShop), 1, fb);
	}
	system("cls");
	SetConsoleTextAttribute(hConsole, 10);
	cout << endl << " Видалення успішне!" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	fclose(fb);
}
void rewrite(ElShop shop[])//перезапис з txt в  bin
{
	int i = 0;
	f = fopen("Database.txt", "r");
	opening_error(f);
	fb = fopen("Base.bin", "w+b");
	opening_error(fb);
	while (!feof(f))
	{
		fscanf(f, "%i %i %s %s %i %f %s", &shop[i].number, &shop[i].id, shop[i].name, shop[i].firm, &shop[i].year, &shop[i].price, shop[i].garant);
		fwrite(&shop[i], sizeof(ElShop), 1, fb);
	}
	SetConsoleTextAttribute(hConsole, GREEN);
	cout << endl << "\t\tФайл перезаписано!" << endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	fclose(fb);
	fclose(f);
}
void editing(ElShop shop[], int last)//в цій функції розривв між читанням і записом
{
	fb = fopen("Base.bin", "r+b");
	opening_error(fb);
	int edit_num;
	cout << endl << "Введіть номер редагуємого запису: ";
	cin >> edit_num;
	fseek(fb, (edit_num - 1) * sizeof(ElShop), SEEK_SET);
	cout << " Введіть відредагований запис:" << endl;
	cout << " Код -> Найменування -> Фірма -> Рік -> Ціна -> Гарантія" << endl;
	shop[0].number = edit_num;
	cin >> ws >> shop[0].id >> shop[0].name >> shop[0].firm >> shop[0].year >> shop[0].price >> shop[0].garant;
	fwrite(&shop[0], sizeof(ElShop), 1, fb);
	SetConsoleTextAttribute(hConsole, GREEN);
	cout << endl << " Файл успішно відредаговано!" << endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	fclose(fb);
}
void search(ElShop shop[], int last, int x)
{
	fb = fopen("Base.bin", "rb");
	opening_error(fb);
	switch (x)
	{
	case 1://за кодом товару
	{
		system("cls");
		int id_product;
		bool not_result = true;
		cout << " Введіть код потрібного товару: ";
		cin >> id_product;//шуканий код
		id_product = search_id_validation(id_product);
		system("cls");
		cout << " Товари з кодом " << id_product << ":" << endl;
		cout << " №    Код      Найменування   Фірма      Рік     Ціна     Гарантія" << endl;
		for (int i = 0; i < last; i++)
		{
			fread(&shop[i], sizeof(ElShop), 1, fb);//зчитуєм кожний запис в файлі
			if (shop[i].id == id_product)//порівнюєм коди товарів
			{
				not_result = false;//на випадок якщо не знайдено жодного товару
				if (shop[i].number < 10)
				{
					cout << left << " " << setw(5) << shop[i].number << setw(9) << shop[i].id << setw(15) << shop[i].name << setw(11) << shop[i].firm << setw(8) << shop[i].year << setw(9) << shop[i].price << shop[i].garant << endl;
					continue;
				}
				cout << left << setw(6) << shop[i].number << setw(9) << shop[i].id << setw(15) << shop[i].name << setw(11) << shop[i].firm << setw(8) << shop[i].year << setw(9) << shop[i].price << shop[i].garant << endl;
			}
		}
		if (not_result)//сповіщення про відсутність товарів з таким кодом
		{
			system("cls");
			SetConsoleTextAttribute(hConsole, RED);
			cout << " Товарів з кодом " << id_product << " не знайдено!" << endl;
			SetConsoleTextAttribute(hConsole, WHITE);
		}
		break;
	}
	case 2://за назвою товару
	{
		system("cls");
		char name_product[15];
		bool not_result = true;
		cout << "Введіть назву шуканого товару: ";
		cin >> name_product;
		system("cls");
		cout << " Товари з назвою " << name_product << ":" << endl;
		cout << " №    Код      Найменування   Фірма      Рік     Ціна     Гарантія" << endl;
		name_product[0] = toupper(name_product[0]);
		for (int i = 1; name_product[i] != '\0'; i++)
		{
			name_product[i] = tolower(name_product[i]);
		}
		for (int i = 0; i < last; i++)
		{
			fread(&shop[i], sizeof(ElShop), 1, fb);//зчитуєм кожний запис в файлі
			if (strcmp(shop[i].name, name_product) == 0)//порівнюєм назви товарів
			{
				not_result = false;//на випадок якщо не знайдено жодного товару
				if (shop[i].number < 10)
				{
					cout << left << " " << setw(5) << shop[i].number << setw(9) << shop[i].id << setw(15) << shop[i].name << setw(11) << shop[i].firm << setw(8) << shop[i].year << setw(9) << shop[i].price << shop[i].garant << endl;
					continue;
				}
				cout << left << setw(6) << shop[i].number << setw(9) << shop[i].id << setw(15) << shop[i].name << setw(11) << shop[i].firm << setw(8) << shop[i].year << setw(9) << shop[i].price << shop[i].garant << endl;
			}
		}
		if (not_result)//сповіщення про відсутність товарів з такою назвою
		{
			system("cls");
			SetConsoleTextAttribute(hConsole, RED);
			cout << " Товарів з назвою " << name_product << " не знайдено!" << endl;
			SetConsoleTextAttribute(hConsole, WHITE);
		}
		break;
	}
	case 3://за наявністю гарантії
	{
		system("cls");
		if (GetChoiseGarantStatus())
		{
			system("cls");
			cout << "\t\tТовари з гарантією" << endl;
			cout << " №    Код      Найменування   Фірма      Рік     Ціна     Гарантія" << endl;
			for (int i = 0; i < last; i++)
			{
				fread(&shop[i], sizeof(ElShop), 1, fb);//зчитуєм кожний запис в файлі
				if (strcmp(shop[i].garant, "так") == 0)//перевіряєм наявність гарантії
				{
					if (shop[i].number < 10)
					{
						cout << left << " " << setw(5) << shop[i].number << setw(9) << shop[i].id << setw(15) << shop[i].name << setw(11) << shop[i].firm << setw(8) << shop[i].year << setw(9) << shop[i].price << shop[i].garant << endl;
						continue;
					}
					cout << left << setw(6) << shop[i].number << setw(9) << shop[i].id << setw(15) << shop[i].name << setw(11) << shop[i].firm << setw(8) << shop[i].year << setw(9) << shop[i].price << shop[i].garant << endl;
				}
			}
		}
		else
		{
			system("cls");
			cout << "\t\tТовари без гарантії" << endl;
			cout << " №    Код      Найменування   Фірма      Рік     Ціна     Гарантія" << endl;
			for (int i = 0; i < last; i++)
			{
				fread(&shop[i], sizeof(ElShop), 1, fb);//зчитуєм кожний запис в файлі
				if (strcmp(shop[i].garant, "ні") == 0)//перевіряєм наявність гарантії
				{
					if (shop[i].number < 10)
					{
						cout << left << " " << setw(5) << shop[i].number << setw(9) << shop[i].id << setw(15) << shop[i].name << setw(11) << shop[i].firm << setw(8) << shop[i].year << setw(9) << shop[i].price << shop[i].garant << endl;
						continue;
					}
					cout << left << setw(6) << shop[i].number << setw(9) << shop[i].id << setw(15) << shop[i].name << setw(11) << shop[i].firm << setw(8) << shop[i].year << setw(9) << shop[i].price << shop[i].garant << endl;
				}
			}
		}
		break;
	}
	case 4://за роком випуску товару
	{
		system("cls");
		int year_product;
		bool not_result = true;
		cout << " Введіть рік випуску потрібного товару: ";
		cin >> year_product;//шуканий рік
		year_product = search_year_validation(year_product);
		system("cls");
		cout << " Товари " << year_product << "-го року виробницва:" << endl;
		cout << " №    Код      Найменування   Фірма      Рік     Ціна     Гарантія" << endl;
		for (int i = 0; i < last; i++)
		{
			fread(&shop[i], sizeof(ElShop), 1, fb);//зчитуєм кожний запис в файлі
			if (shop[i].year == year_product)//порівнюєм роки випуску товарів
			{
				not_result = false;//на випадок якщо не знайдено жодного товару
				if (shop[i].number < 10)
				{
					cout << left << " " << setw(5) << shop[i].number << setw(9) << shop[i].id << setw(15) << shop[i].name << setw(11) << shop[i].firm << setw(8) << shop[i].year << setw(9) << shop[i].price << shop[i].garant << endl;
					continue;
				}
				cout << left << setw(6) << shop[i].number << setw(9) << shop[i].id << setw(15) << shop[i].name << setw(11) << shop[i].firm << setw(8) << shop[i].year << setw(9) << shop[i].price << shop[i].garant << endl;
			}
		}
		if (not_result)//сповіщення про відсутність товарів з таким роком випуску
		{
			system("cls");
			SetConsoleTextAttribute(hConsole, RED);
			cout << " Товарів " << year_product << "-го року випуску не знайдено!" << endl;
			SetConsoleTextAttribute(hConsole, WHITE);
		}
		break;
	}
	case 5://за фірмою виробником
	{
		system("cls");
		char firm_product[15];
		bool not_result = true;
		cout << "Введіть назву фірми-виробника: ";
		cin >> firm_product;
		system("cls");
		cout << " Товари виготовлені фірмою " << firm_product << ":" << endl;
		cout << " №    Код      Найменування   Фірма      Рік     Ціна     Гарантія" << endl;
		for (int i = 0; i < last; i++)
		{
			fread(&shop[i], sizeof(ElShop), 1, fb);//зчитуєм кожний запис в файлі
			if (strcmp(shop[i].firm, firm_product) == 0)//порівнюєм фірми товарів
			{
				not_result = false;//на випадок якщо не знайдено жодного товару
				if (shop[i].number < 10)
				{
					cout << left << " " << setw(5) << shop[i].number << setw(9) << shop[i].id << setw(15) << shop[i].name << setw(11) << shop[i].firm << setw(8) << shop[i].year << setw(9) << shop[i].price << shop[i].garant << endl;
					continue;
				}
				cout << left << setw(6) << shop[i].number << setw(9) << shop[i].id << setw(15) << shop[i].name << setw(11) << shop[i].firm << setw(8) << shop[i].year << setw(9) << shop[i].price << shop[i].garant << endl;
			}
		}
		if (not_result)//сповіщення про відсутність товарів токої фірми
		{
			system("cls");
			SetConsoleTextAttribute(hConsole, RED);
			cout << " Товарів від фірми " << firm_product << " не знайдено!" << endl;
			SetConsoleTextAttribute(hConsole, WHITE);
		}
		break;
	}
	default:
	{
		system("cls");
		break;
	}
	}
	fclose(fb);
}
void samsung_tv(ElShop shop[], int last)
{
	fb = fopen("Base.bin", "rb");
	opening_error(fb);
	bool not_result = true;
	system("cls");
	cout << " Товари з кодом :" << endl;
	cout << " №    Код      Найменування   Фірма      Рік     Ціна     Гарантія" << endl;
	for (int i = 0; i < last; i++)
	{
		fread(&shop[i], sizeof(ElShop), 1, fb);//зчитуєм кожний запис в файлі
		if (!strcmp(shop[i].name, "Телевізор") && !strcmp(shop[i].garant, "так"))//порівнюєм 
		{
			not_result = false;//на випадок якщо не знайдено жодного товару
			if (shop[i].number < 10)
			{
				cout << left << " " << setw(5) << shop[i].number << setw(9) << shop[i].id << setw(15) << shop[i].name << setw(11) << shop[i].firm << setw(8) << shop[i].year << setw(9) << shop[i].price << shop[i].garant << endl;
				continue;
			}
			cout << left << setw(6) << shop[i].number << setw(9) << shop[i].id << setw(15) << shop[i].name << setw(11) << shop[i].firm << setw(8) << shop[i].year << setw(9) << shop[i].price << shop[i].garant << endl;
		}
	}
	if (not_result)//сповіщення про відсутність товарів з таким кодом
	{
		system("cls");
		SetConsoleTextAttribute(hConsole, RED);
		cout << " Телевізори компанії Samsung з наявною гарантією відсутні " << endl;
		SetConsoleTextAttribute(hConsole, WHITE);
	}
	fclose(fb);
}
void old_products(ElShop shop[], int last)
{
	fb = fopen("Base.bin", "rb");
	opening_error(fb);
	bool not_result = true;
	system("cls");
	cout << " Товари випущені понад 2 роки тому з вартістю більше 1000 грн.:" << endl;
	cout << " №    Код      Найменування   Фірма      Рік     Ціна     Гарантія" << endl;
	for (int i = 0; i < last; i++)
	{
		fread(&shop[i], sizeof(ElShop), 1, fb);//зчитуєм кожний запис в файлі
		if (shop[i].year < 2018 && 1000 < shop[i].price)//порівнюєм 
		{
			not_result = false;//на випадок якщо не знайдено жодного товару
			if (shop[i].number < 10)
			{
				cout << left << " " << setw(5) << shop[i].number << setw(9) << shop[i].id << setw(15) << shop[i].name << setw(11) << shop[i].firm << setw(8) << shop[i].year << setw(9) << shop[i].price << shop[i].garant << endl;
				continue;
			}
			cout << left << setw(6) << shop[i].number << setw(9) << shop[i].id << setw(15) << shop[i].name << setw(11) << shop[i].firm << setw(8) << shop[i].year << setw(9) << shop[i].price << shop[i].garant << endl;
		}
	}
	if (not_result)//сповіщення про відсутність товарів
	{
		system("cls");
		SetConsoleTextAttribute(hConsole, RED);
		cout << " Товарів випущених понад 2 роки тому з ціною більше 1000 грн. не знайдено!" << endl;
		SetConsoleTextAttribute(hConsole, WHITE);
	}
	fclose(fb);
}
void del_oldest_products(ElShop shop[], int last)
{
	fb = fopen("Base.bin", "r+b");
	opening_error(fb);
	for (int i = 0; i < last; i++)
	{
		fread(&shop[i], sizeof(ElShop), 1, fb);
	}
	fclose(fb);
	fb = fopen("Base.bin", "w+b");
	opening_error(fb);
	for (int i = 0, j = 1; i < last; i++)
	{
		if (2015 != shop[i].year)
		{
			shop[i].number = j;
			fwrite(&shop[i], sizeof(ElShop), 1, fb);
			j++;
		}

	}
	system("cls");
	SetConsoleTextAttribute(hConsole, GREEN);
	cout << "Видалення завершилось успішно!" << endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	fclose(fb);
}
void desc_sort(ElShop shop[], int last)
{
	system("cls");
	fb = fopen("Base.bin", "rb");
	opening_error(fb);
	for (int i = 0; i < last; i++)
	{
		fread(&shop[i], sizeof(ElShop), 1, fb);
	}
	for (int i = 0;i < last - 1;i++)
	{
		for (int j = i + 1;j < last;j++)
		{
			if (shop[j].price > shop[i].price)
			{
				swap(shop[j], shop[i]);
			}
		}
	}
	cout << "\t\tТовари відсортовані за спаданням вартості:" << endl;
	cout << " №    Код      Найменування   Фірма      Рік     Ціна     Гарантія" << endl;
	for (int i = 0; i < last; i++)
	{
		shop[i].number = i + 1;
		if (shop[i].number < 10)
		{
			cout << left << " " << setw(5) << shop[i].number << setw(9) << shop[i].id << setw(15) << shop[i].name << setw(11) << shop[i].firm << setw(8) << shop[i].year << setw(9) << shop[i].price << shop[i].garant << endl;
			continue;
		}
		cout << left << setw(6) << shop[i].number << setw(9) << shop[i].id << setw(15) << shop[i].name << setw(11) << shop[i].firm << setw(8) << shop[i].year << setw(9) << shop[i].price << shop[i].garant << endl;
	}
	fclose(fb);
}
void price_sort(ElShop shop[], int last, int mod)
{
	system("cls");
	fb = fopen("Base.bin", "rb");
	opening_error(fb);
	for (int i = 0; i < last; i++)
	{
		fread(&shop[i], sizeof(ElShop), 1, fb);
	}
	for (int i = 0;i < last - 1;i++)
	{
		for (int j = i + 1;j < last;j++)
		{
			if (!mod)
			{
				if (shop[j].price > shop[i].price)
				{
					swap(shop[j], shop[i]);
				}
			}
			else
			{
				if (shop[j].price < shop[i].price)
				{
					swap(shop[j], shop[i]);
				}
			}
		}
	}
	(!mod) ? cout << "\t\tТовари відсортовані за спаданням вартості:" << endl : cout << "\t\tТовари відсортовані за зростанням вартості:" << endl;
	cout << " №    Код      Найменування   Фірма      Рік     Ціна     Гарантія" << endl;
	for (int i = 0; i < last; i++)
	{
		shop[i].number = i + 1;
		if (shop[i].number < 10)
		{
			cout << left << " " << setw(5) << shop[i].number << setw(9) << shop[i].id << setw(15) << shop[i].name << setw(11) << shop[i].firm << setw(8) << shop[i].year << setw(9) << shop[i].price << shop[i].garant << endl;
			continue;
		}
		cout << left << setw(6) << shop[i].number << setw(9) << shop[i].id << setw(15) << shop[i].name << setw(11) << shop[i].firm << setw(8) << shop[i].year << setw(9) << shop[i].price << shop[i].garant << endl;
	}
	fclose(fb);
}
void year_sort(ElShop shop[], int last, int mod)
{
	system("cls");
	fb = fopen("Base.bin", "rb");
	opening_error(fb);
	for (int i = 0; i < last; i++)
	{
		fread(&shop[i], sizeof(ElShop), 1, fb);
	}
	for (int i = 0;i < last - 1;i++)
	{
		for (int j = i + 1;j < last;j++)
		{
			if (!mod)
			{
				if (shop[j].year > shop[i].year)
				{
					swap(shop[j], shop[i]);
				}
			}
			else
			{
				if (shop[j].year < shop[i].year)
				{
					swap(shop[j], shop[i]);
				}
			}
		}
	}
	(!mod) ? cout << "\t\tТовари відсортовані за спаданням року випуску:" << endl : cout << "\t\tТовари відсортовані за зростанням року випуску:" << endl;
	cout << " №    Код      Найменування   Фірма      Рік     Ціна     Гарантія" << endl;
	for (int i = 0; i < last; i++)
	{
		shop[i].number = i + 1;
		if (shop[i].number < 10)
		{
			cout << left << " " << setw(5) << shop[i].number << setw(9) << shop[i].id << setw(15) << shop[i].name << setw(11) << shop[i].firm << setw(8) << shop[i].year << setw(9) << shop[i].price << shop[i].garant << endl;
			continue;
		}
		cout << left << setw(6) << shop[i].number << setw(9) << shop[i].id << setw(15) << shop[i].name << setw(11) << shop[i].firm << setw(8) << shop[i].year << setw(9) << shop[i].price << shop[i].garant << endl;
	}
	fclose(fb);
}
void name_sort(ElShop shop[], int last, int mod)
{
	system("cls");
	fb = fopen("Base.bin", "rb");
	opening_error(fb);
	for (int i = 0; i < last; i++)
	{
		fread(&shop[i], sizeof(ElShop), 1, fb);
	}
	for (int i = 0;i < last - 1;i++)
	{
		for (int j = i + 1;j < last;j++)
		{
			if (mod)
			{
				if (0 < strcmp(shop[j].name, shop[i].name))
				{
					swap(shop[j], shop[i]);
				}
			}
			else
			{
				if (strcmp(shop[j].name, shop[i].name) < 0)
				{
					swap(shop[j], shop[i]);
				}
			}
		}
	}
	(mod) ? cout << "\t\tТовари відсортовані в алфавітному порядку за спаданням:" << endl : cout << "\t\tТовари відсортовані в алфавітному порядку за зростанням:" << endl;
	cout << " №    Код      Найменування   Фірма      Рік     Ціна     Гарантія" << endl;
	for (int i = 0; i < last; i++)
	{
		shop[i].number = i + 1;
		if (shop[i].number < 10)
		{
			cout << left << " " << setw(5) << shop[i].number << setw(9) << shop[i].id << setw(15) << shop[i].name << setw(11) << shop[i].firm << setw(8) << shop[i].year << setw(9) << shop[i].price << shop[i].garant << endl;
			continue;
		}
		cout << left << setw(6) << shop[i].number << setw(9) << shop[i].id << setw(15) << shop[i].name << setw(11) << shop[i].firm << setw(8) << shop[i].year << setw(9) << shop[i].price << shop[i].garant << endl;
	}
	fclose(fb);
}
void firm_sort(ElShop shop[], int last, int mod)
{
	system("cls");
	fb = fopen("Base.bin", "rb");
	opening_error(fb);
	for (int i = 0; i < last; i++)
	{
		fread(&shop[i], sizeof(ElShop), 1, fb);
	}
	for (int i = 0;i < last - 1;i++)
	{
		for (int j = i + 1;j < last;j++)
		{
			if (mod)
			{
				if (0 < strcmp(shop[j].firm, shop[i].firm))
				{
					swap(shop[j], shop[i]);
				}
			}
			else
			{
				if (strcmp(shop[j].firm, shop[i].firm) < 0)
				{
					swap(shop[j], shop[i]);
				}
			}
		}
	}
	(mod) ? cout << "\t\tТовари відсортовані в алфавітному порядку за спаданням:" << endl : cout << "\t\tТовари відсортовані в алфавітному порядку за зростанням:" << endl;
	cout << " №    Код      Найменування   Фірма      Рік     Ціна     Гарантія" << endl;
	for (int i = 0; i < last; i++)
	{
		shop[i].number = i + 1;
		if (shop[i].number < 10)
		{
			cout << left << " " << setw(5) << shop[i].number << setw(9) << shop[i].id << setw(15) << shop[i].name << setw(11) << shop[i].firm << setw(8) << shop[i].year << setw(9) << shop[i].price << shop[i].garant << endl;
			continue;
		}
		cout << left << setw(6) << shop[i].number << setw(9) << shop[i].id << setw(15) << shop[i].name << setw(11) << shop[i].firm << setw(8) << shop[i].year << setw(9) << shop[i].price << shop[i].garant << endl;
	}
	fclose(fb);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int c;
	ElShop shop[MAX];
	for (;;)//цикл для безкінечного вибору пунктів головного меню
	{
		switch (GetChoiceNumberMenu())
		{
		case 1://перше підменю
		{
			system("cls");			
			switch (GetChoiceSortNumber())
			{
			case 1://за вартістю
			{
				system("cls");
				c = GetChoiceSortPriceMod();
				int last_row = num_of_last_row();
				price_sort(shop, last_row, c);
				cout << endl << " Для повернення до головного меню натисніть любу клавішу...";
				_getch();
				break;
			}
			case 2://за роком
			{
				system("cls");						
				c = GetChoiceSortYearMod();
				int last_row = num_of_last_row();
				year_sort(shop, last_row, c);
				cout << endl << " Для повернення до головного меню натисніть любу клавішу...";
				_getch();
				break;
			}
			case 3://за назвою товару
			{
				system("cls");				
				c = GetChoiceSortNameMod();
				int last_row = num_of_last_row();
				name_sort(shop, last_row, c);
				cout << endl << " Для повернення до головного меню натисніть любу клавішу...";
				_getch();
				break;
			}
			case 4://за фірмою-виробником
			{
				system("cls");			
				c = GetChoiceSortFirmMod();
				int last_row = num_of_last_row();
				firm_sort(shop, last_row, c);
				cout << endl << " Для повернення до головного меню натисніть любу клавішу...";
				_getch();
				break;
			}
			case 5:
			{
				system("cls");
			}
			default:
				system("cls");
				break;
			}
			break;
		}
		case 2://додавання нових записів
		{
			int last_row = num_of_last_row();
			add_row(last_row);
			cout << endl << " Для повернення до головного меню натисніть любу клавішу...";
			_getch();
			break;
		}
		case 3://редагування даних
		{
			int last_row = num_of_last_row();
			editing(shop, last_row);
			cout << endl << " Для повернення до головного меню натисніть любу клавішу...";
			_getch();
			break;
		}
		case 4://видалення даних
		{
			int last_row = num_of_last_row();
			del_row(shop, last_row);
			cout << endl << " Для повернення до головного меню натисніть любу клавішу...";
			_getch();
			break;
		}
		case 5://перегляд бінарного файлу
		{
			int last_row = num_of_last_row();
			print_file(shop, last_row);
			cout << endl << " Для повернення до головного меню натисніть любу клавішу...";
			_getch();
			break;
		}
		case 6://розрахунки щодо індивідкального варіанту
		{
			system("cls");
			switch (GetChoiseMyVarianMenu())
			{
			case 1://телевізори самсунг
			{
				int last_row = num_of_last_row();
				samsung_tv(shop, last_row);
				cout << endl << " Для повернення до головного меню натисніть любу клавішу...";
				_getch();
				break;
			}
			case 2://продукти старше двох років
			{
				int last_row = num_of_last_row();
				old_products(shop, last_row);
				cout << endl << " Для повернення до головного меню натисніть любу клавішу...";
				_getch();
				break;
			}
			case 3://видалення товарів випущених 5 років тому
			{
				int last_row = num_of_last_row();
				del_oldest_products(shop, last_row);
				cout << endl << " Для повернення до головного меню натисніть любу клавішу...";
				_getch();
				break;
			}
			case 4://сортування за спаданням ціни
			{
				int last_row = num_of_last_row();
				desc_sort(shop, last_row);
				cout << endl << " Для повернення до головного меню натисніть любу клавішу...";
				_getch();
				break;
			}
			default://назад
				system("cls");
				break;
			}
			break;
		}
		case 7://критерії пошуку товарів
		{
			system("cls");
			c = GetChoiseNumberSearchMenu();
			int last_row = num_of_last_row();
			search(shop, last_row, c);
			cout << endl << " Для повернення до головного меню натисніть любу клавішу...";
			_getch();
			break;
		}
		case 8://перезапис з .txt в .bin 
		{
			system("cls");
			rewrite(shop);
			cout << endl << " Для повернення до головного меню натисніть любу клавішу...";
			_getch();
			break;
		}
		case 9://завершення роботи
		{
			system("cls");
			SetConsoleTextAttribute(hConsole, GREEN);
			cout << endl << "\t\tРоботу завершено!" << endl;
			SetConsoleTextAttribute(hConsole, WHITE);
			exit(1);
			return 0;
			break;
		}
		default://ніколи не виконається
		{
			system("cls");
			SetConsoleTextAttribute(hConsole, RED);
			cout << endl << "\t\t    Неіснуючий пункт меню!" << endl;
			SetConsoleTextAttribute(hConsole, WHITE);
			break;
		}
		}
	}
	return 0;
}