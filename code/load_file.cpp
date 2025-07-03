#include "load_file.h"

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <string_view>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

string load_file(const string& file_name){

    //Declaracion de la ruta del archivo que se va a cargar
    fs::path directory = fs::path("../datasets/Concatenated") / file_name; //¿Esta bien si se le pasa asi el nombre del archivo considerando que se le esta pasando por referencia a la funcion?

    //Verificacion de que el archivo existe
    ifstream input(directory, ios::in);
    if(!input){
        cerr << "Error: No se puedo abrir el archivo: " << directory << " en load_file.cpp" << endl;
        exit(1);
    }

    //Copia del archivo a un string
    return string(istreambuf_iterator<char>(input), istreambuf_iterator<char>());
}