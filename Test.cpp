#include <GL/freeglut.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "hitbox.h"
#include "enemy.h"
#include "player.h"
#include <vector>
#include "game.h"
using namespace std;

// Define the keyboard callback function

game space;


player shooter(0.01f,0.01f,0.04f);
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
            shooter.print();
           // glutPostRedisplay();
        }
        if (key == 'a'){
            shooter.a_pressed = true;
            shooter.print();
          //  glutPostRedisplay();
        }
        if (key == 's'){
            shooter.s_pressed = true;
            shooter.print();
           // glutPostRedisplay();
        }
        if ( key == 'd'){
            shooter.d_pressed = true;
            shooter.print();
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
    updatePlayer();
    shooter.drawTriangle();

   int i;
   //cout << space.enemyList.size() << endl;
   for(i=0;i<space.enemyList.size();i++){
    space.enemyList[i]->draw();
    //cout << i << endl
    
   }
   
   glutSwapBuffers();
   
}
void idle() {
    int i;
    
    for(i = 0;i<(space.getList()).size();i++){
        space.checkIfDead(space.getList()[i]);
    }
    space.move();
    if(space.gameEnd()){
        exit(0);
    }
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
    
    

    // Enter the main loop
    glutMainLoop();
    return 0;
}
