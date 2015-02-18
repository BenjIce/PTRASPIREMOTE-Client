#include "capteur.h"

Capteur::Capteur() {
	setWindowIcon(QIcon("logo.gif"));
	setWindowTitle("Tourelle Pan Tilt");
	// affichage ligne calcul
	grille = new QGridLayout;
	lblTitre1 = new QLabel("--- Conversion de la mesure a saisir ---");
	lblTitre1->setAlignment(Qt::AlignCenter);
	lblMesPan = new QLabel("Mesure de Xout (V)");
	lblMesTilt = new QLabel("Mesure de Yout (V)");
	txtMesPan = new QLineEdit();
	txtMesTilt = new QLineEdit();
	cmdConvertir = new QPushButton("=> Convertir =>");
    lblResPan = new QLabel("Valeur du pan (\u00b0)");
    lblResTilt = new QLabel("Valeur du tilt (\u00b0)");
	txtResPan = new QLineEdit();
	txtResTilt = new QLineEdit();
	QObject::connect(cmdConvertir,SIGNAL(clicked()),this,SLOT(ftcmdConvertir()));
	grille->addWidget(lblTitre1,0,0,1,5);
	grille->addWidget(lblMesPan,1,0);
	grille->addWidget(lblMesTilt,2,0);
	grille->addWidget(txtMesPan,1,1);
	grille->addWidget(txtMesTilt,2,1);
	grille->addWidget(cmdConvertir,1,2,2,1);
	grille->addWidget(lblResPan,1,3);
	grille->addWidget(lblResTilt,2,3);
	grille->addWidget(txtResPan,1,4);
	grille->addWidget(txtResTilt,2,4);
	// affichage ligne automatique
	lblTitre2 = new QLabel("--- Convertion automatique de l'information de la tourelle ---");
	lblTitre2->setAlignment(Qt::AlignCenter);
	lblMesPanAuto = new QLabel("Mesure du pan (V)");
	lblMesTiltAuto = new QLabel("Mesure du tilt (V)");
	txtMesPanAuto = new QLineEdit();
	txtMesTiltAuto = new QLineEdit();
	cmdConvertirAuto = new QLabel("<= Convertion <=");
    lblResPanAuto = new QLabel("Valeur du pan (\u00b0)");
    lblResTiltAuto = new QLabel("Valeur du tilt (\u00b0)");
	txtResPanAuto = new QLineEdit();
	txtResTiltAuto = new QLineEdit();
	grille->addWidget(lblTitre2,3,0,1,5);
	grille->addWidget(lblMesPanAuto,4,0);
	grille->addWidget(lblMesTiltAuto,5,0);
	grille->addWidget(txtMesPanAuto,4,1);
	grille->addWidget(txtMesTiltAuto,5,1);
	grille->addWidget(cmdConvertirAuto,4,2,5,1);
	grille->addWidget(lblResPanAuto,4,3);
	grille->addWidget(lblResTiltAuto,5,3);
	grille->addWidget(txtResPanAuto,4,4);
	grille->addWidget(txtResTiltAuto,5,4);
	setLayout(grille);
}

void Capteur::ftcmdConvertir() { // lignes haut
	float Xout,Yout;
	float ax,ay;
	float pan,tilt;
	Xout = txtMesPan->text().toFloat();
	Yout = txtMesTilt->text().toFloat();
	ax = (Xout-1.175)/0.295;
	ay = (Yout-1.22)/0.29;
	pan = atan(ay/ax);
	tilt = acos((180/PI)*sqrt(pow(ay,2)+pow(ax,2)));
	txtResPan->setText(QString::number((180/PI)*pan));
	txtResTilt->setText(QString::number((180/PI)*tilt));
}

void Capteur::ftcmdConvertirAuto(float pan, float tilt) { //lignes bas
	float Xout,Yout;
	float ax,ay;
	ax = sqrt((pow(cos(tilt*PI/180),2))/(1+(pow(tan(pan*PI/180),2))));
	ay = ax*tan(pan*PI/180);
	Xout = (ax*0.295)+1.175;
	Yout = (ay*0.29)+1.22;

	txtResPanAuto->setText(QString::number(pan));
	txtResTiltAuto->setText(QString::number(tilt));
	txtMesPanAuto->setText(QString::number(Xout));
	txtMesTiltAuto->setText(QString::number(Yout));
}
