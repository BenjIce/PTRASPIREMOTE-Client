#include "fenPrincipale.h"

FenPrincipale::FenPrincipale() {
	setWindowIcon(QIcon("logo.gif"));
	setWindowTitle("Tourelle Pan Tilt");

	mainWidget = new QWidget; // zone centrale
	mainLayout = new QHBoxLayout; // disposition de la zone centrale
	layoutER = new QGridLayout; // disposition partie gauche
	layoutAction = new QVBoxLayout; // disposition zone connexion
	layoutGestion = new QVBoxLayout; // disposition zone position itineraire
	// zone Angle
	tabCommande = new QTabWidget; // onglets
	grpAngle = new QWidget;
	grpAngle->setWhatsThis("Envoi les ordres de positionnements a la tourelle.\r\n\r\nSi vous etes bien connecte au serveur, vous pouvez saisir les angles pan et tilt et valider avec le bouton positionner.\r\nVous pouvez choisir de ne pas modifier un angle en decochant la case dans la ligne correspondante.\r\nEnfin, si vous preferez choisir la valeur a ajouter aux angles actuels (plutot que de choisir directement les angles), cliquez sur \"Par rapport a la position actuelle (M)\"");
	layoutAngle = new QVBoxLayout;
	layoutPanAngle = new QHBoxLayout; // ligne Pan
		lblPanAngle = new QLabel("Pan");
		txtPanAngle = new QLineEdit("0");
		chkPanAngle = new QCheckBox;
		chkPanAngle->setChecked(true);
		//QObject::connect(txtPanAngle,SIGNAL(textChanged()),chkPanAngle,SLOT(setChecked(true)));
		layoutPanAngle->addWidget(lblPanAngle);
		layoutPanAngle->addWidget(txtPanAngle);
		layoutPanAngle->addWidget(chkPanAngle);
	layoutTiltAngle = new QHBoxLayout; // ligne Tilt
		lblTiltAngle = new QLabel("Tilt");
		txtTiltAngle = new QLineEdit("0");
		chkTiltAngle = new QCheckBox;
		chkTiltAngle->setChecked(true);
		layoutTiltAngle->addWidget(lblTiltAngle);
		layoutTiltAngle->addWidget(txtTiltAngle);
		layoutTiltAngle->addWidget(chkTiltAngle);
		QObject::connect(txtPanAngle,SIGNAL(returnPressed()),txtTiltAngle,SLOT(setFocus()));
		QObject::connect(txtTiltAngle,SIGNAL(returnPressed()),this,SLOT(ftcmdAngle()));
	radAbs1Angle = new QRadioButton("Par rapport a l'origine de la tourelle (O)");
		radAbs1Angle->setChecked(true);
	radRelAngle = new QRadioButton("Par rapport a la position actuelle (M)");
	cmdPosAngle = new QPushButton("Positionner");
		QObject::connect(cmdPosAngle,SIGNAL(clicked()),this,SLOT(ftcmdAngle()));
		layoutAngle->addLayout(layoutPanAngle);
		layoutAngle->addLayout(layoutTiltAngle);
		layoutAngle->addWidget(radAbs1Angle);
		layoutAngle->addWidget(radRelAngle);
		layoutAngle->addWidget(cmdPosAngle);
	grpAngle->setLayout(layoutAngle);
	tabCommande->addTab(grpAngle,"Angles (°)");
	// zone dim
	grpDim = new QWidget;
	grpDim->setWhatsThis("Envoi les ordres de positionnements a la tourelle.\r\n\r\nSi vous etes bien connecte au serveur, vous pouvez saisir les dimensions x, y et z (comme indiquees sur l'image) et valider avec le bouton positionner.\r\nVous pouvez choisir de ne pas prendre en compte une dimension en decochant la case dans la ligne correspondante.\r\nEnfin, si vous preferez choisir la valeur a ajouter aux dimensions actuels (plutot que de choisir directement les dimensions), cliquez sur \"Par rapport a la position actuelle (M)\"");
	layoutDim = new QVBoxLayout;
	layoutXDim = new QHBoxLayout; // X
		lblXDim = new QLabel("X");
		layoutXDim->addWidget(lblXDim);
		txtXDim = new QLineEdit("2");
		layoutXDim->addWidget(txtXDim);
		chkXDim = new QCheckBox;
		chkXDim->setChecked(true);
		layoutXDim->addWidget(chkXDim);
		layoutDim->addLayout(layoutXDim);
	layoutYDim = new QHBoxLayout; // Y
		lblYDim = new QLabel("Y");
		layoutYDim->addWidget(lblYDim);
		txtYDim = new QLineEdit("2.159");
		layoutYDim->addWidget(txtYDim);
		chkYDim = new QCheckBox;
		chkYDim->setChecked(true);
		layoutYDim->addWidget(chkYDim);
		layoutDim->addLayout(layoutYDim);
	layoutZDim = new QHBoxLayout; // Z
		lblZDim = new QLabel("Z");
		layoutZDim->addWidget(lblZDim);
		txtZDim = new QLineEdit("4.572");
		layoutZDim->addWidget(txtZDim);
		chkZDim = new QCheckBox;
		chkZDim->setChecked(true);
		layoutZDim->addWidget(chkZDim);
		layoutDim->addLayout(layoutZDim);
		QObject::connect(txtXDim,SIGNAL(returnPressed()),txtYDim,SLOT(setFocus()));
		QObject::connect(txtYDim,SIGNAL(returnPressed()),txtZDim,SLOT(setFocus()));
		QObject::connect(txtZDim,SIGNAL(returnPressed()),this,SLOT(ftcmdPosition()));
	
	radAbs1Dim = new QRadioButton("Par rapport a l'origine de la tourelle (0)");
		radAbs1Dim->setChecked(true);
		layoutDim->addWidget(radAbs1Dim);
	radRelDim = new QRadioButton("Par rapport a la position actuelle (M)");
		layoutDim->addWidget(radRelDim);
	cmdPosDim = new QPushButton("Positionner");
		QObject::connect(cmdPosDim,SIGNAL(clicked()),this,SLOT(ftcmdPosition()));
		layoutDim->addWidget(cmdPosDim);
	grpDim->setLayout(layoutDim);
	tabCommande->addTab(grpDim,"Position (cm)");
	// Commande par pave
	grpPave = new QWidget;
    grpPave->setWhatsThis("Controle la tourelle avec les quatres touches (haut, bas, gauche et droite) du pavé numerique du clavier ou de l'ecran.\r\n\r\nPour acceder a ces commandes, veuillez desactiver le bouton de bloquage. Vous pouvez egalement regler le pas de chaque angle.");
	layoutPave = new QVBoxLayout;
	layoutTouchesPave = new QGridLayout;
		cmdHautPave = new QPushButton("Haut");
		cmdGauchePave = new QPushButton("Gauche");
		cmdBasPave = new QPushButton("Bas");
		cmdDroitePave = new QPushButton("Droite");
		cmdHautPave->setShortcut(QKeySequence("Up"));
		cmdBasPave->setShortcut(QKeySequence("Down"));
		cmdDroitePave->setShortcut(QKeySequence("Right"));
		cmdGauchePave->setShortcut(QKeySequence("Left"));
		QObject::connect(cmdHautPave,SIGNAL(clicked()),this,SLOT(ftcmdPaveHaut()));
		QObject::connect(cmdGauchePave,SIGNAL(clicked()),this,SLOT(ftcmdPaveGauche()));
		QObject::connect(cmdBasPave,SIGNAL(clicked()),this,SLOT(ftcmdPaveBas()));
		QObject::connect(cmdDroitePave,SIGNAL(clicked()),this,SLOT(ftcmdPaveDroite()));
		layoutTouchesPave->addWidget(cmdHautPave,1,2);
		layoutTouchesPave->addWidget(cmdGauchePave,2,1);
		layoutTouchesPave->addWidget(cmdBasPave,2,2);
		layoutTouchesPave->addWidget(cmdDroitePave,2,3);
		layoutPave->addLayout(layoutTouchesPave);
	layoutPasPanPave = new QHBoxLayout;
        lblPasPanPave = new QLabel("Reglage du pas du pan (\u00b0)");
		txtPasPanPave = new QLineEdit("10");
		layoutPasPanPave->addWidget(lblPasPanPave);
		layoutPasPanPave->addWidget(txtPasPanPave);
		layoutPave->addLayout(layoutPasPanPave);
	layoutPasTiltPave = new QHBoxLayout;
        lblPasTiltPave = new QLabel("Reglage du pas du tilt (\u00b0)");
		txtPasTiltPave = new QLineEdit("10");
		layoutPasTiltPave->addWidget(lblPasTiltPave);
		layoutPasTiltPave->addWidget(txtPasTiltPave);
		layoutPave->addLayout(layoutPasTiltPave);
		QObject::connect(txtPasPanPave,SIGNAL(returnPressed()),txtPasTiltPave,SLOT(setFocus()));
		QObject::connect(txtPasTiltPave,SIGNAL(returnPressed()),this,SLOT(setFocus()));
    chkPavebloque = new QCheckBox("Bloquage du pavé");
		chkPavebloque->setChecked(true);
		layoutPave->addWidget(chkPavebloque);
	grpPave->setLayout(layoutPave);
    tabCommande->addTab(grpPave,"Pavé");
	// commande d'arret
    cmdHalt = new QPushButton("Arrêt immediat");
    cmdHalt->setWhatsThis("Arrête la tourelle quelque soit la commande en cours.\r\n\r\nCe bouton est relié à la barre espace de votre clavier.");
		QObject::connect(cmdHalt,SIGNAL(clicked()),this,SLOT(ftcmdHalt()));
		cmdHalt->setShortcut(QKeySequence(" "));
	// zone de reponse 
	grpReponse = new QGroupBox("Retour de la tourelle");
    grpReponse->setWhatsThis("Liste toutes les informations de la tourelle.\r\n\r\nCette zone s'actualise toutes les secondes si une commande est en cours d'exécution. Vous pouvez voir la position actuelle et la consigne de la commande en cours dans tous les axes. Vous voyez également la vitesse de chaque axes pan et tilt et l'avancement de la commande actuelle.");
	layoutReponse = new QVBoxLayout;
		lblVitessePan = new QLabel("Vitesse pan : -");
		lblVitesseTilt = new QLabel("Vitesse tilt : -");
		layoutTabRep = new QGridLayout;
			lblTabRep[0] = new QLabel("Position");
			lblTabRep[1] = new QLabel("Consigne");
			lblTabRep[2] = new QLabel("Pan : ");
			lblTabRep[3] = new QLabel("Tilt : ");
			lblTabRep[4] = new QLabel("X : ");
			lblTabRep[5] = new QLabel("Y : ");
			lblTabRep[6] = new QLabel("Z : ");
			lblTabRep[7] = new QLabel("-");
			lblTabRep[8] = new QLabel("-");
			lblTabRep[9] = new QLabel("-");
			lblTabRep[10] = new QLabel("-");
			lblTabRep[11] = new QLabel("-");
			lblTabRep[12] = new QLabel("-");
			lblTabRep[13] = new QLabel("-");
			lblTabRep[14] = new QLabel("-");
			lblTabRep[15] = new QLabel("-");
			lblTabRep[16] = new QLabel("-");
			layoutTabRep->addWidget(lblTabRep[0],0,1);
			layoutTabRep->addWidget(lblTabRep[1],0,2);
			layoutTabRep->addWidget(lblTabRep[2],1,0);
			layoutTabRep->addWidget(lblTabRep[3],2,0);
			layoutTabRep->addWidget(lblTabRep[4],3,0);
			layoutTabRep->addWidget(lblTabRep[5],4,0);
			layoutTabRep->addWidget(lblTabRep[6],5,0);
			layoutTabRep->addWidget(lblTabRep[7],1,1);
			layoutTabRep->addWidget(lblTabRep[8],2,1);
			layoutTabRep->addWidget(lblTabRep[9],3,1);
			layoutTabRep->addWidget(lblTabRep[10],4,1);
			layoutTabRep->addWidget(lblTabRep[11],5,1);
			layoutTabRep->addWidget(lblTabRep[12],1,2);
			layoutTabRep->addWidget(lblTabRep[13],2,2);
			layoutTabRep->addWidget(lblTabRep[14],3,2);
			layoutTabRep->addWidget(lblTabRep[15],4,2);
			layoutTabRep->addWidget(lblTabRep[16],5,2);
		progress = new QProgressBar;
		progress->setValue(100);
		layoutReponse->addWidget(lblVitessePan);
		layoutReponse->addWidget(lblVitesseTilt);
		layoutReponse->addLayout(layoutTabRep);
		layoutReponse->addWidget(progress);
	grpReponse->setLayout(layoutReponse);



    // WIDGET OPENGL SPHERE

    //Création du layout vertical principal
    QGridLayout *layoutPrincipal = new QGridLayout;


    // ----- 1ERE GROUPBOX -----

    // Création de la GroupBox
    QGroupBox *groupbox1 = new QGroupBox("Modélisations 3D Temps Réel", this);

    // Création du Widget OpenGL
    //tourelle3D = new GLTourelle(this, 400, 240); //Ajout d'une nouvelle tourelle 3D dans la fenêtre d'une taille de 400x240
    sphere = new GLSphere(this, 400, 240); //Ajout d'une nouvelle représentation sphérique dans la fenêtre d'une taille de 400x240

    // Création du Layout OpenGL de la GroupBox1 et ajout des Widgets
    QHBoxLayout *layout1 = new QHBoxLayout;
    //layout1->addWidget(tourelle3D);
    layout1->addWidget(sphere);

    // Ajout du Layout à la GroupBox1
    groupbox1->setLayout(layout1);

    // Ajout de la GroupBox1 au Layout Principal
    layoutPrincipal->addWidget(groupbox1,1,1);

    // ----- 2EME GROUPBOX -----

    // Création de la GroupBox
    QGroupBox *groupbox2 = new QGroupBox("Valeurs des angles", this);

    // Création des Widgets

    //QLine
    QSlider *slider_delta = new QSlider(Qt::Horizontal,this);
    slider_delta->setRange(-90,90);
    QSlider *slider_omega = new QSlider(Qt::Horizontal,this);
    slider_omega->setRange(-180,180);
    QLCDNumber *x_disp = new QLCDNumber;
    x_disp->setSegmentStyle(QLCDNumber::Flat);
    QLCDNumber *y_disp = new QLCDNumber;
    y_disp->setSegmentStyle(QLCDNumber::Flat);
    QLCDNumber *z_disp = new QLCDNumber;
    z_disp->setSegmentStyle(QLCDNumber::Flat);

    QSlider *slider_deltaCons = new QSlider(Qt::Horizontal,this);
    slider_deltaCons->setRange(-90,90);
    QSlider *slider_omegaCons = new QSlider(Qt::Horizontal,this);
    slider_omegaCons->setRange(-180,180);
    QLCDNumber *xCons_disp = new QLCDNumber;
    xCons_disp->setSegmentStyle(QLCDNumber::Flat);
    QLCDNumber *yCons_disp = new QLCDNumber;
    yCons_disp->setSegmentStyle(QLCDNumber::Flat);
    QLCDNumber *zCons_disp = new QLCDNumber;
    zCons_disp->setSegmentStyle(QLCDNumber::Flat);

    // Création des layouts de la GroupBox2 et ajout des Widgets
    QGridLayout *layout2 = new QGridLayout;
    layout2->setColumnStretch(1,2);
    QFormLayout *coordonnees = new QFormLayout;
    coordonnees->addRow("Mesure de delta", slider_delta);
    coordonnees->addRow("Mesure de omega", slider_omega);
    coordonnees->addRow("Mesure - x :",x_disp);
    coordonnees->addRow("Mesure - y :",y_disp);
    coordonnees->addRow("Mesure - z :",z_disp);

    coordonnees->addRow("Consigne de delta", slider_deltaCons);
    coordonnees->addRow("Consigne de omega", slider_omegaCons);
    coordonnees->addRow("Consigne - x :",xCons_disp);
    coordonnees->addRow("Consigne - y :",yCons_disp);
    coordonnees->addRow("Consigne - z :",zCons_disp);

    // Ajout du Layout à la GroupBox2
    layout2->addLayout(coordonnees,1,1);
    groupbox2->setLayout(layout2);

    // Ajout de la GroupBox2 au Layout Principal
    layoutPrincipal->addWidget(groupbox2,2,1);

    //Connections
    QObject::connect(slider_delta,SIGNAL(valueChanged(int)),this,SLOT(MAJdelta(int)));
    QObject::connect(slider_omega,SIGNAL(valueChanged(int)),this,SLOT(MAJomega(int)));
    QObject::connect(this,SIGNAL(xChanged(double)),x_disp,SLOT(display(double)));
    QObject::connect(this,SIGNAL(yChanged(double)),y_disp,SLOT(display(double)));
    QObject::connect(this,SIGNAL(zChanged(double)),z_disp,SLOT(display(double)));

    QObject::connect(slider_deltaCons,SIGNAL(valueChanged(int)),this,SLOT(MAJdeltaCons(int)));
    QObject::connect(slider_omegaCons,SIGNAL(valueChanged(int)),this,SLOT(MAJomegaCons(int)));
    QObject::connect(this,SIGNAL(xConsChanged(double)),xCons_disp,SLOT(display(double)));
    QObject::connect(this,SIGNAL(yConsChanged(double)),yCons_disp,SLOT(display(double)));
    QObject::connect(this,SIGNAL(zConsChanged(double)),zCons_disp,SLOT(display(double)));



	// Connection
    grpConnection = new QGroupBox("Connection à la tourelle");
    grpConnection->setWhatsThis("Réalise la connexion\r\n\r\nVous devez entrer l'adresse IP et le numéro de port du serveur (ordinateur sur lequel se trouve le logiciel serveur et la tourelle à piloter.\r\nEntrez ensuite votre identifiant et votre mot de passe. Si vous n'en avez pas, demandez le réglage du serveur à votre administrateur système.\r\nVous pouvez ensuite vous connecter et vous déconnecter avec les deux boutons en dessous.");
	layoutConnection = new QVBoxLayout;
		layoutTcp = new QGridLayout;
			lblTcp = new QLabel("Adresse IP et port");
			txtTcp = new QLineEdit("192.168.0.0");
			txtPort = new QLineEdit("1234");
			txtPort->setMaximumWidth(50);
			layoutTcp->addWidget(lblTcp,0,0);
			layoutTcp->addWidget(txtTcp,0,1);
			layoutTcp->addWidget(txtPort,0,2);
			lblLogin = new QLabel("Login");
			txtLogin = new QLineEdit("");
			layoutTcp->addWidget(lblLogin,1,0);
			layoutTcp->addWidget(txtLogin,1,1,1,2);
			lblPassWD = new QLabel("Mot de passe");
			txtPassWD = new QLineEdit("");
			txtPassWD->setEchoMode(QLineEdit::Password);
			layoutTcp->addWidget(lblPassWD,2,0);
			layoutTcp->addWidget(txtPassWD,2,1,1,2);
			QObject::connect(txtTcp,SIGNAL(returnPressed()),txtPort,SLOT(setFocus()));
			QObject::connect(txtPort,SIGNAL(returnPressed()),txtLogin,SLOT(setFocus()));
			QObject::connect(txtLogin,SIGNAL(returnPressed()),txtPassWD,SLOT(setFocus()));
			QObject::connect(txtPassWD,SIGNAL(returnPressed()),this,SLOT(ftcmdConnection()));
		layoutConnect = new QHBoxLayout;
			cmdConnection = new QPushButton("Connexion");
            cmdDeconnection = new QPushButton("Déconnection");
			cmdDeconnection->setEnabled(false);
			layoutConnect->addWidget(cmdConnection);
			layoutConnect->addWidget(cmdDeconnection);
			QObject::connect(cmdConnection,SIGNAL(clicked()),this,SLOT(ftcmdConnection()));
			QObject::connect(cmdDeconnection,SIGNAL(clicked()),this,SLOT(ftcmdDeconnection()));
        lblConnection = new QLabel("Etat actuel : tourelle déconnectée");
		layoutConnection->addLayout(layoutTcp);
		layoutConnection->addLayout(layoutConnect);
		layoutConnection->addWidget(lblConnection);
	grpConnection->setLayout(layoutConnection);
	//Registre
	grpRegistre = new QGroupBox("Positions et itineraires");
    grpRegistre->setWhatsThis("Registres de positions et itinéraires sauvegardés.\r\n\r\nVous accédez ici aux sauvegardes que vous (l'utilisateur connecté au serveur de la tourelle) avez effectué. Le bouton <Nouveau> permet de sauvegarder une nouvelle position (par défaut la position actuelle). Le bouton <Supprimer> efface l'élément selectionné. Exécuter lance l'élément selectionné. Le bouton <Modifier> permet de changer les paramètres de l'élément selectionné.");
	layoutRegistre = new QVBoxLayout;
		layoutNouv = new QHBoxLayout;
			cmdNouveau = new QPushButton("Nouveau");
			cmdSupprimer = new QPushButton("Supprimer");
			QObject::connect(cmdNouveau,SIGNAL(clicked()),this,SLOT(ftcmdNouveau()));
			QObject::connect(cmdSupprimer,SIGNAL(clicked()),this,SLOT(ftcmdSupprimer()));
			layoutNouv->addWidget(cmdNouveau);
			layoutNouv->addWidget(cmdSupprimer);
			lstRegistre = new QListWidget;
		layoutExe = new QHBoxLayout;
            cmdExecuter = new QPushButton("Exécuter");
			cmdModifier = new QPushButton("Modifier");
			QObject::connect(cmdExecuter,SIGNAL(clicked()),this,SLOT(ftcmdExecuter()));
			QObject::connect(cmdModifier,SIGNAL(clicked()),this,SLOT(ftcmdModifier()));
			layoutExe->addWidget(cmdExecuter);
			layoutExe->addWidget(cmdModifier);
        lblRegistre = new QLabel("Pas d'exécutions passées");
		progressRegistre = new QProgressBar;
		progressRegistre->setValue(100);
		layoutRegistre->addLayout(layoutNouv);
		layoutRegistre->addWidget(lstRegistre);
		layoutRegistre->addLayout(layoutExe);
		//layoutRegistre->addWidget(lblRegistre);
		//layoutRegistre->addWidget(progressRegistre);
	grpRegistre->setLayout(layoutRegistre);
	// widget Central
	layoutER->addWidget(tabCommande,0,0);
	layoutER->addWidget(grpReponse,0,1);
	layoutER->addWidget(cmdHalt,1,0,1,2);
    layoutER->addLayout(layoutPrincipal,2,0,2,2);
	layoutAction->addLayout(layoutER);
	layoutGestion->addWidget(grpConnection);
	layoutAction->addStretch();
	layoutGestion->addWidget(grpRegistre);
	mainLayout->addLayout(layoutAction);
	mainLayout->addLayout(layoutGestion);
	mainWidget->setLayout(mainLayout);
	this->setCentralWidget(mainWidget);
	txtTcp->setFocus(); // --------- fin zone fenetre principal
	
	// liaisons (objet utilises)
	commande = "";
	tourelle = new QTcpSocket();
    tourelleConnectee = false; // bonton connexion
	tourelleLoguee = false; // identification reussi
	cmdEnCours = false; // pour voir si il faut mettre a jour le tableau reponse
	QObject::connect(tourelle,SIGNAL(disconnected()),this,SLOT(ftdisconnected()));
	QObject::connect(tourelle,SIGNAL(readyRead()),this,SLOT(reception()));
	mecanique = new Mecanique(); // dimensions et calculs
	timer = new QTimer(); // raffraichissement regulier tableau reponse
	QObject::connect(timer,SIGNAL(timeout()),this,SLOT(ftTimer()));
	timer->start(2000);
	pan_prec = 0.0;
	tilt_prec = 0.0;
	pan = 0.0;
	tilt = 0.0;
	pan_avant = 0.0;
	tilt_avant = 0.0;
	pan_cons = 0.0;
	tilt_cons=0.0;
	debutCmd = true;
	capteur = new Capteur();
	reglage = new Reglage;
	
	// menus
	mTourelle = menuBar()->addMenu("&Tourelle");
        mReglage = new QAction("&Réglage",this);
		mCapteur = new QAction("&Capteur",this);
        mReglage->setWhatsThis("Effectue les réglages de la vitesse des axes.");
        mCapteur->setWhatsThis("Permet de valider la position de la tourelle avec le module acceleromètre proposé.");
		QObject::connect(mReglage, SIGNAL(triggered()), reglage, SLOT(show()));
		QObject::connect(mCapteur, SIGNAL(triggered()), capteur, SLOT(show()));
		mTourelle->addAction(mReglage);
		mTourelle->addAction(mCapteur);
	mAide = menuBar()->addMenu("&Aide");
		mPointeur = new QAction("&Pointeur d'aide",this);
		mLogiciel = new QAction("A propos",this);
		QObject::connect(mPointeur, SIGNAL(triggered()), this, SLOT(ftPointeurAide()));
		QObject::connect(mLogiciel, SIGNAL(triggered()), this, SLOT(ftLogiciel()));
		mAide->addAction(mPointeur);
		mAide->addAction(mLogiciel);
	
	QObject::connect(reglage,SIGNAL(signalOK(QString,QString)),this,SLOT(ftReglage(QString,QString)));
	modifPos = new ModifPos();
	QObject::connect(modifPos,SIGNAL(signalOK(QString,QString,QString)),this,SLOT(ftModif(QString,QString,QString)));
}

