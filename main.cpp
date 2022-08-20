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

// textura
#define STB_IMAGE_IMPLEMENTATION


using namespace std;

const int WINDOWS_WIDTH = 750;
const int WINDOWS_HEIGHT = 500;
const int VIEW_A = 0;
const int VIEW_B = 1;
const int VIEW_GAME = 2;
const int VIEW_SCORE = 3;
const int VIEW_LEARN = 4;
const int SPECIAL_FUNCTIONS = 5;
const int VIEW_TUTORIAL = 6;
const int OBJECTS_PER_LEVEL = 5;

int current_object = 1;
char* current_object_name = "garrafa PET";
int current_view = VIEW_A;
float object_scale = 1;
float object_scale_factor = .15;
//float object_scale_factor = 10;
GLuint textureId[15]; // 15 ids para cada textura/imagem

#include "libs/stb_image.h"
#include "textures/texture.h"
#include "libs/objects_text.h"
#include "views/view_a.h"
#include "views/view_score.h"       
#include "views/view_learn.h"  
#include "views/view_tutorial.h"  
#include "views/view_game.h"
#include "libs/special_functions.h"

int main(void) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);     
	glutInitWindowSize(WINDOWS_WIDTH, WINDOWS_HEIGHT);  
	glutCreateWindow("Jogo da Reciclagem"); 
 	gluOrtho2D(0, WINDOWS_WIDTH, WINDOWS_HEIGHT,0); 	
	glutMouseFunc(mouseEvents);   	

 	gluOrtho2D(0, WINDOWS_WIDTH, WINDOWS_HEIGHT,0);
 	
//	glutDisplayFunc(drawViewA);  
	glutDisplayFunc(drawViewGame);
	
	glutSpecialFunc(keyboardEvents);
	glutKeyboardFunc (keyboard);
	glutPassiveMotionFunc(moveMouse);
	glutMainLoop();
	
	glDisable(GL_TEXTURE_2D);
	glDeleteTextures(15, textureId);
	return 0;
}

