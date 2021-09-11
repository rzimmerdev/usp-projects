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

-- DATE "06/29/2021 11:58:57"

-- 
-- Device: Altera 5CEBA2F23C7 Package FBGA484
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

ENTITY 	project9 IS
    PORT (
	display_g : OUT std_logic;
	A0 : IN std_logic;
	B0 : IN std_logic;
	A1 : IN std_logic;
	B1 : IN std_logic;
	A2 : IN std_logic;
	B2 : IN std_logic;
	A3 : IN std_logic;
	B3 : IN std_logic;
	display_f : OUT std_logic;
	display_e : OUT std_logic;
	display_d : OUT std_logic;
	display_c : OUT std_logic;
	display_b : OUT std_logic;
	display_a : OUT std_logic;
	Cout : OUT std_logic
	);
END project9;

-- Design Ports Information
-- display_g	=>  Location: PIN_U21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- display_f	=>  Location: PIN_V21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- display_e	=>  Location: PIN_W22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- display_d	=>  Location: PIN_W21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- display_c	=>  Location: PIN_Y22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- display_b	=>  Location: PIN_Y21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- display_a	=>  Location: PIN_AA22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Cout	=>  Location: PIN_Y15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A3	=>  Location: PIN_AA13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B3	=>  Location: PIN_T12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A1	=>  Location: PIN_AB15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B1	=>  Location: PIN_V13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A2	=>  Location: PIN_AA14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B2	=>  Location: PIN_T13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A0	=>  Location: PIN_AA15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B0	=>  Location: PIN_U13,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF project9 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_display_g : std_logic;
SIGNAL ww_A0 : std_logic;
SIGNAL ww_B0 : std_logic;
SIGNAL ww_A1 : std_logic;
SIGNAL ww_B1 : std_logic;
SIGNAL ww_A2 : std_logic;
SIGNAL ww_B2 : std_logic;
SIGNAL ww_A3 : std_logic;
SIGNAL ww_B3 : std_logic;
SIGNAL ww_display_f : std_logic;
SIGNAL ww_display_e : std_logic;
SIGNAL ww_display_d : std_logic;
SIGNAL ww_display_c : std_logic;
SIGNAL ww_display_b : std_logic;
SIGNAL ww_display_a : std_logic;
SIGNAL ww_Cout : std_logic;
SIGNAL \~QUARTUS_CREATED_GND~I_combout\ : std_logic;
SIGNAL \A3~input_o\ : std_logic;
SIGNAL \B3~input_o\ : std_logic;
SIGNAL \inst|inst10~0_combout\ : std_logic;
SIGNAL \B0~input_o\ : std_logic;
SIGNAL \A0~input_o\ : std_logic;
SIGNAL \inst9|inst10~0_combout\ : std_logic;
SIGNAL \B2~input_o\ : std_logic;
SIGNAL \A2~input_o\ : std_logic;
SIGNAL \inst7|inst10~0_combout\ : std_logic;
SIGNAL \inst7|inst16~0_combout\ : std_logic;
SIGNAL \B1~input_o\ : std_logic;
SIGNAL \A1~input_o\ : std_logic;
SIGNAL \inst10|inst51|inst12~0_combout\ : std_logic;
SIGNAL \inst10|inst53|inst12~0_combout\ : std_logic;
SIGNAL \inst10|inst49|inst11~0_combout\ : std_logic;
SIGNAL \inst10|inst54|inst13~combout\ : std_logic;
SIGNAL \inst10|inst47|inst11~0_combout\ : std_logic;
SIGNAL \inst10|inst46|inst17~0_combout\ : std_logic;
SIGNAL \inst10|inst|inst9~combout\ : std_logic;
SIGNAL \inst9|inst16~0_combout\ : std_logic;
SIGNAL \ALT_INV_B1~input_o\ : std_logic;
SIGNAL \ALT_INV_A2~input_o\ : std_logic;
SIGNAL \inst|ALT_INV_inst10~0_combout\ : std_logic;
SIGNAL \inst7|ALT_INV_inst16~0_combout\ : std_logic;
SIGNAL \inst7|ALT_INV_inst10~0_combout\ : std_logic;
SIGNAL \inst9|ALT_INV_inst10~0_combout\ : std_logic;
SIGNAL \ALT_INV_B2~input_o\ : std_logic;
SIGNAL \ALT_INV_A0~input_o\ : std_logic;
SIGNAL \ALT_INV_A3~input_o\ : std_logic;
SIGNAL \ALT_INV_B3~input_o\ : std_logic;
SIGNAL \ALT_INV_A1~input_o\ : std_logic;
SIGNAL \ALT_INV_B0~input_o\ : std_logic;

