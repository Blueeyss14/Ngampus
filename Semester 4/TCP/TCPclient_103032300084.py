import socket

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(('localhost', 12345))

while True:
    pesan = input("Masukkan pesan: ")
    
    if pesan.lower() == "exit":
        print("Menutup koneksi...")
        client_socket.sendall(pesan.encode())
        break

    client_socket.sendall(pesan.encode())
    data = client_socket.recv(1024).decode()
    print("Respon dari server:", data)

client_socket.close()
