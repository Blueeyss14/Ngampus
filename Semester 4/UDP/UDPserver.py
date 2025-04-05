import socket
import datetime

def process_data(data):
    # Inversi case
    inverted_case = data.swapcase()
    # Hitung jumlah karakter dalam data
    char_count = len(data)
    # Hapus spasi di awal dan akhir
    trimmed_data = data.strip()
    # Tambahkan timestamp
    timestamp = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
    # Tambahkan pesan konfirmasi
    processed_data = f"{inverted_case} [{timestamp}] [Data telah diproses]"
    return processed_data

server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_address = ('localhost', 12345)
server_socket.bind(server_address)

print("Server UDP berjalan...")

while True:
    data, client_address = server_socket.recvfrom(1024)
    received_data = data.decode()
    print(f"Menerima data dari client: {received_data}")
    processed_data = process_data(received_data)
    server_socket.sendto(processed_data.encode(), client_address)