#pragma once

#include "QGuiObject.h"
#include <vector>
using namespace std;

class QFrame : public QGuiObject
{
	public:
		friend class QGuiObject;
		QFrame();
		~QFrame();
		int Add(QGuiObject & qgo);
		QGuiObject * FindChildByHWND(HWND find_hwnd);
	protected:
		int RegisterChild(QGuiObject * p_object);
		vector<QGuiObject *> v_children;
};

