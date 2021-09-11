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

-- DATE "07/06/2021 11:51:16"

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

ENTITY 	project10 IS
    PORT (
	Cout : OUT std_logic;
	A0 : IN std_logic;
	B0 : IN std_logic;
	A1 : IN std_logic;
	B1 : IN std_logic;
	A2 : IN std_logic;
	B2 : IN std_logic;
	A3 : IN std_logic;
	B3 : IN std_logic;
	display_g : OUT std_logic;
	display_f : OUT std_logic;
	display_e : OUT std_logic;
	display_d : OUT std_logic;
	display_c : OUT std_logic;
	display_b : OUT std_logic;
	display_a : OUT std_logic
	);
END project10;

-- Design Ports Information
-- Cout	=>  Location: PIN_P22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- display_g	=>  Location: PIN_N19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- display_f	=>  Location: PIN_M18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- display_e	=>  Location: PIN_R17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- display_d	=>  Location: PIN_M22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- display_c	=>  Location: PIN_L22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- display_b	=>  Location: PIN_P16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- display_a	=>  Location: PIN_P17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A0	=>  Location: PIN_M20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B0	=>  Location: PIN_M16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A1	=>  Location: PIN_N16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B1	=>  Location: PIN_N20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A2	=>  Location: PIN_P18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B2	=>  Location: PIN_K17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A3	=>  Location: PIN_N21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B3	=>  Location: PIN_P19,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF project10 IS
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
SIGNAL ww_A0 : std_logic;
SIGNAL ww_B0 : std_logic;
SIGNAL ww_A1 : std_logic;
SIGNAL ww_B1 : std_logic;
SIGNAL ww_A2 : std_logic;
SIGNAL ww_B2 : std_logic;
SIGNAL ww_A3 : std_logic;
SIGNAL ww_B3 : std_logic;
SIGNAL ww_display_g : std_logic;
SIGNAL ww_display_f : std_logic;
SIGNAL ww_display_e : std_logic;
SIGNAL ww_display_d : std_logic;
SIGNAL ww_display_c : std_logic;
SIGNAL ww_display_b : std_logic;
SIGNAL ww_display_a : std_logic;
SIGNAL \~QUARTUS_CREATED_GND~I_combout\ : std_logic;
SIGNAL \B3~input_o\ : std_logic;
SIGNAL \A2~input_o\ : std_logic;
SIGNAL \A3~input_o\ : std_logic;
SIGNAL \B2~input_o\ : std_logic;
SIGNAL \inst11|inst7~0_combout\ : std_logic;
SIGNAL \B0~input_o\ : std_logic;
SIGNAL \B1~input_o\ : std_logic;
SIGNAL \A1~input_o\ : std_logic;
SIGNAL \A0~input_o\ : std_logic;
SIGNAL \inst14|inst7~0_combout\ : std_logic;
SIGNAL \inst14|inst1~0_combout\ : std_logic;
SIGNAL \inst11|inst1~combout\ : std_logic;
SIGNAL \inst10|inst~combout\ : std_logic;
SIGNAL \inst15|inst51|inst12~0_combout\ : std_logic;
SIGNAL \inst15|inst53|inst12~0_combout\ : std_logic;
SIGNAL \inst15|inst49|inst11~0_combout\ : std_logic;
SIGNAL \inst15|inst54|inst13~combout\ : std_logic;
SIGNAL \inst15|inst47|inst11~0_combout\ : std_logic;
SIGNAL \inst15|inst46|inst17~0_combout\ : std_logic;
SIGNAL \inst15|inst|inst9~combout\ : std_logic;
SIGNAL \ALT_INV_A0~input_o\ : std_logic;
SIGNAL \inst11|ALT_INV_inst7~0_combout\ : std_logic;
SIGNAL \inst10|ALT_INV_inst~combout\ : std_logic;
SIGNAL \inst11|ALT_INV_inst1~combout\ : std_logic;
SIGNAL \inst14|ALT_INV_inst1~0_combout\ : std_logic;
SIGNAL \ALT_INV_B3~input_o\ : std_logic;
SIGNAL \ALT_INV_A3~input_o\ : std_logic;
SIGNAL \ALT_INV_B2~input_o\ : std_logic;
SIGNAL \ALT_INV_A2~input_o\ : std_logic;
SIGNAL \ALT_INV_B1~input_o\ : std_logic;
SIGNAL \ALT_INV_A1~input_o\ : std_logic;
SIGNAL \ALT_INV_B0~input_o\ : std_logic;

