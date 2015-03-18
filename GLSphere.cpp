#include "GLSphere.h"
#include "fenprincipale.h"
#include <math.h>

GLfloat	rsphr;				// Angle de la sphère par rapport à la scène
GLfloat r = 2.0;                  //Rayon de la sphere
int vitesse;

GLSphere::GLSphere(QWidget *parent, int longueur, int hauteur)
    : myGLWidget(60, parent)
{
    setFixedSize(longueur, hauteur);
}

void GLSphere::setX(double X){
    x_var = (GLfloat)X;
}

void GLSphere::setY(double Y){
    y_var = (GLfloat)Y;
}

void GLSphere::setZ(double Z){
    z_var = (GLfloat)Z;
}

void GLSphere::setOmega(double omega){
    om_var = omega;
}

void GLSphere::setDelta(double delta){
    dl_var = delta;
}


void GLSphere::setXCons(double XCons){
    xCons_var = (GLfloat)XCons;
}

void GLSphere::setYCons(double YCons){
    yCons_var = (GLfloat)YCons;
}

void GLSphere::setZCons(double ZCons){
    zCons_var = (GLfloat)ZCons;
}

void GLSphere::setOmegaCons(double omegaCons){
    omCons_var = omegaCons;
}

void GLSphere::setDeltaCons(double deltaCons){
    dlCons_var = deltaCons;
}


