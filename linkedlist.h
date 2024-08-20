#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h" // Include the node class declaration

enum SortCriterion {
    BY_ISBN,
    BY_YEAR,
    BY_COPIES,
    BY_AUTHOR,
    BY_TITLE
};
// Creation of the LinkedList class
class LinkedList {
    
private:
    Node* head; // Puntero al primer Node de la lista ligada

    // Método auxiliar para dividir la lista en dos mitades
    Node* split(Node* head);

    // Método auxiliar para fusionar dos listas ordenadas
    Node* merge(Node* left, Node* right, SortCriterion criterion);

    // Método auxiliar para realizar el Merge Sort de manera recursiva
    Node* merge_sort_recursive(Node* head, SortCriterion criterion);

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
    void bubble_sort();

    // Método para ordenar la lista usando el método de Merge Sort
    void merge_sort(SortCriterion criterion);
    
};

#endif // LINKEDLIST_H