BEGIN

Cout <= ww_Cout;
ww_A0 <= A0;
ww_B0 <= B0;
ww_A1 <= A1;
ww_B1 <= B1;
ww_A2 <= A2;
ww_B2 <= B2;
ww_A3 <= A3;
ww_B3 <= B3;
display_g <= ww_display_g;
display_f <= ww_display_f;
display_e <= ww_display_e;
display_d <= ww_display_d;
display_c <= ww_display_c;
display_b <= ww_display_b;
display_a <= ww_display_a;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
\ALT_INV_A0~input_o\ <= NOT \A0~input_o\;
\inst11|ALT_INV_inst7~0_combout\ <= NOT \inst11|inst7~0_combout\;
\inst10|ALT_INV_inst~combout\ <= NOT \inst10|inst~combout\;
\inst11|ALT_INV_inst1~combout\ <= NOT \inst11|inst1~combout\;
\inst14|ALT_INV_inst1~0_combout\ <= NOT \inst14|inst1~0_combout\;
\ALT_INV_B3~input_o\ <= NOT \B3~input_o\;
\ALT_INV_A3~input_o\ <= NOT \A3~input_o\;
\ALT_INV_B2~input_o\ <= NOT \B2~input_o\;
\ALT_INV_A2~input_o\ <= NOT \A2~input_o\;
\ALT_INV_B1~input_o\ <= NOT \B1~input_o\;
\ALT_INV_A1~input_o\ <= NOT \A1~input_o\;
\ALT_INV_B0~input_o\ <= NOT \B0~input_o\;

-- Location: IOOBUF_X54_Y16_N56
\Cout~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst14|inst7~0_combout\,
	devoe => ww_devoe,
	o => ww_Cout);

-- Location: IOOBUF_X54_Y19_N5
\display_g~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst15|inst51|inst12~0_combout\,
	devoe => ww_devoe,
	o => ww_display_g);

-- Location: IOOBUF_X54_Y19_N22
\display_f~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst15|inst53|inst12~0_combout\,
	devoe => ww_devoe,
	o => ww_display_f);

-- Location: IOOBUF_X54_Y16_N22
\display_e~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst15|inst49|inst11~0_combout\,
	devoe => ww_devoe,
	o => ww_display_e);

-- Location: IOOBUF_X54_Y19_N39
\display_d~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst15|inst54|inst13~combout\,
	devoe => ww_devoe,
	o => ww_display_d);

-- Location: IOOBUF_X54_Y19_N56
\display_c~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst15|inst47|inst11~0_combout\,
	devoe => ww_devoe,
	o => ww_display_c);

-- Location: IOOBUF_X54_Y17_N5
\display_b~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst15|inst46|inst17~0_combout\,
	devoe => ww_devoe,
	o => ww_display_b);

-- Location: IOOBUF_X54_Y17_N22
\display_a~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst15|inst|inst9~combout\,
	devoe => ww_devoe,
	o => ww_display_a);

-- Location: IOIBUF_X54_Y17_N38
\B3~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B3,
	o => \B3~input_o\);

-- Location: IOIBUF_X54_Y17_N55
\A2~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A2,
	o => \A2~input_o\);

-- Location: IOIBUF_X54_Y18_N95
\A3~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A3,
	o => \A3~input_o\);

