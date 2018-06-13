#include "QFrame.h"


QFrame::QFrame()
{
}


QFrame::~QFrame()
{
}

int QFrame::Add(QGuiObject & qgo)
{
	if (!FindChildByHWND(qgo.GetHWND()))
	{
		v_children.push_back(&qgo);
	}
	return 1;
}

QGuiObject * QFrame::FindChildByHWND(HWND find_hwnd)
{
	for (unsigned int i = 0; i < v_children.size(); i++)
	{
		if (v_children[i]->GetHWND() == find_hwnd)
		{
			return v_children[i];
		}
	}
	return 0L;
}