#include "TicketRegistry.h"
#include <iostream>
#include <chrono>
#include <iomanip> // Для форматирования вывода

void runTests() {
    std::cout << "=== Performance Tests ===" << std::endl;

    TicketRegistry registry;
    const int numTickets = 10000;

    // Вставка билетов
    std::cout << "[DEBUG] Starting insertion of " << numTickets << " tickets..." << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numTickets; ++i) {
        if (!registry.addTicket(Ticket(i, "Description " + std::to_string(i)))) {
            std::cerr << "Failed to insert ticket " << i << std::endl;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    double insertionTime = std::chrono::duration<double>(end - start).count();
    std::cout << "[DEBUG] Finished insertion. Time: " << insertionTime << " seconds." << std::endl;

    // Поиск билетов
    std::cout << "[DEBUG] Starting search for tickets every 1000th ID..." << std::endl;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numTickets; i += 1000) {
        if (!registry.findTicket(i)) {
            std::cerr << "Ticket " << i << " not found!" << std::endl;
        }
    }
    end = std::chrono::high_resolution_clock::now();
    double searchTime = std::chrono::duration<double>(end - start).count();
    std::cout << "[DEBUG] Finished search. Time: " << searchTime << " seconds." << std::endl;

    // Размер реестра
    std::cout << "Registry Size: " << registry.size() << std::endl;

    // Итоговый вывод
    std::cout << "=== Test Summary ===" << std::endl;
    std::cout << "Insertion Time: " << insertionTime << " seconds" << std::endl;
    std::cout << "Search Time: " << searchTime << " seconds" << std::endl;
}

int main() {
    try {
        std::cout << "[DEBUG] Starting performance tests..." << std::endl;
        runTests();
        std::cout << "[DEBUG] Performance tests completed." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown error occurred." << std::endl;
    }
    return 0;
}