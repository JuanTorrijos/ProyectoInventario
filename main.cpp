/*
Autor: Juan Manuel Torrijos González A01706428
Proyecto: Inventario de una tienda de videojuegos
28/04/2020
*/
#include<iostream>
using namespace std;
/*
Importo las clases que se usarán, como la clase inventario ya incluye a las
demas clases solo la incluyo aqui, pero como se usara un metodo directamente
de la clase play, se importa también
*/
#include "Play.h"
#include "Inventario.h"
//crea el objeto inventario con sus valores default y las variables que usara
Inventario inv(0, 0);
int j;
int p;
int x;
int sel;

//en el main se crearan y agregaran los objetos y se despliegara el menu
int main(){	
//se corre la funcion de abasto para actualizar los indices y productos
	inv.pedirAbasto();
//se imprimen los valores siguientes para confirmar que estan correctos
	cout<<"abasto: "<<inv.get_abasto()<<endl;
	cout<<"indice juegos: "<<inv.get_jgi()<<endl;
	cout<<"indice plays: "<<inv.get_psi()<<endl;
	cout<<"indice xboxs: "<<inv.get_xbi()<<endl<<endl;
/*
Ahora ya que no hay productos en el inventario, la funcion get_abasto 
regresara su valor default true y ya que es true es necesario agregar objetos
con un ciclo creara los objetos de cada tipo y los guardara en sus respectivos
arreglos para tenerlos listos en el inventario
*/
	if(inv.get_abasto() == 1){
		for(int i=0;i<5;i++){
			Play auxp("play", 5000, "si", "no");
			inv.agrega_play(auxp);
			Xbox auxx("xbox", 4000, "no", 1);
			inv.agrega_xbox(auxx);
			Juegos auxj("play", "fisico", 0, 2015);
			inv.agrega_juego(auxj);
			Juegos auxj2("xbox", "digital", 0, 2020);
			inv.agrega_juego(auxj2);
		}
//inicia los indices para las compras y se imprimen para verificar
		j = inv.get_jgi();
		p = inv.get_psi();
		x = inv.get_xbi();
	}
	cout<<"j: "<<j<<endl;
	cout<<"p: "<<p<<endl;
	cout<<"x: "<<x<<endl;
	
//ya que hay productos se actualizan los datos y se imprimen para verificar
	inv.pedirAbasto();
	cout<<endl<<"abasto: "<<inv.get_abasto()<<endl;
	cout<<"indice juegos: "<<inv.get_jgi()<<endl;
	cout<<"indice plays: "<<inv.get_psi()<<endl;
	cout<<"indice xboxs: "<<inv.get_xbi()<<endl;
	cout <<"productos: "<< inv.get_numeroproductos()<<endl;
	cout <<"ganancias: "<< inv.get_ganancias() << endl<<endl;

/*
despliega el menu que le permitira al usuario definir las caracteristicas dela
producto que comprará
*/
	cout<<"Producto a comprar:"<<endl;
	cout<<"Plastation = 1"<<endl<<"Xbox = 2"<<endl<<"Juego = 3"<<endl;
	cin>>sel;
	if(sel == 1){
		cout<<"Agregar PS plus: ";
		string pp;
		cin>>pp;
		cout<<"Agregar ps VR: ";
		string pvr;
		cin>>pvr;
		
		cout<<"Agregar control: ";
		string ac;
		cin>>ac;
/*
compara los datos dados y arma el paquete de producto con ellos
una vez que arma el producto lo agrega al inventario para que se cobre 
y llama su respectiva funcion de compra
*/
		if(ac == "si"){
			cout<<"Color: ";
			string colCon;
			cin>>colCon;
			cout<<"Tipo de led (1, 2 o 3): ";
			int tl;
			cin>>tl;
			cout<<"Numero de controles: ";
			int nc;
			cin>>nc;
			Play auxp("play", 5000, pp, pvr);
			auxp.set_colC(colCon);
			auxp.set_ledC(tl);
			auxp.set_cantC(nc);
			inv.agrega_play(auxp);
			inv.pedirAbasto();
			p = inv.get_psi();
			inv.compra_play(p-1);
		}
		else{
			Play auxp("play", 5000, pp, pvr);
			inv.agrega_play(auxp);
			inv.pedirAbasto();
			p = inv.get_psi();
			inv.compra_play(p-1);
		}
		
	}
	else if(sel == 2){
		cout<<"Agregar XboxLive: ";
		string xl;
		cin>>xl;
		cout<<"Baterias: ";
		int bt;
		cin>>bt;
		Xbox auxx("xbox", 4000, xl, bt);
		inv.agrega_xbox(auxx);
		inv.pedirAbasto();
		x = inv.get_xbi();
		inv.compra_xbox(x-1);
	}
	else{
		cout<<"Plataforma (play o xbox): ";
		string pt;
		cin>>pt;
		cout<<"fisico o digital: ";
		string fd;
		cin>>fd;
		cout<<"Anio: ";
		int an;
		cin>>an;
		Juegos auxj(pt, fd, 0, an);
		inv.agrega_juego(auxj);
		inv.pedirAbasto();
		j = inv.get_jgi();
		inv.compra_juego(j-1);
	}

/*
por ultimo vuelve a actualizar los datos de productos restantes, ganancias,
y lo que queda de cada producto y los imprime 
*/
	inv.pedirAbasto();
	cout<<"productos: "<<inv.get_numeroproductos()<<endl;
	cout<<"ganancias: "<<inv.get_ganancias()<<endl;
	cout<<"indice juegos: "<<inv.get_jgi()<<endl;
	cout<<"indice plays: "<<inv.get_psi()<<endl;
	cout<<"indice xboxs: "<<inv.get_xbi()<<endl;
}


