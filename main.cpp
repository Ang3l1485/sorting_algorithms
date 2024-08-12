#include <iostream>
#include <chrono> // Incluir la biblioteca <chrono>
#include "file.h"
#include "book.h"
#include "linkedlist.h"

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
    charge_data(generator, "nombres.txt");
    charge_data(generator2, "apellidos.txt");

    LinkedList list;
    for (int i = 0; i < 100000; i++) {
        list.add(Book(simulate_full_name(), 
                              generator.generate_random_integer(12, 89),
                              generator.random_date(1972, 2023)));
    }

    std::cout << "List before sort:" << std::endl;
    list.print();

    // Medir el tiempo de ordenación
    auto start = std::chrono::high_resolution_clock::now(); // Captura el tiempo de inicio
      //lista.ordenarBurbuja(); // Llama al método de ordenación
      list.merge_sort();
    auto end = std::chrono::high_resolution_clock::now(); // Captura el tiempo de fin
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); // Calcula la duración en milisegundos

    std::cout << "List after sort:" << std::endl;
    list.print();
    std::cout << "Sorting time: " << duration << " ms" << std::endl; // Imprime la duración
    
    return 0;
}
