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

-- DATE "06/15/2021 11:59:37"

-- 
-- Device: Altera 5CEBA4F23C7 Package FBGA484
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

ENTITY 	project7 IS
    PORT (
	Cout : OUT std_logic;
	A1 : IN std_logic;
	A0 : IN std_logic;
	B1 : IN std_logic;
	B0 : IN std_logic;
	B2 : IN std_logic;
	A2 : IN std_logic;
	B3 : IN std_logic;
	A3 : IN std_logic;
	display_g : OUT std_logic;
	display_e : OUT std_logic;
	display_f : OUT std_logic;
	display_d : OUT std_logic;
	display_c : OUT std_logic;
	display_b : OUT std_logic;
	display_a : OUT std_logic
	);
END project7;

-- Design Ports Information
-- Cout	=>  Location: PIN_Y16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- display_g	=>  Location: PIN_AA22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- display_e	=>  Location: PIN_Y22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- display_f	=>  Location: PIN_Y21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- display_d	=>  Location: PIN_W21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- display_c	=>  Location: PIN_W22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- display_b	=>  Location: PIN_V21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- display_a	=>  Location: PIN_U21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A1	=>  Location: PIN_V13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A0	=>  Location: PIN_U13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B1	=>  Location: PIN_AB15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B0	=>  Location: PIN_AA15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B2	=>  Location: PIN_AA14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A2	=>  Location: PIN_T13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B3	=>  Location: PIN_AA13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A3	=>  Location: PIN_T12,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF project7 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_Cout : std_logic;
SIGNAL ww_A1 : std_logic;
SIGNAL ww_A0 : std_logic;
SIGNAL ww_B1 : std_logic;
SIGNAL ww_B0 : std_logic;
SIGNAL ww_B2 : std_logic;
SIGNAL ww_A2 : std_logic;
SIGNAL ww_B3 : std_logic;
SIGNAL ww_A3 : std_logic;
SIGNAL ww_display_g : std_logic;
SIGNAL ww_display_e : std_logic;
SIGNAL ww_display_f : std_logic;
SIGNAL ww_display_d : std_logic;
SIGNAL ww_display_c : std_logic;
SIGNAL ww_display_b : std_logic;
SIGNAL ww_display_a : std_logic;
SIGNAL \~QUARTUS_CREATED_GND~I_combout\ : std_logic;
SIGNAL \B1~input_o\ : std_logic;
SIGNAL \A0~input_o\ : std_logic;
SIGNAL \B0~input_o\ : std_logic;
SIGNAL \B3~input_o\ : std_logic;
SIGNAL \A2~input_o\ : std_logic;
SIGNAL \A3~input_o\ : std_logic;
SIGNAL \B2~input_o\ : std_logic;
SIGNAL \inst4|inst7~0_combout\ : std_logic;
SIGNAL \A1~input_o\ : std_logic;
SIGNAL \inst6|inst7~0_combout\ : std_logic;
SIGNAL \inst4|inst1~combout\ : std_logic;
SIGNAL \inst2|inst~combout\ : std_logic;
SIGNAL \inst6|inst1~0_combout\ : std_logic;
SIGNAL \inst11|inst51|inst12~0_combout\ : std_logic;
SIGNAL \inst11|inst49|inst11~0_combout\ : std_logic;
SIGNAL \inst11|inst53|inst12~0_combout\ : std_logic;
SIGNAL \inst11|inst54|inst13~combout\ : std_logic;
SIGNAL \inst11|inst47|inst11~0_combout\ : std_logic;
SIGNAL \inst11|inst46|inst17~0_combout\ : std_logic;
SIGNAL \inst11|inst|inst9~combout\ : std_logic;
SIGNAL \ALT_INV_A1~input_o\ : std_logic;
SIGNAL \inst4|ALT_INV_inst7~0_combout\ : std_logic;
SIGNAL \inst2|ALT_INV_inst~combout\ : std_logic;
SIGNAL \inst4|ALT_INV_inst1~combout\ : std_logic;
SIGNAL \inst6|ALT_INV_inst1~0_combout\ : std_logic;
SIGNAL \ALT_INV_A3~input_o\ : std_logic;
SIGNAL \ALT_INV_B3~input_o\ : std_logic;
SIGNAL \ALT_INV_A2~input_o\ : std_logic;
SIGNAL \ALT_INV_B2~input_o\ : std_logic;
SIGNAL \ALT_INV_B0~input_o\ : std_logic;
SIGNAL \ALT_INV_B1~input_o\ : std_logic;
SIGNAL \ALT_INV_A0~input_o\ : std_logic;