void FenPrincipale::ftcmdConnection() { // bouton connexion
	if (!tourelleConnectee) {
		cmdConnection->setEnabled(false);
		cmdDeconnection->setEnabled(true);
		tourelleConnectee = true;
		commande = "connexion";
		tourelle->connectToHost(txtTcp->text(),txtPort->text().toInt());
		lblConnection->setText("Etat actuel : en cours de connexion");
		if(!tourelle->waitForConnected(3000)) {
			ftcmdDeconnection();
			QMessageBox::critical(this,tr("Tourelle Pan Tilt"),tr("Pas de serveur en ligne"));
		}
	}
}

void FenPrincipale::ftdisconnected() { // serveur coupee
	if(tourelleConnectee) {
        QMessageBox::warning(this,"Tourelle Pan Tilt","Serveur déconnecté");
		ftcmdDeconnection();
	}
}

void FenPrincipale::ftcmdDeconnection() { // bouton deconnexion
	if(tourelleConnectee) {
		lstRegistre->clear();
		tourelleConnectee = false;
		tourelleLoguee = false;
		tourelle->disconnectFromHost();
        lblConnection->setText("Etat actuel : déconnectee");
		cmdDeconnection->setEnabled(false);
		cmdConnection->setEnabled(true);
		listeCmd.clear();
	}
}

