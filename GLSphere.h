#ifndef GLSPHERE_H
#define GLSPHERE_H

#include "myGLWidget.h"  //Heritage du Widget OpenGL
#include <GL/glu.h> //Intégration des fonctions glu


class GLSphere : public myGLWidget
{
    Q_OBJECT
public:
    explicit GLSphere(QWidget *parent = 0, int longueur = 100, int hauteur = 100);
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

    void setX(double X);
    void setY(double Y);
    void setZ(double Z);
    void setOmega(double omega);
    void setDelta(double delta);

    void setXCons(double XCons);
    void setYCons(double YCons);
    void setZCons(double ZCons);
    void setOmegaCons(double omegaCons);
    void setDeltaCons(double deltaCons);

private:

      GLfloat x_var;
      GLfloat y_var;
      GLfloat z_var;
      double om_var;
      double dl_var;

      GLfloat xCons_var;
      GLfloat yCons_var;
      GLfloat zCons_var;
      double omCons_var;
      double dlCons_var;
};

#endif // GLSPHERE_H
