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

-- DATE "07/23/2021 01:22:14"

-- 
-- Device: Altera 5CEFA7F23C7 Package FBGA484
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

ENTITY 	project12 IS
    PORT (
	D4 : OUT std_logic;
	Y4 : IN std_logic;
	Y3 : IN std_logic;
	Y2 : IN std_logic;
	X4 : IN std_logic;
	Y1 : IN std_logic;
	D3 : OUT std_logic;
	X3 : IN std_logic;
	D2 : OUT std_logic;
	X2 : IN std_logic;
	D1 : OUT std_logic;
	X1 : IN std_logic;
	M1 : OUT std_logic;
	M2 : OUT std_logic;
	M3 : OUT std_logic;
	M4 : OUT std_logic;
	M5 : OUT std_logic
	);
END project12;

-- Design Ports Information
-- D4	=>  Location: PIN_L19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D3	=>  Location: PIN_L17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D2	=>  Location: PIN_N16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D1	=>  Location: PIN_K22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- M1	=>  Location: PIN_M21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- M2	=>  Location: PIN_K21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- M3	=>  Location: PIN_L18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- M4	=>  Location: PIN_M20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- M5	=>  Location: PIN_C6,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Y2	=>  Location: PIN_N21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- X4	=>  Location: PIN_M22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Y1	=>  Location: PIN_M16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Y4	=>  Location: PIN_L22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Y3	=>  Location: PIN_M18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- X3	=>  Location: PIN_K17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- X2	=>  Location: PIN_N19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- X1	=>  Location: PIN_N20,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF project12 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_D4 : std_logic;
SIGNAL ww_Y4 : std_logic;
SIGNAL ww_Y3 : std_logic;
SIGNAL ww_Y2 : std_logic;
SIGNAL ww_X4 : std_logic;
SIGNAL ww_Y1 : std_logic;
SIGNAL ww_D3 : std_logic;
SIGNAL ww_X3 : std_logic;
SIGNAL ww_D2 : std_logic;
SIGNAL ww_X2 : std_logic;
SIGNAL ww_D1 : std_logic;
SIGNAL ww_X1 : std_logic;
SIGNAL ww_M1 : std_logic;
SIGNAL ww_M2 : std_logic;
SIGNAL ww_M3 : std_logic;
SIGNAL ww_M4 : std_logic;
SIGNAL ww_M5 : std_logic;
SIGNAL \~QUARTUS_CREATED_GND~I_combout\ : std_logic;
SIGNAL \Y4~input_o\ : std_logic;
SIGNAL \Y3~input_o\ : std_logic;
SIGNAL \inst23|inst6~0_combout\ : std_logic;
SIGNAL \Y2~input_o\ : std_logic;
SIGNAL \X4~input_o\ : std_logic;
SIGNAL \Y1~input_o\ : std_logic;
SIGNAL \inst8|inst|inst15~combout\ : std_logic;
SIGNAL \X3~input_o\ : std_logic;
SIGNAL \inst18|inst|inst14~0_combout\ : std_logic;
SIGNAL \inst13|inst6~0_combout\ : std_logic;
SIGNAL \inst25|inst|inst14~1_combout\ : std_logic;
SIGNAL \inst25|inst|inst14~0_combout\ : std_logic;
SIGNAL \X2~input_o\ : std_logic;
SIGNAL \inst25|inst|inst14~2_combout\ : std_logic;
SIGNAL \X1~input_o\ : std_logic;
SIGNAL \inst22|inst6~0_combout\ : std_logic;
SIGNAL \inst20|inst6~0_combout\ : std_logic;
SIGNAL \inst30|inst|inst16~0_combout\ : std_logic;
SIGNAL \inst23|inst6~1_combout\ : std_logic;
SIGNAL \inst31|inst|inst16~0_combout\ : std_logic;
SIGNAL \inst27|inst6~0_combout\ : std_logic;
SIGNAL \inst29|inst6~0_combout\ : std_logic;
SIGNAL \inst29|inst6~1_combout\ : std_logic;
SIGNAL \inst29|inst|inst16~0_combout\ : std_logic;
SIGNAL \inst30|inst6~0_combout\ : std_logic;
SIGNAL \inst31|inst6~0_combout\ : std_logic;
SIGNAL \inst23|ALT_INV_inst6~0_combout\ : std_logic;
SIGNAL \inst8|inst|ALT_INV_inst15~combout\ : std_logic;
SIGNAL \inst18|inst|ALT_INV_inst14~0_combout\ : std_logic;
SIGNAL \inst13|ALT_INV_inst6~0_combout\ : std_logic;
SIGNAL \inst25|inst|ALT_INV_inst14~0_combout\ : std_logic;
SIGNAL \inst25|inst|ALT_INV_inst14~1_combout\ : std_logic;
SIGNAL \inst25|inst|ALT_INV_inst14~2_combout\ : std_logic;
SIGNAL \inst22|ALT_INV_inst6~0_combout\ : std_logic;
SIGNAL \inst20|ALT_INV_inst6~0_combout\ : std_logic;
SIGNAL \inst30|inst|ALT_INV_inst16~0_combout\ : std_logic;
SIGNAL \inst23|ALT_INV_inst6~1_combout\ : std_logic;
SIGNAL \inst31|inst|ALT_INV_inst16~0_combout\ : std_logic;
SIGNAL \inst29|ALT_INV_inst6~0_combout\ : std_logic;
SIGNAL \inst29|inst|ALT_INV_inst16~0_combout\ : std_logic;
SIGNAL \ALT_INV_Y2~input_o\ : std_logic;
SIGNAL \ALT_INV_X4~input_o\ : std_logic;
SIGNAL \ALT_INV_Y1~input_o\ : std_logic;
SIGNAL \ALT_INV_Y4~input_o\ : std_logic;
SIGNAL \ALT_INV_Y3~input_o\ : std_logic;
SIGNAL \ALT_INV_X3~input_o\ : std_logic;
SIGNAL \ALT_INV_X2~input_o\ : std_logic;
SIGNAL \ALT_INV_X1~input_o\ : std_logic;

