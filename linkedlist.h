#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h" // Include the node class declaration

// Creation of the LinkedList class
class LinkedList {
private:
    Node* head; // Puntero al primer Node de la lista ligada

    Node* quick_sort_recursive_title(Node* low, Node* high);

    Node* quick_sort_recursive_author(Node* low, Node* high);

    Node* quick_sort_recursive_year(Node* low, Node* high);

    Node* quick_sort_recursive_isbn(Node* low, Node* high);

    Node* quick_sort_recursive_copies(Node* low, Node* high);

    Node* split_quick_sort_title(Node* low, Node* high, Node** newLow, Node** newHigh);

    Node* split_quick_sort_author(Node* low, Node* high, Node** newLow, Node** newHigh);

    Node* split_quick_sort_year(Node* low, Node* high, Node** newLow, Node** newHigh);

    Node* split_quick_sort_isbn(Node* low, Node* high, Node** newLow, Node** newHigh);

    Node* split_quick_sort_copies(Node* low, Node* high, Node** newLow, Node** newHigh);

    Node* getLast(Node* head);

public:
    // Constructor que inicializa la lista vacía
    LinkedList();

    // Destructor que libera la memoria de todos los Nodes
    ~LinkedList();

    // Método para agregar un Node al final de la lista
    void add(const Book& book);

    // Método para imprimir todos los Nodes de la lista
    void print() const;
    
    void quick_sort_title();

    void quick_sort_author();

    void quick_sort_year();

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

    void quick_sort_isbn();

    void quick_sort_copies();

    void swap(Node* node1, Node* node2);
};

#endif // LINKEDLIST_H
