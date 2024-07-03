//
// Created by konstantine on 5/15/24.
//

#ifndef ABSTRACTIONS_HOTEL_H
#define ABSTRACTIONS_HOTEL_H

#include<iostream>
#include"vector.h"

using namespace std;

class Hotel {
public:
    struct bookingsT {
        int left, right, price;
    };
private:
    void manageBookings(Vector<bool>& usedDates, int left, int right, bool state);
    int maxBookingsHelper(Vector<bookingsT>& options, int index, Vector<bool>& usedDates);

public:
    int maxBookings(Vector<bookingsT>& options);
};


#endif //ABSTRACTIONS_HOTEL_H
