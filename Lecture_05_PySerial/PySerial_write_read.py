import serial

ser = serial.Serial(
    port='COM8',
    baudrate=115200,
    timeout=1
)

while True:
    command = str(input("Input command:"))
    ser.write(bytes(command, encoding="ascii"))

    response_raw = ser.readline()
    response = response_raw.strip().decode()
    print(response)

ser.close