set ns [new Simulator]

set nf [open out2.nam w]
set nf1 [open out2.tr w]

$ns namtrace-all $nf
$ns trace-all $nf1

proc finish { } {
    global ns nf nf1
    $ns flush-trace

    close $nf
    close $nf1
    exec nam out2.nam &
    exit 0
}

$ns at 700 "finish"

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]

$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n2 $n3 0.3Mb 100ms DropTail
$ns duplex-link $n3 $n4 0.5Mb 40ms DropTail
$ns duplex-link $n3 $n5 0.5Mb 30ms DropTail

set udp0 [new Agent/UDP]
$ns attach-agent $n1 $udp0

set tcp0 [new Agent/TCP]
$ns attach-agent $n0 $tcp0

set tcpsink [new Agent/TCPSink]
$ns attach-agent $n4 $tcpsink

$ns connect $tcp0 $tcpsink

set null0 [new Agent/Null]
$ns attach-agent $n5 $null0

$ns connect $udp0 $null0

set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0

set cbr0 [new Application/Traffic/CBR]
$cbr0 attach-agent $udp0

$ns at 0.1 "$cbr0 start"
$ns at 4.5 "$cbr0 stop"
$ns at 0.3 "$ftp0 start"
$ns at 6 "$ftp0 stop"

$ns run

