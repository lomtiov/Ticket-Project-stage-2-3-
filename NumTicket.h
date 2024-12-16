#ifndef NUMTICKET_H
#define NUMTICKET_H

#include "Ticket.h"

class NumTicket : public Ticket {
private:
    int remainingTrips;

public:
    NumTicket(int ticketNumber, int saleTime, int remainingTrips);

    int getRemainingTrips() const;

    bool attemptPass(int currentTime) override;

    // Реализация клонирования
    NumTicket* clone() const override;
};

#endif // NUMTICKET_H