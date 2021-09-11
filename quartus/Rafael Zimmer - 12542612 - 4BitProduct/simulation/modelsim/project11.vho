-- Copyright (C) 2020  Intel Corporation. All rights reserved.
-- Your use of Intel Corporation's design tools, logic functions 
-- and other software and tools, and any partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Intel Program License 
-- Subscription Agreement, the Intel Quartus Prime License Agreement,
-- the Intel FPGA IP License Agreement, or other applicable license
-- agreement, including, without limitation, that your use is for
-- the sole purpose of programming logic devices manufactured by
-- Intel and sold by Intel or its authorized distributors.  Please
-- refer to the applicable agreement for further details, at
-- https://fpgasoftware.intel.com/eula.

-- VENDOR "Altera"
-- PROGRAM "Quartus Prime"
-- VERSION "Version 20.1.1 Build 720 11/11/2020 SJ Lite Edition"

-- DATE "07/14/2021 01:45:07"

-- 
-- Device: Altera 5CEFA4F23C7 Package FBGA484
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY ALTERA_LNSIM;
LIBRARY CYCLONEV;
LIBRARY IEEE;
USE ALTERA_LNSIM.ALTERA_LNSIM_COMPONENTS.ALL;
USE CYCLONEV.CYCLONEV_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	project11 IS
    PORT (
	P0 : OUT std_logic;
	X0 : IN std_logic;
	Y3 : IN std_logic;
	X1 : IN std_logic;
	X2 : IN std_logic;
	X3 : IN std_logic;
	Y2 : IN std_logic;
	Y1 : IN std_logic;
	Y0 : IN std_logic;
	P1 : OUT std_logic;
	P2 : OUT std_logic;
	P3 : OUT std_logic;
	P4 : OUT std_logic;
	P5 : OUT std_logic;
	P6 : OUT std_logic;
	P7 : OUT std_logic
	);
END project11;

-- Design Ports Information
-- P0	=>  Location: PIN_N16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- P1	=>  Location: PIN_L17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- P2	=>  Location: PIN_M16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- P3	=>  Location: PIN_N20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- P4	=>  Location: PIN_N21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- P5	=>  Location: PIN_K21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- P6	=>  Location: PIN_K17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- P7	=>  Location: PIN_M20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- X0	=>  Location: PIN_K22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Y0	=>  Location: PIN_M21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- X1	=>  Location: PIN_M18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Y1	=>  Location: PIN_L22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Y2	=>  Location: PIN_L19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Y3	=>  Location: PIN_L18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- X2	=>  Location: PIN_N19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- X3	=>  Location: PIN_M22,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF project11 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_P0 : std_logic;
SIGNAL ww_X0 : std_logic;
SIGNAL ww_Y3 : std_logic;
SIGNAL ww_X1 : std_logic;
SIGNAL ww_X2 : std_logic;
SIGNAL ww_X3 : std_logic;
SIGNAL ww_Y2 : std_logic;
SIGNAL ww_Y1 : std_logic;
SIGNAL ww_Y0 : std_logic;
SIGNAL ww_P1 : std_logic;
SIGNAL ww_P2 : std_logic;
SIGNAL ww_P3 : std_logic;
SIGNAL ww_P4 : std_logic;
SIGNAL ww_P5 : std_logic;
SIGNAL ww_P6 : std_logic;
SIGNAL ww_P7 : std_logic;
SIGNAL \~QUARTUS_CREATED_GND~I_combout\ : std_logic;
SIGNAL \Y2~input_o\ : std_logic;
SIGNAL \X1~input_o\ : std_logic;
SIGNAL \X2~input_o\ : std_logic;
SIGNAL \Y3~input_o\ : std_logic;
SIGNAL \X3~input_o\ : std_logic;
SIGNAL \X0~input_o\ : std_logic;
SIGNAL \inst29|inst|inst1~combout\ : std_logic;
SIGNAL \Y1~input_o\ : std_logic;
SIGNAL \inst30|inst|inst7~0_combout\ : std_logic;
SIGNAL \inst31|inst|inst~combout\ : std_logic;
SIGNAL \inst30|inst|inst4~0_combout\ : std_logic;
SIGNAL \inst32|inst|inst7~0_combout\ : std_logic;
SIGNAL \inst29|inst|inst7~combout\ : std_logic;
SIGNAL \inst33|inst|inst1~0_combout\ : std_logic;
SIGNAL \inst33|inst|inst1~combout\ : std_logic;
SIGNAL \inst33|inst|inst7~0_combout\ : std_logic;
SIGNAL \inst32|inst|inst1~combout\ : std_logic;
SIGNAL \inst26|inst|inst1~combout\ : std_logic;
SIGNAL \Y0~input_o\ : std_logic;
SIGNAL \inst36|inst|inst4~0_combout\ : std_logic;
SIGNAL \inst36|inst|inst7~0_combout\ : std_logic;
SIGNAL \inst36|inst|inst7~1_combout\ : std_logic;
SIGNAL \inst38|inst|inst7~0_combout\ : std_logic;
SIGNAL \inst38|inst|inst1~combout\ : std_logic;
SIGNAL \inst37|inst4~combout\ : std_logic;
SIGNAL \inst37|inst|inst1~combout\ : std_logic;
SIGNAL \inst30|inst|inst1~combout\ : std_logic;
SIGNAL \inst36|inst|inst1~combout\ : std_logic;
SIGNAL \inst35|inst|inst1~combout\ : std_logic;
SIGNAL \inst28|inst|inst1~combout\ : std_logic;
SIGNAL \inst27|inst|inst1~combout\ : std_logic;
SIGNAL \inst|inst4~combout\ : std_logic;
SIGNAL \ALT_INV_X3~input_o\ : std_logic;
SIGNAL \ALT_INV_X2~input_o\ : std_logic;
SIGNAL \ALT_INV_Y3~input_o\ : std_logic;
SIGNAL \ALT_INV_Y2~input_o\ : std_logic;
SIGNAL \ALT_INV_Y1~input_o\ : std_logic;
SIGNAL \ALT_INV_X1~input_o\ : std_logic;
SIGNAL \ALT_INV_Y0~input_o\ : std_logic;
SIGNAL \ALT_INV_X0~input_o\ : std_logic;
SIGNAL \inst30|inst|ALT_INV_inst1~combout\ : std_logic;
SIGNAL \inst37|ALT_INV_inst4~combout\ : std_logic;
SIGNAL \inst33|inst|ALT_INV_inst1~combout\ : std_logic;
SIGNAL \inst33|inst|ALT_INV_inst1~0_combout\ : std_logic;
SIGNAL \inst36|inst|ALT_INV_inst7~1_combout\ : std_logic;
SIGNAL \inst36|inst|ALT_INV_inst4~0_combout\ : std_logic;
SIGNAL \inst32|inst|ALT_INV_inst1~combout\ : std_logic;
SIGNAL \inst36|inst|ALT_INV_inst7~0_combout\ : std_logic;
SIGNAL \inst26|inst|ALT_INV_inst1~combout\ : std_logic;
SIGNAL \inst33|inst|ALT_INV_inst7~0_combout\ : std_logic;
SIGNAL \inst32|inst|ALT_INV_inst7~0_combout\ : std_logic;
SIGNAL \inst30|inst|ALT_INV_inst4~0_combout\ : std_logic;
SIGNAL \inst29|inst|ALT_INV_inst1~combout\ : std_logic;
SIGNAL \inst30|inst|ALT_INV_inst7~0_combout\ : std_logic;
SIGNAL \inst31|inst|ALT_INV_inst~combout\ : std_logic;
SIGNAL \inst29|inst|ALT_INV_inst7~combout\ : std_logic;

