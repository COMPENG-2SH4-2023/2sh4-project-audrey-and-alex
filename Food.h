#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <ctime>

#include "GameMechs.h"
#include "objPos.h"

using namespace std;

class Food 
{
    private:
        objPos foodPos;

        GameMechs* mainGameMechsRef;

    public:
    Food(GameMechs* thisGMRef);

    void generateFood(objPos blockOff);
    void getFoodPos(objPos &returnPos);


};
#endif