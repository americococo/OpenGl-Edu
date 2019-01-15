#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <stdlib.h>

GLfloat Delta = 0.0f;
void MyDisplay()
{
	glViewport(0, 0, 300, 300);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(-1.0f + Delta, -0.5, 0.0);
		glVertex3f(0.0f + Delta, -0.5, 0.0);
		glVertex3f(0.0f + Delta, 0.5, 0.0);
		glVertex3f(-1.0f + Delta, 0.5, 0.0);
	glEnd();
	glutSwapBuffers();
	

}
void MyIdle()
{
	Delta = Delta + 0.001;
	glutPostRedisplay();

}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);					//glut���̺귯�� �ʱ�ȭ & ������ os�� �����Ͽ� �ϳ��� ���� ����
	glutInitDisplayMode(GLUT_RGB);				//������ �⺻ �÷� ��带 rgb�� ����
	glutInitWindowSize(300, 300);				// ��300 ���� 300
	glutInitWindowPosition(0, 0);				// �������� �ü���� ȭ�� ��ǥ��� 0,0�� ��ġ
	glutCreateWindow("OpenGL Drawing Example");
	glClearColor(0.0, 0.0, 0.0, 1.0);			//�ʱ�ȭ ���� ����

	glMatrixMode(GL_PROJECTION);				// ������� ��ȯ �������
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);




	glutDisplayFunc(MyDisplay);
	glutIdleFunc(MyIdle);
	glutMainLoop();
	return 0;
}