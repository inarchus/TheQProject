#pragma once

class QEvent
{
	public:
		typedef enum QEventType { QGeneralEventType, QKeyEventType, QButtonEventType, QMouseEventType } QEventType;

		QEvent();
		QEventType GetType() const;
		QEventType SetType(QEventType qet);
		~QEvent();
		
	private:
		QEventType q_event_type;
};

