#include "../Headers/Inventory.h"
#include <vector>
#include<bits/stdc++.h> 

void Inventory::AddBook(Book book)
{
    Inventory::Books.push_back(book);
}

int Inventory::FindBookByTitle(std::string title)
{

    std::vector<Book>::iterator it = std::find(Inventory::Books.begin(), Inventory::Books.end(), Book(0, title, ""));
    if (it == Inventory::Books.end())
    {
        return -1;
    }

    int index = it - Inventory::Books.begin();
    
    return index;
}

void Inventory::CheckOutBook(Book* book)
{
    book -> CheckedOut = true;      //dereference the pointer
}

void Inventory::CheckInBook(Book* book)
{
    book -> CheckedOut = false;
}