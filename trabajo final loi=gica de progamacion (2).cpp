#include <iostream>
#include <string>

using namespace std;

bool disponibilidad [4][5];
string marca [4][5];
string tipo [4][5];
string puerto [4][5];
float peso [4][5];
int valorpagados [4][5];
float porcentajes=0;

/*
SE EMPIEZA LAS FUNCIONES 
*/

bool llenarBarcoEnPuerto(string nombrePuerto){

   string marcaaux;
   string tipoaaux;
   float pesoaux;
   int x,y;

   cout<<"----Llenando datos de "<<nombrePuerto<<"----"<<endl;

	
	
	cout<<"----ESPACIOS DISPONIBLES-----"<<endl;
	for(int i=0;i<4;i++){	
		for(int j=0;j<5;j++){
			cout<<disponibilidad[i][j]<<"\t";
		}
		cout<<endl;	
	}


 cout<<"Ingrese posicion X del container: ";
   cin>>x;

   if(x<0 || x>3){
       return false;
   }

   cout<<"Ingrese posicion Y del container: ";
   cin>>y;

   if(y<0 || y>5){
    return false;
   }
   
 if (disponibilidad [x][y]==0){
 	disponibilidad [x][y]=1;
 	
 }else{
 	return false;	
 }

   cout<<"Ingrese peso del container: "<<endl;
   cin>>pesoaux;

   cout<<"Ingrese marca del container: "<<endl;
   cin>>marcaaux;

   cout<<"A: Alimentos"<<endl;
   cout<<"B: Dispositivos electrónicos"<<endl;
   cout<<"C: Ropa y demas textiles"<<endl;

   cout<<"Ingrese tipo del container: "<<endl;
   cin>>tipoaaux;

   /*
    * buscar disponibilidad
    * Imprimir las celdas disponibles
    * Preguntarle al usuario que celdas quiere utilizar
    */

 puerto [x][y]=nombrePuerto; 
 marca [x][y]=marcaaux;
 tipo [x][y]=tipoaaux;
 peso [x][y]=pesoaux;
 
 cout<<"----ESPACIOS DISPONIBLES-----"<<endl;
	for(int i=0;i<4;i++){	
		for(int j=0;j<5;j++){
			cout<<disponibilidad[i][j]<<"\t";
		}
		cout<<endl;
	}
 
 
 
 return true;
 }
 
 void porcentajeOcupacion(){
 	
 	cout<<endl<<"--------PORCENTAJE DE OCUPACION-------"<<endl;
 	
 	float contador=0;
 	
 	for(int i=0;i<4;i++){	
		for(int j=0;j<5;j++){
			contador=contador+disponibilidad[i][j];
		}
	}
	cout<<"Porcentaje de ocupacion: "<<(contador/20)*100<<"%"<<endl;
	
	cout<<endl<<"---------------------------------"<<endl;
 }   
    
void calculoRecaudado(){
	cout<<endl<<"--------CALCULO DE RECAUDO-------"<<endl;
	
	int suma;
	
	for(int i=0;i<4;i++){	
		for(int j=0;j<5;j++){
		
				if(i==1 || i==2){
					if(j>0 && j<4){
						suma=suma+disponibilidad[i][j]*300;
					}else{
						suma=suma+disponibilidad[i][j]*100;
					}
				}else{
					suma=suma+disponibilidad[i][j]*100;
	  }
     }
    }
   cout<<"Valor recaudado: "<<suma<<" USD ";
   cout<<endl<<"---------------------------------"<<endl;
   
}

void contenedoresEnZonaEconomica(){

cout<<endl<<"--------CONTENEDORES EN LA ZONA ECONOMICA-------"<<endl;
	
	cout<<"Las marcas que hay en la zona economica son: "<<endl;
	
	for(int i=0;i<4;i++){	
		for(int j=0;j<5;j++){
			
			if(i==1 || i==2){
				
				if(j>0 && j<4){
						
				}else{						
					if(disponibilidad[i][j]==1){
					
						cout<<marca[i][j]<<"/"<<endl;
					}
					
				}
			}else{
				if(disponibilidad[i][j]==1){							
					cout<<marca[i][j]<<"/";
				}
			}
  		}
 	}
 	cout<<endl<<"---------------------------------"<<endl;
}

void contenedoresEnZonaPremium(){
	
	cout<<endl<<"--------CONTENEDORES EN LA ZONA PREMIUM-------"<<endl;
	
		cout<<"Las marcas que hay en la zona premium son: ";
	
	for(int i=0;i<4;i++){	
		for(int j=0;j<5;j++){
			
			if(i==1 || i==2){
				
				if(j>0 && j<4){
					if(disponibilidad[i][j]==1){
					
						cout<<marca[i][j]<<"/"<<endl;
					}
						
		}	
  	  }
 	}
  }
  cout<<endl<<"---------------------------------"<<endl;
}

