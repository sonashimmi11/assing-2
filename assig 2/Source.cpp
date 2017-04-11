#include<GL\glut.h>
#include<iostream>
#include <vector>
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
			glPointSize(55);
	
	glBegin(GL_POINTS);

			glColor3f(0, 0, 1);
			for (int i = 0; i < points.size(); i++)
				glVertex2i(points[i].x, points[i].y);



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
