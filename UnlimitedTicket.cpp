#include "UnlimitedTicket.h"

UnlimitedTicket::UnlimitedTicket(int ticketNumber, int saleTime, const std::string& reason)
    : Ticket(ticketNumber, saleTime), reason(reason), lastPassTime(-1) {}

bool UnlimitedTicket::attemptPass(int currentTime) {
    if (lastPassTime != -1 && (currentTime - lastPassTime < 180)) {
        return false;
    }
    lastPassTime = currentTime;
    return true;
}

UnlimitedTicket* UnlimitedTicket::clone() const {
    return new UnlimitedTicket(*this);
}