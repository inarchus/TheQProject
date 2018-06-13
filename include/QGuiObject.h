#pragma once

#include <Windows.h>

#include "QPoint.h"

class QGuiObject
{
	public:
		QGuiObject();
		~QGuiObject();
		LPCWSTR GetTitle() const;
		LPCWSTR SetTitle(LPCWSTR new_title);
		HWND GetHWND() const;
		
		void SetPositionAndSize(int p_x, int p_y, int s_x, int s_y);

		QPoint GetPosition() const;
		QPoint GetSize() const;
		QPoint SetPosition(const QPoint & p);
		QPoint SetSize(const QPoint & p) ;

		bool SetEnabled(bool t_or_f);


	protected:
		LPWSTR title_string;
		HWND hWindow;
		static int MAX_TITLE_LENGTH;

		QPoint position;
		QPoint size;
};

