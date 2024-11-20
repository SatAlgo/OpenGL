// Draw a color cube and spin it using OpenGL transformation matrices.


// Draw a color cube and spin it using OpenGL transformation matrices.


#include <GL/glut.h>
#include <math.h>

GLfloat v0[] = { -0.5, -0.5, -0.5 };
GLfloat v1[] = { 0.5, -0.5, -0.5 };
GLfloat v2[] = { 0.5, 0.5, -0.5 };
GLfloat v3[] = { -0.5, 0.5, -0.5 };
GLfloat v4[] = { -0.5, 0.5, 0.5 };
GLfloat v5[] = { -0.5, -0.5, 0.5 };
GLfloat v6[] = { 0.5, -0.5, 0.5 };
GLfloat v7[] = { 0.5, 0.5, 0.5 };

GLfloat angle = 0.0;


void rotateCube()
{
    GLfloat radian_angle = angle * M_PI / 180.0;
    //GLfloat radian_angle = angle;

    GLfloat rotation_matrix[] =
    {
        cos(radian_angle), -sin(radian_angle), 0.0, 0.0,
        sin(radian_angle), cos(radian_angle), 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0
    };

    glMultMatrixf(rotation_matrix);
}

void drawCube()
{

    rotateCube();

    // Front face
    glBegin(GL_QUADS); // Define a quadrilateral
    glColor3f(1.0, 0.0, 0.0); // Set color to red
    glVertex3fv(v0);          // Bottom-left
    glVertex3fv(v1);          // Bottom-right
    glVertex3fv(v2);          // Top-right
    glVertex3fv(v3);          // Top-left
    glEnd();

    // Right face
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0); // Set color to green
    glVertex3fv(v1);          // Bottom-left
    glVertex3fv(v6);          // Bottom-right
    glVertex3fv(v7);          // Top-right
    glVertex3fv(v2);          // Top-left
    glEnd();

    // Top face
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0); // Set color to blue
    glVertex3fv(v3);          // Bottom-left
    glVertex3fv(v2);          // Bottom-right
    glVertex3fv(v7);          // Top-right
    glVertex3fv(v4);          // Top-left
    glEnd();

    // Back face
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0); // Set color to yellow
    glVertex3fv(v5);          // Bottom-left
    glVertex3fv(v6);          // Bottom-right
    glVertex3fv(v7);          // Top-right
    glVertex3fv(v4);          // Top-left
    glEnd();

    // Left face
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0); // Set color to cyan
    glVertex3fv(v0);          // Bottom-left
    glVertex3fv(v5);          // Bottom-right
    glVertex3fv(v4);          // Top-right
    glVertex3fv(v3);          // Top-left
    glEnd();

    // Bottom face
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 1.0); // Set color to magenta
    glVertex3fv(v0);          // Bottom-left
    glVertex3fv(v1);          // Bottom-right
    glVertex3fv(v6);          // Top-right
    glVertex3fv(v5);          // Top-left
    glEnd();

}


void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);



    glLoadIdentity();
    glRotatef(45.0, 1.0, 1.0, 0.0);

    drawCube();

    angle += 0.1;

    glFlush();

    glutSwapBuffers();
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rotating Cube");
    glutDisplayFunc(displayMe);
    glutIdleFunc(displayMe); //for continuous animation
    glutMainLoop();
    return 0;
}
