#include <conio.h>
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoXY(int x, int y);
void gotoXY(int x, int y, string text);
void Draw(int style, int col, int row, int length, int amount, bool filled);

int main(int)
{
	//  Draw routine
	//  first number = 1 for single line, 2 for a double lines
	//	second number = column's across
	//  third number = row's down
	//	fourth number = box total length
	//  fifth number = box total height
	//  sixth number = 0 for not filled, 1 for filled 
	
	
	Draw(1, 28, 6, 45, 3, 1);  
	gotoXY(30, 7, "Hi, my name is label and i love Unicorns!");

	CONSOLE_CURSOR_INFO cci = { 100, FALSE };
	SetConsoleCursorInfo(console, &cci);
	
	gotoXY(25, 14, "                                ");
	getchar();

}

void gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void gotoXY(int x, int y, string text)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
	cout << text;
}

void Draw(int style, int col, int row, int length, int amount, bool fill)
{
	int a;
	style = (style - 1) * 6;
	char box[12];

	box[0] = '\xDA';//  ┌
	box[1] = '\xBF';//  ┐
	box[2] = '\xC0';//  └
	box[3] = '\xD9';//  ┘
	box[4] = '\xB3';//  │ 
	box[5] = '\xC4';//  ─
	box[6] = '\xC9';//  ╔ 
	box[7] = '\xBB';//  ╗
	box[8] = '\xC8';//  ╚
	box[9] = '\xBC';//  ╝
	box[10] = '\xBA';// ║
	box[11] = '\xCD';// ═


	char tl, tr, bl, br, side, edge, shadow;
	tl = box[style];
	tr = box[style + 1];
	bl = box[style + 2];
	br = box[style + 3];
	side = box[style + 4];
	edge = box[style + 5];
	
	string Line(length - 2, edge);
	string Fill(length - 2, ' ');

	gotoXY(col, row);
	cout << tl << Line << tr;
	for (a = 1; a <amount - 1; a++)
	{
		gotoXY(col, row + a);
		cout << side;
		if (fill)
			cout << Fill;
		else
			gotoXY(col + length - 1, row + a);
		cout << side;
	}
	gotoXY(col, (amount + row) - 1);
	cout << bl << Line << br;

	DWORD wAttr = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
	SetConsoleTextAttribute(console, wAttr);

	CONSOLE_SCREEN_BUFFER_INFO cbi;

	GetConsoleScreenBufferInfo(console, &cbi);

	DWORD wAttr2 = cbi.wAttributes & ~(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY) ;
	SetConsoleTextAttribute(console, wAttr2);
	
}

	

	