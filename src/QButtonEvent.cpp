#include "QButtonEvent.h"


QButtonEvent::QButtonEvent(QButtonEventType qet)
: q_button_event(qet)
{
}


QButtonEvent::~QButtonEvent()
{
}

QButtonEvent::QButtonEventType QButtonEvent::GetAction() const
{
	return q_button_event;
}

QButtonEvent::QButtonEventType QButtonEvent::SetAction(QButtonEventType qet)
{
	q_button_event = qet;
	return q_button_event;
}
