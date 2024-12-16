#ifndef NUMTICKET_H
#define NUMTICKET_H

#include "Ticket.h"

class NumTicket : public Ticket {
private:
    int remainingTrips;  // Оставшиеся поездки

public:
    NumTicket(int ticketNumber, int saleTime, int remainingTrips);

    int getRemainingTrips() const;

    bool attemptPass(int currentTime) override;
};

#endif // NUMTICKET_H