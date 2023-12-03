#include "Food.h"

Food::Food(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    srand(time(nullptr));
    foodPos.setObjPos(-1,-1,'o');
}

void Food::generateFood(objPos blockOff)
{
    do
    {  
        foodPos.x = rand() % mainGameMechsRef->getBoardSizeX();
        foodPos.y = rand() % mainGameMechsRef->getBoardSizeY();
        
    } while (blockOff.isPosEqual(&foodPos)|| foodPos.y == 0 || foodPos.y == (mainGameMechsRef->getBoardSizeY()-1) || foodPos.x == 0 || foodPos.x == (mainGameMechsRef->getBoardSizeX()-1));
    
}

void Food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos);
}