BEGIN

Cout <= ww_Cout;
ww_A1 <= A1;
ww_A0 <= A0;
ww_B1 <= B1;
ww_B0 <= B0;
ww_B2 <= B2;
ww_A2 <= A2;
ww_B3 <= B3;
ww_A3 <= A3;
display_g <= ww_display_g;
display_e <= ww_display_e;
display_f <= ww_display_f;
display_d <= ww_display_d;
display_c <= ww_display_c;
display_b <= ww_display_b;
display_a <= ww_display_a;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
\ALT_INV_A1~input_o\ <= NOT \A1~input_o\;
\inst4|ALT_INV_inst7~0_combout\ <= NOT \inst4|inst7~0_combout\;
\inst2|ALT_INV_inst~combout\ <= NOT \inst2|inst~combout\;
\inst4|ALT_INV_inst1~combout\ <= NOT \inst4|inst1~combout\;
\inst6|ALT_INV_inst1~0_combout\ <= NOT \inst6|inst1~0_combout\;
\ALT_INV_A3~input_o\ <= NOT \A3~input_o\;
\ALT_INV_B3~input_o\ <= NOT \B3~input_o\;
\ALT_INV_A2~input_o\ <= NOT \A2~input_o\;
\ALT_INV_B2~input_o\ <= NOT \B2~input_o\;
\ALT_INV_B0~input_o\ <= NOT \B0~input_o\;
\ALT_INV_B1~input_o\ <= NOT \B1~input_o\;
\ALT_INV_A0~input_o\ <= NOT \A0~input_o\;

-- Location: IOOBUF_X40_Y0_N59
\Cout~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst6|inst7~0_combout\,
	devoe => ww_devoe,
	o => ww_Cout);

-- Location: IOOBUF_X46_Y0_N36
\display_g~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst11|inst51|inst12~0_combout\,
	devoe => ww_devoe,
	o => ww_display_g);

-- Location: IOOBUF_X48_Y0_N93
\display_e~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst11|inst49|inst11~0_combout\,
	devoe => ww_devoe,
	o => ww_display_e);

-- Location: IOOBUF_X50_Y0_N53
\display_f~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst11|inst53|inst12~0_combout\,
	devoe => ww_devoe,
	o => ww_display_f);

-- Location: IOOBUF_X50_Y0_N36
\display_d~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst11|inst54|inst13~combout\,
	devoe => ww_devoe,
	o => ww_display_d);

-- Location: IOOBUF_X48_Y0_N76
\display_c~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst11|inst47|inst11~0_combout\,
	devoe => ww_devoe,
	o => ww_display_c);

-- Location: IOOBUF_X51_Y0_N36
\display_b~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst11|inst46|inst17~0_combout\,
	devoe => ww_devoe,
	o => ww_display_b);

-- Location: IOOBUF_X52_Y0_N53
\display_a~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst11|inst|inst9~combout\,
	devoe => ww_devoe,
	o => ww_display_a);

-- Location: IOIBUF_X36_Y0_N52
\B1~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B1,
	o => \B1~input_o\);

-- Location: IOIBUF_X33_Y0_N41
\A0~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A0,
	o => \A0~input_o\);

-- Location: IOIBUF_X36_Y0_N35
\B0~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B0,
	o => \B0~input_o\);

-- Location: IOIBUF_X34_Y0_N35
\B3~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B3,
	o => \B3~input_o\);