void FenPrincipale::ftcmdAngle() { // bouton positionner en angle
	if(tourelleConnectee) {
		if(radAbs1Angle->isChecked()) { // par rapport a O
			if(chkPanAngle->isChecked() && !chkTiltAngle->isChecked()) {
                listeCmd.enqueue("pp:"+txtPanAngle->text().toLatin1()); //toAscii
				envoi();
			}
			if(chkTiltAngle->isChecked() && !chkPanAngle->isChecked()) {
                listeCmd.enqueue("tp:"+txtTiltAngle->text().toLatin1()); //toAscii
				envoi();
			}
			if(chkTiltAngle->isChecked() && chkPanAngle->isChecked()) {
                listeCmd.enqueue("pp:"+txtPanAngle->text().toLatin1()); //toAscii
                listeCmd.enqueue("tp:"+txtTiltAngle->text().toLatin1()); //toAscii
				envoi();
			}
		}
		if(radRelAngle->isChecked()) { // par rapport a M
			if(chkPanAngle->isChecked() && !chkTiltAngle->isChecked()) {
                listeCmd.enqueue("po:"+txtPanAngle->text().toLatin1()); //toAscii
				envoi();
			}
			if(chkTiltAngle->isChecked() && !chkPanAngle->isChecked()) {
                listeCmd.enqueue("to:"+txtTiltAngle->text().toLatin1()); //toAscii
				envoi();
			}
			if(chkTiltAngle->isChecked() && chkPanAngle->isChecked()) {
                listeCmd.enqueue("po:"+txtPanAngle->text().toLatin1()); //toAscii
                listeCmd.enqueue("to:"+txtTiltAngle->text().toLatin1()); //toAscii
				envoi();
			}
		}
		modifEnCours = true;
	}
	else {
        QMessageBox::warning(this,tr("Tourelle non connectée"),tr("Vous devez d'abord vous connecter à une tourelle"));
	}
}
void FenPrincipale::ftcmdPosition() { // Positionner en position
	if(tourelleConnectee) {
		double pan, tilt;
		QString strPan, strTilt;
		double X, Y, Z;
		if(radAbs1Dim->isChecked()) { // par rapport a O
			X = txtXDim->text().toDouble();
			Y = txtYDim->text().toDouble();
			Z = txtZDim->text().toDouble();
			if(chkXDim->isChecked() && !chkYDim->isChecked() && !chkZDim->isChecked()) {
				mecanique->Pos2AngleX(&pan,&tilt,X);
				strPan = QString::number(pan);
				strTilt = QString::number(tilt);
                listeCmd.enqueue("pp:"+strPan.toLatin1()); //toAscii
                listeCmd.enqueue("tp:"+strTilt.toLatin1()); //toAscii
			}
			if(!chkXDim->isChecked() && chkYDim->isChecked() && !chkZDim->isChecked()) {
				mecanique->Pos2AngleY(&pan,&tilt,Y);
				strPan = QString::number(pan);
				strTilt = QString::number(tilt);
                listeCmd.enqueue("pp:"+strPan.toLatin1()); //toAscii
                listeCmd.enqueue("tp:"+strTilt.toLatin1()); //toAscii
			}
			if(!chkXDim->isChecked() && !chkYDim->isChecked() && chkZDim->isChecked()) {
				mecanique->Pos2AngleZ(&tilt,Z);
				strTilt = QString::number(tilt);
                listeCmd.enqueue("tp:"+strTilt.toLatin1()); //toAscii
			}
			if(chkXDim->isChecked() && chkYDim->isChecked() && !chkZDim->isChecked()) {
				mecanique->Pos2AngleXY(&pan,&tilt,X,Y);
				strPan = QString::number(pan);
				strTilt = QString::number(tilt);
                listeCmd.enqueue("pp:"+strPan.toLatin1()); //toAscii
                listeCmd.enqueue("tp:"+strTilt.toLatin1()); //toAscii
			}
			if(chkXDim->isChecked() && !chkYDim->isChecked() && chkZDim->isChecked()) {
				mecanique->Pos2AngleXZ(&pan,&tilt,X,Z);
				strPan = QString::number(pan);
				strTilt = QString::number(tilt);
                listeCmd.enqueue("pp:"+strPan.toLatin1()); //toAscii
                listeCmd.enqueue("tp:"+strTilt.toLatin1()); //toAscii
			}
			if(!chkXDim->isChecked() && chkYDim->isChecked() && chkZDim->isChecked()) {
				mecanique->Pos2AngleYZ(&pan,&tilt,Y,Z);
				strPan = QString::number(pan);
				strTilt = QString::number(tilt);
                listeCmd.enqueue("pp:"+strPan.toLatin1()); //toAscii
                listeCmd.enqueue("tp:"+strTilt.toLatin1()); //toAscii
			}
			if(chkXDim->isChecked() && chkYDim->isChecked() && chkZDim->isChecked()) {
				mecanique->Pos2AngleXYZ(&pan,&tilt,X,Y,Z);
				strPan = QString::number(pan);
				strTilt = QString::number(tilt);
                listeCmd.enqueue("pp:"+strPan.toLatin1()); //toAscii
                listeCmd.enqueue("tp:"+strTilt.toLatin1()); //toAscii
			}
		}
		else { // par rapport a M
			X = lblTabRep[14]->text().toDouble() + txtXDim->text().toDouble();
			Y = lblTabRep[15]->text().toDouble() + txtYDim->text().toDouble();
			Z = lblTabRep[16]->text().toDouble() + txtZDim->text().toDouble();
			if(chkXDim->isChecked() && !chkYDim->isChecked() && !chkZDim->isChecked()) {
				mecanique->Pos2AngleX(&pan,&tilt,X);
				strPan = QString::number(pan);
				strTilt = QString::number(tilt);
                listeCmd.enqueue("pp:"+strPan.toLatin1()); //toAscii
                listeCmd.enqueue("tp:"+strTilt.toLatin1()); //toAscii
			}
			if(!chkXDim->isChecked() && chkYDim->isChecked() && !chkZDim->isChecked()) {
				mecanique->Pos2AngleY(&pan,&tilt,Y);
				strPan = QString::number(pan);
				strTilt = QString::number(tilt);
                listeCmd.enqueue("pp:"+strPan.toLatin1()); //toAscii
                listeCmd.enqueue("tp:"+strTilt.toLatin1()); //toAscii
			}
			if(!chkXDim->isChecked() && !chkYDim->isChecked() && chkZDim->isChecked()) {
				mecanique->Pos2AngleZ(&tilt,Z);
				strTilt = QString::number(tilt);
                listeCmd.enqueue("tp:"+strTilt.toLatin1()); //toAscii
			}
			if(chkXDim->isChecked() && chkYDim->isChecked() && !chkZDim->isChecked()) {
				mecanique->Pos2AngleXY(&pan,&tilt,X,Y);
				strPan = QString::number(pan);
				strTilt = QString::number(tilt);
                listeCmd.enqueue("pp:"+strPan.toLatin1()); //toAscii
                listeCmd.enqueue("tp:"+strTilt.toLatin1()); //toAscii
			}
			if(chkXDim->isChecked() && !chkYDim->isChecked() && chkZDim->isChecked()) {
				mecanique->Pos2AngleXZ(&pan,&tilt,X,Z);
				strPan = QString::number(pan);
				strTilt = QString::number(tilt);
                listeCmd.enqueue("pp:"+strPan.toLatin1()); //toAscii
                listeCmd.enqueue("tp:"+strTilt.toLatin1()); //toAscii
			}
			if(!chkXDim->isChecked() && chkYDim->isChecked() && chkZDim->isChecked()) {
				mecanique->Pos2AngleYZ(&pan,&tilt,Y,Z);
				strPan = QString::number(pan);
				strTilt = QString::number(tilt);
                listeCmd.enqueue("pp:"+strPan.toLatin1()); //toAscii
                listeCmd.enqueue("tp:"+strTilt.toLatin1()); //toAscii
			}
			if(chkXDim->isChecked() && chkYDim->isChecked() && chkZDim->isChecked()) {
				mecanique->Pos2AngleXYZ(&pan,&tilt,X,Y,Z);
				strPan = QString::number(pan);
				strTilt = QString::number(tilt);
                listeCmd.enqueue("pp:"+strPan.toLatin1()); //toAscii
                listeCmd.enqueue("tp:"+strTilt.toLatin1()); //toAscii
			}
		}
		envoi();
		modifEnCours = true;
	}
	else {
        QMessageBox::warning(this,tr("Tourelle Pan Tilt"),tr("Vous devez d'abord vous connecter à une tourelle"));
	}
}

