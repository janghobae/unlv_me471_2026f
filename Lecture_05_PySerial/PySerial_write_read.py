import serial

ser = serial.Serial(
    port='COM8',
    baudrate=115200,
    timeout=1
)

while True:
    command = str(input("Input command:"))
    ser.write(bytes(command, encoding='utf-8'))

    response = ser.readline().decode().strip()
    print(response)

ser.close