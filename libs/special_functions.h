#include <string>
// void keyboard(unsigned char, int, int);
// void keyboardEvents(int, int, int);
// void mouseEvents(int, int, int, int);

void nextObject() {
	if (current_object <= (OBJECTS_PER_LEVEL-1))
		current_object++;
}

void keyboardEvents(int key, int x, int y) {
	if (current_view == VIEW_GAME) {
		if (key == GLUT_KEY_DOWN) {
			if (current_object != OBJECTS_PER_LEVEL) {
				// apaga o objeto anterior da lista de objetos para não repetir
				objects.erase(objects.begin() + current_object_pos);
				// incrementa o objeto: x de y
				nextObject();
				// pega novo objeto de uma posição aleatória da lista de objetos
				current_object_pos = getRandomRange();
				strcpy(current_object_name, objects.at(current_object_pos).getObjectName());
				strcpy(current_object_category, objects.at(current_object_pos).getObjectCategory());
				current_object_point = objects.at(current_object_pos).getObjectPoint();
				glutPostRedisplay();
			}			
		}
	}
}

// void moveMouse(int x, int y) {
// 	system("cls"); 
//     printf("\n(%d,%d) ", x, y);
// }

void mouseEvents (int button, int state, int x, int y) {	
	if (button == GLUT_LEFT_BUTTON) {
    	 if (state == GLUT_DOWN) {
	 		//BOTĂO APRENDER NA VIEW_A
	 		if(x>=250 && x<=498  && y>=251 && y<=294 && current_view == VIEW_A) {
		 		current_view = VIEW_LEARN;
		 		glutDisplayFunc(drawViewLearn);
		 		glutPostRedisplay();
			}

			//BOTĂO JOGAR NA VIEW_A
			if(x>=250 && x<=498  && y>=156 && y<=204 && current_view == VIEW_A) {
		 		current_view = VIEW_GAME;
		 		glutDisplayFunc(drawViewGame);
		 		glutPostRedisplay();
			}

			//BOTĂO INICIAR NA VIEW_TUTORIAL
			if(x>=601 && x<=697  && y>=420 && y<=468 && current_view == VIEW_TUTORIAL) {
		 		current_view = VIEW_GAME;
		 		glutPostRedisplay();
			}

			//BOTĂO NEXT NA VIEW_LEARN
			if(x>=601 && x<=697  && y>=420 && y<=468 && current_view == VIEW_LEARN) {
		 		current_view = VIEW_B;
		 		glutPostRedisplay();
			}

			//BOTĂO JOGAR NOVAMENTE NA VIEW_SCORE
			if(x>=225 && x<=520  && y>=256 && y<=303 && current_view == VIEW_SCORE) {
		 		current_view = VIEW_GAME;
		 		glutPostRedisplay();
			}

			//BOTĂO MENU NA VIEW_SCORE
			if(x>=251 && x<=497  && y>=351 && y<=396 && current_view == VIEW_SCORE) {
		 		current_view = VIEW_TUTORIAL;
		 		glutDisplayFunc(drawViewTutorial);
		 		glutPostRedisplay();
			}
		}
	}
}

void keyboard (unsigned char key, int x, int y) {		
	if (key == 27) // ESC PARA SAIR
		exit(0);		
}
