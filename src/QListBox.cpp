#include "QListBox.h"


QListBox::QListBox(QFrame & parent)
{
	parent_frame = &parent;
}

QListBox::~QListBox()
{
}

QListBox & QListBox::CreateListBox()
{
	hWindow = CreateWindow(L"LISTBOX", NULL, WS_CHILD | WS_VISIBLE, position.GetX(), position.GetY(), size.GetX(), size.GetY(), parent_frame->GetHWND(), NULL, NULL, NULL);
	SetWindowLong(hWindow, GWL_USERDATA, (LONG)this);
	return *this;
}

QListBoxSelection & QListBox::GetSelectedElement() const
{
	return *(new QListBoxSelection());
}

int QListBox::AddItemAtEnd(QListBoxSelection & new_element)
{
	SendMessage(hWindow, LB_ADDSTRING, NULL, (LPARAM)new_element.selection_string);
	selections.push_back(&new_element);
	return 0;
}

int QListBox::AddItemAtIndex(int index)
{
	return 0;
}

int QListBox::RemoveItemByIndex(int index)
{
	return 0;
}

int QListBox::RemoveItemByName(LPWSTR name)
{
	return 0;
}

int QListBox::AddItemVector(vector<QListBoxSelection *> & elements)
{
	return 0;
}

int QListBox::EmptySelections()
{
	return 0;
}