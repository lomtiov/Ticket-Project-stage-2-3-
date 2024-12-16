test: *.h *.cpp
	g++ -std=c++17 -Wall -Wextra -g NumTicket.cpp TestTicketRegistry.cpp Ticket.cpp TicketRegistry.cpp TimeLimitedTicket.cpp UnlimitedTicket.cpp -o test