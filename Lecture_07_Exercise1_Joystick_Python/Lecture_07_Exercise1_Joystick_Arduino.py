import serial
import matplotlib.pyplot as plt

point_x = 0
point_y = 0

ser = serial.Serial(
    port='COM8',
    baudrate=115200,
    timeout=1
)

while True:
    x_data_raw = ser.readline()
    y_data_raw = ser.readline()
    sw_data_raw = ser.readline()

    x_data_int = int(x_data_raw.strip().decode())
    y_data_int = int(y_data_raw.strip().decode())
    sw_data_int = int(sw_data_raw.strip().decode())

    plt.clf()

    if x_data_int > 600:
        point_x = point_x - 1
    elif x_data_int < 500:
        point_x = point_x + 1

    if y_data_int > 600:
        point_y = point_y + 1
    elif y_data_int < 500:
        point_y = point_y - 1

    if sw_data_int == 1:
        plt.scatter(point_x, point_y, color='blue')
    else:
        plt.scatter(point_x, point_y, color='red')

    plt.xlabel("x")
    plt.ylabel("y")
    plt.title("Point")
    plt.grid(True)
    plt.xlim([-20, 20])
    plt.ylim([-20, 20])

    plt.pause(0.05)