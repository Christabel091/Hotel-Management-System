#include "../header/room.h"

#include<iostream>
#include<fstream>
#include<vector>
#include<string>

//constructor
Room::Room(){
}




bool Room::Check_availability(){
    return isAvailable;
}

//unbook booked room
bool Room::releaseRoom(std::vector<Room> &rooms, int check_out_number, std::string checkout_name){
    for (auto& room : rooms){
        if ((room.room_number == check_out_number)){
            room.isAvailable = true;
            return true;
        }
    }
    return false;
    
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
    type = std::lower(type);
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
        type = std::lower(type);
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

bool Room::bookRoom(std::vector<Room> &rooms, std::string roomType){
    for (auto& room : rooms) {
            if (room.room_type == roomType) {
                if (room.Check_availability()) {
                    room.isAvailable = false;
                    return true; // Room booked successfully
                } else {
                    continue;
                }
            }
    }
     return false; // type not found
    
}


void  Room::updateRommfile(std::vector<Room> rooms){
    std::ofstream outfile;
    outfile.opemm("room.csv");
    outfile << "RoomNumber,Type,Occupancy,PricePerNight,Status\n";
    for (auto& room : rooms ){
        outfile << room.room_number << ',' 
        << room.room_type << ',' 
        << room.max_size << ','
        << room.room_price << ',';
        if (room.isAvailable){
            outfile << "available\n";
        }else {
            outfile << "occupied\n";
        }

    }
    outfile.close()
}