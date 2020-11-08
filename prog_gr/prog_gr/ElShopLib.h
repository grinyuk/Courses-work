#pragma once
#ifndef ElShopLib
#define ElShopLib
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <iomanip> 
#include <Windows.h>
using namespace std;


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int num_of_last_row()//גסו ןנאצ‏÷ ³הואכüםמ
{
	FILE *fb = fopen("Base.bin", "rb");
	int last_num;
	fseek(fb, -60, SEEK_END);
	fread(&last_num, sizeof(int), 1, fb);
	fclose(fb);
	return last_num;
}

void opening_error(FILE *file)
{
	if (file == NULL)
	{
		SetConsoleTextAttribute(hConsole, 12);
		cout << "Can`t open file." << endl;
		SetConsoleTextAttribute(hConsole, 15);
		exit(1);
	}
}


#endif