void FenPrincipale::ftcmdPaveHaut() { // touche haut
	if(tourelleConnectee) {
		if(!chkPavebloque->isChecked()) {
            listeCmd.enqueue("to:"+txtPasTiltPave->text().toLatin1()); //toAscii
			envoi();
			modifEnCours = true;
		}
	}
	else {
        QMessageBox::warning(this,tr("Tourelle Pan Tilt"),tr("Vous devez d'abord vous connecter à une tourelle"));
	}
}

void FenPrincipale::ftcmdPaveBas() {
	if(tourelleConnectee) {
		if(!chkPavebloque->isChecked()) {
            listeCmd.enqueue("to:-"+txtPasTiltPave->text().toLatin1()); //toAscii
			envoi();
			modifEnCours = true;
		}
	}
	else {
        QMessageBox::warning(this,tr("Tourelle Pan Tilt"),tr("Vous devez d'abord vous connecter à une tourelle"));
	}
}

void FenPrincipale::ftcmdPaveDroite() {
	if(tourelleConnectee) {
		if(!chkPavebloque->isChecked()) {
            listeCmd.enqueue("po:-"+txtPasPanPave->text().toLatin1()); //toAscii
			envoi();
			modifEnCours = true;
		}
	}
	else {
        QMessageBox::warning(this,tr("Tourelle Pan Tilt"),tr("Vous devez d'abord vous connecter à une tourelle"));
	}
}

