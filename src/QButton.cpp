#include "QButton.h"

#include <Windows.h>

QButton::QButton(LPWSTR new_title_string)
{
	title_string = new_title_string;
}


QButton::~QButton()
{
}

int QButton::SetEventHandler(QButtonCallback q_callback)
{
	if (q_callback)
	{
		button_event_handler = q_callback;
		return 1;
	}
	return 0;
}

int QButton::SendEvent(QButtonEvent & qbe)
{
	return button_event_handler(qbe);
}

QButton & QButton::CreateButton(QFrame & parent)
{
	if (!hWindow)
	{
		hWindow = CreateWindow(L"BUTTON", title_string, WS_VISIBLE | WS_CHILD | WS_TABSTOP, position.GetX(), position.GetY(), size.GetX(), size.GetY(), parent.GetHWND(), NULL, NULL, (LPVOID)this);
		parent.Add(*this);
		SetWindowLong(hWindow, GWL_USERDATA, (LONG)this);
	}
	return *this;
}