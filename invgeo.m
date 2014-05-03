function [al1, al2, error] = invgeo(x, y, al1_c, al2_c, a1, a2)
    error = 0;
    
    cos_al2 = (x^2 + y^2 - a1^2 - a2^2) / (2 * a1 * a2);
    D = a1 + a2 * cos_al2;
    
    sin_al1_p = (D * y + x * sqrt(x^2 + y^2 - D^2)) / (x^2 + y^2);
    sin_al1_n = (D * y - x * sqrt(x^2 + y^2 - D^2)) / (x^2 + y^2);
    
    cos_al1_p = (D * x + y * sqrt(x^2 + y^2 - D^2)) / (x^2 + y^2);
    cos_al1_n = (D * x - y * sqrt(x^2 + y^2 - D^2)) / (x^2 + y^2);
    
    al1_1 = atan2(sin_al1_p, cos_al1_n);
    
    al1_2 = atan2(sin_al1_n, cos_al1_p);
    
    al2_p = acos(cos_al2);
    al2_n = -al2_p; 
    
    if ( x == (a1 * cos_al1_n + a2 * cos(al1_1 + al2_p)))
        al2_1 = al2_p;
        al2_2 = al2_n;
    else 
       al2_1 = al2_n;
       al2_2 = al2_p;
    end
    
    if (abs(al1_c - al1_1) < abs(al1_c - al1_2))
        al1 = al1_1;
        al2 = al2_1;
    else
        al1 = al1_2;
        al2 = al2_2;
    end
        
end