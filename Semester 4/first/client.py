import socket

def start_client():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    server_address = ("127.0.0.1", 20003)
    print("Menghubungkan ke server...")
    client_socket.connect(server_address)

    try:
        nama = "Delkano"
        nim = "103032300084"
        message = f"Halo, Server saya {nama} dengan {nim} mengirim pesan."
        client_socket.send(message.encode("utf-8"))

        response = client_socket.recv(1024).decode("utf-8")
        print(f"Balasan dari server: {response}")

    finally:
        client_socket.close()
        print("Koneksi ditutup.")

if __name__ == "__main__":
    start_client()
