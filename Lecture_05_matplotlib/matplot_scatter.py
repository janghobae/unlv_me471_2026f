import matplotlib.pyplot as plt

time = [1.2, 2.8, 3.4, 4.9, 5.1, 
        6.7, 7.5, 8.9, 9.3, 10.8,
        11.4, 12.9, 13.2, 14.7, 15.6, 
        16.1, 17.8, 18.5, 19.3, 20.7]
sensor_value = [5.2, 8.1, 7.4, 12.3, 11.6, 
                15.2, 18.5, 16.8, 21.4, 24.1,
                22.7, 28.3, 27.6, 31.2, 35.5, 
                33.9, 38.4, 41.1, 39.7, 45.3]

plt.scatter(time, sensor_value)

plt.xlabel("Time (s)")
plt.ylabel("Sensor Value (V)")
plt.title("Sensor Data")

plt.xlim([0, 25])
plt.ylim([0, 50])

plt.grid(True)
plt.show()
