#include "reglage.h"



Reglage::Reglage() {
	setWindowIcon(QIcon("logo.gif"));
	setWindowTitle("Tourelle Pan Tilt");
	mainLayout = new QVBoxLayout;
	layoutControle = new QGridLayout; // vitesse
        lblPanSpeed = new QLabel("Vitesse du pan (\u00b0/s)");
		txtPanSpeed = new QLineEdit();
        lblTiltSpeed = new QLabel("Vitesse du tilt (\u00b0/s)");
		txtTiltSpeed = new QLineEdit();
		layoutControle->addWidget(lblPanSpeed,0,0);
		layoutControle->addWidget(txtPanSpeed,0,1);
		layoutControle->addWidget(lblTiltSpeed,1,0);
		layoutControle->addWidget(txtTiltSpeed,1,1);
	layoutCmd = new QHBoxLayout; // validation
		cmdOK = new QPushButton("OK");
		cmdAnnuler = new QPushButton("Annuler");
		QObject::connect(cmdOK,SIGNAL(clicked()),this,SLOT(ftcmdOK()));
		QObject::connect(cmdAnnuler,SIGNAL(clicked()),this,SLOT(hide()));
		layoutCmd->addWidget(cmdOK);
		layoutCmd->addWidget(cmdAnnuler);
	mainLayout->addLayout(layoutControle);
	mainLayout->addLayout(layoutCmd);
	setLayout(mainLayout);
}

void Reglage::ftcmdOK() { // bouton OK
	emit signalOK(txtPanSpeed->text(),txtTiltSpeed->text());
	hide();
}
