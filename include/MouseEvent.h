#pragma once

#include "QEvent.h"

enum MouseEventType {MouseClicked, MouseDown, RightMouseClicked, RightMouseDown, MouseWheelScroll, MouseWheelDown, MouseWheelClicked};

class QMouseEvent : public QEvent
{
	public:
		QMouseEvent();
		QMouseEvent(MouseEventType met);
		MouseEventType GetEventType() const;

		~QMouseEvent();
	private:
		MouseEventType event_type;
};

