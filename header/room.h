#ifndef ROOM_H
#define ROOM_H

#include<iostream>
#include<vector>
class Room {
    int room_number;
    bool isAvailable;
    std::string room_type;
    int max_size;
    double room_price;
public:
    Room(int, std::string, int, double, bool);
    std::vector<Room> loadRoom(std::vector<Room> &);
    bool bookRoom(std::vector<Room>, std::string);
    bool Check_availability();
    bool releaseRoom();
    int get_room_number(){
        return room_number;


    }
    void updateRommfile();
};
#endif