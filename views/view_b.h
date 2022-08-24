
void viewbText();

void drawViewB() {
	current_view = VIEW_B;
	
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
	
	viewbText();

	glPushMatrix();
		COLOR_FONT_MENU;
		glTranslatef(325, 212, 0);
		drawArrow();
	glPopMatrix();
	
	glPushMatrix();
		COLOR_FONT_MENU;
		glTranslatef(325, 212, 0);
		drawArrow();
	glPopMatrix();
	
	glFlush();
}

void viewbText(){
	int y_pos = 90;

	glPushMatrix();	
		COLOR_FONT_MENU;
		y_pos+=30;
		glTranslatef(30, y_pos, 0);
		glScalef(0.2, 0.2, 0.2);
		glRotatef(180, 1,0,0);
		glLineWidth(1.5);
		drawTextStroke(GLUT_STROKE_ROMAN,"Coletor de papel: representado pela cor azul.");
	glPopMatrix();
	  
	glPushMatrix();	
		COLOR_FONT_MENU;
		y_pos+=30;
		glTranslatef(30, y_pos, 0);
		glScalef(0.2, 0.2, 0.2);
		glRotatef(180, 1,0,0);
		glLineWidth(1.5);
		drawTextStroke(GLUT_STROKE_ROMAN,"Exemplos: jornais, revistas, caixas de papelao e etc.");
	glPopMatrix();
	 
	glPushMatrix();	
		COLOR_FONT_MENU;
		y_pos+=90;
		glTranslatef(30, y_pos, 0);
		glScalef(0.2, 0.2, 0.2);
		glRotatef(180, 1,0,0);
		glLineWidth(1.5);
		drawTextStroke(GLUT_STROKE_ROMAN,"Coletor de plastico: representado pela cor vermelha.");
	glPopMatrix();
										  
	glPushMatrix();	
		COLOR_FONT_MENU;
		y_pos+=30;
		glTranslatef(30, y_pos, 0);
		glScalef(0.2, 0.2, 0.2);
		glRotatef(180, 1,0,0);
		glLineWidth(1.5);
		drawTextStroke(GLUT_STROKE_ROMAN,"Exemplos: garrafas PET, sacos, embalagens e etc.");
	glPopMatrix();
	 
	glPushMatrix();	
		COLOR_FONT_MENU;
		y_pos+=90;
		glTranslatef(30, y_pos, 0);
		glScalef(0.2, 0.2, 0.2);
		glRotatef(180, 1,0,0);
		glLineWidth(1.5);
		drawTextStroke(GLUT_STROKE_ROMAN,"Coletor de Metal: representado pela cor amarela.");
	glPopMatrix();
	glPushMatrix();	
		COLOR_FONT_MENU;
		y_pos+=30;
		glTranslatef(30, y_pos, 0);
		glScalef(0.2, 0.2, 0.2);
		glRotatef(180, 1,0,0);
		glLineWidth(1.5);
		drawTextStroke(GLUT_STROKE_ROMAN,"Exemplos: latas, tampas, clips e etc.");
	glPopMatrix();
}