-- Location: IOIBUF_X34_Y0_N1
\A2~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A2,
	o => \A2~input_o\);

-- Location: IOIBUF_X34_Y0_N18
\A3~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A3,
	o => \A3~input_o\);

-- Location: IOIBUF_X34_Y0_N52
\B2~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B2,
	o => \B2~input_o\);

-- Location: LABCELL_X41_Y1_N0
\inst4|inst7~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst4|inst7~0_combout\ = ( \B2~input_o\ & ( ((\B3~input_o\ & \A3~input_o\)) # (\A2~input_o\) ) ) # ( !\B2~input_o\ & ( (\B3~input_o\ & (\A2~input_o\ & \A3~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000100000001000000010000000100110111001101110011011100110111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_B3~input_o\,
	datab => \ALT_INV_A2~input_o\,
	datac => \ALT_INV_A3~input_o\,
	dataf => \ALT_INV_B2~input_o\,
	combout => \inst4|inst7~0_combout\);

-- Location: IOIBUF_X33_Y0_N58
\A1~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A1,
	o => \A1~input_o\);

-- Location: LABCELL_X41_Y1_N39
\inst6|inst7~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst6|inst7~0_combout\ = ( \A1~input_o\ & ( ((!\B1~input_o\ & (\B0~input_o\ & \inst4|inst7~0_combout\)) # (\B1~input_o\ & ((\inst4|inst7~0_combout\) # (\B0~input_o\)))) # (\A0~input_o\) ) ) # ( !\A1~input_o\ & ( (\A0~input_o\ & ((!\B1~input_o\ & 
-- (\B0~input_o\ & \inst4|inst7~0_combout\)) # (\B1~input_o\ & ((\inst4|inst7~0_combout\) # (\B0~input_o\))))) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000100010011000000010001001100110111011111110011011101111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_B1~input_o\,
	datab => \ALT_INV_A0~input_o\,
	datac => \ALT_INV_B0~input_o\,
	datad => \inst4|ALT_INV_inst7~0_combout\,
	dataf => \ALT_INV_A1~input_o\,
	combout => \inst6|inst7~0_combout\);

-- Location: LABCELL_X41_Y1_N3
\inst4|inst1\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst4|inst1~combout\ = ( \B2~input_o\ & ( !\A2~input_o\ $ (((\B3~input_o\ & \A3~input_o\))) ) ) # ( !\B2~input_o\ & ( !\A2~input_o\ $ (((!\B3~input_o\) # (!\A3~input_o\))) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0011011000110110001101100011011011001001110010011100100111001001",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_B3~input_o\,
	datab => \ALT_INV_A2~input_o\,
	datac => \ALT_INV_A3~input_o\,
	dataf => \ALT_INV_B2~input_o\,
	combout => \inst4|inst1~combout\);

-- Location: LABCELL_X41_Y1_N36
\inst2|inst\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst2|inst~combout\ = ( \B3~input_o\ & ( !\A3~input_o\ ) ) # ( !\B3~input_o\ & ( \A3~input_o\ ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000111100001111000011110000111111110000111100001111000011110000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => \ALT_INV_A3~input_o\,
	dataf => \ALT_INV_B3~input_o\,
	combout => \inst2|inst~combout\);

-- Location: LABCELL_X41_Y1_N12
\inst6|inst1~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst6|inst1~0_combout\ = ( !\A0~input_o\ & ( \A1~input_o\ ) ) # ( \A0~input_o\ & ( !\A1~input_o\ ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000111111111111111111111111111111110000000000000000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datae => \ALT_INV_A0~input_o\,
	dataf => \ALT_INV_A1~input_o\,
	combout => \inst6|inst1~0_combout\);

