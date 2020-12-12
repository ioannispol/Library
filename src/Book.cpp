#include "../Headers/Book.h"

Book::Book(){}

Book::Book(std::string title, std::string author)
{
    // initialize the input parameters
    Book::Title = title;
    Book::Author = author;
    Book::CheckedOut = false;
}