// rodrigo é lindo

void drawViewA() {
	current_view = VIEW_A;
	// seta background
	DARK_SLATE_BG;
	glClear(GL_COLOR_BUFFER_BIT);
	
	AQUAMARINE;
	glPushMatrix();	
		glTranslatef(80, 150, 0);
		glScalef(0.4, 0.4, 0.4); // diminui o tamanho do fonte
		glRotatef(180, 1,0,0); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		drawTextStroke(GLUT_STROKE_ROMAN,"JOGO DA RECICLAGEM");
	glPopMatrix();

	AQUAMARINE;
	glPushMatrix();	
		glTranslatef(335, 260, 0);
		glScalef(0.2, 0.2, 0.2); // diminui o tamanho do fonte
		glRotatef(180, 1,0,0); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		drawTextStroke(GLUT_STROKE_ROMAN,"JOGAR");
	glPopMatrix();

	glFlush();
}