-- Location: IOIBUF_X54_Y20_N4
\B2~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B2,
	o => \B2~input_o\);

-- Location: LABCELL_X53_Y18_N0
\inst11|inst7~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst11|inst7~0_combout\ = ( \B2~input_o\ & ( (!\A2~input_o\) # ((\B3~input_o\ & !\A3~input_o\)) ) ) # ( !\B2~input_o\ & ( (\B3~input_o\ & (!\A2~input_o\ & !\A3~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0100000001000000010000000100000011011100110111001101110011011100",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_B3~input_o\,
	datab => \ALT_INV_A2~input_o\,
	datac => \ALT_INV_A3~input_o\,
	dataf => \ALT_INV_B2~input_o\,
	combout => \inst11|inst7~0_combout\);

-- Location: IOIBUF_X54_Y18_N61
\B0~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B0,
	o => \B0~input_o\);

-- Location: IOIBUF_X54_Y18_N78
\B1~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B1,
	o => \B1~input_o\);

-- Location: IOIBUF_X54_Y18_N44
\A1~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A1,
	o => \A1~input_o\);

-- Location: IOIBUF_X54_Y20_N38
\A0~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A0,
	o => \A0~input_o\);

-- Location: LABCELL_X53_Y18_N39
\inst14|inst7~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst14|inst7~0_combout\ = ( \A0~input_o\ & ( (!\B0~input_o\) # ((!\inst11|inst7~0_combout\ & ((!\B1~input_o\) # (\A1~input_o\))) # (\inst11|inst7~0_combout\ & (!\B1~input_o\ & \A1~input_o\))) ) ) # ( !\A0~input_o\ & ( (!\B0~input_o\ & 
-- ((!\inst11|inst7~0_combout\ & ((!\B1~input_o\) # (\A1~input_o\))) # (\inst11|inst7~0_combout\ & (!\B1~input_o\ & \A1~input_o\)))) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "1000000011001000100000001100100011101100111111101110110011111110",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst11|ALT_INV_inst7~0_combout\,
	datab => \ALT_INV_B0~input_o\,
	datac => \ALT_INV_B1~input_o\,
	datad => \ALT_INV_A1~input_o\,
	dataf => \ALT_INV_A0~input_o\,
	combout => \inst14|inst7~0_combout\);

-- Location: LABCELL_X53_Y18_N42
\inst14|inst1~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst14|inst1~0_combout\ = ( !\B0~input_o\ & ( \A0~input_o\ ) ) # ( \B0~input_o\ & ( !\A0~input_o\ ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000111111111111111111111111111111110000000000000000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datae => \ALT_INV_B0~input_o\,
	dataf => \ALT_INV_A0~input_o\,
	combout => \inst14|inst1~0_combout\);

-- Location: LABCELL_X53_Y18_N3
\inst11|inst1\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst11|inst1~combout\ = ( \B2~input_o\ & ( !\A2~input_o\ $ (((!\B3~input_o\) # (\A3~input_o\))) ) ) # ( !\B2~input_o\ & ( !\A2~input_o\ $ (((\B3~input_o\ & !\A3~input_o\))) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "1001100111001100100110011100110001100110001100110110011000110011",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_B3~input_o\,
	datab => \ALT_INV_A2~input_o\,
	datad => \ALT_INV_A3~input_o\,
	dataf => \ALT_INV_B2~input_o\,
	combout => \inst11|inst1~combout\);

-- Location: LABCELL_X53_Y18_N36
\inst10|inst\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst10|inst~combout\ = !\B3~input_o\ $ (!\A3~input_o\)

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000111111110000000011111111000000001111111100000000111111110000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datac => \ALT_INV_B3~input_o\,
	datad => \ALT_INV_A3~input_o\,
	combout => \inst10|inst~combout\);

-- Location: LABCELL_X53_Y18_N18
\inst15|inst51|inst12~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst15|inst51|inst12~0_combout\ = ( \inst10|inst~combout\ & ( \B1~input_o\ & ( (!\inst11|inst7~0_combout\ & ((!\inst14|inst1~0_combout\ & (\inst11|inst1~combout\ & \A1~input_o\)) # (\inst14|inst1~0_combout\ & (!\inst11|inst1~combout\ & !\A1~input_o\)))) 
-- # (\inst11|inst7~0_combout\ & (\inst14|inst1~0_combout\ & (!\inst11|inst1~combout\ $ (!\A1~input_o\)))) ) ) ) # ( !\inst10|inst~combout\ & ( \B1~input_o\ & ( (\inst11|inst1~combout\ & (!\inst14|inst1~0_combout\ $ (((\inst11|inst7~0_combout\ & 
-- !\A1~input_o\))))) ) ) ) # ( \inst10|inst~combout\ & ( !\B1~input_o\ & ( (!\inst11|inst7~0_combout\ & (!\inst14|inst1~0_combout\ & (!\inst11|inst1~combout\ $ (!\A1~input_o\)))) # (\inst11|inst7~0_combout\ & ((!\inst14|inst1~0_combout\ & 
-- (\inst11|inst1~combout\ & \A1~input_o\)) # (\inst14|inst1~0_combout\ & (!\inst11|inst1~combout\ & !\A1~input_o\)))) ) ) ) # ( !\inst10|inst~combout\ & ( !\B1~input_o\ & ( (\inst11|inst1~combout\ & (!\inst14|inst1~0_combout\ $ (((!\inst11|inst7~0_combout\ 
-- & \A1~input_o\))))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000110000000110000110001000010000001001000011000010000100011000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst11|ALT_INV_inst7~0_combout\,
	datab => \inst14|ALT_INV_inst1~0_combout\,
	datac => \inst11|ALT_INV_inst1~combout\,
	datad => \ALT_INV_A1~input_o\,
	datae => \inst10|ALT_INV_inst~combout\,
	dataf => \ALT_INV_B1~input_o\,
	combout => \inst15|inst51|inst12~0_combout\);

