/* Hello Triangle - c�digo adaptado de https://learnopengl.com/#!Getting-started/Hello-Triangle
 *
 * Adaptado por Mateus de Souza de -> Rossana Baptista Queiroz
 * para a disciplina de Processamento Gr�fico - Unisinos
 * Vers�o inicial: 7/4/2017
 * �ltima atualiza��o em 27/09/2021
 *
 */

#include <iostream>
#include <string>
#include <assert.h>
#include <cmath>

using namespace std;

// GLAD
#include <glad/glad.h>

// GLFW
#include <GLFW/glfw3.h>

#include "Shader.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


// Prot�tipo da fun��o de callback de teclado
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// Prot�tipos das fun��es
int setupGeometry();

// Dimens�es da janela (pode ser alterado em tempo de execu��o)
const GLuint WIDTH = 800, HEIGHT = 600;


// Fun��o MAIN
int main()
{
	// Inicializa��o da GLFW
	glfwInit();

	// Cria��o da janela GLFW
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Ola Quadradinhos", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	// Fazendo o registro da fun��o de callback para a janela GLFW
	glfwSetKeyCallback(window, key_callback);

	// GLAD: carrega todos os ponteiros d fun��es da OpenGL
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;

	}

	// Obtendo as informa��es de vers�o
	const GLubyte* renderer = glGetString(GL_RENDERER); /* get renderer string */
	const GLubyte* version = glGetString(GL_VERSION); /* version as a string */
	cout << "Renderer: " << renderer << endl;
	cout << "OpenGL version supported " << version << endl;

	// Definindo as dimens�es da viewport com as mesmas dimens�es da janela da aplica��o
	int width, height;

	// Compilando e buildando o programa de shader
	//GLuint shaderID = setupShader();
	Shader* shader = new Shader("./shaders/transforms.vs", "./shaders/transforms.fs");

	// Gerando um buffer simples, com a geometria de um tri�ngulo
	GLuint VAO = setupGeometry();

	shader->Use();

	// Enviando a cor desejada (vec4) para o fragment shader
	// Utilizamos a vari�veis do tipo uniform em GLSL para armazenar esse tipo de info
	// que n�o est� nos buffers
	GLint colorLoc = glGetUniformLocation(shader->Program, "inputColor");
	assert(colorLoc > -1);

	glm::mat4 projection = glm::mat4(1);
	double xmin = 0.0, xmax = 800.0, ymin = 0.0, ymax = 600.0;

	projection = glm::ortho(xmin, xmax, ymin, ymax, -1.0, 1.0);

	GLint projLoc = glGetUniformLocation(shader->Program, "projection");
	glUniformMatrix4fv(projLoc, 1, FALSE, glm::value_ptr(projection));

	glm::mat4 model = glm::mat4(1);

	model = glm::translate(model, glm::vec3(400, 300, 0.0));
	//model = glm::rotate(model, glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, glm::vec3(200, 100, 1.0));

	GLint modelLoc = glGetUniformLocation(shader->Program, "model");

	int n = 0;

	GLfloat azulx[6] = {  {50}, {350}, {250}, {350}, {250}, {550} };
	GLfloat azuly[6] = { {550}, {450}, {350}, {250}, {150},  {50} };

	GLfloat laranjax[6] = { {150},  {50}, {550},  {50}, {550}, {450} };
	GLfloat laranjay[6] = { {550}, {450}, {350}, {250}, {150},  {50} };

	GLfloat verdex[6] = { {250}, {450}, {350}, {250}, {150}, {350} };
	GLfloat verdey[6] = { {550}, {450}, {350}, {250}, {150},  {50} };

	GLfloat amarelox[6] = { {350}, {150},  {50}, {550}, {450}, {250} };
	GLfloat amareloy[6] = { {550}, {450}, {350}, {250}, {150},  {50} };

	GLfloat roxox[6] = { {450}, {550}, {150}, {450},  {50}, {150} };
	GLfloat roxoy[6] = { {550}, {450}, {350}, {250}, {150},  {50} };

	GLfloat magentax[6] = { {550}, {250}, {450}, {150}, {350}, {50} };
	GLfloat magentay[6] = { {550}, {450}, {350}, {250}, {150}, {50} };

	// Loop da aplica��o - "game loop"
	while (!glfwWindowShouldClose(window))
	{
		// Checa se houveram eventos de input (key pressed, mouse moved etc.) e chama as fun��es de callback correspondentes
		glfwPollEvents();

		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);

		// Limpa o buffer de cor
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //cor de fundo
		glClear(GL_COLOR_BUFFER_BIT);

		glLineWidth(10);
		glPointSize(10);


		//Linha 1
		for (n = 0; n <=5; n++)
		{
			//Quadrados azuis
			model = glm::mat4(1); //matriz identidade

			//model = glm::translate(model, glm::vec3(50 + (n * 100), 550, 0.0));
			model = glm::translate(model, glm::vec3(azulx[n], azuly[n], 0.0));
			model = glm::scale(model, glm::vec3(100, 100, 1.0));

			glUniformMatrix4fv(modelLoc, 1, FALSE, glm::value_ptr(model));

			glUniformMatrix4fv(projLoc, 1, FALSE, glm::value_ptr(projection));

			// Chamada de desenho - drawcall
			// Poligono Preenchido - GL_TRIANGLES
			glUniform4f(colorLoc, 0.0f, 0.0f, 1.0f, 1.0f);

			glBindVertexArray(VAO);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);
		}
		
		//Linha 2
		for (n = 0; n <= 5; n++)
		{
			//Quadrados azuis
			model = glm::mat4(1); //matriz identidade

			model = glm::translate(model, glm::vec3(laranjax[n], laranjay[n], 0.0));
			model = glm::scale(model, glm::vec3(100, 100, 1.0));

			glUniformMatrix4fv(modelLoc, 1, FALSE, glm::value_ptr(model));

			glUniformMatrix4fv(projLoc, 1, FALSE, glm::value_ptr(projection));

			// Chamada de desenho - drawcall
			// Poligono Preenchido - GL_TRIANGLES
			glUniform4f(colorLoc, 1.0f, 0.55f, 0.015f, 1.0f);

			glBindVertexArray(VAO);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);
		}

		//Linha 3
		for (n = 0; n <= 5; n++)
		{
			//Quadrados azuis
			model = glm::mat4(1); //matriz identidade

			model = glm::translate(model, glm::vec3(verdex[n], verdey[n], 0.0));
			model = glm::scale(model, glm::vec3(100, 100, 1.0));

			glUniformMatrix4fv(modelLoc, 1, FALSE, glm::value_ptr(model));

			glUniformMatrix4fv(projLoc, 1, FALSE, glm::value_ptr(projection));

			// Chamada de desenho - drawcall
			// Poligono Preenchido - GL_TRIANGLES
			glUniform4f(colorLoc, 0.03f, 0.77f, 0.09f, 1.0f);

			glBindVertexArray(VAO);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);
		}

		//Linha 4
		for (n = 0; n <= 5; n++)
		{
			//Quadrados azuis
			model = glm::mat4(1); //matriz identidade

			model = glm::translate(model, glm::vec3(amarelox[n], amareloy[n], 0.0));
			model = glm::scale(model, glm::vec3(100, 100, 1.0));

			glUniformMatrix4fv(modelLoc, 1, FALSE, glm::value_ptr(model));

			glUniformMatrix4fv(projLoc, 1, FALSE, glm::value_ptr(projection));

			// Chamada de desenho - drawcall
			// Poligono Preenchido - GL_TRIANGLES
			glUniform4f(colorLoc, 0.9f, 0.9f, 0.0f, 1.0f);

			glBindVertexArray(VAO);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);
		}

		//Linha 5
		for (n = 0; n <= 5; n++)
		{
			//Quadrados azuis
			model = glm::mat4(1); //matriz identidade

			model = glm::translate(model, glm::vec3(roxox[n], roxoy[n], 0.0));
			model = glm::scale(model, glm::vec3(100, 100, 1.0));

			glUniformMatrix4fv(modelLoc, 1, FALSE, glm::value_ptr(model));

			glUniformMatrix4fv(projLoc, 1, FALSE, glm::value_ptr(projection));

			// Chamada de desenho - drawcall
			// Poligono Preenchido - GL_TRIANGLES
			glUniform4f(colorLoc, 0.56f, 0.18f, 0.9f, 1.0f);

			glBindVertexArray(VAO);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);
		}

		//Linha 6
		for (n = 0; n <= 5; n++)
		{
			//Quadrados azuis
			model = glm::mat4(1); //matriz identidade

			model = glm::translate(model, glm::vec3(magentax[n], magentay[n], 0.0));
			model = glm::scale(model, glm::vec3(100, 100, 1.0));

			glUniformMatrix4fv(modelLoc, 1, FALSE, glm::value_ptr(model));

			glUniformMatrix4fv(projLoc, 1, FALSE, glm::value_ptr(projection));

			// Chamada de desenho - drawcall
			// Poligono Preenchido - GL_TRIANGLES
			glUniform4f(colorLoc, 1.0f, 0.0f, 1.0f, 1.0f);

			glBindVertexArray(VAO);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);
		}

		glfwSwapBuffers(window);
	}


	// Pede pra OpenGL desalocar os buffers
	glDeleteVertexArrays(1, &VAO);
	// Finaliza a execu��o da GLFW, limpando os recursos alocados por ela
	glfwTerminate();
	return 0;
}

