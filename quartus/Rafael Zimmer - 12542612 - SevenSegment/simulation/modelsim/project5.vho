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

-- DATE "05/30/2021 02:12:55"

-- 
-- Device: Altera 5CEBA7F23C7 Package FBGA484
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

ENTITY 	project5 IS
    PORT (
	segment_a : OUT std_logic;
	\0\ : IN std_logic;
	\1\ : IN std_logic;
	\2\ : IN std_logic;
	\3\ : IN std_logic;
	segment_b : OUT std_logic;
	segment_c : OUT std_logic;
	segment_d : OUT std_logic;
	segment_e : OUT std_logic;
	segment_f : OUT std_logic;
	segment_g : OUT std_logic
	);
END project5;

-- Design Ports Information
-- segment_a	=>  Location: PIN_U21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- segment_b	=>  Location: PIN_V21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- segment_c	=>  Location: PIN_W22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- segment_d	=>  Location: PIN_W21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- segment_e	=>  Location: PIN_Y22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- segment_f	=>  Location: PIN_Y21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- segment_g	=>  Location: PIN_AA22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- 0	=>  Location: PIN_U13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- 3	=>  Location: PIN_T12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- 1	=>  Location: PIN_V13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- 2	=>  Location: PIN_T13,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF project5 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_segment_a : std_logic;
SIGNAL \ww_0\ : std_logic;
SIGNAL \ww_1\ : std_logic;
SIGNAL \ww_2\ : std_logic;
SIGNAL \ww_3\ : std_logic;
SIGNAL ww_segment_b : std_logic;
SIGNAL ww_segment_c : std_logic;
SIGNAL ww_segment_d : std_logic;
SIGNAL ww_segment_e : std_logic;
SIGNAL ww_segment_f : std_logic;
SIGNAL ww_segment_g : std_logic;
SIGNAL \~QUARTUS_CREATED_GND~I_combout\ : std_logic;
SIGNAL \2~input_o\ : std_logic;
SIGNAL \0~input_o\ : std_logic;
SIGNAL \1~input_o\ : std_logic;
SIGNAL \3~input_o\ : std_logic;
SIGNAL \inst|inst9~combout\ : std_logic;
SIGNAL \inst46|inst17~0_combout\ : std_logic;
SIGNAL \inst47|inst11~0_combout\ : std_logic;
SIGNAL \inst54|inst13~combout\ : std_logic;
SIGNAL \inst49|inst11~0_combout\ : std_logic;
SIGNAL \inst53|inst12~0_combout\ : std_logic;
SIGNAL \inst51|inst12~combout\ : std_logic;
SIGNAL \ALT_INV_2~input_o\ : std_logic;
SIGNAL \ALT_INV_1~input_o\ : std_logic;
SIGNAL \ALT_INV_3~input_o\ : std_logic;
SIGNAL \ALT_INV_0~input_o\ : std_logic;

BEGIN

segment_a <= ww_segment_a;
\ww_0\ <= \0\;
\ww_1\ <= \1\;
\ww_2\ <= \2\;
\ww_3\ <= \3\;
segment_b <= ww_segment_b;
segment_c <= ww_segment_c;
segment_d <= ww_segment_d;
segment_e <= ww_segment_e;
segment_f <= ww_segment_f;
segment_g <= ww_segment_g;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
\ALT_INV_2~input_o\ <= NOT \2~input_o\;
\ALT_INV_1~input_o\ <= NOT \1~input_o\;
\ALT_INV_3~input_o\ <= NOT \3~input_o\;
\ALT_INV_0~input_o\ <= NOT \0~input_o\;

-- Location: IOOBUF_X72_Y0_N53
\segment_a~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst|inst9~combout\,
	devoe => ww_devoe,
	o => ww_segment_a);

-- Location: IOOBUF_X70_Y0_N36
\segment_b~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst46|inst17~0_combout\,
	devoe => ww_devoe,
	o => ww_segment_b);

-- Location: IOOBUF_X66_Y0_N76
\segment_c~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst47|inst11~0_combout\,
	devoe => ww_devoe,
	o => ww_segment_c);

-- Location: IOOBUF_X68_Y0_N36
\segment_d~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst54|inst13~combout\,
	devoe => ww_devoe,
	o => ww_segment_d);

-- Location: IOOBUF_X66_Y0_N93
\segment_e~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst49|inst11~0_combout\,
	devoe => ww_devoe,
	o => ww_segment_e);

-- Location: IOOBUF_X68_Y0_N53
\segment_f~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst53|inst12~0_combout\,
	devoe => ww_devoe,
	o => ww_segment_f);

-- Location: IOOBUF_X64_Y0_N36
\segment_g~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst51|inst12~combout\,
	devoe => ww_devoe,
	o => ww_segment_g);

-- Location: IOIBUF_X52_Y0_N1
\2~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => \ww_2\,
	o => \2~input_o\);

-- Location: IOIBUF_X50_Y0_N41
\0~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => \ww_0\,
	o => \0~input_o\);

-- Location: IOIBUF_X50_Y0_N58
\1~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => \ww_1\,
	o => \1~input_o\);

-- Location: IOIBUF_X52_Y0_N18
\3~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => \ww_3\,
	o => \3~input_o\);

