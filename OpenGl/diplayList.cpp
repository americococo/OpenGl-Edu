#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>

GLuint MyListID;

void MyCreatList()
{
		
	MyListID = glGenLists(3);
	int ListSecond = MyListID + 1;
	int Listthird = MyListID + 2;

	glNewList(MyListID, GL_COMPILE);

	glBegin(GL_POLYGON);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);

	glEnd();
	glEndList();

}
void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glCallList(1);
	glFlush();
}

int main(int argc, char ** argv)
{

	glutInit(&argc, argv);						//glut���̺귯�� �ʱ�ȭ & ������ os�� �����Ͽ� �ϳ��� ���� ����
	glutInitDisplayMode(GLUT_RGB);				//������ �⺻ �÷� ��带 rgb�� ����
	glutInitWindowSize(300, 300);				// ��300 ���� 300
	glutInitWindowPosition(0, 0);				// �������� �ü���� ȭ�� ��ǥ��� 0,0�� ��ġ
	glutCreateWindow("OpenGL Drawing Example");
	glClearColor(0.0, 0.0, 0.0, 1.0);			//�ʱ�ȭ ���� ����

	glutDisplayFunc(MyDisplay);
	MyCreatList();
	glutMainLoop();
	return 0;
}