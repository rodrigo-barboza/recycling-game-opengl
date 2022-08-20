
// void keyboard(unsigned char, int, int);
// void keyboardEvents(int, int, int);
// void mouseEvents(int, int, int, int);

void keyboardEvents(int key, int x, int y) {
	// sempre deve ser chamado no final            
	glutPostRedisplay();
}

void moveMouse(int x, int y)
{
	 system("cls");
     printf("\n(%d,%d)", x, y);
     glutPostRedisplay();
}

void keyboard (unsigned char key, int x, int y) {	
	if (key == 27) // ESC PARA SAIR
		exit(0);		
}