BEGIN

P0 <= ww_P0;
ww_X0 <= X0;
ww_Y3 <= Y3;
ww_X1 <= X1;
ww_X2 <= X2;
ww_X3 <= X3;
ww_Y2 <= Y2;
ww_Y1 <= Y1;
ww_Y0 <= Y0;
P1 <= ww_P1;
P2 <= ww_P2;
P3 <= ww_P3;
P4 <= ww_P4;
P5 <= ww_P5;
P6 <= ww_P6;
P7 <= ww_P7;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
\ALT_INV_X3~input_o\ <= NOT \X3~input_o\;
\ALT_INV_X2~input_o\ <= NOT \X2~input_o\;
\ALT_INV_Y3~input_o\ <= NOT \Y3~input_o\;
\ALT_INV_Y2~input_o\ <= NOT \Y2~input_o\;
\ALT_INV_Y1~input_o\ <= NOT \Y1~input_o\;
\ALT_INV_X1~input_o\ <= NOT \X1~input_o\;
\ALT_INV_Y0~input_o\ <= NOT \Y0~input_o\;
\ALT_INV_X0~input_o\ <= NOT \X0~input_o\;
\inst30|inst|ALT_INV_inst1~combout\ <= NOT \inst30|inst|inst1~combout\;
\inst37|ALT_INV_inst4~combout\ <= NOT \inst37|inst4~combout\;
\inst33|inst|ALT_INV_inst1~combout\ <= NOT \inst33|inst|inst1~combout\;
\inst33|inst|ALT_INV_inst1~0_combout\ <= NOT \inst33|inst|inst1~0_combout\;
\inst36|inst|ALT_INV_inst7~1_combout\ <= NOT \inst36|inst|inst7~1_combout\;
\inst36|inst|ALT_INV_inst4~0_combout\ <= NOT \inst36|inst|inst4~0_combout\;
\inst32|inst|ALT_INV_inst1~combout\ <= NOT \inst32|inst|inst1~combout\;
\inst36|inst|ALT_INV_inst7~0_combout\ <= NOT \inst36|inst|inst7~0_combout\;
\inst26|inst|ALT_INV_inst1~combout\ <= NOT \inst26|inst|inst1~combout\;
\inst33|inst|ALT_INV_inst7~0_combout\ <= NOT \inst33|inst|inst7~0_combout\;
\inst32|inst|ALT_INV_inst7~0_combout\ <= NOT \inst32|inst|inst7~0_combout\;
\inst30|inst|ALT_INV_inst4~0_combout\ <= NOT \inst30|inst|inst4~0_combout\;
\inst29|inst|ALT_INV_inst1~combout\ <= NOT \inst29|inst|inst1~combout\;
\inst30|inst|ALT_INV_inst7~0_combout\ <= NOT \inst30|inst|inst7~0_combout\;
\inst31|inst|ALT_INV_inst~combout\ <= NOT \inst31|inst|inst~combout\;
\inst29|inst|ALT_INV_inst7~combout\ <= NOT \inst29|inst|inst7~combout\;

