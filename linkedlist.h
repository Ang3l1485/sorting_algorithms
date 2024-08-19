#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h" // Include the node class declaration

// Creation of the LinkedList class
class LinkedList {
private:
    Node* head; // Puntero al primer Node de la lista ligada

    // Método auxiliar para dividir la lista en dos mitades
    Node* split(Node* head);

    // Método auxiliar para fusionar dos listas ordenadas
    Node* merge(Node* left, Node* right);

    // Método auxiliar para realizar el Merge Sort de manera recursiva
    Node* merge_sort_recursive(Node* head);

public:
    // Constructor que inicializa la lista vacía
    LinkedList();

    // Destructor que libera la memoria de todos los Nodes
    ~LinkedList();

    // Método para agregar un Node al final de la lista
    void add(const Book& book);

    // Método para imprimir todos los Nodes de la lista
    void print() const;

    // Método para intercambiar dos Nodes si el primero es mayor que el segundo
    void swap(Node* node1, Node* node2);

    // Método para ordenar la lista usando el método de burbuja
    void bubble_sort_year();

    // Metodo para ordenar la lista por isbn usando el metodo de burbuja
    void bubble_sort_isbn();

    //Método para ordenar la lista por número de copias usando el método de burbuja
    void bubble_sort_copies();

    //Método para ordenar la lista por autor usando el método de burbuja
    void bubble_sort_author();

    //Método para ordenar la lista por título usando el método de burbuja
    void bubble_sort_title();

    // Método para ordenar la lista usando el método de Merge Sort
    void merge_sort();
};

#endif // LINKEDLIST_H
