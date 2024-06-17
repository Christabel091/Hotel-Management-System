#ifndef RESERVATION_N
#define RESERVATION_H

#include <iostream>
#include <string>
#include "../header/room.h"

class Reservation{
    Room room;
    int reservationId;
    std::string name;
    long int number;
    int room_number;
    int check_in_time;
    int time_period;
    bool isreserved;

public:
    Reservation(std::string userName, int phone);
    bool makeReservations();
    void cancel_reservation();
    void updateReservationFile();
    std::vector load_reservation();
    void iewReservation();
};

#endif