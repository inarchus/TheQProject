#pragma once

#include "QGuiObject.h"
#include "QFrame.h"
#include "QEditBoxEvent.h"

typedef int(*QEditBoxCallback)(QEditBoxEvent);



class QEditBox : public QGuiObject
{
	public:
		typedef enum QEditBoxStyle{
			Multiline = ES_MULTILINE, HorizontalScrolling = ES_AUTOHSCROLL, VerticalScrolling = ES_AUTOVSCROLL,
			Continuous = ES_CONTINUOUS, RightJustify = ES_RIGHT, LeftJustify = ES_LEFT, CenterJustify = ES_CENTER,
			NumericalOnly = ES_NUMBER, LowercaseOnly = ES_LOWERCASE, UppercaseOnly = ES_UPPERCASE, PasswordType = ES_PASSWORD,
			ReadOnly = ES_READONLY, WantsReturn = ES_WANTRETURN, DefaultStyle = ES_MULTILINE | ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_CONTINUOUS
		}; // , Sunken = ES_SUNKEN


		QEditBox();

		QEditBox & CreateEditBox(QFrame & parent, LPWSTR init_text = L"");

		LPCWSTR GetText() const;
		int SetText(LPWSTR set_text);

		QEditBoxStyle SetStyle(QEditBoxStyle new_style);
		QEditBoxStyle GetStyle() const;

		~QEditBox();
	protected:
		QEditBoxStyle style;
};

