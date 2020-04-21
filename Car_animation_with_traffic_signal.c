#include<stdio.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
     //speed of traffic

float i=0.0;    //movement of car
int light=1;      //1 for green-light, 0 for red-light
int day=1;
int m=0;
float SPEED=40;
void traffic_light();

void draw_pixel(GLint cx, GLint cy)
{

	glBegin(GL_POINTS);
		glVertex2i(cx,cy);
	glEnd();
}

void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}

void draw_circle(GLint h, GLint k, GLint r)
{
	GLint d=1-r, x=0, y=r;
	while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}


void draw_object()
{
int l;
if(day==1)
{
//sky
glColor3f(0.0,0.9,0.9);
glBegin(GL_POLYGON);
glVertex2f(0,450);
glVertex2f(0,700);
glVertex2f(1100,700);
glVertex2f(1100,450);
glEnd();

//sun


	for(l=0;l<=35;l++)
{
		glColor3f(1.0,0.9,0.0);
		draw_circle(100,625,l);
}



//cloud1


	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(160+m,625,l);

	}


	for(l=0;l<=35;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(200+m,625,l);
		draw_circle(225+m,625,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(265+m,625,l);
	}

//cloud2


	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(370+m,615,l);
}




	for(l=0;l<=35;l++)
	{

		glColor3f(1.0,1.0,1.0);
		draw_circle(410+m,615,l);
		draw_circle(435+m,615,l);
		draw_circle(470+m,615,l);
	}

for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(500+m,615,l);
}

//grass
glColor3f(0.0,0.9,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,160);
glVertex2f(0,450);
glVertex2f(1100,450);
glVertex2f(1100,160);
glEnd();

//tree
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(350,325);
glVertex2f(350,395);
glVertex2f(365,395);
glVertex2f(365,325);
glEnd();


	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(340,400,l);
		draw_circle(380,400,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(350,440,l);
		draw_circle(370,440,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(360,465,l);
	}







//road boundary
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(0,150);
glVertex2f(0,160);
glVertex2f(1100,160);
glVertex2f(1100,150);
glEnd();

//road
glColor3f(0.2,0.2,0.2);
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(0,150);
glVertex2f(1100,150);
glVertex2f(1100,0);
glEnd();


//signal
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(1060,160);
		glVertex2f(1060,350);
		glVertex2f(1070,350);
		glVertex2f(1070,160);
	glEnd();


	glColor3f(0.7,0.7,0.7);
	glBegin(GL_POLYGON);
		glVertex2f(1040,350);
		glVertex2f(1040,500);
		glVertex2f(1090,500);
		glVertex2f(1090,350);
	glEnd();
traffic_light();
	for(l=0;l<=20;l++)
	{

		glColor3f(1.0,1.0,0.0);
		draw_circle(1065,425,l);

	}

//car 1
glColor3f(0.9,0.1,0.3);
glBegin(GL_POLYGON);
glVertex2f(25+i,50);
glVertex2f(25+i,125);
glVertex2f(75+i,200);
glVertex2f(175+i,200);
glVertex2f(200+i,125);
glVertex2f(250+i,115);
glVertex2f(250+i,50);
glEnd();


//windows
glColor3f(0.1,0.1,0.1);
glBegin(GL_POLYGON);
glVertex2f(35+i,125);
glVertex2f(80+i,190);
glVertex2f(115+i,190);
glVertex2f(115+i,125);
glEnd();

glColor3f(0.1,0.1,0.1);
glBegin(GL_POLYGON);
glVertex2f(125+i,125);
glVertex2f(125+i,190);
glVertex2f(170+i,190);
glVertex2f(190+i,125);
glEnd();


for(l=0;l<20;l++)
   {
	glColor3f(0,0,0);
	draw_circle(75+i,50,l);
	draw_circle(175+i,50,l);
   }

}
}



void traffic_light()
{
	int l;
if(light==1)
	  {
for(l=0;l<=20;l++)
		{

glColor3f(0.0,0.0,0.0);
		draw_circle(1065,475,l);
		glColor3f(0.0,0.7,0.0);
		draw_circle(1065,375,l);
		}
	  }

	if(light==0)
	  {

for(l=0;l<=25;l++)
		{
		glColor3f(1.0,0.0,0.0);
		draw_circle(1065,475,l);
		glColor3f(0.0,0.0,0.0);
		draw_circle(1065,375,l);
		}
	  }
}


void idle()
{

 

if(light==0)
 {
	 i=i;
++m;
 }

else
 {

     i+=SPEED/100;
++m;
 }
if(i>1100)
	 i=0.0;
if(m>1100)
	 m=0.0;
glutPostRedisplay();

}



void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
exit(0);
}


void keyboardFunc( unsigned char key, int x, int y )
{
switch( key )
    {
case 'g':
case 'G':
	light=1;
	break;

case 'r':
case 'R':
	light=0;
	break;
case 'i':
case 'I':
	if(light==1)
		SPEED=SPEED*5;
	break;
case 'd':
case 'D':
	if(light==1)
		SPEED=SPEED/5;
	break;



    };

}


void myinit()
{
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(0.0,0.0,1.0);
glPointSize(2.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,1100.0,0.0,700.0);
}



void display()
{

glClear(GL_COLOR_BUFFER_BIT);
draw_object();
traffic_light();
glFlush();
}






int main(int argc,char** argv)
{
int c_menu;
	printf("Press 'r' or 'R' to change the signal light to red \n");
	printf("Press 'g' or 'G' to change the signal light to green \n");
	printf("Press 'i' or 'I' to increase the speed by 5 times \n");
	printf("Press 'd' or 'D' to decrease the speed by 5 times \n");
	printf("Press RIGHT MOUSE BUTTON to quit the program \n");

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1100.0,700.0);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Mini Project");
	glutDisplayFunc(display);
        glutIdleFunc(idle);
	glutKeyboardFunc(keyboardFunc);
	glutMouseFunc(mouse);
	myinit();
	glutMainLoop();
	return 0;
}


