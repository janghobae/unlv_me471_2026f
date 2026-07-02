import matplotlib.pyplot as plt
import random
import time

x_data = []
y_data = []

plt.ion()

for i in range(50):
    sensor_value = random.randint(0, 1023)

    x_data.append(i)
    y_data.append(sensor_value)

    plt.clf()
    plt.plot(x_data, y_data)

    plt.xlabel("Sample Number")
    plt.ylabel("Sensor Value")
    plt.title("Real-Time Sensor Plot")
    plt.grid(True)

    plt.pause(0.1)

plt.ioff()
plt.show()