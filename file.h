#ifndef FILE_H
#define FILE_H

#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>  // Para std::rand y std::srand
#include <ctime>    // Para std::time
#include <iomanip>  // Para std::setw y std::setfill

class File {
private:
    std::vector<std::string> items;

public:
    // Constructor
    File();

    // Método para leer los items desde un archivo
    void read_from_file(const std::string& file_name);

    // Método para imprimir los items
    void print_items() const;

    // Método para retornar un item aleatorio
    std::string get_random_item() const;

    // Método para generar una fecha aleatoria en formato dia/mes/año
    std::string random_date(int min_year, int max_year) const;

    // Método para generar un número entero aleatorio en un rango
    int generate_random_integer(int min, int max) const;

    // Método para generar un número flotante aleatorio en un rango
    float generate_random_float(float min, float max) const;
};

#endif // FILE_H
