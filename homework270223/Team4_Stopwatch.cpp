#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <Windows.h>

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void clearScreen()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
int main()
{
	resizeConsole(550, 300);
	printf("Press any key to start\n");
	printf("00 : 00\n");
	char x = _getch();
	int countvar = 1;
	//int k = 0, f = 0;
	int arr[100];
	int idx = 0;
	int brr[100];
	int check = 0;
	for (int i = 0; i < 60; i++)
			{
				for (int j = 0; j <= 60; j++)
				{
					system("cls");
					clearScreen();
					printf("%02d : %02d\n", i, j);
					printf("\nSave result:\n");
					for (int f = 0; f < idx; f++)
					{
						printf("%02d : %02d\n", arr[f], brr[f]);
					}

					printf("\n\nSpace : Pause\t\tENTER : Save\t\tESC : Exit\n");
					Sleep(1000);

					if (GetAsyncKeyState(VK_SPACE))
					{
						countvar++;
					}
					if (countvar % 2 == 0)
					{
						j--;
						char a = _getch();
					}
					if (GetAsyncKeyState(VK_ESCAPE))
					{
						goto loi;
					}
					if (GetAsyncKeyState(VK_RETURN))
					{
						arr[idx] = i;
						brr[idx] = j;
						idx++;
					}

				}
			}
	loi:
	return 0;
}
