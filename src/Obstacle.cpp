#include <iostream>
#include <string>
#include "shooting.h"

using namespace std;

Obstacle::Obstacle()
{
	obs_judge = 0;
	obs_num = 5;//障害物の数
	obs_pop[5];
	obs_y = 480;
	hit_o = 0;
	a_j3;
	fall_cheack;
}

void Obstacle::setting()
{
	obs_judge = 0;
	obs_num = 5;//障害物の数
	obs_pop[5];
	obs_y = 480;
	hit_o = 0;
	a_j3;
	fall_cheack;
}

void Obstacle::hit_cheak_O(Player p, int Num)
{
    double d = ( this->obs_x[Num] - p.play_x ) * ( this->obs_x[Num] - p.play_x ) + (( p.play_y + p.p_v[1]) - this->obs_y) * ((p.play_y + p.p_v[1]) - this->obs_y);
    if((60.0 + 10.0) * (60.0 + 10.0) >= d)
    {
        this->hit_o = 1;
        a_j3 = 1;
    }
}

void Obstacle::obstacle( int x, int y)
{
	glColor3d(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x, y - 10);
	glVertex2f(x + 10, y - 10);
	glVertex2f(x + 10, y + 10);
	glVertex2f(x - 10, y + 10);
	glVertex2f(x - 10, y - 10);
	glVertex2f(x, y - 10);
	glVertex2f(x, y);
	glEnd();
}

void Obstacle::move_obs(Player p)
{
	this->obs_y += 3;
	for(int i = 0; this->obs_num > i; i++)
	{
		if(this->obs_y > 480)
	   	{ 
	   		this->fall_cheack = 0;
	        this->a_j3 = 0;                     
		    this->obs_y = 0;
    	}    

    	if(this->fall_cheack == 0)
    	{
    		this->fall_cheack = 1;
    		for(int i = 0; this->obs_num > i; i++)
    		{
    			this->obs_pop[i] = rand() % 2 + 1;//2分の1の確率で発射する
    		}
    	}

		if(this->obs_pop[i] == 1)
		{
			this->obstacle(this->obs_x[i] , this->obs_y);
		}

		if(a_j3 == 0)
		{
			this->hit_cheak_O(p, i);
		}
	}
}