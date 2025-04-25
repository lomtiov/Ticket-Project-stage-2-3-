#ifndef TICKET_LIBRARY_H
#define TICKET_LIBRARY_H

#ifdef _WIN32
#define DLL_EXPORT extern "C" __declspec(dllexport)
#else
#define DLL_EXPORT extern "C"
#endif

DLL_EXPORT void* createTicket(int number, int saleTime, int trips);
DLL_EXPORT bool checkPass(void* ticketPtr, int currentTime);
DLL_EXPORT int getTrips(void* ticketPtr);
DLL_EXPORT void deleteTicket(void* ticketPtr);

#endif
