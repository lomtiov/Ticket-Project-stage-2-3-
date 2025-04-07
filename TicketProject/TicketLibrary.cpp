#include "TicketLibrary.h"
#include "NumTicket.h"

DLL_EXPORT void* createTicket(int number, int saleTime, int trips) {
    return new NumTicket(number, saleTime, trips);
}

DLL_EXPORT bool checkPass(void* ticketPtr, int currentTime) {
    NumTicket* ticket = static_cast<NumTicket*>(ticketPtr);
    return ticket->attemptPass(currentTime);
}

DLL_EXPORT int getTrips(void* ticketPtr) {
    NumTicket* ticket = static_cast<NumTicket*>(ticketPtr);
    return ticket->getRemainingTrips();
}

DLL_EXPORT void deleteTicket(void* ticketPtr) {
    delete static_cast<NumTicket*>(ticketPtr);
}
