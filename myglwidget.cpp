#include "myGLWidget.h"

bool b_Fullscreen;


myGLWidget::myGLWidget(int framesPerSecond, QWidget *parent)
    : QGLWidget(parent)
{
    b_Fullscreen = false ;
    //setWindowTitle(QString::fromUtf8(name));
    if(framesPerSecond == 0)
        t_Timer = NULL;
    else
    {
        int seconde = 1000; // 1 seconde = 1000 ms
        int timerInterval = seconde / framesPerSecond;
        t_Timer = new QTimer(this);
        connect(t_Timer, SIGNAL(timeout()), this, SLOT(timeOutSlot()));
        t_Timer->start( timerInterval );
    }

    xRot = 0;
    yRot = 0;
    zRot = 0;

    setCursor(Qt::OpenHandCursor);
}

void myGLWidget::keyPressEvent(QKeyEvent *keyEvent)
{
    switch(keyEvent->key())
    {
        case Qt::Key_Escape:
            close();
            break;
        case Qt::Key_F1:
            toggleFullWindow();
            break;
    }
}

void myGLWidget::timeOutSlot()
{
    updateGL();
}

void myGLWidget::toggleFullWindow()
{
    if(b_Fullscreen)
    {
        showNormal();
        b_Fullscreen = false;
    }
    else
    {
        showFullScreen();
        b_Fullscreen = true;
    }
}

void myGLWidget::qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360 * 16)
        angle -= 360 * 16;
}


void myGLWidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}

void myGLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != yRot) {
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void myGLWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}

void myGLWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->buttons()& Qt::LeftButton){
        //setCursor(Qt::ClosedHandCursor);


    }
    else if (event->buttons() & Qt::RightButton){
        //setCursor(Qt::ClosedHandCursor);

    }
}



void myGLWidget::mouseMoveEvent(QMouseEvent *event)
{
     int dx = event->x() - lastPos.x();
     int dy = event->y() - lastPos.y();

     if (event->buttons() & Qt::LeftButton) {
         //setXRotation(xRot + 8 * dy);
         setYRotation(yRot + 8 * dx);       //Rotation sur l'axe Y
         //setZRotation(zRot + 8 * dx);
         setCursor(Qt::ClosedHandCursor);
     }
     else if (event->buttons() & Qt::RightButton) {
         setXRotation(xRot + 8 * dy);       //Rotation sur l'axe X
         //setZRotation(zRot + 8 * dx)
         setCursor(Qt::ClosedHandCursor);
     }
    lastPos = event->pos();
}

void myGLWidget::mouseReleaseEvent(QMouseEvent *)
{
    setCursor(Qt::OpenHandCursor);
}

