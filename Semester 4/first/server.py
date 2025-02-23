import socket

def start_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    server_socket.bind(("127.0.0.1", 20003))

    server_socket.listen(1)
    print("Server berjalan di 127.0.0.1:20003, menunggu koneksi...")

    while True:
        client_socket, client_address = server_socket.accept()
        print(f"Koneksi diterima dari {client_address}")

        try:
            data = client_socket.recv(1024).decode("utf-8")
            if not data:
                break
            print(f"Klien mengirim pesan: {data}")

            response = f"Pesan diterima: {data}"
            client_socket.send(response.encode("utf-8"))

        finally:
            client_socket.close()
            print("Koneksi ditutup.")

if __name__ == "__main__":
    start_server()
