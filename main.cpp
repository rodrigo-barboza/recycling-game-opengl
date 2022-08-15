#include <iostream>
#include <cstdlib>
#include <GL/glut.h>

// paletas de cores
#define SLATE_BLUE 	      glColor3f(0.000000, 0.498000, 1.000000)
#define STEEL_BLUE 	      glColor3f(0.137300, 0.419600, 0.556900)
#define AQUAMARINE 	      glColor3f(0.439200, 0.858800, 0.576500)
#define FIREBRICK         glColor3f(0.556900, 0.137300, 0.137300)
#define ORCHID 	   	      glColor3f(0.858800, 0.439200, 0.858800)
#define CORAL 	   	      glColor3f(1.000000, 0.498000, 0.000000)
#define DARK_SLATE_BG     glClearColor(0.419600, 0.137300, 0.556900, 0.000000)
#define MIDNIGHT_BLUE_BG  glClearColor(0.184300, 0.184300, 0.309800, 0.000000)
#define BROWN_BG	      glClearColor(0.647100, 0.164700, 0.164700, 0.000000)
#define GOLD_BG    		  glClearColor(0.800000, 0.498000, 0.196100, 0.000000)
#define VIOLET_BG 	      glClearColor(0.309800, 0.184300, 0.309800, 0.000000)
#define DARK_ORCHID_BG 	  glClearColor(0.600000, 0.196100, 0.800000, 0.000000)

const int WINDOWS_WIDTH = 750;
const int WINDOWS_HEIGHT = 500;
const int VIEW_A = 0;
const int VIEW_B = 1;
const int VIEW_GAME = 2;
const int VIEW_SCORE = 3;
const int VIEW_LEARN = 4;
const int SPACIAL_FUNCTIONS = 5;

int current_view = VIEW_A;

#include "objects_text.h"
#include "special_functions.h"
#include "view_a.h"
           
int main(void) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);     
	glutInitWindowSize(WINDOWS_WIDTH, WINDOWS_HEIGHT);  
	glutCreateWindow("Jogo da Reciclagem"); 
 	gluOrtho2D(0, WINDOWS_WIDTH, WINDOWS_HEIGHT,0);
 	
	glutDisplayFunc(drawViewA);  
	
	glutSpecialFunc(keyboardEvents);
	glutMouseFunc(mouseEvents);
	glutKeyboardFunc (keyboard);
	  
	glutMainLoop();
	return 0;
}