void GLSphere::initializeGL()
{
    glShadeModel(GL_SMOOTH);                                // Active le Smooth Shading
        glClearColor(1.0f, 1.0f, 1.0f, 0.5f);				// Arrière-plan noir
        glClearDepth(1.0f);									// Depth Buffer
        glEnable(GL_DEPTH_TEST);							// Active le Depth Testing
        glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
        glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void GLSphere::resizeGL(int width, int height)              // Proportions respectées quel que soit la taille de la scène
{
    if(height == 0)
        height = 1;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void GLSphere::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // Réinitialisation de l'écran et du buffer de profondeur



        //rsphr=20.0f;										// Incrémente l'angle de la sphère à chaque image
    rsphr=20.0f;
    vitesse = 8;

    //3 Axes
        glLoadIdentity();									// Réinitialisation des matrices du modèle actuel
        glTranslatef(0.0f,0.0f,-6.0f);						// Objet centré en avant plan
        glRotatef(rsphr,1.0f,1.0f,0.0f);					// Rotation de l'objet
        glRotatef(xRot/vitesse, 1.0, 0.0, 0.0);
        glRotatef(yRot/vitesse, 0.0, 1.0, 0.0);
        glRotatef(zRot/vitesse, 0.0, 0.0, 1.0);
        glLineWidth(1);
        glBegin(GL_LINES);
            glColor3f(0.0f,1.0f,1.0f);                               // Couleur bleu ciel : x
            glVertex3f(0.0f,0.0f,-r);                              // Début Axe : x
            glVertex3f(0.0f,0.0f,r);                              // Fin Axe : x
            glColor3f(0.0f,1.0f,0.0f);                               // Couleur verte : y
            glVertex3f(-r,0.0f,0.0f);                              // Début Axe : y
            glVertex3f(r,0.0f,0.0f);                              // Fin Axe : y
            glColor3f(1.0f,0.0f,0.0f);                               // Couleur rouge : z
            glVertex3f(0.0f,-r,0.0f);                              // Début Axe : z
            glVertex3f(0.0f,r,0.0f);                              // Fin Axe : z

        glEnd();

        //ANGLE DELTA CONSIGNE : VECTEUR
        glLoadIdentity();									// Réinitialisation des matrices du modèle actuel
        glTranslatef(0.0f,0.0f,-6.0f);						// Objet centré en avant plan
        glRotatef(rsphr,1.0f,1.0f,0.0f);					// Rotation de l'objet
        glRotatef(xRot/vitesse, 1.0, 0.0, 0.0);
        glRotatef(yRot/vitesse, 0.0, 1.0, 0.0);
        glRotatef(zRot/vitesse, 0.0, 0.0, 1.0);
        glLineWidth(1);
        glBegin(GL_LINES);
            glColor3f(1.0f,0.0f,0.0f);                              //Couleur rouge
            glVertex3f(0.0f,0.0f,0.0f);                              // Début Axe Angle
            glVertex3f(yCons_var,zCons_var,xCons_var);                          // Fin Axe Angle
        glEnd();

        //ANGLE OMEGA CONSIGNE : VECTEUR
        glLoadIdentity();									// Réinitialisation des matrices du modèle actuel
        glTranslatef(0.0f,0.0f,-6.0f);						// Objet centré en avant plan
        glRotatef(rsphr,1.0f,1.0f,0.0f);					// Rotation de l'objet
        glRotatef(xRot/vitesse, 1.0, 0.0, 0.0);
        glRotatef(yRot/vitesse, 0.0, 1.0, 0.0);
        glRotatef(zRot/vitesse, 0.0, 0.0, 1.0);
        glRotatef(omCons_var*(360/(2*M_PI)),0.0f,r,0.0f);
        glLineWidth(1);
        glBegin(GL_LINES);
            glColor3f(1.0f,0.0f,0.0f);                              //Couleur rouge
            glVertex3f(0.0f,0.0f,0.0f);                             //début angle omega
            glVertex3f(0.0f,0.0f,r);                           //fin angle omega
        glEnd();

        //ANGLE DELTA MESURE : VECTEUR
        glLoadIdentity();									// Réinitialisation des matrices du modèle actuel
        glTranslatef(0.0f,0.0f,-6.0f);						// Objet centré en avant plan
        glRotatef(rsphr,1.0f,1.0f,0.0f);					// Rotation de l'objet
        glRotatef(xRot/vitesse, 1.0, 0.0, 0.0);
        glRotatef(yRot/vitesse, 0.0, 1.0, 0.0);
        glRotatef(zRot/vitesse, 0.0, 0.0, 1.0);
        glLineWidth(1);
        glBegin(GL_LINES);
            glColor3f(0.0f,1.0f,0.0f);                              //Couleur verte
            glVertex3f(0.0f,0.0f,0.0f);                              // Début Axe Angle
            glVertex3f(y_var,z_var,x_var);                          // Fin Axe Angle
        glEnd();

        //ANGLE OMEGA MESURE : VECTEUR
        glLoadIdentity();									// Réinitialisation des matrices du modèle actuel
        glTranslatef(0.0f,0.0f,-6.0f);						// Objet centré en avant plan
        glRotatef(rsphr,1.0f,1.0f,0.0f);					// Rotation de l'objet
        glRotatef(xRot/vitesse, 1.0, 0.0, 0.0);
        glRotatef(yRot/vitesse, 0.0, 1.0, 0.0);
        glRotatef(zRot/vitesse, 0.0, 0.0, 1.0);
        glRotatef(om_var*(360/(2*M_PI)),0.0f,r,0.0f);
        glLineWidth(1);
        glBegin(GL_LINES);
            glColor3f(0.0f,1.0f,0.0f);                              //Couleur verte
            glVertex3f(0.0f,0.0f,0.0f);                             //début angle omega
            glVertex3f(0.0f,0.0f,r);                           //fin angle omega
        glEnd();


        //3 CERCLES :
        glLoadIdentity();									// Réinitialisation des matrices du modèle actuel
        glTranslatef(0.0f,0.0f,-6.0f);						// Objet centré en avant plan
        glRotatef(rsphr,1.0f,1.0f,0.0f);					// Rotation de l'objet
        glRotatef(xRot/vitesse, 1.0, 0.0, 0.0);
        glRotatef(yRot/vitesse, 0.0, 1.0, 0.0);
        glRotatef(zRot/vitesse, 0.0, 0.0, 1.0);
        glBegin(GL_LINE_STRIP);
        for(int i=0; i<250; i++)
        {
            double angle = r*M_PI*i/250;
            glColor3f(0.0f,0.0f,1.0f);
            glVertex3f(cos(angle)*r,0.0f,sin(angle)*r );
        }
        glEnd();

        glLoadIdentity();									// Réinitialisation des matrices du modèle actuel
        glTranslatef(0.0f,0.0f,-6.0f);						// Objet centré en avant plan
        glRotatef(rsphr,1.0f,1.0f,0.0f);					// Rotation de l'objet
        glRotatef(xRot/vitesse, 1.0, 0.0, 0.0);
        glRotatef(yRot/vitesse, 0.0, 1.0, 0.0);
        glRotatef(zRot/vitesse, 0.0, 0.0, 1.0);
        glBegin(GL_LINE_STRIP);
        for(int i=0; i<250; i++)
        {
            double angle = r*M_PI*i/250;
            glColor3f(0.0f,0.0f,1.0f);
            glVertex3f(0.0f,cos(angle)*r,sin(angle)*r);
        }
        glEnd();

        glLoadIdentity();									// Réinitialisation des matrices du modèle actuel
        glTranslatef(0.0f,0.0f,-6.0f);						// Objet centré en avant plan
        glRotatef(rsphr,1.0f,1.0f,0.0f);					// Rotation de l'objet
        glRotatef(xRot/vitesse, 1.0, 0.0, 0.0);
        glRotatef(yRot/vitesse, 0.0, 1.0, 0.0);
        glRotatef(zRot/vitesse, 0.0, 0.0, 1.0);
        glBegin(GL_LINE_STRIP);
        for(int i=0; i<250; i++)
        {
            double angle = r*M_PI*i/250;
            glColor3f(0.0f,0.0f,1.0f);
            glVertex3f(cos(angle)*r,sin(angle)*r,0.0f);
        }
        glEnd();

        //OMEGA CONSIGNE : ARC DE CERCLE
        glLoadIdentity();									// Réinitialisation des matrices du modèle actuel
        glTranslatef(0.0f,0.0f,-6.0f);						// Objet centré en avant plan
        glRotatef(rsphr,1.0f,1.0f,0.0f);					// Rotation de l'objet
        glRotatef(xRot/vitesse, 1.0, 0.0, 0.0);
        glRotatef(yRot/vitesse, 0.0, 1.0, 0.0);
        glRotatef(zRot/vitesse, 0.0, 0.0, 1.0);
        glLineWidth(4.0);
        glBegin(GL_LINE_STRIP);
        for(int i=0; i<200; i++)
        {
            double angle = omCons_var*i/200;
            glColor3f(1.0f,0.0f,0.0f);                              //Couleur rouge
            glVertex3f(sin(angle)*r,0.0f,cos(angle)*r);
        }
        glEnd();

        //DELTA CONSIGNE : ARC DE CERCLE
        glLoadIdentity();									// Réinitialisation des matrices du modèle actuel
        glTranslatef(0.0f,0.0f,-6.0f);						// Objet centré en avant plan
        glRotatef(rsphr,1.0f,1.0f,0.0f);					// Rotation de l'objet
        glRotatef(xRot/vitesse, 1.0, 0.0, 0.0);
        glRotatef(yRot/vitesse, 0.0, 1.0, 0.0);
        glRotatef(zRot/vitesse, 0.0, 0.0, 1.0);
        glRotatef(omCons_var*(360/(2*M_PI)),0.0f,r,0.0f);
        glLineWidth(4.0);
        glBegin(GL_LINE_STRIP);
        for(int i=0; i<200; i++)
        {
            double angle = dlCons_var*i/200;
            glColor3f(1.0f,0.0f,0.0f);                              //Couleur rouge
            glVertex3f(0.0f,sin(angle)*r,cos(angle)*r);
        }
        glEnd();


        //OMEGA MESURE : ARC DE CERCLE
        glLoadIdentity();									// Réinitialisation des matrices du modèle actuel
        glTranslatef(0.0f,0.0f,-6.0f);						// Objet centré en avant plan
        glRotatef(rsphr,1.0f,1.0f,0.0f);					// Rotation de l'objet
        glRotatef(xRot/vitesse, 1.0, 0.0, 0.0);
        glRotatef(yRot/vitesse, 0.0, 1.0, 0.0);
        glRotatef(zRot/vitesse, 0.0, 0.0, 1.0);
        glLineWidth(4.0);
        glBegin(GL_LINE_STRIP);
        for(int i=0; i<200; i++)
        {
            double angle = om_var*i/200;
            glColor3f(0.0f,1.0f,0.0f);                              //Couleur verte
            glVertex3f(sin(angle)*r,0.0f,cos(angle)*r);
        }
        glEnd();

        //DELTA MESURE : ARC DE CERCLE
        glLoadIdentity();									// Réinitialisation des matrices du modèle actuel
        glTranslatef(0.0f,0.0f,-6.0f);						// Objet centré en avant plan
        glRotatef(rsphr,1.0f,1.0f,0.0f);					// Rotation de l'objet
        glRotatef(xRot/vitesse, 1.0, 0.0, 0.0);
        glRotatef(yRot/vitesse, 0.0, 1.0, 0.0);
        glRotatef(zRot/vitesse, 0.0, 0.0, 1.0);
        glRotatef(om_var*(360/(2*M_PI)),0.0f,r,0.0f);
        glLineWidth(4.0);
        glBegin(GL_LINE_STRIP);
        for(int i=0; i<200; i++)
        {
            double angle = dl_var*i/200;
            glColor3f(0.0f,1.0f,0.0f);                              //Couleur verte
            glVertex3f(0.0f,sin(angle)*r,cos(angle)*r);
        }
        glEnd();

        //SPHERE
            glLoadIdentity();									// Réinitialisation des matrices du modèle actuel
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glTranslatef(0.0f,0.0f,-6.0f);						// Objet centré en avant plan
            glRotatef(rsphr,1.0f,1.0f,0.0f);					// Rotation de l'objet
            glRotatef(xRot/vitesse, 1.0, 0.0, 0.0);
            glRotatef(yRot/vitesse, 0.0, 1.0, 0.0);
            glRotatef(zRot/vitesse, 0.0, 0.0, 1.0);
            glLineWidth(1);
            glBegin(GL_QUADS);                                  // Dessin du quadratique
                GLUquadric* sphere = gluNewQuadric();           // Nouvel objet GLUquadratic, la sphère
                    glColor4f(1.0f,1.0f,1.0f,0.1f);             // Couleur de la sphère
                    gluQuadricDrawStyle(sphere,GLU_FILL);       // Style de la sphère (ici, pleine)
                    //gluQuadricTexture(sphere,GL_TRUE);        // Textures de la sphère
                    gluSphere(sphere,r,40,40);               // Sphere de rayon 2 avec 20 latitudes et 35 longitudes
            glEnd();											// Fin programme Sphere
            glDisable(GL_BLEND);
}


