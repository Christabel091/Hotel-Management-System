#include<iostream>
#include<string>
#include "../header/reservation.h"
#include "reservation.h"
#include<vector>
#include "../header/room.h"
#include<fstream>


Reservation::Reservation(std::string userName, int room, int date, int days){
    name = userName;
    room_number = room;
    check_in_time = date;
    time_period = days;
}


bool Reservation::makeReservations(std::vector<Reservation> &reservations){
    for (auto& reserve : reservations){
        if (reserve.room_number == room_number){
            if (reserve.check_in_time == check_in_time && reserve.isreserved == true){
                isreserved = false;
                return false;
            }
        }
    }
    isreserved = true;
    return true;
}

std::vector<Reservation> loadReservations(const std::string& filename) {
    std::vector<Reservation> reservations;
    std::ifstream file(filename);
    std::string line;
    
    // Skip the header line
    std::getline(file, line);
    
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string token;
        
        int reservationId;
        std::string name;
        long int number;
        int room_number;
        int check_in_time;
        int time_period;
        bool isreserved;
        
        std::getline(ss, token, ',');
        reservationId = std::stoi(token);
        std::getline(ss, name, ',');
        std::getline(ss, token, ',');
        number = std::stol(token);
        std::getline(ss, token, ',');
        room_number = std::stoi(token);
        std::getline(ss, token, ',');
        check_in_time = std::stoi(token);
        std::getline(ss, token, ',');
        time_period = std::stoi(token);
        std::getline(ss, token, ',');
        isreserved = (token == "true");
        
        reservations.push_back(Reservation(reservationId, name, number, room_number, check_in_time, time_period, isreserved));
    }
    
    return reservations;
}

bool Reservation::cancel_reservation(std::string Name, std::vector<Reservation> &reservations){
    for (auto reserve : reservations){
        if (reserve.name == Name){
            std::string anwser;
            std::cout << "You want to cancel reservation made by " << reserve.name << "to check in on " << reserve.check_in_time << "for " << reserve.time_period << " days?  (YES/NO)";
            std::cin >> anwser;
            std::toupper(anwser);
            if ("YES"){
                reserve.isreserved = false;
                return true;
            }
            else{
                std::cout << "Do you wish to cancel another another reservation or not cancel at all? ";
                std::cout << "\n 'YES' to csncel anither reservation or 'NO' not to cancel any reservation ";
                std::cout << anwser;
                anwser = ::toupper(anwser);
                if ("YES") continue;
                else return false;
            }
        }
    }
    return false;

}