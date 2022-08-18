
// void keyboard(unsigned char, int, int);
// void keyboardEvents(int, int, int);
// void mouseEvents(int, int, int, int);
char texto[30];
GLfloat win=150.0f;

void keyboardEvents(int key, int x, int y) {
	// sempre deve ser chamado no final            
	glutPostRedisplay();
}

void DesenhaTexto(char *string) 
{  
  	glPushMatrix();
  		COLOR_FONT_MENU;
        // Posição no universo onde o texto será colocado          
        glRasterPos2f(-win,win-(win*0.08)); 
        // Exibe caracter a caracter
        while(*string)
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,*string++); 
	glPopMatrix();
}

void MoveMouse(int x, int y)
{
	 system("cls");
     printf("\n(%d,%d)", x, y);
     glutPostRedisplay();
}

void keyboard (unsigned char key, int x, int y) {	
	if (key == 27) // ESC PARA SAIR
		exit(0);		
}
