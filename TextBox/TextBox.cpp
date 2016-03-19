/*
******************************************************************
******************************************************************
******************************************************************
*******													   *******
*******													   *******
*******			Methods in software engineering			   *******
*******			     Writen By - Golan Sabo				   *******
*******				   Date - 13/3/2016					   *******
*******					   *******						   *******
*******													   *******
******************************************************************
******************************************************************
******************************************************************
*/



#include "TextBox.h"


TextBox::TextBox() : _frame('@'), Widget() { ConsoleSingleton::GetInstance()->Sign(this); }

TextBox::TextBox(int x, int y, int width, int height, char frame) : _frame(frame), Widget(x, y, width, height, true) { ConsoleSingleton::GetInstance()->Sign(this); }

TextBox::TextBox(int x, int y, int width, int height) : _frame('@'), Widget(x, y, width, height, true) { ConsoleSingleton::GetInstance()->Sign(this); }

void TextBox::Draw(COORD CursorPosition, const HANDLE& console)
{
	CursorPosition = GetCoord();
	for (int i = 0; i < GetHeight(); ++i)
	{
		SetConsoleCursorPosition(console, CursorPosition);
		CursorPosition.Y += 1;
		for (int j = 0; j < GetWidth(); ++j)
		{
			if (i == 0 || i == GetHeight() - 1)
			{
				std::cout << _frame;
			}
			else if (j == 0 || j == GetWidth() - 1)
			{
				std::cout << _frame;
			}
			else
			{
				std::cout << " ";
			}
		}
	}
}

int TextBox::MouseEvent(const MOUSE_EVENT_RECORD& mer)
{
	if (CheckPosition(mer.dwMousePosition))
		return MOVE_CURSOR;
	return NONE;
}

COORD TextBox::GetDefaultPosition() const
{
	COORD defaultPosition;
	defaultPosition.X = GetX() + 1;
	defaultPosition.Y = GetY() + 1;
	return defaultPosition;
}

bool TextBox::CheckPosition(COORD clickedPosition) const
{
	COORD defaultPosition = GetDefaultPosition();
	int x = defaultPosition.X + GetWidth() - 1;
	int y = defaultPosition.Y + GetHeight() - 2;
	if (clickedPosition.X >= x || clickedPosition.X < defaultPosition.X)
		return false;
	if (clickedPosition.Y >= y || clickedPosition.Y < defaultPosition.Y)
		return false;

	return true;
}

int TextBox::KeyboardEvent(const KEY_EVENT_RECORD& ker, COORD& currentLocation)
{
	//if (!currentWidgetInFocus->GetEditFlag())
	//	return;

	if (ker.bKeyDown)
	{
		if (ker.wVirtualKeyCode == VK_UP || ker.wVirtualKeyCode == 104)
		{
			currentLocation.Y -= 1;
			if (CheckPosition(currentLocation))
				return MOVE_CURSOR;
			return NONE;
		}
		else if (ker.wVirtualKeyCode == VK_DOWN || ker.wVirtualKeyCode == 98)
		{
			currentLocation.Y += 1;
			if (CheckPosition(currentLocation))
				return MOVE_CURSOR;
			return NONE;
		}
		else if (ker.wVirtualKeyCode == VK_LEFT || ker.wVirtualKeyCode == 52)
		{
			currentLocation.X -= 1;
			if (CheckPosition(currentLocation))
				return MOVE_CURSOR;
			return NONE;
		}
		else if (ker.wVirtualKeyCode == VK_RIGHT || ker.wVirtualKeyCode == 54)
		{
			currentLocation.X += 1;
			if (CheckPosition(currentLocation))
				return MOVE_CURSOR;
			return NONE;
		}
		else if (ker.wVirtualKeyCode == VK_RETURN)
		{
			currentLocation.Y += 1;
			currentLocation.X = GetX() + 1;
			if (CheckPosition(currentLocation))
				return MOVE_CURSOR;
			return NONE;
		}
		else if (ker.wVirtualKeyCode == VK_TAB)
		{
			currentLocation.X += 4;
			if (CheckPosition(currentLocation))
				return MOVE_CURSOR;
			return NONE;
		}
		else if (ker.wVirtualKeyCode == VK_BACK)
		{
			currentLocation.X -= 1;
			if (CheckPosition(currentLocation))
				return MOVE_CURSOR;
			return NONE;
		}
		else
		{
			currentLocation.X += 1;
			if (CheckPosition(currentLocation))
				return PRINT_KEY;
			return NONE;
		}

	}
}
TextBox::~TextBox() {}



