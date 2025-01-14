#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen

    glBegin(GL_TRIANGLES); // Start drawing a triangle
        glColor3f(1.0, 0.0, 0.0); // Red
        glVertex2f(-0.5, -0.5);   // Vertex 1
        glColor3f(0.0, 1.0, 0.0); // Green
        glVertex2f(0.5, -0.5);    // Vertex 2
        glColor3f(0.0, 0.0, 1.0); // Blue
        glVertex2f(0.0, 0.5);     // Vertex 3
    glEnd();

    glFlush(); // Render now
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);                          // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // Set display mode
    glutInitWindowSize(800, 600);                   // Set window size
    glutCreateWindow("OpenGL Example");             // Create window

    glClearColor(0.0, 0.0, 0.0, 1.0); // Set background color (black)

    glutDisplayFunc(display); // Set display callback
    glutMainLoop();           // Enter the event-processing loop

    return 0;
}
