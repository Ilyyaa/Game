#include "Tetris.h"
#include "IBlock.h"

Tetris::Tetris()
{
	paint_device().resize(Size(m_Width + 6, m_Height));
	m_GameField.resize(m_Width, m_Height);
	m_Figure = new IBlock(Point(5, 1));
	track_key(VK_LEFT);
	track_key(VK_RIGHT);
	track_key(VK_DOWN);
	track_key(VK_SPACE);
}
