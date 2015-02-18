#ifndef HEADER_NOUVPOS
#define HEADER_NOUVPOS

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class NouvPos : public QWidget {
		Q_OBJECT
	public:
		NouvPos(float pan,float tilt);
	public slots:
		void ftcmdOK();
	signals:
		void signalOK(QString Nom, QString A, QString B);
	private:
		QVBoxLayout *mainLayout;
		QGridLayout *layoutControle;
			QLabel *lblNom;
			QLineEdit *txtNom;
			QLabel *lblPan;
			QLineEdit *txtPan;
			QLabel *lblTilt;
			QLineEdit *txtTilt;
		QHBoxLayout *layoutCmd;
			QPushButton *cmdOK;
			QPushButton *cmdAnnuler;
};

#endif
