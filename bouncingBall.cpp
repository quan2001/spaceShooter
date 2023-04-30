#include <GL/freeglut.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

using namespace std;

void drawTriangle(float pointX,float pointY,float length){
    float width = pointX+(length/2.0f);
    //cout << width << " " << pointX;
    glColor3f( 0.5f, 0.0f, 0.5f );
    glBegin( GL_TRIANGLES );
        glVertex2f( pointX, pointY );
        glVertex2f( pointX+length, pointY );
        glVertex2f( width, pointY+length);
    glEnd();
    
    
}
void collisionTriangle(float pointX,float pointY,float& x,float& y){
    if(pointX <=-1.0f){
        x = 0.01;
    }
    if(pointX >= 1.0f){
        x = -0.01;
    }
    if(pointY <=-1.0f){
        y = 0.01;
    }
    if(pointY >= 1.0f){
        y = -0.01;
    }
}
void getKey(unsigned char key,int x, int y){
    cout << "getkey: " << key << endl; 
    if (key == 27){
        exit(0);
    }
    if(key == 'f'){
        glutFullScreen();
    }
    if (key == 'a'){
       // x = x -0.01;
    }
    if (key == 's'){
       // y = y - 0.01;
    }
    if (key == 'd'){
        //x = x + 0.01;
    }
    if (key == 'w'){
        //y = y + 0.01;
    }

}


//g++ bouncingBall.cpp -o Ball -framework glut -framework opengl -I /opt/homebrew/Cellar/freeglut/3.4.0/include/ -I /opt/homebrew/Cellar/glfw/3.3.8/include/  -framework IOKit -framework Cocoa -framework carbon -lglfw -L /opt/homebrew/lib 
int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(640, 480, "My OpenGL Window", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    
    // Make the window's context current
    glfwMakeContextCurrent(window);
    float x = 0.01f;
    float y = 0.01f;
    float i = 0;
    float j = 0;
    
    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)) {
        // Render here
        glClear(GL_COLOR_BUFFER_BIT);
        /*
        drawTriangle(0.01f+i,0.01f+j,0.04f);
        collisionTriangle(x0.01f+i,0.01f+j,x,y);
        i = i + x;
        j = j + 5.0f*y;
        */
        drawTriangle(0.01f+i,0.01f+j,0.04f);
        
        glutKeyboardFunc(getKey);
        
        
        
        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
        

    }

    // Clean up
    glfwTerminate();
    return 0;
}

//g++ bouncingBall.cpp -o Ball -framework glut -framework opengl -I /opt/homebrew/Cellar/freeglut/3.4.0/include/