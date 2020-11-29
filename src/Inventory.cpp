#include "../Headers/Inventory.h"

void Inventory::AddBook(Book book)
{
    Inventory::Books.push_back(book);
}