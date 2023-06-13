#pragma once
#include "Engine.h"
#include "Figure.h"
#include "IBlock.h"
#include "GameField.h"
class Tetris:
	public Engine
{
private:
	GameField m_GameField;
	const size_t m_Width = 14;
	const size_t m_Height = 26;
	Figure* m_Figure;
	bool m_End = false;
public:
	Tetris();
	inline bool end() const override { return m_End; };
	inline void on_button_press(const int button) override { 
		m_Figure->backup();
		switch (button)
		{
		case VK_LEFT:
				m_Figure->move_left();
			break;
		case VK_RIGHT:
			m_Figure->move_right();
			break;
		case VK_DOWN:
			m_Figure->boost();
			break;
		case VK_SPACE:
			m_Figure->rotate();
			break;
		}
		if (m_GameField.has_collision(*m_Figure))
			m_Figure->restore();
	};
	inline void update(const int dt) override { 
		m_Figure->backup();
		m_Figure->update(dt);
		if (m_GameField.has_collision(*m_Figure))
		{
			m_Figure->restore();
			m_GameField.merge(*m_Figure);
			m_Figure = new IBlock(Point(5, 1));
			if (m_GameField.has_collision(*m_Figure))
			{
				m_End = true;
			}
		}
	};
	inline void render(PaintDevice& paintDevice) override { 
		m_GameField.render(paintDevice); 
		m_Figure->render(paintDevice);
	};
};

