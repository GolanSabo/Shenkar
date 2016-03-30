#include <conio.h>
#include <iostream>
#include <string>
#include <windows.h>
#include "../ConsoleSingleton/ConsoleSingleton.h"
#include "Label.h"


int main(int)
{
	
	Label* lab = new Label(28, 6, "Hi, my name is label and i love Unicorns!" );
	ConsoleSingleton::GetInstance()->Sign(lab);
	ConsoleSingleton::GetInstance()->Listen();
	delete lab;
	return 0;
}
