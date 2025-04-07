#ifndef NUMTICKET_H
#define NUMTICKET_H

class NumTicket {
private:
    int ticketNumber;
    int saleTime;
    int remainingTrips;

public:
    NumTicket(int ticketNumber, int saleTime, int remainingTrips);
    int getRemainingTrips() const;
    bool attemptPass(int currentTime);
};

#endif
