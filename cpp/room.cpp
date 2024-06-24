#include "../header/room.h"

#include<iostream>
#include<fstream>
#include<vector>
#include<string>

//constructor
Room::Room(int number,std::string type, int size,double price, bool available){
    room_number = number;
    room_type = type;
    max_size = size;
    room_price = price;
    isAvailable = available;
}




bool Room::Check_availability(){
    return isAvailable;
}

//unbook booked room
void Room::releaseRoom(){
    isAvailable = true;
}


std::vector<Room> Room::loadRoom(std::vector<Room> &rooms){
    std::ifstream infile ("room.csv");
    int number, size;
    std::string type;
    float price;
    std::string available;
    std::string head;
    std::getline(infile, head);
    infile.ignore();
    infile >> number ;
    infile.ignore();
    std::getline(infile, type, ',');
    infile.ignore();
    infile >> size ;
    infile.ignore();
    infile >> price;
    infile.ignore();
    std::getline(infile, available);
    while (infile){
        bool isavailable = (available == "available") ? true : false;
        rooms.emplace_back(number, type, size, price, isavailable);
        infile.ignore();
        infile >> number ;
        infile.ignore();
        std::getline(infile, type, ',');
        infile.ignore();
        infile >> size ;
        infile.ignore();
        infile >> price;
        infile.ignore();
        std::getline(infile, available);
    }
    infile.close();
    return rooms;
}

bool Room::bookRoom(int roomNumberToFind, std::vector<Room> &rooms){
    for (auto& room : rooms) {
            if (room.room_number == roomNumberToFind) {
                if (room.Check_availability()) {
                    room.isAvailable = false;
                    return true; // Room booked successfully
                } else {
                    return false; // Room is not available
                }
            }
    }
     return false; // Room not found
    
}


