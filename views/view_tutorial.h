
void tutorialText();
void tutorialTextGenerator();

void drawViewTutorial() {
	current_view = VIEW_TUTORIAL;
	
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
	
	tutorialText();
	//tutorialTextGenerator();
	
	COLOR_FONT_MENU;
	glPushMatrix();	
		glTranslatef(610, 455, 0);
		glScalef(0.2, 0.2, 0.2); // diminui o tamanho do fonte
		glRotatef(180, 1,0,0); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		drawTextStroke(GLUT_STROKE_ROMAN,"INICIAR");
		
	glPopMatrix();

	glFlush();
}
void tutorialText(){
	//------------------------------------------------------------------------------------------------------------
	int y_pos = 90;
	glPushMatrix();	
		COLOR_FONT_MENU;
		y_pos+=30;
		glTranslatef(70, y_pos, 0);
		glScalef(0.2, 0.2, 0.2); // diminui o tamanho do fonte
		glRotatef(180, 1,0,0); // rotaciona o texto
		glLineWidth(1.5); // define a espessura da linha
		drawTextStroke(GLUT_STROKE_ROMAN,"Use ARROW_UP e ARROW_DOWN para mudar");
	glPopMatrix();
	
	glPushMatrix();	
		COLOR_FONT_MENU;
		y_pos+=30;
		glTranslatef(70, y_pos, 0);
		glScalef(0.2, 0.2, 0.2); // diminui o tamanho do fonte
		glRotatef(180, 1,0,0); // rotaciona o texto
		glLineWidth(1.5); // define a espessura da linha
		drawTextStroke(GLUT_STROKE_ROMAN,"de alternativa.");
	glPopMatrix();
	
	glPushMatrix();	
		COLOR_FONT_MENU;
		y_pos+=80;
		glTranslatef(70, y_pos, 0);
		glScalef(0.2, 0.2, 0.2); // diminui o tamanho do fonte
		glRotatef(180, 1,0,0); // rotaciona o texto
		glLineWidth(1.5); // define a espessura da linha
		drawTextStroke(GLUT_STROKE_ROMAN,"Use a tecla ENTER para confirmar sua resposta.");
	glPopMatrix();
	
	

	//------------------------------------------------------------------------------------------------------------
}
void tutorialTextGenerator(){
	int y_pos = 500;
	
	
	for(int i=0;i<12;i++){
		glPushMatrix();			
			y_pos+=115;
			COLOR_FONT_MENU;
			glScalef(0.2, 0.2, 0.2); // diminui o tamanho do fonte
			glTranslatef(330, y_pos, 0);
			glRotatef(180, 1,0,0); // rotaciona o texto
			glLineWidth(1.5); // define a espessura da linha
			drawTextStroke(GLUT_STROKE_ROMAN,"viverra, ullamcorper turpis id, tristique sema.");
		glPopMatrix();
	}
	

}
