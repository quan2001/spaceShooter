#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>

#include <cstdlib> 

class Enemy {
private:
    
    
public:
    float pointX;
    float pointY;
    float width;
    float height;
    float speed;
    int hp;
    int direction=0;
    virtual ~Enemy() {}
    virtual void draw() = 0;
    virtual int incScore() = 0;
    void reduceHp(){
        hp = hp -1;
    }

    bool isHit(float x,float y) {
        if(x>=pointX && x <= pointX+width && pointY >= y){
            return true;
        }
        return false;
    }

    int getHp(){
        return hp;
    }

        void wkey(){
        if(pointY < .8f){
            pointY = pointY + speed;
        }
    }
    void skey(){
         if(pointY > -1.0f){
        pointY = pointY - speed;
        }
    }
    void akey(){
        if(pointX > -0.9f )
        pointX = pointX - speed;
    }
    
    void dkey(){
        if(pointX < .9f){
            pointX = pointX + speed;
        }
    }

    void move(int direction){
        if(direction == 1){
            wkey();
        }
        if(direction == 2){
            wkey();
            dkey();
            
        }
        if(direction == 3){
            dkey();
            
        }
        if(direction == 4){
            dkey();
            skey();
        }
        if(direction == 5){
            skey();
            
        }
        if(direction == 6){
            skey();
            akey();
            
        }
        if(direction == 7){
            akey();
            
        }
        if(direction == 8){
            akey();
            wkey();
        }
        
    }

    void update(){
        if (rand() % 20==0)
            direction = (rand() % 8)+1; //make random number 1-8
        
        move(direction);
    }
};

class smallEnemy : public Enemy {

public:
    smallEnemy(float x, float y,float width, float height){
            this->pointX = x;
            this->pointY = y;
            this->width = width;
            this->height = height;
            this->speed=  0.0055f;
            hp = 1;
    }
    ~smallEnemy(){
        std::cout << "small enemy destory" << std::endl;
    }
    int incScore(){
        return 1;
    }
    void draw(){
        glColor3f(1.0f, 0.0f, 0.0f); // red

        // Draw the square
        glBegin(GL_QUADS);
            glVertex2f(pointX, pointY);           // bottom-left
            glVertex2f(pointX + width, pointY);  // bottom-right
            glVertex2f(pointX+ width, pointY + height);  // top-right
            glVertex2f(pointX, pointY + height);  // top-left
        glEnd();
    }
    
    
    
    //HitBox getHitBox() const;
private:
    
};

class mediumEnemy : public Enemy {

public:
    mediumEnemy(float x, float y,float width, float height){
            this->pointX = x;
            this->pointY = y;
            this->width = width;
            this->height = height;
            this -> speed = 0.005f;
            hp = 3;
    }
    ~mediumEnemy(){
        std::cout << "destroy midEnemy" << std::endl;
    }
    int incScore(){
        return 3;
    }
    void draw(){
        

        glColor3f(0.0f, 0.0f, 1.0f);//blue
        glBegin(GL_POLYGON);
        glVertex3f(pointX, pointY+0.15f*hp/3, 0.0f);
        glVertex3f(pointX+-.03f*hp/3, pointY, 0.0f);
        glVertex3f(pointX+.03f*hp/3, pointY, 0.0f);
        glEnd();
        
        glColor3f(1.0f, 0.0f, 0.0f);//red
	    glBegin(GL_POLYGON);
        glVertex3f(pointX+-.03f*hp/3, pointY, 0.0f);
        glVertex3f(pointX+-.05f*hp/3, pointY+0.03f*hp/3, 0.0f);
        glVertex3f(pointX+.05f*hp/3, pointY+0.03f*hp/3, 0.0f);
        glVertex3f(pointX+.03f*hp/3, pointY, 0.0f);
        glEnd();
    }
    
};

