#include "../Headers/Book.h"

Book::Book(int id, std::string title, std::string author)
{
    // initialize the input parameters
    Book::Id = id;
    Book::Title = title;
    Book::Author = author;
}