-- Location: LABCELL_X41_Y1_N18
\inst11|inst51|inst12~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst11|inst51|inst12~0_combout\ = ( \inst4|inst7~0_combout\ & ( \B1~input_o\ & ( (!\inst2|inst~combout\ & (!\inst4|inst1~combout\ & (!\B0~input_o\ $ (!\inst6|inst1~0_combout\)))) # (\inst2|inst~combout\ & (\inst6|inst1~0_combout\ & 
-- (!\inst4|inst1~combout\ $ (\B0~input_o\)))) ) ) ) # ( !\inst4|inst7~0_combout\ & ( \B1~input_o\ & ( (!\inst4|inst1~combout\ & (\inst6|inst1~0_combout\ & ((!\inst2|inst~combout\) # (\B0~input_o\)))) # (\inst4|inst1~combout\ & (!\B0~input_o\ & 
-- (\inst2|inst~combout\ & !\inst6|inst1~0_combout\))) ) ) ) # ( \inst4|inst7~0_combout\ & ( !\B1~input_o\ & ( (!\inst4|inst1~combout\ & (\inst6|inst1~0_combout\ & ((!\inst2|inst~combout\) # (\B0~input_o\)))) # (\inst4|inst1~combout\ & (!\B0~input_o\ & 
-- (\inst2|inst~combout\ & !\inst6|inst1~0_combout\))) ) ) ) # ( !\inst4|inst7~0_combout\ & ( !\B1~input_o\ & ( (!\inst2|inst~combout\ & (!\inst4|inst1~combout\ & (!\B0~input_o\ $ (\inst6|inst1~0_combout\)))) # (\inst2|inst~combout\ & 
-- (!\inst6|inst1~0_combout\ & (!\inst4|inst1~combout\ $ (\B0~input_o\)))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "1000100100100000000001001010001000000100101000100010000010001001",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst4|ALT_INV_inst1~combout\,
	datab => \ALT_INV_B0~input_o\,
	datac => \inst2|ALT_INV_inst~combout\,
	datad => \inst6|ALT_INV_inst1~0_combout\,
	datae => \inst4|ALT_INV_inst7~0_combout\,
	dataf => \ALT_INV_B1~input_o\,
	combout => \inst11|inst51|inst12~0_combout\);

-- Location: LABCELL_X41_Y1_N54
\inst11|inst49|inst11~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst11|inst49|inst11~0_combout\ = ( \inst4|inst7~0_combout\ & ( \B1~input_o\ & ( (!\inst4|inst1~combout\ & ((!\B0~input_o\ & (\inst2|inst~combout\)) # (\B0~input_o\ & ((\inst6|inst1~0_combout\))))) # (\inst4|inst1~combout\ & (((\inst2|inst~combout\ & 
-- \inst6|inst1~0_combout\)))) ) ) ) # ( !\inst4|inst7~0_combout\ & ( \B1~input_o\ & ( (!\inst4|inst1~combout\ & ((!\B0~input_o\ & ((!\inst6|inst1~0_combout\))) # (\B0~input_o\ & (\inst2|inst~combout\)))) # (\inst4|inst1~combout\ & (\inst2|inst~combout\ & 
-- (!\B0~input_o\ $ (\inst6|inst1~0_combout\)))) ) ) ) # ( \inst4|inst7~0_combout\ & ( !\B1~input_o\ & ( (!\inst4|inst1~combout\ & ((!\B0~input_o\ & ((!\inst6|inst1~0_combout\))) # (\B0~input_o\ & (\inst2|inst~combout\)))) # (\inst4|inst1~combout\ & 
-- (\inst2|inst~combout\ & (!\B0~input_o\ $ (\inst6|inst1~0_combout\)))) ) ) ) # ( !\inst4|inst7~0_combout\ & ( !\B1~input_o\ & ( (!\inst4|inst1~combout\ & ((!\B0~input_o\ & (\inst2|inst~combout\)) # (\B0~input_o\ & ((!\inst6|inst1~0_combout\))))) # 
-- (\inst4|inst1~combout\ & (((\inst2|inst~combout\ & !\inst6|inst1~0_combout\)))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0010111100001000100011100000001110001110000000110000100000101111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst4|ALT_INV_inst1~combout\,
	datab => \ALT_INV_B0~input_o\,
	datac => \inst2|ALT_INV_inst~combout\,
	datad => \inst6|ALT_INV_inst1~0_combout\,
	datae => \inst4|ALT_INV_inst7~0_combout\,
	dataf => \ALT_INV_B1~input_o\,
	combout => \inst11|inst49|inst11~0_combout\);

