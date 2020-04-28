#ifndef JUEGOS_H
#define JUEGOS_H

#include<iostream>
using namespace std;

class Juegos {
	private:
		string plataforma;
		string estado;
		float precio;
		int anio;
		
	public:
		Juegos(){};
		Juegos(string plat, string est, float pre, int an): plataforma(plat), estado(est), precio(pre), anio(an){};
		
		//Getters
		string getPlat(){
			return plataforma;
		}
		string getEst(){
			return estado;
		}
		float getPrecio(){
			return precio;
		}
		int getAnio(){
			return anio;
		}
		
		//Setters
		void setPrecio(float pre){
			precio = pre;
		}
	
		float precioFinal();
		
		void consultarEstado(){
			getEst();
		}

	
	
};



float Juegos::precioFinal(){
		if(getPlat() == "play"){
			setPrecio(getPrecio() + (1000 + (1000*0.15)));
		}
		else {
			setPrecio(getPrecio() + (1000 + (1000*0.10)));
		}
		
		if(getEst() == "fisico"){
			setPrecio(getPrecio() * (getPrecio() * 0.05));
		}
		
		if((2020 - getAnio()) > 2){
			setPrecio(getPrecio() - (getPrecio() * 0.10));
		}
		else{
			setPrecio(getPrecio() + (getPrecio() * 0.20));
		}
}

#endif

