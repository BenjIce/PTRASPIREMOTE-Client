#include "mecanique.h"

Mecanique::Mecanique() {
	// premier moteur
	OO1x = 2;
	OO1y = 2.159;
	OO1z = 4.572;
	// deuxième moteur
	O1O2z1 = 4.5;
	// fourche
	O2Mz2 = 3.9116;
}
 // conversion d'egre vers cm
void Mecanique::Angle2Pos(double pan, double tilt, double *X, double *Y, double *Z) {
	pan=pan * PI/180;
	tilt=tilt * PI/180;
	*X = O2Mz2*sin(tilt)*cos(pan) + OO1x;
	*Y = -O2Mz2*sin(tilt)*sin(pan) + OO1y;
	*Z = O2Mz2*cos(tilt) + O1O2z1 + OO1z;
}
// differentes conversions cm vers degre en fonction des boutons coches
void Mecanique::Pos2AngleX(double *pan, double *tilt, double X) {
	*pan = 0.0;
	*tilt = acos((X-OO1x) / O2Mz2);
	*tilt = *tilt*180/PI;
}

void Mecanique::Pos2AngleY(double *pan, double *tilt, double Y) {
	*pan = 90.0;
	*tilt = acos((Y-OO1y) / O2Mz2);
	*tilt = *tilt*180/PI;
}

void Mecanique::Pos2AngleZ(double *tilt, double Z) {
	*tilt = acos((Z - O1O2z1 - OO1z) / O2Mz2);
	*tilt = *tilt*180/PI;
}

void Mecanique::Pos2AngleXY(double *pan, double *tilt, double X, double Y) {
	*pan=0.0; // pas fait
	*tilt=0.0;
}

void Mecanique::Pos2AngleXZ(double *pan, double *tilt, double X, double Z) {
	*tilt = acos((Z - O1O2z1 - OO1z) / O2Mz2);
	*pan = acos((X - OO1x) / (O2Mz2*sin(*tilt)));
	*pan = *pan*180/PI;
	*tilt = *tilt*180/PI;
}

void Mecanique::Pos2AngleYZ(double *pan, double *tilt, double Y, double Z) {
	*tilt = acos((Z - O1O2z1 - OO1z) / O2Mz2);
	*pan = asin((Y - OO1y) / (-O2Mz2*sin(*tilt)));
	*pan = *pan*180/PI;
	*tilt = *tilt*180/PI;
}

void Mecanique::Pos2AngleXYZ(double *pan, double *tilt, double X, double Y, double Z) {
	*pan=0.0; // pas fait
	*tilt = 0.0;
}
