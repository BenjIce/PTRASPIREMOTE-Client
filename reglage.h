#ifndef HEADER_REGLAGE
#define HEADER_REGLAGE

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Reglage : public QWidget {
		Q_OBJECT
	public:
		Reglage();
	public slots:
		void ftcmdOK();
	signals:
		void signalOK(QString ps, QString ts);
	private:
		QVBoxLayout *mainLayout;
		QGridLayout *layoutControle;
			QLabel *lblPanSpeed;
			QLineEdit *txtPanSpeed;
			QLabel *lblTiltSpeed;
			QLineEdit *txtTiltSpeed;
		QHBoxLayout *layoutCmd;
			QPushButton *cmdOK;
			QPushButton *cmdAnnuler;
};

#endif
