
void vieweText();

void drawViewE() {
	current_view = VIEW_E;
	
	COLOR_BACKGROUND;
	glClear(GL_COLOR_BUFFER_BIT);
	
    COLOR_GREEN;
    //width, height, X position, Y position
    drawSquare(100, 98, 600, 420);

	COLOR_GREEN;
	glPushMatrix();	
		glTranslatef(300, 50, 0);
		glScalef(0.21, 0.21, 0.21); // diminui o tamanho do fonte
		glRotatef(180, 1,0,0); // rotaciona o texto
		glLineWidth(3); // define a espessura da linha
		drawTextStroke(GLUT_STROKE_ROMAN,"APRENDER");
	glPopMatrix();
	
	vieweText();
	
	COLOR_FONT_MENU;
	glPushMatrix();	
		glTranslatef(615, 455, 0);
		glScalef(0.2, 0.2, 0.2); // diminui o tamanho do fonte
		glRotatef(180, 1,0,0); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		drawTextStroke(GLUT_STROKE_ROMAN,"MENU");
		
	glPopMatrix();

	glFlush();
}

void vieweText(){
	//------------------------------------------------------------------------------------------------------------
	int y_pos = 90;
	glPushMatrix();	
		COLOR_FONT_MENU;
		y_pos+=30;
		glTranslatef(30, y_pos, 0);
		glScalef(0.2, 0.2, 0.2); // diminui o tamanho do fonte
		glRotatef(180, 1,0,0); // rotaciona o texto
		glLineWidth(1.5); // define a espessura da linha
		drawTextStroke(GLUT_STROKE_ROMAN,"Coletor de vidro: representado pela cor verde.");
	glPopMatrix();
	  
	glPushMatrix();	
		COLOR_FONT_MENU;
		y_pos+=30;
		glTranslatef(30, y_pos, 0);
		glScalef(0.2, 0.2, 0.2); // diminui o tamanho do fonte
		glRotatef(180, 1,0,0); // rotaciona o texto
		glLineWidth(1.5); // define a espessura da linha
		drawTextStroke(GLUT_STROKE_ROMAN,"Exemplos: copos, garradas, potes, perfumes e etc.");
	glPopMatrix();
	 
	glPushMatrix();	
		COLOR_FONT_MENU;
		y_pos+=90;
		glTranslatef(30, y_pos, 0);
		glScalef(0.2, 0.2, 0.2); // diminui o tamanho do fonte
		glRotatef(180, 1,0,0); // rotaciona o texto
		glLineWidth(1.5); // define a espessura da linha
		drawTextStroke(GLUT_STROKE_ROMAN,"Coletor Nao Reciclavel: representado pela cor cinza.");
	glPopMatrix();
										  
	glPushMatrix();	
		COLOR_FONT_MENU;
		y_pos+=30;
		glTranslatef(30, y_pos, 0);
		glScalef(0.2, 0.2, 0.2); // diminui o tamanho do fonte
		glRotatef(180, 1,0,0); // rotaciona o texto
		glLineWidth(1.5); // define a espessura da linha
		drawTextStroke(GLUT_STROKE_ROMAN,"Exemplos: espelhos, loucas, tomadas e etc.");
	glPopMatrix();

	//------------------------------------------------------------------------------------------------------------
}
