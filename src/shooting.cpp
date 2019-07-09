#include <GLUT/glut.h>
#include <stdlib.h>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <stdio.h>
#include <ctime>
#include "shooting.h"

using namespace std;

#define WIDTH 645
#define HEIGHT 480
#define GAMEMODE 1

Player p;
Ballet_p b_p;
Enemy1 e1;	
Ene1_Ballet ene1_bull;
Enemy2 e2;
Ene2_Ballet ene2_bull;
Obstacle obs;
HP_bar hb;

//キーボード/////////////////////////////////////////////////////////////////
int bull;//プレイヤーの弾のキーボード
int ch;
int WindowNum = 0;
int VoD_judge = 0;
int d_Num = 0;
int h_Num = 0;
int uxm;
int change = 0;
int start = 0;
int ed_Num = 0;
int m[4];
int s;

//Text//////////////////////////////////////////////////////////////////////////////////
inline void BuildList_s();
inline void BuildList_c();
inline void BuildList_l();
inline void DISPLAY_TEXT();

//各関数/////////////////////////////////////////////////////////////////////////////////

void DRAW_STRING(int x, int y, char *string, void *font = GLUT_BITMAP_TIMES_ROMAN_24);//文字の描画

//画面////////////////////////////////////////////////////////////////////////////

void init()
{
	glClearColor(1.0, 1.0 , 1.0, 1.0);
	glOrtho(0, WIDTH, HEIGHT, 0, -1, 1);
	glutPostRedisplay();
}

void setting()
{
	p.setting();
	e1.setting();
	b_p.setting();
	ene1_bull.setting();
	ene2_bull.setting();
	obs.setting();
	hb.setting();
}

void cheak()
{
	p.player(uxm, WindowNum, bull, ch);
	if(p.change[3] == 1){
		if(bull == 3)
		{
			if(WindowNum == 0)
			{
				if(p.play_y <= -130)
				{
					WindowNum = 1;
					bull = 0;
					setting();
				}			
			}
			if(WindowNum == 2 || WindowNum == 3)
			{
				if(p.play_y <= -280)
				{
					WindowNum = 1;
					bull = 0;
					setting();
				}
			}
		}
	}
}

//Main画面/////////////////////////////////////////////////////////////////////////////
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	if(WindowNum == 0)
	{
		BuildList_s();
		DISPLAY_TEXT();		
		cheak();
	}

	if(WindowNum == 1)
	{	
		h_Num = 0;
		b_p.Ballet(bull, p, e1, h_Num);
		ene1_bull.shot(e1, p);
		ene2_bull.shot(e2, p);
		e2.enemy2();
		obs.move_obs(p);
		hb.damage(d_Num);
		p.player(uxm, WindowNum, bull, ch);
		e1.enemy1();
		switch(b_p.hit)
		{
			case 0:
				break;

			case 1://Enemy1_0に当たった
				h_Num = 1;
				e1.hit_e(h_Num);
				break;

			case 2://Enemy1_1に当たった
				h_Num = 2;
				e1.hit_e(h_Num);
				break;

			case 3://Enemy1_2に当たった
				h_Num = 3;
				e1.hit_e(h_Num);
				break;

			case 4://Enemy1_3に当たった
				h_Num = 4;
				e1.hit_e(h_Num);
				break;
		}
		if(ene1_bull.hit_E1 == 1)
		{
			ene1_bull.hit_E1 = 0;
			d_Num = 1;
			hb.damage(d_Num);
			d_Num = 0;	
		}else if(ene2_bull.hit_E2 == 1)
		{
			ene2_bull.hit_E2 = 0;
			d_Num = 2;
			hb.damage(d_Num);
			d_Num = 0;
		}else if(obs.hit_o == 1)
		{
			d_Num = 3;
			obs.hit_o = 0;
			hb.damage(d_Num);
			d_Num = 0;
		}

		if(e1.el[0] == 0 && e1.el[1] == 0 && e1.el[2] == 0 && e1.el[3] == 0)
    	{
			WindowNum = 2;
			bull = 0;
			p.play_y = 400;
			p.play_x = 312;
		}else if(hb.d >= 100){
			WindowNum = 3;
			bull = 0;
			p.play_y = 400;
			p.play_x = 312;
		}else{

		}
	}

	if(WindowNum == 2)
	{
		BuildList_c();
		DISPLAY_TEXT();
		//p.player(uxm, WindowNum, bull, ch);
		cheak();
	}

	if(WindowNum == 3)
	{
		BuildList_l();
		DISPLAY_TEXT();
		//p.player(uxm, WindowNum, bull, ch);
		cheak();
	}
	glutSwapBuffers();
}

