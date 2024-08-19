#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

// Declaración de la clase Book
class Book {
    private:
        std::string title;
        std::string author;
        int isbn;
        int year;
        int number_copies;

    public:
        //Constructor de la clase Book
        Book(const std::string& title, const std::string& author, int isbn, int year, int number_copies);

        //Métodos para obtener los valores de los atributos
        std::string getTitle() const;
        std::string getAuthor() const;
        int getIsbn() const;
        int getYear() const;
        int getNumberCopies() const;

        //Sobrecarga del operador << para permitir la salida de objetos Book a un flujo de salida
        friend std::ostream& operator<<(std::ostream& os, const Book& book);

        //Sobrecarga de los operadores de comparación
        bool operator>(const Book& other) const;
        bool operator<(const Book& other) const;
        bool operator==(const Book& other) const;
};
#endif; // BOOK_H