set term x11 persist
set title 'FD = 1.0'
set ylabel 'w'
set xlabel '\theta'
plot filename using 2:3 with lines
