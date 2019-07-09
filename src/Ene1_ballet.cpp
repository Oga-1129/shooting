#include <iostream>
#include <string>
#include "shooting.h"

using namespace std;

Ene1_Ballet::Ene1_Ballet()
{
    enebull_x; 
    enebull_y = 480;
    ene_shot_judge = 0;
    Bcop;
    sei = 0;
    hit_E1 = 0;
    a_j1;
}

void Ene1_Ballet::setting()
{
    enebull_x; 
    enebull_y = 480;
    ene_shot_judge = 0;
    Bcop;
    sei = 0;
    hit_E1 = 0;
    a_j1;   
}

void Ene1_Ballet::hit_cheak_E1(Player p)
{
    double d = (this->enebull_x + this->Bcop - p.play_x ) * (this->enebull_x + this->Bcop - p.play_x ) + (( p.play_y + p.p_v[1]) - this->enebull_y) * ((p.play_y + p.p_v[1]) - this->enebull_y);
    if((60.0 + 15.0) * (60.0 + 15.0) >= d && this->a_j1 == 0)
    {
        this->hit_E1 = 1;
        this->a_j1 = 1;
    }

}

void Point_1(int pointx, int pointy, float size)
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

void Ene1_Ballet::ene1_ballet(Enemy1 e1, Player p)
{
	glColor4f(0.0f, 0.0f, 1.0f, 0.0f);
    if(this->sei == 0)
    {
    	if(this->enebull_y == 80)
    	{
    		this->enebull_x = e1.enexm + 60;
    	}
    }
	Point_1(this->enebull_x + this->Bcop, this->enebull_y, 15);
}

//弾の条件、複製
void Ene1_Ballet::shot(Enemy1 e1, Player p)
{

    this->enebull_y += 8;//弾の速度
    if(this->enebull_y > 480)
    {
        this->a_j1 = 0;                      
        for(int i = 0; 4 > i; i++)
        {
           this->ene_shot[i] = rand() % 2 + 1;//2分の1の確率で発射する
        }
        this->enebull_y = 80;
        this->sei = 0;
    }
    
    for(int j = 0; 4 > j; j++)
    {
        if(e1.el[j] == 0)
        {                               //死んでいると発射しないように

        }else if(e1.el[j] == 1 && this->ene_shot[j] == 1){
            this->Bcop = j * 80;
            this->ene1_ballet(e1, p);
            if(this->a_j1 == 0)
            {
                this->hit_cheak_E1(p);
            }
        }
    }
    
}