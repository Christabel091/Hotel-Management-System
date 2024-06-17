#include<iostream>
#include<vector>
#include "../header/room.h"
#include "../header/reservation.h"
int main() {
    int want;

    std::cout << "Thank you for visiting your hotel";

    do {
        // Display menu options to the user
        std::cout << "\nWhat would you like to do today?";
        std::cout << "\n1. Book a room";
        std::cout << "\n2. Make a reservation";
        std::cout << "\n3. Cancel a reservation";
        std::cout << "\n4. Release a room";
        std::cout << "\n5. Quit";
        std::cout << "\nEnter your choice: ";
        
        // Get user input
        std::cin >> want;

        // Handle invalid input
        while (std::cin.fail() || want < 1 || want > 5) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(INT_MAX, '\n'); // Ignore invalid input
            std::cout << "Invalid choice. Please enter a number between 1 and 5: ";
            std::cin >> want;
        }

        // Switch statement based on user choice
        switch (want) {
            case 1:
                //book a room
                break;
            case 2:
                int phone;
                std::string name;
                std::cout << "What is your namr:";
                std::cin >> name;
                std::cout << "What is our contact number";
                std::cin >> phone;
                Reservation reservation(name, phone);
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                std::cout << "Quitting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }

    } while (want != 5);  // Continue until user selects '5' to quit

    return 0;
}
