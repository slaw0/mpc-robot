function [al1, al2, error] = invgeo(x, y, al1_c, al2_c, a1, a2)
    
    d = sqrt(x^2 + y^2);
    if ((d^2 > (a1^2 + a2^2)) | (d < (a1 - a2)))
        al1 = al1_c;
        al2 = al2_c;
        error = uint8(1);
        return;
    end
    
    cos_al2 = (x^2 + y^2 - a1^2 - a2^2) / (2 * a1 * a2);
    D = a1 + a2 * cos_al2;
    
    sin_al1_p = (D * y + x * sqrt(x^2 + y^2 - D^2)) / (x^2 + y^2);
    sin_al1_n = (D * y - x * sqrt(x^2 + y^2 - D^2)) / (x^2 + y^2);
    
    cos_al1_p = (D * x + y * sqrt(x^2 + y^2 - D^2)) / (x^2 + y^2);
    cos_al1_n = (D * x - y * sqrt(x^2 + y^2 - D^2)) / (x^2 + y^2);
    
    al1_1 = atan2(sin_al1_p, cos_al1_n);
    
    al1_2 = atan2(sin_al1_n, cos_al1_p);
    
<<<<<<< HEAD
    al1
    
    sin_al2 = 1/2/a2*(-x*cos(al1)^2+a2*cos(al1)*cos(al2)+a1*cos(al1)^3-(cos(al1)^2*(-x*cos(al1)-a2*cos(al2)+a1*cos(al1)^2+2*a2*cos(al1)^2*cos(al2))^2)^(1/2))/sin(al1)/cos(al1)^2
=======
    al2_p = acos(cos_al2);
    al2_n = -al2_p; 
    
    cos_al1_al2_1 = (x - a1 * cos(al1_1)) / a2;
    sin_al1_al2_1 = (y - a1 * sin(al1_1)) / a2;
    al1_al2_1 = atan2(sin_al1_al2_1, cos_al1_al2_1);
    al2_1 = al1_al2_1 - al1_1;
    
    cos_al1_al2_2 = (x - a1 * cos(al1_2)) / a2;
    sin_al1_al2_2 = (y - a1 * sin(al1_2)) / a2;
    al1_al2_2 = atan2(sin_al1_al2_2, cos_al1_al2_2);
    al2_2 = al1_al2_2 - al1_2;
    
    error = uint8(0);  
>>>>>>> ca23ad72d6e6b3b796b7279db9827fd9e79aeea7
end