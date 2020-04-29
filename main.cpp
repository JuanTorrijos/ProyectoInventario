/*
Autor: Juan Manuel Torrijos González A01706428
Proyecto: Inventario de una tienda de videojuegos
28/04/2020
*/
#include<iostream>
using namespace std;

//#include "Play.h"
//#include "Xbox.h"
//#include "Juegos.h"
//#include "Consola.h"
#include "Inventario.h"

Inventario inv(0, 0.0);

int j;
void abastecer(int cantd, Inventario inv, int j);
//Juegos juegos_i[100];

int main(){	
	inv.pedirAbasto();
	if(inv.get_abasto() == true){
		abastecer(5, inv, j);
	}
	inv.pedirAbasto();
	cout << inv.get_numeroproductos()<<endl;
	cout << inv.get_ganancias() << endl;

	inv.compra_juego(j);
	inv.pedirAbasto();
	cout<<inv.get_numeroproductos()<<endl;
	cout<<inv.get_ganancias()<<endl;
}

void abastecer(int cantd, Inventario inv, int j){
	for(int i=0;i<cantd;i++){
	Play auxp("play", 5000, "si", "no");
	inv.agrega_play(auxp);
	Xbox auxx("xbox", 4000, "no", 1);
	inv.agrega_xbox(auxx);
	Juegos auxj("play", "fisico", 0, 2015);
	inv.agrega_juego(auxj);
	Juegos auxj2("xbox", "digital", 0, 2020);
	inv.agrega_juego(auxj2);
	}
	j = inv.get_jgi();
}

