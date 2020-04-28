#ifndef CONTROL_H
#define CONTROL_H

#include<iostream>
using namespace std;

class Control {
	private:
	string color;
	int estiloLed;
	int cantidad;
	
	public:
	Control(){};
	Control(string col, int led, int cant): color(col), estiloLed(led), cantidad(cant){};
	
	void cambiaColor(string colorn){
		setColor(colorn);
	}
	void cambiaLed(int ledn){
		setLed(ledn);
	}
	
	//getters
	string getColor(){
		return color;
	}
	int getLed(){
		return estiloLed;
	}
	int getCantidad(){
		return cantidad;
	}
	
	//setters
	void setColor(string col){
		color = col;
	}
	void setLed(int led){
		estiloLed = led;
	}
	void setCantidad(int cant){
		cantidad = cant;
	}
	
};
#endif

