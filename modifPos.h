#ifndef HEADER_MODIFPOS
#define HEADER_MODIFPOS

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class ModifPos : public QWidget {
		Q_OBJECT
	public:
		ModifPos();
		void changeLabel(QString nom, QString pan,QString tilt);
	public slots:
		void ftcmdOK();
	signals:
		void signalOK(QString Nom, QString pan, QString tilt);
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