class boss : public Enemy {
public:
    boss(float x, float y,float width, float height){
            this->pointX = x;
            this->pointY = y;
            this->width = width;
            this->height = height;
            hp = 10;
            this -> speed = 0.004f;
    }
   
    ~boss(){
       
        std::cout << "destroy boss" << std::endl;
    
    }
    int incScore(){
        return 10;
    }
    void draw(){
       glColor3f(1.0f, 0.0f, 0.0f);//red
        glBegin(GL_POLYGON);
        glVertex3f(pointX, pointY+0.30f*hp/10, 0.0f);//center
        glVertex3f(pointX-0.1f*hp/10, pointY, 0.0f);//left
        glVertex3f(pointX+0.1f*hp/10, pointY, 0.0f);//right
        glEnd();

        glColor3f(1.0f, 1.0f, 1.0f);//white
	    glBegin(GL_POLYGON);
        glVertex3f(pointX-0.1f*hp/10, pointY, 0.0f);
        glVertex3f(pointX-0.16f*hp/10, pointY-0.06f*hp/10, 0.0f);
        glVertex3f(pointX+0.16f*hp/10, pointY-0.06f*hp/10, 0.0f);
        glVertex3f(pointX+0.1f*hp/10, pointY, 0.0f);
        glEnd();

        glColor3f(2.0f, 0.5f, 1.0f);//Lilac
        glBegin(GL_POLYGON);
        glVertex3f(pointX-0.16f*hp/10, pointY-0.06f*hp/10, 0.0f);
        glVertex3f(pointX-0.16f*hp/10, pointY-0.09f*hp/10, 0.0f);
        glVertex3f(pointX+0.16f*hp/10, pointY-0.09f*hp/10, 0.0f);
        glVertex3f(pointX+0.16f*hp/10, pointY-0.06f*hp/10, 0.0f);
        glEnd();

        glColor3f(0.6f, 0.3f, 0.0f);//Brown
        glBegin(GL_POLYGON);
        glVertex3f(pointX-0.05f*hp/10, pointY+-0.09f*hp/10, 0.0f);
        glVertex3f(pointX-0.05f*hp/10, pointY+-0.13f*hp/10, 0.0f);
        glVertex3f(pointX-0.15f*hp/10, pointY+-0.13f*hp/10, 0.0f);
        glVertex3f(pointX-0.15f*hp/10, pointY+-0.09f*hp/10, 0.0f);
        glEnd();

        glColor3f(0.6f, 0.3f, 0.0f);//Brown
        glBegin(GL_POLYGON);
        glVertex3f(pointX+0.05f*hp/10, pointY+-0.09f*hp/10, 0.0f);
        glVertex3f(pointX+0.05f*hp/10, pointY+-0.13f*hp/10, 0.0f);
        glVertex3f(pointX+0.15f*hp/10, pointY+-0.13f*hp/10, 0.0f);
        glVertex3f(pointX+0.15f*hp/10, pointY+-0.09f*hp/10, 0.0f);
        glEnd();

        glColor3f(1.0f, 1.0f, 0.0f);//white
        glBegin(GL_POLYGON);
        glVertex3f(pointX-0.10f*hp/10, pointY+-0.39f*hp/10, 0.0f);
        glVertex3f(pointX-0.05f*hp/10, pointY+-0.13f*hp/10, 0.0f);
        glVertex3f(pointX-0.15f*hp/10, pointY+-0.13f*hp/10, 0.0f);
        glEnd();

        glColor3f(1.0f, 1.0f, 0.0f);//white
        glBegin(GL_POLYGON);
        glVertex3f(pointX+0.1f*hp/10, pointY+-0.39f*hp/10, 0.0f);
        glVertex3f(pointX+0.05f*hp/10, pointY+-0.13f*hp/10, 0.0f);
        glVertex3f(pointX+0.15f*hp/10, pointY+-0.13f*hp/10, 0.0f);
        glEnd();
    }
    
    

};

#endif // ENEMY_H
