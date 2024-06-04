#ifndef ROOM_H
#define ROOM_H

#include<iostream>
#include<vector>
class Room {
    int room_number;
    bool isAvailable;
    std::string room_type;
    int max_size;
    double price;
public:
    Room();
    std::vector<Room> loadRoom();
    void setIsAvailable();
    void bookRoom();
    bool Check_availability();
    void releaseRoom();

};
#endif