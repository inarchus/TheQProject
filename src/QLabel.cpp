#include "QLabel.h"

QLabel::QLabel(QFrame & parent, LPWSTR loc_label_string)
{
	parent_frame = &parent;
}


QLabel::~QLabel()
{
}

QLabel & QLabel::CreateLabel(LPWSTR lpString)
{
	hWindow = CreateWindow(L"STATIC", lpString, WS_CHILD | WS_VISIBLE, position.GetX(), position.GetY(), size.GetX(), size.GetY(), parent_frame->GetHWND() , NULL, NULL, NULL);
	SetWindowLong(hWindow, GWL_USERDATA, (LONG)this);
	return *this;
}