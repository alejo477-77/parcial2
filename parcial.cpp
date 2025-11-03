#include <iostream>
#include <string>
using namespace std;

const int MAX_CONDUCTORES = 10;
const int MAX_VIAJES = 10;

double validarDato(string mensaje) {
    double valor;
    do {
        cout << mensaje;
        cin >> valor;
        if (valor < 0) {
            cout << "error: el valor no puede ser negativo. Intente nuevamente"<<endl;
        }
    } while (valor < 0);
    return valor;
}

double calcularTotal(double distancia[], double costos[], int numViajes) {
    double total = 0;
    for (int i = 0; i < numViajes; i++) {
        total += distancia[i] * costos[i];
    }
    return total;
}

double promedioDistancia(double distancia[], int numViajes) {
    double suma = 0;
    for (int i = 0; i < numViajes; i++) {
        suma += distancia[i];
    }
    return (numViajes > 0) ? suma / numViajes : 0;
}

int main() {
    int numConductores;

   
    do {
        cout << "ingrese la cantidad de conductores (máx. " << MAX_CONDUCTORES << "): ";
        cin >> numConductores;
        if (numConductores <= 0 || numConductores > MAX_CONDUCTORES) {
            cout << "error cantidad de conductores inválida"<<endl;
        }
    } while (numConductores <= 0 || numConductores > MAX_CONDUCTORES);

    
    string nombres[MAX_CONDUCTORES];
    double totalGanado[MAX_CONDUCTORES];
    double promedioKm[MAX_CONDUCTORES];

    
    for (int i = 0; i < numConductores; i++) {
        cout << "conductor " << (i + 1) <<endl;
        cout << "nombre: ";
        cin >> nombres[i];

        int numViajes;
        do {
            cout << "ingrese el número de viajes (máx. " << MAX_VIAJES << "): ";
            cin >> numViajes;
            if (numViajes <= 0 || numViajes > MAX_VIAJES) {
                cout << "error cantidad de viajes inválida"<<endl;
            }
        } while (numViajes <= 0 || numViajes > MAX_VIAJES);

        double distancias[MAX_VIAJES];
        double costos[MAX_VIAJES];

        // Datos por viaje
        for (int j = 0; j < numViajes; j++) {
            cout << "Viaje " << (j + 1) <<endl;
            distancias[j] = validarDato("Distancia (km): ");
            costos[j] = validarDato("Costo por km: ");
        }

        // Calcular total ganado y promedio de distancia
        totalGanado[i] = calcularTotal(distancias, costos, numViajes);
        promedioKm[i] = promedioDistancia(distancias, numViajes);
    }

    cout << " RESULTADOS"<<endl;
    cout << "Nombre\t\tTotal Ganado\tPromedio Distancia"<<endl;


    double mayorIngreso = 0;
    string conductorMayor;

    for (int i = 0; i < numConductores; i++) {
        cout << nombres[i] << "\t\t$" << totalGanado[i]
             << "\t\t" << promedioKm[i] << " km\n";

        if (totalGanado[i] > mayorIngreso) {
            mayorIngreso = totalGanado[i];
            conductorMayor = nombres[i];
        }
    }

    cout << "El conductor con mayor ingreso es: " << conductorMayor<<endl;
         << " con un total de $" << mayorIngreso << endl;

    return 0;
}
