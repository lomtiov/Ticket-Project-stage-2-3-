#ifndef TIMELIMITEDTICKET_H
#define TIMELIMITEDTICKET_H

#include "Ticket.h"

class TimeLimitedTicket : public Ticket {
private:
    int validityPeriod;  // Срок действия в секундах

public:
    TimeLimitedTicket(int ticketNumber, int saleTime, int validityPeriod);

    // Проверка возможности прохода
    bool attemptPass(int currentTime) override;
};

#endif // TIMELIMITEDTICKET_H