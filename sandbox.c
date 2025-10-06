// Compile with:
// clear; gcc sandbox.c ./fge/*.c -o sandbox -lglfw -lGL -lX11 -lXrandr -lXi -lm

#include <GLFW/glfw3.h>
#include <stdio.h>

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(320*4, 200*4, "Foenix", NULL, NULL);
    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    glViewport(0, 0, 320*4, 200*4);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 320*4, 200*4, 0, -10, 10);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.75f, 0.75f, 1.75f, 1.0f); // Red, Green, Blue, Alpha

        glClear(GL_COLOR_BUFFER_BIT);

        //glBegin(GL_POINTS);
        //    glColor3f(0.0, 0.0, 0.0);
        //    glVertex2i(50, 50);
        //glEnd();

        glBegin(GL_QUADS);
            glColor3f(1, 0, 0);
            glVertex2f(10, 10);
            glVertex2f(10, 20);
            glVertex2f(30, 20);
            glVertex2f(30, 10);       
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();
    return 0;
}