void FenPrincipale::ftcmdPaveGauche() {
	if(tourelleConnectee) {
		if(!chkPavebloque->isChecked()) {
            listeCmd.enqueue("po:"+txtPasPanPave->text().toLatin1()); //toAscii
			envoi();
			modifEnCours = true;
		}
	}
	else {
        QMessageBox::warning(this,tr("Tourelle Pan Tilt"),tr("Vous devez d'abord vous connecter à une tourelle"));
	}
}

void FenPrincipale::ftcmdHalt() { // barre espace
	if(tourelleConnectee) {
		listeCmd.enqueue("h:pt");
		envoi();
	}
	else {
        QMessageBox::warning(this,tr("Tourelle Pan Tilt"),tr("Vous devez d'abord vous connecter à une tourelle"));
	}
}

void FenPrincipale::ftcmdNouveau() { // nouvelle position
	if(tourelleConnectee) {
		nouvPos = new NouvPos(pan,tilt);
		QObject::connect(nouvPos,SIGNAL(signalOK(QString,QString,QString)),this,SLOT(ftNouveau(QString,QString,QString)));
		nouvPos->show();
	}
	else {
        QMessageBox::warning(this,tr("Tourelle Pan Tilt"),tr("Vous devez d'abord vous connecter à une tourelle"));
	}
}
// retour validation nouvelle position
void FenPrincipale::ftNouveau(QString nom, QString pan, QString tilt) {
    listeCmd.enqueue("savepos:"+nom.toLatin1()+":"+pan.toLatin1()+":"+tilt.toLatin1()); //toAscii
	lstRegistre->clear();
	listeCmd.enqueue("get:p");
	listeCmd.enqueue("get:i");
	envoi();
	modifEnCours = true;
}

