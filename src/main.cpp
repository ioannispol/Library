#include <iostream>
#include <string>
#include "../Headers/Book.h"
#include "../Headers/Inventory.h"

void menu_selection();

Inventory _inventory;

int main()
{
    while(true){

        int input;
        menu_selection();
        std::cin >> input;
        std::cin.ignore();
        switch (input)
        {
        case 0:
            std::cout << "Thank you. Goodbye!" << std::endl;
            return 0;
        case 1:
        {   
            std::cout << "Enter Title: ";
            std::string title;
            std::getline(std::cin, title);

            std::cout << "Enter Author: ";
            std::string author;
            std::getline(std::cin, author);

            int id = _inventory.Books.size() + 1;

            Book newBook(id, title, author);
            //Book myBook(1, "Hello", "World");


            _inventory.AddBook(newBook);
            break;
        }
        case 2:
        {
                if (_inventory.Books.size() == 0){
                    std::cout << "The Books List is empty! Please add a book first." << std::endl; 
                } else {
                    std::cout << "\nID\tTitle\tAuthor" << std::endl;
                    for (int i = 0; i < _inventory.Books.size(); i++) {
                        std::cout << _inventory.Books[i].Id << "\t" << _inventory.Books[i].Title << "\t" << _inventory.Books[i].Author << std::endl;
                }
            }
        }
            break;
        case 3:
        {
            std::cout << "Enter a book title to checkout: ";
            std::string title;
            std::getline(std::cin, title);

            int foundBookIndex = _inventory.FindBookByTitle(title);
            
            if (foundBookIndex >= 0 ){
                
                Book* foundBook = &_inventory.Books[foundBookIndex];

                if (foundBook -> CheckedOut)
                {   
                    std::cout << "Book already checked out!" << std::endl;
                    break;
                }
                _inventory.CheckOutBook(foundBook);
                std::cout << "Book checked out!" << std::endl;
            }else{
                std::cout << "Book not found!" << std::endl;
            }
            break;
        }
        case 4:
            {
            std::cout << "Enter a book title to check in: ";
            std::string title;
            std::getline(std::cin, title);

            int foundBookIndex = _inventory.FindBookByTitle(title);

            if (foundBookIndex >= 0){

                Book* foundBook = &_inventory.Books[foundBookIndex];

                if (!foundBook -> CheckedOut)
                {   
                    std::cout << "Book already checked in!" << std::endl;
                    break;
                }
                _inventory.CheckOutBook(foundBook);
                std::cout << "Book checked in!" << std::endl;
            }else{
                std::cout << "Book not found!" << std::endl;
            }
            break;
        }
        case 5:
        {   
            std::cout << "Enter Title: ";
            std::string title;
            std::getline(std::cin, title);

            _inventory.RemoveBook(title);
            break;
        }
        default:
            std::cout << "Invalid input!\n";
            break;
        }
        
    }

}

/***********************************************************************
 ********************** Menu display function **************************
 **********************************************************************/
void menu_selection() {

        std::cout << "Choose and option: " << std::endl;
        std::cout << "1. Add Book: " << std::endl;
        std::cout << "2. List all books: " << std::endl;
        std::cout << "3. Check out book: " << std::endl;
        std::cout << "4. Check in book: " << std::endl;
        std::cout << "5. Remove book from library: " << std::endl;

        std::cout << "0. Exit: " << std::endl;
}