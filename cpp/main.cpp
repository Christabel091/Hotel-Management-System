#include<iostream>
#include<vector>
#include "../header/room.h"
#include "../header/reservation.h"
#include "../header/customer.h"
#include<string>
int main() {
    int want;

    std::cout << "Thank you for visiting your hotel";
    std::cout << "What is your name: ";
    std::string customerName;
    std::cin >> customerName;
    std::cout << "If you dont mind can you provide us with your contact details(phone number) ";
    int number;
    std::cin >> number;
    Customer customer(customerName, number);


    do {
        // Display menu options to the user
        std::cout << "\nWhat would you like to do today?";
        std::cout << "\n1. Book a room";
        std::cout << "\n2. Make a reservation";
        std::cout << "\n3. Cancel a reservation";
        std::cout << "\n4. Release a room";
        std::cout << "\n5. Check in."
        std::cout << "\n6. Quit";
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
        Room room;
        std::vector<Room> rooms;
        // Switch statement based on user choice
        switch (want) {
            case 1:
                std::cout << "Which room do you wish to book? ";
                int rnumber;
                std::cin >> rnumber;
                rooms = room.loadRoom();
                bool booked;
                booked = room.bookRoom(rnumber, rooms);
                if (booked) std::cout << "Room successfully booked. ";
                else std::cout << "room is already booked  You can book another room. or quit";
                break;
            case 2:
                int rooM;
                int date;
                int days;
                std::string name;
                std::cout << "What is your name:";
                std::cin >> name;
                std::cout << "What is the room you want to reserve";
                std::cin >> rooM;
                std::cout << "what date and time do you want to reserve the room? ";
                std::cin >> date;
                std::cout << "How many days do you want the room reserved? ";
                std::cin >> days;
                Reservation reservation(name, rooM, date, days, number);
                std::vector<Reservation> reservations;
                reservations = reservation.load_reservation("reservation.csv");
                bool isreserved;
                isreserved = reservation.makeReservations(reservations);
                if (isreserved) std::cout << "room successfully reserved. Thak you for being a customer. ";
                else std::cout << "Room is already reserved on the particualr date. Yoi can reserve another room or on another date. Thank you.";
                break;
            case 3:
                std::string opinion;
                std::cout << "Is there a specific reason why you want to cancel your reservation: ";
                std::cin >> opinion;
                std::string name;
                std::cout << "What is the name you used to make reservation: ";
                std::cin >> name;
                std::tolower(name);
                bool isCancelled;
                isCancelled = reservation.cancel_reservation(name, reservations);
                if (isCancelled) std::cout << "Resrevation successfully cancelled. ";
                else std::cout << "Reservation not duccessfult=y cancelled. You either put in a wrong reservation name or wished to cancel. You can try again or exit program. ";

                break;
            case 4:
                int room_number;
                std::cout << "please what is your room number ";
                std::cin >> room_number;
                std::cout << "Kindly state your name agin ";
                std::string checkout_name;
                std::cin >> checkout_name;
                int released = room.releaseRoom(rooms, room_number, checkout_name);
                if (released) std::cout << "Room successfully released. Thank you.\n";
                else std::cout << "incorrect room number, put in the correct room number and try again\n"
                break;
            case 5:
                //to check in after reservation.
                std::cout << "What is your name you used for the resr=ervations. ";
                std::string reserve_name;
                std::cin >> reserve_name;
                reserve_name = std::lower(reserve_name);
                int checked = reservation.checkin( reservations,reserve_name);
                if (checked){
                    std::cout << "You have suvvvesfully checked in.\n";
                }else std::cout << "reservation does not exist. ";
                break;
            case 6:
                room.updateRommfile(rooms);
                reservation.updateReservationFile(reservations);
                std::cout << "Thank you for using our program..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }

    } while (want != 6);  // Continue until user selects '6' to quit

    return 0;
}