-- Location: LABCELL_X41_Y1_N30
\inst11|inst53|inst12~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst11|inst53|inst12~0_combout\ = ( \inst4|inst7~0_combout\ & ( \B1~input_o\ & ( (!\inst4|inst1~combout\ & (\inst2|inst~combout\ & (!\B0~input_o\ $ (!\inst6|inst1~0_combout\)))) # (\inst4|inst1~combout\ & (\inst6|inst1~0_combout\ & ((!\B0~input_o\) # 
-- (\inst2|inst~combout\)))) ) ) ) # ( !\inst4|inst7~0_combout\ & ( \B1~input_o\ & ( (!\inst4|inst1~combout\ & (((\inst2|inst~combout\ & \inst6|inst1~0_combout\)))) # (\inst4|inst1~combout\ & ((!\B0~input_o\ & (\inst2|inst~combout\ & 
-- !\inst6|inst1~0_combout\)) # (\B0~input_o\ & ((\inst6|inst1~0_combout\))))) ) ) ) # ( \inst4|inst7~0_combout\ & ( !\B1~input_o\ & ( (!\inst4|inst1~combout\ & (((\inst2|inst~combout\ & \inst6|inst1~0_combout\)))) # (\inst4|inst1~combout\ & ((!\B0~input_o\ 
-- & (\inst2|inst~combout\ & !\inst6|inst1~0_combout\)) # (\B0~input_o\ & ((\inst6|inst1~0_combout\))))) ) ) ) # ( !\inst4|inst7~0_combout\ & ( !\B1~input_o\ & ( (!\inst4|inst1~combout\ & (\inst2|inst~combout\ & (!\B0~input_o\ $ (\inst6|inst1~0_combout\)))) 
-- # (\inst4|inst1~combout\ & (!\inst6|inst1~0_combout\ & ((!\B0~input_o\) # (\inst2|inst~combout\)))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0100110100000010000001000001101100000100000110110000001001001101",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst4|ALT_INV_inst1~combout\,
	datab => \ALT_INV_B0~input_o\,
	datac => \inst2|ALT_INV_inst~combout\,
	datad => \inst6|ALT_INV_inst1~0_combout\,
	datae => \inst4|ALT_INV_inst7~0_combout\,
	dataf => \ALT_INV_B1~input_o\,
	combout => \inst11|inst53|inst12~0_combout\);

-- Location: LABCELL_X41_Y1_N6
\inst11|inst54|inst13\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst11|inst54|inst13~combout\ = ( \inst4|inst7~0_combout\ & ( \B1~input_o\ & ( (!\inst4|inst1~combout\ & (\inst6|inst1~0_combout\ & (!\B0~input_o\ $ (!\inst2|inst~combout\)))) # (\inst4|inst1~combout\ & ((!\B0~input_o\ & (!\inst2|inst~combout\ & 
-- !\inst6|inst1~0_combout\)) # (\B0~input_o\ & (\inst2|inst~combout\)))) ) ) ) # ( !\inst4|inst7~0_combout\ & ( \B1~input_o\ & ( (!\inst2|inst~combout\ & (!\inst6|inst1~0_combout\ & (!\inst4|inst1~combout\ $ (\B0~input_o\)))) # (\inst2|inst~combout\ & 
-- ((!\inst4|inst1~combout\ & (\B0~input_o\ & \inst6|inst1~0_combout\)) # (\inst4|inst1~combout\ & (!\B0~input_o\)))) ) ) ) # ( \inst4|inst7~0_combout\ & ( !\B1~input_o\ & ( (!\inst2|inst~combout\ & (!\inst6|inst1~0_combout\ & (!\inst4|inst1~combout\ $ 
-- (\B0~input_o\)))) # (\inst2|inst~combout\ & ((!\inst4|inst1~combout\ & (\B0~input_o\ & \inst6|inst1~0_combout\)) # (\inst4|inst1~combout\ & (!\B0~input_o\)))) ) ) ) # ( !\inst4|inst7~0_combout\ & ( !\B1~input_o\ & ( (!\inst4|inst1~combout\ & 
-- (!\inst6|inst1~0_combout\ & (!\B0~input_o\ $ (!\inst2|inst~combout\)))) # (\inst4|inst1~combout\ & ((!\B0~input_o\ & (!\inst2|inst~combout\ & \inst6|inst1~0_combout\)) # (\B0~input_o\ & (\inst2|inst~combout\)))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0010100101000001100101000000011010010100000001100100000100101001",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst4|ALT_INV_inst1~combout\,
	datab => \ALT_INV_B0~input_o\,
	datac => \inst2|ALT_INV_inst~combout\,
	datad => \inst6|ALT_INV_inst1~0_combout\,
	datae => \inst4|ALT_INV_inst7~0_combout\,
	dataf => \ALT_INV_B1~input_o\,
	combout => \inst11|inst54|inst13~combout\);

