#include <GLFW/glfw3.h>
#include "button.h"
#include "textur.h"
#include <iostream>
#include "Game.h"
#include "Hero.h"
#include <chrono>
int WinWidth = 640, WinHeight = 480;
Button* Show;
Button* Start;
Button* Exit;
Button* Back;
Game* game;
int windowState = 0;

GLuint bg;

float vertex[] = { -0, -300, 300, -300, 300, 300 };



void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE); // Закрыть приложение при нажатии Escape
    else if (action == GLFW_PRESS || action == GLFW_RELEASE) {
        switch (key) {
        case GLFW_KEY_W:
            if (action == GLFW_PRESS)
            {
                std::cout << "Key W was pressed." << std::endl;
                game->hero->position->y -= 100;
            }
            else if (action == GLFW_RELEASE)
                std::cout << "Key W was released." << std::endl;
            break;
        case GLFW_KEY_A:
            if (action == GLFW_PRESS)
            {
                std::cout << "Key A was pressed." << std::endl;
                game->hero->MoveXdirection = -1;
                game->hero->direction = -1;
            }
            else if (action == GLFW_RELEASE)
                game->hero->MoveXdirection = 0;
                std::cout << "Key A was released." << std::endl;
            break;
        case GLFW_KEY_S:
            if (action == GLFW_PRESS)
            {
                std::cout << "Key S was pressed." << std::endl;
                game->hero->position->y += 10;
            }
            else if (action == GLFW_RELEASE)
                std::cout << "Key S was released." << std::endl;
            break;
        case GLFW_KEY_D:
            if (action == GLFW_PRESS)
            {
                std::cout << "Key D was pressed." << std::endl;
                game->hero->MoveXdirection = 1;
                game->hero->direction = 1;
            }
            else if (action == GLFW_RELEASE)
            {
                std::cout << "Key D was released." << std::endl;
                game->hero->MoveXdirection = 0;
            }
            break;
        }
    }
}


bool EventHandler(float x, float y, Button* btn) {
    return (x > (btn->Center->x - btn->width / 2)) && (x < (btn->Center->x + btn->width / 2)) &&
        (y > ((btn->Center->y) - (btn->height) / 2)) && (y < (btn->Center->y + btn->height / 2));
}
// Колбэк-функция для обработки события изменения размера окна
void framebuffer_size_callback(GLFWwindow* window, int new_width, int new_height) {
    WinWidth = new_width;
    WinHeight = new_height;
    glViewport(0, 0, new_width, new_height);
    glLoadIdentity();
    glOrtho(0, new_width, new_height, 0, 1, -1); //выставляем их как координаты окна
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    // Проверяем состояние окна
    switch (windowState) {
    case 0:
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
            if (EventHandler(xpos, ypos, Show)) {
                std::cout << "Button clicked: Show" << std::endl;
                windowState = 1;
            }
            if (EventHandler(xpos, ypos, Start)) {
                std::cout << "Button clicked: Start" << std::endl;
                windowState = 2;
            }
            if (EventHandler(xpos, ypos, Exit)) {
                std::cout << "Button clicked: Exit" << std::endl;
                glfwSetWindowShouldClose(window, GLFW_TRUE);
            }
        }
        break;

    case 1:
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
            if (EventHandler(xpos, ypos, Back)) {
                std::cout << "Button clicked: Back" << std::endl;
                windowState = 0;
            }
        }
        break;
    }
}

int main()
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); // обработчик изменения окна
    glfwSetMouseButtonCallback(window, mouse_button_callback); // обработчик нажатия мышки
    glfwSetKeyCallback(window, key_callback);
    glViewport(0, 0, WinWidth, WinHeight);
    glLoadIdentity();
    glOrtho(0, WinWidth, WinHeight, 0, 1, -1); //выставляем их как координаты окна


   



    char filename[] = "sprite.png";
    Load_Textur(filename, &bg, GL_CLAMP, GL_CLAMP, GL_NEAREST);
    /* Loop until the user closes the window */
    game = new Game();
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        if (windowState == 0) {
            glClear(GL_COLOR_BUFFER_BIT);
            glPushMatrix();
            //std::cout << WinWidth << " " << WinHeight << std::endl;
            char ShowS[] = "Show";
            char StartS[] = "Start";
            char ExitS[] = "Exit";
            Show = new Button(ShowS, 150, 50, new Point(WinWidth / 2, WinHeight / 2 - 60)); Show->Show();
            Start = new Button(StartS, 150, 50, new Point(WinWidth / 2, WinHeight / 2)); Start->Show();
            Exit = new Button(ExitS, 150, 50, new Point(WinWidth / 2, WinHeight / 2 + 60)); Exit->Show();
            /*glBegin(GL_TRIANGLES);
            glColor3f(1, 1, 1); glVertex2f(0, 0);
            glColor3f(1, 1, 1); glVertex2f(1, 1);
            glColor3f(1, 1, 1); glVertex2f(0.5, 1);
            glEnd();*/
            glPopMatrix();
        }
        if (windowState == 1) {
            glClear(GL_COLOR_BUFFER_BIT);

            glPushMatrix();
            glEnableClientState(GL_VERTEX_ARRAY);

            glVertexPointer(2, GL_FLOAT, 0, vertex);
            glDrawArrays(GL_TRIANGLES, 0, 6);

            glDisableClientState(GL_VERTEX_ARRAY);


            ShowBackground(bg);
            char ExitS[] = "Exit";
            Back = new Button(ExitS, 150, 50, new Point(WinWidth / 2, WinHeight / 2 + 120)); Back->Show();
            // IMAGE


            glPopMatrix();
        }
        if (windowState == 2) {
            glClear(GL_COLOR_BUFFER_BIT);


            game->Start(WinWidth, WinHeight);
            //Hero* hero = new Hero
            //char ExitS[] = "Exit";

            //Back = new Button(ExitS, 150, 50, new Point(WinWidth / 2, WinHeight / 2 + 120)); Back->Show();
            // IMAGE


        }
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}