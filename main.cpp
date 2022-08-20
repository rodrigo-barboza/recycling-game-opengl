#include <iostream>
#include <cstdlib>
#include <GL/glut.h>

// paletas de cores
#define COLOR_BACKGROUND  glClearColor(0.00392, 0.05098, 0.00392, 0.000000)
#define COLOR_FONT_MENU   glColor3f(1.000000, 1.000000, 1.000000)
#define COLOR_BLUE_MENU   glColor3f(0.000000, 0.362000, 0.832000)
#define COLOR_GREEN		  glColor3ub(6, 133, 90);
#define LIGHT_GREEN		  glColor3ub(142, 191, 37);
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
const int SPECIAL_FUNCTIONS = 5;
const int VIEW_TUTORIAL = 6;

int current_view=VIEW_A;


#include "libs/objects_text.h"
#include "libs/special_functions.h"
#include "views/view_a.h"
#include "views/view_score.h"       
#include "views/view_learn.h"  
#include "views/view_tutorial.h"  

void mouseEvents(int button, int state, int x, int y);

int main(void) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);     
	glutInitWindowSize(WINDOWS_WIDTH, WINDOWS_HEIGHT);  
	glutCreateWindow("Jogo da Reciclagem"); 
 	gluOrtho2D(0, WINDOWS_WIDTH, WINDOWS_HEIGHT,0); 	
	glutDisplayFunc(drawViewA);
	glutMouseFunc(mouseEvents);   	
	glutSpecialFunc(keyboardEvents);
	glutKeyboardFunc (keyboard);
	glutPassiveMotionFunc(moveMouse);
	glutMainLoop();
	return 0;
}

void mouseEvents(int button, int state, int x, int y) {      	
    if (button == GLUT_LEFT_BUTTON)
    	 if (state == GLUT_DOWN){
    	 	
    	 		//BOTÃO APRENDER NA VIEW_A
    	 		if(x>=250 && x<=498  && y>=251 && y<=294 && current_view == VIEW_A){
			 		current_view = VIEW_LEARN;
			 		glutDisplayFunc(drawViewLearn);
				}
				
				//BOTÃO JOGAR NA VIEW_A
				if(x>=250 && x<=498  && y>=156 && y<=204 && current_view == VIEW_A){
			 		current_view = VIEW_GAME;
			 		printf("\nload View Play");
				}
				
				//BOTÃO INICIAR NA VIEW_TUTORIAL
				if(x>=601 && x<=697  && y>=420 && y<=468 && current_view == VIEW_TUTORIAL){
			 		current_view = VIEW_GAME;
			 		printf("\nload View INICIAR");
				}
				
				//BOTÃO NEXT NA VIEW_LEARN
				if(x>=601 && x<=697  && y>=420 && y<=468 && current_view == VIEW_LEARN){
			 		current_view = VIEW_B;
			 		printf("\nload View B");
				}
				
				//BOTÃO JOGAR NOVAMENTE NA VIEW_SCORE
				if(x>=225 && x<=520  && y>=256 && y<=303 && current_view == VIEW_SCORE){
			 		current_view = VIEW_GAME;
			 		printf("\nload View Play Again");
				}
				
				//BOTÃO MENU NA VIEW_SCORE
				if(x>=251 && x<=497  && y>=351 && y<=396 && current_view == VIEW_SCORE){
			 		current_view = VIEW_TUTORIAL;
			 		glutDisplayFunc(drawViewTutorial);
				}
		 }	
    glutPostRedisplay();
}
