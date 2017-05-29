set term x11 persist
set title "Decay of U235"
plot "dualdecaydata.dat" using 1:2 title 'Particle A', \
     "dualdecaydata.dat" using 1:3 title 'Particle B'
