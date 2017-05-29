set term x11 persist
set title "Bicycle velocity under constant power"
set ylabel "velocity (m/s)"
set xlabel "time (s)"
plot "bikevelocitydata.dat" using 1:2 title 'No Air Resistance' with lines, \
     "bikevelocitydata.dat" using 1:3 title 'Air Resistance' with lines

