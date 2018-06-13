#pragma once

#include "QEvent.h"

class QButton;

class QButtonEvent : public QEvent
{
	public:
		enum QButtonEventType{ QButtonDown, QButtonClick };
		QButtonEvent(QButtonEventType qet = QButtonClick);
		QButtonEventType GetAction() const;
		QButtonEventType SetAction(QButtonEventType qet);
		~QButtonEvent();
	private:
		QButtonEventType q_button_event;
		QButton * source;
};

