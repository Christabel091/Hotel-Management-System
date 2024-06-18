#include<iostream>
#include<string>
#include "../header/reservation.h"
#include "reservation.h"
#include<vector>
#include "../header/room.h"
#include<fstream>


Reservation::Reservation(std::string userName, int userPhone){
    name = userName;
    number = userPhone;
}

bool Reservation::makeReservations(int roomToReserve){
    std::vector<Room> rooms;
    rooms = room.loadRoom(rooms);
    for (auto& room : rooms){
        
    }
}

std::vector<Reservation>  Reservation::load_reservation(){
    std::ifstream infile;
    infile.open("reservation.csv")
    while (infile){
        ??read from file
    }
    //open file and load and fund rooms that are reserved on the date
}

bool Reservation::cancel_reservation(){
    std::vector<Reservation> reserves;
    reserves = load_reservation()

}