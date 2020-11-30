#include "../Headers/Inventory.h"
#include <vector>
#include<bits/stdc++.h> 

void Inventory::AddBook(Book book)
{
    Inventory::Books.push_back(book);
}

Book Inventory::FindBookByTitle(std::string title)
{
    if (std::find(Inventory::Books.begin(), Inventory::Books.end(), Book(0, title, "")) != Inventory::Books.end())
    {

    }

    return Book(1, "", "");
}