#include "book.h"

// Constructor de la clase Book
Book::Book(const std::string& title, const std::string& author, int isbn, int year, int number_copies)
    :title(title), author(author), isbn(isbn), year(year), number_copies(number_copies) {}

// Método para obtener el título del libro
std::string Book::getTitle() const {
    return title;
}

// Método para obtener el autor del libro
std::string Book::getAuthor() const {
    return author;
}

// Método para obtener el ISBN del libro
int Book::getIsbn() const {
    return isbn;
}

// Método para obtener el año de publicación del libro
int Book::getYear() const {
    return year;
}

// Método para obtener el número de copias disponibles del libro
int Book::getNumberCopies() const {
    return number_copies;
}

// Sobrecarga del operador << para permitir la salida de objetos Book a un flujo de salida
std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.isbn << ", Year: " << book.year << ", Number of copies: " << book.number_copies;
    return os;
}

// Sobrecarga del operador > para comparar dos objetos Book por año de publicación
bool Book::operator>(const Book& other) const {
    return year > other.year;
}

// Sobrecarga del operador < para comparar dos objetos Book por año de publicación
bool Book::operator<(const Book& other) const {
    return year < other.year;
}

// Sobrecarga del operador == para comparar dos objetos Book por año de publicación
bool Book::operator==(const Book& other) const {
    return year == other.year;
}