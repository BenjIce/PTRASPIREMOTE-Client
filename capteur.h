#ifndef HEADER_CAPTEUR
#define HEADER_CAPTEUR

#include <math.h>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "mecanique.h"

class Capteur : public QWidget {
		Q_OBJECT
	public:
		Capteur();
	public slots:
		void ftcmdConvertir();
		void ftcmdConvertirAuto(float pan, float tilt);
	private:
		// affichage ligne calcul
		QGridLayout *grille;
		QLabel *lblTitre1;
		QLabel *lblMesPan;
		QLabel *lblMesTilt;
		QLineEdit *txtMesPan;
		QLineEdit *txtMesTilt;
		QPushButton *cmdConvertir;
		QLabel *lblResPan;
		QLabel *lblResTilt;
		QLineEdit *txtResPan;
		QLineEdit *txtResTilt;
		// affichage ligne automatique
		QLabel *lblTitre2;
		QLabel *lblResPanAuto;
		QLabel *lblResTiltAuto;
		QLineEdit *txtResPanAuto;
		QLineEdit *txtResTiltAuto;
		QLabel *cmdConvertirAuto;
		QLabel *lblMesPanAuto;
		QLabel *lblMesTiltAuto;
		QLineEdit *txtMesPanAuto;
		QLineEdit *txtMesTiltAuto;
};

#endif
