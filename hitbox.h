#ifndef HITBOX_H
#define HITBOX_H

class Hitbox {
private:
    float x, y, width, height;

public:
    Hitbox(){

    }

    Hitbox(float x, float y, float width, float height){
        this->x = x;
        this->y = y;
        this-> width = width;
        this->height = height;
    }
    ~Hitbox(){

    }
    bool intersectBox(float pointX) {
        //std::cout << "pointX: " << pointX << std::endl;
        //std::cout << "x: " << x <<  std::endl;
         if(pointX >= x && pointX <= x+width){
            std::cout << "hit: "  ;
            return true;
        }
        return false;
    }
    float getX(){
        return x;
    }
    float getY(){
        return y;
    }
    float getWidth(){
        return width;
    }
    float getHeight(){
        return height;
    }
    void updateHitBox(float x, float y, float width, float height){
        this->x = x;
        this->y = y;
        this-> width = width;
        this->height = height;
    }
};

#endif
