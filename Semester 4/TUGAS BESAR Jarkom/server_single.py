import socket

def handle_client(conn):
    try:
        req = conn.recv(1024).decode()
        parts = req.split()
        if len(parts) < 2 or parts[0] != 'GET':
            return
        filename = parts[1].lstrip('/') or 'index.html'
        try:
            with open(filename, 'rb') as f:
                content = f.read()
            status = "HTTP/1.1 200 OK"
        except FileNotFoundError:
            content = b"<h1>404 Not Found</h1>"
            status = "HTTP/1.1 404 Not Found"
        header = (
            f"{status}\r\n"
            f"Content-Length: {len(content)}\r\n"
            "Content-Type: text/html\r\n"
            "Connection: close\r\n\r\n"
        )
        conn.sendall(header.encode() + content)
    except Exception as e:
        print(f"Error: {e}")
    finally:
        conn.close()

def main():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind(('', 6789))
        s.listen(1)
        print("Server listening on port 6789...")
        conn, addr = s.accept()
        print(f"Connected by {addr}")
        handle_client(conn)

if __name__ == "__main__":
    main()
