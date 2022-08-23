#include <string>

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

void drawArrow(){
	glMatrixMode(GL_MODELVIEW);
	
	glBegin(GL_TRIANGLES);
	    glVertex2f(320.0,215.0);
	    glVertex2f(340.0,230.0);
	    glVertex2f(320.0,245.0);
    glEnd();

}

void drawText(void *font, char *string) {
	while(*string) {
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *string++);
	}
}

void drawTextStroke(void *font, char *string) {
	while(*string) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN,*string++); 
	}
}

void drawSelectionText() {
	vector <char*> titles;
	titles.push_back("Coletor de Papel");
	titles.push_back("Coletor de Plastico");
	titles.push_back("Coletor de Metal");
	titles.push_back("Coletor de Vidro");
	titles.push_back("Nao reciclavel");

	for (int c = 0, step = 0; c < titles.size(); c++, step += 50) {
		glPushMatrix();	
			glRasterPos3i(430, 135 + step, 0);
			glScalef(0.15, 0.15, 0.15);
			glRotatef(180, 1,0,0); 
			drawText(GLUT_BITMAP_HELVETICA_12, titles.at(c));
		glPopMatrix();
	}
}

void changeScoreIfMatch() {
	if (has_match) {
		SPRING_GREEN;
		glPushMatrix();	
			glRasterPos3f(10, 490, 0);		
			char text_c[100];
			sprintf(text_c, "PONTUACAO: %i", current_score);
			drawText(GLUT_BITMAP_HELVETICA_18, text_c);
		glPopMatrix();
	} else if (!has_match) {
		RED;
		glPushMatrix();	
			glRasterPos3f(10, 490, 0);		
			char text_c[100];
			sprintf(text_c, "PONTUACAO: %i", current_score);
			drawText(GLUT_BITMAP_HELVETICA_18, text_c);
		glPopMatrix();
	} 
}