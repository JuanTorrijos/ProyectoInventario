#ifndef PLAY_H
#define PLAY_H

#include<iostream>
using namespace std;

#include "Consola.h"
#include "Control.h"

class Play: public Consola{
	private:
		string psPlus;
		string psVR;
		Control control;
		
		
	public:
		Play();
		Play(string marc, float gan, string plus, string vr);
		
		string getPsPlus(){
			return psPlus;
		}
		string getPsVR(){
			return psVR;
		}
		
		//void agregarVR(){
		//	set_ganancia(get_ganancia + 3000);
		
		void agregaControl(){
			Control control("negro", 1, 2);
		}
		
		float definePrecioPlay();
		
		void eliminaPlay(){
			set_marca("");
			set_ganancia(0);
			psPlus = "";
			psVR = "";
		}
	
	
	
};

Play::Play(string marc, float gan, string plus, string vr):Consola(marc, gan){
	psPlus = plus;
	psVR = vr;
}

float Play::definePrecioPlay(){
	Control control("negro", 1, 2);
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


//int main(){
	//Control control("rojo", 1, 2);
	//Play play("si", "no");
	

	
	
	
#endif 