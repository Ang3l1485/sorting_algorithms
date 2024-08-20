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

void LinkedList::quick_sort_title() {
    head = quick_sort_recursive_title(head, getLast(head));
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