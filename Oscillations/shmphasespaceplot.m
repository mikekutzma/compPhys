data05 = load('shmdata_phasespace_05.dat');
theta05 = data05(:,2);
w05 = data05(:,3);
subplot(221);
comet(theta05,w05,0.001);
subplot(222);
h = polar([-pi pi], [0 10]);
comet(h,theta05,9.81);
