#pragma once
#include "PaintDevice.h"
#include "Figure.h"
#include <vector>
using namespace std;
class GameField
{
private:
	size_t m_Width;
	size_t m_Height;
	vector<vector<wchar_t>> m_Field;
public:
	void resize(size_t width, size_t height) {
		m_Height = height;
		m_Width = width;
		m_Field = vector<vector<wchar_t>>(m_Height - 2,
			vector<wchar_t>(m_Width - 2, 0x0387));
	}
	void render(PaintDevice& paintDevice);
	bool has_collision(const Figure figure);
	void merge(const Figure& figure) {
		Point position = figure.get_position();
		for (const Point& point : figure.get_body()) {
			m_Field[point.y + position.y - 1][point.x + position.x - 1] = 0x25D8;
		}
		for (size_t i = 0; i < m_Field.size(); i++)
		{
			bool isfool = true;
			for (size_t j = 0; j < m_Field[i].size(); j++)
			{
				isfool = isfool && m_Field[i][j] != 0x0387;
			}
			if (isfool)
			{
				for (size_t j = i; j >  0; j--)
				{
					m_Field[j] = m_Field[j - 1];
				}
				m_Field[0] = vector <wchar_t>(m_Width - 2, 0x0387);
			}
		}
	};
};

