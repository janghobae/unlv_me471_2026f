import matplotlib.pyplot as plt

voltage = [0, 1, 2, 3, 4, 5]
sensor_value = [5, 102, 210, 315, 430, 520]

plt.scatter(voltage, sensor_value)

plt.xlabel("Voltage [V]")
plt.ylabel("Analog Reading")
plt.title("Voltage vs. Analog Sensor Reading")

plt.grid(True)
plt.show()