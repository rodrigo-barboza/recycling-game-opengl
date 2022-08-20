// void drawSquare(int, int, int, int);
// void drawText(void*, char*);
// void drawTextStroke(void*, char*);

void drawSquare(int width, int height, int shamt_x, int shamt_y) {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();   
	glTranslated(shamt_x, shamt_y, 0); 

	glBegin(GL_POLYGON);
		glVertex2i(0, height/2); // bottom-left
		glVertex2i(width, height/2); // bottom-right
		glVertex2f(width, 0); // top-right	
		glVertex2i(0, 0); // top-left			
	glEnd();
	
	glPopMatrix(); 
}


void drawText(void *font, char *string) {
	while(*string)
		glutBitmapCharacter(font, *string++); 
}

void drawTextStroke(void *font, char *string) {  
	// Exibe caractere a caractere
	while(*string)
		glutStrokeCharacter(GLUT_STROKE_ROMAN,*string++); 
}
