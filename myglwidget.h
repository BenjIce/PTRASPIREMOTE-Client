#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QtOpenGL>   //Héritage de la classe QtOpenGL
#include <QGLWidget>  //Héritage de la classe QTWidget

class myGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit myGLWidget(int framesPerSecond = 0, QWidget *parent = 0);
    virtual void initializeGL() = 0;
    virtual void resizeGL(int width, int height) = 0;
    virtual void paintGL() = 0;
    virtual void keyPressEvent( QKeyEvent *keyEvent );
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void qNormalizeAngle(int &angle);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *);
    int xRot;
    int yRot;
    int zRot;


public slots:
    virtual void timeOutSlot();
    virtual void toggleFullWindow();
    virtual void setXRotation(int angle);
    virtual void setYRotation(int angle);
    virtual void setZRotation(int angle);

signals:
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

private:
    QTimer *t_Timer;
    QPoint lastPos;

};


#endif // MYGLWIDGET_H