BEGIN

D4 <= ww_D4;
ww_Y4 <= Y4;
ww_Y3 <= Y3;
ww_Y2 <= Y2;
ww_X4 <= X4;
ww_Y1 <= Y1;
D3 <= ww_D3;
ww_X3 <= X3;
D2 <= ww_D2;
ww_X2 <= X2;
D1 <= ww_D1;
ww_X1 <= X1;
M1 <= ww_M1;
M2 <= ww_M2;
M3 <= ww_M3;
M4 <= ww_M4;
M5 <= ww_M5;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
\inst23|ALT_INV_inst6~0_combout\ <= NOT \inst23|inst6~0_combout\;
\inst8|inst|ALT_INV_inst15~combout\ <= NOT \inst8|inst|inst15~combout\;
\inst18|inst|ALT_INV_inst14~0_combout\ <= NOT \inst18|inst|inst14~0_combout\;
\inst13|ALT_INV_inst6~0_combout\ <= NOT \inst13|inst6~0_combout\;
\inst25|inst|ALT_INV_inst14~0_combout\ <= NOT \inst25|inst|inst14~0_combout\;
\inst25|inst|ALT_INV_inst14~1_combout\ <= NOT \inst25|inst|inst14~1_combout\;
\inst25|inst|ALT_INV_inst14~2_combout\ <= NOT \inst25|inst|inst14~2_combout\;
\inst22|ALT_INV_inst6~0_combout\ <= NOT \inst22|inst6~0_combout\;
\inst20|ALT_INV_inst6~0_combout\ <= NOT \inst20|inst6~0_combout\;
\inst30|inst|ALT_INV_inst16~0_combout\ <= NOT \inst30|inst|inst16~0_combout\;
\inst23|ALT_INV_inst6~1_combout\ <= NOT \inst23|inst6~1_combout\;
\inst31|inst|ALT_INV_inst16~0_combout\ <= NOT \inst31|inst|inst16~0_combout\;
\inst29|ALT_INV_inst6~0_combout\ <= NOT \inst29|inst6~0_combout\;
\inst29|inst|ALT_INV_inst16~0_combout\ <= NOT \inst29|inst|inst16~0_combout\;
\ALT_INV_Y2~input_o\ <= NOT \Y2~input_o\;
\ALT_INV_X4~input_o\ <= NOT \X4~input_o\;
\ALT_INV_Y1~input_o\ <= NOT \Y1~input_o\;
\ALT_INV_Y4~input_o\ <= NOT \Y4~input_o\;
\ALT_INV_Y3~input_o\ <= NOT \Y3~input_o\;
\ALT_INV_X3~input_o\ <= NOT \X3~input_o\;
\ALT_INV_X2~input_o\ <= NOT \X2~input_o\;
\ALT_INV_X1~input_o\ <= NOT \X1~input_o\;

