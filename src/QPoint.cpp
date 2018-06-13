#include "QPoint.h"


QPoint::QPoint()
: n_x(0), n_y(0)
{
}

QPoint::QPoint(int x, int y)
: n_x(x), n_y(y)
{
}


QPoint::~QPoint()
{
}

QPoint & QPoint::Set(int x, int y)
{
	n_x = x;
	n_y = y;
	return *this;
}

QPoint & QPoint::SetX(int x)
{
	n_x = x;
	return *this;
}

QPoint & QPoint::SetY(int y)
{
	n_y = y;
	return *this;
}


int QPoint::GetX() const
{
	return n_x;
}

int QPoint::GetY() const
{
	return n_y;
}

QPoint & QPoint::operator = (const QPoint & cp)
{
	n_x = cp.n_x;
	n_y = cp.n_y;
	return *this;
}