-- Location: LABCELL_X53_Y18_N54
\inst15|inst53|inst12~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst15|inst53|inst12~0_combout\ = ( \inst10|inst~combout\ & ( \B1~input_o\ & ( !\inst14|inst1~0_combout\ $ (((!\inst11|inst7~0_combout\ & (!\inst11|inst1~combout\ & !\A1~input_o\)) # (\inst11|inst7~0_combout\ & ((!\inst11|inst1~combout\) # 
-- (!\A1~input_o\))))) ) ) ) # ( !\inst10|inst~combout\ & ( \B1~input_o\ & ( (!\inst11|inst1~combout\ & ((!\inst11|inst7~0_combout\ & (!\inst14|inst1~0_combout\ & \A1~input_o\)) # (\inst11|inst7~0_combout\ & (\inst14|inst1~0_combout\ & !\A1~input_o\)))) ) ) 
-- ) # ( \inst10|inst~combout\ & ( !\B1~input_o\ & ( !\inst14|inst1~0_combout\ $ (((!\inst11|inst7~0_combout\ & (\inst11|inst1~combout\ & \A1~input_o\)) # (\inst11|inst7~0_combout\ & (!\inst11|inst1~combout\ & !\A1~input_o\)))) ) ) ) # ( 
-- !\inst10|inst~combout\ & ( !\B1~input_o\ & ( (!\inst14|inst1~0_combout\ & (!\inst11|inst1~combout\ & (!\inst11|inst7~0_combout\ $ (\A1~input_o\)))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "1000000001000000100111001100011000010000100000000011100110011100",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst11|ALT_INV_inst7~0_combout\,
	datab => \inst14|ALT_INV_inst1~0_combout\,
	datac => \inst11|ALT_INV_inst1~combout\,
	datad => \ALT_INV_A1~input_o\,
	datae => \inst10|ALT_INV_inst~combout\,
	dataf => \ALT_INV_B1~input_o\,
	combout => \inst15|inst53|inst12~0_combout\);

-- Location: LABCELL_X53_Y18_N30
\inst15|inst49|inst11~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst15|inst49|inst11~0_combout\ = ( \inst10|inst~combout\ & ( \B1~input_o\ & ( (!\inst11|inst1~combout\ & (!\inst14|inst1~0_combout\ $ (((!\A1~input_o\) # (\inst11|inst7~0_combout\))))) # (\inst11|inst1~combout\ & ((!\inst11|inst7~0_combout\ $ 
-- (!\A1~input_o\)) # (\inst14|inst1~0_combout\))) ) ) ) # ( !\inst10|inst~combout\ & ( \B1~input_o\ & ( (\inst14|inst1~0_combout\ & (\inst11|inst1~combout\ & (!\inst11|inst7~0_combout\ $ (\A1~input_o\)))) ) ) ) # ( \inst10|inst~combout\ & ( !\B1~input_o\ & 
-- ( (!\inst11|inst7~0_combout\ & ((!\inst14|inst1~0_combout\) # ((\inst11|inst1~combout\ & !\A1~input_o\)))) # (\inst11|inst7~0_combout\ & ((!\inst14|inst1~0_combout\ & ((\A1~input_o\))) # (\inst14|inst1~0_combout\ & ((!\A1~input_o\) # 
-- (\inst11|inst1~combout\))))) ) ) ) # ( !\inst10|inst~combout\ & ( !\B1~input_o\ & ( (\inst11|inst1~combout\ & ((!\inst11|inst7~0_combout\ & (!\inst14|inst1~0_combout\ & \A1~input_o\)) # (\inst11|inst7~0_combout\ & (\inst14|inst1~0_combout\ & 
-- !\A1~input_o\)))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000100001000100110111100110100000010000000010011011110011011",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst11|ALT_INV_inst7~0_combout\,
	datab => \inst14|ALT_INV_inst1~0_combout\,
	datac => \inst11|ALT_INV_inst1~combout\,
	datad => \ALT_INV_A1~input_o\,
	datae => \inst10|ALT_INV_inst~combout\,
	dataf => \ALT_INV_B1~input_o\,
	combout => \inst15|inst49|inst11~0_combout\);

