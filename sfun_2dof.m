function sfun_2dof(block)

setup(block);

function setup(block)
    
    % A folytonos idej? állapotváltozók: [q1, q1p, q2, q2p]
    block.NumContStates = 4;
    % A bemenetek: [tau1, tau2]
    block.NumInputPorts = 2;
    % A kimenetek: [q1, q1p, q2, q2p]
    block.NumOutputPorts = 4;
    % Dialógus paraméterek: [m1, l1, m2, l2, I1, I2]
    block.NumDialogPrms = 6;
    
    block.InputPort(1).DirectFeedthrough=0;
    block.InputPort(1).Dimensions=1;
    block.InputPort(1).SamplingMode='Sample';
    
    block.InputPort(2).DirectFeedthrough=0;
    block.InputPort(2).Dimensions=1;
    block.InputPort(2).SamplingMode='Sample';
    
    block.OutputPort(1).Dimensions=1;
    block.OutputPort(1).SamplingMode='Sample';
    
    block.OutputPort(2).Dimensions=1;
    block.OutputPort(2).SamplingMode='Sample';

    block.OutputPort(3).SamplingMode='Sample';
    block.OutputPort(3).Dimensions=1;
    
    block.OutputPort(4).SamplingMode='Sample';
    block.OutputPort(4).Dimensions=1;
    
    % Folytonos idej? a rendszer
    block.SampleTimes = [0 0];
    
    % Callback-függvények regisztrálása
    block.RegBlockMethod('Derivatives',@der);
    block.RegBlockMethod('Outputs',@outs);
    block.RegBlockMethod('PostPropagationSetup',@PostProp);
    block.RegBlockMethod('InitializeConditions',@init);
    
function PostProp(block)
    block.NumDworks = 1;
    block.Dwork(1).Dimensions = 6;
    block.Dwork(1).Name = 'Rprms';
    block.Dwork(1).DatatypeID = 0;
    block.Dwork(1).Complexity = 'real';
    
function init(block)
    m1 = block.DialogPrm(1).Data;
    l1 = block.DialogPrm(2).Data;
    m2 = block.DialogPrm(3).Data;
    l2 = block.DialogPrm(4).Data;
    I1 = block.DialogPrm(5).Data;
    I2 = block.DialogPrm(6).Data;
    
  
    % A dwork vektor: [m1 l1 m2 l2 I1 I2]
    block.Dwork(1).Data = [m1 l1 m2 l2 I1 I2];
    % Állapotváltozók inicializálása
    block.ContStates.Data = [0 0 0 0];
    
function der(block)
    m1 = block.Dwork(1).Data(1);
    l1 = block.Dwork(1).Data(2);
    m2 = block.Dwork(1).Data(3);
    l2 = block.Dwork(1).Data(4);
    I1 = block.Dwork(1).Data(5);
    I2 = block.Dwork(1).Data(6);
    
    tau1 = block.InputPort(1).Data;
    tau2 = block.InputPort(2).Data;
    
    q1 = block.ContStates.Data(1);
    q1p = block.ContStates.Data(2);
    q2 = block.ContStates.Data(3);
    q2p = block.ContStates.Data(4);
    
    D11 = l1^2*m1 + m2*(l1^2 + 2*l1*l2*cos(q2)+l2^2) + I1 + I2;
    D12 = m2*l2*(l1*cos(q2)+l2)+I2;
    D22 = m2*l2^2+I1;
    D112 = -m2*l1*l2*sin(q2);
    D122 = D112;
    
    block.Derivatives.Data = [q1p...
                             -(2*D22*D112*q1p*q2p+D22*D122*q2p^2-D22*tau1+D112*q1p^2*D12+tau2*D12)/(-D12^2+D11*D22)...
                             q2p...
                             (2*D12*D112*q1p*q2p+D12*D122*q2p^2-D12*tau1+D11*D112*q1p^2+D11*tau2)/(-D12^2+D11*D22)];
       
function outs(block)
    block.OutputPort(1).Data = block.ContStates.Data(1);
    block.OutputPort(2).Data = block.ContStates.Data(2);
    block.OutputPort(3).Data = block.ContStates.Data(3);
    block.OutputPort(4).Data = block.ContStates.Data(4);