#include <glut.h>

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);					//������ ���۸� �ʱ�ȭ �ʱ�ȭ�� ���� ���� glcearcolor���� ������ ��
	
	glColor3f(1.0, 0.0, 0.0);//���

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
	glViewport(0, 0, NewWidth, NewHeight);		//����Ʈ ����
	float widthF  = NewWidth / 300.0f;			//������ ��
	float heightF = NewHeight / 300.0f;			//������ ����
	
	glMatrixMode(GL_PROJECTION);				// ������� ��ȯ �������
	glLoadIdentity();
	glOrtho(-1.0 * widthF , 1.0 * widthF , -1.0 * heightF, 1.0 * heightF, -1.0, 1.0);	
	//glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);//���� ���� ���� (-1.0 ~ 1.0,-1.0 ~ 1.0,-1.0 ~ 1.0)���� ������ ����

}
int main(int argc,char ** argv)
{
	glutInit(&argc, argv);						//glut���̺귯�� �ʱ�ȭ & ������ os�� �����Ͽ� �ϳ��� ���� ����
	glutInitDisplayMode(GLUT_RGB);				//������ �⺻ �÷� ��带 rgb�� ����
	glutInitWindowSize(300, 300);				// ��300 ���� 300
	glutInitWindowPosition(0, 0);				// �������� �ü���� ȭ�� ��ǥ��� 0,0�� ��ġ
	glutCreateWindow("OpenGL Drawing Example");
	glClearColor(0.0, 0.0, 0.0, 1.0);			//�ʱ�ȭ ���� ����
	
	glutReshapeFunc(MyReshape);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}