#include "QProgressBar.h"
#include "commctrl.h"

QProgressBar::QProgressBar(QFrame & parent, QProgressBarType qbt)
: f_progress(0)
{
	q_parent = &parent;
}

QProgressBar & QProgressBar::CreateProgressBar()
{
	hWindow = CreateWindow(PROGRESS_CLASS, L"", WS_CHILD | WS_VISIBLE, position.GetX(), position.GetY(), size.GetX(), size.GetY(), q_parent->GetHWND(), NULL, NULL, NULL);
	SetWindowLong(hWindow, GWL_USERDATA, (LONG)this);
	SendMessage(hWindow, PBM_SETRANGE, NULL, 0xFFFF0000);
	return *this;
}

QProgressBar::QProgressBarType QProgressBar::SetType(QProgressBarType qbt)
{
	qbt_type = qbt;
	return qbt_type;
}

QProgressBar::QProgressBarType QProgressBar::GetType() const
{
	return qbt_type;
}

double QProgressBar::GetProgressPercent() const
{
	return f_progress;
}

double QProgressBar::SetProgressPercent(double new_progress)
{
	if (new_progress >= 0.0f && new_progress <= 100.0f)
	{
		if (new_progress > f_progress)
		{
			MessageBox(NULL, L"Trying to Resize", L"Trying to Resize", MB_OK);
			SendMessage(hWindow, PBM_DELTAPOS, WPARAM((double(0xFFFF) * (new_progress - f_progress) / 100.0f)), NULL);
		}
		else
		{
			MessageBox(NULL, L"Trying to Resize", L"Trying to Resize", MB_OK);
			SendMessage(hWindow, PBM_SETPOS, WPARAM((double(0xFFFF) * new_progress)/100.0f), NULL);
		}
		f_progress = new_progress;
	}
	else if (new_progress > 100.0f)
	{
		f_progress = 100.0f;
		SendMessage(hWindow, PBM_SETPOS, WPARAM(0xFFFF) , NULL);
	}
	else if (new_progress < 0.0f)
	{
		f_progress = 0.0f;
		SendMessage(hWindow, PBM_SETPOS, WPARAM(0x0000), NULL);
	}
	return f_progress;
}

QProgressBar::~QProgressBar()
{

}