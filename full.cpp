
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

static GLfloat spin=360.0;/*fan rotation variable*/
static GLfloat u=0.45;
static GLfloat v=0.45;
static GLfloat w=0.45;
static GLfloat b=0.45;
static GLfloat c=0.00;
static GLfloat d=0.00;
static GLfloat e=0.00;
static GLfloat a=-40;
static GLfloat l=0.1; 
static GLfloat f=0.1; 
static GLfloat g=0.1; 
static GLfloat l1=0.0;
static GLfloat f1=0.1;
static GLfloat g1=0.0;

static GLfloat o=1.0;
static GLfloat p=1.0;
static GLfloat q=0.0;

static int z=0;
GLfloat x=0;
GLfloat y=0;
int m,n;



void background()
{
	glColor3f(l1,f1,g1);
	glBegin(GL_POLYGON);//green ground
	glVertex2i(-250.0,-250.0);
	glVertex2i(250.0,-250.0);
	glVertex2i(250.0,0.0);
	glVertex2i(-250.0,0.0);
	glEnd();
	glColor3f(l,f,g);
	glBegin(GL_POLYGON);//mid night blue sky
	glVertex2i(-250.0,0.0);
	glVertex2i(-250.0,250.0);
	glVertex2i(250.0,250.0);
	glVertex2i(250.0,0.0);
	glEnd();

}
void fan1()
{
	glPushMatrix();
	glLoadIdentity();
	glColor3f(1,1,1);
	glTranslatef (-8.0,20.0, 2.0);/*rotation about fixed point*/
	glRotatef(spin,0.0,0.0,1.0);
	glTranslatef (8.0,-20.0, -2.0);
	glBegin(GL_TRIANGLES);/*1st fan*/
	glVertex3f(-8.0,20.0,2.0);
	glVertex3f(-12.0,16.0,3.0);
	glVertex3f(-12.0,18.0,4.0);
	glVertex3f(-8.0,20.0,2.0);
	glVertex3f(-4.0,24.0,3.0);
	glVertex3f(-4.0,22.0,4.0);
	glEnd();
	glPopMatrix();
}
void fan2()
{
	glPushMatrix();
	glLoadIdentity();
	glTranslatef (-20.0, 20.0, 2.0);/*rotation about fixed point*/
	glRotatef(spin,0.0,0.0,1.0);
	glTranslatef (20.0, -20.0,-2.0);
	glColor3f(1,1,1);
	glBegin(GL_TRIANGLES);/*2nd fan*/
	glVertex3f(-20.0,20.0,2.0);
	glVertex3f(-25.0,17.0,3.0);
	glVertex3f(-25.0,19.0,4.0);
	glVertex3f(-20.0,20.0,2.0);
	glVertex3f(-15.0,23.0,3.0);
	glVertex3f(-15.0,21.0,4.0);
	glEnd();
	glPopMatrix();
}
void fan3()
{
	glPushMatrix();
	glLoadIdentity();
	glTranslatef (-32.0, 20.0, 2.0);/*rotation about fixed point*/
	glRotatef(spin,0.0,0.0,1.0);
	glTranslatef (32.0, -20.0, -2.0);
	glColor3f(1,1,1);
	glBegin(GL_TRIANGLES);/*2nd fan*/
	glVertex3f(-32.0,20.0,2.0);
	glVertex3f(-36.0,16.0,3.0);
	glVertex3f(-36.0,18.0,4.0);
	glVertex3f(-32.0,20.0,2.0);
	glVertex3f(-28.0,24.0,3.0);
	glVertex3f(-28.0,22.0,4.0);
	glEnd();
	glPopMatrix();
}

void powerstation()
{
	GLint ax=1.5,ay=8;
	glColor3f(0.4,0.75,0.1);
	glBegin(GL_POLYGON);//from tip(anti clkwise)
	glVertex2i(ax,ay);//a
	glVertex2i(ax-2,ay-2);//b
	glVertex2i(ax-2,ay-8);//c
	glVertex2i(ax+2,ay-8);//d
	glVertex2i(ax+2,ay-2);//e
	glEnd();
	glColor3f(0.2,0.5,1);
	glBegin(GL_POLYGON);//roof (from a)
	glVertex2i(ax,ay+3);//a
	glVertex2i(ax-3,ay-3);//b
	glVertex2i(ax+3,ay-3);//e
	glEnd();
	glColor3f(v,v,w);
	glBegin(GL_POLYGON);/* door */
	glVertex2i(ax-1,ay-5.0);//top left
	glVertex2i(ax-1.0,ay-8.0);//bottom left
	glVertex2i(ax+1.0,ay-8.0);// bottom right
	glVertex2i(ax+1.0,ay-5.0);//top right
	glEnd();
}
void road()
{
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(-1,0);
	glVertex2f(4,0);
	glVertex2f(43,-39);
	glVertex2f(37,-40);
	glEnd();
}


