#include<iostream>
using namespace std;

#include "Consola.h"

//Crea la clase Xbox que esta en herencia con consola
class Xbox: public Consola{
	private:
		string xboxLive;
		int baterias;
		
	public:
		Xbox();
		Xbox(string marc, float gan, string live, int bat);
		//Getters
		string getXboxLive(){
			return xboxLive;
		}
		int getBaterias(){
			return baterias;
		}
		//setters
		void setLive(string live){
			xboxLive = live;
		}
		void setBaterias(int bat){
			baterias = bat;
		}
		
//metodo para eliminar el objeto comprado(esta en play y juegos tambien)
		void eliminaXbox(){
			set_marca("");
			set_ganancia(0);
			xboxLive = "";
			baterias = 0;
		}
	
		float definePrecioXbox();
	
	
};

Xbox::Xbox(){}

Xbox::Xbox(string marc, float gan, string live, int bat):Consola(marc, gan){
	xboxLive = live;
	baterias = bat;
}

//metodo para definir las ganancias de un xbox segun sus caracteristicas
float Xbox::definePrecioXbox(){
	if (xboxLive == "si"){
		set_ganancia(get_ganancia() + 100);
	}
	set_ganancia(get_ganancia() + (baterias * 50));
	return get_ganancia();
}
