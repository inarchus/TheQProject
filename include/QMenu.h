#pragma once

#include"QFrames.h"

class QMenu
{
	public:
		QMenu();
		QMenu(QFrame & q_frame);
		~QMenu();
		QMenu & CreateMenu(LPWSTR menu_name);
	private:
		HMENU hMenu;	
};

