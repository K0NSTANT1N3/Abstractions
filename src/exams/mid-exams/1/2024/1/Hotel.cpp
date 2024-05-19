//
// Created by konstantine on 5/15/24.
//

#include "Hotel.h"

/** private */
int Hotel::maxBookingsHelper(Vector<bookingsT> &options, int index, Vector<bool> &usedDates) {
    /* Base Case */
    if (index >= options.size())return 0;

    /* Inductive Step */
    bool mustContain = true;
    bookingsT cur = options[index];
    for (int i = cur.left; i <= cur.right; i++) {
        if (usedDates[i]) { // check if hotel is already booked
            mustContain = false;
            break;
        }
    }

    int ansWithout = maxBookingsHelper(options, index + 1, usedDates);
    if (!mustContain) return ansWithout;

    manageBookings(usedDates, cur.left, cur.right, true);
    int ansWithin = cur.price + maxBookingsHelper(options, index + 1, usedDates);
    manageBookings(usedDates, cur.left, cur.right, false);

    return max(ansWithout, ansWithin);
}

void Hotel::manageBookings(Vector<bool> &usedDates, int left, int right, bool state) {
    for (int i = left; i <= right; i++) {
        usedDates[i] = state;
    }
}

/** public */
int Hotel::maxBookings(Vector<bookingsT> &options) {
    Vector<bool> usedDates;
    for (int i = 0; i < 366; i++) {
        usedDates.push_back(false);
    }
    return maxBookingsHelper(options, 0, usedDates);
}
