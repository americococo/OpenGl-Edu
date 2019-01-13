#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <stdlib.h>
GLint TopleftX, TopleftY, BottomRightX, BottomRightY;
void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);					
	glViewport(0, 0, 300, 300);
	glColor3f(1.0, 0.0, 0.0);//������




	glBegin(GL_POLYGON);
	//glVertex3f(TopleftX / 300.0, (300 - TopleftY) / 300.0, 0.0);
	//glVertex3f(TopleftX / 300.0, (300 - BottomRightY) / 300.0, 0.0);
	//glVertex3f(BottomRightX / 300.0, (300 - BottomRightY) / 300.0, 0.0);
	//glVertex3f(BottomRightX / 300.0, (300 - TopleftY) / 300.0, 0.0);

	glVertex3f(TopleftX / 300.0, TopleftY / 300.0, 0.0);
	glVertex3f(TopleftX / 300.0, BottomRightY / 300.0, 0.0);
	glVertex3f(BottomRightX / 300.0, BottomRightY / 300.0, 0.0);
	glVertex3f(BottomRightX / 300.0, TopleftY / 300.0, 0.0);


	glEnd();
	glFlush();

}
void MyKeyboard(unsigned char keyPressd, int X, int Y)
{
	switch (keyPressd)
	{
	case 'q':
		exit(0); break;
	case 27:
		exit(0); break;
	default:
		break;
	}
}



void MyMouseCLick(GLint button, GLint state, GLint x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		TopleftX = x;
		TopleftY = y;
	}
}
void MyMouseMove(GLint x,GLint y)
{
	BottomRightX = x;
	BottomRightY = y;
	glutPostRedisplay();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);						//glut���̺귯�� �ʱ�ȭ & ������ os�� �����Ͽ� �ϳ��� ���� ����
	glutInitDisplayMode(GLUT_RGB);				//������ �⺻ �÷� ��带 rgb�� ����
	glutInitWindowSize(300, 300);				// ��300 ���� 300
	glutInitWindowPosition(0, 0);				// �������� �ü���� ȭ�� ��ǥ��� 0,0�� ��ġ
	glutCreateWindow("OpenGL Drawing Example");
	glClearColor(0.0, 0.0, 0.0, 1.0);			//�ʱ�ȭ ���� ����
	
	glMatrixMode(GL_PROJECTION);				// ������� ��ȯ �������
	glLoadIdentity();
	glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
	
	glutDisplayFunc(MyDisplay);
	glutMouseFunc(MyMouseCLick);
	glutKeyboardFunc(MyKeyboard);
	glutMotionFunc(MyMouseMove);
	glutMainLoop();
	return 0;
}