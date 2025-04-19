
# 🔌 Linux Socket System Calls

Socket system calls are essential for network programming in Linux. They allow processes to communicate over a network using well-defined functions.

---

## 1. `socket()`
Creates a new socket and returns a file descriptor for it. This descriptor is used for subsequent socket-related system calls.  
**Syntax:**
```c
int socket(int domain, int type, int protocol);
```

---

## 2. `bind()`
Associates a socket with a local address (IP and port). Required for servers to listen on a specific address.  
**Syntax:**
```c
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
```

---

## 3. `connect()`
Connects the socket to the specified address. Typically used by clients to establish a connection with a server.  
**Syntax:**
```c
int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
```

---

## 4. `listen()`
Marks the socket as passive and ready to accept incoming connections.  
**Syntax:**
```c
int listen(int sockfd, int backlog);
```

---

## 5. `accept()`
Blocks and waits for an incoming connection. Returns a new socket descriptor connected to the client.  
**Syntax:**
```c
int accept(int sockfd, struct sockaddr *restrict addr, socklen_t *restrict addrlen);
```

---

## 6. `send()` / `sendto()`
Used to send messages or data.  
- `send()` is used for connection-oriented protocols (e.g., TCP).  
- `sendto()` is used for connectionless protocols (e.g., UDP).  
**Syntax:**
```c
int send(int sockfd, const void *buf, size_t len, int flags);
int sendto(int sockfd, const void *buf, size_t len, int flags,
           const struct sockaddr *dest_addr, socklen_t addrlen);
```

---

## 7. `recv()` / `recvfrom()`
Used to receive messages or data.  
- `recv()` is used for connection-oriented protocols.  
- `recvfrom()` is used for connectionless protocols.  
**Syntax:**
```c
int recv(int sockfd, void *buf, size_t len, int flags);
int recvfrom(int sockfd, void *restrict buf, size_t len, int flags,
             struct sockaddr *restrict src_addr, socklen_t *restrict addrlen);
```

---

## 8. `close()`
Closes the socket file descriptor once it is no longer needed.  
**Syntax:**
```c
int close(int fd);
```

---
