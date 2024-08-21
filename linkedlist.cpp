#include "linkedlist.h"
#include <iostream>

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
        case BY_AUTHOR:
            comparison = left->data.getAuthor() < right->data.getAuthor();
            break;
        case BY_TITLE:
            comparison = left->data.getTitle() < right->data.getTitle();

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

void LinkedList::quick_sort_title() {
    head = quick_sort_recursive_title(head, getLast(head));
}

// Método para ordenar la lista por año usando el método de burbuja
void LinkedList::bubble_sort_year() {
    if (head == nullptr) return;
}

void LinkedList::quick_sort_author() {
    head = quick_sort_recursive_author(head, getLast(head));
}

void LinkedList::quick_sort_year() {
    head = quick_sort_recursive_year(head, getLast(head));
}

void LinkedList::quick_sort_isbn() {
    head = quick_sort_recursive_isbn(head, getLast(head));
}

void LinkedList::quick_sort_copies() {
    head = quick_sort_recursive_copies(head, getLast(head));
}

Node* LinkedList::quick_sort_recursive_title(Node* low, Node* high) {
    if(low == nullptr || low == high || low == high->next ) return low; 

    Node* newLow = nullptr;
    Node* newHigh = nullptr;

    Node* pivot = split_quick_sort_title(low, high, &newLow, &newHigh);

    if (newLow != pivot) {
        Node* temp = newLow;
        while (temp->next != pivot)
        temp = temp->next;
        temp->next = nullptr;

        newLow = quick_sort_recursive_title(newLow, temp);

        temp = getLast(newLow);
        temp->next = pivot;
    }

    pivot->next = quick_sort_recursive_title(pivot->next, newHigh);    
    
    return newLow; 
}

Node* LinkedList::quick_sort_recursive_author(Node* low, Node* high) {
    if(low == nullptr || low == high || low == high->next ) return low; 

    Node* newLow = nullptr;
    Node* newHigh = nullptr;

    Node* pivot = split_quick_sort_author(low, high, &newLow, &newHigh);

    if (newLow != pivot) {
        Node* temp = newLow;
        while (temp->next != pivot)
        temp = temp->next;
        temp->next = nullptr;

        newLow = quick_sort_recursive_author(newLow, temp);

        temp = getLast(newLow);
        temp->next = pivot;
    }

    pivot->next = quick_sort_recursive_author(pivot->next, newHigh);    
    
    return newLow; 
}

Node* LinkedList::quick_sort_recursive_year(Node* low, Node* high) {
    if(low == nullptr || low == high || low == high->next ) return low; 

    Node* newLow = nullptr;
    Node* newHigh = nullptr;

    Node* pivot = split_quick_sort_year(low, high, &newLow, &newHigh);

    if (newLow != pivot) {
        Node* temp = newLow;
        while (temp->next != pivot)
        temp = temp->next;
        temp->next = nullptr;

        newLow = quick_sort_recursive_year(newLow, temp);

        temp = getLast(newLow);
        temp->next = pivot;
    }

    pivot->next = quick_sort_recursive_year(pivot->next, newHigh);    
    
    return newLow; 
}

Node* LinkedList::quick_sort_recursive_isbn(Node* low, Node* high) {
    if(low == nullptr || low == high || low == high->next ) return low; 

    Node* newLow = nullptr;
    Node* newHigh = nullptr;

    Node* pivot = split_quick_sort_isbn(low, high, &newLow, &newHigh);

    if (newLow != pivot) {
        Node* temp = newLow;
        while (temp->next != pivot)
        temp = temp->next;
        temp->next = nullptr;

        newLow = quick_sort_recursive_isbn(newLow, temp);

        temp = getLast(newLow);
        temp->next = pivot;
    }

    pivot->next = quick_sort_recursive_isbn(pivot->next, newHigh);    
    
    return newLow; 
}

Node* LinkedList::quick_sort_recursive_copies(Node* low, Node* high) {
    if(low == nullptr || low == high || low == high->next ) return low; 

    Node* newLow = nullptr;
    Node* newHigh = nullptr;

    Node* pivot = split_quick_sort_copies(low, high, &newLow, &newHigh);

    if (newLow != pivot) {
        Node* temp = newLow;
        while (temp->next != pivot)
        temp = temp->next;
        temp->next = nullptr;

        newLow = quick_sort_recursive_copies(newLow, temp);

        temp = getLast(newLow);
        temp->next = pivot;
    }

    pivot->next = quick_sort_recursive_copies(pivot->next, newHigh);    
    
    return newLow; 
}

