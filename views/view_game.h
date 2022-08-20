#include <ctime>

void drawViewGame() {
	current_view = VIEW_GAME;

	DARK_SLATE_BG;
	glClear(GL_COLOR_BUFFER_BIT);

	int current_pos = getRandomRange();
	strcpy(current_object_name, objects.at(current_pos).getObjectName());
	strcpy(current_object_category, objects.at(current_pos).getObjectCategory());
	current_object_point = objects.at(current_pos).getObjectPoint();
	
	glPushMatrix();
    	drawSquare(400, 600, 10, 90);
    glPopMatrix();
    
    glPushMatrix();
    	applyTexture();
    glPopMatrix();
    
    COLOR_FONT_MENU;
	glPushMatrix();	
		glRasterPos3f(10, 20, 0);
		glScalef(0.15, 0.15, 0.15); // diminui o tamanho do fonte
		glRotatef(180, 1,0,0); // rotaciona o texto
		
		char text_a[12];
		sprintf(text_a, "OBJETO %i/%i", current_object, OBJECTS_PER_LEVEL);
		drawText(GLUT_BITMAP_HELVETICA_10, text_a);
	glPopMatrix();
	
	glPushMatrix();	
		glRasterPos3f(10, 70, 0);		
		char text_b[100];
		sprintf(text_b, "Objeto: %s", current_object_name);
		drawText(GLUT_BITMAP_HELVETICA_18, text_b);
	glPopMatrix();

	glFlush();
}