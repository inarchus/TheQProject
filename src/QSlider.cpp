#include "QSlider.h"
#include "commctrl.h"


QSlider::QSlider(QFrame & q_ref_parent, QSliderType local_qst)
: p_parent(&q_ref_parent), qst_type(local_qst)
{
	
}

QSlider & QSlider::CreateSlider()
{
	if (qst_type == SLIDER)
	{
		hWindow = CreateWindow(TRACKBAR_CLASS, L"", WS_CHILD | WS_VISIBLE | TBS_AUTOTICKS | TBS_TOOLTIPS, position.GetX(), position.GetY(), size.GetX(), size.GetY(), p_parent->GetHWND(), NULL, NULL, NULL);
		SendMessage(hWindow, TBM_SETRANGE, TRUE, 0x000F0000);
	}
	else if (qst_type == RANGE_SLIDER)
	{
		hWindow = CreateWindow(TRACKBAR_CLASS, L"", WS_CHILD | WS_VISIBLE | TBS_ENABLESELRANGE | TBS_NOTICKS, position.GetX(), position.GetY(), size.GetX(), size.GetY(), p_parent->GetHWND(), NULL, NULL, NULL);
		SendMessage(hWindow, TBM_SETRANGE, TRUE, 0xFFFF0000);
		//SendMessage(hWindow, TBM_SETSEL, TRUE, 0x0C000300);
	}
	SetWindowLong(hWindow, GWL_USERDATA, (LONG)this);

	return *this;
}

QSlider::~QSlider()
{
}
