#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <iomanip>
using namespace std;
unsigned short i_zero, j_zero;
void filling_array(unsigned short A[][4], unsigned short n);
void random_filling(unsigned short A[][4], unsigned short n);
void search_for_zero(unsigned short A[][4], unsigned short n);
bool end_of_the_game(unsigned short A[][4]);
void get_direction(unsigned short A[][4]);
void SetConsoleCursorPosition(short x_position, short y_position);
void screen(unsigned short A[][4], unsigned short n);
void SetConsoleWinSizePosition(int width = 0, int heigth = 0, short x_position = 0, short y_position = 0);
enum {
	clBlack, clNavy, clGreen, clTeal, clBrown,
	clPurple, clOlive, clGray, clSilver, clBlue,
	clLime, clCyan, clRed, clMagneta, clYellow,
	clWhite
};
void SetConsoleColorTextBackground(unsigned short Tex = clWhite, unsigned short Bg = clBlack);

////////////////////////////////////////////////////////////////////////
int main()
{
	SetConsoleWinSizePosition(15, 8, 400, 200);
	SetConsoleColorTextBackground(clYellow, clBlack);
	srand(time(NULL));
	const unsigned short n = 4;
	unsigned short A[n][n];
	int ch = 0;
	filling_array(A, n);
	do
	{
		random_filling(A, n);
		search_for_zero(A, n);
	} while (end_of_the_game(A));
	screen(A, n);
	do
	{
		get_direction(A);
		screen(A, n);
	} while (!end_of_the_game(A));
	system("cls");
	cout << endl << "You win!" << endl << "Game over!" << endl;
	_getch();
}
///////////////////////////////////////////////////////////////////

void filling_array(unsigned short A[][4], unsigned short n)
{
	int b = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = b++;
		}
	}
	A[n - 1][n - 1] = 0;
}
void random_filling(unsigned short A[][4], unsigned short n)
{
	int i1, j1, b;
	for (int i = 0; i < n; i++)
	{
		i1 = rand() % 4;
		for (int j = 0; j < n; j++)
		{
			j1 = rand() % 4;
			b = A[i][j];
			A[i][j] = A[i1][j1];
			A[i1][j1] = b;
		}
	}
}
void search_for_zero(unsigned short A[][4], unsigned short n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (A[i][j] == 0)
			{
				i_zero = i;
				j_zero = j;
				break;
			}
		}
	}
}
bool end_of_the_game(unsigned short A[][4])
{
	if (A[0][0] == 1 && A[0][1] == 2 && A[0][2] == 3 && A[0][3] == 4 && A[1][0] == 5 && A[1][1] == 6 && A[1][2] == 7 && A[1][3] == 8 && A[2][0] == 9 && A[2][1] == 10 && A[2][2] == 11 && A[2][3] == 12 && A[3][0] == 13 && A[3][1] == 14 && A[3][2] == 15 && A[3][3] == 0)
		return true;
	return false;
}
void get_direction(unsigned short A[][4])
{
	int move = (_getch()); // UP = 72, DOWN = 80, RIGHT = 77, LEFT = 75
	switch (move)
	{
	case 72:
	{
		if (i_zero >= 0 && i_zero <= 2)
		{
			A[i_zero][j_zero] = A[i_zero + 1][j_zero];
			i_zero++;
			A[i_zero][j_zero] = 0;
		}
		break;
	}
	case 80:
	{
		if (i_zero <= 3 && i_zero >= 1)
		{
			A[i_zero][j_zero] = A[i_zero - 1][j_zero];
			i_zero--;
			A[i_zero][j_zero] = 0;
		}
		break;
	}
	case 77:
	{
		if (j_zero <= 3 && j_zero >= 1)
		{
			A[i_zero][j_zero] = A[i_zero][j_zero - 1];
			j_zero--;
			A[i_zero][j_zero] = 0;
		}
		break;
	}
	case 75:
	{
		if (j_zero >= 0 && j_zero <= 2)
		{
			A[i_zero][j_zero] = A[i_zero][j_zero + 1];
			j_zero++;
			A[i_zero][j_zero] = 0;
		}
		break;
	}
	default:
	{
		get_direction(A);
	}
	}
}
void SetConsoleCursorPosition(short x_position, short y_position)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD _coordPosition = { x_position , y_position };
	SetConsoleCursorPosition(hConsole, _coordPosition);
}
void screen(unsigned short A[][4], unsigned short n)
{
	system("cls");
	for (int i = 0; i < n; i++)
	{
		//SetConsoleCursorPosition(23, i + 10);
		for (int j = 0; j < n; j++)
		{
			cout << setw(2) << A[i][j] << "  ";
		}
		cout << endl;
	}
}
void SetConsoleWinSizePosition(int width , int heigth, short x_position, short y_position)
{
	HWND hWnd = GetForegroundWindow();
	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetWindowPos(hWnd, NULL, x_position, y_position, 0, 0, NULL);
	SMALL_RECT windowSize;
	windowSize.Bottom = heigth;
	windowSize.Left = 0;
	windowSize.Right = width;
	windowSize.Top = 0;
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	COORD bufferSize = { width + 1 , heigth + 1 };
	SetConsoleScreenBufferSize(wHnd, bufferSize);
}
void SetConsoleColorTextBackground(unsigned short Tex, unsigned short Bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Bg = Bg << 4 | Tex;
	SetConsoleTextAttribute(hConsole, Bg);
}