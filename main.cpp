#include <Imagine/Graphics.h>
using namespace Imagine;
#include<iostream>
using namespace std;
#include <cmath>
#include "Classes.h"

#include "Fonctions.h"

const double x0 = width / 3, vx = 1400*dt, m = 40,r=13, jump=180*m*dt; 

int main(){ 
	srand(time(NULL));
	Piaf p(x0, height/2, 0, m,r,RED);  //cr�e un piaf (cercle de rayon r, de masse m, plac� en (x0,height/2) etde couleur rouge)
	Obstacle obs[N]; //liste de tout les obstacles
	int n = 0; //n est le nombre d'obstacles cr��s
	openWindow(width,height, "FlaPonts Bird");
	bool b=false;
	Timer t;
	double u = 0,v=0;
	while (!b && p.gety()>r && p.gety()<height-r){
		t.reset();
		if (n == 0||obs[n-1].getx()<width/3) //on cr�e un obstacle si le dernier est suffisament avanc� (dans le tiers gauche). Le rand() sert � ne pas avoir une distnce constante entre deux obstacles
		{
			n++;
			obs[n-1].setx(width+50*double(rand())/RAND_MAX);
			obs[n-1].sety(double(rand()) / RAND_MAX*(height-200)); 
			u = double(rand()) / RAND_MAX;
			v = double(rand()) / RAND_MAX;
			obs[n - 1].seth(135 + 20 * sqrt(-2*log(u))*cos(2* M_PI*v)); //loi gaussienne pour l'epaisseur (pour �viter qu'il y ait trop de trucs large, mais un peu quand m�me
		}
		noRefreshBegin();
		p.effacer();
		if (Clavier()){
			if (p.getvy() > 0)
				p.saut(jump);
			else
				p.saut(jump - p.getvy());
		}
		p.bouger();
		p.afficher();
		for (int i = 0; i < n; i++)
		{
			obs[i].effacer();
			obs[i].bouger(-vx);
			if (obs[i].cadre()) //on affiche l'obstacle i  si il est dans la fen�tre
				obs[i].afficher();
			else{ //sinon on l'efface de la liste et on d�cale l'ensemble 
				for (int i = 0; i < n; i++)
					obs[i] = obs[i + 1];
				n--;
			}
		}
		noRefreshEnd();
		for (int i = 0; i < 3; i++) //Jamais plus de trois obstacles pass�s par p et toujours dans l'�cran, pas besoin de tout tester
			b = b||obs[i].test(p);
		if (250 * dt - 1000 * t.lap()>0)
			milliSleep(250 * dt - 1000 * t.lap());
	}
	cout << "PERDU" << endl;
	endGraphics();
	return 0;
}

