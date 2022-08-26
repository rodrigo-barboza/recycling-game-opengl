# recycling-game-opengl
Game developed in opengl about recycling and sustainability

## Aplicação: Jogo da Reciclagem

<aside>
💡 O jogo tem como objetivo ensinar crianças de 4-8 anos a como fazer o descarte do lixo, de forma adequada, de acordo com a coleta seletiva, induzidos as crianças a desenvolverem uma intuição a certa de tópicos tais como: reciclagem e sustentabilidade. O jogabilidade se dá da seguinte forma: Aparecerão objetos que, de forma randômica, serão apresentados ao jogador. A missão principal da criança é destinar o lixo para a lixeira correta, indicada pelos botões coloridos localizados à direita do objeto. As possibilidades de escolha são:  coletor azul para objetos de papel, vermelho para objetos de plástico, amarelo (metal), verde (vidro) ou cinza (não reciclável). O usuário também poderá ver informações de cada tipo de coletor antes de tomar uma decisão. Cada objeto terá seu grau de dificuldade, alguns valerão mais pontos do que outros e ao final da partida será mostrado a pontuação do jogador.

</aside>

---

## Links úteis

- [https://www.dca.fee.unicamp.br/courses/IA725/1s2006/program/samples.html](https://www.dca.fee.unicamp.br/courses/IA725/1s2006/program/samples.html)
- [https://users.cs.jmu.edu/bernstdh/web/common/lectures/summary_opengl-text.php](https://users.cs.jmu.edu/bernstdh/web/common/lectures/summary_opengl-text.php) (aqui tem as fontes do opengl)
- [https://learnopengl.com/Lighting/Materials](https://learnopengl.com/Lighting/Materials)
- [https://www.inf.pucrs.br/~manssour/OpenGL/Transformacoes.html](https://www.inf.pucrs.br/~manssour/OpenGL/Transformacoes.html)

## Especificações técnicas:

**Para facilitar na padronização do código**

- Nomes de variáveis e métodos em inglês
- Nomes de variáveis em **snake_case** com letras minúsculas
- Nomes de constantes em **SNAKE_CASE** com letras maiúsculas
- Nomes de métodos em **camelCase()** com um espaço antes do abre chaves

**Estrutura do código fonte**

```cpp
// Importações de libs padrões
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <GL/glut.h>
#include <cmath>

// Importações de libs externas
#include "view_a.h"
#include "view_b.h"
#include "view_game.h"

// Macros (em caixa alta)
#define SLATE_BLUE    glColor3f(0.000000, 0.498000, 1.000000)

// Constantes
const type SNAKE_CASE = 1312;

// Variáveis globais
type snake_case = 1312;

// Assinatura de métodos
void drawSquare(int, int, int, int);
void drawPlayer(int, int, int, int);
void drawCircle(int, int, int, int, int);

// Main
int main (void) {}

// Métodos
void drawSquare(int, int, int, int) {}
void drawPlayer(int, int, int, int) {}
void drawCircle(int, int, int, int, int) {}
```

**Nossas bibliotecas .h serão divididas em**
1 - "view_a.h"
2 - "view_b.h"
3 - "view_game.h"
4 - "view_score.h"
5 - "view_learn.h"
3 - "objects.h" (objetos que aparecerão no jogo dentro da viewport do objeto)
4 - "special_functions.h" (funções de ação de teclado, mouse, etc)

**Nosso sistema de coordenadas será inteiro**

```cpp
int main (void) {
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);     
		// WINDOWS_WIDTH = 750;
		// WINDOWS_HEIGHT = 500;
		glutInitWindowSize(WINDOWS_WIDTH, WINDOWS_HEIGHT); 
		glutCreateWindow("Jogo da Reciclagem"); 
		// permite o sistema de coordenadas ser inteiro
		gluOrtho2D(0, WINDOWS_WIDTH, WINDOWS_HEIGHT,0);
}
```

**Funções úteis para usar (tiradas da atividade 3 que eu fiz com Edson, [código completo aqui](https://drive.google.com/file/d/1aHDXL6gYQyT6gHN7MfN9cTur63KM7S5c/view?usp=sharing))**

desenha um retângulo com o tamanho width x height, e posiciona nas coordenadas do (shamt_x, shamt_y)

```cpp
void drawSquare(int width, int height, int shamt_x, int shamt_y) {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();   
	glTranslated(shamt_x, shamt_y, 0); 

	glBegin(GL_POLYGON);
		glVertex2i(0, height/2); // bottom-left
		glVertex2i(width, height/2); // bottom-right
		glVertex2f(width, 0); // top-right	
		glVertex2i(0, 0); // top-left			
	glEnd();
	
	glPopMatrix(); 
}
```

![SISTEMA_COORDENADAS.png](https://i.imgur.com/rWNF8j4.png)

**Função para textos**

```cpp
// desenha texto simples
void drawText(void *font, char *string) {
	while(*string)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *string++); 
}

// desenha texto com stroke
void drawTextStroke(void *font, char *string) {  
	// Exibe caractere a caractere
	while(*string)
		glutStrokeCharacter(GLUT_STROKE_ROMAN,*string++); 
}

// exemplo de uso:
glPushMatrix();
		glTranslatef(95,481,0); // posiciona o texto
		glScalef(0.2, 0.2, 0.2); // diminui o tamanho do fonte
		glRotatef(180, 1,0,0); // rotaciona o texto
		glLineWidth(3); // define a espessura da linha
		drawTextStroke(GLUT_STROKE_ROMAN, "opa meu patrão");
glPopMatrix();
```

**Forma de controlar os eventos de cada view**

Teremos uma variável global chamada `current_view` ela será atualizada com a view atual que será o valor das constantes abaixo: 

```cpp
const int VIEW_A = 0;
const int VIEW_B = 1;
const int VIEW_GAME = 2;
const int VIEW_SCORE = 3;
const int VIEW_LEARN = 4;
const int OBJECTS = 5;
const int SPACIAL_FUNCTIONS = 6;
```

Quando eu executar uma ação para alternar entre as views, eu devo atualizar a `current_view` com a view atual:

```cpp
current_view = VIEW_SCORE;
```

Com isso, por exemplo no código de eventos de mouse posso fazer:

```cpp
void mouseEvents (int button, int state, int x, int y) {
	// se for um evento de clique, eu verifico antes em qual view eu estou
	if (current_view == VIEW_MENU) {
		if (button == GLUT_LEFT_BUTTON) {
			getRandomColor(0);
			getRandomColor(1);
			glutDisplayFunc(drawGame);  
		}
	}

	if (current_view == VIEW_GAME) {
		if (button == GLUT_LEFT_BUTTON) {
			if (state == GLUT_DOWN) {
	        	getRandomColor(0);
				getRandomColor(1);
	         }
		}
	}
	
    glutPostRedisplay();
}
```

## Telas

![PROJETO_FINAL_MOCKUP.png](https://i.imgur.com/oRX2Djc.png)

### Divisão de tarefas

| To do | Doing | To review | Done |
| --- | --- | --- | --- |
| Descrição da atividade | (se você for fazer, coloque seu nome aqui e avise no grupo) | (se você concluiu a atividade que estava fazendo coloque o link aqui) | (se você passou pelas etapas anteriores, use o badge de concluído aqui) |
| Código fonte principal (estrutura do projeto) | Rodrigo | https://github.com/rodrigo-barboza/recycling-game-opengl | concluído |
| Procurar se existem objetos já prontos para que possamos utilizar no projeto | Edson | https://github.com/rodrigo-barboza/recycling-game-opengl/tree/edsonblimajr-patch-1 | concluído |
| Fazer lista de objetos que iremos adicionar no jogo | Edson | https://github.com/rodrigo-barboza/recycling-game-opengl/tree/edsonblimajr-patch-2 | concluído |
| view_a | Filipe Alves | https://github.com/rodrigo-barboza/recycling-game-opengl/tree/view-a | concluído |
| view_b | Luan | https://github.com/rodrigo-barboza/recycling-game-opengl/tree/view-score | concluído |
| view_game | Rodrigo | https://github.com/rodrigo-barboza/recycling-game-opengl | concluído |
| view_learn | Luan | https://github.com/rodrigo-barboza/recycling-game-opengl/tree/view-score | concluído |
| view_score | Luan | https://github.com/rodrigo-barboza/recycling-game-opengl/tree/view-score | concluído |
| objects | Edson | https://github.com/rodrigo-barboza/recycling-game-opengl/tree/funcionamentoTextura1 | concluído |
| special_functions | Luan | https://github.com/rodrigo-barboza/recycling-game-opengl/tree/view-score | concluído |
