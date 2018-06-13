#pragma once
#include "QGuiObject.h"
#include "QFrame.h"

class QSlider : public QGuiObject
{
	public:
		typedef enum QSliderType{SLIDER, RANGE_SLIDER};

		QSlider(QFrame & q_ref_parent, QSliderType local_qst = SLIDER);
		QSlider & CreateSlider();
		~QSlider();
	private:
		QFrame * p_parent;
		QSliderType qst_type;
};

