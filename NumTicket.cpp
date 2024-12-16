#include "NumTicket.h"

NumTicket::NumTicket(int ticketNumber, int saleTime, int remainingTrips) 
    : Ticket(ticketNumber, saleTime), remainingTrips(remainingTrips) 
{
    if (remainingTrips < 0) throw std::invalid_argument("Invalid remaining trips");
}

int NumTicket::getRemainingTrips() const {
    return remainingTrips;
}

bool NumTicket::attemptPass(int currentTime) {
    if (remainingTrips <= 0) return false;
    remainingTrips--;
    return true;
}