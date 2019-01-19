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

	glutInit(&argc, argv);						//glut라이브러리 초기화 & 윈도우 os와 연결하여 하나의 세션 형성
	glutInitDisplayMode(GLUT_RGB);				//윈도우 기본 컬러 모드를 rgb로 설정
	glutInitWindowSize(300, 300);				// 폭300 높이 300
	glutInitWindowPosition(0, 0);				// 윈도우의 운영체제의 화면 좌표계상 0,0에 위치
	glutCreateWindow("OpenGL Drawing Example");
	glClearColor(0.0, 0.0, 0.0, 1.0);			//초기화 색깔 지정

	glutDisplayFunc(MyDisplay);
	MyCreatList();
	glutMainLoop();
	return 0;
}