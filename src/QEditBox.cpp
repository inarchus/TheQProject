#include "QEditBox.h"
#include "QFrame.h"

#include <CommCtrl.h>
#include <Richedit.h>

QEditBox::QEditBox()
: style(DefaultStyle)
{
}


QEditBox::~QEditBox()
{
}

QEditBox & QEditBox::CreateEditBox(QFrame & parent, LPWSTR init_text)
{
	if (!hWindow)
	{
		LoadLibrary(TEXT("Msftedit.dll"));
		hWindow = CreateWindowEx(0, MSFTEDIT_CLASS, init_text, WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER | style, position.GetX(), position.GetY(), size.GetX(), size.GetY(), parent.GetHWND(), NULL, NULL, NULL);
		SetWindowLong(hWindow, GWL_USERDATA, (LONG)this);
	}
	return *this;
}

LPCWSTR QEditBox::GetText() const
{
	return GetTitle();
}

int QEditBox::SetText(LPWSTR set_text)
{
	SetTitle(set_text);
	return 1;
}

QEditBox::QEditBoxStyle QEditBox::SetStyle(QEditBoxStyle new_style)
{
	style = new_style;
	SetWindowLong(hWindow, GWL_STYLE, WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER | style);
	return style;
}

QEditBox::QEditBoxStyle QEditBox::GetStyle() const
{
	return style;
}