// Fun��o de callback de teclado - s� pode ter uma inst�ncia (deve ser est�tica se
// estiver dentro de uma classe) - � chamada sempre que uma tecla for pressionada
// ou solta via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

// Esta fun��o est� bastante harcoded - objetivo � criar os buffers que armazenam a 
// geometria de um tri�ngulo
// Apenas atributo coordenada nos v�rtices
// 1 VBO com as coordenadas, VAO com apenas 1 ponteiro para atributo
// A fun��o retorna o identificador do VAO

int setupGeometry()
{
	GLfloat vertices[] = {
	-0.5f,  0.5f, 0.0f, //top left 
	 0.5f,  0.5f, 0.0f, //top right
	 0.5f, -0.5f, 0.0f, //bottom right
	-0.5f, -0.5f, 0.0f, //bottom left
	};

	GLuint indices[] = {
		0, 1, 2, //primeiro triangulo
		0, 2, 3, //segundo triangulo
	};

	GLuint VBO, VAO, EBO;

	//Gera��o do identificador do VBO
	glGenBuffers(1, &VBO);
	//Faz a conex�o (vincula) do buffer como um buffer de array
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//Envia os dados do array de floats para o buffer da OpenGl
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//Gera��o do identificador do VAO (Vertex Array Object)
	glGenVertexArrays(1, &VAO);
	// Vincula (bind) o VAO primeiro, e em seguida  conecta e seta o(s) buffer(s) de v�rtices
	// e os ponteiros para os atributos 
	glBindVertexArray(VAO);
	//Para cada atributo do vertice, criamos um "AttribPointer" (ponteiro para o atributo), indicando: 
	// Localiza��o no shader * (a localiza��o dos atributos devem ser correspondentes no layout especificado no vertex shader)
	// Numero de valores que o atributo tem (por ex, 3 coordenadas xyz) 
	// Tipo do dado
	// Se est� normalizado (entre zero e um)
	// Tamanho em bytes 
	// Deslocamento a partir do byte zero 
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	//Set up index buffer
	glGenBuffers(1, &EBO); //Create buffer space on the GPU for the index buffer

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	// Observe que isso � permitido, a chamada para glVertexAttribPointer registrou o VBO como o objeto de buffer de v�rtice 
	// atualmente vinculado - para que depois possamos desvincular com seguran�a
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Desvincula o VAO (� uma boa pr�tica desvincular qualquer buffer ou array para evitar bugs medonhos)
	glBindVertexArray(0);

	return VAO;
}