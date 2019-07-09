#include <iostream>
#include <string>
#include "shooting.h"

using namespace std;

Ballet_p::Ballet_p()
{
    vertexY = 408;//弾のy座標
    balletr = 8;//弾の半径
    hit = 0;  
}

void Ballet_p::setting()
{
    vertexY = 408;//弾のy座標
    balletr = 8;//弾の半径
    hit = 0;
}

void Point_P(int pointx, int pointy, float size)
{
    glPointSize(size);
    glBegin(GL_POLYGON);
    //glVertex2f(pointx, pointy);
    for(double i = 0; 360.0 > i;++i)
    {
        int x = pointx + size * cos(i);
        int y = pointy + size * sin(i);
        glVertex2f(x, y);
    }
    glEnd();
}

void Ballet_p::hit_cheak_P(Enemy1 e1, int Num)//当たり判定
{
    for(int i = 1; 5 > i; i++)
    {
        double d = sqrt(( this->vertexX[Num] - e1.enex[i - 1] ) * (this->vertexX[Num] - e1.enex[i - 1]) + ( this->vertexY - (e1.ene1Y + e1.e_v[1])) * (this->vertexY + e1.e_v[1]));
        if(this->balletr + 20 > d)
        {
            this->hit = i;
        }
    }
}


void Ballet_p::Ballet(int& bull, Player p, Enemy1 e1, int& h_Num)
{
	glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
    if(bull == 3)//死んでいると発射しないように
    {                   
    	if(this->vertexY == 408)
    	{
    		this->vertexX[0] = p.play_x - 8;
            this->vertexX[1] = p.play_x + 8;
    		this->vertexY = p.play_y;
    	}
        this->vertexY -= 5;//弾の速度
        for(int i = 0; 2 > i;i++)
        {
            Point_P(this->vertexX[i], this->vertexY, this->balletr);
            if(this->hit == 0)
            {
                this->hit_cheak_P(e1, i);
            }
        }
        if(this->vertexY < 0)
        {
            bull = 0;
        	this->vertexY = 408;
            this->hit = 0;
        }
    }
}