-- Location: LABCELL_X41_Y1_N42
\inst11|inst47|inst11~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst11|inst47|inst11~0_combout\ = ( \inst4|inst7~0_combout\ & ( \B1~input_o\ & ( (!\B0~input_o\ & (\inst4|inst1~combout\ & (!\inst2|inst~combout\ & \inst6|inst1~0_combout\))) # (\B0~input_o\ & (!\inst6|inst1~0_combout\ & ((!\inst2|inst~combout\) # 
-- (\inst4|inst1~combout\)))) ) ) ) # ( !\inst4|inst7~0_combout\ & ( \B1~input_o\ & ( (\inst6|inst1~0_combout\ & ((!\inst4|inst1~combout\ & (!\B0~input_o\ & !\inst2|inst~combout\)) # (\inst4|inst1~combout\ & ((!\B0~input_o\) # (!\inst2|inst~combout\))))) ) ) 
-- ) # ( \inst4|inst7~0_combout\ & ( !\B1~input_o\ & ( (\inst6|inst1~0_combout\ & ((!\inst4|inst1~combout\ & (!\B0~input_o\ & !\inst2|inst~combout\)) # (\inst4|inst1~combout\ & ((!\B0~input_o\) # (!\inst2|inst~combout\))))) ) ) ) # ( !\inst4|inst7~0_combout\ 
-- & ( !\B1~input_o\ & ( (!\B0~input_o\ & (\inst4|inst1~combout\ & (!\inst2|inst~combout\ & !\inst6|inst1~0_combout\))) # (\B0~input_o\ & (\inst6|inst1~0_combout\ & ((!\inst2|inst~combout\) # (\inst4|inst1~combout\)))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0100000000110001000000001101010000000000110101000011000101000000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst4|ALT_INV_inst1~combout\,
	datab => \ALT_INV_B0~input_o\,
	datac => \inst2|ALT_INV_inst~combout\,
	datad => \inst6|ALT_INV_inst1~0_combout\,
	datae => \inst4|ALT_INV_inst7~0_combout\,
	dataf => \ALT_INV_B1~input_o\,
	combout => \inst11|inst47|inst11~0_combout\);

-- Location: LABCELL_X41_Y1_N48
\inst11|inst46|inst17~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst11|inst46|inst17~0_combout\ = ( \inst4|inst7~0_combout\ & ( \B1~input_o\ & ( (!\inst4|inst1~combout\ & (\B0~input_o\ & (!\inst2|inst~combout\ $ (\inst6|inst1~0_combout\)))) # (\inst4|inst1~combout\ & ((!\inst2|inst~combout\ & (\B0~input_o\)) # 
-- (\inst2|inst~combout\ & ((!\inst6|inst1~0_combout\))))) ) ) ) # ( !\inst4|inst7~0_combout\ & ( \B1~input_o\ & ( (!\inst4|inst1~combout\ & (!\B0~input_o\ & (!\inst2|inst~combout\ $ (!\inst6|inst1~0_combout\)))) # (\inst4|inst1~combout\ & (!\B0~input_o\ $ 
-- (((\inst2|inst~combout\ & !\inst6|inst1~0_combout\))))) ) ) ) # ( \inst4|inst7~0_combout\ & ( !\B1~input_o\ & ( (!\inst4|inst1~combout\ & (!\B0~input_o\ & (!\inst2|inst~combout\ $ (!\inst6|inst1~0_combout\)))) # (\inst4|inst1~combout\ & (!\B0~input_o\ $ 
-- (((\inst2|inst~combout\ & !\inst6|inst1~0_combout\))))) ) ) ) # ( !\inst4|inst7~0_combout\ & ( !\B1~input_o\ & ( (!\inst4|inst1~combout\ & (\B0~input_o\ & (!\inst2|inst~combout\ $ (!\inst6|inst1~0_combout\)))) # (\inst4|inst1~combout\ & 
-- ((!\inst2|inst~combout\ & (\B0~input_o\)) # (\inst2|inst~combout\ & ((\inst6|inst1~0_combout\))))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0001001000110101010010011100010001001001110001000011010100010010",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst4|ALT_INV_inst1~combout\,
	datab => \ALT_INV_B0~input_o\,
	datac => \inst2|ALT_INV_inst~combout\,
	datad => \inst6|ALT_INV_inst1~0_combout\,
	datae => \inst4|ALT_INV_inst7~0_combout\,
	dataf => \ALT_INV_B1~input_o\,
	combout => \inst11|inst46|inst17~0_combout\);

