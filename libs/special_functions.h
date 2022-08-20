#include <string>
// void keyboard(unsigned char, int, int);
// void keyboardEvents(int, int, int);
// void mouseEvents(int, int, int, int);

void keyboardEvents(int key, int x, int y) {
	// sempre deve ser chamado no final         
	glutPostRedisplay();
}

void mouseEvents (int button, int state, int x, int y) {
	if (current_view == VIEW_A) {
		if (button == GLUT_LEFT_BUTTON) {
			std::cout << "estou na view a " << std::endl;
		}
	}
	
	// sempre deve ser chamado no final            
    glutPostRedisplay();
}

void keyboard (unsigned char key, int x, int y) {	
	if (current_view == VIEW_GAME) {
		if (key == 43 || key == 61) {
			cout << "incr" << endl;
			object_scale += object_scale_factor;
		}
		
		if (key == 45) {
			object_scale -= object_scale_factor;
		}
		
		glutDisplayFunc(drawViewGame);
	}
	
	glutPostRedisplay();
	
	if (key == 27) // ESC PARA SAIR
		exit(0);		
}
