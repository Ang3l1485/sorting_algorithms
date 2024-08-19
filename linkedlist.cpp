#include "linkedlist.h"
#include <iostream>
#include <chrono> // Biblioteca para medir el tiempo de ejecución

// Constructor que inicializa la lista vacía
LinkedList::LinkedList() : head(nullptr) {}

// Destructor que libera la memoria de todos los nodos
LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::add(const Book& book) {
    Node* new_node = new Node(book);
    if (head == nullptr) {
        head = new_node; // Si la lista está vacía, el nuevo nodo se convierte en la cabeza
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next; // Avanzar hasta el último nodo
        }
        current->next = new_node; // Añadir el nuevo nodo al final
    }
}

// Método para imprimir todos los nodos de la lista
void LinkedList::print() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << std::endl; // Imprimir los datos del nodo actual
        current = current->next; // Avanzar al siguiente nodo
    }
}

// Método para intercambiar dos nodos si el primero es mayor que el segundo
void LinkedList::swap(Node* node1, Node* node2) {
    Book temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

// Método para ordenar la lista usando el método de burbuja
void LinkedList::bubble_sort() {
    if (head == nullptr) return;

    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        while (current->next != nullptr) {
            if (current->data.getIsbn() > current->next->data.getIsbn()) {
                swap(current, current->next);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

// Método auxiliar para dividir la lista en dos mitades
Node* LinkedList::split(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr; // La lista está vacía o tiene un solo nodo
    }

    Node* slow = head;
    Node* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next; // Avanzar el puntero lento
        fast = fast->next->next; // Avanzar el puntero rápido
    }

    Node* half = slow->next; // La segunda mitad comienza en el siguiente nodo del puntero lento
    slow->next = nullptr; // Dividir la lista en dos mitades
    return half;
}

// Método auxiliar para fusionar dos listas ordenadas
// Método auxiliar para fusionar dos listas ordenadas según el criterio
Node* LinkedList::merge(Node* left, Node* right, SortCriterion criterion) {
    if (left == nullptr) return right;
    if (right == nullptr) return left;

    bool comparison = false;
    // Comparar los nodos según el criterio de ordenación
    switch (criterion) {
        case BY_ISBN:
            comparison = left->data.getIsbn() < right->data.getIsbn();
            break;
        case BY_YEAR:
            comparison = left->data.getYear() < right->data.getYear(); // Asume que es un string
            break;
        case BY_COPIES:
            comparison = left->data.getNumberCopies() < right->data.getNumberCopies();
            break;
    }

    if (comparison) {
        left->next = merge(left->next, right, criterion);
        return left;
    } else {
        right->next = merge(left, right->next, criterion);
        return right;
    }
}


// Método auxiliar para realizar el Merge Sort de manera recursiva
Node* LinkedList::merge_sort_recursive(Node* head, SortCriterion criterion) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* half = split(head);
    Node* left = merge_sort_recursive(head, criterion);
    Node* right = merge_sort_recursive(half, criterion);

    return merge(left, right, criterion);
}

// Método para ordenar la lista usando el método de Merge Sort
void LinkedList::merge_sort(SortCriterion criterion) {
    head = merge_sort_recursive(head, criterion);
}

