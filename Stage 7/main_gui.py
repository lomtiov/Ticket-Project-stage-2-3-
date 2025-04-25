import tkinter as tk
from tkinter import messagebox
from ticket_search import TicketSearch

def search():
    try:
        min_number = int(entry_min_number.get())
        min_trips = int(entry_min_trips.get())
        start_time = int(entry_start_time.get())
        end_time = int(entry_end_time.get())

        tickets = searcher.search_tickets(min_number, min_trips, start_time, end_time)
        result_text.set(f"Найденные билеты: {', '.join(map(str, tickets))}" if tickets else "Нет подходящих билетов")
    except Exception as e:
        messagebox.showerror("Ошибка", f"Не удалось выполнить поиск: {e}")

# Initialize Prolog interaction
prolog_path = "ticket_search.pl"
searcher = TicketSearch(prolog_path)

# Create GUI
root = tk.Tk()
root.title("Поиск билетов")

tk.Label(root, text="Минимальный номер билета:").grid(row=0, column=0)
entry_min_number = tk.Entry(root)
entry_min_number.grid(row=0, column=1)

tk.Label(root, text="Минимальное число поездок:").grid(row=1, column=0)
entry_min_trips = tk.Entry(root)
entry_min_trips.grid(row=1, column=1)

tk.Label(root, text="Начальное время продажи:").grid(row=2, column=0)
entry_start_time = tk.Entry(root)
entry_start_time.grid(row=2, column=1)

tk.Label(root, text="Конечное время продажи:").grid(row=3, column=0)
entry_end_time = tk.Entry(root)
entry_end_time.grid(row=3, column=1)

tk.Button(root, text="Искать", command=search).grid(row=4, column=0, columnspan=2)

result_text = tk.StringVar()
tk.Label(root, textvariable=result_text, fg="blue").grid(row=5, column=0, columnspan=2)

root.mainloop()