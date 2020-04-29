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
		
		void eliminaJuego(){
			plataforma = "";
			estado = "";
			precio = 0;
			anio = 0;
		}

	
	
};



float Juegos::precioFinal(){
		if(plataforma == "play"){
			precio = (precio + (1000 + (1000*0.15)));
		}
		else {
			precio = (precio + (1000 + (1000*0.10)));
		}
		
		if(estado == "fisico"){
			precio = (precio + (precio * 0.05));
		}
		
		if((2020 - anio) > 2){
			precio = (precio - (precio * 0.10));
		}
		else{
			precio = (precio + (precio * 0.20));
		}
		return precio;
}

#endif

