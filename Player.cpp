#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPos.setObjPos(5,10,'A');
    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
   returnPos.setObjPos(playerPos.x,playerPos.y,playerPos.symbol);
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
  switch(mainGameMechsRef->getInput()) {
    case 'w':
                if(myDir!=DOWN) {
                    myDir = UP;
                }
                break;

            case 's':
                if(myDir!=UP) {
                    myDir = DOWN;
                }
                break;

            case 'a':
                if(myDir!=RIGHT) {
                    myDir = LEFT;
                }
                break;

            case 'd':
                if(myDir!=LEFT) {
                    myDir = RIGHT;
                }
                break;
            default:
                break;
  } 
    // PPA3 input processing logic        
}

void Player::movePlayer()
{
switch(myDir) {
    case UP:
        if(playerPos.x == 0) {
            playerPos.x = mainGameMechsRef->getBoardSizeX()-1;
        }
        playerPos.x --;
        break;

    case DOWN:
        if(playerPos.x == mainGameMechsRef->getBoardSizeX()-1) {
            playerPos.x = 0;
        }
        playerPos.x ++;
        break;

    case LEFT:
        if(playerPos.y == 0) {
            playerPos.y = mainGameMechsRef->getBoardSizeY()-1;
        }
        playerPos.y --;
        break;

    case RIGHT:
        if(playerPos.y == mainGameMechsRef->getBoardSizeY()-1) {
            playerPos.y = 0;
        }
        playerPos.y ++;
        break;
    default:
        break;
}   
    // PPA3 Finite State Machine logic
}

