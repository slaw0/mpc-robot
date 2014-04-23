clc

al1_c_deg = 90;
al2_c_deg = 0;

x = 1;
y = 0;

al1_c = al1_c_deg * pi / 180;
al2_c = al2_c_deg * pi / 180;

[al1, al2, error] = invgeo(x, y, al1_c, al2_c, 1, 0.75);

al1_deg = al1 * 180 / pi
al2_deg = al2 * 180 / pi

x_test = 1 * cos(al1) + 0.75 * cos(al1 + al2)
y_test = 1 * sin(al1) + 0.75 * sin(al1 + al2)