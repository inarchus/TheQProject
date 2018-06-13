#pragma once

#include "QFrames.h"

class QProgressBar : public QGuiObject
{
	public:
		enum QProgressBarType {PROGRESS, SCROLLING};
		
		QProgressBar(QFrame & parent, QProgressBarType qbt = PROGRESS);
		QProgressBar & CreateProgressBar();
		QProgressBarType SetType(QProgressBarType qbt);
		QProgressBarType GetType() const;
		double GetProgressPercent() const;
		double SetProgressPercent(double new_progress);
		~QProgressBar();
	private:
		QProgressBarType qbt_type;
		QFrame * q_parent;
		double f_progress;
};