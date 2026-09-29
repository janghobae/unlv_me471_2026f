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

while True:
    data_raw = ser.readline()
    data_str = data_raw.strip().decode()
    data_int = int(data_str)

    x_data.append(i)
    y_data.append(data_int)

    plt.clf()
    plt.plot(x_data, y_data)

    plt.xlabel("Sample Number")
    plt.ylabel("Sensor Value")
    plt.title("Real-Time Sensor Plot")
    plt.grid(True)

    if len(x_data) > 20:
        plt.xlim([len(x_data)-20, len(x_data)])

    plt.pause(0.1)
    i = i + 1

plt.show()