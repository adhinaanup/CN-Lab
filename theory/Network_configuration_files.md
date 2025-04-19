---

# 🛠️ Network Configuration Files

To store IP addresses and other related settings, Linux uses a separate configuration file for each network interface. These files are typically stored in the `/etc/sysconfig/network-scripts` directory. The important Linux network configuration files are:

---

## 1. `/etc/hosts`
This file is used to map the hostname with an IP address. Once hostname and IP address are mapped, the hostname can be used to access services on the destination IP address.  
A hostname can be mapped in two ways:
- Through the DNS server
- Through the `/etc/hosts` file

---

## 2. `/etc/resolv.conf`
Specifies the IP addresses of DNS servers and the search domain for domain name resolution.

---

## 3. `/etc/sysconfig/network`
This file specifies routing and host information for all network interfaces.

---

## 4. `/etc/nsswitch.conf`
This file controls how various system lookups are carried out. One of its main roles is determining how the network is resolved (e.g., files, DNS, etc.).

---
