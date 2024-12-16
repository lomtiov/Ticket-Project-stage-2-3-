#ifndef TIMELIMITEDTICKET_H
#define TIMELIMITEDTICKET_H

#include "Ticket.h"

class TimeLimitedTicket : public Ticket {
private:
    int validityPeriod;

public:
    TimeLimitedTicket(int ticketNumber, int saleTime, int validityPeriod);

    bool attemptPass(int currentTime) override;

    // Реализация клонирования
    TimeLimitedTicket* clone() const override;
};

#endif // TIMELIMITEDTICKET_H