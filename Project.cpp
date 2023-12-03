#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs* myGM;
Food* myFood;
objPos tempPos(10, 10, '*');


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs(36,18); 
    myFood = new Food(myGM);
    myFood->generateFood(tempPos);
} 

void GetInput(void)
{

}

void RunLogic(void)
{
    
    if (myGM->getInput() == ' ')
    {
        myGM->setExitTrue();
    }
    
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   
    objPos newfood;
    myFood->getFoodPos(newfood);
    MacUILib_printf("game board x:%d game board y:%d\ninput: %c score: %d\n", myGM->getBoardSizeX(), myGM->getBoardSizeY(), myGM->getInput(), myGM->getScore()); 
    for (int y = 0; y < myGM->getBoardSizeY(); y++)
    {
        for (int x = 0; x < myGM->getBoardSizeX(); x++)
        {
            if (y == 0 || y == (myGM->getBoardSizeY()-1) || x == 0 || x == (myGM->getBoardSizeX()-1))
            {
                MacUILib_printf("#");
            }
            else if (y == tempPos.y && x == tempPos.x)
            {
                MacUILib_printf("%c", tempPos.symbol);
            }
            else if (y == newfood.y && x == newfood.x)
            {
                MacUILib_printf("%c", newfood.symbol);
            }
            else 
            {
                MacUILib_printf(" ");
            }

        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("\nfood x:%d\tfood y:%d\n", newfood.x,newfood.y);
}


void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();

    delete myGM;
    delete myFood;
}
