#pragma once

class QPoint
{
	public:
		QPoint();
		QPoint(int x, int y);
		~QPoint();
		QPoint & Set(int x, int y);
		QPoint & SetX(int x);
		QPoint & SetY(int y);
		int GetX() const;
		int GetY() const;

		QPoint & operator = (const QPoint & cp);
	private:
		int n_x;
		int n_y;
};

