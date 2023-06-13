#pragma once
#include <vector>
#include "PaintDevice.h"
using namespace std;
enum class Moves {left, right};
struct Point
{
	int x;
	int y;
	inline Point(int x = 0, int y = 0) : x(x), y(y) { };
};
class Figure
{
protected:
	Point m_Position;
	double m_TimeFromLastUpdatec = 0;
	double m_TimeForUpdate = 500; //полсекунды
	vector<vector<Point>> m_Body;
	size_t m_CurrentRotate = 0;
	Point m_PositionBackup;
	size_t m_CurrentRotateBackup = 0;
public:
	inline Figure(Point position) {
		m_Position.x = position.x;
		m_Position.y = position.y;
	};
	void update(double dt);
	inline void render(PaintDevice& paintDevice) {
		for (const Point& point: m_Body[m_CurrentRotate])
		{
			Vector2 v(point.x + m_Position.x,
				point.y + m_Position.y);
			paintDevice.set_char(v, 0x25D8);
		}
	}
	void move_right() {
		m_Position.x++;
	};
	void move_left() {
		m_Position.x--;
	};
	const vector<Point>get_body() const { return m_Body[m_CurrentRotate]; };
	Point get_position() const { return m_Position; };
	void set_position(Point position) { m_Position = position;  };
	void backup() { 
		m_PositionBackup = m_Position; 
		m_CurrentRotateBackup = m_CurrentRotate;
	};
	void restore() { 
		m_Position = m_PositionBackup; 
		m_CurrentRotate = m_CurrentRotateBackup;
	};
	void boost() { m_TimeForUpdate = 50; };
	void rotate() {
		++m_CurrentRotate;
		if (m_CurrentRotate >= m_Body.size())
			m_CurrentRotate = 0;
	};
};

