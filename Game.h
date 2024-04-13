#pragma once
#include "Hero.h"
#include "Game.h"
#include <GLFW/glfw3.h>
#include <chrono>
#include "GameEngine.h"
#include <iostream>
class Game
{
public:
	Hero* hero;
	void Update(int WinWidth, int WinHeight);
	std::chrono::time_point<std::chrono::high_resolution_clock> TimeBuffer;
	GameEngine* ge;
	Game() {
		this->hero = new Hero("sprite.png");
		//start = clock();
		//dt = std::chrono::high_resolution_clock::now();
		this->ge = new GameEngine(hero);
	}
	void LogicForHero(Hero* hero);



    void key_callback(int key, int scancode, int action) {
        if (action == GLFW_PRESS || action == GLFW_RELEASE) {
            switch (key) {
            case GLFW_KEY_W:
                if (action == GLFW_PRESS)
                {
                    std::cout << "Key W was pressed." << std::endl;
                    this->ge->physhero->Jump = true;
                    
                }
                else if (action == GLFW_RELEASE)
                {
                    //std::cout << "Key W was released." << std::endl;
                    this->ge->physhero->Jump = false;
                }
                break;
            case GLFW_KEY_A:
                if (action == GLFW_PRESS)
                {
                    //std::cout << "Key A was pressed." << std::endl;
                    this->ge->physhero->MoveLeft = true;
                    this->hero->MoveXdirection -= 1;
                    this->hero->direction = -1;
                }
                else if (action == GLFW_RELEASE)
                {
                    this->ge->physhero->MoveLeft = false;
                    this->hero->MoveXdirection += 1;
                //std::cout << "Key A was released." << std::endl;
                }
                break;
            case GLFW_KEY_S:
                if (action == GLFW_PRESS)
                {
                    std::cout << "Key S was pressed." << std::endl;

                }
                else if (action == GLFW_RELEASE)
                    std::cout << "Key S was released." << std::endl;
                break;
            case GLFW_KEY_D:
                if (action == GLFW_PRESS)
                {
                    this->ge->physhero->MoveRight = true;
                    this->hero->MoveXdirection += 1;
                    this->hero->direction = 1;
                    //std::cout << "Key D was pressed." << std::endl;

                }
                else if (action == GLFW_RELEASE)
                {

                    this->ge->physhero->MoveRight = false;
                    this->hero->MoveXdirection -= 1;
                    
                    //std::cout << "Key D was released." << std::endl;
                }
                break;
            }
        }
    }
};

