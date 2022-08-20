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
		glScalef(0.21, 0.21, 0.21); // diminui o tamanho do fonte
		glRotatef(180, 1,0,0); // rotaciona o texto
		glLineWidth(3); // define a espessura da linha
		drawTextStroke(GLUT_STROKE_ROMAN,"JOGO DA RECICLAGEM");
	glPopMatrix();

	COLOR_FONT_MENU;
	glPushMatrix();	
		glTranslatef(334, 190, 0);
		glScalef(0.2, 0.2, 0.2); // diminui o tamanho do fonte
		glRotatef(180, 1,0,0); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		drawTextStroke(GLUT_STROKE_ROMAN,"JOGAR");
	glPopMatrix();

    COLOR_FONT_MENU;
	glPushMatrix();	
		glTranslatef(312, 285, 0);
		glScalef(0.2, 0.2, 0.2); // diminui o tamanho do fonte
		glRotatef(180, 1,0,0); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		drawTextStroke(GLUT_STROKE_ROMAN,"APRENDER");
	glPopMatrix();

	glFlush();
}
