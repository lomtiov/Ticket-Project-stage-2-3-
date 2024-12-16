#include "TimeLimitedTicket.h"

TimeLimitedTicket::TimeLimitedTicket(int ticketNumber, int saleTime, int validityPeriod) 
    : Ticket(ticketNumber, saleTime), validityPeriod(validityPeriod) 
{
    if (validityPeriod <= 0) throw std::invalid_argument("Invalid validity period");
}

bool TimeLimitedTicket::attemptPass(int currentTime) {
    return currentTime <= saleTime + validityPeriod;
}