BEGIN

display_g <= ww_display_g;
ww_A0 <= A0;
ww_B0 <= B0;
ww_A1 <= A1;
ww_B1 <= B1;
ww_A2 <= A2;
ww_B2 <= B2;
ww_A3 <= A3;
ww_B3 <= B3;
display_f <= ww_display_f;
display_e <= ww_display_e;
display_d <= ww_display_d;
display_c <= ww_display_c;
display_b <= ww_display_b;
display_a <= ww_display_a;
Cout <= ww_Cout;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
\ALT_INV_B1~input_o\ <= NOT \B1~input_o\;
\ALT_INV_A2~input_o\ <= NOT \A2~input_o\;
\inst|ALT_INV_inst10~0_combout\ <= NOT \inst|inst10~0_combout\;
\inst7|ALT_INV_inst16~0_combout\ <= NOT \inst7|inst16~0_combout\;
\inst7|ALT_INV_inst10~0_combout\ <= NOT \inst7|inst10~0_combout\;
\inst9|ALT_INV_inst10~0_combout\ <= NOT \inst9|inst10~0_combout\;
\ALT_INV_B2~input_o\ <= NOT \B2~input_o\;
\ALT_INV_A0~input_o\ <= NOT \A0~input_o\;
\ALT_INV_A3~input_o\ <= NOT \A3~input_o\;
\ALT_INV_B3~input_o\ <= NOT \B3~input_o\;
\ALT_INV_A1~input_o\ <= NOT \A1~input_o\;
\ALT_INV_B0~input_o\ <= NOT \B0~input_o\;

-- Location: IOOBUF_X52_Y0_N53
\display_g~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst10|inst51|inst12~0_combout\,
	devoe => ww_devoe,
	o => ww_display_g);

-- Location: IOOBUF_X51_Y0_N36
\display_f~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst10|inst53|inst12~0_combout\,
	devoe => ww_devoe,
	o => ww_display_f);

-- Location: IOOBUF_X48_Y0_N76
\display_e~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst10|inst49|inst11~0_combout\,
	devoe => ww_devoe,
	o => ww_display_e);

-- Location: IOOBUF_X50_Y0_N36
\display_d~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst10|inst54|inst13~combout\,
	devoe => ww_devoe,
	o => ww_display_d);

-- Location: IOOBUF_X48_Y0_N93
\display_c~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst10|inst47|inst11~0_combout\,
	devoe => ww_devoe,
	o => ww_display_c);

-- Location: IOOBUF_X50_Y0_N53
\display_b~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst10|inst46|inst17~0_combout\,
	devoe => ww_devoe,
	o => ww_display_b);

-- Location: IOOBUF_X46_Y0_N36
\display_a~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst10|inst|inst9~combout\,
	devoe => ww_devoe,
	o => ww_display_a);

-- Location: IOOBUF_X36_Y0_N2
\Cout~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \inst9|inst16~0_combout\,
	devoe => ww_devoe,
	o => ww_Cout);

-- Location: IOIBUF_X34_Y0_N35
\A3~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A3,
	o => \A3~input_o\);

-- Location: IOIBUF_X34_Y0_N18
\B3~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B3,
	o => \B3~input_o\);

-- Location: LABCELL_X35_Y1_N0
\inst|inst10~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst|inst10~0_combout\ = !\A3~input_o\ $ (!\B3~input_o\)

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0110011001100110011001100110011001100110011001100110011001100110",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_A3~input_o\,
	datab => \ALT_INV_B3~input_o\,
	combout => \inst|inst10~0_combout\);

-- Location: IOIBUF_X33_Y0_N41
\B0~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B0,
	o => \B0~input_o\);

-- Location: IOIBUF_X36_Y0_N35
\A0~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A0,
	o => \A0~input_o\);