-- Location: LABCELL_X41_Y1_N24
\inst11|inst|inst9\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst11|inst|inst9~combout\ = ( \inst4|inst7~0_combout\ & ( \B1~input_o\ & ( (!\B0~input_o\ & (\inst2|inst~combout\ & (!\inst4|inst1~combout\ $ (!\inst6|inst1~0_combout\)))) # (\B0~input_o\ & (!\inst4|inst1~combout\ & (!\inst2|inst~combout\ $ 
-- (!\inst6|inst1~0_combout\)))) ) ) ) # ( !\inst4|inst7~0_combout\ & ( \B1~input_o\ & ( (!\B0~input_o\ & (!\inst4|inst1~combout\ & (!\inst2|inst~combout\ $ (\inst6|inst1~0_combout\)))) # (\B0~input_o\ & (\inst2|inst~combout\ & (!\inst4|inst1~combout\ $ 
-- (!\inst6|inst1~0_combout\)))) ) ) ) # ( \inst4|inst7~0_combout\ & ( !\B1~input_o\ & ( (!\B0~input_o\ & (!\inst4|inst1~combout\ & (!\inst2|inst~combout\ $ (\inst6|inst1~0_combout\)))) # (\B0~input_o\ & (\inst2|inst~combout\ & (!\inst4|inst1~combout\ $ 
-- (!\inst6|inst1~0_combout\)))) ) ) ) # ( !\inst4|inst7~0_combout\ & ( !\B1~input_o\ & ( (!\B0~input_o\ & (\inst2|inst~combout\ & (!\inst4|inst1~combout\ $ (\inst6|inst1~0_combout\)))) # (\B0~input_o\ & (!\inst4|inst1~combout\ & (!\inst2|inst~combout\ $ 
-- (\inst6|inst1~0_combout\)))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0010100000000110100000010000101010000001000010100000011000101000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst4|ALT_INV_inst1~combout\,
	datab => \ALT_INV_B0~input_o\,
	datac => \inst2|ALT_INV_inst~combout\,
	datad => \inst6|ALT_INV_inst1~0_combout\,
	datae => \inst4|ALT_INV_inst7~0_combout\,
	dataf => \ALT_INV_B1~input_o\,
	combout => \inst11|inst|inst9~combout\);

-- Location: MLABCELL_X9_Y13_N0
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