-- Location: LABCELL_X62_Y1_N30
\inst|inst9\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst|inst9~combout\ = ( \1~input_o\ & ( \3~input_o\ & ( (!\2~input_o\ & \0~input_o\) ) ) ) # ( !\1~input_o\ & ( \3~input_o\ & ( !\2~input_o\ $ (\0~input_o\) ) ) ) # ( \1~input_o\ & ( !\3~input_o\ & ( (!\2~input_o\ & !\0~input_o\) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000110000001100000011000011110000110000110000001100",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_2~input_o\,
	datac => \ALT_INV_0~input_o\,
	datae => \ALT_INV_1~input_o\,
	dataf => \ALT_INV_3~input_o\,
	combout => \inst|inst9~combout\);

-- Location: LABCELL_X62_Y1_N39
\inst46|inst17~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst46|inst17~0_combout\ = ( \1~input_o\ & ( \3~input_o\ & ( !\0~input_o\ $ (\2~input_o\) ) ) ) # ( !\1~input_o\ & ( \3~input_o\ & ( (\0~input_o\ & \2~input_o\) ) ) ) # ( \1~input_o\ & ( !\3~input_o\ & ( (\2~input_o\) # (\0~input_o\) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000010111110101111100000101000001011010010110100101",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_0~input_o\,
	datac => \ALT_INV_2~input_o\,
	datae => \ALT_INV_1~input_o\,
	dataf => \ALT_INV_3~input_o\,
	combout => \inst46|inst17~0_combout\);

-- Location: LABCELL_X62_Y1_N42
\inst47|inst11~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst47|inst11~0_combout\ = ( \1~input_o\ & ( \3~input_o\ & ( (\2~input_o\ & \0~input_o\) ) ) ) # ( \1~input_o\ & ( !\3~input_o\ & ( \0~input_o\ ) ) ) # ( !\1~input_o\ & ( !\3~input_o\ & ( (\2~input_o\ & !\0~input_o\) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0011000000110000000011110000111100000000000000000000001100000011",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_2~input_o\,
	datac => \ALT_INV_0~input_o\,
	datae => \ALT_INV_1~input_o\,
	dataf => \ALT_INV_3~input_o\,
	combout => \inst47|inst11~0_combout\);

-- Location: LABCELL_X62_Y1_N21
\inst54|inst13\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst54|inst13~combout\ = ( \1~input_o\ & ( \3~input_o\ & ( \2~input_o\ ) ) ) # ( !\1~input_o\ & ( \3~input_o\ & ( (!\0~input_o\ & !\2~input_o\) ) ) ) # ( \1~input_o\ & ( !\3~input_o\ & ( (!\0~input_o\ & !\2~input_o\) ) ) ) # ( !\1~input_o\ & ( 
-- !\3~input_o\ & ( (\0~input_o\ & \2~input_o\) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000010100000101101000001010000010100000101000000000111100001111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_0~input_o\,
	datac => \ALT_INV_2~input_o\,
	datae => \ALT_INV_1~input_o\,
	dataf => \ALT_INV_3~input_o\,
	combout => \inst54|inst13~combout\);

-- Location: LABCELL_X62_Y1_N24
\inst49|inst11~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst49|inst11~0_combout\ = ( \1~input_o\ & ( \3~input_o\ & ( !\0~input_o\ ) ) ) # ( !\1~input_o\ & ( \3~input_o\ & ( (!\2~input_o\) # (!\0~input_o\) ) ) ) # ( \1~input_o\ & ( !\3~input_o\ & ( (!\2~input_o\ & !\0~input_o\) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000110000001100000011111100111111001111000011110000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_2~input_o\,
	datac => \ALT_INV_0~input_o\,
	datae => \ALT_INV_1~input_o\,
	dataf => \ALT_INV_3~input_o\,
	combout => \inst49|inst11~0_combout\);

-- Location: LABCELL_X62_Y1_N3
\inst53|inst12~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst53|inst12~0_combout\ = ( \1~input_o\ & ( \3~input_o\ & ( !\0~input_o\ $ (!\2~input_o\) ) ) ) # ( !\1~input_o\ & ( \3~input_o\ & ( !\0~input_o\ ) ) ) # ( !\1~input_o\ & ( !\3~input_o\ & ( (!\0~input_o\ & \2~input_o\) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000101000001010000000000000000010101010101010100101101001011010",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_0~input_o\,
	datac => \ALT_INV_2~input_o\,
	datae => \ALT_INV_1~input_o\,
	dataf => \ALT_INV_3~input_o\,
	combout => \inst53|inst12~0_combout\);

-- Location: LABCELL_X62_Y1_N6
\inst51|inst12\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst51|inst12~combout\ = ( \1~input_o\ & ( \3~input_o\ & ( (\2~input_o\ & !\0~input_o\) ) ) ) # ( !\1~input_o\ & ( \3~input_o\ & ( (!\2~input_o\ & !\0~input_o\) ) ) ) # ( \1~input_o\ & ( !\3~input_o\ & ( (!\2~input_o\ & \0~input_o\) ) ) ) # ( 
-- !\1~input_o\ & ( !\3~input_o\ & ( (!\2~input_o\ & !\0~input_o\) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "1100000011000000000011000000110011000000110000000011000000110000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_2~input_o\,
	datac => \ALT_INV_0~input_o\,
	datae => \ALT_INV_1~input_o\,
	dataf => \ALT_INV_3~input_o\,
	combout => \inst51|inst12~combout\);

-- Location: LABCELL_X51_Y71_N3
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


