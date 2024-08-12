#ifndef NODE_H
#define NODE_H

#include "book.h"

// Declaración de la clase Nodo
class Node {
public:
    Book data;       // Atributo para almacenar los datos del nodo, en este caso una instancia de Persona
    Node* next;    // Puntero al siguiente nodo en la lista ligada

    // Constructor que inicializa el atributo data y establece el puntero siguiente a nullptr
    Node(const Book& data);
};

#endif // NODE_H
