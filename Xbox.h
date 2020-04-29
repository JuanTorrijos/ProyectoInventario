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
		//setters
		void setLive(string live){
			xboxLive = live;
		}
		void setBaterias(int bat){
			baterias = bat;
		}
		
		void agregarBateria(){
			set_ganancia(get_ganancia() + 50);
		}
		
		void eliminaXbox(){
			set_marca("");
			set_ganancia(0);
			xboxLive = "";
			baterias = 0;
		}
	
	
	
};

Xbox::Xbox(){}

Xbox::Xbox(string marc, float gan, string live, int bat):Consola(marc, gan){
	xboxLive = live;
	baterias = bat;
}
//#endif 