import socket

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('localhost', 12345))
server_socket.listen(1)

print("Menunggu koneksi dari client...")
conn, addr = server_socket.accept()
print(f"Koneksi diterima dari {addr}")

while True:
    data = conn.recv(1024).decode()
    
    if not data:
        print("Koneksi ditutup oleh client.")
        break
    
    print("Pesan dari client:", data)
    
    if data.lower() == "exit":
        print("Client meminta keluar. Menutup koneksi...")
        break  

    conn.sendall(f"Pesan diterima: {data}".encode())

conn.close()
server_socket.close()
