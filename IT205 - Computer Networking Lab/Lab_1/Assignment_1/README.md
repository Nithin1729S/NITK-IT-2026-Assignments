# Socket Programming in C - Server and Client

This repository contains two C programs for a simple client-server application using socket programming. The server counts the characters in the received data and sends the count back to the client.

## Server Code (`server.c`)

The `server.c` program implements a TCP server that performs the following tasks:

1. **Socket Creation:**
   - Creates a socket using `socket()` with the address family `AF_INET` (IPv4), socket type `SOCK_STREAM` (for TCP), and protocol `0` (default protocol).
   
2. **Server Address Initialization:**
   - Initializes a `struct sockaddr_in` named `servaddr` to represent the server's address.
   - Sets the address family to `AF_INET`.
   - Specifies the port number using `htons()` to convert it to network byte order.

3. **Binding:**
   - Binds the socket to the server address using `bind()`. Handles errors and exits if binding fails.
   
4. **Listening:**
   - Listens for incoming connections using `listen()`. Handles errors and exits if listening fails.
   
5. **Accepting Connections:**
   - Accepts incoming client connections using `accept()`. Handles errors and exits if accepting a connection fails.
   - Returns a new socket descriptor (`clifd`) to communicate with the client.
   
6. **Data Reception:**
   - Receives data sent by the client using `read()`. Stores the received data in the `recvContent` buffer.
   
7. **Character Counting:**
   - Counts the number of characters received from the client by iterating through `recvContent`.
   
8. **Converting Count:**
   - Converts the character count to network byte order using `htonl()` for consistent representation.
   
9. **Sending Data:**
   - Sends the character count back to the client using `send()`.
   
10. **Cleaning Up:**
    - Closes both the client and server sockets using `close()`.

## Client Code (`client.c`)

The `client.c` program implements a client that connects to the server and performs the following tasks:

1. **Socket Creation:**
   - Creates a client socket using `socket()` with the address family `AF_INET`, socket type `SOCK_STREAM`, and protocol `0`.

2. **Server Address Initialization:**
   - Initializes a `struct sockaddr_in` named `servaddr` to represent the server's address.
   - Sets the address family to `AF_INET`.
   - Specifies the server's port number using `htons()`.
   - Sets the server's IP address to "127.0.0.1" (localhost).

3. **Connecting to the Server:**
   - Connects to the server using `connect()`. Handles errors and exits if the connection fails.

4. **File Reading:**
   - Opens a file named "file.txt" for reading using `fopen()`. Handles errors and exits if file opening fails.

5. **File Size Calculation:**
   - Calculates the file size using `fseek()` and `ftell()` to determine the number of bytes in the file.

6. **Memory Allocation:**
   - Allocates memory for storing file contents in the `fileContents` buffer using `malloc()`. Handles errors and exits if memory allocation fails.

7. **File Contents Reading:**
   - Reads the file contents into the buffer using `fread()`.
   - Ensures null-termination of the contents.

8. **Data Transmission:**
   - Sends the file contents to the server using `send()`. Handles errors and exits if sending data fails.

9. **Receiving Data from Server:**
   - Receives the character count from the server using `read()`.
   - Converts the count from network byte order to host byte order using `ntohl()`.

10. **Displaying the Character Count:**
    - Displays the received character count on the client's console, avoiding counting the null character.

11. **Cleaning Up:**
    - Releases allocated memory for `fileContents` using `free()`.
    - Closes the client socket using `close()`.

## Usage

1. Compile the server and client code separately using a C compiler (e.g., `gcc server.c -o server` and `gcc client.c -o client`).

2. Run the server using `./server`.

3. Run the client using `./client`.

4. The client will send the contents of "file.txt" to the server, and the server will count the characters and send the count back to the client.

5. The client will display the received character count.


