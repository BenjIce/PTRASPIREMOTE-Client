#ifndef HEADER_FENPRINCIALE
#define HEADER_FENPRINCIALE

#include <QWidget>
#include <QMainWindow>
#include <QMenuBar>
#include <QTabWidget>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSplitter>
#include <QCheckBox>
#include <QRadioButton>
#include <QProgressBar>
#include <QListWidget>
#include <QMessageBox>
#include <QInputDialog>
#include <QTcpSocket>
#include <QQueue>
#include <QByteArray>
#include <QObject>
#include <QMenu>
#include <QKeySequence>
#include <QTimer>
#include <QWhatsThis>
#include <math.h>

#include "mecanique.h"
#include "capteur.h"
#include "reglage.h"
#include "nouvPos.h"
#include "modifPos.h"

class FenPrincipale : public QMainWindow {
		Q_OBJECT
	public:
		FenPrincipale();
	public slots:
		void ftcmdConnection();
		void ftdisconnected();
		void ftcmdDeconnection();
		void ftcmdAngle();
		void ftcmdPosition();
		void envoi();
		void reception();
		void ftcmdPaveHaut();
		void ftcmdPaveBas();
		void ftcmdPaveGauche();
		void ftcmdPaveDroite();
		void ftcmdHalt();
		void ftcmdNouveau();
		void ftNouveau(QString nom, QString A, QString B);
		void ftcmdSupprimer();
		void ftcmdExecuter();
		void ftcmdModifier();
		void ftModif(QString nom, QString A, QString B);
		void ftTimer();
		void ftReglage(QString ps,QString ts);
		void ftPointeurAide();
		void ftLogiciel();
	
	private:
		//
		// controles graphiques
		//
		QWidget *mainWidget;
		QHBoxLayout *mainLayout;
		QGridLayout *layoutER; // envoi retour
		QVBoxLayout *layoutAction;
		QVBoxLayout *layoutGestion;
		// Position angle
		QTabWidget *tabCommande;
		QWidget *grpAngle;
			QVBoxLayout *layoutAngle;
			QHBoxLayout *layoutPanAngle;
			QLabel *lblPanAngle;
			QLineEdit *txtPanAngle;
			QCheckBox *chkPanAngle;
			QHBoxLayout *layoutTiltAngle;
			QLabel *lblTiltAngle;
			QLineEdit *txtTiltAngle;
			QCheckBox *chkTiltAngle;
			QRadioButton *radAbs1Angle;
			QRadioButton *radRelAngle;
			QPushButton *cmdPosAngle;
		// Position dimensions
		QWidget *grpDim;
			QVBoxLayout *layoutDim;
			QHBoxLayout *layoutXDim;
			QLabel *lblXDim;
			QLineEdit *txtXDim;
			QCheckBox *chkXDim;
			QHBoxLayout *layoutYDim;
			QLabel *lblYDim;
			QLineEdit *txtYDim;
			QCheckBox *chkYDim;
			QHBoxLayout *layoutZDim;
			QLabel *lblZDim;
			QLineEdit *txtZDim;
			QCheckBox *chkZDim;
			QRadioButton *radAbs1Dim;
			QRadioButton *radRelDim;
			QPushButton *cmdPosDim;
		// Commande par pave
		QWidget *grpPave;
			QVBoxLayout *layoutPave;
			QGridLayout *layoutTouchesPave;
			QPushButton *cmdHautPave;
			QPushButton *cmdBasPave;
			QPushButton *cmdGauchePave;
			QPushButton *cmdDroitePave;
			QHBoxLayout *layoutPasPanPave;
			QLabel *lblPasPanPave;
			QLineEdit *txtPasPanPave;
			QHBoxLayout *layoutPasTiltPave;
			QLabel *lblPasTiltPave;
			QLineEdit *txtPasTiltPave;
			QCheckBox *chkPavebloque;
		// arret
		QPushButton *cmdHalt;
		// Reponse
		QGroupBox *grpReponse;
			QVBoxLayout *layoutReponse;
			QLabel *lblVitessePan;
			QLabel *lblVitesseTilt;
			QGridLayout *layoutTabRep;
			QLabel *lblTabRep[16];
			QProgressBar *progress;
		// Image nomenclature
			QLabel *pictNom;
		// Connexion
		QGroupBox *grpConnection;
			QVBoxLayout *layoutConnection;
			QGridLayout *layoutTcp;
			QLabel *lblTcp;
			QLineEdit *txtTcp;
			QLineEdit *txtPort;
			QLabel *lblLogin;
			QLineEdit *txtLogin;
			QLabel *lblPassWD;
			QLineEdit *txtPassWD;
			QHBoxLayout *layoutConnect;
			QPushButton *cmdConnection;
			QPushButton *cmdDeconnection;
			QLabel *lblConnection;
		// Registre
		QGroupBox *grpRegistre;
			QVBoxLayout *layoutRegistre;
			QHBoxLayout *layoutNouv;
			QPushButton *cmdNouveau;
			QPushButton *cmdSupprimer;
			QListWidget *lstRegistre;
			QHBoxLayout *layoutExe;
			QPushButton *cmdExecuter;
			QPushButton *cmdModifier;
			QLabel *lblRegistre;
			QProgressBar *progressRegistre;
		//
		// menu
		//
		QMenu *mTourelle;
			QAction *mReglage;
			QAction *mCapteur;
		QMenu *mAide;
			QAction *mPointeur;
			QAction *mLogiciel;
		//
		// liaisons
		//
		QTcpSocket *tourelle;
		bool tourelleConnectee;
		bool tourelleLoguee;
		QByteArray commande;
		bool cmdEnCours;
		bool modifEnCours;
		QQueue<QByteArray> listeCmd;
		Mecanique *mecanique;
		QTimer *timer;
		Reglage *reglage;
		//
		// memoire position
		//
		float pan_prec, tilt_prec; // consigne précédent
		float pan,tilt; // position actuelle
		float pan_avant,tilt_avant; // position instants d'avant
		float pan_cons,tilt_cons; // consigne
		bool debutCmd;
		//
		// informations
		//
		Capteur *capteur;
		NouvPos *nouvPos;
		ModifPos *modifPos;
		
		QString arrondi(double valeur);
};

#endif
