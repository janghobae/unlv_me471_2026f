import serial
import matplotlib.pyplot as plt

x_data = []
y_data = []
i = 0;

ser = serial.Serial(
    port='COM8',
    baudrate=115200,
    timeout=1
)

command = str(input("Input Desired Position:"))
ser.write(bytes(command, encoding='utf-8'))

for i in range(0, 1000):
    data_raw = ser.readline()
    data_str = data_raw.strip().decode()
    data_int = int(data_str)

    x_data.append(i)
    y_data.append(data_int)

plt.clf()
plt.plot(x_data, y_data)

plt.xlabel("Time")
plt.ylabel("Position")
plt.title("Real-Time Sensor Plot")
plt.grid(True)

plt.show()