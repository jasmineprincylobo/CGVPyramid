// pyramid.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<GL/glut.h>
float v[][3]={{1,0,0},{0,0,1},{-1,0,0},{0,0,-1},{0,1,0}};
float angle[3]={0,0,0};
int axis=0;
void draw_triangle(float *a, float *b, float *c)
{
	glBegin(GL_POLYGON);
//	glColor3fv(a);
	glVertex3fv(a);
//	glColor3fv(b);
	glVertex3fv(b);
//	glColor3fv(c);
	glVertex3fv(c);
	glEnd();
//	glFlush();
}
void draw_square(float *w, float *x, float *y, float *z)
{
	glBegin(GL_POLYGON);
	//glColor3fv(w);
	glVertex3fv(w);
	//glColor3fv(x);
	glVertex3fv(x);
	//glColor3fv(y);
	glVertex3fv(y);
	//glColor3fv(z);
	glVertex3fv(z);
	glEnd();
//	glFlush();
}
void pyramid(void)
{
	glColor3f(1,1,0);
	draw_triangle(v[0],v[1],v[4]);
	glColor3f(1,0,1);
	draw_triangle(v[3],v[4],v[0]);
	glColor3f(1,0.5,0.5);
	draw_triangle(v[3],v[4],v[2]);
	glColor3f(0,1,0.5);
	draw_triangle(v[1],v[4],v[2]);
	glColor3f(0,1,1);
	draw_square(v[0],v[1],v[2],v[3]);
	
	//glFlush();
}
void init()
{
	glClearColor(0,0,0,1);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	glOrtho(-2,2,-2,2,-2,2);
	//glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(angle[0],1,0,0);
	glRotatef(angle[1],0,1,0);
	glRotatef(angle[2],0,0,1);
	pyramid();
	glFlush();
}
 void spin()
 {
	 if(angle[axis]>=360)
		 angle[axis]=0.0;
	 else
		 angle[axis]+=0.05;
	 display();
 }
void mouse(int btn, int st, int a, int b)
{
	if(btn==GLUT_LEFT_BUTTON && st==GLUT_DOWN)
		axis=0;
	if(btn==GLUT_MIDDLE_BUTTON && st==GLUT_DOWN)
		axis=1;
	if(btn==GLUT_RIGHT_BUTTON && st==GLUT_DOWN)
		axis=2;
	spin();	
}


void main()
{
	glutInitDisplayMode(GLUT_SINGLE|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutCreateWindow("Pyramid");
	glutDisplayFunc(display);
	glutIdleFunc(spin);
	glutMouseFunc(mouse);

	init();

	glutMainLoop();
}