Node* LinkedList::split_quick_sort_title(Node* low, Node* high, Node** newLow, Node** newHigh) {
    Node* pivot = high;
    Node* prev = nullptr;
    Node* current = low;
    Node* tail = pivot;

    while (current != pivot) {
        if (current->data.getTitle() < pivot->data.getTitle()) {
            if ((*newLow) == nullptr) {
                (*newLow) = current;
            }
            prev = current;
            current = current->next;
        } else {
            if (prev != nullptr) {
                prev->next = current->next;
            }
            Node* temp = current->next;
            current->next = nullptr;
            tail->next = current;
            tail = current;
            current = temp;
        }
    }

    if ((*newLow) == nullptr) {
        (*newLow) = pivot;
    }

    (*newHigh) = tail;

    return pivot;
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

Node* LinkedList::split_quick_sort_author(Node* low, Node* high, Node** newLow, Node** newHigh) {
    Node* pivot = high;
    Node* prev = nullptr;
    Node* current = low;
    Node* tail = pivot;

    while (current != pivot) {
        if (current->data.getAuthor() < pivot->data.getAuthor()) {
            if ((*newLow) == nullptr) {
                (*newLow) = current;
            }
            prev = current;
            current = current->next;
        } else {
            if (prev != nullptr) {
                prev->next = current->next;
            }
            Node* temp = current->next;
            current->next = nullptr;
            tail->next = current;
            tail = current;
            current = temp;
        }
    }

    if ((*newLow) == nullptr) {
        (*newLow) = pivot;
    }

    (*newHigh) = tail;

    return pivot;
}


Node* LinkedList::split_quick_sort_year(Node* low, Node* high, Node** newLow, Node** newHigh) {
    Node* pivot = high;
    Node* prev = nullptr;
    Node* current = low;
    Node* tail = pivot;

    while (current != pivot) {
        if (current->data.getYear() < pivot->data.getYear()) {
            if ((*newLow) == nullptr) {
                (*newLow) = current;
            }
            prev = current;
            current = current->next;
        } else {
            if (prev != nullptr) {
                prev->next = current->next;
            }
            Node* temp = current->next;
            current->next = nullptr;
            tail->next = current;
            tail = current;
            current = temp;
        }
    }

    if ((*newLow) == nullptr) {
        (*newLow) = pivot;
    }

    (*newHigh) = tail;

    return pivot;
}

Node* LinkedList::split_quick_sort_isbn(Node* low, Node* high, Node** newLow, Node** newHigh) {
    Node* pivot = high;
    Node* prev = nullptr;
    Node* current = low;
    Node* tail = pivot;

    while (current != pivot) {
        if (current->data.getIsbn() < pivot->data.getIsbn()) {
            if ((*newLow) == nullptr) {
                (*newLow) = current;
            }
            prev = current;
            current = current->next;
        } else {
            if (prev != nullptr) {
                prev->next = current->next;
            }
            Node* temp = current->next;
            current->next = nullptr;
            tail->next = current;
            tail = current;
            current = temp;
        }
    }

    if ((*newLow) == nullptr) {
        (*newLow) = pivot;
    }

    (*newHigh) = tail;

    return pivot;
}

Node* LinkedList::split_quick_sort_copies(Node* low, Node* high, Node** newLow, Node** newHigh) {
    Node* pivot = high;
    Node* prev = nullptr;
    Node* current = low;
    Node* tail = pivot;

    while (current != pivot) {
        if (current->data.getNumberCopies() < pivot->data.getNumberCopies()) {
            if ((*newLow) == nullptr) {
                (*newLow) = current;
            }
            prev = current;
            current = current->next;
        } else {
            if (prev != nullptr) {
                prev->next = current->next;
            }
            Node* temp = current->next;
            current->next = nullptr;
            tail->next = current;
            tail = current;
            current = temp;
        }
    }

    if ((*newLow) == nullptr) {
        (*newLow) = pivot;
    }

    (*newHigh) = tail;

    return pivot;
}

Node* LinkedList::getLast(Node* head) {
    while (head != nullptr && head->next != nullptr) {
        head = head->next; 
    }
    return head; // Retornar el último nodo
}
