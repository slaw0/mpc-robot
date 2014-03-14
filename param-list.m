%% MPC555 robot controller model parameter list
clear
clc

%% CAN communication parameters
init_1_message_frequency = 0.01;

init_1_message = uint8(1);
init_2_message = uint8(2);
init_ack_sync_message = uint8(20);
init_ack_async_message = uint8(21);