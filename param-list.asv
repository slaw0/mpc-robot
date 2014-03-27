%% MPC555 robot controller model parameter list
clear
clc

%% CAN communication parameters
init_1_message_frequency = 0.01;

init_1_message = uint8(1);
init_2_message = uint8(2);
init_ack_sync_message = uint8(20);
init_ack_async_message = uint8(21);

%% Incremental counter configuration parameters
incntr_max_val = uint32(2^24);
incntr_display_max_val = uint32(hex2dec('FFFF'));

%% Control parameters
DA_max = uint16(hex2dec('FFFF'));
motor_stopped_value = DA_max/2;
motor_positive_value = DA_max * 0.6;
motor_negative_value = DA_max * 0.4;

