#include <iostream>
#include <string>
#include "shooting.h"

using namespace std;

Player::Player()
{
	HP = 10; 	//playerのHP
	uxm;//プレイヤーの移動値判定値
	play_x = 322;
	play_y = 300;//Playerの座標
	size = 1;
}

void Player::setting()
{
	HP = 10; 	//playerのHP
	play_x = 312;
	play_y = 300;//Playerの座標
	size = 1;
	for(int i = 0; 3 > i; i++)
	{
		change[i] = 0;
	}
}

void Broc_P(int x, int y, double size)
{
	glBegin(GL_POLYGON);
	glVertex2f(x, y - 95 /size);
	glVertex2f(x, y - 70/size);
	glVertex2f(x + 10/size, y - 70 /size);
	glVertex2f(x + 10/size, y + 30 /size);
	glVertex2f(x - 10/size, y + 30 /size);
	glVertex2f(x - 10/size, y - 70 /size);
	glVertex2f(x, y - 70 /size);
	glEnd();
}

//右側///////////////////////////////////////////////////////////
void WING_P_R(int x, int y, double size)//右翼
{
	glColor3d(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x + 22 / size, y - 25 /size);
	glVertex2f(x + (22 + 60) / size, y + 30/size);
	glVertex2f(x + (22 + 50) / size, y + 45/size);
	glVertex2f(x + 22 / size, y + 30/size);
	glVertex2f(x + 22 / size, y - 25 /size);
	glEnd();
}

void WING_P_R_2(int x, int y, double size)//右の銃
{
	glColor3d(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x + 30/size, y + 40/size);
	glVertex2f(x + (30 +  5)/size, y + 40 /size);
	glVertex2f(x + (30 + 20)/size, y + 60/size);
	glVertex2f(x + (30 + 20)/size, y + 65/size);
	glVertex2f(x + 30/size, y + 65/size);
	glVertex2f(x + 30/size, y + 40/size);
	glEnd();
}

//左側//////////////////////////////////////////////////////////
void WING_P_L(int x, int y, double size)//左翼
{
	glColor3d(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x - 22/size, y - 25/size);
	glVertex2f(x + (-22 -60)/size, y + 30/size);
	glVertex2f(x + (-22 -50)/size, y + 45/size);
	glVertex2f(x - 22/size, y + 30/size);
	glVertex2f(x - 22/size, y + 30/size);
	glEnd();
}

void WING_P_L_2(int x, int y, double size)//左の銃
{
	glColor3d(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x - 30/size, y + 40/size);
	glVertex2f(x + (-30  -5)/size, y + 40/size);
	glVertex2f(x + (-30 -20)/size, y + 60/size);
	glVertex2f(x + (-30 -20)/size, y + 65/size);
	glVertex2f(x - 30/size, y + 65/size);
	glVertex2f(x - 30/size, y + 40/size);
	glEnd();
}

//右の肩//////////////////////////////////////////
void SHOULDER_P_BR(int x, int y, double size)
{
	glColor3d(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x + 25/size, y - 40 /size);
	glVertex2f(x + 30/size, y - 40 /size);
	glVertex2f(x + 30/size, y + 30 /size);
	glVertex2f(x + 10/size, y + 30 /size);
	glVertex2f(x + 10/size, y - 40 /size);
	glVertex2f(x + 25/size, y - 40 /size);
	glEnd();
}

//左の肩///////////////////////////////////////////////////
void SHOULDER_P_BL(int x, int y, double size)
{
	glColor3d(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x - 25/size, y - 40 /size);
	glVertex2f(x - 30/size, y - 40 /size);
	glVertex2f(x - 30/size, y + 30 /size);
	glVertex2f(x - 10/size, y + 30 /size);
	glVertex2f(x - 10/size, y - 40 /size);
	glVertex2f(x - 25/size, y - 40 /size);
	glEnd();
}

//右後ろのブースター////////////////////////////////////////////////////////
void BOOSTER_P_BR_2(int x, int y, double size)
{
	glColor3d(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x, y + 20 /size);
	glVertex2f(x + 30/size, y + 20 /size);
	glVertex2f(x + 30/size, y + 60 /size);
	glVertex2f(x + 20/size, y + 70 /size);
	glVertex2f(x + 10/size, y + 70 /size);
	glVertex2f(x, y + 60 /size);
	glVertex2f(x, y + 20 /size);
	glVertex2f(x, y + 20 /size);
	glEnd();
}

