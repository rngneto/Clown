/*

Raimundo Nonato Gomes Neto
Tarefa da Aula 06: Trabalho do Palha�o 2D em OpenGL

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

    glTranslatef(0.0, 2.5, 0.0);  // Transla��o para mover o palha�o para a posi��o desejada

    glScalef(1.0, 1.0, 1.0);  // Configura a escala dos eixos X e Y para serem iguais

    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(0, 0, 1, 100); // Cabe�a de raio 1

    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(-0.4, 0.4, 0.18, 100); // Olho esquerdo
    drawCircle(0.4, 0.4, 0.18, 100);  // Olho direito

    glColor3f(1.0f, 0.0f, 0.0f); //Cor vermelha
    drawCircle(0, 0, 0.23, 100); // Nariz 

    glColor3f(0.0f, 0.0f, 1.0f);

    //Chap�u
    glBegin(GL_TRIANGLES);
    glVertex2f(-1.15, 1);  
    glVertex2f(1.15, 1);  
    glVertex2f(0, 2.7); 
    glEnd();
	
	//Sorriso
	glColor3f(1.0f, 1.0f, 1.0f); //Cor branca
    
    drawCircle(-0.6, -0.4, 0.1, 100); // Primeiro c�rculo
    drawCircle(-0.35, -0.6, 0.1, 100); // Segundo c�rculo
    drawCircle(0, -0.7, 0.1, 100); // Terceiro c�rculo
    drawCircle(0.35, -0.6, 0.1, 100); // Quarto c�rculo
    drawCircle(0.6, -0.4, 0.1, 100); // Quinto c�rculo
	
	//Torso do palha�o
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-1, -1); // Canto superior esquerdo
    glVertex2f(1, -1);  // Canto superior direito
    glVertex2f(1, -3.5);    // Canto inferior direito
    glVertex2f(-1, -3.5);   // Canto inferior esquerdo
    glEnd();
    
    // Circulos verdes no tronco
	glColor3f(0.5f, 1.0f, 0.0f);  // Cor verde lim�o
	
	// Primeiro c�rculo
	drawCircle(0, -1.5, 0.25, 100);
	
	// Segundo c�rculo
	drawCircle(0, -2.3, 0.25, 100);
	
	// Terceiro c�rculo
	drawCircle(0, -3, 0.25, 100);
	    
    // Bra�os
    glColor3f(1.0f, 0.0f, 0.0f); // Cor vermelha

    // �ngulo de inclina��o (em graus)
    float anguloInclinacao = -15.0f;

    // Transla��o para a altura dos ombros
    glPushMatrix();
    glTranslatef(0.0, -1.0, 0.0);
	
    // Bra�o esquerdo
    glPushMatrix();
    glTranslatef(-2.25, 0.75, 0.0);  // Ajuste a posi��o do bra�o esquerdo
    glRotatef(anguloInclinacao, 0, 0, 1); // Rota��o em torno do eixo Z 
    glBegin(GL_QUADS);
    glVertex2f(1.4, -0.4);  // Coordenada da extremidade superior esquerda do bra�o esquerdo
    glVertex2f(-1.3, -0.4);  // Coordenada da extremidade superior direita do bra�o esquerdo
    glVertex2f(-1.3, -1.6);  // Coordenada da extremidade inferior direita do bra�o esquerdo
    glVertex2f(1.5, -1.7);  // Coordenada da extremidade inferior esquerda do bra�o esquerdo
    glEnd();

    // M�o esquerda
    glColor3f(1.0f, 1.0f, 0.0f);  // Cor amarela
    glBegin(GL_QUADS);
    glVertex2f(-2.1, -0.4);  // Coordenada da extremidade superior esquerda da m�o esquerda
    glVertex2f(-1.45, -0.4);  // Coordenada da extremidade superior direita da m�o esquerda
    glVertex2f(-1.45, -1.6);  // Coordenada da extremidade inferior direita da m�o esquerda
    glVertex2f(-2.1, -1.6);  // Coordenada da extremidade inferior esquerda da m�o esquerda
    glEnd();

    glPopMatrix();  // Restaurar a matriz de transforma��o

    // Bra�o direito
    glPushMatrix();
    glTranslatef(2.25, 0.75, 0.0);  // Ajuste a posi��o do bra�o direito
    glRotatef(-anguloInclinacao, 0, 0, 1); // Rota��o em torno do eixo Z (inclina��o)

    glScalef(-1.0, 1.0, 1.0);

    // Bra�o direito
    glColor3f(1.0f, 0.0f, 0.0f);  // Cor vermelha
    glBegin(GL_QUADS);
    glVertex2f(1.4, -0.4);  // Coordenada da extremidade superior esquerda do bra�o direito
    glVertex2f(-1.3, -0.4);  // Coordenada da extremidade superior direita do bra�o direito
    glVertex2f(-1.3, -1.6);  // Coordenada da extremidade inferior direita do bra�o direito
    glVertex2f(1.5, -1.7);  // Coordenada da extremidade inferior esquerda do bra�o direito
    glEnd();

    // M�o direita 
    glColor3f(1.0f, 1.0f, 0.0f);  // Cor amarela
    glBegin(GL_QUADS);
    glVertex2f(-2.1, -0.4);  // Coordenada da extremidade superior esquerda da m�o esquerda
    glVertex2f(-1.45, -0.4);  // Coordenada da extremidade superior direita da m�o esquerda
    glVertex2f(-1.45, -1.6);  // Coordenada da extremidade inferior direita da m�o esquerda
    glVertex2f(-2.1, -1.6);  // Coordenada da extremidade inferior esquerda da m�o esquerda
    glEnd();

    glPopMatrix();  // Restaurar a matriz de transforma��o

    // Pernas
    glColor3f(1.0f, 0.0f, 0.0f); 

    // Perna esquerda
    glPushMatrix();  // Salva a matriz de transforma��o atual
    glTranslatef(-0.01, -2.9, 0.0);  // Move para a posi��o da perna esquerda
    glRotatef(-16.0, 0, 0, 1);  // Gira a perna esquerda

    glBegin(GL_QUADS);
    glVertex2f(-1.01, 0);  // Coordenada da extremidade superior esquerda da perna esquerda
    glVertex2f(-0.01, 0);  // Coordenada da extremidade superior direita da perna esquerda
    glVertex2f(-0.01, -3);  // Coordenada da extremidade inferior direita da perna esquerda
    glVertex2f(-1.01, -3);  // Coordenada da extremidade inferior esquerda da perna esquerda
    glEnd();

    glPopMatrix();  // Restaura a matriz de transforma��o

    // Perna direita
    glPushMatrix();  // Salva a matriz de transforma��o atual
    glTranslatef(0.07, -2.9, 0.0);  // Move para a posi��o da perna direita
    glRotatef(16, 0, 0, 1);  // Gira a perna direita

    glBegin(GL_QUADS);
    glVertex2f(0.01, 0);  // Coordenada da extremidade superior esquerda da perna direita
    glVertex2f(1, 0);  // Coordenada da extremidade superior direita da perna direita
    glVertex2f(1, -3);  // Coordenada da extremidade inferior direita da perna direita
    glVertex2f(0.01, -3);  // Coordenada da extremidade inferior esquerda da perna direita
    glEnd();

    glPopMatrix();  // Restaura a matriz de transforma��o
                        
    // P�s 
	glColor3f(1.0f, 1.0f, 0.0f);  // Cor amarela
	
	// P� esquerdo
	glPushMatrix();  // Salva a matriz de transforma��o atual
	glTranslatef(-1.7, -6.5, 0.0);  // Move para a posi��o do p� esquerdo
	glRotatef(-110, 0, 0, 1);  // Utiliza o mesmo �ngulo que a perna esquerda
	
	glBegin(GL_QUADS);
	glVertex2f(-0.7, 0);  // Coordenada da extremidade superior esquerda do p� esquerdo
	glVertex2f(-0.1, 0);  // Coordenada da extremidade superior direita do p� esquerdo
	glVertex2f(-0.1, -2);  // Coordenada da extremidade inferior direita do p� esquerdo
	glVertex2f(-0.7, -2);  // Coordenada da extremidade inferior esquerda do p� esquerdo
	glEnd();
	
	glPopMatrix();  // Restaura a matriz de transforma��o
	
	// P� direito
	glPushMatrix();  // Salva a matriz de transforma��o atual
	glTranslatef(1.7, -6.5, 0.0);  // Move para a posi��o do p� direito
	glRotatef(110, 0, 0, 1);  // Utiliza o mesmo �ngulo que a perna direita
	
	glBegin(GL_QUADS);
	glVertex2f(0.7, 0);  // Coordenada da extremidade superior esquerda do p� direito
	glVertex2f(0.1, 0);  // Coordenada da extremidade superior direita do p� direito
	glVertex2f(0.1, -2);  // Coordenada da extremidade inferior direita do p� direito
	glVertex2f(0.7, -2);  // Coordenada da extremidade inferior esquerda do p� direito
	glEnd();
	
	glPopMatrix();  // Restaura a matriz de transforma��o

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
    glutCreateWindow("Palha�o 2D");

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
