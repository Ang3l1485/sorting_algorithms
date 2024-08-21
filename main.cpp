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


File generator;
File generator2;

void charge_data(File &generate, const std::string& file) {
    generate.read_from_file(file);
}

void measure_performance_title(LinkedList& list) {
    {
        auto start = std::chrono::high_resolution_clock::now();
        list.bubble_sort_title();
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "\nBubble sort by Title: " << duration << " ms" << std::endl;
    }

    {
        auto start = std::chrono::high_resolution_clock::now();
        list.merge_sort(BY_TITLE);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "\nMerge sort by Title: " << duration << " ms" << std::endl;
    }

    {
        auto start = std::chrono::high_resolution_clock::now();
        list.quick_sort_title();
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "\nQuick Sort by Title: " << duration << " ms" << std::endl;
    }
}

void measure_performance_isbn(LinkedList& list) {
    {
        auto start = std::chrono::high_resolution_clock::now();
        list.bubble_sort_isbn();
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "\nBubble sort by ISBN: " << duration << " ms" << std::endl;
    }

    {
        auto start = std::chrono::high_resolution_clock::now();
        list.merge_sort(BY_ISBN);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "\nMerge sort by ISBN: " << duration << " ms" << std::endl;
    }

    {
        auto start = std::chrono::high_resolution_clock::now();
        list.quick_sort_isbn();
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "\nQuick Sort by ISBN: " << duration << " ms" << std::endl;
    }
}

void measure_performance_copies(LinkedList& list) {
    {
        auto start = std::chrono::high_resolution_clock::now();
        list.bubble_sort_copies();
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "\nBubble sort by Copies: " << duration << " ms" << std::endl;
    }

    {
        auto start = std::chrono::high_resolution_clock::now();
        list.merge_sort(BY_COPIES);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "\nMerge sort by Copies: " << duration << " ms" << std::endl;
    }

    {
        auto start = std::chrono::high_resolution_clock::now();
        list.quick_sort_copies();
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "\nQuick Sort by Copies: " << duration << " ms" << std::endl;
    }
}


int main() {
    setupConsole();

    charge_data(generator, "book_titles.txt");
    charge_data(generator2, "authors.txt");

    LinkedList list;

    for (int i = 0; i < 250000; i++) {
        list.add(Book(generator.get_random_item(),generator2.get_random_item(),generator.generate_random_integer(10000000,99999999),generator.random_date(1600,2024), generator.generate_random_integer(0,500)));
    }

    measure_performance_title(list);
    measure_performance_copies(list);
    
    return 0;
}