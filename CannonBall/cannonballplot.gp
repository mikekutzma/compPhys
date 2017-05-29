set term x11 persist
set title "Cannonball Trajectories with air resistance and air density"
set ylabel "y (m)"
set xlabel "x (m)"
plot "cannonballdata30ard.dat" using 1:2 title '30' with lines, \
     "cannonballdata35ard.dat" using 1:2 title '35' with lines, \
     "cannonballdata40ard.dat" using 1:2 title '40' with lines, \
     "cannonballdata45ard.dat" using 1:2 title '45' with lines, \
     "cannonballdata50ard.dat" using 1:2 title '50' with lines, \
     "cannonballdata55ard.dat" using 1:2 title '55' with lines

