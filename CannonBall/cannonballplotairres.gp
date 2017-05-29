set term x11 persist
set title "Cannonball Trajectories with air resistance"
set ylabel "y (m)"
set xlabel "x (m)"
plot "cannonballdata30ar.dat" using 1:2 title '30' with lines, \
     "cannonballdata35ar.dat" using 1:2 title '35' with lines, \
     "cannonballdata40ar.dat" using 1:2 title '40' with lines, \
     "cannonballdata45ar.dat" using 1:2 title '45' with lines, \
     "cannonballdata50ar.dat" using 1:2 title '50' with lines, \
     "cannonballdata55ar.dat" using 1:2 title '55' with lines

