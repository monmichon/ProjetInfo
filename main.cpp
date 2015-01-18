#include <Imagine/Graphics.h>
using namespace Imagine;
#include<iostream>
using namespace std;
#include <cmath>
#include "Classes.h"

#include "Fonctions.h"

const double x0 = width / 3, vx = 700*dt, m = 20,r=8, jump=3000*dt;

int main(){ 
	srand(time(NULL));
	Piaf p(x0, height/2, 0, m,r,RED);  //crée un piaf (cercle de rayon r, de masse m, placé en (x0,height/2) etde couleur rouge)
	Obstacle obs[N]; //liste de tout les obstacles
	int n = 0; //n est le nombre d'obstacles créés
	openWindow(width,height, "FlaPonts Bird");
	bool b=false;
	Timer t;
	double u = 0;
	while (!b){
		t.reset();
		if (n == 0||obs[n-1].getx()<width/3) //on crée un obstacle si le dernier est suffisament avancé (dans le tiers gauche). Le rand() sert à ne pas avoir une distnce constante entre deux obstacles
		{
			n++;
			obs[n-1].setx(width+50*double(rand())/RAND_MAX);
			obs[n-1].sety(double(rand()) / RAND_MAX*(height-200)); 
			u = double(rand()) / RAND_MAX;
			obs[n - 1].seth(130 + 10 * sqrt(-2*log(u))*cos(2* M_PI*u)); //loi gaussienne pour l'epaisseur (pour éviter qu'il y ait trop de trucs large, mais un peu quand même
		}
		noRefreshBegin();
		p.effacer();
		if (Clavier())
			p.saut(jump);
		p.bouger();
		p.afficher();
		for (int i = 0; i < n; i++)
		{
			obs[i].effacer();
			obs[i].bouger(-vx);
			if (obs[i].cadre()) //on affiche l'obstacle i  si il est dans la fenêtre
				obs[i].afficher();
			else{ //sinon on l'efface de la liste et on décale l'ensemble 
				for (int i = 0; i < n; i++)
					obs[i] = obs[i + 1];
				n--;
			}
		}
		noRefreshEnd();
		for (int i = 0; i < 3; i++) //Jamais plus de trois obstacles passés par p et toujours dans l'écran, pas besoin de tout tester
			b = b||obs[i].test(p);
		milliSleep(250*dt- 1000*t.lap());
	}
	cout << "PERDU" << endl;
	endGraphics();
	return 0;
}

