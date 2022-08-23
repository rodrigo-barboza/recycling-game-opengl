#include <string>
#include <map>

void nextObject() {
	if (current_object <= (OBJECTS_PER_LEVEL-1))
		current_object++;
}

void keyboardEvents(int key, int x, int y) {
	if (current_view == VIEW_GAME) {
		can_redisplay = false;

		if (key == GLUT_KEY_DOWN && select_option_y < 310) {
			select_option_y += SELECT_OPTION_STEP;
		} else if (key == GLUT_KEY_UP && select_option_y > 120) {
			select_option_y -= SELECT_OPTION_STEP;
		} else if (select_option_y == 110) {
			select_option_y = 310;
		} else if (select_option_y == 120) {
			select_option_y = 320;
		} else {
			select_option_y = SELECT_OPTION_ORIGIN_Y;
		}
		glutPostRedisplay();
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
		 		current_view = VIEW_TUTORIAL;
				glutDisplayFunc(drawViewTutorial);
		 		glutPostRedisplay();
			}

			//BOTĂO INICIAR NA VIEW_TUTORIAL
			if(x>=601 && x<=697  && y>=420 && y<=468 && current_view == VIEW_TUTORIAL) {
		 		current_view = VIEW_GAME;
				glutDisplayFunc(drawViewGame);
		 		glutPostRedisplay();
			}

			//BOTĂO NEXT NA VIEW_LEARN
			if(x>=601 && x<=697  && y>=420 && y<=468 && current_view == VIEW_LEARN) {
		 		current_view = VIEW_B;
		 		glutPostRedisplay();
			}

			//BOTĂO JOGAR NOVAMENTE NA VIEW_SCORE
			if(x>=225 && x<=520  && y>=256 && y<=303 && current_view == VIEW_SCORE) {
		 		current_view = VIEW_TUTORIAL;
				glutDisplayFunc(drawViewTutorial);
		 		glutPostRedisplay();
			}

			//BOTĂO MENU NA VIEW_SCORE
			if(x>=251 && x<=497  && y>=351 && y<=396 && current_view == VIEW_SCORE) {
		 		current_view = VIEW_A;
		 		glutDisplayFunc(drawViewA);
		 		glutPostRedisplay();
			}
		}
	}
}

void verifyObject() {
	map <int, string> values;

	values[120] = "papel";
	values[170] = "plastico";
	values[220] = "metal";
	values[270] = "vidro";
	values[320] = "nao reciclavel";

	score_should_be += current_object_point;

	if (current_object_category == values[select_option_y]) {
		current_score += current_object_point;
		has_match = true;
	} else {
		has_match = false;
	}
	// apaga o objeto anterior da lista de objetos para não repetir
	objects.erase(objects.begin() + current_object_pos);
	// incrementa o objeto: x de y
	nextObject();
	// pega novo objeto de uma posição aleatória da lista de objetos
	current_object_pos = getRandomRange();
	strcpy(current_object_name, objects.at(current_object_pos).getObjectName());
	strcpy(current_object_category, objects.at(current_object_pos).getObjectCategory());
	current_object_point = objects.at(current_object_pos).getObjectPoint();
}

void keyboard (unsigned char key, int x, int y) {	
	if (key == 13 && current_view == VIEW_GAME) {
		can_redisplay = true;

		if (current_object != OBJECTS_PER_LEVEL) {
			verifyObject();
			glutPostRedisplay();
		} else {
			verifyObject();
			percent_score = (current_score * 100)/score_should_be;
			current_object = 1;
			glutDisplayFunc(drawViewScore);
		 	glutPostRedisplay();
		}
	}

	if (key == 27) // ESC PARA SAIR
		exit(0);		
}
