#pragma once

#include "QGuiObject.h"
#include "QButtonEvent.h"
#include "QFrame.h"

typedef int(*QButtonCallback)(QButtonEvent);

class QButton : public QGuiObject
{
	public:
		QButton(LPWSTR new_title_string = L"");
		int SetEventHandler(QButtonCallback);
		QButton & CreateButton(QFrame & parent);
		int SendEvent(QButtonEvent & qbe);
		~QButton();
	private:
		QButtonCallback button_event_handler;
};

