// Write opengl program to scale the given object to double the size of any 2D object.


#include <iostream>
#include <GL/glut.h>

using namespace std;

// Original vertices of the triangle
float vertices[3][2];
float scaledVertices[3][2];

// Function to scale the object
void scaleObject(float scaleFactor)
{
    for (int i = 0; i < 3; i++)
    {
        scaledVertices[i][0] = vertices[i][0] * scaleFactor;
        scaledVertices[i][1] = vertices[i][1] * scaleFactor;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw original triangle in white
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 3; i++)
    {
        glVertex2f(vertices[i][0], vertices[i][1]);
    }
    glEnd();

    // Draw scaled triangle in red
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 3; i++)
    {
        glVertex2f(scaledVertices[i][0], scaledVertices[i][1]);
    }
    glEnd();

    glFlush();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -500, 500);
}

int main(int argc, char **argv)
{
    float scaleFactor = 2.0; // Scaling factor (double the size)

    cout << "Enter the coordinates of the 3 vertices of the triangle (x y):" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Vertex " << i + 1 << ": ";
        cin >> vertices[i][0] >> vertices[i][1];
    }

    // Scale the object
    scaleObject(scaleFactor);

    // Initialize OpenGL
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2D Object Scaling");
    init();

    // Display callback
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
