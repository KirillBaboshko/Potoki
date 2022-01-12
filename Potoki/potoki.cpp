#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<Windows.h>
#define MAX_PATH 260
#define NUM_COLS 18
#define NUM_ROWS 24

using namespace std;
//void main()
//{
//	setlocale(0, "rus");
//	char path[MAX_PATH];
//	cout << "Vvdite puti k falu";
//	cin.getline(path, MAX_PATH);
//	int counter = 0, i = 0, j = 0;
//	char text[NUM_COLS];
//	ifstream input(path, ios::in | ios::binary);
//	if (!input)
//	{
//		cout << "Ne mogem otkrit fale" << endl;
//		return;
//	}
//	cout.setf(ios::uppercase);
//	while (!input.eof())
//	{
//		for ( i = 0; (i < NUM_COLS && !input.eof()); i++)
//			input.get(text[i]);
//		if (i < NUM_COLS)
//			i--;
//		for (j = 0; j < i; j++)
//			if ((unsigned)text[j] < 0x10)
//				cout << setw(2) << 0 << hex << (unsigned)text[j];
//			else
//				cout << setw(3) << 0 << hex << (unsigned)text[j];
//		for (; j < NUM_COLS; j++)
//			cout << "     ";
//		cout << "\t";
//		for (j = 0; j < i; j++)
//			if (text[j] > 31 && text[j] <= 255)
//				cout << text[j];
//			else
//				cout << ".";
//		cout << "\n";
//		if (++counter == NUM_COLS)
//		{
//			counter = 0;
//			cout << "Press any key to continur..." << flush;
//			_getch();
//			cout << "\n";
//		}
//	}
//	input.close();
//}
void main()
{
	char Answer;
	const int MassageCount = 8;
	int i, j;
	enum{CHOICE=3,INPUT_FILENAME, INPUT_DIMENSION,INPUT_ELEMENTS,FILE_ERROR};
	char Msg[MassageCount][50] =
	{
		"1.Вывести данные из текстового файла\n",
		"2.Записать данные в текстовый файл\n",
		"3.Выход из программы\n",
		"\nВаш выбор: ",
		"Введите имя обрабатываемого файла\n",
		"Введите размерность матрицы:\n",
		"Введите элементы матрицы:\n",
		"Невозможно открыть файл\n"
	};
	for(i=0;i< MassageCount;i++)
		CharToOemA(Msg[i], Msg[i]);
	do 
	{
		for (int i = 0; i < 4; i++)
			cout << Msg[i];
		cin >> Answer;
	} while (Answer < '1' || Answer > '3');
	if (Answer == '3')
	{
		return;
	}
	char FileName[80];
	int M, N;
	int num;
	cout << "\n" << Msg[INPUT_FILENAME];
	cin >> FileName;
	if (Answer == '1')
	{
		ifstream inF(FileName, ios::in | ios::_Nocreate);
		if (!inF)
		{
			cout << endl << Msg[FILE_ERROR];
			return;
		}
		inF >> M;
		inF >> N;
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
			{
				inF >> num;
				cout << setw(6) << num;
			}
			cout << endl;
		}
		inF.close();
	}
	if (Answer == '2')
	{
		ofstream outF(FileName, ios::out);
		if (!outF)
		{
			cout << "\n" << Msg[FILE_ERROR];
			return;
		}
		cout << Msg[INPUT_DIMENSION];
		cout << "M: ";
		cin >> M;
		cout << "N: ";
		cin >> N;
		outF << M << ' ' << N << "\n";
		cout << Msg[INPUT_ELEMENTS];
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
			{
				cout << "A[" << i << "][" << j << "] =";
				cin >> num;
				outF << num << " ";
			}
			outF << "\n";
		}
		outF.close();
	}
}