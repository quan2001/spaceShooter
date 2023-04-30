#include <GL/freeglut.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "hitbox.h"
#include "enemy.h"
#include "player.h"
#include <vector>
#include "game.h"
#include <cstdlib> 
using namespace std;

// Define the keyboard callback function

game space;


player shooter(0.01f,0.01f,0.04f);
void countdown(int value) {
    if (space.timeRemaining> 0) {
        space.timeRemaining--;
        glutPostRedisplay();
        glutTimerFunc(1000, countdown, 0); // register the callback function again
    }
    int random_numberSmall = (rand() % 8)+1; //make random number 1-8
    int random_numberSmallY = (rand() % 8)+1;
    int random_numberMid = (rand() % 8)+1; //make random number 1-8
   //cout << "boss " << space.timeBoss <<endl;
    if(space.timeBoss>=20000){
        space.addBoss(-0.03f,0.5f);
        space.timeBoss -= 20000;
    }
    //cout << "midEnemy: " << space.timeMid <<endl;
    if(space.timeMid>=5000){
        space.addMidEnemy(-0.9f+(0.2*random_numberSmall),0.4f);
        space.timeMid -= 5000;

    }
    //cout << "smallEnemy: " << space.timeSmall <<endl;
    if(space.timeSmall>=2000){
        space.addSmallEnemy(-0.9f+(0.1*random_numberSmall),-0.9f+(0.1*random_numberSmall));
        space.timeSmall -= 2000;
    }
}

void keyboardCallback(unsigned char key, int x, int y) {
    // Handle the keyboard input

        if (key == 27) {
         
            exit(0); // Exit the program
            
        }
        if(key == 13){
            //shooter.enter_pressed = true;
            shooter.shoot(space.getList());
            //cout << "shooting" << endl;
        }
        if (key == 'f') {
            
            glutFullScreen();
            //glutPostRedisplay(); // maybe cause problems
        }
        if (key == 'w') {
            shooter.w_pressed = true;
            //shooter.print();
           // glutPostRedisplay();
        }
        if (key == 'a'){
            shooter.a_pressed = true;
            //shooter.print();
          //  glutPostRedisplay();
        }
        if (key == 's'){
            shooter.s_pressed = true;
            //shooter.print();
           // glutPostRedisplay();
        }
        if ( key == 'd'){
            shooter.d_pressed = true;
            //shooter.print();
            //glutPostRedisplay();
        }
        
            

    
}
void keyboardUpCallback(unsigned char key, int x, int y) {
    // Handle the keyboard input

        /*
        if(key == 13){
            shooter.enter_pressed = false;
            //shooter.shoot(space.getList());
            //cout << "shooting" << endl;
        }
        */
        
        if (key == 'w') {
            shooter.w_pressed = false;
            //shooter.print();
           // glutPostRedisplay();
        }
        if (key == 'a'){
            shooter.a_pressed = false;
            //shooter.print();
          //  glutPostRedisplay();
        }
        if (key == 's'){
            shooter.s_pressed = false;
            //shooter.print();
           // glutPostRedisplay();
        }
        if ( key == 'd'){
            shooter.d_pressed = false;
            //shooter.print();
            //glutPostRedisplay();
        }      

    
}
void updatePlayer() {
   
    if (shooter.w_pressed) { // move up
        shooter.wkey();
        //shooter.print();
    }
    if (shooter.s_pressed) { // move down
        shooter.skey();
       // shooter.print();
    }
    if (shooter.a_pressed) { // move left
        shooter.akey();
       //shooter.print();
    }
    if (shooter.d_pressed) { // move right
        shooter.dkey();
        //shooter.print();

    }
    /*
    if(shooter.enter_pressed){
        shooter.shoot(space.getList());
        
        //cout << "shooting" << endl;
    }
    */
}
void render(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    int len;
    if(space.timeRemaining <=0){
        glColor3f(1.0, 0.0, 0.0); // Set color to red
        glRasterPos2f(-0.01f,0.01f);
        char gameOverStr[] = "Game Over";
        int len = strlen(gameOverStr);
        for (int i = 0; i < len; i++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, gameOverStr[i]);
        }
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos2f(0.5f, -0.8f);
        char scoreStr[50];
        sprintf(scoreStr, "Score: %d", space.score);
        len = strlen(scoreStr);
        for (int i = 0; i < len; i++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, scoreStr[i]);
        }
        glutSwapBuffers();
    }else{
    
        space.previousTime = space.currentTime;
        space.currentTime = glutGet(GLUT_ELAPSED_TIME);
        
        space.updateTime();

        //space.printTime();
        updatePlayer();
        shooter.drawTriangle();

        int i;
        //cout << space.enemyList.size() << endl;
    
        for(i=0;i<space.enemyList.size();i++){
            space.enemyList[i]->draw();
            //cout << i << endl
            
        }
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos2f(0.5f, -0.8f);
        char scoreStr[50];
        sprintf(scoreStr, "Score: %d", space.score);
        len = strlen(scoreStr);
        for (int i = 0; i < len; i++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, scoreStr[i]);
        }
    // cout << space.timeRemaining << endl;
    glutSwapBuffers();
    }
   
}
void idle() {
    int i;
    
    for(i = 0;i<(space.getList()).size();i++){
        space.checkIfDead(space.getList()[i]);
    }
    space.move();
    /*
    if(space.timeRemaining <=0){
        //cout << space.score << endl;
        exit(0);
    }
    */
    glutPostRedisplay(); // Mark the window for redisplay
}


int main(int argc, char** argv) {
    space.gameStart();
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    // Initialize GLUT and create a window
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutCreateWindow("OpenGL Window");

    glutDisplayFunc(render);
    
    glutIdleFunc(idle);
    // Set the keyboard callback function
    glutKeyboardFunc(keyboardCallback);
    glutKeyboardUpFunc(keyboardUpCallback);
    glutTimerFunc(1000, countdown, 0);
    
    

    // Enter the main loop
    glutMainLoop();
    return 0;
}