void FenPrincipale::ftcmdSupprimer() { // supprimer position
	if(tourelleConnectee) {
        listeCmd.enqueue("delpos:"+lstRegistre->currentItem()->text().split(QRegExp(" (pan|tilt)="))[0].toLatin1()); //toAscii
		lstRegistre->clear();
		listeCmd.enqueue("get:p");
		listeCmd.enqueue("get:i");
		envoi();
		modifEnCours = true;
	}
	else {
        QMessageBox::warning(this,tr("Tourelle Pan Tilt"),tr("Vous devez d'abord vous connecter à une tourelle"));
	}
}

void FenPrincipale::ftcmdModifier() { // modifier position
	if(tourelleConnectee) {
		modifPos->changeLabel(lstRegistre->currentItem()->text().split(QRegExp(" (pan|tilt)="))[0],lstRegistre->currentItem()->text().split(QRegExp(" (pan|tilt)="))[1],lstRegistre->currentItem()->text().split(QRegExp(" (pan|tilt)="))[2]);
		modifPos->show();
		envoi();
	}
	else {
        QMessageBox::warning(this,tr("Tourelle Pan Tilt"),tr("Vous devez d'abord vous connecter à une tourelle"));
	}
}
// valider modif
void FenPrincipale::ftModif(QString nom, QString pan, QString tilt) {
	if(tourelleConnectee) {
        listeCmd.enqueue("delpos:"+lstRegistre->currentItem()->text().split(QRegExp(" pan="))[0].toLatin1()); //toAscii
        listeCmd.enqueue("savepos:"+nom.toLatin1()+":"+pan.toLatin1()+":"+tilt.toLatin1()); //toAscii
		lstRegistre->clear();
		listeCmd.enqueue("get:p");
		listeCmd.enqueue("get:i");
		envoi();
		modifEnCours = true;
	}
	else {
        QMessageBox::warning(this,tr("Tourelle Pan Tilt"),tr("Vous devez d'abord vous connecter à une tourelle"));
	}
}

void FenPrincipale::ftcmdExecuter() { // executer position
	if(tourelleConnectee) {
        listeCmd.enqueue("exec:"+lstRegistre->currentItem()->text().split(QRegExp(" (pan|tilt)="))[0].toLatin1()); //toAscii
		envoi();
		modifEnCours = true;
	}
	else {
        QMessageBox::warning(this,tr("Tourelle Pan Tilt"),tr("Vous devez d'abord vous connecter à une tourelle"));
	}
}

void FenPrincipale::ftReglage(QString ps, QString ts) { // popup reglage
	if(tourelleConnectee) {
		QString strcommande;
		strcommande = "ps:"+ps;
        listeCmd.enqueue(strcommande.toLatin1()); //toAscii
		strcommande = "ts:"+ts;
        listeCmd.enqueue(strcommande.toLatin1()); //toAscii
		envoi();
	}
	else {
        QMessageBox::warning(this,tr("Tourelle Pan Tilt"),tr("Vous devez d'abord vous connecter à une tourelle"));
	}
}

