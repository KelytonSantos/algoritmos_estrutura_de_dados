import socket

def listener(port):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind(('0.0.0.0', port))
    s.listen(1)
    print(f"[+] Listening on port {port}...")

    conn, addr = s.accept()
    print(f"[+] Connection from {addr}")

    while True:
        command = input("")
        if command.lower() in ['exit', 'quit']:
            break
        conn.send(command.encode() + b'\n')
        data = conn.recv(4096)
        print(data.decode(), end='')

    conn.close()
    s.close()

if __name__ == "__main__":
    listener(4444)