void calcularCostoPorEmpresa(){
	
		cout<<endl<<"--------CALCULO COSTO POR EMPRESA-------"<<endl;
	
	string analizarMarca;
	
	cout<<"Ingrese marca a analizar: ";
	cin>>analizarMarca;
	
			int suma=0;
	
	for(int i=0;i<4;i++){	
		for(int j=0;j<5;j++){
		
				if(i==1 || i==2){
					if(j>0 && j<4){
						if(marca[i][j]==analizarMarca){
							suma=suma+disponibilidad[i][j]*300;
						}
						
					}else{
						if(marca[i][j]==analizarMarca){
							suma=suma+disponibilidad[i][j]*100;
						}
						
					}
				}else{
					if(marca[i][j]==analizarMarca){
							suma=suma+disponibilidad[i][j]*100;
						}
			
     }
    }
 }
  cout<<"Valor a cobrar a marca: "<<analizarMarca<<" es "<<suma<<" USD "<<endl;
  
  cout<<endl<<"---------------------------------"<<endl;
}

void promedioPeso(){
	
	cout<<endl<<"--------PROMEDIO DEL PESO-------"<<endl;
	
	int suma=0;
	int contador=0;
	float promedio=0;
	
	
	
	for(int i=0;i<4;i++){	
		for(int j=0;j<5;j++){
			
		contador=contador+disponibilidad[i][j];
		suma=suma+peso[i][j]*disponibilidad[i][j];
		
 	}
  }
	promedio=suma/contador;
	
	cout<<"El promedio de peso de todos los contenedores es: "<<promedio<<endl;
	
	cout<<endl<<"---------------------------------"<<endl;
}

void filaMasGrande(){
	
	cout<<endl<<"--------FILA MAS PESADA-------"<<endl;
	
	int suma=0;
	int filagrande=0;
	int indicefila;
	
	
	
	for(int i=0;i<4;i++){
		suma=0;	
		for(int j=0;j<5;j++){
		suma=suma+peso[i][j]*disponibilidad[i][j];	
				
 	}
 	if(suma>filagrande){
 		filagrande=suma;
 		indicefila=i;
	 }
  }
  cout<<"En la fila que hay mas carga es la: "<<indicefila<<" con un peso de: "<<filagrande<<endl;
  
  cout<<endl<<"---------------------------------"<<endl;
}

void columnaMasPequena(){
	
	cout<<endl<<"--------COLUMNA MAS LIVIANA-------"<<endl;
	
	int suma=0;
	int columnapeque=999999;
	int indicefila;
	
	
	
	for(int i=0;i<5;i++){
		for(int j=0;j<4;j++){
		suma=suma+peso[j][i]*disponibilidad[j][i];	
				
 	}
 	if(suma<columnapeque){
 		columnapeque=suma;
 		indicefila=i;
	 }
	 suma=0;
  }
  cout<<"En la columna que hay menos carga es la: "<<indicefila<<" con un peso de: "<<columnapeque<<endl;
  
  cout<<endl<<"---------------------------------"<<endl;
}




void calcularTipo(){
	
	cout<<endl<<"--------CALCULO TIPO DE MERCANCIA-------"<<endl;
	
	string analizarTipo;
	
   cout<<"A: Alimentos"<<endl;
   cout<<"B: Dispositivos electrónicos"<<endl;
   cout<<"C: Ropa y demas textiles"<<endl;
	
	cout<<"Ingrese tipo de mercancia a analizar: ";
	cin>>analizarTipo;
	
			int suma=0;
	
	for(int i=0;i<4;i++){	
		for(int j=0;j<5;j++){
					if(tipo[i][j]==analizarTipo){
							suma=suma+disponibilidad[i][j];
		}	
      }
    }
 
  cout<<"Tipo de mercancia: "<<analizarTipo<<" es "<<suma<<endl;
  
  cout<<endl<<"---------------------------------"<<endl;
}

void promedioPesoPorPuerto(){
	
	cout<<endl<<"--------PROMEDIO DE PESO POR PUERTO-------"<<endl;
	
	int suma=0;
	int contador=0;
	float promedio=0;
	string nombrepuerto;
	
	cout<<"Ingrese el nombre del puerto que quira saber el promedio de peso cargado: "<<nombrepuerto;
	cin>>nombrepuerto;
	
	for(int i=0;i<4;i++){	
		for(int j=0;j<5;j++){
		
		if(nombrepuerto==puerto[i][j]){
		contador=contador+disponibilidad[i][j];
		suma=suma+peso[i][j]*disponibilidad[i][j];
    }
   }
  }
	promedio=suma/contador;
	
	
	cout<<"El promedio de peso del puerto: "<<nombrepuerto<<" es "<<promedio<<endl;
	
	cout<<endl<<"---------------------------------"<<endl;
}

