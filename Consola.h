#ifndef CONSOLA_H
#define CONSOLA_H


#include<iostream>
using namespace std;
// esta clase definirá las ganancia que se tendrán por un juego según de la consola que sea
//declara la clase consola que determinará cuanto se le aumenta el precio a un juego
class Consola {
	//define los atributos que en este caso son la marca de la consola y la ganancia
	private:
	string marca;
	float ganancia;
	
	//se crea el objeto consola con los metodos, en este caso es el metodo precio que dira en cuanto aumentará éste según 
	// la consola
	public:
	Consola(){};
	Consola(string marc, float gan): marca(marc), ganancia(gan){};
	float definePrecio();
	
	//getters (para saber el valor de las variables)
	string get_marca();
	float get_ganancia();
	
	//setters (para asignarle otro valor a las variables)
	void set_marca(string marc);
	void set_ganancia(float gan);
	
	
};

//Getters (se construyen las funciones de los getters)
string Consola::get_marca(){
	return marca;
}

float Consola::get_ganancia(){
	return ganancia;
}

//Setters (se construyen las funciones de los setters)
void Consola::set_marca(string marc){
	marca = marc;
}

void Consola::set_ganancia(float gan){
	ganancia = gan;
}

//se construye la funcion precio que en base a la marca de la consola define la ganancia
float Consola::definePrecio(){
	if (marca == "xbox"){
		ganancia = ganancia + (ganancia *0.10);
	}
	else if (marca == "play"){
		ganancia = ganancia + (ganancia *0.15);
	}
	else {
		ganancia = ganancia + (ganancia*0.5);
	}
	return ganancia;
}
#endif 

