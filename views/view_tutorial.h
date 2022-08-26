
void tutorialText();

void drawViewTutorial() {
	current_view = VIEW_TUTORIAL;
	
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
	
	tutorialText();
	
	COLOR_FONT_MENU;
	glPushMatrix();	
		glTranslatef(610, 455, 0);
		glScalef(0.2, 0.2, 0.2);
		glRotatef(180, 1,0,0);
		glLineWidth(2);
		drawTextStroke(GLUT_STROKE_ROMAN,"INICIAR");
		
	glPopMatrix();

	glFlush();
}
void tutorialText(){
	int y_pos = 90;

	glPushMatrix();	
		COLOR_FONT_MENU;
		y_pos+=30;
		glTranslatef(70, y_pos, 0);
		glScalef(0.2, 0.2, 0.2);
		glRotatef(180, 1,0,0);
		glLineWidth(1.5);
		drawTextStroke(GLUT_STROKE_ROMAN,"Use SETA PARA CIMA e SETA PARA BAIXO ");
	glPopMatrix();
	
	glPushMatrix();	
		COLOR_FONT_MENU;
		y_pos+=30;
		glTranslatef(70, y_pos, 0);
		glScalef(0.2, 0.2, 0.2);
		glRotatef(180, 1,0,0);
		glLineWidth(1.5);
		drawTextStroke(GLUT_STROKE_ROMAN,"para mudar de alternativa.");
	glPopMatrix();
	
	glPushMatrix();	
		COLOR_FONT_MENU;
		y_pos+=80;
		glTranslatef(70, y_pos, 0);
		glScalef(0.2, 0.2, 0.2);
		glRotatef(180, 1,0,0);
		glLineWidth(1.5);
		drawTextStroke(GLUT_STROKE_ROMAN,"Use a tecla ENTER para confirmar sua resposta.");
	glPopMatrix();
}
