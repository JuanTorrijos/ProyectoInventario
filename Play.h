#ifndef PLAY_H
#define PLAY_H

#include<iostream>
using namespace std;

#include "Consola.h"
#include "Control.h"

//Crea la clase Play en herencia con consola.
class Play: public Consola{
	private:
		string psPlus;
		string psVR;
		Control control;
		
//se crean los valores por default de un control 
		string colCont = "negro";
		int ledCont = 1;
		int cantCont = 1;
		
	public:
		Play();
		Play(string marc, float gan, string plus, string vr);
		//Getters
		string getPsPlus(){
			return psPlus;
		}
		string getPsVR(){
			return psVR;
		}
		string get_colC(){
			return colCont;
		}
		int get_ledC(){
			return ledCont;
		}
		int get_cantC(){
			return cantCont;
		}
		
		//Setters
		void set_colC(string c){
			colCont = c;
		}
		void set_ledC(int t){
			ledCont = t;
		}
		void set_cantC(int ca){
			cantCont = ca;
		}
		
		//metodos para compra y precio de play
		float definePrecioPlay();
		
		void eliminaPlay(){
			set_marca("");
			set_ganancia(0);
			psPlus = "";
			psVR = "";
		}
	
	
	
};

Play::Play(){}

Play::Play(string marc, float gan, string plus, string vr):Consola(marc, gan){
	psPlus = plus;
	psVR = vr;
}

/*
este metodo calcula la ganancia del play de acuerdo a sus caracteristicas y
a las de su control, que es la clase que esta en composicion con play y que
crea el objeto con las especificaciones del usuario mediante los metodos set
de play.
*/
float Play::definePrecioPlay(){
	Control control(colCont, ledCont, cantCont);
	if (control.getColor() != "negro"){
		set_ganancia(get_ganancia() + 100);
	}
	if(control.getLed() == 1){
		set_ganancia(get_ganancia() + 50);
	}
	else if (control.getLed() == 2){
		set_ganancia(get_ganancia() + 30);
	}
	else{
		set_ganancia(get_ganancia() + 20);
	}
	set_ganancia(get_ganancia() + (control.getCantidad() * 1000));
	
	if(psPlus == "si"){
		set_ganancia(get_ganancia() + 150);
	}
	if (psVR == "si"){
		set_ganancia(get_ganancia() + 3000);
	}
	return get_ganancia();
}	
#endif 