//左後ろのブースター///////////////////////////////////////////////////////////
void BOOSTER_P_BL_2(int x, int y, double size)
{
	glColor3d(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x, y + 20 /size);
	glVertex2f(x - 30/size, y + 20 /size);
	glVertex2f(x - 30/size, y + 60 /size);
	glVertex2f(x - 20/size, y + 70 /size);
	glVertex2f(x - 10/size, y + 70 /size);
	glVertex2f(x, y + 60 /size);
	glVertex2f(x, y + 20 /size);
	glVertex2f(x, y + 20 /size);
	glEnd();
}

void hit_cheak(int px, int py, int size)
{
	glBegin(GL_POLYGON);
    //glVertex2f(pointx, pointy);
    glColor3d(1.0, 0.0, 0.0);
    for(double i = 0; 360.0 > i;++i)
    {
        int x = px + size * cos(i);
        int y = py + size * sin(i);
        glVertex2f(x, y);
    }
    glEnd();
}

//Playerの動き///////////////////////////////////////////////////////////
void Player::move_player(int& uxm)//playerの動き
{
	switch(uxm)
	{
		case 1:
			if(this->play_x <= 500)
			{
				this->play_x += 5;
			}
			break;
		case 2:
			if(this->play_x >= 150)
			{
				this->play_x -= 5;
			}
			break;
		case 3:
			if(this->play_y <=400)
			{
				this->play_y += 5;
			}
			break;
		case 4:
			if(this->play_y >= 200)
			{
				this->play_y -= 5;
			}
			break;	
	}
}

void Player::s_move(int WindowNum)
{
	if(WindowNum == 0|| WindowNum == 1)
	{
		if(this->play_y > -280)
		{
			this->play_y -= 10;
		}
	}else if(WindowNum == 2 || WindowNum == 3)
	{
		if(this->play_y > -280)
		{
			this->play_y -= 10;
		}
	}
}

void Player::player(int& uxm, int WindowNum, int bull, int& ch)//playerの描画
{
	if(WindowNum == 0 && change[3] == 1)
	{
		if(bull == 3)
		{
			this->s_move(WindowNum);
		}
		size = 1;
	}else if(WindowNum == 1)
	{
		move_player(uxm);
		size = 1.5;
	}else if(WindowNum == 2 && change[3] == 1)
	{
		if(bull == 3)
		{
			this->s_move(WindowNum);
		}
		size = 1;
	}else if(WindowNum == 3 && change[3] == 1)
	{
		if(bull == 3)
		{
			this->s_move(WindowNum);
		}
		size = 1;
	}
	//hit_cheak(this->play_x, this->play_y, 60);//当たり判定確認用
	glColor3d(0.0, 0.0, 0.0);
	Broc_P(this->play_x, this->play_y, size);
	if(ch == 1)
	{
		if(this->change[0] == 0 && ch == 1)
		{
			this->change[0] = 1;
			ch = 0;
		}else if(this->change[1] == 0 && ch == 1){
			this->change[1] = 1;
			ch = 0;
		}else if(this->change[2] == 0 && ch == 1){
			this->change[2] = 1;
			ch = 0;
		}else if(this->change[3] == 0 && ch == 1){
			this->change[3] = 1;
			ch = 0;
		}
	}
	if(this->change[0] == 1)
	{
		SHOULDER_P_BR(this->play_x, this->play_y, size);
		SHOULDER_P_BL(this->play_x, this->play_y, size);
	}

	if(this->change[1] == 1)
	{
		BOOSTER_P_BR_2(this->play_x, this->play_y, size);
		BOOSTER_P_BL_2(this->play_x, this->play_y, size);
	}

	if(this->change[2] == 1)
	{
		WING_P_R(this->play_x, this->play_y, size);
		WING_P_L(this->play_x, this->play_y, size);
	}

	if(this->change[3] == 1)
	{
		WING_P_R_2(this->play_x, this->play_y, size);
		WING_P_L_2(this->play_x, this->play_y, size);
	}	
	glFlush();
}

