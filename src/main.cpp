#include <iostream>
#include "../Headers/Book.h"


int main()
{
    while(true){

        std::cout << "Choose and option: " << std::endl;
        std::cout << "1. Add Book: " << std::endl;
        std::cout << "2. List all books: " << std::endl;
        std::cout << "3. Check out book: " << std::endl;
        std::cout << "4. Check in book : " << std::endl;

        std::cout << "0. Exit : " << std::endl;

        int input;
        std::cin >> input;

        switch (input)
        {
        case 0:
            std::cout << "Thank you. Goodbye!" << std::endl;
            return 0;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        
        default:
            std::cout << "Invalid input!\n";
            break;
        }
        
    }

}