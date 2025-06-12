import serial
import csv
import time
import locale

locale.setlocale(locale.LC_NUMERIC, 'nl_NL.UTF-8')

ser = serial.Serial('COM5', 9600, timeout=1)
ser.readline()

with open('output/logs.csv', mode='w', newline='') as file:
    writer = csv.writer(file, delimiter=';')
    writer.writerow(['Timestamp (s)', 'Temperature (C)', 'Light'])

    start_time = time.time()
    try:
        while True:
            line = ser.readline().decode('utf-8').strip()
            if line:
                try:
                    parts = line.split(',')
                    tempC = float(parts[0].split(':')[1])
                    light = float(parts[1].split(':')[1])

                    elapsed = time.time() - start_time
                    elapsed = round(elapsed * 2) / 2

                    elapsed_str = locale.format_string('%.1f', elapsed)
                    tempC_str = locale.format_string('%.2f', tempC)
                    light_str = locale.format_string('%.2f', light)

                    writer.writerow([elapsed_str, tempC_str, light_str])
                    print(f"{elapsed_str}s - {tempC_str}°C | Licht: {light_str}")
                except (ValueError, IndexError):
                    print(f"Line kan niet gelezen worden: {line}")
    except KeyboardInterrupt:
        print("\nLoggen is gestopt.")
