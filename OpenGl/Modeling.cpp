#include <glut.h>     
#include <gl/gl.h>      
#include <gl/glu.h>


#include <stdlib.h>
bool FlatShaded = 0;
bool wireFramed = 0;

int viewX = 0;
int viewY = 0;

void InitLight()
{
	float mat_diffuse[] =  { 0.5,0.4,0.3,1.0 };
	float mat_specular[] = { 1.0,1.0,1.0 };
	float mat_ambient[] =  { 0.5,0.4,0.3,1.0 };
	float mat_shininess[] = { 15.0 };
	float light_specular[] = { 1.0,1.0,1.0,1.0 };
	float light_diffuse[] = { 0.8,0.8,0.8,1.0 };
	float light_ambient[] = { 0.3,0.3,0.3,1.0 };
	float light_position[] = { -3,6,3.0,0.0 };
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, mat_specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, mat_ambient);
	glLightfv(GL_LIGHT0, GL_SHININESS, mat_shininess);
}
void MyMouseMove(int x, int y)
{
	viewX = x;
	viewY = y;

	glutPostRedisplay();
}

void MyKeyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'q':
		case 'Q':
		case '\033':
			exit(0);
			break;
		case 's':
			if (FlatShaded)
			{
				FlatShaded = false;
				glShadeModel(GL_SMOOTH);
			}
			else
			{
				FlatShaded = true;
				glShadeModel(GL_FLAT);
			}
			glutPostRedisplay();
			break;
		case 'w':
			if (wireFramed)
			{
				wireFramed = false;
			}
			else
			{
				wireFramed = true;
			}
	}
}

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	gluLookAt(0.0 ,0.0, 0.0,  0.0, 0.0, 1.0,   0.0, 1.0, 10.0);
	
	glutSolidTeapot(0.2);


	glFlush();
}

void MyReshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Modeling");
	glClearColor(0.4, 0.4, 0.4, 0.0);
	InitLight();
	glutDisplayFunc(MyDisplay);
	glutMotionFunc(MyMouseMove);
	glutKeyboardFunc(MyKeyboard);
	glutReshapeFunc(MyReshape);

	
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}