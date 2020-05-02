/*Ejercicio # 1:
El presidente de un club de futbol requiere calcular el sueldo de sus jugadores
si se tiene como dato la edad y la nacionalidad del jugador.

Ademas se sabe que el sueldo se calculara de la siguiente manera:
Sueldo fijo $2500.00
Si es extranjero recibe un bono de $500.00

Si la edad esta entre 15 y 20, el salario incrementa en $1400.00
Si la edad esta entre 21 y 25, el salario incrementa en $1500.00
Si la edad esta entre 26 y 30, el salario incrementa en $1200.00
Si la edad es mayor a 30, el salario incrementa en $800.00
Determine el sueldo del jugador si se tiene como datos la edad y nacionalidad.

Mostrar un reporte del total a pagar de planilla, así como el total de jugadores por
los rangos de edad. Ademas de indicar que rango de edad es el mas remunerado.

/*
EJERCICIO #2
El director de un colegio desea realizar un programa que procese un archivo de registros correspondiente a los diferentes 
alumnos del centro a fin de obtener los siguientes datos:

    Nota más alta y número de identificación del alumno correspondiente.
    Nota media del colegio.

Datos de Estudiantes:

    Identificación
    Nombre    
    Nota
*/

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct jugadore {  //estudiante
	string nombre;
	string nacionalidad; //int id	
	float sueldo;	//nota
};
void mp(); 
void ingresardatos(string na);
void leer_archivo(string na);
int main(){
	mp();	
}
void mp(){
	int resp;
	string nombrearchivo;
	cout<<"Indique nombre de archivo: ";
	getline(cin,nombrearchivo);
	
	do {
		system("CLS");
		cout<<"--------------------------"<<"\n";
		cout<<" Menu Principal"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Ingresar Jugador "<<"\n";
		cout<<" 2 - Reporte "<<"\n";		
		cout<<" 3 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			ingresardatos(nombrearchivo);			
		}
		else if (resp==2){		
			system("CLS");
			leer_archivo(nombrearchivo);
		}					
		else if (resp==4)
			break;
		else 
			break;
		
	} while(resp!=4);	
}

void ingresardatos(string na){
	string nacionalidad_est;
	string nombre_est;
	float sueldo_est;
	
	cout<<"Ingrese Nacionalidad del jugador: "<<endl;
	cin>>nacionalidad_est;
	fflush(stdin);
	cout<<"Ingrese Nombre del Jugador: "<<endl;
	getline(cin,nombre_est);
	cout<<"Ingrese Sueldo: "<<endl;
	cin>>sueldo_est;
	
	ofstream archivo; //grabar en archivo;
	fflush(stdin); //borrar el buffer existente
	archivo.open(na.c_str(),ios::app); //append
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	archivo<<nombre_est<<"\t"<<nacionalidad_est<<"\t"<<sueldo_est<<endl;
	archivo.close();
}

void leer_archivo(string na){
	ifstream archivo; //leer archivo;
	fflush(stdin); //borrar el buffer existente
	archivo.open("football.txt",ios::in); //append
	if(archivo.fail()){
		cout<<" 1 No se pudo abrir el archivo";
		exit(1);
	}
	int lineas;
	string s;
	while (getline(archivo, s))
        lineas++;
    archivo.close();
    
    jugador recordset[lineas];
	archivo.open(na.c_str(),ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1);
	}	
	
	for (int i = 0; i < lineas; i++)
    {
        if (!archivo)
        {                                               
            cerr << "No se puede abrir el archivo " << endl;
            system("PAUSE");
            break;
        }
        //cout<<"i: "<<i;
        archivo>>recordset[i].nombre>>recordset[i].nacionalidad>>recordset[i].sueldo;
    	//cout<<s;
	}
    archivo.close();
    for (int i = 0; i < lineas; i++){
    	cout<<recordset[i].nacionalidad<<recordset[i].nombre<<recordset[i].sueldo<<endl;
	}

	system("Pause");
}
