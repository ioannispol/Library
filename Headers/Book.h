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

        Book();
        Book(std::string title, std::string author);

        bool operator == (const Book &book) const
        {
            if (Title.compare(book.Title) == 0)
                return true;
            else
                return false;
        }
};

#endif // BOOK_H
