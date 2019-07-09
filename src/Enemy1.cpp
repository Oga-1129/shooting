#include <iostream>
#include <string>
#include "shooting.h"

using namespace std;

Enemy1::Enemy1()
{
	ene1X = 30;//Enemyの先頭のx座標
	ene1Y = 80;//Enemyの最上列のy座標
	L_R = 0;//0が右、１が左
	enexm = 0;
	enex[4];
}

void Enemy1::setting()
{
	ene1X = 30;//Enemyの先頭のx座標
	ene1Y = 80;//Enemyの最上列のy座標
	L_R = 0;//0が右、１が左
	enexm = 0;
	enex[4];
	for(int i = 0; 4 > i; i++)
	{
		el[i] = 1;
	}	
}

void TRIANGLE_E(int x, int y, int x1, int y1, int x2, int y2)
{
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x, y + y1);
	glVertex2f(x + x1, y + y2);
	glVertex2f(x + x2, y + y2);
	glVertex2f(x, y + y1);
	glEnd();
}

void Enemy1::hit_e(int Num)
{
	switch(Num)
	{
		case 0:
			break;
		case 1:
			this->el[0] = 0;
			break;
		case 2:
			this->el[1] = 0;
			break;
		case 3:
			this->el[2] = 0;
			break;
		case 4:
			this->el[3] = 0;
			break;
	}
}

void Enemy1::move_enemy1()
{
	if(this->L_R == 0)
	{
		if(this->enex[3]>= 630)
		{
			this->L_R = 1;
		}else{
			this->enexm += 5;
		}
	}else if(this->L_R == 1)
	{
		if(this->enex[0] <= 15)
		{
			this->L_R = 0;
		}else{
			this->enexm -= 5;
		}
	}
}

void Enemy1::enemy1()
{
	move_enemy1();
	glColor3d(1.0, 0.0, 0.0);
	for(int i = 0; 4 > i; i++)
	{
		this->enex[i] = this->ene1X + i * 80 + this->enexm;
		if(this->el[i] == 0)
		{

		}else if(this->el[i] == 1){
			TRIANGLE_E(this->enex[i], this->ene1Y, this->e_v[0], this->e_v[1], this->e_v[2], this->e_v[3]);
		}
	}
	glFlush();
}
