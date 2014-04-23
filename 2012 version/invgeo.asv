function [al1, al2, error] = invgeo(x, y, al1_c, al2_c, a1, a2)
    error = 0;
    
    cos_al2 = (x^2 + y^2 - a1^2 - a2^2) / (2 * a1 * a2);
    D = a1 + a2 * cos_al2;
    
    sin_al1_p = (D * y + x * sqrt(x^2 + y^2 - D^2)) / (x^2 + y^2);
    sin_al1_n = (D * y - x * sqrt(x^2 + y^2 - D^2)) / (x^2 + y^2);
    
    cos_al1_p = (D * x + y * sqrt(x^2 + y^2 - D^2)) / (x^2 + y^2);
    cos_al1_n = (D * x - y * sqrt(x^2 + y^2 - D^2)) / (x^2 + y^2);
    
    al1_1 = atan2(sin_al1_p, cos_al1_n);
    al1_1_deg = al1_1 * 180 / pi;
    
    al1_2 = atan2(sin_al1_n, cos_al1_p);
    al1_2_deg = al1_2 * 180 / pi;
    
    al1
    
    sin_al2 = 1/2/a2*(-x*cos(al1)^2+a2*cos(al1)*cos(al2)+a1*cos(al1)^3-(cos(al1)^2*(-x*cos(al1)-a2*cos(al2)+a1*cos(al1)^2+2*a2*cos(al1)^2*cos(al2))^2)^(1/2))/sin(al1)/cos(al1)^2
end