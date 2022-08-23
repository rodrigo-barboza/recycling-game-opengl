#include <ctime>

void drawViewGame() {
	current_view = VIEW_GAME;

	MIDNIGHT_BLUE_BG;
	glClear(GL_COLOR_BUFFER_BIT);

	if (current_object == 1) {
		current_score = 0;
		score_should_be = 0;
		percent_score = 0.0;
	}

	if (can_redisplay) {
		int current_pos = getRandomRange();
		strcpy(current_object_name, objects.at(current_pos).getObjectName());
		strcpy(current_object_category, objects.at(current_pos).getObjectCategory());
		current_object_point = objects.at(current_pos).getObjectPoint();
	}
	
	COLOR_FONT_MENU;
	glPushMatrix();	
		glRasterPos3f(10, 20, 0);
		glScalef(0.15, 0.15, 0.15); // diminui o tamanho do fonte
		glRotatef(180, 1,0,0); // rotaciona o texto
		
		char text_a[12];
		sprintf(text_a, "OBJETO %i/%i", current_object, OBJECTS_PER_LEVEL);
		drawText(GLUT_BITMAP_HELVETICA_10, text_a);
	glPopMatrix();
	
	COLOR_FONT_MENU;
	glPushMatrix();	
		glRasterPos3i(420, 100, 0);
		glScalef(0.15, 0.15, 0.15); // diminui o tamanho do fonte
		glRotatef(180, 1,0,0); // rotaciona o texto
		drawText(GLUT_BITMAP_HELVETICA_12, "COMO DEVO DESCARTAR?");
	glPopMatrix();

	STEEL_BLUE;
   	drawSquare(320, 80, 420, 110);
	drawSquare(320, 80, 420, 160);
	drawSquare(320, 80, 420, 210);
	drawSquare(320, 80, 420, 260);
	drawSquare(320, 80, 420, 310);
	COLOR_FONT_MENU;
	drawSquare(20, 40, select_option_x, select_option_y);

	drawSelectionText();

	COLOR_FONT_MENU;
	glPushMatrix();	
		glRasterPos3i(420, 370, 0);
		glScalef(0.15, 0.15, 0.15); // diminui o tamanho do fonte
		glRotatef(180, 1,0,0); // rotaciona o texto
		drawText(GLUT_BITMAP_HELVETICA_12, "ENTER PARA CONFIRMAR");
	glPopMatrix();

	COLOR_FONT_MENU;
	glPushMatrix();	
		glRasterPos3f(10, 70, 0);		
		char text_b[100];
		sprintf(text_b, "Objeto: %s", current_object_name);
		drawText(GLUT_BITMAP_HELVETICA_18, text_b);
	glPopMatrix();
	
	if(current_object == 1) {
		COLOR_FONT_MENU;
		glPushMatrix();	
			glRasterPos3f(10, 490, 0);		
			char text_c[100];
			sprintf(text_c, "PONTUACAO: %i", current_score);
			drawText(GLUT_BITMAP_HELVETICA_18, text_c);
		glPopMatrix();
	} else {
		changeScoreIfMatch();
	}

	COLOR_FONT_MENU;
	glPushMatrix();
		drawSquare(400, 600, 10, 90);
	glPopMatrix();

	glPushMatrix();
		applyTexture();
	glPopMatrix();
	
	glFlush();
}