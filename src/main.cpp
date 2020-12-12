#include <iostream>
#include <string>
#include "../Headers/Book.h"
#include "../Headers/Inventory.h"

/******** Function Declarations********/
void menu_selection();
void AddNewBook();
void ListAllBooks();
void CheckInOrOutBooks(bool checkIn);
void RemoveBook();
void DisplayCheckedOutBooks();

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
            AddNewBook();
            break;
        case 2:
            ListAllBooks();  
            break;
        case 3:
            CheckInOrOutBooks(false);
            break;
        case 4:
            CheckInOrOutBooks(true);
            break;
        case 5:
            RemoveBook();
            break;
        case 6:
            DisplayCheckedOutBooks();
            break;
        default:
            std::cout << "Invalid input!\n";
            break;
        }
        
    }

}

/***********************************************************************
 ********************** Menu display function **************************
 **********************************************************************/
void menu_selection() 
{

        std::cout << "Choose and option: " << std::endl;
        std::cout << "1. Add Book: " << std::endl;
        std::cout << "2. List all books: " << std::endl;
        std::cout << "3. Check out book: " << std::endl;
        std::cout << "4. Check in book: " << std::endl;
        std::cout << "5. Remove book from library: " << std::endl;
        std::cout << "6. List all checked out books: " << std::endl;
        

        std::cout << "0. Exit: " << std::endl;
}

/***********************************************************************
 ********************** AddNewBook function ****************************
 **********************************************************************/
void AddNewBook()
{
    std::cout << "Enter Title: ";
            std::string title;
            std::getline(std::cin, title);

            std::cout << "Enter Author: ";
            std::string author;
            std::getline(std::cin, author);

            Book newBook(title, author);
            //Book myBook(1, "Hello", "World");


            _inventory.AddBook(newBook);
}

/***********************************************************************
 ********************** ListAllBooks function **************************
 **********************************************************************/
void ListAllBooks()
{
    if (_inventory.NumberOfBooks() == 0){
                    std::cout << "The Books List is empty! Please add a book first." << std::endl; 
                } else {
                    std::cout << "\nID\tTitle\tAuthor" << std::endl;
                    for (int i = 0; i < _inventory.NumberOfBooks(); i++) {
                        std::cout << _inventory.GetBookByIndex(i) -> Id << "\t" <<_inventory.GetBookByIndex(i) -> Title << "\t" << _inventory.GetBookByIndex(i) -> Author << std::endl;
                    }
                }
}

/***********************************************************************
 ********************** CheckInOrOutBooks function *********************
 **********************************************************************/
void CheckInOrOutBooks(bool checkOut)
{
    std::string InOrOut;
    if (checkOut){
        InOrOut = "out";
    }
    else{
        InOrOut = "in";
    }
    std::cout << "Enter a book title to check" + InOrOut + ": ";
            std::string title;
            std::getline(std::cin, title);

            int foundBookIndex = _inventory.FindBookByTitle(title);
            
            if (foundBookIndex >= 0 ){
                
                Book* foundBook = _inventory.GetBookByIndex(foundBookIndex);

                // if checkedOut == false then we're checke in
                // if checkedPut == true then we're checked out

                if (foundBook -> CheckedOut == checkOut)
                {   
                    std::cout << "Book already checked" + InOrOut + "!" << std::endl;
                    return;
                }
                if (checkOut){
                    _inventory.CheckOutBook(foundBook);
                }
                else{
                    _inventory.CheckInBook(foundBook);
                }
                std::cout << "Book checked " + InOrOut + "!" << std::endl;
            }else{
                std::cout << "Book not found!" << std::endl;
            }
}

/***********************************************************************
 ********************** RemoveBook function ****************************
 **********************************************************************/
void RemoveBook()
{
    std::cout << "Enter Title: ";
            std::string title;
            std::getline(std::cin, title);

            _inventory.RemoveBook(title);
}

/***********************************************************************
 ********************** DisplayCheckedOutBooks function ****************
 **********************************************************************/
void DisplayCheckedOutBooks()
{

    if (_inventory.NumberOfBooks() == 0){
        std::cout << "The Books List is empty! Please add a book first." << std::endl; 
    } else {
        std::cout << "\nID\tTitle\tAuthor" << std::endl;
        for (int i = 0; i < _inventory.NumberOfBooks(); i++) {
            if (_inventory.GetBookByIndex(i) -> CheckedOut){
                std::cout << _inventory.GetBookByIndex(i) -> Id << "\t" << _inventory.GetBookByIndex(i) -> Title << "\t" << _inventory.GetBookByIndex(i) -> Author << std::endl;
            }
        }
        std::cout << std::endl;
    }
}