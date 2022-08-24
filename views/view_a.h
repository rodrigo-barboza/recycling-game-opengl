void drawViewA() {
	current_view = VIEW_A;
	
	COLOR_BACKGROUND;
	glClear(GL_COLOR_BUFFER_BIT);
	
    COLOR_GREEN;
    drawSquare(250, 98, 250, 156);
    drawSquare(250, 98, 250, 250);

	COLOR_FONT_MENU;
	glPushMatrix();	
		glTranslatef(215, 50, 0);
		glScalef(0.21, 0.21, 0.21);
		glRotatef(180, 1,0,0);
		glLineWidth(3);
		drawTextStroke(GLUT_STROKE_ROMAN,"JOGO DA RECICLAGEM");
	glPopMatrix();

	COLOR_FONT_MENU;
	glPushMatrix();	
		glTranslatef(334, 190, 0);
		glScalef(0.2, 0.2, 0.2);
		glRotatef(180, 1,0,0);
		glLineWidth(2);
		drawTextStroke(GLUT_STROKE_ROMAN,"JOGAR");
	glPopMatrix();

    COLOR_FONT_MENU;
	glPushMatrix();	
		glTranslatef(312, 285, 0);
		glScalef(0.2, 0.2, 0.2);
		glRotatef(180, 1,0,0);
		glLineWidth(2);
		drawTextStroke(GLUT_STROKE_ROMAN,"APRENDER");
	glPopMatrix();
	
	glFlush();
}
