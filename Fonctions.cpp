#include<iostream>
using namespace std;
#include<Imagine/Graphics.h>
using namespace Imagine;
#include "Classes.h"
#include "Fonctions.h"
#include <Imagine/Common.h>

bool Clavier() {
	Timer t;
	Event e;
		getEvent(1, e);
		cout << t.lap() << endl;
		if (e.type == EVT_KEY_ON)
		{
			return true;
		}
	return false;
}

bool Clavier2() {
	Event e;
	do {
		getEvent(2, e);
		if (e.type == EVT_KEY_ON)
			return true;
	} while (e.type != EVT_NONE);
	return false;
}