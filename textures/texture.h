#include <ctime>

void drawTextureField(int width, int height, int shamt_x, int shamt_y, GLuint texId) {
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
		glTranslated(shamt_x, shamt_y, 0); 
		glBindTexture(GL_TEXTURE_2D,texId);     

		glBegin(GL_QUADS);
			glTexCoord2f(0.0,1.0); glVertex2f(0, height/2); // bottom-left
			glTexCoord2f(1.0,1.0); glVertex2f(width, height/2); // bottom-right
			glTexCoord2f(1.0,0.0); glVertex2f(width, 0); // top-right	
			glTexCoord2f(0.0,0.0); glVertex2f(0, 0); // top-left	
		glEnd();
	glPopMatrix(); 
}

void loadObjects() {
	objects.push_back(Object (
		"Caixa de Pepelao",
		"textures/images/caixaPapelao.jpg",
		"papel",
		150
	));

	objects.push_back(Object (
		"Saco de Papel",
		"textures/images/sacoPapel.jpg",
		"papel",
		150
	));

	objects.push_back(Object (
		"Folha de Caderno",
		"textures/images/folhaPapel.jpg",
		"papel",
		140
	));

	objects.push_back(Object (
		"Copo Quebrado",
		"textures/images/copoQuebrado.jpg",
		"vidro",
		200
	));

	objects.push_back(Object (
		"Garrafa de Cerveja",
		"textures/images/garrafaCerveja.png",
		"vidro",
		240
	));

	objects.push_back(Object (
		"Taca Quebrada",
		"textures/images/tacaQuebrada.jpg",
		"vidro",
		210
	));

	objects.push_back(Object (
		"Tampa de Garrafa",
		"textures/images/tampagarrafa.jpg",
		"metal",
		200
	));

	objects.push_back(Object (
		"Latas Amassadas",
		"textures/images/latasAmassadas.jpg",
		"metal",
		240
	));

	objects.push_back(Object (
		"Lata Velha",
		"textures/images/latavelha.jpg",
		"metal",
		250
	));

	objects.push_back(Object (
		"Garrafa PET",
		"textures/images/garrafaPET.jpg",
		"plastico",
		220
	));

	objects.push_back(Object (
		"Embalagem",
		"textures/images/embalagemPlastica.jpg",
		"plastico",
		200
	));

	objects.push_back(Object (
		"Saco",
		"textures/images/sacosPlasticos.png",
		"plastico",
		200
	));

	objects.push_back(Object (
		"Espelho Quebrado",
		"textures/images/espelhoQuebrado2.jpg",
		"nao reciclavel",
		230
	));

	objects.push_back(Object (
		"Lampada Queimada",
		"textures/images/lampadaQueimada.jpg",
		"nao reciclavel",
		240
	));

	objects.push_back(Object (
		"Esponja de Aco",
		"textures/images/esponjaDeAco.jpg",
		"nao reciclavel",
		280
	));
}

int getRandomRange() {
	srand(time(NULL)); 
	return rand() % objects.size();
}

void loadImage(GLuint tex_id, std::string file_path) {
	unsigned char* image_data;
	int width, height, channels;
	
	image_data = stbi_load(file_path.c_str(), &width, &height, &channels, 4);
	if(image_data) {
		glBindTexture(GL_TEXTURE_2D, tex_id);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
	
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		
		stbi_image_free(image_data);
	}
	else {
		cout<< "ERRO! NAO FOI POSSIVEL CARREGAR A TEXTURA!" << file_path.c_str() << endl;
	}
}

void applyTexture() {
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTranslatef(85, 20, 0);
	GLuint textures[1]; 

	if (can_redisplay) {
		current_object_pos = getRandomRange();
	}
	
	textures[current_object] = objects.at(current_object_pos).texture;
	glGenTextures(1, textures);
	loadImage(objects.at(current_object_pos).texture, objects.at(current_object_pos).getObjectPath());
	drawTextureField(225, 525, 10, 90, objects.at(current_object_pos).texture);
	glDisable(GL_TEXTURE_2D);
}
