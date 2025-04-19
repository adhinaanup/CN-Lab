# Create simulator
set ns [new Simulator]

# Open trace and NAM files
set tracefile [open out.tr w]
set namfile [open out.nam w]
$ns trace-all $tracefile
$ns namtrace-all $namfile

# Configure nodes to use DSDV routing
$ns node-config -routingAgent DSDV

# Create nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]

# Create links between nodes
$ns duplex-link $n0 $n1 1Mb 10ms DropTail
$ns duplex-link $n1 $n2 1Mb 10ms DropTail

# Setup agents
set udp [new Agent/UDP]
$ns attach-agent $n0 $udp

set null [new Agent/Null]
$ns attach-agent $n2 $null

# Connect agents
$ns connect $udp $null

# Create traffic generator (CBR)
set cbr [new Application/Traffic/CBR]
$cbr set packetSize_ 500
$cbr set interval_ 1
$cbr attach-agent $udp

# Schedule events
$ns at 1.0 "$cbr start"
$ns at 4.0 "$cbr stop"
$ns at 5.0 "finish"

# Define finish procedure
proc finish {} {
    global ns tracefile namfile
    $ns flush-trace
    close $tracefile
    close $namfile
    puts "Simulation completed. Open NAM with: nam out.nam"
    exec nam out.nam &
    exit 0
}

# Run the simulation
$ns run
