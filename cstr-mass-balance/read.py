import serial
import csv
import time
import locale

locale.setlocale(locale.LC_NUMERIC, 'nl_NL.UTF-8')

ser = serial.Serial('COM5', 9600, timeout=1)
ser.readline()

with open('output/logs.csv', mode='w', newline='') as file:
    writer = csv.writer(file, delimiter=';')
    writer.writerow(['Timestamp', 'Temperature', 'Humidity', 'Alcohol'])

    start_time = time.time()
    try:
        while True:
            line = ser.readline().decode('utf-8').strip()
            if line:
                try:
                    parts = line.split(',')
                    tempC = float(parts[0].split(':')[1])
                    hum = float(parts[1].split(':')[1])
                    alc = float(parts[2].split(':')[1])

                    elapsed = time.time() - start_time
                    elapsed = round(elapsed * 2) / 2

                    elapsed_str = locale.format_string('%.1f', elapsed)
                    tempC_str = locale.format_string('%.2f', tempC)
                    hum_str = locale.format_string('%.1f', hum)
                    alc_str = locale.format_string('%.0f', alc)

                    writer.writerow([elapsed_str, tempC_str, hum_str, alc_str])
                    print(f"{elapsed_str}s - {tempC_str}°C | Humidity: {hum_str}% | Alcohol: {alc_str}")
                except (ValueError, IndexError):
                    print(f"Line kan niet gelezen worden: {line}")
    except KeyboardInterrupt:
        print("\nLoggen is gestopt.")
