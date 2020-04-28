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
	bool abasto = false;
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
	void compra_play(Play p);
	void compra_xbox(Xbox x);
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


//el metodo "compra" calculará los productos restantes después de una compra
void Inventario::compra_play(Play p){
	set_ganancias(p.definePrecioPlay() + (p.definePrecio() * p.definePrecioPlay()));
	//numeroproductos = numeroproductos - 1;
	ps_i --;
	//plays_i[ps_i] = Play vacio("0",0, "0", "0");
	plays_i[ps_i].eliminaPlay();
}
void Inventario::compra_xbox(Xbox x){
	ganancias = ganancias + x.definePrecio();
	//numeroproductos = numeroproductos - 1;
	xb_i --;
	//xboxs_i[xb_i] = Xbox vaci("0",0,"0",0);
	xboxs_i[xb_i].eliminaXbox();
}
void Inventario::compra_juego(int j){
	ganancias = ganancias + juegos_i[j].precioFinal();
	//numeroproductos = numeroproductos - 1;
	jg_i --;
	//juegos_i[jg_i] = Juegos vac("0","0",0,0);
	juegos_i[j].eliminaJuego();
}
	

void Inventario::pedirAbasto(){
	set_numeroproductos(ps_i + xb_i + jg_i);
	if (numeroproductos < 3){
		abasto = true;
	}
}

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

/*
aquí está el main que le da valores de prueba a los atributos para comprobar
que los getters, setters y demás métodos funcionan correctamente, éste
imprimirá los valores dados en un principio y después los imprime 
pero ya posterior a que se ha realizado una compra.
*/
/*
int main(){
	inventario inventario(10, false, "fisico");
	cout << inventario.get_numeroproductos() << " ";
	cout << inventario.get_pedirabasto() << " "; 
	cout << inventario.get_tipojuego() << endl;
	inventario.compra();
	cout << inventario.get_numeroproductos() << " ";
	cout << inventario.get_pedirabasto() << " "; 
	cout << inventario.get_tipojuego() << endl;

}
*/


#endif

