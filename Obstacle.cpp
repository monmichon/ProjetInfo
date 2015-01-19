#include<Imagine/Graphics.h>
using namespace Imagine;
#include "Classes.h"

Obstacle::Obstacle(){ //génère un obstacle hors de l'écran
	x = 2*width;
	l = 100;
	h = 50;
	y = 350;
}
void Obstacle::afficher(){
	fillRect(IntPoint2(x,0),l,y,BLACK);
	fillRect(IntPoint2(x, y+h), l, height-h-y, BLACK);
}
void Obstacle:: effacer(){
	fillRect(IntPoint2(x, 0), l, y, WHITE);
	fillRect(IntPoint2(x, y+h), l, height-h-y, WHITE);
}
void Obstacle::bouger(double vx){
	x += vx*dt;
}

bool Obstacle::test(Piaf p){
	double r = p.getr();
	return((p.getx() < (x + l+r)) && (p.getx() > x-r)&& (p.gety()<y+r || p.gety()>y+h-r)); //si p est dans l'obstacle, on retourne true
}

void Obstacle::setx(double X){
	x = X;
}

void Obstacle::sety(double Y){
	y = Y;
}

void Obstacle::seth(double H){
	h = H;
}

bool Obstacle::cadre(){
	if ((x + l) < 0)
		return false;
	else return true;
}
double Obstacle::getx(){
	return x;
}