-- Location: IOOBUF_X54_Y18_N45
\P0~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst38|inst|inst7~0_combout\,
	devoe => ww_devoe,
	o => ww_P0);

-- Location: IOOBUF_X54_Y20_N22
\P1~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst38|inst|inst1~combout\,
	devoe => ww_devoe,
	o => ww_P1);

-- Location: IOOBUF_X54_Y18_N62
\P2~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst37|inst|inst1~combout\,
	devoe => ww_devoe,
	o => ww_P2);

-- Location: IOOBUF_X54_Y18_N79
\P3~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst36|inst|inst1~combout\,
	devoe => ww_devoe,
	o => ww_P3);

-- Location: IOOBUF_X54_Y18_N96
\P4~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst35|inst|inst1~combout\,
	devoe => ww_devoe,
	o => ww_P4);

-- Location: IOOBUF_X54_Y21_N39
\P5~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst28|inst|inst1~combout\,
	devoe => ww_devoe,
	o => ww_P5);

-- Location: IOOBUF_X54_Y20_N5
\P6~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst27|inst|inst1~combout\,
	devoe => ww_devoe,
	o => ww_P6);

-- Location: IOOBUF_X54_Y20_N39
\P7~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst|inst4~combout\,
	devoe => ww_devoe,
	o => ww_P7);

-- Location: IOIBUF_X54_Y21_N4
\Y2~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Y2,
	o => \Y2~input_o\);

-- Location: IOIBUF_X54_Y19_N21
\X1~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_X1,
	o => \X1~input_o\);

-- Location: IOIBUF_X54_Y19_N4
\X2~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_X2,
	o => \X2~input_o\);

-- Location: IOIBUF_X54_Y21_N21
\Y3~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Y3,
	o => \Y3~input_o\);

-- Location: IOIBUF_X54_Y19_N38
\X3~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_X3,
	o => \X3~input_o\);

-- Location: IOIBUF_X54_Y21_N55
\X0~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_X0,
	o => \X0~input_o\);

