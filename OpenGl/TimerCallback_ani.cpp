#include <glut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <stdlib.h>

GLfloat Delta = 0.0f;
int Index = 0;

void MyDisplay()
{
	static unsigned char PALETTE[8][3] =
	{
		{255,255,255},
		{0,255,255},
		{255,0,255},
		{255,255,0},
		{0,0,255},
		{0,255,0},
		{255,0,0},
		{0,0,0},
	};
	

	
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(PALETTE[Index][0]/255.0f, PALETTE[Index][1] / 255.0f, PALETTE[Index][2] / 255.0f);
	//palette값 0~1값으로 표본화



	glLineWidth(130.0f);

	glBegin(GL_LINES);
	glVertex3f(-1.0f + Delta, 1.0, 0.0);
	glVertex3f(1.0f - Delta, -1.0, 0.0);
	glVertex3f(-1.0, -1.0 + Delta, 0.0);
	glVertex3f(1.0, 1.0 - Delta, 0.0);
	
	glEnd();
	glutSwapBuffers();


}
void MyTimmer(int value)
{
	static bool left= true;
	static int bosu=1;

	Delta += (bosu * 0.01);

	if (Delta >= 2.0f || Delta <= 0.0f)
	{
		left = !left;
		bosu *= -1;

		
		Index >= 7 ? Index = 0 : Index++;
	}


	glutPostRedisplay();
	glutTimerFunc(10, MyTimmer, 1);

}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);					//glut라이브러리 초기화 & 윈도우 os와 연결하여 하나의 세션 형성
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);				//윈도우 기본 컬러 모드를 rgb로 설정
	glutInitWindowSize(300, 300);				// 폭300 높이 300
	
	glutCreateWindow("OpenGL Drawing Example");
	glClearColor(0.0, 0.0, 0.0, 1.0);			//초기화 색깔 지정

	glMatrixMode(GL_PROJECTION);				// 투상행렬 변환 대상으로
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);




	glutDisplayFunc(MyDisplay);
	glutTimerFunc(10, MyTimmer, 1);
	glutMainLoop();
	return 0;
}