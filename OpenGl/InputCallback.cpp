#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <stdlib.h>
GLint TopleftX, TopleftY, BottomRightX, BottomRightY;
void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);					
	glViewport(0, 0, 300, 300);
	glColor3f(1.0, 0.0, 0.0);//빨간색




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
	glutInit(&argc, argv);						//glut라이브러리 초기화 & 윈도우 os와 연결하여 하나의 세션 형성
	glutInitDisplayMode(GLUT_RGB);				//윈도우 기본 컬러 모드를 rgb로 설정
	glutInitWindowSize(300, 300);				// 폭300 높이 300
	glutInitWindowPosition(0, 0);				// 윈도우의 운영체제의 화면 좌표계상 0,0에 위치
	glutCreateWindow("OpenGL Drawing Example");
	glClearColor(0.0, 0.0, 0.0, 1.0);			//초기화 색깔 지정
	
	glMatrixMode(GL_PROJECTION);				// 투상행렬 변환 대상으로
	glLoadIdentity();
	glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
	
	glutDisplayFunc(MyDisplay);
	glutMouseFunc(MyMouseCLick);
	glutKeyboardFunc(MyKeyboard);
	glutMotionFunc(MyMouseMove);
	glutMainLoop();
	return 0;
}