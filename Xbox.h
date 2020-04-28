//#ifndef XBOX_H
//#define XBOX_H

#include<iostream>
using namespace std;

#include "Consola.h"

class Xbox: public Consola{
	private:
		string xboxLive;
		int baterias;
		
	public:
		Xbox();
		Xbox(string marc, float gan, string live, int bat);
		//Getters
		string getXboxLive(){
			return xboxLive;
		}
		int getBaterias(){
			return baterias;
		}
		
		void agregarBateria(){
			set_ganancia(get_ganancia() + 50);
		}
	
	
	
};

Xbox::Xbox(string marc, float gan, string live, int bat):Consola(marc, gan){
	xboxLive = live;
	baterias = bat;
}
//#endif 