set term x11 persist
set title "SHM"
set ylabel "theta (radians)"
set xlabel "time (s)"
plot filename using 1:2 with lines