-- Location: LABCELL_X35_Y1_N9
\inst9|inst10~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst9|inst10~0_combout\ = !\B0~input_o\ $ (!\A0~input_o\)

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0101010110101010010101011010101001010101101010100101010110101010",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_B0~input_o\,
	datad => \ALT_INV_A0~input_o\,
	combout => \inst9|inst10~0_combout\);

-- Location: IOIBUF_X34_Y0_N1
\B2~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B2,
	o => \B2~input_o\);

-- Location: IOIBUF_X34_Y0_N52
\A2~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A2,
	o => \A2~input_o\);

-- Location: LABCELL_X35_Y1_N3
\inst7|inst10~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst7|inst10~0_combout\ = ( \A2~input_o\ & ( !\B2~input_o\ $ (((!\A3~input_o\ & \B3~input_o\))) ) ) # ( !\A2~input_o\ & ( !\B2~input_o\ $ (((!\B3~input_o\) # (\A3~input_o\))) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0010110100101101001011010010110111010010110100101101001011010010",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_A3~input_o\,
	datab => \ALT_INV_B3~input_o\,
	datac => \ALT_INV_B2~input_o\,
	dataf => \ALT_INV_A2~input_o\,
	combout => \inst7|inst10~0_combout\);

-- Location: LABCELL_X35_Y1_N6
\inst7|inst16~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst7|inst16~0_combout\ = ( \A2~input_o\ & ( (\B3~input_o\ & (!\A3~input_o\ & \B2~input_o\)) ) ) # ( !\A2~input_o\ & ( ((\B3~input_o\ & !\A3~input_o\)) # (\B2~input_o\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0011000011111111001100001111111100000000001100000000000000110000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	datab => \ALT_INV_B3~input_o\,
	datac => \ALT_INV_A3~input_o\,
	datad => \ALT_INV_B2~input_o\,
	dataf => \ALT_INV_A2~input_o\,
	combout => \inst7|inst16~0_combout\);

-- Location: IOIBUF_X33_Y0_N58
\B1~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B1,
	o => \B1~input_o\);

-- Location: IOIBUF_X36_Y0_N52
\A1~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A1,
	o => \A1~input_o\);

-- Location: LABCELL_X35_Y1_N42
\inst10|inst51|inst12~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst10|inst51|inst12~0_combout\ = ( \B1~input_o\ & ( \A1~input_o\ & ( (!\inst9|inst10~0_combout\ & (!\inst7|inst10~0_combout\ & ((!\inst|inst10~0_combout\) # (!\inst7|inst16~0_combout\)))) # (\inst9|inst10~0_combout\ & (\inst|inst10~0_combout\ & 
-- (\inst7|inst10~0_combout\ & \inst7|inst16~0_combout\))) ) ) ) # ( !\B1~input_o\ & ( \A1~input_o\ & ( (!\inst|inst10~0_combout\ & (!\inst7|inst10~0_combout\ & (!\inst9|inst10~0_combout\ $ (!\inst7|inst16~0_combout\)))) # (\inst|inst10~0_combout\ & 
-- (!\inst9|inst10~0_combout\ & (!\inst7|inst10~0_combout\ $ (!\inst7|inst16~0_combout\)))) ) ) ) # ( \B1~input_o\ & ( !\A1~input_o\ & ( (!\inst|inst10~0_combout\ & (!\inst7|inst10~0_combout\ & (!\inst9|inst10~0_combout\ $ (\inst7|inst16~0_combout\)))) # 
-- (\inst|inst10~0_combout\ & (\inst9|inst10~0_combout\ & (!\inst7|inst10~0_combout\ $ (!\inst7|inst16~0_combout\)))) ) ) ) # ( !\B1~input_o\ & ( !\A1~input_o\ & ( (!\inst9|inst10~0_combout\ & (!\inst7|inst10~0_combout\ & ((!\inst|inst10~0_combout\) # 
-- (!\inst7|inst16~0_combout\)))) # (\inst9|inst10~0_combout\ & (\inst|inst10~0_combout\ & (\inst7|inst10~0_combout\ & \inst7|inst16~0_combout\))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "1100000010000001100000010011000000100100110000001100000010000001",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst|ALT_INV_inst10~0_combout\,
	datab => \inst9|ALT_INV_inst10~0_combout\,
	datac => \inst7|ALT_INV_inst10~0_combout\,
	datad => \inst7|ALT_INV_inst16~0_combout\,
	datae => \ALT_INV_B1~input_o\,
	dataf => \ALT_INV_A1~input_o\,
	combout => \inst10|inst51|inst12~0_combout\);

