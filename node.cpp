#include "node.h"

// Implementación del constructor de la clase Nodo
Node::Node(const Book& data) : data(data), next(nullptr) {}