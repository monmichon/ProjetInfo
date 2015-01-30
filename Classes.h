#pragma once


const double dt = 0.05; //pas temporel
const double g = 98*dt;//pesanteur
const double vo = -500*dt; //vitesse obstacle;
const double lim = 140;//vitesse limite de l'oiseau
const int width = 600, height = 800;
const int N = 10;

class Piaf{
	double x, y;//position
	double vx,vy;//vitesse
	double m; //masse
	double r;//Rayon
	Color c; //couleur pour jeu à plusieurs (pourquoi pas?)
	void setpos(double X, double Y);
	void setv(double vX, double vY);

public:
	Piaf(double x,double y,double vx, double m,double r,Color c);
	double getr();
	double getx();
	double gety();
	double getvx();
	double getvy();
	void saut(double dy);
	void bouger();
	void afficher();
	void effacer();
};

class Obstacle{
	double x,y, l, h; //x est le coin du bas, l la largeur, h la hauteur du trou dans le tube;
public:
	Obstacle(double x,double y, double l, double h);
	Obstacle();
	void afficher();
	void effacer();
	void bouger(double vx);
	bool test(Piaf p);
	void setx(double X);
	void sety(double Y);
	void seth(double H);
	bool cadre();
	double getx();
};