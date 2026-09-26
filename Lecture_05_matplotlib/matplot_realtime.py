import matplotlib.pyplot as plt
import random

x_data = []
y_data = []

for i in range(101):
    sensor_value = random.randint(0, 100)

    x_data.append(i)
    y_data.append(sensor_value)

    plt.clf()
    plt.plot(x_data, y_data)

    plt.xlabel("Sample Number")
    plt.ylabel("Sensor Value")
    plt.title("Real-Time Sensor Plot")
    plt.grid(True)
    plt.pause(0.05)

plt.show()