//keybord/////////////////////////////////////////////////////////////////////////////
void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case ' ': bull = 3;
			glutPostRedisplay();
			break;

		case 'c':ch = 1;
			glutPostRedisplay();
			break;
        case '\033':
        case 'q':
        case 'Q':
        #if GAMEMODE
            glutLeaveGameMode();
        #endif
            exit(0);
        default:
            break;
	}
}

void Skey(int key, int x, int y)
{
	switch(key){
		case GLUT_KEY_UP: uxm = 4;
			glutPostRedisplay();
			break;

		case GLUT_KEY_DOWN: uxm = 3;
			glutPostRedisplay();
			break;

		case GLUT_KEY_LEFT: uxm = 2;
			glutPostRedisplay();
			break;

		case GLUT_KEY_RIGHT: uxm = 1;
			glutPostRedisplay();
			break;
		}
}

void Supkey(int key, int x, int y)//プレイヤーの動きの停止
{
	switch(key)
	{
		case GLUT_KEY_UP: uxm = 0;
			glutPostRedisplay();
			break;

		case GLUT_KEY_DOWN: uxm = 0;
			glutPostRedisplay();
			break;

		case GLUT_KEY_LEFT: uxm = 0;
			glutPostRedisplay();
			break;

		case GLUT_KEY_RIGHT: uxm = 0;
			glutPostRedisplay();
			break;
	}
}

void idle()
{
	glutPostRedisplay();
}

//Main/////////////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
	srand(time(NULL));
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA| GLUT_DOUBLE);
	#if GAMEMODE
		glutGameModeString("width=800 height=600 bpp~24 hertz>=100");
		glutEnterGameMode();
	#else
		glutCreateWindow("shooting");
	#endif

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(Skey);
    glutSpecialUpFunc(Supkey);
    glutSetCursor(GLUT_CURSOR_NONE);
    glutIdleFunc(idle);
    init();
	glutMainLoop();
	return 0;
}

int list;

inline void BuildList_s()
{
	list=glGenLists(1);
	glNewList(list,GL_COMPILE);
	glColor3f(1.0, 0.0, 0.0);
	DRAW_STRING(85, 130, "c...change ",GLUT_BITMAP_TIMES_ROMAN_24);
	glEndList();
}

inline void BuildList_c()
{
	list=glGenLists(1);
	glNewList(list,GL_COMPILE);
	glColor3f(1.0, 0.0, 0.0);
	DRAW_STRING(60, 130, "Game Clear",GLUT_BITMAP_TIMES_ROMAN_24);
	DRAW_STRING(60, 110, "Replay...[space key]",GLUT_BITMAP_TIMES_ROMAN_24);
	DRAW_STRING(60,  90, "Game_end...[Q] or [esc]",GLUT_BITMAP_TIMES_ROMAN_24);
	glEndList();
}

inline void BuildList_l()
{
	list=glGenLists(1);
	glNewList(list,GL_COMPILE);
	glColor3f(1.0, 0.0, 0.0);
	DRAW_STRING(60, 130, "Lose...",GLUT_BITMAP_TIMES_ROMAN_24);
	DRAW_STRING(60, 110, "Replay...[space key]",GLUT_BITMAP_TIMES_ROMAN_24);
	DRAW_STRING(60,  90, "Game_end...[Q] or [esc]",GLUT_BITMAP_TIMES_ROMAN_24);
	glEndList();
}


inline void DISPLAY_TEXT()
{
	glPushAttrib(GL_ENABLE_BIT);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity(); 
	gluOrtho2D(0, 200, 0, 200); 
	glMatrixMode(GL_MODELVIEW); 
	glPushMatrix(); 
	glLoadIdentity(); 
	glColor3f(1,1,1);
	glCallList(list);
	glPopMatrix(); 
	glMatrixMode(GL_PROJECTION); 
	glPopMatrix(); 
	glPopAttrib(); 
	glMatrixMode(GL_MODELVIEW); 
}

void DRAW_STRING(int x, int y, char *string, void *font)
{
	int len, i;

	y += 5; //位置補正
	glRasterPos2f(x, y);
	len = (int) strlen(string);
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(font, string[i]);
	}

}