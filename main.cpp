#include <iostream>
#include <random>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

// Función para calcular la distancia entre dos puntos

double calcularDistancia(const vector<double>& punto1, const vector<double>& punto2) {
    double distancia = 0.0;
    
    for (int i = 0; i < punto1.size(); i++) {
        distancia += pow(punto1[i] - punto2[i], 2);
    }
    return sqrt(distancia);
}

int main() {

    
    random_device rd;  // Genera un dispositivo de números aleatorios
    mt19937 gen(rd());  // Inicializa el generador de números aleatorios con el dispositivo
    uniform_real_distribution<double> dis(0.0, 1.0);  // Distribución uniforme entre 0.0 y 1.0

    int dimensiones[] = {10, 50, 100, 500, 1000, 2000, 5000};  
    

    for (int d : dimensiones) {
        vector<vector<double>> puntos;

        // Generar 100 puntos aleatorios en la dimensión actual
        for (int i = 0; i < 100; i++) {
            
            vector<double> punto;
            for (int j = 0; j < d; j++) {
                punto.push_back(dis(gen));  // Generar coordenadas aleatorias y agregarlas al punto
            }
            puntos.push_back(punto);  // Agregar el punto al vector de puntos
        }

        int numDistancias = (100 * (100 - 1)) / 2; // Número de distancias a calcular

        ofstream archivo("distancias_" + to_string(d) + ".txt");  // Crear un archivo de salida
        
        if (archivo.is_open()) {

            // Calcular y guardar las distancias entre todos los pares de puntos
            for (int i = 0; i < puntos.size(); i++) {
                
                for (int j = i + 1; j < puntos.size(); j++) {
                    double distancia = calcularDistancia(puntos[i], puntos[j]);
                    
                    archivo << distancia << endl;  // Guardar la distancia en el archivo
                }
            }
            archivo.close();  
        } else {
            
            cout << "No se puede abrir el archivo" << endl;
        }
    }

    return 0;
}
