#pragma once

#include "QGuiObject.h"
#include "QFrame.h"

struct QListBoxSelection 
{
	QListBoxSelection(LPWSTR set_string = L"", int new_selection_code = -1) 
		: selection_code(new_selection_code), selection_string(set_string)
	{	}

	LPWSTR selection_string;
	int selection_code;
};

class QListBox : public QGuiObject
{
	public:
		QListBox(QFrame & parent);
		QListBox & CreateListBox();

		QListBoxSelection & GetSelectedElement() const;

		int AddItemAtEnd(QListBoxSelection & new_element);
		int AddItemAtIndex(int index);
		int RemoveItemByIndex(int index);
		int RemoveItemByName(LPWSTR name);

		int AddItemVector(vector<QListBoxSelection *> & elements);

		int EmptySelections();

		~QListBox();
	private:
		int n_elements;
		QFrame * parent_frame;
		vector<QListBoxSelection *> selections;
};

