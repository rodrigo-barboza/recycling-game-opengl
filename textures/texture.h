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


void loadImage(GLuint tex_id, std::string filePath) {
	unsigned char* imgData;
	int width, height, channels;
	
	imgData = stbi_load(filePath.c_str(),&width,&height,&channels,4);
	if(imgData) {
		glBindTexture(GL_TEXTURE_2D, tex_id);
		glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,imgData);
	
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
		
		stbi_image_free(imgData);
	}
	else {
		std::cout<<"ERRO! NAO FOI POSSIVEL CARREGAR A TEXTURA!"<< filePath.c_str() << std::endl;
	}
}

void applyTexture(int random) {
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
	glGenTextures(15, textureId);
	
	glTranslatef(85, 20, 0);
	// Papel Reciclavel
	loadImage(textureId[0],"textures/images/caixaPapelao.jpg");
	loadImage(textureId[1],"textures/images/sacoPapel.jpg");
	loadImage(textureId[2],"textures/images/folhaPapel.jpg");
	// Vidro Reciclavel
	loadImage(textureId[3],"textures/images/copoQuebrado.jpg");
	loadImage(textureId[4],"textures/images/garrafaCerveja.png");
	loadImage(textureId[5],"textures/images/tacaQuebrada.jpg");
	// Metal Reciclavel
	loadImage(textureId[6],"textures/images/tampagarrafa.jpg");
	loadImage(textureId[7],"textures/images/latasAmassadas.jpg");
	loadImage(textureId[8],"textures/images/latavelha.jpg");
	// Plastico Reciclavel
	loadImage(textureId[9],"textures/images/garrafaPET.jpg");
	loadImage(textureId[10],"textures/images/embalagemPlastica.jpg");
	loadImage(textureId[11],"textures/images/sacosPlasticos.png");
	// Nao Reciclavel
	loadImage(textureId[12],"textures/images/espelhoQuebrado2.jpg");
	loadImage(textureId[13],"textures/images/lampadaQueimada.jpg");
	loadImage(textureId[14],"textures/images/esponjaDeAco.jpg");
	    
    
	drawTextureField(225, 525, 10, 90, textureId[10]);
}