-- Location: LABCELL_X35_Y1_N18
\inst10|inst53|inst12~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst10|inst53|inst12~0_combout\ = ( \B1~input_o\ & ( \A1~input_o\ & ( (!\inst|inst10~0_combout\ & (!\inst9|inst10~0_combout\ & (\inst7|inst10~0_combout\ & !\inst7|inst16~0_combout\))) # (\inst|inst10~0_combout\ & (!\inst9|inst10~0_combout\ $ 
-- (((\inst7|inst10~0_combout\ & \inst7|inst16~0_combout\))))) ) ) ) # ( !\B1~input_o\ & ( \A1~input_o\ & ( (!\inst|inst10~0_combout\ & (!\inst9|inst10~0_combout\ & (\inst7|inst10~0_combout\ & \inst7|inst16~0_combout\))) # (\inst|inst10~0_combout\ & 
-- (!\inst9|inst10~0_combout\ $ (((!\inst7|inst10~0_combout\ & !\inst7|inst16~0_combout\))))) ) ) ) # ( \B1~input_o\ & ( !\A1~input_o\ & ( (!\inst|inst10~0_combout\ & (\inst9|inst10~0_combout\ & (\inst7|inst10~0_combout\ & \inst7|inst16~0_combout\))) # 
-- (\inst|inst10~0_combout\ & (!\inst9|inst10~0_combout\ $ (((\inst7|inst16~0_combout\) # (\inst7|inst10~0_combout\))))) ) ) ) # ( !\B1~input_o\ & ( !\A1~input_o\ & ( (!\inst|inst10~0_combout\ & (!\inst9|inst10~0_combout\ & (\inst7|inst10~0_combout\ & 
-- !\inst7|inst16~0_combout\))) # (\inst|inst10~0_combout\ & (!\inst9|inst10~0_combout\ $ (((\inst7|inst10~0_combout\ & \inst7|inst16~0_combout\))))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0100110001000001010000010001001100010100010011000100110001000001",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst|ALT_INV_inst10~0_combout\,
	datab => \inst9|ALT_INV_inst10~0_combout\,
	datac => \inst7|ALT_INV_inst10~0_combout\,
	datad => \inst7|ALT_INV_inst16~0_combout\,
	datae => \ALT_INV_B1~input_o\,
	dataf => \ALT_INV_A1~input_o\,
	combout => \inst10|inst53|inst12~0_combout\);

-- Location: LABCELL_X35_Y1_N54
\inst10|inst49|inst11~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst10|inst49|inst11~0_combout\ = ( \B1~input_o\ & ( \A1~input_o\ & ( (!\inst7|inst10~0_combout\ & ((!\inst7|inst16~0_combout\ & (\inst|inst10~0_combout\)) # (\inst7|inst16~0_combout\ & ((\inst9|inst10~0_combout\))))) # (\inst7|inst10~0_combout\ & 
-- (\inst|inst10~0_combout\ & (!\inst9|inst10~0_combout\ $ (\inst7|inst16~0_combout\)))) ) ) ) # ( !\B1~input_o\ & ( \A1~input_o\ & ( (!\inst7|inst10~0_combout\ & ((!\inst7|inst16~0_combout\ & ((!\inst9|inst10~0_combout\))) # (\inst7|inst16~0_combout\ & 
-- (\inst|inst10~0_combout\)))) # (\inst7|inst10~0_combout\ & (\inst|inst10~0_combout\ & (!\inst9|inst10~0_combout\))) ) ) ) # ( \B1~input_o\ & ( !\A1~input_o\ & ( (!\inst7|inst10~0_combout\ & ((!\inst7|inst16~0_combout\ & ((\inst9|inst10~0_combout\))) # 
-- (\inst7|inst16~0_combout\ & (\inst|inst10~0_combout\)))) # (\inst7|inst10~0_combout\ & (\inst|inst10~0_combout\ & (\inst9|inst10~0_combout\))) ) ) ) # ( !\B1~input_o\ & ( !\A1~input_o\ & ( (!\inst7|inst10~0_combout\ & ((!\inst7|inst16~0_combout\ & 
-- (\inst|inst10~0_combout\)) # (\inst7|inst16~0_combout\ & ((\inst9|inst10~0_combout\))))) # (\inst7|inst10~0_combout\ & (\inst|inst10~0_combout\ & (!\inst9|inst10~0_combout\ $ (\inst7|inst16~0_combout\)))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0101010000110001001100010101000111000100010101000101010000110001",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst|ALT_INV_inst10~0_combout\,
	datab => \inst9|ALT_INV_inst10~0_combout\,
	datac => \inst7|ALT_INV_inst10~0_combout\,
	datad => \inst7|ALT_INV_inst16~0_combout\,
	datae => \ALT_INV_B1~input_o\,
	dataf => \ALT_INV_A1~input_o\,
	combout => \inst10|inst49|inst11~0_combout\);

