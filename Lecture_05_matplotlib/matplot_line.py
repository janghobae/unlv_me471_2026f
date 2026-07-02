import matplotlib.pyplot as plt

x = [0, 1, 2, 3, 4, 5]
y = [0, 1, 4, 9, 16, 25]

plt.plot(x, y)

plt.xlabel("Time")
plt.ylabel("Sensor Value")
plt.title("Basic Line Plot")

plt.show()