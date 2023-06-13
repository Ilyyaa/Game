#pragma once
#include "Figure.h"
class IBlock :
    public Figure
{
public:
    inline IBlock(Point position) :Figure(position)
    {
        m_Body = {  { Point(1,0), Point(1,1), Point(1,2), Point(1,3) },
                    { Point(0,2), Point(1,2), Point(2,2), Point(3,2) },
                    { Point(2,0), Point(2,1), Point(2,2), Point(2,3) },
                    { Point(0,1), Point(1,1), Point(2,1), Point(3,1) } };

    }
};