void hut(GLint rux,GLint ruy,GLint rdx,GLint rdy)
{
	GLint blx=rdx,bly=rdy-9,brx=rdx+10,bry=rdy-9,kx=rdx-8,ky=rdy+1;
	GLfloat i;
	for(i=0;i<440;i=i+1)
	glColor3f(0.3,0.25,0.1);
	glBegin(GL_POLYGON);/* front wall */
	glVertex2i(rdx,rdy);//roof left
	glVertex2i(rdx+10,rdy);//roof right
	glVertex2i(brx,bry);//base right
	glVertex2i(blx,bly);//base left
	glEnd();
	glColor3f(0.3,0.15,0.1);
	glBegin(GL_POLYGON);/* side wall */
	glVertex2i(rux,ruy);//roof up
	glVertex2i(kx,ky);//bacK
	glVertex2i(kx,ky-6);//bacK base
	glVertex2i(blx,bly);
	glVertex2i(rdx,rdy);
	glEnd();
	glColor3f(v,v,w);
	glBegin(GL_POLYGON);/* window */
	glVertex2i(kx+2,ky-2.5);//top left
	glVertex2i(kx+2,ky-5.5);//bottom left
	glVertex2i(blx-3,bly+3.5);//bottom right
	glVertex2i(blx-3,bly+6.9);//top right
	glEnd();
	glColor3f(v,v,w);
	glBegin(GL_POLYGON);/* door */
	glVertex2i(blx+3.5,bly+5);//top left
	glVertex2i(blx+3.5,bly);//bottom left
	glVertex2i(brx-3.5,bry);//bottom right
	glVertex2i(brx-3.5,bry+5);//top right
	glEnd();
	glColor3f(0.9,0.1,0.1);
	glBegin(GL_POLYGON);
	glVertex2i(rdx+10.4,rdy);//roof left
	glVertex2i(rdx,rdy);
	glVertex2i(rux,ruy);
	glVertex2i(rdx+5,ruy);
	glEnd();
}
void fanpole1()
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-8.1,20.0);
	glVertex2f(-7.9,20.0);
	glVertex2f(-8.5,0.0);
	glVertex2f(-7.5,0.0);
	glEnd();
}
void fanpole2()
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-20.1,20.0);
	glVertex2f(-19.9,20.0);
	glVertex2f(-20.5,0.0);
	glVertex2f(-19.5,0.0);
	glEnd();
}
void fanpole3()
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-32.1,20.0);
	glVertex2f(-31.9,20.0);
	glVertex2f(-32.5,0.0);
	glVertex2f(-31.5,0.0);
	glEnd();
}


void display(void)
{
	int b=0;
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	if(z<50)
	{
		for(z=0;z<=100;z++)
		{
			glutPostRedisplay();
			glutSwapBuffers();
			glFlush();
		}
	}
	else
	{

	background();
	road();
	hut(-29,-23,-24,-33);
	hut(0,-11,5,-21);
	hut(-21,-1,-14,-11);

	powerstation();

	fanpole1();
	fanpole2();
	fanpole3();


	fan1();
	fan2();
	fan3();
	glutSwapBuffers();
	glFlush();
	}
}

void spinclockwise(void)
{
	w=0.3;u=0;v=1;b=0.5;c=1;d=1;e=0;
	 a=a+0.1;
          if(a>40)
	 a-=100.0;
	 spin=spin-0.5;
	 if(spin<0)
	spin=spin+360.0;

	glutPostRedisplay();

 }

void anticlockwise(void )
{
	u=0;w=.3;v=1;b=0.5;c=1;d=1,e=0;
	 if(a==40)
	 a=40;
	 a=a-0.1;
         if(a<-100)
	 a+=100.0;
         if(spin==360.0)
	spin=spin-360;
	spin=spin+0.5;
	if(spin>360.0)
         spin=spin-0.5;
	glutPostRedisplay();

}
void night(void)
{ 	u=0;w=.3;v=1;
  b=0.5;c=1;d=1,e=0;  
  l=0.1,f=0.1,g=0.1; 
  l1=0,f1=0.1;g1=0;  
   a=a+0.1;
          if(a>40)
	 a-=100.0;
	 spin=spin-0.5;
	 if(spin<0)
	spin=spin+360.0;

	glutPostRedisplay();

}

void day(void)
 {   
  l1=0.5,f1=0.8,g1=0.3; 
   b=0.5;c=1;d=1,e=0;  
  l=0.2,f=0.4,g=0.7;
  u=0;w=0.3;v=1;
  o=1,p=2,q=0;
    a=a+0.1;
          if(a>40)
	 a-=100.0;
	 spin=spin-0.5;
	 if(spin<0)
	spin=spin+360.0;
	glutPostRedisplay();

}

void reshape(int w, int h)
{
glViewport(0, 0, (GLsizei) w, (GLsizei) h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-35.0, 35.0, -45.0, 45.0, -20.0, 20.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}
void menu(int id )
{
	switch(id)
	{
	case 1: u=v=w=b=0.45;c=d=e=1;
			glutIdleFunc(display);
			break;
	case 2: glutIdleFunc(spinclockwise);
			break;
	case 3: glutIdleFunc(anticlockwise);
			break;
    case 4: glutIdleFunc(day);
			break;
	case 5: glutIdleFunc(night);
			break;
	case 6:exit(0);
	}
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("WIND ENERGY");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);	
    glutCreateMenu(menu);
	glutAddMenuEntry("No Wind",1);
	glutAddMenuEntry("Wind CW",2);
	glutAddMenuEntry("Wind ACW",3);
     glutAddMenuEntry("Day",4);
    glutAddMenuEntry("Night",5);
	glutAddMenuEntry("Quit",6);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}


