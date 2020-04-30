/*
Autor: Juan Manuel Torrijos González A01706428
Proyecto: Inventario de una tienda de videojuegos
02/04/2020
*/

#ifndef INVENTARIO_H
#define INVENTARIO_H

#include<iostream>
using namespace std;

//importo las librerias de las clases
#include "Play.h"
#include "Xbox.h"
#include "Juegos.h"
//crea la constante para los tamaños de arreglos
const int MAX = 100;
//crea la clase inventario que contendrá todos los productos de la tienda
class Inventario {
/*
declara los atributos de la clase que seran los productos que hay,
si es necesario pedir más productos
o si el juego es fisico o digital
*/
	private:
	int numeroproductos;
	float ganancias;
	bool abasto = true;
	int ps_i = 0;
	int xb_i = 0;
	int jg_i = 0;
	Play plays_i[MAX];
	Xbox xboxs_i[MAX];
	Juegos juegos_i[MAX];
/*
declara los metodos que en este caso serán para saber los valores iniciales 
de los atributos, cambiarlos con los setters y con el metodo compra,
calculará los productos restantes en el inventario
*/
	public:
	Inventario();
	Inventario(int numprod, float gan):numeroproductos(numprod), ganancias(gan){};
	void compra_play(int p);
	void compra_xbox(int x);
	void compra_juego(int j);
	void pedirAbasto();
	void agrega_play(Play ps);
	void agrega_xbox(Xbox xb);
	void agrega_juego(Juegos js);
	//getters
	int get_numeroproductos();
	float get_ganancias();
	bool get_abasto();
	int get_jgi(){
		return jg_i;
	}
	int get_psi(){
		return ps_i;
	}
	int get_xbi(){
		return xb_i;
	}
	
	//setters
	void set_numeroproductos(int numprod);
	void set_ganancias(float gan);
};

// los getters nos permitirán saber que valor tienen las variables y 
//aquí se definen con sus funciones
int Inventario::get_numeroproductos(){
	return numeroproductos;
}

float Inventario::get_ganancias(){
	return ganancias;
}
bool Inventario::get_abasto(){
	return abasto;
}

/*
los setters le daran un valor a los atributos según los parametros que
reciben, estos serán proporcionados posteriormente
*/
void Inventario::set_numeroproductos(int numprod){
	numeroproductos = numprod;
}

void Inventario::set_ganancias(float gan){
	ganancias = gan;
}


//los metodos "compra" calcularán los productos restantes después de una
//compra y las ganancias ademas de eliminar el comprado
void Inventario::compra_play(int p){
	plays_i[p].definePrecioPlay();
	ganancias = ganancias + plays_i[p].definePrecio();
	ps_i = ps_i-2;
	plays_i[p].eliminaPlay();
}
void Inventario::compra_xbox(int x){
	xboxs_i[x].definePrecioXbox();
	ganancias = ganancias + xboxs_i[x].definePrecio();
	xb_i = xb_i-2;
	xboxs_i[x].eliminaXbox();
}
void Inventario::compra_juego(int j){
	ganancias = ganancias + juegos_i[j].precioFinal();
	jg_i = jg_i-2;
	juegos_i[j].eliminaJuego();
}
	
//este metodo actualiza el numero de productos y la condicion de abasto
//calcula el numero de productos y si estos son menores a 3, cambia el valor
//de abasto por true para que se abastesca el inventario.
void Inventario::pedirAbasto(){
	set_numeroproductos(ps_i + xb_i + jg_i);
	if (numeroproductos < 3){
		abasto = true;
	}
	else{
		abasto = false;
	}
}

//estos metodos agregan los objetos a sus respectivos arreglos 
void Inventario::agrega_play(Play ps){
	plays_i[ps_i] = ps;
	ps_i ++;
}
void Inventario::agrega_xbox(Xbox xb){
	xboxs_i[xb_i] = xb;
	xb_i ++;
}
void Inventario::agrega_juego(Juegos js){
	juegos_i[jg_i] = js;
	jg_i ++;
}
#endif

