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

// Método para ordenar la lista por año usando el método de burbuja
void LinkedList::bubble_sort_year() {
    if (head == nullptr) return;

    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        while (current->next != nullptr) {
            if (current->data > current->next->data) {
                swap(current, current->next);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

// Metodo para ordenar la lista por isbn usando el metodo de burbuja
void LinkedList::bubble_sort_isbn() {
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

// Método para ordenar la lista por número de copias usando el método de burbuja
void LinkedList::bubble_sort_copies() {
    if (head == nullptr) return;

    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        while (current->next != nullptr) {
            if (current->data.getNumberCopies() > current->next->data.getNumberCopies()) {
                swap(current, current->next);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

// Método para ordenar la lista por autor usando el método de burbuja
void LinkedList::bubble_sort_author() {
    if (head == nullptr) return;

    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        while (current->next != nullptr) {
            if (current->data.getAuthor() > current->next->data.getAuthor()) {
                swap(current, current->next);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

// Método para ordenar la lista por título usando el método de burbuja
void LinkedList::bubble_sort_title() {
    if (head == nullptr) return;

    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        while (current->next != nullptr) {
            if (current->data.getTitle() > current->next->data.getTitle()) {
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
Node* LinkedList::merge(Node* left, Node* right) {
    if (left == nullptr) return right; // Si la lista izquierda está vacía, devolver la lista derecha
    if (right == nullptr) return left; // Si la lista derecha está vacía, devolver la lista izquierda

    if (left->data < right->data) {
        left->next = merge(left->next, right); // Fusionar el resto de la lista izquierda con la lista derecha
        return left;
    } else {
        right->next = merge(left, right->next); // Fusionar la lista izquierda con el resto de la lista derecha
        return right;
    }
}

// Método auxiliar para realizar el Merge Sort de manera recursiva
Node* LinkedList::merge_sort_recursive(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head; // Si la lista está vacía o tiene un solo nodo, ya está ordenada
    }

    Node* half = split(head); // Dividir la lista en dos mitades
    Node* left = merge_sort_recursive(head); // Ordenar la primera mitad
    Node* right = merge_sort_recursive(half); // Ordenar la segunda mitad

    return merge(left, right); // Fusionar las dos mitades ordenadas
}

// Método para ordenar la lista usando el método de Merge Sort
void LinkedList::merge_sort() {
    head = merge_sort_recursive(head); // Ordenar la lista y actualizar la cabeza
}
