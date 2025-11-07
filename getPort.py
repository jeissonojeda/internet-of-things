import serial.tools.list_ports

def detectBoardPort():
    ports = serial.tools.list_ports.comports()
    for port in ports:
        if "Arduino" in port.description or "CH340" in port.description:
            print(f"Board description: {port.description}")
            print(f"Board port: {port.device}")
            print(f"Board name: {port.name}")
            print(f"HWID: {port.hwid}")
            return port.device
    return None

if __name__ == "__main__":
    port = detectBoardPort()
    if port:
        print(f"Board port detected: {port}")
    else:
        print("No Board detected")
