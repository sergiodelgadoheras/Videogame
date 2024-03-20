#include <iostream>
#include "main.h"
#include <GL/glut.h>
#include <GL/freeglut.h>

struct World
{
    float x;
    float y;
    float z;
    float d;
    float theta;
    int num;
};

World world;

//declarations

void OnDraw(void); 
void OnTimer(int value); 
void OnKeyboardDown(unsigned char key, int x, int y); 

int main(int argc,char* argv[])
{
    //FREEGLUT service initialization and window creation 
    glutInit(&argc, argv); 
    glutInitWindowSize(800,600); 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
    glutCreateWindow("MyGame"); 
    //light and perspective definition 
    glEnable(GL_LIGHT0); 
    glEnable(GL_LIGHTING); 
    glEnable(GL_DEPTH_TEST); 
    glEnable(GL_COLOR_MATERIAL); 
    glMatrixMode(GL_PROJECTION); 
    gluPerspective( 40.0, 800/600.0f, 0.1, 150);

    //Callbacks registration
    glutDisplayFunc(OnDraw); 
    glutTimerFunc(25,OnTimer,0); 
    glutKeyboardFunc(OnKeyboardDown);

    //FREEGLUT will call the callbacks 
    glutMainLoop();
    return 0; 
} 

void OnDraw(void) 
{ 
    //Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    //Define point of view
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity(); 
    
    gluLookAt(world.x, world.y, world.z, // eye position
    0.0, 0, 0.0, // point looking to (0,0,0) 
    0.0, 1.0, 0.0); // looking up (Y axis) 
    
    glutSolidTeapot(1);//draw an Teapol 

    //At the end, it changes the buffer (redraw) 
    //No addings after it 
    glutSwapBuffers();
} 

void OnTimer(int value) 
{  
    world.theta = atan2(world.z,world.x);
    world.theta+=0.01f;// angle increment
    
    if(world.d>=3){

        if((world.d>=3.00001 && world.d<=3.200020) || (world.d>=14.00001 && world.d<=14.300020)){ // borders for cycle
        world.num++;
        }
        if (world.num%2){
            world.d+=0.2f;//distance increment
        }else{
            world.d-=0.2f;
        }
    }
    else{world.d+=0.1f;}

    world.x=world.d*cos(world.theta);
    world.z=world.d*sin(world.theta);

    glutTimerFunc(25,OnTimer,0); 
    glutPostRedisplay(); 
} 
    void OnKeyboardDown(unsigned char key, int x_t, int y_t) 
{ 
} 