-- Location: LABCELL_X53_Y18_N6
\inst15|inst54|inst13\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst15|inst54|inst13~combout\ = ( \inst10|inst~combout\ & ( \B1~input_o\ & ( (!\inst11|inst1~combout\ & (!\inst11|inst7~0_combout\ $ (((\A1~input_o\))))) # (\inst11|inst1~combout\ & ((!\inst11|inst7~0_combout\ & (!\inst14|inst1~0_combout\ & 
-- \A1~input_o\)) # (\inst11|inst7~0_combout\ & (\inst14|inst1~0_combout\ & !\A1~input_o\)))) ) ) ) # ( !\inst10|inst~combout\ & ( \B1~input_o\ & ( (!\inst11|inst7~0_combout\ & (\inst14|inst1~0_combout\ & (!\inst11|inst1~combout\ $ (!\A1~input_o\)))) # 
-- (\inst11|inst7~0_combout\ & ((!\inst14|inst1~0_combout\ & (!\inst11|inst1~combout\ & !\A1~input_o\)) # (\inst14|inst1~0_combout\ & (\inst11|inst1~combout\ & \A1~input_o\)))) ) ) ) # ( \inst10|inst~combout\ & ( !\B1~input_o\ & ( (!\inst11|inst1~combout\ & 
-- (!\inst11|inst7~0_combout\ $ (((!\A1~input_o\))))) # (\inst11|inst1~combout\ & (!\inst14|inst1~0_combout\ & (!\inst11|inst7~0_combout\ $ (\A1~input_o\)))) ) ) ) # ( !\inst10|inst~combout\ & ( !\B1~input_o\ & ( (!\inst11|inst7~0_combout\ & 
-- ((!\inst14|inst1~0_combout\ & (\inst11|inst1~combout\ & \A1~input_o\)) # (\inst14|inst1~0_combout\ & (!\inst11|inst1~combout\ & !\A1~input_o\)))) # (\inst11|inst7~0_combout\ & (\inst14|inst1~0_combout\ & (!\inst11|inst1~combout\ $ (!\A1~input_o\)))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0010000100011000010110001010010001000010001000011010000101011000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst11|ALT_INV_inst7~0_combout\,
	datab => \inst14|ALT_INV_inst1~0_combout\,
	datac => \inst11|ALT_INV_inst1~combout\,
	datad => \ALT_INV_A1~input_o\,
	datae => \inst10|ALT_INV_inst~combout\,
	dataf => \ALT_INV_B1~input_o\,
	combout => \inst15|inst54|inst13~combout\);

-- Location: LABCELL_X53_Y18_N12
\inst15|inst47|inst11~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst15|inst47|inst11~0_combout\ = ( \inst10|inst~combout\ & ( \B1~input_o\ & ( (!\inst14|inst1~0_combout\ & (!\inst11|inst1~combout\ & (!\inst11|inst7~0_combout\ $ (\A1~input_o\)))) ) ) ) # ( !\inst10|inst~combout\ & ( \B1~input_o\ & ( 
-- (!\inst11|inst1~combout\ & (!\inst14|inst1~0_combout\ $ (((\inst11|inst7~0_combout\ & !\A1~input_o\))))) # (\inst11|inst1~combout\ & (!\inst14|inst1~0_combout\ & (!\inst11|inst7~0_combout\ $ (\A1~input_o\)))) ) ) ) # ( \inst10|inst~combout\ & ( 
-- !\B1~input_o\ & ( (!\inst11|inst1~combout\ & ((!\inst11|inst7~0_combout\ & (\inst14|inst1~0_combout\ & \A1~input_o\)) # (\inst11|inst7~0_combout\ & (!\inst14|inst1~0_combout\ & !\A1~input_o\)))) ) ) ) # ( !\inst10|inst~combout\ & ( !\B1~input_o\ & ( 
-- (!\inst11|inst7~0_combout\ & ((!\inst14|inst1~0_combout\ & (!\inst11|inst1~combout\ & !\A1~input_o\)) # (\inst14|inst1~0_combout\ & ((\A1~input_o\))))) # (\inst11|inst7~0_combout\ & (!\inst14|inst1~0_combout\ & ((!\inst11|inst1~combout\) # 
-- (!\A1~input_o\)))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "1100010001100010010000000010000010011000110001001000000001000000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst11|ALT_INV_inst7~0_combout\,
	datab => \inst14|ALT_INV_inst1~0_combout\,
	datac => \inst11|ALT_INV_inst1~combout\,
	datad => \ALT_INV_A1~input_o\,
	datae => \inst10|ALT_INV_inst~combout\,
	dataf => \ALT_INV_B1~input_o\,
	combout => \inst15|inst47|inst11~0_combout\);

-- Location: LABCELL_X53_Y18_N48
\inst15|inst46|inst17~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst15|inst46|inst17~0_combout\ = ( \inst10|inst~combout\ & ( \B1~input_o\ & ( (!\inst11|inst1~combout\ & (!\inst14|inst1~0_combout\ $ (((!\inst11|inst7~0_combout\ & \A1~input_o\))))) # (\inst11|inst1~combout\ & (\inst14|inst1~0_combout\ & 
-- (!\inst11|inst7~0_combout\ $ (\A1~input_o\)))) ) ) ) # ( !\inst10|inst~combout\ & ( \B1~input_o\ & ( (!\inst14|inst1~0_combout\ & (!\inst11|inst7~0_combout\ $ (((\A1~input_o\))))) # (\inst14|inst1~0_combout\ & (!\inst11|inst1~combout\ & 
-- (!\inst11|inst7~0_combout\ $ (\A1~input_o\)))) ) ) ) # ( \inst10|inst~combout\ & ( !\B1~input_o\ & ( (!\inst14|inst1~0_combout\ & ((!\inst11|inst7~0_combout\ & (\inst11|inst1~combout\ & \A1~input_o\)) # (\inst11|inst7~0_combout\ & (!\inst11|inst1~combout\ 
-- & !\A1~input_o\)))) # (\inst14|inst1~0_combout\ & (!\inst11|inst1~combout\ $ (((\inst11|inst7~0_combout\ & !\A1~input_o\))))) ) ) ) # ( !\inst10|inst~combout\ & ( !\B1~input_o\ & ( (!\inst11|inst7~0_combout\ & (\A1~input_o\ & ((!\inst11|inst1~combout\) # 
-- (\inst14|inst1~0_combout\)))) # (\inst11|inst7~0_combout\ & (!\A1~input_o\ & ((!\inst14|inst1~0_combout\) # (!\inst11|inst1~combout\)))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0101010010100010011000010011100010101000010101001100001001100001",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst11|ALT_INV_inst7~0_combout\,
	datab => \inst14|ALT_INV_inst1~0_combout\,
	datac => \inst11|ALT_INV_inst1~combout\,
	datad => \ALT_INV_A1~input_o\,
	datae => \inst10|ALT_INV_inst~combout\,
	dataf => \ALT_INV_B1~input_o\,
	combout => \inst15|inst46|inst17~0_combout\);

