#include "nouvPos.h"

NouvPos::NouvPos(float pan,float tilt) {
	setWindowIcon(QIcon("logo.gif"));
	setWindowTitle("Tourelle Pan Tilt");
	mainLayout = new QVBoxLayout;
	layoutControle = new QGridLayout;
		lblNom = new QLabel("Nom de la position");
		txtNom = new QLineEdit();
        lblPan = new QLabel("valeur du pan (\u00b0)");
		txtPan = new QLineEdit(QString::number(pan));
        lblTilt = new QLabel("Valeur du tilt (\u00b0)");
		txtTilt = new QLineEdit(QString::number(tilt));
		layoutControle->addWidget(lblNom,0,0);
		layoutControle->addWidget(txtNom,0,1);
		layoutControle->addWidget(lblPan,1,0);
		layoutControle->addWidget(txtPan,1,1);
		layoutControle->addWidget(lblTilt,2,0);
		layoutControle->addWidget(txtTilt,2,1);
	layoutCmd = new QHBoxLayout;
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

void NouvPos::ftcmdOK() { // bouton OK
	emit signalOK(txtNom->text(),txtPan->text(),txtTilt->text());
	hide();
}
