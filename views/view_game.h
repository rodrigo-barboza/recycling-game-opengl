
void drawViewGame() {
	current_view = VIEW_GAME;
	DARK_SLATE_BG;
	glClear(GL_COLOR_BUFFER_BIT);

	COLOR_FONT_MENU;
	glPushMatrix();	
		glRasterPos3f(10, 20, 0);
		glScalef(0.15, 0.15, 0.15); // diminui o tamanho do fonte
		glRotatef(180, 1,0,0); // rotaciona o texto
		
		char text[12];
		sprintf(text, "OBJETO %i/%i", current_object, OBJECTS_PER_LEVEL);
		drawText(GLUT_BITMAP_HELVETICA_10, text);
	glPopMatrix();
	
	glPushMatrix();	
		glRasterPos3f(10, 70, 0);		
		text[sizeof(current_object_name) + 9];
		sprintf(text, "Objeto: %s", current_object_name);
		drawText(GLUT_BITMAP_HELVETICA_18, text);
	glPopMatrix();
	
	glPushMatrix();
    	drawSquare(400, 600, 10, 90);
    glPopMatrix();
    
    CORAL;
//    glRotatef(20,1,0,0);
    //		glTranslatef(10,10,10);
    glPushMatrix();
    	glRotatef(50, object_scale, object_scale/2, 0);
    	drawSquare(100, 150, 200, 120);
    glPopMatrix();
    
	glFlush();
}

//glPushMatrix();	
//		glTranslatef(334, 190, 0);
//		glScalef(0.2, 0.2, 0.2); // diminui o tamanho do fonte
//		glRotatef(180, 1,0,0); // rotaciona o texto
//		glLineWidth(2); // define a espessura da linha
//		drawTextStroke(GLUT_STROKE_ROMAN,"JOGAR");
//	glPopMatrix();
