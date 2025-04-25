from pyswip import Prolog

class TicketSearch:
    def __init__(self, prolog_file_path):
        self.prolog = Prolog()
        self.prolog.consult(prolog_file_path)

    def search_tickets(self, min_number, min_trips, start_time, end_time):
        query = f"find_tickets({min_number}, {min_trips}, {start_time}, {end_time}, TicketNumber)"
        results = list(self.prolog.query(query))
        return [result['TicketNumber'] for result in results]