void empresaMasPeso(){
	
	cout<<endl<<"--------EMPRESA CON MAS PESO-------"<<endl;
    
	int marcagrande=0;
	string indiceMarca;
	
	
	
	for(int i=0;i<4;i++){
		for(int j=0;j<5;j++){	
		
		if(peso[i][j]*disponibilidad[i][j]>marcagrande){
 		marcagrande=peso[i][j]*disponibilidad[i][j];
 		indiceMarca=marca[i][j];
 		
	 }	
 	}
  }
  cout<<"la marca que tiene el contenedor mas pesado es la: "<<indiceMarca<<endl;
  
  cout<<endl<<"---------------------------------"<<endl;
}

void contenedorMasLiviano(){
	
	cout<<endl<<"--------CONTENEDOR MAS LIVIANO-------"<<endl;
	
	int contepeque=999999;
	string indiceMarca;
	
	
	
	for(int i=0;i<4;i++){
		for(int j=0;j<5;j++){	
		
		if(disponibilidad[i][j]==1){
		
			if(peso[i][j]<contepeque){
 			contepeque=peso[i][j];
 			indiceMarca=marca[i][j];
 		
	  }	
     }
 	}
  }
  cout<<"la marca que tiene el contenedor mas liviano es la: "<<indiceMarca<<" con el peso de: "<<contepeque;
  
  cout<<endl<<"---------------------------------"<<endl;	
}



void imprimerVectores(int cantidad[],string puertoNombre[],int container){
	
	cout<<endl<<"--------NUMERO DE  CONTENEDORES POR PUERTO-------"<<endl;
	
for(int i=0;i<container;i++){
	cout<<puertoNombre[i]<<" Tiene: "<<cantidad[i]<<" de containers"<<endl;
 	}	
 	cout<<endl<<"---------------------------------"<<endl;
}


int main() {
   string puertoNombre [20];
   int cantidad [20];
   int puertos;
   int container;

   /*
    * Preguntar cuántos puertos son
    */

   cout<<"Cuanto puertos son?: ";
   cin>>puertos;

   for(int i=0;i<puertos;i++){
       //Ciclo grande del programa
		
       
       string nombrePuerto;

       cout<<"ingrese nombre del puerto: #"<<(i+1)<<" ";
       cin>>nombrePuerto;
       
       
       cout<<"Ingrese la cantidad de containers a ingresar en el puerto: "<<nombrePuerto<<" : ";
       cin>>container;
       		cantidad [i]=container;
        			puertoNombre [i]=nombrePuerto;
       
       for(int j=0;j<container;j++){
       	bool guardado=false;
       		do{
           guardado= llenarBarcoEnPuerto(nombrePuerto);

           }while(!guardado);
           
	   }
   }
   

bool salirMenu=false;

do{
	int opcion=0;
	cout<<endl<<"----------MENU--------"<<endl;
	cout<<"1) porcentaje ocupacion"<<endl;
	cout<<"2) calculo de recaudo"<<endl;
	cout<<"3) contenedores por puerto"<<endl;
	cout<<"4) contenedores en zona economica"<<endl;
	cout<<"5) contenedores en zona premium"<<endl;
	cout<<"6) calculo costo por empresa"<<endl;
	cout<<"7) promedio peso"<<endl;
	cout<<"8) fila mas pesada"<<endl;
	cout<<"9) columna mas liviana"<<endl;
	cout<<"10) calculo de tipo de mercancia"<<endl;
	cout<<"11) promedio peso por puerto"<<endl;
	cout<<"12) empresa mas pesada"<<endl;
	cout<<"13) contenedor mas liviano"<<endl;
	cout<<"14) Salir del programa"<<endl;
	cout<<"opcion:";
	cin>>opcion;
	cout<<endl<<"----------------------"<<endl;
	
	if(opcion==1){
		porcentajeOcupacion();	//
	}
	if(opcion==2){
		calculoRecaudado();	//
	}  
	if(opcion==3){		
		imprimerVectores(cantidad,puertoNombre,puertos);//
	}
	if(opcion==4){		
		contenedoresEnZonaEconomica();//
	}
	if(opcion==5){		
		contenedoresEnZonaPremium();//
	}
	if(opcion==6){		
		calcularCostoPorEmpresa();//
	}
	if(opcion==7){		
		promedioPeso();//
	}
	if(opcion==8){		
		filaMasGrande();//
	}
	if(opcion==9){		
		columnaMasPequena();//
	}
	if(opcion==10){		
		calcularTipo();
	}
	if(opcion==11){		
		promedioPesoPorPuerto();
	}
	if(opcion==12){		
		empresaMasPeso();
	}
	if(opcion==13){		
		contenedorMasLiviano();
	}
	if(opcion==14){
		salirMenu=true;
	}
	
}while(!salirMenu);

   return 0;
}


