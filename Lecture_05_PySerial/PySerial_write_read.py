import serial

ser = serial.Serial(
    port='COM8',
    baudrate=115200,
    timeout=1
)

while True:
    command = str(input("Input command:"))
    ser.write(command)

    response = ser.readline()
    print(response)

ser.close