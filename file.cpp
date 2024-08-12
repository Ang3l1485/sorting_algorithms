#include "file.h"
#include <iostream>

// Constructor
File::File() {
    // Inicializar el generador de números aleatorios con el tiempo actual
    //std::srand(static_cast<unsigned int>(std::time(0)));
    // Inicializar la semilla para números aleatorios
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

// Método para leer los textos desde un archivo
void File::read_from_file(const std::string& file_name) {
    std::ifstream file(file_name);
    if (file.is_open()) {
        std::string text;
        while (std::getline(file, text)) {
            items.push_back(text);
        }
        file.close();
    } else {
        std::cerr << "Couldn't open the file: " << file_name << std::endl;
    }
}

// Método para imprimir los items
void File::print_items() const {
    int i=1;
    for (const auto& item : items) {
        std::cout << "["<< i << "]: " <<item << std::endl;
        i=i+1;
    }
    std::cout << std::endl;
}

// Método para retornar un item aleatorio
std::string File::get_random_item() const {
    if (items.empty()) {
        return "There is no items in the list.";
    }
    int random_index = std::rand() % items.size();
    return items[random_index];
}

// Método para generar una fecha aleatoria en formato dia/mes/año
std::string File::random_date(int min_year, int max_year) const {
    int year = min_year + std::rand() % (max_year - min_year + 1);
    int month = 1 + std::rand() % 12;
    int day = 1 + std::rand() % 28;  // Simplificación: todos los meses tienen 28 días

    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << day << "/"
       << std::setw(2) << std::setfill('0') << month << "/"
       << year;
    return ss.str();
}

// Método para generar un número entero aleatorio en un rango
int File::generate_random_integer(int min, int max) const {
    return min + std::rand() % (max - min + 1);
}

// Método para generar un número flotante aleatorio en un rango
float File::generate_random_float(float min, float max) const {
    float random = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
    return min + random * (max - min);
}