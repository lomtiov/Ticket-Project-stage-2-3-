#include "NumTicket.h"
#include <exception>

extern "C" __declspec(dllexport)
const char* process_ticket(int ticketNumber, int saleTime, int remaining) {
    try {
        NumTicket ticket(ticketNumber, saleTime, remaining);
        bool result = ticket.attemptPass(saleTime + 5); // имитируем проход через 5 сек

        if (result)
            return "Проход разрешён";
        else
            return "Проход запрещён";
    } catch (const std::exception& e) {
        return "Ошибка: билет недействителен";
    }
}
