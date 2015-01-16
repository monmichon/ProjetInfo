#include<Imagine/Graphics.h>
using namespace Imagine;
#include "Classes.h"

void Piaf::setpos(double X, double Y){
	x = X;
	y = Y;
}
void Piaf::setv(double vX, double vY){
	vx = vX;
	vy = vY;
}
double Piaf::getr(){
	return r;
}
double Piaf::getx(){
	return x;
}
double Piaf::gety(){
	return y;
}
double Piaf::getvx(){
	return vx;
}
double Piaf::getvy(){
	return vy;
}
void Piaf::saut(double dy){
	vy += -dy;
}
void Piaf::bouger(){
	vy =(abs(vy)>lim)?vy/(abs(vy))*lim:(vy+ m*g*dt);
	x += vx*dt;
	y += vy*dt;
}
void Piaf::afficher(){
	fillCircle(IntPoint2(x, y), r, c);
}
Piaf::Piaf(double X, double Y, double vX, double M,double R,Color C){
	setpos(X, Y);
	setv(vX, 0);
	r = R;
	m = M;
	c = C;
}
void Piaf::effacer(){
	fillCircle(IntPoint2(x, y), r, WHITE);
}