void FenPrincipale::reception() { // le serveur envoi quelque chose
	QByteArray retour;
	retour = tourelle->readAll();
	if (commande == "connexion") { // lors d'une connexion
		if (retour == "1") {
			ftcmdDeconnection();
            QMessageBox::critical(this,tr("Tourelle Pan Tilt"),tr("Un utilisateur est dejà connecté sur la tourelle.\rUne personne à la fois."));
		}
		else if (retour == "0") {
			lblConnection->setText("Etat actuel : en cours d'identification");
            listeCmd.enqueue("login:"+txtLogin->text().toLatin1()+":"+txtPassWD->text().toLatin1()); //toAscii
		}
		else if(retour == "2") {
            QMessageBox::critical(this,tr("Tourelle Pan Tilt"),tr("La base de données du serveur n'est pas prête. Veuillez contacter votre administrateur système"));
		}
	}
	else if(commande.startsWith("login:")) { // identification
		if (retour == "0") {
			lblConnection->setText("Etat actuel : "+txtLogin->text()+" connecte");
			tourelleLoguee = true;
            listeCmd.enqueue("v:p"); // première tâche en mode connecté
			listeCmd.enqueue("v:t");
			listeCmd.enqueue("get:p");
			listeCmd.enqueue("get:i");
			listeCmd.enqueue("p:p");
			listeCmd.enqueue("p:t");
		}
		else if(retour == "1") {
			QMessageBox::critical(this,"Tourelle Pan Tilt","Commande non reconnue par la tourelle");
		}
		else if(retour == "2") {
			ftcmdDeconnection();
			QMessageBox::critical(this,"Tourelle Pan Tilt","Identification incorrecte.");
		}
	}
	else if(commande.startsWith("savepos:")
			||commande.startsWith("delpos:")) { // commande necessitant BDD
		if(retour == "0") {
			// -----------------------------------------------------------------------
			// zone des actions pour les commandes passés avec succès
			if (commande.startsWith("savepos:")) {
			}
			if (commande.startsWith("delpos:")) {
			}
			// ------------------------------------------------------------------------
		}
		if(retour == "1") {
			QMessageBox::critical(this,"Tourelle Pan Tilt","Commande non reconnue par la tourelle");
		}
		if(retour == "2") {
            QMessageBox::critical(this,"Tourelle Pan Tilt","Il y a une erreur de base de données côté serveur");
		}
	}
	else if(commande.startsWith("pp:")
			||commande.startsWith("tp:")
			||commande.startsWith("po:")
			||commande.startsWith("to:")
			||commande.startsWith("h:")
			||commande.startsWith("v:")
			||commande.startsWith("ps:")
			||commande.startsWith("ts:")
			||commande.startsWith("get:")
			||commande.startsWith("p:")
			||commande.startsWith("exec:")
			||commande.startsWith("infopos:")) {
		if(retour.startsWith("0")) {
			// -----------------------------------------------------------------------
			// zone des actions pour les commandes passés avec succès
			if (commande == "v:pt") {
				lblVitessePan->setText("Vitesse pan : "+retour.split(':')[1]);
				lblVitesseTilt->setText("Vitesse tilt : "+retour.split(':')[2]);
			}
			if (commande == "v:p") {
				lblVitessePan->setText("Vitesse pan : "+retour.split(':')[1]);
			}
			if (commande == "v:t") {
				lblVitesseTilt->setText("Vitesse tilt : "+retour.split(':')[1]);
			}
			if (commande.startsWith("ps:")) {
				lblVitessePan->setText("Vitesse pan : "+commande.split(':')[1]);
			}
			if (commande.startsWith("ts:")) {
				lblVitesseTilt->setText("Vitesse tilt : "+commande.split(':')[1]);
			}
			if (commande == "p:p") {
				QString s;
				s=retour.split(':')[1];
				pan_prec = pan;
				pan = s.toFloat();
				lblTabRep[7]->setText(arrondi((double)pan));
				double x,y,z;
				mecanique->Angle2Pos((double)pan,(double)tilt,&x,&y,&z);
				lblTabRep[9]->setText(arrondi(x));
				lblTabRep[10]->setText(arrondi(y));
				lblTabRep[11]->setText(arrondi(z));
				if (lblTabRep[12]->text()!="-" && lblTabRep[13]->text()!="-") {
					progress->setValue((int)(50*(((pan-pan_prec)/(pan_cons-pan_prec))+((tilt-tilt_prec)/(tilt_cons-tilt_prec)))));
				}
				if (capteur->isVisible())
					capteur->ftcmdConvertirAuto(pan,tilt);
			}
			if (commande == "p:t") {
				QString s;
				s=retour.split(':')[1];
				tilt_avant = tilt;
				tilt = s.toFloat();
				lblTabRep[8]->setText(arrondi((double)tilt));
				double x,y,z;
				mecanique->Angle2Pos((double)pan,(double)tilt,&x,&y,&z);
				lblTabRep[9]->setText(arrondi(x));
				lblTabRep[10]->setText(arrondi(y));
				lblTabRep[11]->setText(arrondi(z));
				if (lblTabRep[12]->text()!="-" && lblTabRep[13]->text()!="-")
					progress->setValue((int)(50*(((pan-pan_prec)/(pan_cons-pan_prec))+((tilt-tilt_prec)/(tilt_cons-tilt_prec)))));
				if (capteur->isVisible())
					capteur->ftcmdConvertirAuto(pan,tilt);
			}
			if (commande == "p:pt") {
				lblTabRep[7]->setText(retour.split(':')[1]);
				lblTabRep[8]->setText(retour.split(':')[2]);
				pan = lblTabRep[7]->text().toFloat();
				tilt = lblTabRep[8]->text().toFloat();
				double x,y,z;
				mecanique->Angle2Pos((double)pan,(double)tilt,&x,&y,&z);
				lblTabRep[9]->setText(arrondi(x));
				lblTabRep[10]->setText(arrondi(y));
				lblTabRep[11]->setText(arrondi(z));
				if (lblTabRep[12]->text()!="-" && lblTabRep[13]->text()!="-")
					progress->setValue((int)(50*(((pan-pan_prec)/(pan_cons-pan_prec))+((tilt-tilt_prec)/(tilt_cons-tilt_prec)))));
				if (capteur->isVisible())
					capteur->ftcmdConvertirAuto(pan,tilt);
			}
			if (commande.startsWith("pp:")) {
				pan_prec = pan;
				pan_cons = commande.split(':')[1].toFloat();
				lblTabRep[12]->setText(commande.split(':')[1]);
				double x=0.0,y=0.0,z=0.0;
				mecanique->Angle2Pos((double)pan_cons,(double)tilt_cons,&x,&y,&z);
				//lblTabRep[14]->setText(QString::number(x)); // bug de l'affichage et bug de positin par rapport a M
				//lblTabRep[15]->setText(QString::number(y));
				//lblTabRep[16]->setText(QString::number(z));
			}
			if (commande.startsWith("tp:")) {
				tilt_prec = tilt;
				tilt_cons = commande.split(':')[1].toFloat();
				lblTabRep[13]->setText(commande.split(':')[1]);
				double x=0.0,y=0.0,z=0.0;
				mecanique->Angle2Pos((double)pan_cons,(double)tilt_cons,&x,&y,&z);
				//lblTabRep[14]->setText(QString::number(x));
				//lblTabRep[15]->setText(QString::number(y));
				//lblTabRep[16]->setText(QString::number(z));
			}
			if (commande.startsWith("po:")) {
				pan_prec = pan;
				lblTabRep[12]->setText(commande.split(':')[1]);
				pan_cons += lblTabRep[12]->text().toFloat();
				double x=0.0,y=0.0,z=0.0;
				mecanique->Angle2Pos((double)pan_cons,(double)tilt_cons,&x,&y,&z);
				//lblTabRep[14]->setText(QString::number(x));
				//lblTabRep[15]->setText(QString::number(y));
				//lblTabRep[16]->setText(QString::number(z));
			}
			if (commande.startsWith("to:")) {
				tilt_prec = tilt;
				lblTabRep[13]->setText(commande.split(':')[1]);
				tilt_cons += lblTabRep[13]->text().toFloat();
				double x,y,z;
				mecanique->Angle2Pos((double)pan_cons,(double)tilt_cons,&x,&y,&z);
				//lblTabRep[14]->setText(QString::number(x));
				//lblTabRep[15]->setText(QString::number(y));
				//lblTabRep[16]->setText(QString::number(z));
			}
			if (commande == "get:p") {
				int i;
				lstRegistre->clear();
				for(i=1;i<=retour.count(':');i++)
					listeCmd.enqueue("infopos:"+retour.split(':')[i]);
			}
			if (commande == "get:i") {
				int i;
				for(i=1;i<=retour.count(':');i++)
					lstRegistre->addItem(retour.split(':')[i]);
			}
			if (commande.startsWith("exec:")) {
			
			}
			if (commande.startsWith("infopos:")) {
				lstRegistre->addItem(commande.split(':')[1]+" pan="+retour.split(':')[1]+" tilt="+retour.split(':')[2]);
			}
			// ------------------------------------------------------------------------
		}
		else if(retour == "1") {
			QMessageBox::critical(this,"Tourelle Pan Tilt","Commande non reconnue par la tourelle");
		}
		else if(retour.startsWith("2")) {
			retour.remove(0,1);
			QMessageBox::critical(this,"Tourelle Pan Tilt","Erreur de la tourelle : "+retour);
		}
		else if(retour == "3") {
			QMessageBox::critical(this,"Tourelle Pan Tilt","La tourelle n'est pas connectée.");
		}
	}
	else if(commande == "") // ne devrait jamais arriver
        QMessageBox::critical(this,"Tourelle Pan Tilt","Une erreur de gestion de communication entre ce logiciel et le serveur de la tourelle s'est produite.\r\nVeuillez verifier l'état du serveur.\nDernière commande : \"\".\nDernier retour : \""+retour+"\".");
	else // commande non reconnu par le client meme (n'arrive jamais)
        QMessageBox::critical(this,"Tourelle Pan Tilt","Une erreur de gestion de communication entre ce logiciel et le serveur de la tourelle s'est produite.\r\nVeuillez verifier l'état du serveur.\nDernière commande : \""+commande+"\".\nDernier retour : \""+retour+"\".");
    commande = ""; // securité pour ne pas prendre 2x une meme commande
	cmdEnCours = false; // fin de commande
	envoi();
}