-- Location: MLABCELL_X49_Y22_N48
\inst29|inst|inst1\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst29|inst|inst1~combout\ = ( \X3~input_o\ & ( \X0~input_o\ & ( (!\Y2~input_o\ & (((\Y3~input_o\)))) # (\Y2~input_o\ & (!\X1~input_o\ $ (((!\Y3~input_o\) # (\X2~input_o\))))) ) ) ) # ( !\X3~input_o\ & ( \X0~input_o\ & ( (!\Y2~input_o\ & 
-- (((\Y3~input_o\)))) # (\Y2~input_o\ & ((!\X1~input_o\ & ((\Y3~input_o\))) # (\X1~input_o\ & ((!\Y3~input_o\) # (\X2~input_o\))))) ) ) ) # ( \X3~input_o\ & ( !\X0~input_o\ & ( (\Y2~input_o\ & (!\X1~input_o\ $ (((!\X2~input_o\) # (!\Y3~input_o\))))) ) ) ) # 
-- ( !\X3~input_o\ & ( !\X0~input_o\ & ( (\Y2~input_o\ & (\X1~input_o\ & ((!\X2~input_o\) # (!\Y3~input_o\)))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0001000100010000000100010001010000010001111011110001000111101011",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_Y2~input_o\,
	datab => \ALT_INV_X1~input_o\,
	datac => \ALT_INV_X2~input_o\,
	datad => \ALT_INV_Y3~input_o\,
	datae => \ALT_INV_X3~input_o\,
	dataf => \ALT_INV_X0~input_o\,
	combout => \inst29|inst|inst1~combout\);

-- Location: IOIBUF_X54_Y19_N55
\Y1~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Y1,
	o => \Y1~input_o\);

-- Location: MLABCELL_X49_Y22_N42
\inst30|inst|inst7~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst30|inst|inst7~0_combout\ = ( \Y3~input_o\ & ( (\Y1~input_o\ & (((\X1~input_o\ & \X3~input_o\)) # (\X2~input_o\))) ) ) # ( !\Y3~input_o\ & ( (\X2~input_o\ & \Y1~input_o\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000001010101000000000101010100000000010101110000000001010111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_X2~input_o\,
	datab => \ALT_INV_X1~input_o\,
	datac => \ALT_INV_X3~input_o\,
	datad => \ALT_INV_Y1~input_o\,
	dataf => \ALT_INV_Y3~input_o\,
	combout => \inst30|inst|inst7~0_combout\);

-- Location: MLABCELL_X49_Y22_N36
\inst31|inst|inst\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst31|inst|inst~combout\ = ( \X3~input_o\ & ( \X0~input_o\ & ( (\Y2~input_o\ & ((!\Y3~input_o\) # ((!\X1~input_o\ & !\X2~input_o\)))) ) ) ) # ( !\X3~input_o\ & ( \X0~input_o\ & ( (\Y2~input_o\ & ((!\X1~input_o\) # (!\Y3~input_o\))) ) ) ) # ( 
-- \X3~input_o\ & ( !\X0~input_o\ & ( (\Y2~input_o\ & (\X1~input_o\ & (\X2~input_o\ & \Y3~input_o\))) ) ) ) # ( !\X3~input_o\ & ( !\X0~input_o\ & ( (\Y2~input_o\ & (\X1~input_o\ & (\X2~input_o\ & \Y3~input_o\))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000001000000000000000101010101010001000101010101000000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_Y2~input_o\,
	datab => \ALT_INV_X1~input_o\,
	datac => \ALT_INV_X2~input_o\,
	datad => \ALT_INV_Y3~input_o\,
	datae => \ALT_INV_X3~input_o\,
	dataf => \ALT_INV_X0~input_o\,
	combout => \inst31|inst|inst~combout\);

-- Location: MLABCELL_X49_Y22_N24
\inst30|inst|inst4~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst30|inst|inst4~0_combout\ = ( \X3~input_o\ & ( \Y3~input_o\ & ( (\X1~input_o\ & (\X2~input_o\ & \Y1~input_o\)) ) ) ) # ( \X3~input_o\ & ( !\Y3~input_o\ & ( (\Y2~input_o\ & (\X2~input_o\ & \Y1~input_o\)) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000010100000000000000000000000000000011",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_Y2~input_o\,
	datab => \ALT_INV_X1~input_o\,
	datac => \ALT_INV_X2~input_o\,
	datad => \ALT_INV_Y1~input_o\,
	datae => \ALT_INV_X3~input_o\,
	dataf => \ALT_INV_Y3~input_o\,
	combout => \inst30|inst|inst4~0_combout\);

-- Location: MLABCELL_X49_Y22_N0
\inst32|inst|inst7~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst32|inst|inst7~0_combout\ = ( \Y1~input_o\ & ( \inst30|inst|inst4~0_combout\ & ( (\X1~input_o\) # (\inst31|inst|inst~combout\) ) ) ) # ( !\Y1~input_o\ & ( \inst30|inst|inst4~0_combout\ & ( \inst31|inst|inst~combout\ ) ) ) # ( \Y1~input_o\ & ( 
-- !\inst30|inst|inst4~0_combout\ & ( (!\inst31|inst|inst~combout\ & (\inst29|inst|inst1~combout\ & (\inst30|inst|inst7~0_combout\ & \X1~input_o\))) # (\inst31|inst|inst~combout\ & (((\inst29|inst|inst1~combout\ & \inst30|inst|inst7~0_combout\)) # 
-- (\X1~input_o\))) ) ) ) # ( !\Y1~input_o\ & ( !\inst30|inst|inst4~0_combout\ & ( (\inst29|inst|inst1~combout\ & (\inst30|inst|inst7~0_combout\ & \inst31|inst|inst~combout\)) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000100000001000000010001111100001111000011110000111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst29|inst|ALT_INV_inst1~combout\,
	datab => \inst30|inst|ALT_INV_inst7~0_combout\,
	datac => \inst31|inst|ALT_INV_inst~combout\,
	datad => \ALT_INV_X1~input_o\,
	datae => \ALT_INV_Y1~input_o\,
	dataf => \inst30|inst|ALT_INV_inst4~0_combout\,
	combout => \inst32|inst|inst7~0_combout\);

-- Location: MLABCELL_X49_Y22_N30
\inst29|inst|inst7\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst29|inst|inst7~combout\ = ( \X3~input_o\ & ( \X0~input_o\ & ( (\Y2~input_o\ & (\Y3~input_o\ & ((\X2~input_o\) # (\X1~input_o\)))) ) ) ) # ( !\X3~input_o\ & ( \X0~input_o\ & ( (\Y2~input_o\ & (\X1~input_o\ & \Y3~input_o\)) ) ) ) # ( \X3~input_o\ & ( 
-- !\X0~input_o\ & ( (\Y2~input_o\ & (\X1~input_o\ & (\X2~input_o\ & \Y3~input_o\))) ) ) ) # ( !\X3~input_o\ & ( !\X0~input_o\ & ( (\Y2~input_o\ & (\X1~input_o\ & (\X2~input_o\ & \Y3~input_o\))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000001000000000000000100000000000100010000000000010101",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_Y2~input_o\,
	datab => \ALT_INV_X1~input_o\,
	datac => \ALT_INV_X2~input_o\,
	datad => \ALT_INV_Y3~input_o\,
	datae => \ALT_INV_X3~input_o\,
	dataf => \ALT_INV_X0~input_o\,
	combout => \inst29|inst|inst7~combout\);

-- Location: LABCELL_X50_Y22_N33
\inst33|inst|inst1~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst33|inst|inst1~0_combout\ = ( \inst29|inst|inst7~combout\ & ( (\X0~input_o\ & (!\Y2~input_o\ $ (!\Y1~input_o\))) ) ) # ( !\inst29|inst|inst7~combout\ & ( (\X0~input_o\ & \Y1~input_o\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000001100000011000000110000001100010010000100100001001000010010",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_Y2~input_o\,
	datab => \ALT_INV_X0~input_o\,
	datac => \ALT_INV_Y1~input_o\,
	dataf => \inst29|inst|ALT_INV_inst7~combout\,
	combout => \inst33|inst|inst1~0_combout\);

-- Location: LABCELL_X50_Y22_N18
\inst33|inst|inst1\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst33|inst|inst1~combout\ = ( \inst33|inst|inst1~0_combout\ & ( !\inst32|inst|inst7~0_combout\ ) ) # ( !\inst33|inst|inst1~0_combout\ & ( \inst32|inst|inst7~0_combout\ ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0011001100110011001100110011001111001100110011001100110011001100",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \inst32|inst|ALT_INV_inst7~0_combout\,
	dataf => \inst33|inst|ALT_INV_inst1~0_combout\,
	combout => \inst33|inst|inst1~combout\);

-- Location: LABCELL_X50_Y22_N30
\inst33|inst|inst7~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst33|inst|inst7~0_combout\ = ( \inst32|inst|inst7~0_combout\ & ( (\X0~input_o\ & (((\Y2~input_o\ & \inst29|inst|inst7~combout\)) # (\Y1~input_o\))) ) ) # ( !\inst32|inst|inst7~0_combout\ & ( (\Y2~input_o\ & (\X0~input_o\ & (\inst29|inst|inst7~combout\ 
-- & \Y1~input_o\))) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000001000000000000000100000001001100110000000100110011",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_Y2~input_o\,
	datab => \ALT_INV_X0~input_o\,
	datac => \inst29|inst|ALT_INV_inst7~combout\,
	datad => \ALT_INV_Y1~input_o\,
	dataf => \inst32|inst|ALT_INV_inst7~0_combout\,
	combout => \inst33|inst|inst7~0_combout\);

-- Location: MLABCELL_X49_Y22_N6
\inst32|inst|inst1\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst32|inst|inst1~combout\ = ( \Y1~input_o\ & ( \inst30|inst|inst4~0_combout\ & ( !\inst31|inst|inst~combout\ $ (\X1~input_o\) ) ) ) # ( !\Y1~input_o\ & ( \inst30|inst|inst4~0_combout\ & ( !\inst31|inst|inst~combout\ ) ) ) # ( \Y1~input_o\ & ( 
-- !\inst30|inst|inst4~0_combout\ & ( !\inst31|inst|inst~combout\ $ (!\X1~input_o\ $ (((\inst29|inst|inst1~combout\ & \inst30|inst|inst7~0_combout\)))) ) ) ) # ( !\Y1~input_o\ & ( !\inst30|inst|inst4~0_combout\ & ( !\inst31|inst|inst~combout\ $ 
-- (((!\inst29|inst|inst1~combout\) # (!\inst30|inst|inst7~0_combout\))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0001111000011110000111101110000111110000111100001111000000001111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst29|inst|ALT_INV_inst1~combout\,
	datab => \inst30|inst|ALT_INV_inst7~0_combout\,
	datac => \inst31|inst|ALT_INV_inst~combout\,
	datad => \ALT_INV_X1~input_o\,
	datae => \ALT_INV_Y1~input_o\,
	dataf => \inst30|inst|ALT_INV_inst4~0_combout\,
	combout => \inst32|inst|inst1~combout\);

-- Location: MLABCELL_X49_Y22_N45
\inst26|inst|inst1\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst26|inst|inst1~combout\ = ( \Y2~input_o\ & ( (!\Y3~input_o\ & (\X2~input_o\)) # (\Y3~input_o\ & (!\X1~input_o\ $ (((!\X2~input_o\) # (\X3~input_o\))))) ) ) # ( !\Y2~input_o\ & ( (\X1~input_o\ & \Y3~input_o\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000001100000011000000110000001101010110010100110101011001010011",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_X2~input_o\,
	datab => \ALT_INV_X1~input_o\,
	datac => \ALT_INV_Y3~input_o\,
	datad => \ALT_INV_X3~input_o\,
	dataf => \ALT_INV_Y2~input_o\,
	combout => \inst26|inst|inst1~combout\);

-- Location: IOIBUF_X54_Y20_N55
\Y0~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Y0,
	o => \Y0~input_o\);

-- Location: LABCELL_X50_Y22_N12
\inst36|inst|inst4~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst36|inst|inst4~0_combout\ = ( \Y1~input_o\ & ( \Y0~input_o\ & ( (\X3~input_o\ & (\X2~input_o\ & (!\inst29|inst|inst1~combout\ $ (\inst26|inst|inst1~combout\)))) ) ) ) # ( !\Y1~input_o\ & ( \Y0~input_o\ & ( (\inst29|inst|inst1~combout\ & (\X3~input_o\ 
-- & \X2~input_o\)) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000000000100010000000000100001",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst29|inst|ALT_INV_inst1~combout\,
	datab => \ALT_INV_X3~input_o\,
	datac => \inst26|inst|ALT_INV_inst1~combout\,
	datad => \ALT_INV_X2~input_o\,
	datae => \ALT_INV_Y1~input_o\,
	dataf => \ALT_INV_Y0~input_o\,
	combout => \inst36|inst|inst4~0_combout\);

-- Location: LABCELL_X50_Y22_N6
\inst36|inst|inst7~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst36|inst|inst7~0_combout\ = ( \Y1~input_o\ & ( \Y0~input_o\ & ( ((\X3~input_o\ & (!\inst29|inst|inst1~combout\ $ (!\inst26|inst|inst1~combout\)))) # (\X2~input_o\) ) ) ) # ( !\Y1~input_o\ & ( \Y0~input_o\ & ( ((\inst29|inst|inst1~combout\ & 
-- \X3~input_o\)) # (\X2~input_o\) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000010001111111110001001011111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst29|inst|ALT_INV_inst1~combout\,
	datab => \ALT_INV_X3~input_o\,
	datac => \inst26|inst|ALT_INV_inst1~combout\,
	datad => \ALT_INV_X2~input_o\,
	datae => \ALT_INV_Y1~input_o\,
	dataf => \ALT_INV_Y0~input_o\,
	combout => \inst36|inst|inst7~0_combout\);

-- Location: LABCELL_X50_Y22_N21
\inst36|inst|inst7~1\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst36|inst|inst7~1_combout\ = ( \inst36|inst|inst7~0_combout\ & ( (!\inst32|inst|inst1~combout\ & !\inst36|inst|inst4~0_combout\) ) ) # ( !\inst36|inst|inst7~0_combout\ & ( !\inst36|inst|inst4~0_combout\ ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "1111000011110000111100001111000010100000101000001010000010100000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst32|inst|ALT_INV_inst1~combout\,
	datac => \inst36|inst|ALT_INV_inst4~0_combout\,
	dataf => \inst36|inst|ALT_INV_inst7~0_combout\,
	combout => \inst36|inst|inst7~1_combout\);

-- Location: LABCELL_X50_Y22_N24
\inst38|inst|inst7~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst38|inst|inst7~0_combout\ = ( \X1~input_o\ & ( \X0~input_o\ & ( (!\inst33|inst|inst1~combout\ & (\Y0~input_o\ & ((!\inst36|inst|inst7~1_combout\) # (\inst33|inst|inst7~0_combout\)))) # (\inst33|inst|inst1~combout\ & (((\inst33|inst|inst7~0_combout\ & 
-- !\inst36|inst|inst7~1_combout\)) # (\Y0~input_o\))) ) ) ) # ( !\X1~input_o\ & ( \X0~input_o\ & ( (!\inst33|inst|inst7~0_combout\ & (\inst33|inst|inst1~combout\ & (!\inst36|inst|inst7~1_combout\ & \Y0~input_o\))) # (\inst33|inst|inst7~0_combout\ & 
-- (((\inst33|inst|inst1~combout\ & !\inst36|inst|inst7~1_combout\)) # (\Y0~input_o\))) ) ) ) # ( \X1~input_o\ & ( !\X0~input_o\ & ( (\inst33|inst|inst7~0_combout\ & ((!\inst33|inst|inst1~combout\ & (!\inst36|inst|inst7~1_combout\ & \Y0~input_o\)) # 
-- (\inst33|inst|inst1~combout\ & ((!\inst36|inst|inst7~1_combout\) # (\Y0~input_o\))))) ) ) ) # ( !\X1~input_o\ & ( !\X0~input_o\ & ( (\inst33|inst|inst1~combout\ & (\inst33|inst|inst7~0_combout\ & !\inst36|inst|inst7~1_combout\)) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0001000000010000000100000011000100010000011100110001000011110111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst33|inst|ALT_INV_inst1~combout\,
	datab => \inst33|inst|ALT_INV_inst7~0_combout\,
	datac => \inst36|inst|ALT_INV_inst7~1_combout\,
	datad => \ALT_INV_Y0~input_o\,
	datae => \ALT_INV_X1~input_o\,
	dataf => \ALT_INV_X0~input_o\,
	combout => \inst38|inst|inst7~0_combout\);

-- Location: LABCELL_X50_Y22_N0
\inst38|inst|inst1\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst38|inst|inst1~combout\ = ( \X1~input_o\ & ( \X0~input_o\ & ( !\inst33|inst|inst7~0_combout\ $ (((!\inst33|inst|inst1~combout\ & ((!\inst36|inst|inst7~1_combout\) # (!\Y0~input_o\))) # (\inst33|inst|inst1~combout\ & ((\Y0~input_o\) # 
-- (\inst36|inst|inst7~1_combout\))))) ) ) ) # ( !\X1~input_o\ & ( \X0~input_o\ & ( !\inst33|inst|inst7~0_combout\ $ (!\Y0~input_o\ $ (((\inst33|inst|inst1~combout\ & !\inst36|inst|inst7~1_combout\)))) ) ) ) # ( \X1~input_o\ & ( !\X0~input_o\ & ( 
-- !\inst33|inst|inst7~0_combout\ $ (((!\inst33|inst|inst1~combout\ & ((!\Y0~input_o\) # (\inst36|inst|inst7~1_combout\))) # (\inst33|inst|inst1~combout\ & (\inst36|inst|inst7~1_combout\ & !\Y0~input_o\)))) ) ) ) # ( !\X1~input_o\ & ( !\X0~input_o\ & ( 
-- !\inst33|inst|inst7~0_combout\ $ (((!\inst33|inst|inst1~combout\) # (\inst36|inst|inst7~1_combout\))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0110001101100011011000111100011001100011100111000110001100111001",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst33|inst|ALT_INV_inst1~combout\,
	datab => \inst33|inst|ALT_INV_inst7~0_combout\,
	datac => \inst36|inst|ALT_INV_inst7~1_combout\,
	datad => \ALT_INV_Y0~input_o\,
	datae => \ALT_INV_X1~input_o\,
	dataf => \ALT_INV_X0~input_o\,
	combout => \inst38|inst|inst1~combout\);

-- Location: LABCELL_X50_Y22_N36
\inst37|inst4\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst37|inst4~combout\ = ( \X1~input_o\ & ( \Y0~input_o\ ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000000000000001111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datae => \ALT_INV_X1~input_o\,
	dataf => \ALT_INV_Y0~input_o\,
	combout => \inst37|inst4~combout\);

-- Location: MLABCELL_X49_Y22_N12
\inst37|inst|inst1\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst37|inst|inst1~combout\ = ( \inst37|inst4~combout\ & ( \inst33|inst|inst1~0_combout\ & ( !\inst32|inst|inst7~0_combout\ $ (((!\inst36|inst|inst4~0_combout\ & ((!\inst36|inst|inst7~0_combout\) # (!\inst32|inst|inst1~combout\))))) ) ) ) # ( 
-- !\inst37|inst4~combout\ & ( \inst33|inst|inst1~0_combout\ & ( !\inst32|inst|inst7~0_combout\ $ ((((\inst36|inst|inst7~0_combout\ & \inst32|inst|inst1~combout\)) # (\inst36|inst|inst4~0_combout\))) ) ) ) # ( \inst37|inst4~combout\ & ( 
-- !\inst33|inst|inst1~0_combout\ & ( !\inst32|inst|inst7~0_combout\ $ ((((\inst36|inst|inst7~0_combout\ & \inst32|inst|inst1~combout\)) # (\inst36|inst|inst4~0_combout\))) ) ) ) # ( !\inst37|inst4~combout\ & ( !\inst33|inst|inst1~0_combout\ & ( 
-- !\inst32|inst|inst7~0_combout\ $ (((!\inst36|inst|inst4~0_combout\ & ((!\inst36|inst|inst7~0_combout\) # (!\inst32|inst|inst1~combout\))))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0001111011110000111000010000111111100001000011110001111011110000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst36|inst|ALT_INV_inst7~0_combout\,
	datab => \inst32|inst|ALT_INV_inst1~combout\,
	datac => \inst32|inst|ALT_INV_inst7~0_combout\,
	datad => \inst36|inst|ALT_INV_inst4~0_combout\,
	datae => \inst37|ALT_INV_inst4~combout\,
	dataf => \inst33|inst|ALT_INV_inst1~0_combout\,
	combout => \inst37|inst|inst1~combout\);

-- Location: LABCELL_X50_Y22_N42
\inst30|inst|inst1\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst30|inst|inst1~combout\ = ( \inst29|inst|inst1~combout\ & ( (!\Y1~input_o\) # (!\X2~input_o\ $ (((\X3~input_o\ & \inst26|inst|inst1~combout\)))) ) ) # ( !\inst29|inst|inst1~combout\ & ( (\Y1~input_o\ & (!\X2~input_o\ $ (((!\X3~input_o\) # 
-- (!\inst26|inst|inst1~combout\))))) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000001010110000000000101011011111111101010011111111110101001",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_X2~input_o\,
	datab => \ALT_INV_X3~input_o\,
	datac => \inst26|inst|ALT_INV_inst1~combout\,
	datad => \ALT_INV_Y1~input_o\,
	dataf => \inst29|inst|ALT_INV_inst1~combout\,
	combout => \inst30|inst|inst1~combout\);

-- Location: LABCELL_X50_Y22_N45
\inst36|inst|inst1\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst36|inst|inst1~combout\ = ( \Y0~input_o\ & ( !\X2~input_o\ $ (!\inst32|inst|inst1~combout\ $ (((\X3~input_o\ & \inst30|inst|inst1~combout\)))) ) ) # ( !\Y0~input_o\ & ( \inst32|inst|inst1~combout\ ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000011111111000000001111111101010110101010010101011010101001",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_X2~input_o\,
	datab => \ALT_INV_X3~input_o\,
	datac => \inst30|inst|ALT_INV_inst1~combout\,
	datad => \inst32|inst|ALT_INV_inst1~combout\,
	dataf => \ALT_INV_Y0~input_o\,
	combout => \inst36|inst|inst1~combout\);

-- Location: LABCELL_X50_Y22_N48
\inst35|inst|inst1\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst35|inst|inst1~combout\ = ( \Y1~input_o\ & ( \Y0~input_o\ & ( !\inst29|inst|inst1~combout\ $ (!\X2~input_o\ $ (((\X3~input_o\ & !\inst26|inst|inst1~combout\)))) ) ) ) # ( !\Y1~input_o\ & ( \Y0~input_o\ & ( !\inst29|inst|inst1~combout\ $ 
-- (!\X3~input_o\) ) ) ) # ( \Y1~input_o\ & ( !\Y0~input_o\ & ( !\inst29|inst|inst1~combout\ $ (!\X2~input_o\ $ (((\X3~input_o\ & \inst26|inst|inst1~combout\)))) ) ) ) # ( !\Y1~input_o\ & ( !\Y0~input_o\ & ( \inst29|inst|inst1~combout\ ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0101010101010101010101101010100101100110011001100110010110011010",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst29|inst|ALT_INV_inst1~combout\,
	datab => \ALT_INV_X3~input_o\,
	datac => \inst26|inst|ALT_INV_inst1~combout\,
	datad => \ALT_INV_X2~input_o\,
	datae => \ALT_INV_Y1~input_o\,
	dataf => \ALT_INV_Y0~input_o\,
	combout => \inst35|inst|inst1~combout\);

-- Location: MLABCELL_X49_Y22_N18
\inst28|inst|inst1\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst28|inst|inst1~combout\ = ( \inst26|inst|inst1~combout\ & ( (!\Y1~input_o\) # (!\X3~input_o\) ) ) # ( !\inst26|inst|inst1~combout\ & ( (\Y1~input_o\ & \X3~input_o\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000001100000011111111001111110000000011000000111111110011111100",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_Y1~input_o\,
	datac => \ALT_INV_X3~input_o\,
	datae => \inst26|inst|ALT_INV_inst1~combout\,
	combout => \inst28|inst|inst1~combout\);

-- Location: LABCELL_X53_Y20_N0
\inst27|inst|inst1\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst27|inst|inst1~combout\ = ( \X3~input_o\ & ( \Y3~input_o\ & ( !\Y2~input_o\ $ (!\X2~input_o\) ) ) ) # ( !\X3~input_o\ & ( \Y3~input_o\ & ( \X2~input_o\ ) ) ) # ( \X3~input_o\ & ( !\Y3~input_o\ & ( \Y2~input_o\ ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000010101010101010100001111000011110101101001011010",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_Y2~input_o\,
	datac => \ALT_INV_X2~input_o\,
	datae => \ALT_INV_X3~input_o\,
	dataf => \ALT_INV_Y3~input_o\,
	combout => \inst27|inst|inst1~combout\);

-- Location: LABCELL_X53_Y20_N36
\inst|inst4\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst|inst4~combout\ = ( \X3~input_o\ & ( \Y3~input_o\ ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000000000000001111111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datae => \ALT_INV_X3~input_o\,
	dataf => \ALT_INV_Y3~input_o\,
	combout => \inst|inst4~combout\);

-- Location: LABCELL_X43_Y31_N0
\~QUARTUS_CREATED_GND~I\ : cyclonev_lcell_comb
-- Equation(s):

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000000000000000000000000000000",
	shared_arith => "off")
-- pragma translate_on
;
END structure;


