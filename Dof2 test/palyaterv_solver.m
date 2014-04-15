clear all
syms D11 D12 D22 D112 D122 tau1 tau2 q1pp q2pp q1p q2p;
[q1pp, q2pp] = solve('D11*q1pp + D12*q2pp + 2*D112*q1p*q2p + D122*q2p^2 = tau1',...
    'D12*q1pp + D22 * q2pp - D112*q1p^2  = tau2', 'q1pp', 'q2pp')