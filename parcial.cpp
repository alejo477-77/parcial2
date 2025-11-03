#include<iostream>
#include<string>
using namespace std;
 const int MAX_CONDUCTORES=10;
 const int MAX_Viajes=10;

 double validarDato(string mensaje){
    double valor;

    do{
        cout<<mensaje;
        cin>>valor;
        if(valor<0){
            cout<<"error el valor no puede ser negativo";
        }
    }while (valor<0);
    return valor; 
 }

 double calcular_total(double distancia[],double costos[],int Num_viaje[]){
    double total=0;
    for(int i=0;i < Num_viaje;i++){
        total+=distancia[i]*costos[i];
    }
    return total;
 }

 double promedio_Distancia (double distancia[],int Num_viaje[]){
    double suma=0;
    for (int i =0; i<Num_viaje; i++){
        suma+=distancia[i];
    }
    return(Num_viaje>0)? suma/Num_viaje:0;
 }

 int main(){
    int num_Conductores;
    cout<<"ingrese la cantidad de conductores"<<endl;
    cin>>num_Conductores;
    while(num_Conductores<=0 || num_Conductores>MAX_CONDUCTORES);
    cout<<"error cantiada de conductores invalida"<<endl;
    cin>>num_Conductores;

    string nombres[MAX_CONDUCTORES];
    double total[MAX_CONDUCTORES];
    double promedio[MAX_CONDUCTORES];

    for(int i=0; i<num_Conductores; i++){
        cout<<"conductor"<<(i+1)<<endl;
        cout<<"nombre;";
        cin>>nombres[i];

        int numViajes;
        cout<<"ingresa el numero de viajes";
        cin>>numViajes;
        while(numViajes<=0||numViajes>MAX_Viajes){
            cout<<"cantidad invalida";
            cin>>numViajes;
        }

    }
 }