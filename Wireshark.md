
# Wireshark - Theory

Wireshark is a free and open-source packet analyzer. It is used for network troubleshooting, analysis, software and communications protocol development.  
It can parse and display the fields, along with their meanings as specified by different networking protocols.  
Wireshark uses **pcap** to capture packets, so it can only capture packets on the types of networks that pcap supports.  
Wireshark can color packets based on rules that match particular fields in packets, to help the user identify the types of traffic at a glance.

---

## Filters

Wireshark shares a powerful filter engine that helps remove the noise from a packet trace and lets you see only the packets that interest you.  
If a packet meets the requirements expressed in your filter, then it is displayed in the list of packets.  

Display filters let you:
- Compare the fields within a protocol against a specific value  
- Compare fields against fields  
- Check the existence of specified fields or protocols  

---

## Flow Graph

The **Flow Graph** window shows connections between hosts.  
It displays the packet time, direction, ports, and comments for each captured connection.  
You can filter all connections by:
- ICMP Flows  
- ICMPv6 Flows  
- UIM Flows  
- TCP Flows  

Flow Graph window is used for showing multiple different topics.  
Each vertical line represents the specific host, which you can see at the top of the window.  
The numbers in each row at the very left of the window represent the time packet.  
The numbers at both ends of each arrow between hosts represent the port numbers.

---

## Statistics

Wireshark provides a wide range of network statistics.  
These statistics range from general information about the loaded capture file (like the number of captured packets),  
to statistics about specific protocols (e.g., statistics about the number of HTTP requests and responses captured).  

General statistics involve:
- Summary about the capture file (packet counts, captured time period)
- Protocol Hierarchy of the captured packets
- Conversations like traffic between specific Ethernet/IP addresses, etc.

---

## Protocol Hierarchy

This is a tree of all the protocols in the capture.  
Each row contains the statistical values of one protocol.  

Two of the columns:
- **Percent Packets**
- **Percent Bytes**

These serve double duty as bar graphs.  
If a display filter is set, it will be shown at the bottom.

