#include <iostream>
#include "TicketRegistry.h"

int main() {
    TicketRegistry registry(0, 100, 0, 100);

    registry.addTicket({1, 10, 10});
    registry.addTicket({2, 20, 20});
    registry.addTicket({3, 30, 30});

    std::cout << "Find ticket 2: " << (registry.findTicket(2) ? "Found" : "Not Found") << "\n";
    std::cout << "Total tickets: " << registry.size() << "\n";

    return 0;
}