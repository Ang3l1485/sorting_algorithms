#include <iostream>
#include <chrono> // Incluir la biblioteca <chrono>
#include "file.h"
#include "book.h"
#include "linkedlist.h"

#ifdef _WIN32
#include <windows.h>
#endif

void setupConsole() {
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif
}

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
    setupConsole();

    charge_data(generator, "book_titles.txt");
    charge_data(generator2, "authors.txt");

    LinkedList list;
    for (int i = 0; i < 10; i++) {
        list.add(Book(generator.get_random_item(),generator2.get_random_item(),generator.generate_random_integer(10000000,99999999),generator.random_date(1600,2024), generator.generate_random_integer(0,500)));
    }

    std::cout << "\nList before sort:" << std::endl;
    list.print();

    std::cout << "\nList after sort by title:" << std::endl;
    list.quick_sort_title();
    list.print();

    std::cout << "\nList after sort by author:" << std::endl;
    list.quick_sort_author();
    list.print();

    std::cout << "\nList after sort by year:" << std::endl;
    list.quick_sort_year();
    list.print();

    std::cout << "\nList after sort by isbn:" << std::endl;
    list.quick_sort_isbn();
    list.print();

    std::cout << "\nList after sort by number of copies:" << std::endl;
    list.quick_sort_copies();
    list.print();
    
    return 0;
}