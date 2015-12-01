#include <gl/glut.h>
#include "Jogo.hpp"

int main(int argc, char **argv) {

    #ifdef _WIN32
        #include <Windows.h>
        //FreeConsole();
    #endif

	Jogo::getInstance().run();
	return 0;
}
//#include "Jogo.hpp"
//#include "Avioes.hpp"
//#include <gl/glut.h>
//#include <math.h>
//#include <iostream>
//#include "Score.hpp"
//using namespace std;
//
//
//Me264 *s = new Me264(-45.0, 0.0, (float)20 / 10000, nullptr);
//
//void desenha(void) {
//    glClear(GL_COLOR_BUFFER_BIT);
//    // desenha o primeiro bloco atiraador
//    glPushMatrix();
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-100, 100, -100, 100);
//    glTranslatef(120, 0, 0);
//    glScalef(2.5, 4, 0);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    s->desenha();
//    glPopMatrix();
//    glutSwapBuffers();
//}
//
//
//int main(int argc, char **argv) {
//
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowSize(1280, 720);
//    glutInitWindowPosition((GetSystemMetrics(SM_CXSCREEN) - 1280) / 2, (GetSystemMetrics(SM_CYSCREEN) - 720) / 2);
//    glutCreateWindow("Jogo");
//    glutDisplayFunc(desenha);
//    glClearColor(1, 1, 1, 1);
//    glutMainLoop();
//
//    return 0;
//}
 