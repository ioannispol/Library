#ifndef BOOK_H
#define BOOK_H
#include <iostream>

class Book
{
    public:
        int Id;
        std::string Title{};
        std::string Author{};
        bool CheckedOut{};

        Book(int id, std::string title, std::string author);

        bool operator == (const Book &book) const
        {
            
        }
};

#endif // BOOK_H
