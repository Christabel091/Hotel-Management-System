#ifndef RESERVATION_N
#define RESERVATION_H

#include <iostream>
#include <string>
#include "../header/room.h"

class Reservation{
    int reservationId{0};
    std::string name;
    long int number;
    int room_number;
    int check_in_time;
    int time_period;
    bool isreserved {false};

public:
    Reservation(std::string, int , int , int );
    bool makeReservations(std::vector<Reservation>);
    void cancel_reservation(std::string , std::vector<Reservation>);
    void updateReservationFile();
    std::vector<Reservation> load_reservation(const std::string );
    bool checkin();
};


#endif