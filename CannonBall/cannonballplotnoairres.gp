set term x11 persist
set title "Cannonball Trajectories"
set ylabel "y (m)"
set xlabel "x (m)"
plot "cannonballdata30.dat" using 1:2 title '30' with lines, \
     "cannonballdata35.dat" using 1:2 title '35' with lines, \
     "cannonballdata40.dat" using 1:2 title '40' with lines, \
     "cannonballdata45.dat" using 1:2 title '45' with lines, \
     "cannonballdata50.dat" using 1:2 title '50' with lines, \
     "cannonballdata55.dat" using 1:2 title '55' with lines

