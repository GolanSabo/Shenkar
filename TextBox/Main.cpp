#include "TextBox.h"
#include "../ConsoleSingleton/ConsoleSingleton.h"
int main(int argc, char* argv[])
{
	TextBox t(10, 10, 10, 10, '*');
	//t.EnableEdit(true);
	TextBox t1(21, 10, 10, 10, '*');
	t1.EnableEdit(false);
	TextBox t2(32, 10, 10, 10, '*');
//	ConsoleSingleton::GetInstance()->Listen();
	getchar();
	return 0;
}