-- Location: IOOBUF_X89_Y38_N5
\D4~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst8|inst|ALT_INV_inst15~combout\,
	devoe => ww_devoe,
	o => ww_D4);

-- Location: IOOBUF_X89_Y37_N22
\D3~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst18|inst|ALT_INV_inst14~0_combout\,
	devoe => ww_devoe,
	o => ww_D3);

-- Location: IOOBUF_X89_Y35_N45
\D2~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst25|inst|ALT_INV_inst14~2_combout\,
	devoe => ww_devoe,
	o => ww_D2);

-- Location: IOOBUF_X89_Y38_N56
\D1~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst31|inst|ALT_INV_inst16~0_combout\,
	devoe => ww_devoe,
	o => ww_D1);

-- Location: IOOBUF_X89_Y37_N56
\M1~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst27|inst6~0_combout\,
	devoe => ww_devoe,
	o => ww_M1);

-- Location: IOOBUF_X89_Y38_N39
\M2~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst29|inst6~1_combout\,
	devoe => ww_devoe,
	o => ww_M2);

-- Location: IOOBUF_X89_Y38_N22
\M3~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst30|inst6~0_combout\,
	devoe => ww_devoe,
	o => ww_M3);

-- Location: IOOBUF_X89_Y37_N39
\M4~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst31|inst6~0_combout\,
	devoe => ww_devoe,
	o => ww_M4);

-- Location: IOOBUF_X30_Y81_N36
\M5~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => GND,
	devoe => ww_devoe,
	o => ww_M5);

-- Location: IOIBUF_X89_Y36_N55
\Y4~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Y4,
	o => \Y4~input_o\);

-- Location: IOIBUF_X89_Y36_N21
\Y3~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Y3,
	o => \Y3~input_o\);

-- Location: LABCELL_X88_Y35_N0
\inst23|inst6~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst23|inst6~0_combout\ = (!\Y4~input_o\ & !\Y3~input_o\)

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "1000100010001000100010001000100010001000100010001000100010001000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_Y4~input_o\,
	datab => \ALT_INV_Y3~input_o\,
	combout => \inst23|inst6~0_combout\);

-- Location: IOIBUF_X89_Y35_N95
\Y2~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Y2,
	o => \Y2~input_o\);

-- Location: IOIBUF_X89_Y36_N38
\X4~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_X4,
	o => \X4~input_o\);

-- Location: IOIBUF_X89_Y35_N61
\Y1~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Y1,
	o => \Y1~input_o\);

-- Location: LABCELL_X88_Y35_N9
\inst8|inst|inst15\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst8|inst|inst15~combout\ = ( \Y1~input_o\ & ( (!\inst23|inst6~0_combout\) # ((!\X4~input_o\) # (\Y2~input_o\)) ) ) # ( !\Y1~input_o\ & ( (!\inst23|inst6~0_combout\) # (\Y2~input_o\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "1011101110111011101110111011101111111111101110111111111110111011",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst23|ALT_INV_inst6~0_combout\,
	datab => \ALT_INV_Y2~input_o\,
	datad => \ALT_INV_X4~input_o\,
	dataf => \ALT_INV_Y1~input_o\,
	combout => \inst8|inst|inst15~combout\);

-- Location: IOIBUF_X89_Y37_N4
\X3~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_X3,
	o => \X3~input_o\);

