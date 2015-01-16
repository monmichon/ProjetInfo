#include <Imagine/Graphics.h>
using namespace Imagine;
#include<iostream>
using namespace std;

#include "Classes.h"

#include "Fonctions.h"

double x0 = width / 3, vx = 80, m = 15,r=8;

int main(){ 
	srand(time(NULL));
	Piaf p(x0, height/2, 0, m,r,RED);  //cr�e un piaf (cercle de rayon r, de masse m, plac� en (x0,height/2) etde couleur rouge)
	Obstacle obs[N]; //liste de tout les obstacles
	int n = 0; //n est le nombre d'obstacles cr��s
	openWindow(width,height, "FlaPonts Bird");
	obs[n].setx(width);
	obs[n].sety(double(rand()) / RAND_MAX*(height - 200));
	obs[n].seth(100 + 50 * double(rand()) / RAND_MAX);
	bool b=false;
	Timer t;

	while (!b){
		t.reset();
		if ((rand() % 10 == 0) && (obs[n].getx()<(width-200)|| n==0)) //on cr�e un obstacle si le dernier est suffisament avanc�. Le rand() sert � ne pas avoir une distnce constante entre deux obstacles
		{
			n++;
			obs[n].setx(width);
			obs[n].sety(double(rand()) / RAND_MAX*(height-200)); 
			obs[n].seth(100 + 50 * double(rand()) / RAND_MAX);
		}
		noRefreshBegin();
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
		
		p.effacer();
		if (Clavier())
			p.saut(200);
		cout << t.lap() << endl;
		p.bouger();
		p.afficher();
		noRefreshEnd();
		for (int i = 0; i < 3; i++) //Jamais plus de trois obstacles pass�s par p et toujours dans l'�cran, pas besoin de tout tester
			b = b||obs[i].test(p);
		milliSleep(45- 1000*t.lap());
	}
	cout << "PERDU" << endl;
	endGraphics();
	return 0;
}

