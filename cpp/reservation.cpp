#include<iostream>
#include<string>
#include "../header/reservation.h"
#include "reservation.h"
#include<vector>
#include "../header/room.h"

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

std::vector Reservation::load_reservation(){
    //open file and load and fund rooms that are reserved on the date
}