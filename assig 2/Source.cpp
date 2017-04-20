#include<GL\glut.h>
#include<iostream>
#include <vector>
#include<math.h>
struct point {
	int   x,y;
	point() {};

	point(int init_val, int init_id)
	{
		x = init_val;
		y = init_id;
	}

};
//typedef point int[2];
int size[]={640,480}; 
std::vector<point> points;
//GLfloat v[4][2];
GLint  obj[5];
int static count=0;
bool handle=false;
/*
class ver_handle {
public:
	GLfloat ver[1];
	void cross() {
		glBegin(GL_LINES);
		glColor3f(1, 0, 0);
		//	glVertex2f(15, 15);
		glVertex2f(ver[0] + 15, 480 - (ver[1] + 15));
		//std::cout << v[0][0] << " " << v[0][1];
		//	glVertex2f(0, 0);
		glVertex2f(ver[0] - 15, 480 - (ver[1] - 15));
		glEnd();
		glBegin(GL_LINES);
		glColor3f(1, 0, 0);
		//	glVertex2f(15, 15);
		glVertex2f(ver[0] - 15, 480 - (ver[1] + 15));
		//std::cout << v[0][0] << " " << v[0][1];
		//	glVertex2f(0, 0);
		glVertex2f(ver[0] + 15, 480 - (ver[1] - 15));
		glEnd();
	}
};*/



void click_handle(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state==GLUT_DOWN) {


		//ver_handle *a;
		//a = new ver_handle;

		points.push_back(point(x, size[1] - y));
		//v[count][0] = x;
		//v[count][1] =size[1]- y;
		handle = true;
		count++;
		
	}
}

void init() {
	glClearColor(1, 1, 1, 1);
	gluOrtho2D(0, 640, 0, 480);

	glFlush();
}

void render() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5);
	// points
	glBegin(GL_POINTS);

	glColor3f(0, 0, 1);
	for (int i = 0; i < points.size(); i++)
		glVertex2i(points[i].x, points[i].y);



	glEnd();
	//rectangle drawing
	glBegin(GL_LINES);

	glColor3f(1, 0, 1);
	//if (points.size() % 2== 0)
	for (int i = 0; (i + 1) < points.size(); i = i + 2)

	{
		//drawing first line
		glVertex2i(points[i].x, points[i].y);
		glVertex2i(points[i + 1].x, points[i].y);
		//second line
		glVertex2i(points[i + 1].x, points[i].y);
		glVertex2i(points[i + 1].x, points[i + 1].y);
		//third line
		glVertex2i(points[i + 1].x, points[i + 1].y);
		glVertex2i(points[i].x, points[i + 1].y);
		//fourth line
		glVertex2i(points[i].x, points[i + 1].y);
		glVertex2i(points[i].x, points[i].y);



	}


	glEnd();
	//lines
	glBegin(GL_LINES);

	glColor3f(1, 1, 0);
	//if (points.size() % 2== 0)
	for (int i = 0; (i + 1) < points.size(); i = i + 2)

	{

		glVertex2i(points[i].x, points[i].y);
		glVertex2i(points[i + 1].x, points[i + 1].y);
	}
	glEnd();
	//polygon

	glBegin(GL_LINE_LOOP);

	glColor4f(0, 0, 0,0.1);
	//if (points.size() % 2== 0)
	for (int i = 0; i < points.size();  i++)

	{

		glVertex2i(points[i].x, points[i].y);
	}
	glEnd();

	//circle
	glBegin(GL_LINES);

	glColor3f(0, 1, 0);
	int segments = 100;
	float angle = 2*3.14/ segments;

	for (int i = 0; (i + 1) < points.size(); i = i + 2)
	{

		point p1(points[i + 1].x, points [i + 1].y);
		point p2(0, 0);

		float radius = sqrtf((p1.x - points[i].x)*(p1.x - points[i].x) + (p1.y - points[i].y)*(p1.y - points[i].y));

		for (int j = 0; j < segments; j++)
		{
			p1.x = (radius*cosf(j*angle) + points[i].x);
			p1.y = (radius*sin(j*angle) + points[i].y);
			p2.x = (radius*cosf((j+1)*angle) + points[i].x);
			p2.y = (radius*sin((j+1)*angle) + points[i].y);
			glVertex2i(p1.x, p1.y);
			glVertex2i(p2.x, p2.y);
		
		}
    }
	


	glEnd();

	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(size[0],size[1]);
	glutCreateWindow("DRAW PRI");
	init();
	glutDisplayFunc(render);
    glutMouseFunc(click_handle);
	glutMainLoop();
	return 0;
}
