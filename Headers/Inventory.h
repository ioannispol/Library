#ifndef INVENTORY_H
#define INVENTORY_H

#include "Book.h"
#include <iostream>
#include <vector>


class Inventory
{
    public:
        std::vector<Book> Books;

        void AddBook(Book book);
        void RemoveBook(std::string title);
        int FindBookByTitle(std::string title);
        void CheckOutBook(Book* book);
        void CheckInBook(Book* book);

};



#endif