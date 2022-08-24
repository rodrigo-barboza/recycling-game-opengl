
void infoText();

void drawViewLearn() {
	current_view = VIEW_LEARN;
	
	COLOR_BACKGROUND;
	glClear(GL_COLOR_BUFFER_BIT);
	
    COLOR_GREEN;
    drawSquare(100, 98, 600, 420);

	COLOR_GREEN;
	glPushMatrix();	
		glTranslatef(300, 50, 0);
		glScalef(0.21, 0.21, 0.21);
		glRotatef(180, 1,0,0);
		glLineWidth(3);
		drawTextStroke(GLUT_STROKE_ROMAN,"APRENDER");
	glPopMatrix();
	
	infoText();
	
	glPushMatrix();
		COLOR_FONT_MENU;
		glTranslatef(325, 212, 0);
		drawArrow();
	glPopMatrix();

	glFlush();
}

void infoText(){
	int y_pos = 90;
	
	glPushMatrix();	
		COLOR_FONT_MENU;
		y_pos+=30;
		glTranslatef(30, y_pos, 0);
		glScalef(0.2, 0.2, 0.2);
		glRotatef(180, 1,0,0);
		glLineWidth(1.5);
		drawTextStroke(GLUT_STROKE_ROMAN,"A Coleta Seletiva eh um mecanismo de recolha");
	glPopMatrix();
	  
	glPushMatrix();	
		COLOR_FONT_MENU;
		y_pos+=30;
		glTranslatef(30, y_pos, 0);
		glScalef(0.2, 0.2, 0.2);
		glRotatef(180, 1,0,0);
		glLineWidth(1.5);
		drawTextStroke(GLUT_STROKE_ROMAN,"dos residuos, os quais sao classificados de ");
	glPopMatrix();
	
	glPushMatrix();	
		COLOR_FONT_MENU;
		y_pos+=30;
		glTranslatef(30, y_pos, 0);
		glScalef(0.2, 0.2, 0.2);
		glRotatef(180, 1,0,0);
		glLineWidth(1.5);
		drawTextStroke(GLUT_STROKE_ROMAN,"acordo com sua origem e depositados em  ");
	glPopMatrix(); 					      
	
	glPushMatrix();	
		COLOR_FONT_MENU;
		y_pos+=30;
		glTranslatef(30, y_pos, 0);
		glScalef(0.2, 0.2, 0.2);
		glRotatef(180, 1,0,0);
		glLineWidth(1.5);
		drawTextStroke(GLUT_STROKE_ROMAN,"contentores indicados por cores. Ou seja, eles ");
	glPopMatrix();
	 
	glPushMatrix();	
		COLOR_FONT_MENU;
		y_pos+=30;
		glTranslatef(30, y_pos, 0);
		glScalef(0.2, 0.2, 0.2);
		glRotatef(180, 1,0,0);
		glLineWidth(1.5);
		drawTextStroke(GLUT_STROKE_ROMAN,"podem ser residuos organicos ou materiais  ");
	glPopMatrix();
										  
	glPushMatrix();	
		COLOR_FONT_MENU;
		y_pos+=30;
		glTranslatef(30, y_pos, 0);
		glScalef(0.2, 0.2, 0.2);
		glRotatef(180, 1,0,0);
		glLineWidth(1.5);
		drawTextStroke(GLUT_STROKE_ROMAN,"reciclaveis como papel, plastico, vidro, dentre ");
	glPopMatrix();
	 
	glPushMatrix();	
		COLOR_FONT_MENU;
		y_pos+=30;
		glTranslatef(30, y_pos, 0);
		glScalef(0.2, 0.2, 0.2);
		glRotatef(180, 1,0,0);
		glLineWidth(1.5);
		drawTextStroke(GLUT_STROKE_ROMAN,"outros. Alem deles, materiais hospitalares e ");
	glPopMatrix();
	
	glPushMatrix();						  
		COLOR_FONT_MENU;
		y_pos+=30;
		glTranslatef(30, y_pos, 0);
		glScalef(0.2, 0.2, 0.2);
		glRotatef(180, 1,0,0);
		glLineWidth(1.5);
		drawTextStroke(GLUT_STROKE_ROMAN,"radioativos tem um destino diferente. A coleta ");
	glPopMatrix();
	 
	glPushMatrix();	
		COLOR_FONT_MENU;
		y_pos+=30;
		glTranslatef(30, y_pos, 0);
		glScalef(0.2, 0.2, 0.2);
		glRotatef(180, 1,0,0);
		glLineWidth(1.5);
		drawTextStroke(GLUT_STROKE_ROMAN,"seletiva representa a maneira ecologica mais");
	glPopMatrix();
	glPushMatrix();	
		COLOR_FONT_MENU;
		y_pos+=30;
		glTranslatef(30, y_pos, 0);
		glScalef(0.2, 0.2, 0.2);
		glRotatef(180, 1,0,0);
		glLineWidth(1.5);
		drawTextStroke(GLUT_STROKE_ROMAN,"adequada para o descarte de lixo.");
	glPopMatrix();
}
