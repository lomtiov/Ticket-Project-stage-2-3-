#include "NumTicket.h"

NumTicket::NumTicket(int number, int sale, int trips)
    : ticketNumber(number), saleTime(sale), remainingTrips(trips) {}

int NumTicket::getRemainingTrips() const {
    return remainingTrips;
}

bool NumTicket::attemptPass(int currentTime) {
    if (remainingTrips <= 0) return false;
    --remainingTrips;
    return true;
}
