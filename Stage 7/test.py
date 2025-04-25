from Python.ticket_search import TicketSearch

def test_prolog_integration():
    searcher = TicketSearch("ticket_search.pl")
    tickets = searcher.search_tickets(0, 1, 1000, 2000)
    assert tickets == [1, 2], f"Unexpected result: {tickets}"
    print("Prolog integration test passed.")

if __name__ == "__main__":
    test_prolog_integration()