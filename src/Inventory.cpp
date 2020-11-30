#include "../Headers/Inventory.h"
#include <vector>

void Inventory::AddBook(Book book)
{
    Inventory::Books.push_back(book);
}

Book Inventory::FindBookByTitle(srd::string title)
{
    if (std::find(Inventory::Books.begin(), Inventory::Books.end(), Book(0, title, "")) != Inventory::Books.end())
    {
        
    }

    return Book(1, "", "");
}