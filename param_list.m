%% MPC555 robot controller model parameter list
clear
clc

fundamental_sample_time = 0.01;
%% CAN communication parameters
init_1_message_frequency = 0.01;

init_1_message = uint8(1);
init_2_message = uint8(2);
init_ack_sync_message = uint8(20);
init_ack_async_message = uint8(21);

%% Incremental counter configuration parameters
incntr_max_val = uint32(2^24);
incntr_display_max_val = uint32(hex2dec('FFFF'));
incntr_out_value_gain = single(double(incntr_max_val) / double(incntr_display_max_val));
increments_per_half_turn = uint32(hex2dec('400000'));

%% Control parameters
DA_max = uint16(hex2dec('FFFF'));
motor_stopped_value = DA_max / 2;
motor_positive_value = DA_max * 0.6;
motor_negative_value = DA_max * 0.4;
trajectory_time = 2; % desired trajectory running time in seconds

%% Robot parameters
a1 = 1000; % Segment 1 length
a2 = 750; % segment 2 length