-- Location: LABCELL_X35_Y1_N30
\inst10|inst54|inst13\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst10|inst54|inst13~combout\ = ( \B1~input_o\ & ( \A1~input_o\ & ( (!\inst|inst10~0_combout\ & (\inst9|inst10~0_combout\ & (!\inst7|inst10~0_combout\ $ (!\inst7|inst16~0_combout\)))) # (\inst|inst10~0_combout\ & ((!\inst7|inst10~0_combout\ & 
-- (!\inst9|inst10~0_combout\ & !\inst7|inst16~0_combout\)) # (\inst7|inst10~0_combout\ & ((\inst7|inst16~0_combout\))))) ) ) ) # ( !\B1~input_o\ & ( \A1~input_o\ & ( (!\inst7|inst10~0_combout\ & (!\inst9|inst10~0_combout\ & (!\inst|inst10~0_combout\ $ 
-- (\inst7|inst16~0_combout\)))) # (\inst7|inst10~0_combout\ & ((!\inst|inst10~0_combout\ & (\inst9|inst10~0_combout\ & \inst7|inst16~0_combout\)) # (\inst|inst10~0_combout\ & ((!\inst7|inst16~0_combout\))))) ) ) ) # ( \B1~input_o\ & ( !\A1~input_o\ & ( 
-- (!\inst7|inst10~0_combout\ & (\inst9|inst10~0_combout\ & (!\inst|inst10~0_combout\ $ (\inst7|inst16~0_combout\)))) # (\inst7|inst10~0_combout\ & ((!\inst|inst10~0_combout\ & (!\inst9|inst10~0_combout\ & \inst7|inst16~0_combout\)) # 
-- (\inst|inst10~0_combout\ & ((!\inst7|inst16~0_combout\))))) ) ) ) # ( !\B1~input_o\ & ( !\A1~input_o\ & ( (!\inst|inst10~0_combout\ & (\inst9|inst10~0_combout\ & (!\inst7|inst10~0_combout\ $ (!\inst7|inst16~0_combout\)))) # (\inst|inst10~0_combout\ & 
-- ((!\inst7|inst10~0_combout\ & (!\inst9|inst10~0_combout\ & !\inst7|inst16~0_combout\)) # (\inst7|inst10~0_combout\ & ((\inst7|inst16~0_combout\))))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0100001000100101001001010001100010000101010000100100001000100101",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst|ALT_INV_inst10~0_combout\,
	datab => \inst9|ALT_INV_inst10~0_combout\,
	datac => \inst7|ALT_INV_inst10~0_combout\,
	datad => \inst7|ALT_INV_inst16~0_combout\,
	datae => \ALT_INV_B1~input_o\,
	dataf => \ALT_INV_A1~input_o\,
	combout => \inst10|inst54|inst13~combout\);

