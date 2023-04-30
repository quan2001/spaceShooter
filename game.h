#ifndef GAME_H
#define GAME_H
#include "enemy.h"
#include <vector>
#include "hitbox.h"

class game{
    
    public:

        std::vector<Enemy*> enemyList;
        int score;
        int timeRemaining;
        int timeBoss;
        int timeMid;
        int timeSmall;
        int currentTime,previousTime;



        
        void addSmallEnemy(float x, float y){
            enemyList.push_back(new smallEnemy(x,y,0.04f,0.04f));
        }
        void addMidEnemy(float x, float y){
            enemyList.push_back(new mediumEnemy(x,y,0.2f,0.2f));
        }
        void addBoss(float x, float y){
            enemyList.push_back(new boss(x,y,0.4f,0.4f));
        }
        // game screen is -1 to 1 on x direction
        void gameStart(){
            int i;
            float x,y;
            x = -0.9f;
            y = 0.3f;
            float j= 0.0f;
            for(i=0;i<10;i++){
                addSmallEnemy(x+j,y);
                j = j + 0.1f;
            }
            //addBoss(-0.03f,0.5f);
        }
        std::vector<Enemy*>& getList(){
            return enemyList;
        }
        game(){
            score = 0;
            timeRemaining = 30;
            timeBoss = 0;
            timeMid = 0;
            timeSmall = 0;
            currentTime = 0;
            previousTime = 0;
        }
        void gameState(){
            
        }
        void move(){
            int i = 0;
            for(i=0;i<enemyList.size();i++){
                enemyList[i]->update();
            }
        }
        
        void checkIfDead(Enemy* enemyPtr ){
            if(enemyPtr->getHp() == 0){
                score = score + enemyPtr->incScore();
                enemyList.erase(std::remove(enemyList.begin(), enemyList.end(), enemyPtr), enemyList.end());
                delete enemyPtr;
                
            }
        }
        void updateTime(){
            int Time = currentTime-previousTime;
            timeBoss = timeBoss+ Time;
            timeMid = timeMid + Time;
            timeSmall = timeSmall + Time;
        }
        void printCurrentPreviousTime(){
            std::cout << "CurrentTime: " << currentTime << " previousTime: " << previousTime << std::endl;
        }
        void printTime(){
            std::cout << "timeSmall: " << timeSmall << " timeMid: " << timeMid << " boss: " << timeBoss << std::endl;
        }
        
        /*
        bool gameEnd(){
            if(enemyList.size() == 0){
                return true;
            }
        }
        */
        
        
};

#endif 
