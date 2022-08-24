void drawViewScore() {
	current_view = VIEW_SCORE;
	
	COLOR_BACKGROUND;
	glClear(GL_COLOR_BUFFER_BIT);
	
    COLOR_GREEN;
    drawSquare(300, 98, 225, 256);
    drawSquare(250, 98, 250, 350);

	COLOR_FONT_MENU;
	glPushMatrix();	
		glTranslatef(280, 50, 0);
		glScalef(0.21, 0.21, 0.21);
		glRotatef(180, 1,0,0);
		glLineWidth(3);
		drawTextStroke(GLUT_STROKE_ROMAN,"PONTUACAO");
	glPopMatrix();
	
	if (percent_score > 60) {
		glPushMatrix();	
			glTranslatef(200, 100, 0);
			glScalef(0.21, 0.21, 0.21);
			glRotatef(180, 1,0,0);
			glLineWidth(3);
			drawTextStroke(GLUT_STROKE_ROMAN,"PARABENS, VOCE ACERTOU:");
		glPopMatrix();
		
		glPushMatrix();	
			LIGHT_GREEN;
			glTranslatef(300, 150, 0);
			glScalef(0.21, 0.21, 0.21);
			glRotatef(180, 1,0,0);
			glLineWidth(3);
			char text_x[100];
			sprintf(text_x, "%i/%i", current_score, score_should_be);
			drawTextStroke(GLUT_STROKE_ROMAN, text_x);
		glPopMatrix();
	} else {
		glPushMatrix();	
			glTranslatef(200, 100, 0);
			glScalef(0.21, 0.21, 0.21);
			glRotatef(180, 1,0,0);
			glLineWidth(3);
			drawTextStroke(GLUT_STROKE_ROMAN,"CONTINUE PRATICANDO");
		glPopMatrix();

		glPushMatrix();	
			glTranslatef(250, 135, 0);
			glScalef(0.21, 0.21, 0.21);
			glRotatef(180, 1,0,0);
			glLineWidth(3);
			drawTextStroke(GLUT_STROKE_ROMAN,"VOCE ACERTOU:");
		glPopMatrix();
		
		glPushMatrix();	
			RED;
			glTranslatef(300, 170, 0);
			glScalef(0.21, 0.21, 0.21);
			glRotatef(180, 1,0,0);
			glLineWidth(3);
			char text_z[100];
			sprintf(text_z, "%i/%i", current_score, score_should_be);
			drawTextStroke(GLUT_STROKE_ROMAN, text_z);
		glPopMatrix();
	}
	
	COLOR_FONT_MENU;
	glPushMatrix();	
		glTranslatef(250, 289, 0);
		glScalef(0.2, 0.2, 0.2);
		glRotatef(180, 1,0,0);
		glLineWidth(2);
		drawTextStroke(GLUT_STROKE_ROMAN,"JOGAR NOVAMENTE");
	glPopMatrix();
	
	COLOR_FONT_MENU;
	glPushMatrix();	
		glTranslatef(340, 383, 0);
		glScalef(0.2, 0.2, 0.2);
		glRotatef(180, 1,0,0);
		glLineWidth(2);
		drawTextStroke(GLUT_STROKE_ROMAN,"MENU");
	glPopMatrix();

	glFlush();
}
