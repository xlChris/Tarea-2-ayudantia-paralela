//Autor: Cristobal Morales

#include "Matriz.h"
#include <iostream>
using namespace std;
Matriz::Matriz() {
    for (int i = 0; i < LARGO; i++) {
        for (int j = 0; j < LARGO; j++) {
            this->matriz[i][j] = 0;  //matriz por defecto
        }
    }
}

Matriz::Matriz(const std::string& orig) { //limpia cada linea del txt
    try {
        Matriz();
        std::string linea(orig.c_str());
        if (!linea.empty()) {
            linea.erase(std::remove(linea.begin(), linea.end(), '['), linea.end());  //se quita corchete
            linea.erase(std::remove(linea.begin(), linea.end(), ']'), linea.end());
            std::replace(linea.begin(), linea.end(), ';', ' ');
            std::replace(linea.begin(), linea.end(), ':', ' ');

            std::vector<std::string> arreglo;
            std::stringstream ss(linea);
            std::string temp;
            while (ss >> temp) {
                arreglo.push_back(temp);
            }

            for (int i = 0; i < 6; i++) {
                std::string fila = arreglo[i];
                std::replace(fila.begin(), fila.end(), ',', ' ');

                std::vector<std::string> columnas;
                std::stringstream sf(fila);
                std::string tmp;
                while (sf >> tmp) {
                    columnas.push_back(tmp);
                }

                for (int j = 0; j < LARGO; j++) {
                    std::string valor = columnas[j];
                    int numero = atoi(valor.c_str());  //transforma texto a numero
                    this->matriz[i][j] = numero;
                }
            }
        }
    } catch (...) {
        Matriz();
    }
}

Matriz::Matriz(const Matriz& orig) { //Rellena la matriz con los datos limpios
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < LARGO; j++) {
            this->matriz[i][j] = orig.matriz[i][j];
        }
    }
}

Matriz::~Matriz() {
}

void Matriz::sacar_multiplicacion() { //Realiza la multiplicacion de las matrices
    cout << "----------" << endl;
    cout <<  this->matriz[0][0] * this->matriz[3][0] + this->matriz[0][1] * this->matriz[4][0] + this->matriz[0][2] * this->matriz [5][0] << " ";
    cout <<  this->matriz[0][0] * this->matriz[3][1] + this->matriz[0][1] * this->matriz[4][1] + this->matriz[0][2] * this->matriz [5][1] << " ";
    cout <<  this->matriz[0][0] * this->matriz[3][2] + this->matriz[0][1] * this->matriz[4][2] + this->matriz[0][2] * this->matriz [5][2] << endl;
    cout <<  this->matriz[1][0] * this->matriz[3][0] + this->matriz[1][1] * this->matriz[4][0] + this->matriz[1][2] * this->matriz [5][0] << " ";
    cout <<  this->matriz[1][0] * this->matriz[3][1] + this->matriz[1][1] * this->matriz[4][1] + this->matriz[1][2] * this->matriz [5][1] << " ";
    cout <<  this->matriz[1][0] * this->matriz[3][2] + this->matriz[1][1] * this->matriz[4][2] + this->matriz[1][2] * this->matriz [5][2] << endl;
    cout <<  this->matriz[2][0] * this->matriz[3][0] + this->matriz[2][1] * this->matriz[4][0] + this->matriz[2][2] * this->matriz [5][0] << " ";
    cout <<  this->matriz[2][0] * this->matriz[3][1] + this->matriz[2][1] * this->matriz[4][1] + this->matriz[2][2] * this->matriz [5][1] << " ";
    cout <<  this->matriz[2][0] * this->matriz[3][2] + this->matriz[2][1] * this->matriz[4][2] + this->matriz[2][2] * this->matriz [5][2] << endl;
}