-- Location: LABCELL_X35_Y1_N36
\inst10|inst47|inst11~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst10|inst47|inst11~0_combout\ = ( \B1~input_o\ & ( \A1~input_o\ & ( (!\inst9|inst10~0_combout\ & ((!\inst|inst10~0_combout\ & ((\inst7|inst16~0_combout\) # (\inst7|inst10~0_combout\))) # (\inst|inst10~0_combout\ & (\inst7|inst10~0_combout\ & 
-- \inst7|inst16~0_combout\)))) ) ) ) # ( !\B1~input_o\ & ( \A1~input_o\ & ( (!\inst9|inst10~0_combout\ & (!\inst|inst10~0_combout\ & (\inst7|inst10~0_combout\ & \inst7|inst16~0_combout\))) # (\inst9|inst10~0_combout\ & (!\inst7|inst16~0_combout\ & 
-- ((!\inst|inst10~0_combout\) # (\inst7|inst10~0_combout\)))) ) ) ) # ( \B1~input_o\ & ( !\A1~input_o\ & ( (!\inst9|inst10~0_combout\ & (!\inst7|inst16~0_combout\ & ((!\inst|inst10~0_combout\) # (\inst7|inst10~0_combout\)))) # (\inst9|inst10~0_combout\ & 
-- (!\inst|inst10~0_combout\ & (\inst7|inst10~0_combout\ & \inst7|inst16~0_combout\))) ) ) ) # ( !\B1~input_o\ & ( !\A1~input_o\ & ( (!\inst9|inst10~0_combout\ & ((!\inst|inst10~0_combout\ & ((\inst7|inst16~0_combout\) # (\inst7|inst10~0_combout\))) # 
-- (\inst|inst10~0_combout\ & (\inst7|inst10~0_combout\ & \inst7|inst16~0_combout\)))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000100010001100100011000000001000100011000010000000100010001100",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst|ALT_INV_inst10~0_combout\,
	datab => \inst9|ALT_INV_inst10~0_combout\,
	datac => \inst7|ALT_INV_inst10~0_combout\,
	datad => \inst7|ALT_INV_inst16~0_combout\,
	datae => \ALT_INV_B1~input_o\,
	dataf => \ALT_INV_A1~input_o\,
	combout => \inst10|inst47|inst11~0_combout\);

