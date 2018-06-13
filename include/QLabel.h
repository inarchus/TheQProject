#pragma once

#include "QGuiObject.h"
#include "QFrame.h"

class QLabel : public QGuiObject
{
	public:
		QLabel(QFrame & parent, LPWSTR loc_label_string = L"");
		~QLabel();
		QLabel & CreateLabel(LPWSTR lpString);
	private:
		QFrame * parent_frame;
		LPWSTR label_string;
};

