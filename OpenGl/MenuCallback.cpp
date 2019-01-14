#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <stdlib.h>

bool isSphere = true;
bool isSmall = true;
void MyDisplay()
{
	glViewport(0, 0, 300, 300);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);

	float rad = isSmall ? 0.1 : 0.2;

	if (isSphere)
		glutWireSphere(rad * 2, 15, 15);
	else
		glutWireTorus(rad, rad*2 + 0.1 , 40, 20);
	glFlush();

}
void MyMainMenu(int entryID)
{
	if (entryID == 1)
		isSphere = true;
	else if (entryID == 2)
		isSphere = false;
	else
		exit(0);
	
	glutPostRedisplay();
}
void MySubMenu(int entryID)
{
	if (entryID == 1)
		isSmall = true;
	else
		isSmall = false;

	glutPostRedisplay();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);					//glut라이브러리 초기화 & 윈도우 os와 연결하여 하나의 세션 형성
	glutInitDisplayMode(GLUT_RGB);				//윈도우 기본 컬러 모드를 rgb로 설정
	glutInitWindowSize(300, 300);				// 폭300 높이 300
	glutInitWindowPosition(0, 0);				// 윈도우의 운영체제의 화면 좌표계상 0,0에 위치
	glutCreateWindow("OpenGL Drawing Example");
	glClearColor(0.0, 0.0, 0.0, 1.0);			//초기화 색깔 지정

	glMatrixMode(GL_PROJECTION);				// 투상행렬 변환 대상으로
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	GLint MySubMenuID = glutCreateMenu(MySubMenu);
	glutAddMenuEntry("Small", 1);
	glutAddMenuEntry("Big", 2);

	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddMenuEntry("Draw sphere", 1);
	glutAddMenuEntry("Draw Torus" , 2);
	glutAddSubMenu("change Size", MySubMenuID);
	glutAddMenuEntry("Exit", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);


	glutDisplayFunc(MyDisplay);

	glutMainLoop();
	return 0;
}