#include "QGuiObject.h"

int QGuiObject::MAX_TITLE_LENGTH = 1024;

QGuiObject::QGuiObject()
: hWindow(NULL), position(100, 100), size(50,50)
{
}


QGuiObject::~QGuiObject()
{
}

LPCWSTR QGuiObject::GetTitle() const
{
	LPWSTR window_text_string = new WCHAR[MAX_TITLE_LENGTH];
	GetWindowText(hWindow, window_text_string, MAX_TITLE_LENGTH);
	return window_text_string;
}

LPCWSTR QGuiObject::SetTitle(LPCWSTR new_title)
{
	if (new_title)
	{
		if (title_string)
		{
			delete[] title_string;
		}
		title_string = new WCHAR[lstrlenW(new_title) + 1];
		wcscpy(title_string, new_title);
		if (hWindow)
		{
			SetWindowText(hWindow, new_title);
		}		
	}
	return title_string;
}

HWND QGuiObject::GetHWND() const
{
	return hWindow;
}

QPoint QGuiObject::GetPosition() const
{
	return position;
}

QPoint QGuiObject::GetSize() const
{
	return size;
}

QPoint QGuiObject::SetPosition(const QPoint & p)
{
	position = p;
	SetWindowPos(hWindow, HWND_TOP, position.GetX(), position.GetY(), 0, 0, SWP_NOSIZE);
	return position;
}

QPoint QGuiObject::SetSize(const QPoint & p)
{
	size = p;
	SetWindowPos(hWindow, HWND_TOP, 0, 0, size.GetX(), size.GetY(), SWP_NOMOVE);	
	return size;
}

void QGuiObject::SetPositionAndSize(int p_x, int p_y, int s_x, int s_y)
{
	position = QPoint(p_x, p_y);
	size = QPoint(s_x, s_y);
	SetWindowPos(hWindow, HWND_TOP, position.GetX(), position.GetY(), size.GetX(), size.GetY(), SWP_NOMOVE);
}

bool QGuiObject::SetEnabled(bool t_or_f)
{
	if (hWindow)
	{
		return EnableWindow(hWindow, t_or_f);
	}
	return false;
}