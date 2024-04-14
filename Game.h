#pragma once
#include "Hero.h"
#include "Game.h"
#include <GLFW/glfw3.h>
#include <chrono>
#include "GameEngine.h"
#include <iostream>
#include "Block.h"
#include "Point.h"
#include <vector>
#include <string>
class Game
{
public:
	Hero* hero;
	void Update(int WinWidth, int WinHeight);
    std::vector<Block*>* level = new std::vector<Block*>();
	std::chrono::time_point<std::chrono::high_resolution_clock> TimeBuffer;
	GameEngine* ge;
	Game() {
		this->hero = new Hero("sprite.png");
		//start = clock();
		//dt = std::chrono::high_resolution_clock::now();
        //level->push_back(new Block(new Point(100, 320), 200, 100));        
        //level->push_back(new Block(new Point(300, 140), 100, 25));
        //level->push_back(new Block(new Point(481, 140), 100, 25));
        //level->push_back(new Block(new Point(300, 200), 100, 25));
        CreateLevel();
		this->ge = new GameEngine(hero, level);
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



    void CreateLevel() {
        std::string StringLevel[12];
        StringLevel[0] = "bbbbbbbbbbbbbbbb";
        StringLevel[1] = "b00000000000000b";
        StringLevel[2] = "b00000000000000b";
        StringLevel[3] = "b00000000000000b";
        StringLevel[4] = "b00000000000000b";
        StringLevel[5] = "b00000000000000b";
        StringLevel[6] = "b00000000000000b";
        StringLevel[7] = "b000000000bbb00b";
        StringLevel[8] = "b00000000000000b";
        StringLevel[9] = "b00000000000000b";
       StringLevel[10] = "b00000000000000b";
       StringLevel[11] = "bbbbbbbbbbbbbbbb";
        int y_coord = 0;
        for (int i = 0; i < 12; i++)
        {
            int x_coord = 0;
            for (int j = 0; j < 16; j++)
            {
                if (StringLevel[i].at(j) == 'b')
                {
                    this->level->push_back(new Block(new Point(x_coord, y_coord), 40, 40));
                }
                x_coord += 40;
            }
            y_coord += 40;
        }
    }
};

