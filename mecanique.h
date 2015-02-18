#ifndef HEADER_MECANIQUE
#define HEADER_MECANIQUE

#include <math.h>
#define PI 3.1414279

class Mecanique {
	public:
		Mecanique();
		void Angle2Pos(double pan, double tilt, double *X, double *Y, double *Z);
		void Pos2AngleX(double *pan, double *tilt, double X);
		void Pos2AngleY(double *pan, double *tilt, double Y);
		void Pos2AngleZ(double *tilt, double Z);
		void Pos2AngleXY(double *pan, double *tilt, double X, double Y);
		void Pos2AngleXZ(double *pan, double *tilt, double X, double Z);
		void Pos2AngleYZ(double *pan, double *tilt, double Y, double Z);
		void Pos2AngleXYZ(double *pan, double *tilt, double X, double Y, double Z);
		
	private:
			// premier moteur
		double OO1x;
		double OO1y;
		double OO1z;
			// deuxième moteur
		double O1O2x1;
		double O1O2y1;
		double O1O2z1;
			// fourche
		double O2Mx2;
		double O2My2;
		double O2Mz2;
		
};

#endif
