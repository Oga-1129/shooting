#include <iostream>
#include <string>
#include <stdio.h>
#include <ctime>
#include "shooting.h"

using namespace std;

Ene2_Ballet::Ene2_Ballet()
{
	La_Ra = 0;//０で左から攻撃。１で右から攻撃
	side_cheak;
	rand_cheack;
	side_shot; 
	hit_E2 = 0;
	a_j2;
}

void Ene2_Ballet::setting()
{
	La_Ra = 0;//０で左から攻撃。１で右から攻撃
	side_cheak;
	rand_cheack;
	side_shot; 
	hit_E2 = 0;
	a_j2;
}

void Point_2(int pointx, int pointy, float size)
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

void Ene2_Ballet::hit_cheak_E2(Player p,int Num)//当たり判定
{
	if(Num == 1)
	{
		double d = sqrt(pow( this->ene2bull_x[0] - p.play_x , 2) + pow( this->ene2bull_y[0] - p.play_y , 2));
		if(60.0 + 30.0 >= d)
		{
			this->hit_E2 = 1;
			this->a_j2 = 1;
		}
	}else if(Num == 2){
		double d = sqrt(pow( this->ene2bull_x[1] - p.play_x , 2) + pow( this->ene2bull_y[1] - p.play_y , 2));
		if(60.0 + 30.0 >= d)
		{
			this->hit_E2 = 1;
			this->a_j2 = 1;
		}		
	}else if(Num == 3){

	}
}

void Ene2_Ballet::ene2_ballet(Enemy2 e2,Player p)
{
	glColor4f(1.0f,0.0f,1.0f,1.0f);

	if(this->side_shot == 1)
	{				
		if(this->ene2bull_y[0] <= 645)
		{
			this->ene2bull_x[0] += 10; 
		}

		Point_2(this->ene2bull_x[0], this->ene2bull_y[0] - 67, 30);		

	}else if(this->side_shot == 2){
		
		if(this->ene2bull_y[1] >= 0)
		{
			this->ene2bull_x[1] -= 10; 
		}

        Point_2(this->ene2bull_x[1], this->ene2bull_y[1] - 67, 30);

	}else if(this->side_shot == 3){

		if(this->ene2bull_y[2] <= 645)
		{
			this->ene2bull_x[2] += 5; 
		}
	}

	if(this->a_j2 == 0)
	{
		this->hit_cheak_E2(p,side_shot);
	}

	if(this->side_shot == 1 && this->ene2bull_x[0] > 645)
	{
		this->ene2bull_x[0] = 0;
		this->rand_cheack = 0;
	}

	if(this->side_shot == 2 && this->ene2bull_x[1] < 0)
	{
		this->ene2bull_x[1] = 645;
		this->rand_cheack = 0;
	}

	if(this->side_shot == 3 && this->ene2bull_x[2] > 645)
	{
		this->ene2bull_x[2] = 0;
		this->rand_cheack = 0;
	}
}

void Ene2_Ballet::shot(Enemy2 e2,Player p)
{
	if(this->rand_cheack == 0)
	{
		this->side_shot = rand() % 3 + 1;//どれが攻撃するか
		this->rand_cheack = 1;
	}
	ene2_ballet(e2,p);
}