#include <iostream>
#include <chrono> // Incluir la biblioteca <chrono>
#include "file.h"
#include "book.h"
#include "linkedlist.h"

#ifdef _WIN32
#include <windows.h>
#endif

// para compilar el codigo: g++ book.cpp file.cpp linkedlist.cpp main.cpp node.cpp -o demo

// ./demo

File generator;
File generator2;

void charge_data(File &generate, const std::string& file) {
    generate.read_from_file(file);
}

std::string simulate_full_name() {
    std::string full_name = generator.get_random_item() + " " +
                            generator2.get_random_item() + " " +
                            generator2.get_random_item();
    return full_name;
}

int main() {
    charge_data(generator, "book_titles.txt");
    charge_data(generator2, "authors.txt");

    LinkedList list;
    for (int i = 0; i < 10; i++) {
        list.add(Book(generator.get_random_item(),generator2.get_random_item(),generator.generate_random_integer(10000000,99999999),generator.random_date(1600,2024), generator.generate_random_integer(0,500)));
    }

    std::cout << "List before sort:" << std::endl;
    list.print();

    // Medir el tiempo de ordenación
    auto start = std::chrono::high_resolution_clock::now(); // Captura el tiempo de inicio
      //lista.ordenarBurbuja(); // Llama al método de ordenación
      list.bubble_sort();
    auto end = std::chrono::high_resolution_clock::now(); // Captura el tiempo de fin
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); // Calcula la duración en milisegundos

    std::cout << "\nList after sort:" << std::endl;
    list.print();
    std::cout << "Sorting time: " << duration << " ms" << std::endl; // Imprime la duración
    
    return 0;
}
