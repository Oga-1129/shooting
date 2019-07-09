#include <iostream>
#include <string>
#include "shooting.h"

using namespace std;

void BROC(int x, int y, int x1, int y1)
{
	glBegin(GL_POLYGON);
	glVertex2f(x , y);
	glVertex2f(x + x1, y);
	glVertex2f(x + x1, y + y1);
	glVertex2f(x , y + y1);
	glVertex2f(x , y);
	glEnd();
}

void Enemy2::enemy2()
{
	glColor3d(1.0, 0.0, 0.0);
	BROC(ene2x[0], ene2y[0], 80, -135);
	BROC(ene2x[1], ene2y[1], -80, -135);
	glFlush();	
}