-- Location: LABCELL_X53_Y18_N24
\inst15|inst|inst9\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst15|inst|inst9~combout\ = ( \inst10|inst~combout\ & ( \B1~input_o\ & ( (!\inst14|inst1~0_combout\ & (!\inst11|inst1~combout\ $ (((!\inst11|inst7~0_combout\) # (\A1~input_o\))))) # (\inst14|inst1~0_combout\ & ((!\inst11|inst7~0_combout\ & 
-- (!\inst11|inst1~combout\ & \A1~input_o\)) # (\inst11|inst7~0_combout\ & (\inst11|inst1~combout\ & !\A1~input_o\)))) ) ) ) # ( !\inst10|inst~combout\ & ( \B1~input_o\ & ( (\inst14|inst1~0_combout\ & (\inst11|inst1~combout\ & (!\inst11|inst7~0_combout\ $ 
-- (\A1~input_o\)))) ) ) ) # ( \inst10|inst~combout\ & ( !\B1~input_o\ & ( (!\inst11|inst1~combout\ & (\inst14|inst1~0_combout\ & (!\inst11|inst7~0_combout\ $ (\A1~input_o\)))) # (\inst11|inst1~combout\ & (!\inst14|inst1~0_combout\ $ 
-- (((!\inst11|inst7~0_combout\ & \A1~input_o\))))) ) ) ) # ( !\inst10|inst~combout\ & ( !\B1~input_o\ & ( (\inst11|inst1~combout\ & ((!\inst11|inst7~0_combout\ & (!\inst14|inst1~0_combout\ & \A1~input_o\)) # (\inst11|inst7~0_combout\ & 
-- (\inst14|inst1~0_combout\ & !\A1~input_o\)))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000100001000001011000001011000000010000000010100100100101100",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst11|ALT_INV_inst7~0_combout\,
	datab => \inst14|ALT_INV_inst1~0_combout\,
	datac => \inst11|ALT_INV_inst1~combout\,
	datad => \ALT_INV_A1~input_o\,
	datae => \inst10|ALT_INV_inst~combout\,
	dataf => \ALT_INV_B1~input_o\,
	combout => \inst15|inst|inst9~combout\);

-- Location: MLABCELL_X13_Y36_N0
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