-- Location: LABCELL_X35_Y1_N12
\inst10|inst46|inst17~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst10|inst46|inst17~0_combout\ = ( \B1~input_o\ & ( \A1~input_o\ & ( (!\inst7|inst10~0_combout\ & (\inst7|inst16~0_combout\ & (!\inst|inst10~0_combout\ $ (\inst9|inst10~0_combout\)))) # (\inst7|inst10~0_combout\ & (!\inst7|inst16~0_combout\ $ 
-- (((!\inst|inst10~0_combout\) # (!\inst9|inst10~0_combout\))))) ) ) ) # ( !\B1~input_o\ & ( \A1~input_o\ & ( (!\inst9|inst10~0_combout\ & (!\inst7|inst16~0_combout\ & (!\inst|inst10~0_combout\ $ (!\inst7|inst10~0_combout\)))) # (\inst9|inst10~0_combout\ & 
-- ((!\inst|inst10~0_combout\ & ((!\inst7|inst16~0_combout\))) # (\inst|inst10~0_combout\ & (\inst7|inst10~0_combout\)))) ) ) ) # ( \B1~input_o\ & ( !\A1~input_o\ & ( (!\inst9|inst10~0_combout\ & ((!\inst|inst10~0_combout\ & ((!\inst7|inst16~0_combout\))) # 
-- (\inst|inst10~0_combout\ & (\inst7|inst10~0_combout\)))) # (\inst9|inst10~0_combout\ & (!\inst7|inst16~0_combout\ & (!\inst|inst10~0_combout\ $ (!\inst7|inst10~0_combout\)))) ) ) ) # ( !\B1~input_o\ & ( !\A1~input_o\ & ( (!\inst7|inst10~0_combout\ & 
-- (\inst7|inst16~0_combout\ & (!\inst|inst10~0_combout\ $ (\inst9|inst10~0_combout\)))) # (\inst7|inst10~0_combout\ & (!\inst7|inst16~0_combout\ $ (((!\inst|inst10~0_combout\) # (!\inst9|inst10~0_combout\))))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000110011110100111100000010001101011000000010000000110011110",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst|ALT_INV_inst10~0_combout\,
	datab => \inst9|ALT_INV_inst10~0_combout\,
	datac => \inst7|ALT_INV_inst10~0_combout\,
	datad => \inst7|ALT_INV_inst16~0_combout\,
	datae => \ALT_INV_B1~input_o\,
	dataf => \ALT_INV_A1~input_o\,
	combout => \inst10|inst46|inst17~0_combout\);

-- Location: LABCELL_X35_Y1_N48
\inst10|inst|inst9\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst10|inst|inst9~combout\ = ( \B1~input_o\ & ( \A1~input_o\ & ( (!\inst7|inst16~0_combout\ & (\inst|inst10~0_combout\ & (!\inst9|inst10~0_combout\ $ (\inst7|inst10~0_combout\)))) # (\inst7|inst16~0_combout\ & (!\inst7|inst10~0_combout\ & 
-- (!\inst|inst10~0_combout\ $ (!\inst9|inst10~0_combout\)))) ) ) ) # ( !\B1~input_o\ & ( \A1~input_o\ & ( (!\inst9|inst10~0_combout\ & (!\inst7|inst10~0_combout\ & (!\inst|inst10~0_combout\ $ (\inst7|inst16~0_combout\)))) # (\inst9|inst10~0_combout\ & 
-- (\inst|inst10~0_combout\ & (!\inst7|inst10~0_combout\ $ (\inst7|inst16~0_combout\)))) ) ) ) # ( \B1~input_o\ & ( !\A1~input_o\ & ( (!\inst9|inst10~0_combout\ & (\inst|inst10~0_combout\ & (!\inst7|inst10~0_combout\ $ (\inst7|inst16~0_combout\)))) # 
-- (\inst9|inst10~0_combout\ & (!\inst7|inst10~0_combout\ & (!\inst|inst10~0_combout\ $ (\inst7|inst16~0_combout\)))) ) ) ) # ( !\B1~input_o\ & ( !\A1~input_o\ & ( (!\inst7|inst16~0_combout\ & (\inst|inst10~0_combout\ & (!\inst9|inst10~0_combout\ $ 
-- (\inst7|inst10~0_combout\)))) # (\inst7|inst16~0_combout\ & (!\inst7|inst10~0_combout\ & (!\inst|inst10~0_combout\ $ (!\inst9|inst10~0_combout\)))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0100000101100000011000000001010010010000010000010100000101100000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \inst|ALT_INV_inst10~0_combout\,
	datab => \inst9|ALT_INV_inst10~0_combout\,
	datac => \inst7|ALT_INV_inst10~0_combout\,
	datad => \inst7|ALT_INV_inst16~0_combout\,
	datae => \ALT_INV_B1~input_o\,
	dataf => \ALT_INV_A1~input_o\,
	combout => \inst10|inst|inst9~combout\);

-- Location: LABCELL_X35_Y1_N24
\inst9|inst16~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \inst9|inst16~0_combout\ = ( \B1~input_o\ & ( \A1~input_o\ & ( (!\A0~input_o\ & ((\B0~input_o\) # (\inst7|inst16~0_combout\))) # (\A0~input_o\ & (\inst7|inst16~0_combout\ & \B0~input_o\)) ) ) ) # ( !\B1~input_o\ & ( \A1~input_o\ & ( (!\A0~input_o\ & 
-- \B0~input_o\) ) ) ) # ( \B1~input_o\ & ( !\A1~input_o\ & ( (!\A0~input_o\) # (\B0~input_o\) ) ) ) # ( !\B1~input_o\ & ( !\A1~input_o\ & ( (!\A0~input_o\ & ((\B0~input_o\) # (\inst7|inst16~0_combout\))) # (\A0~input_o\ & (\inst7|inst16~0_combout\ & 
-- \B0~input_o\)) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0010101100101011101011111010111100001010000010100010101100101011",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_A0~input_o\,
	datab => \inst7|ALT_INV_inst16~0_combout\,
	datac => \ALT_INV_B0~input_o\,
	datae => \ALT_INV_B1~input_o\,
	dataf => \ALT_INV_A1~input_o\,
	combout => \inst9|inst16~0_combout\);

-- Location: LABCELL_X35_Y41_N3
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


