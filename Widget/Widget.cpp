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



#include "Widget.h"



Widget::Widget(int x, int y, int width, int height, bool editFlag) :_width(width), _height(height), _editFlag(editFlag), _lightFlag(false), color(0)
{
	_location.X = x;
	_location.Y = y;
}

Widget::Widget(): _width(10), _height(5),_editFlag(false),_lightFlag(false), color(0)
{
	_location.X = 15;
	_location.Y = 15;
}

const int Widget::GetX()
{
	return _location.X;
}

const int Widget::GetY()
{
	return _location.Y;
}

const COORD Widget::GetCoord()
{
	return _location;
}
const int Widget::GetWidth()
{
	return _width;
}

const int Widget::GetHeight()
{
	return _height;
}

void Widget::EnableEdit(bool flag)
{
	if (flag)
	{

	}
	_editFlag = flag;
}

void Widget::SetLightFlag(bool flag)
{
	_lightFlag = flag;
}

bool Widget::GetLightFlag()
{
	return _lightFlag;
}

bool Widget::GetEditFlag()
{
	return _editFlag;
}

void Widget::SetColor(DWORD c)
{
	color = c;
}
DWORD Widget::GetColor()
{
	return color;
}


Widget::~Widget()
{
}
