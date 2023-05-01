#ifndef PLAYER_H
#define PLAYER_H

#include "game.h"
#include "enemy.h"


#include <iostream>

class player{
    public:
        bool w_pressed;
        bool d_pressed;
        bool s_pressed;
        bool a_pressed;
        bool isLaser;
        bool enter_pressed;
        float pointX;
        float pointY;
        float length;
        const float speed = 0.0015f*3.0f;
         
        player(float pointX,float pointY, float length){
            this->pointX = pointX;
            this->pointY = pointY;
            this->length= length;
            w_pressed = false;
            d_pressed = false;
            s_pressed = false;
            a_pressed = false;
            isLaser = false;
            enter_pressed = false;

            
            
        }
        
        void shoot(std::vector<Enemy*> list){
            float width = pointX+(length/2.0f);
            int i;
            bool isHit=false;
            for(i=0;i<list.size();i++){
                if(list[i]->isHit(width,pointY)){
                    list[i]->reduceHp();
                    isHit=true;
                }
            }
            if (!isHit) {
                std::cout <<"player:" << width << " "<<pointY<<std::endl;
                for(i=0;i<list.size();i++){
                    Enemy* e=list[i];
                    std::cout <<"enemy:" << e->pointX << " "<<e->pointY<<" "<<e->width<<std::endl;
                }
            }

        }

        ~player(){
            std::cout << "player destory" << std::endl;
        }
        float getX(){
            return pointX;
        }
        float getY(){
            return pointY;
        }
        float getlength(){
            return length;
        }
        void drawTriangle(){
             glColor3f(1.0f, 0.0f, 1.0f);//Purple
    glBegin(GL_POLYGON);
        glVertex3f(pointX, pointY, 0.00f);
        glVertex3f(pointX+-.05f, pointY-0.136f, 0.0f);
        glVertex3f(pointX+.05f, pointY-0.136f, 0.0f);
    glEnd();
    glColor3f(0.5f, 0.5f, 0.5f);//Violet
	 glBegin(GL_POLYGON);
        glVertex3f(pointX+-.05f, pointY-0.136f, 0.0f);
        glVertex3f(pointX+-.08f, pointY+-0.166f, 0.0f);
        glVertex3f(pointX+.08f, pointY-0.166f, 0.0f);
        glVertex3f(pointX+.05f, pointY-0.136f, 0.0f);
    glEnd();
        glColor3f(2.0f, 0.5f, 1.0f);//Lilac
        glBegin(GL_POLYGON);
        glVertex3f(pointX+-.08f, pointY-0.166f, 0.0f);
        glVertex3f(pointX+-.08f, pointY-0.196f, 0.0f);
        glVertex3f(pointX+.08f, pointY-0.196f, 0.0f);
        glVertex3f(pointX+.08f, pointY-0.166f, 0.0f);
    glEnd();
       glColor3f(0.0f, 0.5f, 1.0f);//baby Blue
    glBegin(GL_POLYGON);
        glVertex3f(pointX+-.07f, pointY-0.196f, 0.0f);
        glVertex3f(pointX+-.07f, pointY-0.216f, 0.0f);
        glVertex3f(pointX+-.03f, pointY-0.216f, 0.0f);
        glVertex3f(pointX+-.03f, pointY-0.196f, 0.0f);
    glEnd();
        glColor3f(0.0f, 0.5f, 1.0f);//baby Blue
    glBegin(GL_POLYGON);
        glVertex3f(pointX+.07f, pointY-0.196f, 0.0f);
        glVertex3f(pointX+.07f, pointY-0.216f, 0.0f);
        glVertex3f(pointX+.03f, pointY-0.216f, 0.0f);
        glVertex3f(pointX+.03f, pointY-0.196f, 0.0f);
    glEnd();
        glColor3f(0.5f, 1.0f, 1.0f);//cyan
    glBegin(GL_POLYGON);
        glVertex3f(pointX+.05f, pointY-0.286f, 0.0f);
        glVertex3f(pointX+.07f, pointY-0.216f, 0.0f);
        glVertex3f(pointX+.03f, pointY-0.216f, 0.0f);
    glEnd();
        glColor3f(0.5f, 1.0f, 1.0f);//cyan
    glBegin(GL_POLYGON);
        glVertex3f(pointX+-.05f, pointY-0.286f, 0.0f);
        glVertex3f(pointX+-.07f, pointY-0.216f, 0.0f);
        glVertex3f(pointX+-.03f, pointY-0.216f, 0.0f);
    glEnd();
        glColor3f(0.0f, 0.1f, 0.1f);//Dark blue
    glBegin(GL_POLYGON);
        glVertex3f(pointX+-0.01f, pointY-0.066f, 0.0f);
        glVertex3f(pointX+-0.01f, pointY-0.126, 0.0f);
        glVertex3f(pointX+0.01f, pointY-0.126, 0.0f);
        glVertex3f(pointX+0.01f, pointY-0.066f, 0.0f);
    glEnd();
    if(isLaser)
    {
        glColor3d(1,1,1);
        glLineWidth(5);
        glBegin(GL_LINES);
            glVertex3f(pointX,pointY, 0.0f);
            glVertex3f(pointX, 1, 0.0f);
        glEnd();
    }
    

        }
        void print(){
            std::cout << "X: " << pointX << "Y: " << pointY << std::endl;
        }
        void wkey(){
            if(pointY < 0.98f){
                pointY = pointY + speed;
            }
        }
        void skey(){
            if(pointY > -1.0f){
                pointY = pointY - speed;
            }
        }
        void akey(){
            if(pointX >-1.0f){
                pointX = pointX - speed;
            }
        }
        void dkey(){
            if(pointX <0.98f){
                pointX = pointX + speed;
            }
        }
        void wdkey(){
            dkey();
            wkey();
        }
};

#endif 