void FenPrincipale::envoi() { // envoi d'un element de la pile
	if(!listeCmd.isEmpty() && !cmdEnCours) {
		cmdEnCours = true;
		commande = listeCmd.dequeue();
		tourelle->write(commande);
	}
}

void FenPrincipale::ftTimer() {
	if(tourelleLoguee && modifEnCours && listeCmd.isEmpty()) {
		if (pan==pan_avant && tilt==tilt_avant && !debutCmd) {
			modifEnCours = false;
			debutCmd = true;
		}
		else
			debutCmd = false;
		listeCmd.enqueue("p:p");
		listeCmd.enqueue("p:t");
		envoi();
	}
	timer->start(1000);
}

void FenPrincipale::ftPointeurAide() {
	QWhatsThis::enterWhatsThisMode();
}

void FenPrincipale::ftLogiciel() {
    QMessageBox::information(this,"Tourelle Pan Tilt v2.0","Client tourelle pan/tilt v1.0 (mai 2009)\nCompatible avec le Serveur tourelle pan/tilt v1.0 (mai 2009)\n\nRealisé par Thierry FRITZ, Sylvain PETITJACQUES et Yannick SAENGER\n\n\nClient tourelle pan/tilt v2.0 (mai 2015)\nCompatible avec le Serveur tourelle pan/tilt v2.0 (mai 2015)\n\nRealisé par Benoît JELLIMANN et Alexandre MATHERN");
}

QString FenPrincipale::arrondi(double valeur) { // affichage sans trop de chiffres significatifs
	valeur = floor(valeur*1000+0.5) / 1000;
	return QString::number(valeur);
}

void FenPrincipale::MAJdelta(int delta){

            delta_value = (double(delta)/180)*M_PI;
            emit deltaChanged(delta_value);

            x = 2*cos(delta_value)*cos(omega_value);
            y = 2*cos(delta_value)*sin(omega_value);
            z = 2*sin(delta_value);
            emit xChanged(x);
            emit yChanged(y);
            emit zChanged(z);
            sphere->setX(x);
            sphere->setY(y);
            sphere->setZ(z);
            sphere->setDelta(delta_value);
            //sphere->setOmega(omega_value);
}

void FenPrincipale::MAJomega(int omega){

    omega_value = (double(omega)/180)*M_PI;
    emit omegaChanged(omega_value);

    x = 2*cos(delta_value)*cos(omega_value);
    y = 2*cos(delta_value)*sin(omega_value);
    z = 2*sin(delta_value);
    emit xChanged(x);
    emit yChanged(y);
    emit zChanged(z);
    sphere->setX(x);
    sphere->setY(y);
    sphere->setZ(z);
    sphere->setOmega(omega_value);
    if (delta_value!=0.0){
    sphere->setDelta(delta_value);
    }
}

void FenPrincipale::MAJdeltaCons(int deltaCons){

            deltaCons_value = (double(deltaCons)/180)*M_PI;
            emit deltaConsChanged(deltaCons_value);

            xCons = 2*cos(deltaCons_value)*cos(omegaCons_value);
            yCons = 2*cos(deltaCons_value)*sin(omegaCons_value);
            zCons = 2*sin(deltaCons_value);
            emit xConsChanged(xCons);
            emit yConsChanged(yCons);
            emit zConsChanged(zCons);
            sphere->setXCons(xCons);
            sphere->setYCons(yCons);
            sphere->setZCons(zCons);
            sphere->setDeltaCons(deltaCons_value);
            //sphere->setOmega(omega_value);
}

void FenPrincipale::MAJomegaCons(int omegaCons){

    omegaCons_value = (double(omegaCons)/180)*M_PI;
    emit omegaConsChanged(omegaCons_value);

    xCons = 2*cos(deltaCons_value)*cos(omegaCons_value);
    yCons = 2*cos(deltaCons_value)*sin(omegaCons_value);
    zCons = 2*sin(deltaCons_value);
    emit xConsChanged(xCons);
    emit yConsChanged(yCons);
    emit zConsChanged(zCons);
    sphere->setXCons(xCons);
    sphere->setYCons(yCons);
    sphere->setZCons(zCons);
    sphere->setOmegaCons(omegaCons_value);
    if (deltaCons_value!=0.0){
    sphere->setDeltaCons(deltaCons_value);
    }
}

