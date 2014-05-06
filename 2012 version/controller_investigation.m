clear
close all

I1 = 0.033;
T = 0.01;

seg1 = tf([0 0 I1],[1 0 0]);
Td = 4;
Tc = 1/200;
Ap = 10;
D1 = tf([Td 0],[Tc 1]);
P1 = tf(Ap, 1);
cntrl1 = parallel(tf(1,1), D1);
cntrl1 = series(P1, cntrl1);
open1 = series(cntrl1, seg1);
closed1 = feedback(open1, tf(1, 1));
closed1_d = c2d(closed1, T);

delay = 1;
delay_num = zeros(1, delay + 1);
delay_num(delay + 1) = 1;
delay_den = zeros(1, delay + 1);
delay_den(1) = 1;
delay_tf = tf(delay_num, delay_den, T);

cntrl1_d = c2d(cntrl1, T);
seg1_d = c2d(seg1, T);
open2_d = series(cntrl1_d, delay_tf);
open2_d = series(open2_d, seg1_d);
closed2_d = feedback(open2_d, tf(1, 1, T));


figure
margin(closed1_d)
figure
[p,z] = pzmap(closed1)
pzmap(closed1)
figure
step(closed1)
% figure
% margin(closed2_d);