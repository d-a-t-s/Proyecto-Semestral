#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>
#include <functional>
#include "load_file.h"

using namespace std;

int main(int argc, char* argv[]){

    //Verificacion del numero de agumentos, queremos [nombre_ejecutable, nombre_del_archivo, patron_a_buscar]
    if(argc < 3 || argc > 3){
        cerr << "Uso: " << argv[0] << " <nombre_del_archivo> <patron_a_buscar>" << endl;
        return 1;
    }

    //Dado que se debe probar el algoritmo con varios patrones lo que  se hara es crear una funcion "boyer moore" que retorne el tiempo que demoro la ejecucion del algoritmo dado un patron dado
    //Luego como la funcion recibe un patron podemos guardar cada tiempo de ejecucion en un vector y poder sacar la media para un total de 100 200 300 ... patrones de manera que se pueden probar varios
    //patrones utilizando este mismo codigo, de esta forma en un main ejecutando el algoritmo tantas veces como patrones tengamos podemos probar el algoritmo con la cantidad de patrones que queramos

    //Guardado del nombre del archivo y del patron a buscar
    string file_name = argv[1];
    string pattern = argv[2];

    //Carga del archivo
    string corpus = load_file(file_name);

    //Ejecucion del algoritmo de Boyer-Moore

    //Preparacion de la funcion de busqueda
    auto boyer_moore = boyer_moore_searcher(pattern.begin(), pattern.end());

    //Busqueda del patron en el corpus
    auto it = search(corpus.begin(), corpus.end(), boyer_moore);

    //Verificacion de si se encontro el patron
    if(it == corpus.end()){
        cout << "No se encontraron ocurrencias en el archivo" << endl;
    }else{
        cout << "El patron se encuentra en la posicion: " << it - corpus.begin() << endl;
    }

    //Imprimimos el trozo del archivo donde se encuentra el patron
    for(int i = 0; i < pattern.size() + 10; i++){
        cout << *(it + i);
    }
    cout << endl;
    return 0;
}