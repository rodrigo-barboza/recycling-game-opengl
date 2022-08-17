void drawViewScore() {
	current_view = VIEW_SCORE;
	
	COLOR_BACKGROUND;
	glClear(GL_COLOR_BUFFER_BIT);
	
    COLOR_GREEN;
    //width, height, X position, Y position
    drawSquare(300, 98, 225, 256);
    drawSquare(250, 98, 250, 350);

	COLOR_FONT_MENU;
	glPushMatrix();	
		glTranslatef(300, 50, 0);
		glScalef(0.21, 0.21, 0.21); // diminui o tamanho do fonte
		glRotatef(180, 1,0,0); // rotaciona o texto
		glLineWidth(3); // define a espessura da linha
		drawTextStroke(GLUT_STROKE_ROMAN,"PONTUACAO");
	glPopMatrix();
	
	glPushMatrix();	
		glTranslatef(200, 100, 0);
		glScalef(0.21, 0.21, 0.21); // diminui o tamanho do fonte
		glRotatef(180, 1,0,0); // rotaciona o texto
		glLineWidth(3); // define a espessura da linha
		drawTextStroke(GLUT_STROKE_ROMAN,"PARABENS, VOCE ACERTOU:");
	glPopMatrix();
	
	glPushMatrix();	
		LIGHT_GREEN;
		glTranslatef(330, 150, 0);
		glScalef(0.21, 0.21, 0.21); // diminui o tamanho do fonte
		glRotatef(180, 1,0,0); // rotaciona o texto
		glLineWidth(3); // define a espessura da linha
		drawTextStroke(GLUT_STROKE_ROMAN,"556/560");
	glPopMatrix();
	
	COLOR_FONT_MENU;
	glPushMatrix();	
		glTranslatef(250, 289, 0);
		glScalef(0.2, 0.2, 0.2); // diminui o tamanho do fonte
		glRotatef(180, 1,0,0); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		drawTextStroke(GLUT_STROKE_ROMAN,"JOGAR NOVAMENTE");
	glPopMatrix();
	
	COLOR_FONT_MENU;
	glPushMatrix();	
		glTranslatef(340, 383, 0);
		glScalef(0.2, 0.2, 0.2); // diminui o tamanho do fonte
		glRotatef(180, 1,0,0); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		drawTextStroke(GLUT_STROKE_ROMAN,"MENU");
	glPopMatrix();

	glFlush();
}
