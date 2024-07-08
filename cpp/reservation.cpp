#include<iostream>
#include<string>
#include "../header/reservation.h"
#include "reservation.h"
#include<vector>
#include "../header/room.h"
#include<fstream>


Reservation::Reservation(std::string userName, int room, int date, int days, int Number){
    name = userName;
    room_number = room;
    check_in_time = date;
    time_period = days;
    number = Number;
}


bool Reservation::makeReservations(std::vector<Reservation> &reservations){
    for (auto& reserve : reservations){
        if (reserve.room_number == room_number){
            if (reserve.check_in_time == check_in_time && reserve.isreserved == true){
                isreserved = false;
                return false;
            }
        }
        id = reservationId;
    }
    reservationId++;
    isreserved = true;
    reservations.emplace_back(reservationId, name,number, room_number,check_in_time, time_period, isreserved);
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

void Reservation::updateReservationFile(std::vector<Reservation> reservations){
    std::ofstream outfile;
    outfile.open("reservation.csv");
    outfile << "reservationId,name,number,room_number,check_in_time,time_period,isreserved\n";
    for (auto& reserve : reservations){
        outfile << reserve.reservationId << "," 
        << reserve.name << ','
        << reserve.number << ','
        << reserve.room_number << ','
        << reserve.check_in_time << ','
        << reserve.time_period << ','
        << reserve.isreserved << ','
    }
}


bool Reservation::checkin(std::vector<Reservation> &reservations, std::string reserved_name){
    int roomUnreserved;
    for (auto& reserve : reservations){
        if (reserve.name == reserved_name){
            std::vout << "Is your reservation for " << reserve.room_number;
            std::string response;
            std::cin >> response;
            response = std::lower(response);
            if ("yes"){
                roomUnreserved = reserve.reservationId;
                return true;
            }else continue;
        }
    }
     if (roomUnreserved < reserve.size()){
        reservations.erase(reservations.begin(), roomUnreserved-1);
     }
    return false;
}


void Reservation::view_reservation(std::string reserved_name, std::vector<Reservation> &reservations,){
    reserved_name = std::lower(reserved_name);
    bool viewed = false;
    std::cout << "These are the reservation made under " << reserved_name << "\n";
    for (auto &reserve : reservations){
        if (reserve.name == reserved_name) && (reserve.isreserved){
            std::cout << reserve.name << "reserved room " << reserve.room_number << "and was reserved on "<< reserve.check_in_time << "and will be staying for" << reserve.time_period << "days\n";
            viewed = true;
            continue;
            
        }
    }
    if (!viewed){
        std::cout << "There is no reservation made under the name " << reserved_name << '\n';
        std::cout << "You can click on 2 and make a new reservation or\n Put in the correct name used to make reservation";

    }
}