import ctypes

# Загружаем библиотеку
lib = ctypes.CDLL("C:/Programming/TicketProject/TicketLibrary.dll")

# Настраиваем аргументы и возвращаемые типы
lib.createTicket.argtypes = [ctypes.c_int, ctypes.c_int, ctypes.c_int]
lib.createTicket.restype = ctypes.c_void_p

lib.checkPass.argtypes = [ctypes.c_void_p, ctypes.c_int]
lib.checkPass.restype = ctypes.c_bool

lib.getTrips.argtypes = [ctypes.c_void_p]
lib.getTrips.restype = ctypes.c_int

lib.deleteTicket.argtypes = [ctypes.c_void_p]

# Создаём билет
ticket = lib.createTicket(123, 1000, 3)

# Проверяем проход
result = lib.checkPass(ticket, 1005)  # например, передаем текущее время 1005 секунд
print("Попытка прохода:", result)

# Получаем оставшиеся поездки
trips = lib.getTrips(ticket)
print("Осталось поездок:", trips)

# Удаляем билет, чтобы не было утечки памяти
lib.deleteTicket(ticket)