/*

Raimundo Nonato Gomes Neto
Tarefa da Aula 06: Trabalho do Palhaço 2D em OpenGL

*/

#ifdef __APPLE__ // MacOS
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else // Windows e Linux
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#endif

void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * M_PI * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

void drawClown() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glScalef(0.3, 0.3, 1.0);  // Fator de escala para reduzir o tamanho

    glTranslatef(0.0, 2.5, 0.0);  // Translação para mover o palhaço para a posição desejada

    glScalef(1.0, 1.0, 1.0);  // Configura a escala dos eixos X e Y para serem iguais

    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(0, 0, 1, 100); // Cabeça de raio 1

    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(-0.4, 0.4, 0.18, 100); // Olho esquerdo
    drawCircle(0.4, 0.4, 0.18, 100);  // Olho direito

    glColor3f(1.0f, 0.0f, 0.0f); //Cor vermelha
    drawCircle(0, 0, 0.23, 100); // Nariz 

    glColor3f(0.0f, 0.0f, 1.0f);

    //Chapéu
    glBegin(GL_TRIANGLES);
    glVertex2f(-1.15, 1);  
    glVertex2f(1.15, 1);  
    glVertex2f(0, 2.7); 
    glEnd();
	
	//Sorriso
	glColor3f(1.0f, 1.0f, 1.0f); //Cor branca
    
    drawCircle(-0.6, -0.4, 0.1, 100); // Primeiro círculo
    drawCircle(-0.35, -0.6, 0.1, 100); // Segundo círculo
    drawCircle(0, -0.7, 0.1, 100); // Terceiro círculo
    drawCircle(0.35, -0.6, 0.1, 100); // Quarto círculo
    drawCircle(0.6, -0.4, 0.1, 100); // Quinto círculo
	
	//Torso do palhaço
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-1, -1); // Canto superior esquerdo
    glVertex2f(1, -1);  // Canto superior direito
    glVertex2f(1, -3.5);    // Canto inferior direito
    glVertex2f(-1, -3.5);   // Canto inferior esquerdo
    glEnd();
    
    // Circulos verdes no tronco
	glColor3f(0.5f, 1.0f, 0.0f);  // Cor verde limão
	
	// Primeiro círculo
	drawCircle(0, -1.5, 0.25, 100);
	
	// Segundo círculo
	drawCircle(0, -2.3, 0.25, 100);
	
	// Terceiro círculo
	drawCircle(0, -3, 0.25, 100);
	    
    // Braços
    glColor3f(1.0f, 0.0f, 0.0f); // Cor vermelha

    // Ângulo de inclinação (em graus)
    float anguloInclinacao = -15.0f;

    // Translação para a altura dos ombros
    glPushMatrix();
    glTranslatef(0.0, -1.0, 0.0);
	
    // Braço esquerdo
    glPushMatrix();
    glTranslatef(-2.25, 0.75, 0.0);  // Ajuste a posição do braço esquerdo
    glRotatef(anguloInclinacao, 0, 0, 1); // Rotação em torno do eixo Z 
    glBegin(GL_QUADS);
    glVertex2f(1.4, -0.4);  // Coordenada da extremidade superior esquerda do braço esquerdo
    glVertex2f(-1.3, -0.4);  // Coordenada da extremidade superior direita do braço esquerdo
    glVertex2f(-1.3, -1.6);  // Coordenada da extremidade inferior direita do braço esquerdo
    glVertex2f(1.5, -1.7);  // Coordenada da extremidade inferior esquerda do braço esquerdo
    glEnd();

    // Mão esquerda
    glColor3f(1.0f, 1.0f, 0.0f);  // Cor amarela
    glBegin(GL_QUADS);
    glVertex2f(-2.1, -0.4);  // Coordenada da extremidade superior esquerda da mão esquerda
    glVertex2f(-1.45, -0.4);  // Coordenada da extremidade superior direita da mão esquerda
    glVertex2f(-1.45, -1.6);  // Coordenada da extremidade inferior direita da mão esquerda
    glVertex2f(-2.1, -1.6);  // Coordenada da extremidade inferior esquerda da mão esquerda
    glEnd();

    glPopMatrix();  // Restaurar a matriz de transformação

    // Braço direito
    glPushMatrix();
    glTranslatef(2.25, 0.75, 0.0);  // Ajuste a posição do braço direito
    glRotatef(-anguloInclinacao, 0, 0, 1); // Rotação em torno do eixo Z (inclinação)

    glScalef(-1.0, 1.0, 1.0);

    // Braço direito
    glColor3f(1.0f, 0.0f, 0.0f);  // Cor vermelha
    glBegin(GL_QUADS);
    glVertex2f(1.4, -0.4);  // Coordenada da extremidade superior esquerda do braço direito
    glVertex2f(-1.3, -0.4);  // Coordenada da extremidade superior direita do braço direito
    glVertex2f(-1.3, -1.6);  // Coordenada da extremidade inferior direita do braço direito
    glVertex2f(1.5, -1.7);  // Coordenada da extremidade inferior esquerda do braço direito
    glEnd();

    // Mão direita 
    glColor3f(1.0f, 1.0f, 0.0f);  // Cor amarela
    glBegin(GL_QUADS);
    glVertex2f(-2.1, -0.4);  // Coordenada da extremidade superior esquerda da mão esquerda
    glVertex2f(-1.45, -0.4);  // Coordenada da extremidade superior direita da mão esquerda
    glVertex2f(-1.45, -1.6);  // Coordenada da extremidade inferior direita da mão esquerda
    glVertex2f(-2.1, -1.6);  // Coordenada da extremidade inferior esquerda da mão esquerda
    glEnd();

    glPopMatrix();  // Restaurar a matriz de transformação

    // Pernas
    glColor3f(1.0f, 0.0f, 0.0f); 

    // Perna esquerda
    glPushMatrix();  // Salva a matriz de transformação atual
    glTranslatef(-0.01, -2.9, 0.0);  // Move para a posição da perna esquerda
    glRotatef(-16.0, 0, 0, 1);  // Gira a perna esquerda

    glBegin(GL_QUADS);
    glVertex2f(-1.01, 0);  // Coordenada da extremidade superior esquerda da perna esquerda
    glVertex2f(-0.01, 0);  // Coordenada da extremidade superior direita da perna esquerda
    glVertex2f(-0.01, -3);  // Coordenada da extremidade inferior direita da perna esquerda
    glVertex2f(-1.01, -3);  // Coordenada da extremidade inferior esquerda da perna esquerda
    glEnd();

    glPopMatrix();  // Restaura a matriz de transformação

    // Perna direita
    glPushMatrix();  // Salva a matriz de transformação atual
    glTranslatef(0.07, -2.9, 0.0);  // Move para a posição da perna direita
    glRotatef(16, 0, 0, 1);  // Gira a perna direita

    glBegin(GL_QUADS);
    glVertex2f(0.01, 0);  // Coordenada da extremidade superior esquerda da perna direita
    glVertex2f(1, 0);  // Coordenada da extremidade superior direita da perna direita
    glVertex2f(1, -3);  // Coordenada da extremidade inferior direita da perna direita
    glVertex2f(0.01, -3);  // Coordenada da extremidade inferior esquerda da perna direita
    glEnd();

    glPopMatrix();  // Restaura a matriz de transformação
                        
    // Pés 
	glColor3f(1.0f, 1.0f, 0.0f);  // Cor amarela
	
	// Pé esquerdo
	glPushMatrix();  // Salva a matriz de transformação atual
	glTranslatef(-1.7, -6.5, 0.0);  // Move para a posição do pé esquerdo
	glRotatef(-110, 0, 0, 1);  // Utiliza o mesmo ângulo que a perna esquerda
	
	glBegin(GL_QUADS);
	glVertex2f(-0.7, 0);  // Coordenada da extremidade superior esquerda do pé esquerdo
	glVertex2f(-0.1, 0);  // Coordenada da extremidade superior direita do pé esquerdo
	glVertex2f(-0.1, -2);  // Coordenada da extremidade inferior direita do pé esquerdo
	glVertex2f(-0.7, -2);  // Coordenada da extremidade inferior esquerda do pé esquerdo
	glEnd();
	
	glPopMatrix();  // Restaura a matriz de transformação
	
	// Pé direito
	glPushMatrix();  // Salva a matriz de transformação atual
	glTranslatef(1.7, -6.5, 0.0);  // Move para a posição do pé direito
	glRotatef(110, 0, 0, 1);  // Utiliza o mesmo ângulo que a perna direita
	
	glBegin(GL_QUADS);
	glVertex2f(0.7, 0);  // Coordenada da extremidade superior esquerda do pé direito
	glVertex2f(0.1, 0);  // Coordenada da extremidade superior direita do pé direito
	glVertex2f(0.1, -2);  // Coordenada da extremidade inferior direita do pé direito
	glVertex2f(0.7, -2);  // Coordenada da extremidade inferior esquerda do pé direito
	glEnd();
	
	glPopMatrix();  // Restaura a matriz de transformação

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
    float aspectRatio = (float)windowWidth / (float)windowHeight;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (aspectRatio > 1) {
        glOrtho(-2 * aspectRatio, 2 * aspectRatio, -2, 2, -1, 1);
    } else {
        glOrtho(-2, 2, -2 / aspectRatio, 2 / aspectRatio, -1, 1);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    drawClown();

    glutSwapBuffers();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(900, 700);
    glutCreateWindow("Palhaço 2D");

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
