#include <iostream>
#include <string>
#include "shooting.h"

using namespace std;

HP_bar::HP_bar()
{
	b_x = 10;
	b_y = 10;
	f_x = 10;
	f_y = 10;
	d = 0;
}

void HP_bar::setting()
{
	b_x = 10;
	b_y = 10;
	f_x = 10;
	f_y = 10;
	d = 0;	
}

void HP_bar::hp_bar(int d)
{
	glColor3d(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(this->b_x, this->b_y);
	glVertex2f(this->b_x, this->b_y + 20);
	glVertex2f(this->b_x + 100, this->b_y + 20);
	glVertex2f(this->b_x + 100, this->b_y);
	glVertex2f(this->b_x, this->b_y);
	glEnd();

	glColor3d(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(this->f_x, this->f_y);
	glVertex2f(this->f_x, this->f_y + 20);
	glVertex2f(this->f_x - d + 100 , this->f_y + 20);
	glVertex2f(this->f_x - d + 100 , this->f_y);
	glVertex2f(this->f_x, this->f_y);
	glEnd();

}

void HP_bar::damage(int Num)
{
	switch(Num)
	{	
		case 0:
			this->d += 0;
			break;

		case 1://Enemy1の弾
			this->d += 5;
			break;

		case 2://Enemy2の弾
			this->d += 15;
			break;

		case 3://障害物
			this->d += 10;
			break;
	}

	this->hp_bar(this->d);
}

void HP_bar::e_hp_bar(int d, Enemy1 e1, int m)
{
	glColor3d(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(e1.ene1X + m + e1.enexm, e1.ene1Y - 50);
	glVertex2f(e1.ene1X + m + e1.enexm, e1.ene1Y + 1 - 50);
	glVertex2f(e1.ene1X + 50 + m + e1.enexm, e1.ene1Y + 1 - 50);
	glVertex2f(e1.ene1X + 50 + m + e1.enexm, e1.ene1Y - 50);
	glVertex2f(e1.ene1X + m + e1.enexm, e1.ene1Y - 50);
	glEnd();

	glColor3d(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(e1.ene1X + m + e1.enexm, e1.ene1Y - 50);
	glVertex2f(e1.ene1X + m + e1.enexm, e1.ene1Y + 1 - 50);
	glVertex2f(e1.ene1X + 50 + m + e1.enexm - d, e1.ene1Y + 1 - 50);
	glVertex2f(e1.ene1X + 50 + m + e1.enexm - d, e1.ene1Y - 50);
	glVertex2f(e1.ene1X + m + e1.enexm, e1.ene1Y - 50);
	glEnd();	
}

void HP_bar::e_damage(int& s, int Num, Enemy1 e1, int m)
{
	if(s == 1)
	{
		this->e_d[Num] += 10;
	}
	this->e_hp_bar(this->e_d[Num], e1, m);
}
