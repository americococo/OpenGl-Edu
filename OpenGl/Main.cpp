#include <glut.h>

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);					//프레임 버퍼를 초기화 초기화에 사용될 색은 glcearcolor에서 설정한 색
	
	glColor3f(1.0, 0.0, 0.0);//흰색

	/*glutWireCube(0.5);
	glutWireSphere(0.5, 12, 20);*/

	//glutSolidTorus(0.2, 0.4, 300, 300);


	glBegin(GL_POLYGON);

	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);



	glEnd();
	glFlush();

}
void MyReshape(int NewWidth, int NewHeight)
{
	glViewport(0, 0, NewWidth, NewHeight);		//뷰포트 지정
	float widthF  = NewWidth / 300.0f;			//윈도우 폭
	float heightF = NewHeight / 300.0f;			//윈도우 높이
	
	glMatrixMode(GL_PROJECTION);				// 투상행렬 변환 대상으로
	glLoadIdentity();
	glOrtho(-1.0 * widthF , 1.0 * widthF , -1.0 * heightF, 1.0 * heightF, -1.0, 1.0);	
	//glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);//가시 부피 지정 (-1.0 ~ 1.0,-1.0 ~ 1.0,-1.0 ~ 1.0)까지 범위를 가짐

}
int main(int argc,char ** argv)
{
	glutInit(&argc, argv);						//glut라이브러리 초기화 & 윈도우 os와 연결하여 하나의 세션 형성
	glutInitDisplayMode(GLUT_RGB);				//윈도우 기본 컬러 모드를 rgb로 설정
	glutInitWindowSize(300, 300);				// 폭300 높이 300
	glutInitWindowPosition(0, 0);				// 윈도우의 운영체제의 화면 좌표계상 0,0에 위치
	glutCreateWindow("OpenGL Drawing Example");
	glClearColor(0.0, 0.0, 0.0, 1.0);			//초기화 색깔 지정
	
	glutReshapeFunc(MyReshape);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}