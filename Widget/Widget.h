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



#pragma once
#include <string>
#include <iostream>
#include <windows.h>
#include <stdio.h>

class Widget
{
	COORD _location;
	int _width, _height;
	bool _editFlag;
	bool _lightFlag;
	DWORD color;

protected:
	void SetLightFlag(bool flag);
public:
	//constructors
	Widget(int x, int y, int width, int height, bool editFlag);
	Widget();

	//Getters
	const int GetX();
	const int GetY();
	const int GetWidth();
	const int GetHeight();
	const COORD GetCoord();
	bool GetEditFlag();
	bool GetLightFlag();
	DWORD GetColor();
	//Setters
	void SetColor(DWORD c);

	//Functionalities
	virtual void Draw(COORD CursorPosition, HANDLE console) = 0;
	virtual int MouseEvent(MOUSE_EVENT_RECORD mer) = 0;
	virtual int KeyboardEvent(KEY_EVENT_RECORD ker, COORD& currentLocation) = 0;
	virtual bool CheckPosition(COORD clickedPosition) = 0;
	void EnableEdit(bool flag);
	

	~Widget();
};

