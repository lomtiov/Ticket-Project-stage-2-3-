import ctypes
import tkinter as tk
from tkinter import messagebox

# Загрузка DLL
lib = ctypes.CDLL("./TicketLibrary.dll")

# Объявляем сигнатуру функции
lib.process_ticket.argtypes = [ctypes.c_int, ctypes.c_int, ctypes.c_int]
lib.process_ticket.restype = ctypes.c_char_p

def on_check_pass():
    try:
        ticket_number = int(entry_number.get())
        sale_time = int(entry_sale_time.get())
        remaining = int(entry_remaining.get())

        result = lib.process_ticket(ticket_number, sale_time, remaining)
        messagebox.showinfo("Результат", result.decode('utf-8'))

    except ValueError:
        messagebox.showerror("Ошибка", "Введите корректные целые значения.")
    except Exception as e:
        messagebox.showerror("Ошибка", f"Не удалось обработать билет: {e}")

# Интерфейс
root = tk.Tk()
root.title("Проверка билета")

tk.Label(root, text="Номер билета:").grid(row=0, column=0, sticky="e")
entry_number = tk.Entry(root)
entry_number.grid(row=0, column=1)

tk.Label(root, text="Время продажи (сек):").grid(row=1, column=0, sticky="e")
entry_sale_time = tk.Entry(root)
entry_sale_time.grid(row=1, column=1)

tk.Label(root, text="Оставшиеся поездки:").grid(row=2, column=0, sticky="e")
entry_remaining = tk.Entry(root)
entry_remaining.grid(row=2, column=1)

btn = tk.Button(root, text="Проверить проход", command=on_check_pass)
btn.grid(row=3, columnspan=2, pady=10)

root.mainloop()