-- Location: LABCELL_X88_Y35_N42
\inst18|inst|inst14~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst18|inst|inst14~0_combout\ = ( \X3~input_o\ & ( (!\inst23|inst6~0_combout\) # ((\Y2~input_o\ & !\X4~input_o\)) ) ) # ( !\X3~input_o\ & ( ((!\inst23|inst6~0_combout\) # ((\Y2~input_o\ & !\X4~input_o\))) # (\Y1~input_o\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "1111011111110101111101111111010111110011111100001111001111110000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_Y1~input_o\,
	datab => \ALT_INV_Y2~input_o\,
	datac => \inst23|ALT_INV_inst6~0_combout\,
	datad => \ALT_INV_X4~input_o\,
	dataf => \ALT_INV_X3~input_o\,
	combout => \inst18|inst|inst14~0_combout\);

-- Location: LABCELL_X88_Y35_N18
\inst13|inst6~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst13|inst6~0_combout\ = ( \X4~input_o\ & ( \X3~input_o\ & ( ((!\Y1~input_o\) # (\Y3~input_o\)) # (\Y4~input_o\) ) ) ) # ( !\X4~input_o\ & ( \X3~input_o\ & ( (((!\Y1~input_o\) # (\Y3~input_o\)) # (\Y2~input_o\)) # (\Y4~input_o\) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000011110111111111111111010111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_Y4~input_o\,
	datab => \ALT_INV_Y2~input_o\,
	datac => \ALT_INV_Y1~input_o\,
	datad => \ALT_INV_Y3~input_o\,
	datae => \ALT_INV_X4~input_o\,
	dataf => \ALT_INV_X3~input_o\,
	combout => \inst13|inst6~0_combout\);

-- Location: LABCELL_X88_Y35_N3
\inst25|inst|inst14~1\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst25|inst|inst14~1_combout\ = (!\Y4~input_o\ & ((!\Y3~input_o\) # (\X4~input_o\)))

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "1000100010101010100010001010101010001000101010101000100010101010",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_Y4~input_o\,
	datab => \ALT_INV_Y3~input_o\,
	datad => \ALT_INV_X4~input_o\,
	combout => \inst25|inst|inst14~1_combout\);

-- Location: LABCELL_X88_Y35_N24
\inst25|inst|inst14~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst25|inst|inst14~0_combout\ = ( \X4~input_o\ & ( \X3~input_o\ & ( (!\Y3~input_o\ & (((!\Y2~input_o\ & !\Y1~input_o\)) # (\Y4~input_o\))) ) ) ) # ( \X4~input_o\ & ( !\X3~input_o\ & ( (!\Y3~input_o\ & ((!\Y2~input_o\ $ (\Y1~input_o\)) # (\Y4~input_o\))) 
-- ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000110101110000000000000000000000001101010100000000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_Y4~input_o\,
	datab => \ALT_INV_Y2~input_o\,
	datac => \ALT_INV_Y1~input_o\,
	datad => \ALT_INV_Y3~input_o\,
	datae => \ALT_INV_X4~input_o\,
	dataf => \ALT_INV_X3~input_o\,
	combout => \inst25|inst|inst14~0_combout\);

-- Location: IOIBUF_X89_Y36_N4
\X2~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_X2,
	o => \X2~input_o\);

-- Location: MLABCELL_X87_Y35_N30
\inst25|inst|inst14~2\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst25|inst|inst14~2_combout\ = ( \Y2~input_o\ & ( \X2~input_o\ & ( (!\inst25|inst|inst14~1_combout\) # ((!\inst13|inst6~0_combout\ & !\inst25|inst|inst14~0_combout\)) ) ) ) # ( !\Y2~input_o\ & ( \X2~input_o\ & ( !\inst25|inst|inst14~1_combout\ ) ) ) # ( 
-- \Y2~input_o\ & ( !\X2~input_o\ & ( (!\inst25|inst|inst14~1_combout\) # ((!\inst25|inst|inst14~0_combout\ & ((!\inst13|inst6~0_combout\) # (\Y1~input_o\)))) ) ) ) # ( !\Y2~input_o\ & ( !\X2~input_o\ & ( (!\inst25|inst|inst14~1_combout\) # ((\Y1~input_o\ & 
-- (!\inst13|inst6~0_combout\ & !\inst25|inst|inst14~0_combout\))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "1111010011110000111111011111000011110000111100001111110011110000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_Y1~input_o\,
	datab => \inst13|ALT_INV_inst6~0_combout\,
	datac => \inst25|inst|ALT_INV_inst14~1_combout\,
	datad => \inst25|inst|ALT_INV_inst14~0_combout\,
	datae => \ALT_INV_Y2~input_o\,
	dataf => \ALT_INV_X2~input_o\,
	combout => \inst25|inst|inst14~2_combout\);

-- Location: IOIBUF_X89_Y35_N78
\X1~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_X1,
	o => \X1~input_o\);

-- Location: MLABCELL_X87_Y35_N36
\inst22|inst6~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst22|inst6~0_combout\ = ( \Y2~input_o\ & ( \X2~input_o\ & ( (!\inst13|inst6~0_combout\ & (\inst25|inst|inst14~1_combout\ & \inst25|inst|inst14~0_combout\)) # (\inst13|inst6~0_combout\ & (!\inst25|inst|inst14~1_combout\)) ) ) ) # ( !\Y2~input_o\ & ( 
-- \X2~input_o\ & ( \inst13|inst6~0_combout\ ) ) ) # ( \Y2~input_o\ & ( !\X2~input_o\ & ( (!\Y1~input_o\ & ((!\inst13|inst6~0_combout\ & (\inst25|inst|inst14~1_combout\ & \inst25|inst|inst14~0_combout\)) # (\inst13|inst6~0_combout\ & 
-- (!\inst25|inst|inst14~1_combout\)))) # (\Y1~input_o\ & (\inst13|inst6~0_combout\)) ) ) ) # ( !\Y2~input_o\ & ( !\X2~input_o\ & ( (!\Y1~input_o\ & (\inst13|inst6~0_combout\)) # (\Y1~input_o\ & ((!\inst13|inst6~0_combout\ & (\inst25|inst|inst14~1_combout\ & 
-- \inst25|inst|inst14~0_combout\)) # (\inst13|inst6~0_combout\ & (!\inst25|inst|inst14~1_combout\)))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0011001000110110001100010011100100110011001100110011000000111100",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_Y1~input_o\,
	datab => \inst13|ALT_INV_inst6~0_combout\,
	datac => \inst25|inst|ALT_INV_inst14~1_combout\,
	datad => \inst25|inst|ALT_INV_inst14~0_combout\,
	datae => \ALT_INV_Y2~input_o\,
	dataf => \ALT_INV_X2~input_o\,
	combout => \inst22|inst6~0_combout\);

-- Location: MLABCELL_X87_Y35_N42
\inst20|inst6~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst20|inst6~0_combout\ = ( \Y2~input_o\ & ( \X2~input_o\ & ( (!\Y1~input_o\) # ((!\inst25|inst|inst14~1_combout\) # ((!\inst13|inst6~0_combout\ & !\inst25|inst|inst14~0_combout\))) ) ) ) # ( !\Y2~input_o\ & ( \X2~input_o\ & ( (!\Y1~input_o\) # 
-- (!\inst25|inst|inst14~1_combout\) ) ) ) # ( \Y2~input_o\ & ( !\X2~input_o\ & ( (\Y1~input_o\ & (\inst25|inst|inst14~1_combout\ & \inst25|inst|inst14~0_combout\)) ) ) ) # ( !\Y2~input_o\ & ( !\X2~input_o\ & ( (\Y1~input_o\ & (\inst25|inst|inst14~1_combout\ 
-- & ((\inst25|inst|inst14~0_combout\) # (\inst13|inst6~0_combout\)))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000100000101000000000000010111111010111110101111111011111010",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_Y1~input_o\,
	datab => \inst13|ALT_INV_inst6~0_combout\,
	datac => \inst25|inst|ALT_INV_inst14~1_combout\,
	datad => \inst25|inst|ALT_INV_inst14~0_combout\,
	datae => \ALT_INV_Y2~input_o\,
	dataf => \ALT_INV_X2~input_o\,
	combout => \inst20|inst6~0_combout\);

-- Location: LABCELL_X88_Y35_N30
\inst30|inst|inst16~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst30|inst|inst16~0_combout\ = ( \inst20|inst6~0_combout\ & ( \Y3~input_o\ & ( (!\inst22|inst6~0_combout\) # ((\Y1~input_o\ & (!\X1~input_o\ & \Y2~input_o\))) ) ) ) # ( !\inst20|inst6~0_combout\ & ( \Y3~input_o\ & ( (!\inst22|inst6~0_combout\) # 
-- (((\Y1~input_o\ & !\X1~input_o\)) # (\Y2~input_o\)) ) ) ) # ( \inst20|inst6~0_combout\ & ( !\Y3~input_o\ & ( (\Y1~input_o\ & (!\X1~input_o\ & (!\inst22|inst6~0_combout\ & \Y2~input_o\))) ) ) ) # ( !\inst20|inst6~0_combout\ & ( !\Y3~input_o\ & ( 
-- (!\inst22|inst6~0_combout\ & (((\Y1~input_o\ & !\X1~input_o\)) # (\Y2~input_o\))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0100000011110000000000000100000011110100111111111111000011110100",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_Y1~input_o\,
	datab => \ALT_INV_X1~input_o\,
	datac => \inst22|ALT_INV_inst6~0_combout\,
	datad => \ALT_INV_Y2~input_o\,
	datae => \inst20|ALT_INV_inst6~0_combout\,
	dataf => \ALT_INV_Y3~input_o\,
	combout => \inst30|inst|inst16~0_combout\);

-- Location: LABCELL_X88_Y35_N36
\inst23|inst6~1\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst23|inst6~1_combout\ = ( \X4~input_o\ & ( \inst25|inst|inst14~2_combout\ & ( (!\inst23|inst6~0_combout\) # ((!\Y1~input_o\ & (!\Y2~input_o\)) # (\Y1~input_o\ & (\Y2~input_o\ & !\X3~input_o\))) ) ) ) # ( \X4~input_o\ & ( !\inst25|inst|inst14~2_combout\ 
-- & ( (!\Y1~input_o\ & (!\Y2~input_o\ & \inst23|inst6~0_combout\)) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000010000000100000000000000000001111100111111000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_Y1~input_o\,
	datab => \ALT_INV_Y2~input_o\,
	datac => \inst23|ALT_INV_inst6~0_combout\,
	datad => \ALT_INV_X3~input_o\,
	datae => \ALT_INV_X4~input_o\,
	dataf => \inst25|inst|ALT_INV_inst14~2_combout\,
	combout => \inst23|inst6~1_combout\);

-- Location: LABCELL_X88_Y35_N12
\inst31|inst|inst16~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst31|inst|inst16~0_combout\ = ( \Y4~input_o\ & ( (!\X4~input_o\) # (\inst30|inst|inst16~0_combout\) ) ) # ( !\Y4~input_o\ & ( (\inst30|inst|inst16~0_combout\ & !\inst23|inst6~1_combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0011000000110000001100000011000010111011101110111011101110111011",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_X4~input_o\,
	datab => \inst30|inst|ALT_INV_inst16~0_combout\,
	datac => \inst23|ALT_INV_inst6~1_combout\,
	dataf => \ALT_INV_Y4~input_o\,
	combout => \inst31|inst|inst16~0_combout\);

-- Location: LABCELL_X88_Y35_N48
\inst27|inst6~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst27|inst6~0_combout\ = ( \Y1~input_o\ & ( \X1~input_o\ & ( (!\Y4~input_o\ & (((!\inst23|inst6~1_combout\ & \inst30|inst|inst16~0_combout\)))) # (\Y4~input_o\ & ((!\X4~input_o\) # ((\inst30|inst|inst16~0_combout\)))) ) ) ) # ( !\Y1~input_o\ & ( 
-- \X1~input_o\ ) ) # ( \Y1~input_o\ & ( !\X1~input_o\ & ( (!\Y4~input_o\ & (((!\inst30|inst|inst16~0_combout\) # (\inst23|inst6~1_combout\)))) # (\Y4~input_o\ & (\X4~input_o\ & ((!\inst30|inst|inst16~0_combout\)))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000111101010011000011111111111111110000101011001111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_X4~input_o\,
	datab => \inst23|ALT_INV_inst6~1_combout\,
	datac => \ALT_INV_Y4~input_o\,
	datad => \inst30|inst|ALT_INV_inst16~0_combout\,
	datae => \ALT_INV_Y1~input_o\,
	dataf => \ALT_INV_X1~input_o\,
	combout => \inst27|inst6~0_combout\);

-- Location: LABCELL_X88_Y35_N45
\inst29|inst6~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst29|inst6~0_combout\ = !\Y2~input_o\ $ (((!\Y1~input_o\) # (\X1~input_o\)))

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0110001101100011011000110110001101100011011000110110001101100011",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_Y1~input_o\,
	datab => \ALT_INV_Y2~input_o\,
	datac => \ALT_INV_X1~input_o\,
	combout => \inst29|inst6~0_combout\);

-- Location: LABCELL_X88_Y35_N51
\inst29|inst6~1\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst29|inst6~1_combout\ = ( \inst29|inst6~0_combout\ & ( \inst20|inst6~0_combout\ & ( (!\inst30|inst|inst16~0_combout\ & (!\X4~input_o\ & ((\Y4~input_o\)))) # (\inst30|inst|inst16~0_combout\ & (((!\inst23|inst6~1_combout\) # (\Y4~input_o\)))) ) ) ) # ( 
-- !\inst29|inst6~0_combout\ & ( \inst20|inst6~0_combout\ ) ) # ( \inst29|inst6~0_combout\ & ( !\inst20|inst6~0_combout\ & ( (!\inst30|inst|inst16~0_combout\ & (((!\Y4~input_o\)) # (\X4~input_o\))) # (\inst30|inst|inst16~0_combout\ & 
-- (((\inst23|inst6~1_combout\ & !\Y4~input_o\)))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000111100110101000011111111111111110000110010101111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_X4~input_o\,
	datab => \inst23|ALT_INV_inst6~1_combout\,
	datac => \inst30|inst|ALT_INV_inst16~0_combout\,
	datad => \ALT_INV_Y4~input_o\,
	datae => \inst29|ALT_INV_inst6~0_combout\,
	dataf => \inst20|ALT_INV_inst6~0_combout\,
	combout => \inst29|inst6~1_combout\);

-- Location: LABCELL_X88_Y35_N6
\inst29|inst|inst16~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst29|inst|inst16~0_combout\ = ( \X1~input_o\ & ( (\Y2~input_o\ & !\inst20|inst6~0_combout\) ) ) # ( !\X1~input_o\ & ( (!\Y2~input_o\ & (\Y1~input_o\ & !\inst20|inst6~0_combout\)) # (\Y2~input_o\ & ((!\inst20|inst6~0_combout\) # (\Y1~input_o\))) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0011111100000011001111110000001100110011000000000011001100000000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_Y2~input_o\,
	datac => \ALT_INV_Y1~input_o\,
	datad => \inst20|ALT_INV_inst6~0_combout\,
	dataf => \ALT_INV_X1~input_o\,
	combout => \inst29|inst|inst16~0_combout\);

-- Location: LABCELL_X88_Y35_N54
\inst30|inst6~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst30|inst6~0_combout\ = ( \inst23|inst6~1_combout\ & ( \Y4~input_o\ & ( (\inst22|inst6~0_combout\ & ((!\X4~input_o\) # (!\inst29|inst|inst16~0_combout\ $ (\Y3~input_o\)))) ) ) ) # ( !\inst23|inst6~1_combout\ & ( \Y4~input_o\ & ( 
-- (\inst22|inst6~0_combout\ & ((!\X4~input_o\) # (!\inst29|inst|inst16~0_combout\ $ (\Y3~input_o\)))) ) ) ) # ( \inst23|inst6~1_combout\ & ( !\Y4~input_o\ & ( !\inst29|inst|inst16~0_combout\ $ (!\inst22|inst6~0_combout\ $ (\Y3~input_o\)) ) ) ) # ( 
-- !\inst23|inst6~1_combout\ & ( !\Y4~input_o\ & ( (\inst22|inst6~0_combout\ & (!\inst29|inst|inst16~0_combout\ $ (\Y3~input_o\))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000110000000011001111001100001100001110000010110000111000001011",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_X4~input_o\,
	datab => \inst29|inst|ALT_INV_inst16~0_combout\,
	datac => \inst22|ALT_INV_inst6~0_combout\,
	datad => \ALT_INV_Y3~input_o\,
	datae => \inst23|ALT_INV_inst6~1_combout\,
	dataf => \ALT_INV_Y4~input_o\,
	combout => \inst30|inst6~0_combout\);

-- Location: LABCELL_X88_Y35_N15
\inst31|inst6~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst31|inst6~0_combout\ = ( \Y4~input_o\ & ( (\inst23|inst6~1_combout\ & ((!\X4~input_o\) # (\inst30|inst|inst16~0_combout\))) ) ) # ( !\Y4~input_o\ & ( (!\inst30|inst|inst16~0_combout\ & \inst23|inst6~1_combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000011001100000000001100110000000000101110110000000010111011",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_X4~input_o\,
	datab => \inst30|inst|ALT_INV_inst16~0_combout\,
	datad => \inst23|ALT_INV_inst6~1_combout\,
	dataf => \ALT_INV_Y4~input_o\,
	combout => \inst31|inst6~0_combout\);

-- Location: LABCELL_X37_Y38_N3
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


