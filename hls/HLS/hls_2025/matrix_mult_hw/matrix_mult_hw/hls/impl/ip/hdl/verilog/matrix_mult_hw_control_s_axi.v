// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2025.1 (64-bit)
// Tool Version Limit: 2025.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
`timescale 1ns/1ps
module matrix_mult_hw_control_s_axi
#(parameter
    C_S_AXI_ADDR_WIDTH = 14,
    C_S_AXI_DATA_WIDTH = 32
)(
    input  wire                          ACLK,
    input  wire                          ARESET,
    input  wire                          ACLK_EN,
    input  wire [C_S_AXI_ADDR_WIDTH-1:0] AWADDR,
    input  wire                          AWVALID,
    output wire                          AWREADY,
    input  wire [C_S_AXI_DATA_WIDTH-1:0] WDATA,
    input  wire [C_S_AXI_DATA_WIDTH/8-1:0] WSTRB,
    input  wire                          WVALID,
    output wire                          WREADY,
    output wire [1:0]                    BRESP,
    output wire                          BVALID,
    input  wire                          BREADY,
    input  wire [C_S_AXI_ADDR_WIDTH-1:0] ARADDR,
    input  wire                          ARVALID,
    output wire                          ARREADY,
    output wire [C_S_AXI_DATA_WIDTH-1:0] RDATA,
    output wire [1:0]                    RRESP,
    output wire                          RVALID,
    input  wire                          RREADY,
    output wire                          interrupt,
    input  wire [3:0]                    A_0_address0,
    input  wire                          A_0_ce0,
    output wire [31:0]                   A_0_q0,
    input  wire [3:0]                    A_1_address0,
    input  wire                          A_1_ce0,
    output wire [31:0]                   A_1_q0,
    input  wire [3:0]                    A_2_address0,
    input  wire                          A_2_ce0,
    output wire [31:0]                   A_2_q0,
    input  wire [3:0]                    A_3_address0,
    input  wire                          A_3_ce0,
    output wire [31:0]                   A_3_q0,
    input  wire [3:0]                    A_4_address0,
    input  wire                          A_4_ce0,
    output wire [31:0]                   A_4_q0,
    input  wire [3:0]                    A_5_address0,
    input  wire                          A_5_ce0,
    output wire [31:0]                   A_5_q0,
    input  wire [3:0]                    A_6_address0,
    input  wire                          A_6_ce0,
    output wire [31:0]                   A_6_q0,
    input  wire [3:0]                    A_7_address0,
    input  wire                          A_7_ce0,
    output wire [31:0]                   A_7_q0,
    input  wire [3:0]                    A_8_address0,
    input  wire                          A_8_ce0,
    output wire [31:0]                   A_8_q0,
    input  wire [3:0]                    A_9_address0,
    input  wire                          A_9_ce0,
    output wire [31:0]                   A_9_q0,
    input  wire [3:0]                    A_10_address0,
    input  wire                          A_10_ce0,
    output wire [31:0]                   A_10_q0,
    input  wire [3:0]                    A_11_address0,
    input  wire                          A_11_ce0,
    output wire [31:0]                   A_11_q0,
    input  wire [3:0]                    A_12_address0,
    input  wire                          A_12_ce0,
    output wire [31:0]                   A_12_q0,
    input  wire [3:0]                    A_13_address0,
    input  wire                          A_13_ce0,
    output wire [31:0]                   A_13_q0,
    input  wire [3:0]                    A_14_address0,
    input  wire                          A_14_ce0,
    output wire [31:0]                   A_14_q0,
    input  wire [3:0]                    A_15_address0,
    input  wire                          A_15_ce0,
    output wire [31:0]                   A_15_q0,
    input  wire [3:0]                    B_0_address0,
    input  wire                          B_0_ce0,
    output wire [31:0]                   B_0_q0,
    input  wire [3:0]                    B_1_address0,
    input  wire                          B_1_ce0,
    output wire [31:0]                   B_1_q0,
    input  wire [3:0]                    B_2_address0,
    input  wire                          B_2_ce0,
    output wire [31:0]                   B_2_q0,
    input  wire [3:0]                    B_3_address0,
    input  wire                          B_3_ce0,
    output wire [31:0]                   B_3_q0,
    input  wire [3:0]                    B_4_address0,
    input  wire                          B_4_ce0,
    output wire [31:0]                   B_4_q0,
    input  wire [3:0]                    B_5_address0,
    input  wire                          B_5_ce0,
    output wire [31:0]                   B_5_q0,
    input  wire [3:0]                    B_6_address0,
    input  wire                          B_6_ce0,
    output wire [31:0]                   B_6_q0,
    input  wire [3:0]                    B_7_address0,
    input  wire                          B_7_ce0,
    output wire [31:0]                   B_7_q0,
    input  wire [3:0]                    B_8_address0,
    input  wire                          B_8_ce0,
    output wire [31:0]                   B_8_q0,
    input  wire [3:0]                    B_9_address0,
    input  wire                          B_9_ce0,
    output wire [31:0]                   B_9_q0,
    input  wire [3:0]                    B_10_address0,
    input  wire                          B_10_ce0,
    output wire [31:0]                   B_10_q0,
    input  wire [3:0]                    B_11_address0,
    input  wire                          B_11_ce0,
    output wire [31:0]                   B_11_q0,
    input  wire [3:0]                    B_12_address0,
    input  wire                          B_12_ce0,
    output wire [31:0]                   B_12_q0,
    input  wire [3:0]                    B_13_address0,
    input  wire                          B_13_ce0,
    output wire [31:0]                   B_13_q0,
    input  wire [3:0]                    B_14_address0,
    input  wire                          B_14_ce0,
    output wire [31:0]                   B_14_q0,
    input  wire [3:0]                    B_15_address0,
    input  wire                          B_15_ce0,
    output wire [31:0]                   B_15_q0,
    input  wire [7:0]                    C_address0,
    input  wire                          C_ce0,
    input  wire                          C_we0,
    input  wire [31:0]                   C_d0,
    output wire                          ap_start,
    input  wire                          ap_done,
    input  wire                          ap_ready,
    input  wire                          ap_idle
);
//------------------------Address Info-------------------
// Protocol Used: ap_ctrl_hs
//
// 0x0000 : Control signals
//          bit 0  - ap_start (Read/Write/COH)
//          bit 1  - ap_done (Read/COR)
//          bit 2  - ap_idle (Read)
//          bit 3  - ap_ready (Read/COR)
//          bit 7  - auto_restart (Read/Write)
//          bit 9  - interrupt (Read)
//          others - reserved
// 0x0004 : Global Interrupt Enable Register
//          bit 0  - Global Interrupt Enable (Read/Write)
//          others - reserved
// 0x0008 : IP Interrupt Enable Register (Read/Write)
//          bit 0 - enable ap_done interrupt (Read/Write)
//          bit 1 - enable ap_ready interrupt (Read/Write)
//          others - reserved
// 0x000c : IP Interrupt Status Register (Read/TOW)
//          bit 0 - ap_done (Read/TOW)
//          bit 1 - ap_ready (Read/TOW)
//          others - reserved
// 0x0040 ~
// 0x007f : Memory 'A_0' (16 * 32b)
//          Word n : bit [31:0] - A_0[n]
// 0x0080 ~
// 0x00bf : Memory 'A_1' (16 * 32b)
//          Word n : bit [31:0] - A_1[n]
// 0x00c0 ~
// 0x00ff : Memory 'A_2' (16 * 32b)
//          Word n : bit [31:0] - A_2[n]
// 0x0100 ~
// 0x013f : Memory 'A_3' (16 * 32b)
//          Word n : bit [31:0] - A_3[n]
// 0x0140 ~
// 0x017f : Memory 'A_4' (16 * 32b)
//          Word n : bit [31:0] - A_4[n]
// 0x0180 ~
// 0x01bf : Memory 'A_5' (16 * 32b)
//          Word n : bit [31:0] - A_5[n]
// 0x01c0 ~
// 0x01ff : Memory 'A_6' (16 * 32b)
//          Word n : bit [31:0] - A_6[n]
// 0x0200 ~
// 0x023f : Memory 'A_7' (16 * 32b)
//          Word n : bit [31:0] - A_7[n]
// 0x0240 ~
// 0x027f : Memory 'A_8' (16 * 32b)
//          Word n : bit [31:0] - A_8[n]
// 0x0280 ~
// 0x02bf : Memory 'A_9' (16 * 32b)
//          Word n : bit [31:0] - A_9[n]
// 0x02c0 ~
// 0x02ff : Memory 'A_10' (16 * 32b)
//          Word n : bit [31:0] - A_10[n]
// 0x0300 ~
// 0x033f : Memory 'A_11' (16 * 32b)
//          Word n : bit [31:0] - A_11[n]
// 0x0340 ~
// 0x037f : Memory 'A_12' (16 * 32b)
//          Word n : bit [31:0] - A_12[n]
// 0x0380 ~
// 0x03bf : Memory 'A_13' (16 * 32b)
//          Word n : bit [31:0] - A_13[n]
// 0x03c0 ~
// 0x03ff : Memory 'A_14' (16 * 32b)
//          Word n : bit [31:0] - A_14[n]
// 0x0400 ~
// 0x043f : Memory 'A_15' (16 * 32b)
//          Word n : bit [31:0] - A_15[n]
// 0x0440 ~
// 0x047f : Memory 'B_0' (16 * 32b)
//          Word n : bit [31:0] - B_0[n]
// 0x0480 ~
// 0x04bf : Memory 'B_1' (16 * 32b)
//          Word n : bit [31:0] - B_1[n]
// 0x04c0 ~
// 0x04ff : Memory 'B_2' (16 * 32b)
//          Word n : bit [31:0] - B_2[n]
// 0x0500 ~
// 0x053f : Memory 'B_3' (16 * 32b)
//          Word n : bit [31:0] - B_3[n]
// 0x0540 ~
// 0x057f : Memory 'B_4' (16 * 32b)
//          Word n : bit [31:0] - B_4[n]
// 0x0580 ~
// 0x05bf : Memory 'B_5' (16 * 32b)
//          Word n : bit [31:0] - B_5[n]
// 0x05c0 ~
// 0x05ff : Memory 'B_6' (16 * 32b)
//          Word n : bit [31:0] - B_6[n]
// 0x0600 ~
// 0x063f : Memory 'B_7' (16 * 32b)
//          Word n : bit [31:0] - B_7[n]
// 0x0640 ~
// 0x067f : Memory 'B_8' (16 * 32b)
//          Word n : bit [31:0] - B_8[n]
// 0x0680 ~
// 0x06bf : Memory 'B_9' (16 * 32b)
//          Word n : bit [31:0] - B_9[n]
// 0x06c0 ~
// 0x06ff : Memory 'B_10' (16 * 32b)
//          Word n : bit [31:0] - B_10[n]
// 0x0700 ~
// 0x073f : Memory 'B_11' (16 * 32b)
//          Word n : bit [31:0] - B_11[n]
// 0x0740 ~
// 0x077f : Memory 'B_12' (16 * 32b)
//          Word n : bit [31:0] - B_12[n]
// 0x0780 ~
// 0x07bf : Memory 'B_13' (16 * 32b)
//          Word n : bit [31:0] - B_13[n]
// 0x07c0 ~
// 0x07ff : Memory 'B_14' (16 * 32b)
//          Word n : bit [31:0] - B_14[n]
// 0x0800 ~
// 0x083f : Memory 'B_15' (16 * 32b)
//          Word n : bit [31:0] - B_15[n]
// 0x3000 ~
// 0x33ff : Memory 'C' (256 * 32b)
//          Word n : bit [31:0] - C[n]
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

//------------------------Parameter----------------------
localparam
    ADDR_AP_CTRL   = 14'h0000,
    ADDR_GIE       = 14'h0004,
    ADDR_IER       = 14'h0008,
    ADDR_ISR       = 14'h000c,
    ADDR_A_0_BASE  = 14'h0040,
    ADDR_A_0_HIGH  = 14'h007f,
    ADDR_A_1_BASE  = 14'h0080,
    ADDR_A_1_HIGH  = 14'h00bf,
    ADDR_A_2_BASE  = 14'h00c0,
    ADDR_A_2_HIGH  = 14'h00ff,
    ADDR_A_3_BASE  = 14'h0100,
    ADDR_A_3_HIGH  = 14'h013f,
    ADDR_A_4_BASE  = 14'h0140,
    ADDR_A_4_HIGH  = 14'h017f,
    ADDR_A_5_BASE  = 14'h0180,
    ADDR_A_5_HIGH  = 14'h01bf,
    ADDR_A_6_BASE  = 14'h01c0,
    ADDR_A_6_HIGH  = 14'h01ff,
    ADDR_A_7_BASE  = 14'h0200,
    ADDR_A_7_HIGH  = 14'h023f,
    ADDR_A_8_BASE  = 14'h0240,
    ADDR_A_8_HIGH  = 14'h027f,
    ADDR_A_9_BASE  = 14'h0280,
    ADDR_A_9_HIGH  = 14'h02bf,
    ADDR_A_10_BASE = 14'h02c0,
    ADDR_A_10_HIGH = 14'h02ff,
    ADDR_A_11_BASE = 14'h0300,
    ADDR_A_11_HIGH = 14'h033f,
    ADDR_A_12_BASE = 14'h0340,
    ADDR_A_12_HIGH = 14'h037f,
    ADDR_A_13_BASE = 14'h0380,
    ADDR_A_13_HIGH = 14'h03bf,
    ADDR_A_14_BASE = 14'h03c0,
    ADDR_A_14_HIGH = 14'h03ff,
    ADDR_A_15_BASE = 14'h0400,
    ADDR_A_15_HIGH = 14'h043f,
    ADDR_B_0_BASE  = 14'h0440,
    ADDR_B_0_HIGH  = 14'h047f,
    ADDR_B_1_BASE  = 14'h0480,
    ADDR_B_1_HIGH  = 14'h04bf,
    ADDR_B_2_BASE  = 14'h04c0,
    ADDR_B_2_HIGH  = 14'h04ff,
    ADDR_B_3_BASE  = 14'h0500,
    ADDR_B_3_HIGH  = 14'h053f,
    ADDR_B_4_BASE  = 14'h0540,
    ADDR_B_4_HIGH  = 14'h057f,
    ADDR_B_5_BASE  = 14'h0580,
    ADDR_B_5_HIGH  = 14'h05bf,
    ADDR_B_6_BASE  = 14'h05c0,
    ADDR_B_6_HIGH  = 14'h05ff,
    ADDR_B_7_BASE  = 14'h0600,
    ADDR_B_7_HIGH  = 14'h063f,
    ADDR_B_8_BASE  = 14'h0640,
    ADDR_B_8_HIGH  = 14'h067f,
    ADDR_B_9_BASE  = 14'h0680,
    ADDR_B_9_HIGH  = 14'h06bf,
    ADDR_B_10_BASE = 14'h06c0,
    ADDR_B_10_HIGH = 14'h06ff,
    ADDR_B_11_BASE = 14'h0700,
    ADDR_B_11_HIGH = 14'h073f,
    ADDR_B_12_BASE = 14'h0740,
    ADDR_B_12_HIGH = 14'h077f,
    ADDR_B_13_BASE = 14'h0780,
    ADDR_B_13_HIGH = 14'h07bf,
    ADDR_B_14_BASE = 14'h07c0,
    ADDR_B_14_HIGH = 14'h07ff,
    ADDR_B_15_BASE = 14'h0800,
    ADDR_B_15_HIGH = 14'h083f,
    ADDR_C_BASE    = 14'h3000,
    ADDR_C_HIGH    = 14'h33ff,
    WRIDLE         = 2'd0,
    WRDATA         = 2'd1,
    WRRESP         = 2'd2,
    WRRESET        = 2'd3,
    RDIDLE         = 2'd0,
    RDDATA         = 2'd1,
    RDRESET        = 2'd2,
    ADDR_BITS                = 14;

//------------------------Local signal-------------------
    reg  [1:0]                    wstate = WRRESET;
    reg  [1:0]                    wnext;
    reg  [ADDR_BITS-1:0]          waddr;
    wire [C_S_AXI_DATA_WIDTH-1:0] wmask;
    wire                          aw_hs;
    wire                          w_hs;
    reg  [1:0]                    rstate = RDRESET;
    reg  [1:0]                    rnext;
    reg  [C_S_AXI_DATA_WIDTH-1:0] rdata;
    wire                          ar_hs;
    wire [ADDR_BITS-1:0]          raddr;
    // internal registers
    reg                           int_ap_idle = 1'b0;
    reg                           int_ap_ready = 1'b0;
    wire                          task_ap_ready;
    reg                           int_ap_done = 1'b0;
    wire                          task_ap_done;
    reg                           int_task_ap_done = 1'b0;
    reg                           int_ap_start = 1'b0;
    reg                           int_interrupt = 1'b0;
    reg                           int_auto_restart = 1'b0;
    reg                           auto_restart_status = 1'b0;
    wire                          auto_restart_done;
    reg                           int_gie = 1'b0;
    reg  [1:0]                    int_ier = 2'b0;
    reg  [1:0]                    int_isr = 2'b0;
    // memory signals
    wire [3:0]                    int_A_0_address0;
    wire                          int_A_0_ce0;
    wire [31:0]                   int_A_0_q0;
    wire [3:0]                    int_A_0_address1;
    wire                          int_A_0_ce1;
    wire [3:0]                    int_A_0_be1;
    wire                          int_A_0_we1;
    wire [31:0]                   int_A_0_d1;
    wire [31:0]                   int_A_0_q1;
    reg                           int_A_0_read;
    reg                           int_A_0_write;
    wire [3:0]                    int_A_1_address0;
    wire                          int_A_1_ce0;
    wire [31:0]                   int_A_1_q0;
    wire [3:0]                    int_A_1_address1;
    wire                          int_A_1_ce1;
    wire [3:0]                    int_A_1_be1;
    wire                          int_A_1_we1;
    wire [31:0]                   int_A_1_d1;
    wire [31:0]                   int_A_1_q1;
    reg                           int_A_1_read;
    reg                           int_A_1_write;
    wire [3:0]                    int_A_2_address0;
    wire                          int_A_2_ce0;
    wire [31:0]                   int_A_2_q0;
    wire [3:0]                    int_A_2_address1;
    wire                          int_A_2_ce1;
    wire [3:0]                    int_A_2_be1;
    wire                          int_A_2_we1;
    wire [31:0]                   int_A_2_d1;
    wire [31:0]                   int_A_2_q1;
    reg                           int_A_2_read;
    reg                           int_A_2_write;
    wire [3:0]                    int_A_3_address0;
    wire                          int_A_3_ce0;
    wire [31:0]                   int_A_3_q0;
    wire [3:0]                    int_A_3_address1;
    wire                          int_A_3_ce1;
    wire [3:0]                    int_A_3_be1;
    wire                          int_A_3_we1;
    wire [31:0]                   int_A_3_d1;
    wire [31:0]                   int_A_3_q1;
    reg                           int_A_3_read;
    reg                           int_A_3_write;
    wire [3:0]                    int_A_4_address0;
    wire                          int_A_4_ce0;
    wire [31:0]                   int_A_4_q0;
    wire [3:0]                    int_A_4_address1;
    wire                          int_A_4_ce1;
    wire [3:0]                    int_A_4_be1;
    wire                          int_A_4_we1;
    wire [31:0]                   int_A_4_d1;
    wire [31:0]                   int_A_4_q1;
    reg                           int_A_4_read;
    reg                           int_A_4_write;
    wire [3:0]                    int_A_5_address0;
    wire                          int_A_5_ce0;
    wire [31:0]                   int_A_5_q0;
    wire [3:0]                    int_A_5_address1;
    wire                          int_A_5_ce1;
    wire [3:0]                    int_A_5_be1;
    wire                          int_A_5_we1;
    wire [31:0]                   int_A_5_d1;
    wire [31:0]                   int_A_5_q1;
    reg                           int_A_5_read;
    reg                           int_A_5_write;
    wire [3:0]                    int_A_6_address0;
    wire                          int_A_6_ce0;
    wire [31:0]                   int_A_6_q0;
    wire [3:0]                    int_A_6_address1;
    wire                          int_A_6_ce1;
    wire [3:0]                    int_A_6_be1;
    wire                          int_A_6_we1;
    wire [31:0]                   int_A_6_d1;
    wire [31:0]                   int_A_6_q1;
    reg                           int_A_6_read;
    reg                           int_A_6_write;
    wire [3:0]                    int_A_7_address0;
    wire                          int_A_7_ce0;
    wire [31:0]                   int_A_7_q0;
    wire [3:0]                    int_A_7_address1;
    wire                          int_A_7_ce1;
    wire [3:0]                    int_A_7_be1;
    wire                          int_A_7_we1;
    wire [31:0]                   int_A_7_d1;
    wire [31:0]                   int_A_7_q1;
    reg                           int_A_7_read;
    reg                           int_A_7_write;
    wire [3:0]                    int_A_8_address0;
    wire                          int_A_8_ce0;
    wire [31:0]                   int_A_8_q0;
    wire [3:0]                    int_A_8_address1;
    wire                          int_A_8_ce1;
    wire [3:0]                    int_A_8_be1;
    wire                          int_A_8_we1;
    wire [31:0]                   int_A_8_d1;
    wire [31:0]                   int_A_8_q1;
    reg                           int_A_8_read;
    reg                           int_A_8_write;
    wire [3:0]                    int_A_9_address0;
    wire                          int_A_9_ce0;
    wire [31:0]                   int_A_9_q0;
    wire [3:0]                    int_A_9_address1;
    wire                          int_A_9_ce1;
    wire [3:0]                    int_A_9_be1;
    wire                          int_A_9_we1;
    wire [31:0]                   int_A_9_d1;
    wire [31:0]                   int_A_9_q1;
    reg                           int_A_9_read;
    reg                           int_A_9_write;
    wire [3:0]                    int_A_10_address0;
    wire                          int_A_10_ce0;
    wire [31:0]                   int_A_10_q0;
    wire [3:0]                    int_A_10_address1;
    wire                          int_A_10_ce1;
    wire [3:0]                    int_A_10_be1;
    wire                          int_A_10_we1;
    wire [31:0]                   int_A_10_d1;
    wire [31:0]                   int_A_10_q1;
    reg                           int_A_10_read;
    reg                           int_A_10_write;
    wire [3:0]                    int_A_11_address0;
    wire                          int_A_11_ce0;
    wire [31:0]                   int_A_11_q0;
    wire [3:0]                    int_A_11_address1;
    wire                          int_A_11_ce1;
    wire [3:0]                    int_A_11_be1;
    wire                          int_A_11_we1;
    wire [31:0]                   int_A_11_d1;
    wire [31:0]                   int_A_11_q1;
    reg                           int_A_11_read;
    reg                           int_A_11_write;
    wire [3:0]                    int_A_12_address0;
    wire                          int_A_12_ce0;
    wire [31:0]                   int_A_12_q0;
    wire [3:0]                    int_A_12_address1;
    wire                          int_A_12_ce1;
    wire [3:0]                    int_A_12_be1;
    wire                          int_A_12_we1;
    wire [31:0]                   int_A_12_d1;
    wire [31:0]                   int_A_12_q1;
    reg                           int_A_12_read;
    reg                           int_A_12_write;
    wire [3:0]                    int_A_13_address0;
    wire                          int_A_13_ce0;
    wire [31:0]                   int_A_13_q0;
    wire [3:0]                    int_A_13_address1;
    wire                          int_A_13_ce1;
    wire [3:0]                    int_A_13_be1;
    wire                          int_A_13_we1;
    wire [31:0]                   int_A_13_d1;
    wire [31:0]                   int_A_13_q1;
    reg                           int_A_13_read;
    reg                           int_A_13_write;
    wire [3:0]                    int_A_14_address0;
    wire                          int_A_14_ce0;
    wire [31:0]                   int_A_14_q0;
    wire [3:0]                    int_A_14_address1;
    wire                          int_A_14_ce1;
    wire [3:0]                    int_A_14_be1;
    wire                          int_A_14_we1;
    wire [31:0]                   int_A_14_d1;
    wire [31:0]                   int_A_14_q1;
    reg                           int_A_14_read;
    reg                           int_A_14_write;
    wire [3:0]                    int_A_15_address0;
    wire                          int_A_15_ce0;
    wire [31:0]                   int_A_15_q0;
    wire [3:0]                    int_A_15_address1;
    wire                          int_A_15_ce1;
    wire [3:0]                    int_A_15_be1;
    wire                          int_A_15_we1;
    wire [31:0]                   int_A_15_d1;
    wire [31:0]                   int_A_15_q1;
    reg                           int_A_15_read;
    reg                           int_A_15_write;
    wire [3:0]                    int_B_0_address0;
    wire                          int_B_0_ce0;
    wire [31:0]                   int_B_0_q0;
    wire [3:0]                    int_B_0_address1;
    wire                          int_B_0_ce1;
    wire [3:0]                    int_B_0_be1;
    wire                          int_B_0_we1;
    wire [31:0]                   int_B_0_d1;
    wire [31:0]                   int_B_0_q1;
    reg                           int_B_0_read;
    reg                           int_B_0_write;
    wire [3:0]                    int_B_1_address0;
    wire                          int_B_1_ce0;
    wire [31:0]                   int_B_1_q0;
    wire [3:0]                    int_B_1_address1;
    wire                          int_B_1_ce1;
    wire [3:0]                    int_B_1_be1;
    wire                          int_B_1_we1;
    wire [31:0]                   int_B_1_d1;
    wire [31:0]                   int_B_1_q1;
    reg                           int_B_1_read;
    reg                           int_B_1_write;
    wire [3:0]                    int_B_2_address0;
    wire                          int_B_2_ce0;
    wire [31:0]                   int_B_2_q0;
    wire [3:0]                    int_B_2_address1;
    wire                          int_B_2_ce1;
    wire [3:0]                    int_B_2_be1;
    wire                          int_B_2_we1;
    wire [31:0]                   int_B_2_d1;
    wire [31:0]                   int_B_2_q1;
    reg                           int_B_2_read;
    reg                           int_B_2_write;
    wire [3:0]                    int_B_3_address0;
    wire                          int_B_3_ce0;
    wire [31:0]                   int_B_3_q0;
    wire [3:0]                    int_B_3_address1;
    wire                          int_B_3_ce1;
    wire [3:0]                    int_B_3_be1;
    wire                          int_B_3_we1;
    wire [31:0]                   int_B_3_d1;
    wire [31:0]                   int_B_3_q1;
    reg                           int_B_3_read;
    reg                           int_B_3_write;
    wire [3:0]                    int_B_4_address0;
    wire                          int_B_4_ce0;
    wire [31:0]                   int_B_4_q0;
    wire [3:0]                    int_B_4_address1;
    wire                          int_B_4_ce1;
    wire [3:0]                    int_B_4_be1;
    wire                          int_B_4_we1;
    wire [31:0]                   int_B_4_d1;
    wire [31:0]                   int_B_4_q1;
    reg                           int_B_4_read;
    reg                           int_B_4_write;
    wire [3:0]                    int_B_5_address0;
    wire                          int_B_5_ce0;
    wire [31:0]                   int_B_5_q0;
    wire [3:0]                    int_B_5_address1;
    wire                          int_B_5_ce1;
    wire [3:0]                    int_B_5_be1;
    wire                          int_B_5_we1;
    wire [31:0]                   int_B_5_d1;
    wire [31:0]                   int_B_5_q1;
    reg                           int_B_5_read;
    reg                           int_B_5_write;
    wire [3:0]                    int_B_6_address0;
    wire                          int_B_6_ce0;
    wire [31:0]                   int_B_6_q0;
    wire [3:0]                    int_B_6_address1;
    wire                          int_B_6_ce1;
    wire [3:0]                    int_B_6_be1;
    wire                          int_B_6_we1;
    wire [31:0]                   int_B_6_d1;
    wire [31:0]                   int_B_6_q1;
    reg                           int_B_6_read;
    reg                           int_B_6_write;
    wire [3:0]                    int_B_7_address0;
    wire                          int_B_7_ce0;
    wire [31:0]                   int_B_7_q0;
    wire [3:0]                    int_B_7_address1;
    wire                          int_B_7_ce1;
    wire [3:0]                    int_B_7_be1;
    wire                          int_B_7_we1;
    wire [31:0]                   int_B_7_d1;
    wire [31:0]                   int_B_7_q1;
    reg                           int_B_7_read;
    reg                           int_B_7_write;
    wire [3:0]                    int_B_8_address0;
    wire                          int_B_8_ce0;
    wire [31:0]                   int_B_8_q0;
    wire [3:0]                    int_B_8_address1;
    wire                          int_B_8_ce1;
    wire [3:0]                    int_B_8_be1;
    wire                          int_B_8_we1;
    wire [31:0]                   int_B_8_d1;
    wire [31:0]                   int_B_8_q1;
    reg                           int_B_8_read;
    reg                           int_B_8_write;
    wire [3:0]                    int_B_9_address0;
    wire                          int_B_9_ce0;
    wire [31:0]                   int_B_9_q0;
    wire [3:0]                    int_B_9_address1;
    wire                          int_B_9_ce1;
    wire [3:0]                    int_B_9_be1;
    wire                          int_B_9_we1;
    wire [31:0]                   int_B_9_d1;
    wire [31:0]                   int_B_9_q1;
    reg                           int_B_9_read;
    reg                           int_B_9_write;
    wire [3:0]                    int_B_10_address0;
    wire                          int_B_10_ce0;
    wire [31:0]                   int_B_10_q0;
    wire [3:0]                    int_B_10_address1;
    wire                          int_B_10_ce1;
    wire [3:0]                    int_B_10_be1;
    wire                          int_B_10_we1;
    wire [31:0]                   int_B_10_d1;
    wire [31:0]                   int_B_10_q1;
    reg                           int_B_10_read;
    reg                           int_B_10_write;
    wire [3:0]                    int_B_11_address0;
    wire                          int_B_11_ce0;
    wire [31:0]                   int_B_11_q0;
    wire [3:0]                    int_B_11_address1;
    wire                          int_B_11_ce1;
    wire [3:0]                    int_B_11_be1;
    wire                          int_B_11_we1;
    wire [31:0]                   int_B_11_d1;
    wire [31:0]                   int_B_11_q1;
    reg                           int_B_11_read;
    reg                           int_B_11_write;
    wire [3:0]                    int_B_12_address0;
    wire                          int_B_12_ce0;
    wire [31:0]                   int_B_12_q0;
    wire [3:0]                    int_B_12_address1;
    wire                          int_B_12_ce1;
    wire [3:0]                    int_B_12_be1;
    wire                          int_B_12_we1;
    wire [31:0]                   int_B_12_d1;
    wire [31:0]                   int_B_12_q1;
    reg                           int_B_12_read;
    reg                           int_B_12_write;
    wire [3:0]                    int_B_13_address0;
    wire                          int_B_13_ce0;
    wire [31:0]                   int_B_13_q0;
    wire [3:0]                    int_B_13_address1;
    wire                          int_B_13_ce1;
    wire [3:0]                    int_B_13_be1;
    wire                          int_B_13_we1;
    wire [31:0]                   int_B_13_d1;
    wire [31:0]                   int_B_13_q1;
    reg                           int_B_13_read;
    reg                           int_B_13_write;
    wire [3:0]                    int_B_14_address0;
    wire                          int_B_14_ce0;
    wire [31:0]                   int_B_14_q0;
    wire [3:0]                    int_B_14_address1;
    wire                          int_B_14_ce1;
    wire [3:0]                    int_B_14_be1;
    wire                          int_B_14_we1;
    wire [31:0]                   int_B_14_d1;
    wire [31:0]                   int_B_14_q1;
    reg                           int_B_14_read;
    reg                           int_B_14_write;
    wire [3:0]                    int_B_15_address0;
    wire                          int_B_15_ce0;
    wire [31:0]                   int_B_15_q0;
    wire [3:0]                    int_B_15_address1;
    wire                          int_B_15_ce1;
    wire [3:0]                    int_B_15_be1;
    wire                          int_B_15_we1;
    wire [31:0]                   int_B_15_d1;
    wire [31:0]                   int_B_15_q1;
    reg                           int_B_15_read;
    reg                           int_B_15_write;
    wire [7:0]                    int_C_address0;
    wire                          int_C_ce0;
    wire [3:0]                    int_C_be0;
    wire [31:0]                   int_C_d0;
    wire [7:0]                    int_C_address1;
    wire                          int_C_ce1;
    wire [31:0]                   int_C_q1;
    reg                           int_C_read;
    reg                           int_C_write;

//------------------------Instantiation------------------
// int_A_0
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_A_0 (
    .clk0       ( ACLK ),
    .address0   ( int_A_0_address0 ),
    .ce0        ( int_A_0_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_A_0_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_A_0_address1 ),
    .ce1        ( int_A_0_ce1 ),
    .we1        ( int_A_0_be1 ),
    .d1         ( int_A_0_d1 ),
    .q1         ( int_A_0_q1 )
);
// int_A_1
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_A_1 (
    .clk0       ( ACLK ),
    .address0   ( int_A_1_address0 ),
    .ce0        ( int_A_1_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_A_1_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_A_1_address1 ),
    .ce1        ( int_A_1_ce1 ),
    .we1        ( int_A_1_be1 ),
    .d1         ( int_A_1_d1 ),
    .q1         ( int_A_1_q1 )
);
// int_A_2
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_A_2 (
    .clk0       ( ACLK ),
    .address0   ( int_A_2_address0 ),
    .ce0        ( int_A_2_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_A_2_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_A_2_address1 ),
    .ce1        ( int_A_2_ce1 ),
    .we1        ( int_A_2_be1 ),
    .d1         ( int_A_2_d1 ),
    .q1         ( int_A_2_q1 )
);
// int_A_3
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_A_3 (
    .clk0       ( ACLK ),
    .address0   ( int_A_3_address0 ),
    .ce0        ( int_A_3_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_A_3_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_A_3_address1 ),
    .ce1        ( int_A_3_ce1 ),
    .we1        ( int_A_3_be1 ),
    .d1         ( int_A_3_d1 ),
    .q1         ( int_A_3_q1 )
);
// int_A_4
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_A_4 (
    .clk0       ( ACLK ),
    .address0   ( int_A_4_address0 ),
    .ce0        ( int_A_4_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_A_4_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_A_4_address1 ),
    .ce1        ( int_A_4_ce1 ),
    .we1        ( int_A_4_be1 ),
    .d1         ( int_A_4_d1 ),
    .q1         ( int_A_4_q1 )
);
// int_A_5
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_A_5 (
    .clk0       ( ACLK ),
    .address0   ( int_A_5_address0 ),
    .ce0        ( int_A_5_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_A_5_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_A_5_address1 ),
    .ce1        ( int_A_5_ce1 ),
    .we1        ( int_A_5_be1 ),
    .d1         ( int_A_5_d1 ),
    .q1         ( int_A_5_q1 )
);
// int_A_6
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_A_6 (
    .clk0       ( ACLK ),
    .address0   ( int_A_6_address0 ),
    .ce0        ( int_A_6_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_A_6_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_A_6_address1 ),
    .ce1        ( int_A_6_ce1 ),
    .we1        ( int_A_6_be1 ),
    .d1         ( int_A_6_d1 ),
    .q1         ( int_A_6_q1 )
);
// int_A_7
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_A_7 (
    .clk0       ( ACLK ),
    .address0   ( int_A_7_address0 ),
    .ce0        ( int_A_7_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_A_7_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_A_7_address1 ),
    .ce1        ( int_A_7_ce1 ),
    .we1        ( int_A_7_be1 ),
    .d1         ( int_A_7_d1 ),
    .q1         ( int_A_7_q1 )
);
// int_A_8
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_A_8 (
    .clk0       ( ACLK ),
    .address0   ( int_A_8_address0 ),
    .ce0        ( int_A_8_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_A_8_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_A_8_address1 ),
    .ce1        ( int_A_8_ce1 ),
    .we1        ( int_A_8_be1 ),
    .d1         ( int_A_8_d1 ),
    .q1         ( int_A_8_q1 )
);
// int_A_9
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_A_9 (
    .clk0       ( ACLK ),
    .address0   ( int_A_9_address0 ),
    .ce0        ( int_A_9_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_A_9_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_A_9_address1 ),
    .ce1        ( int_A_9_ce1 ),
    .we1        ( int_A_9_be1 ),
    .d1         ( int_A_9_d1 ),
    .q1         ( int_A_9_q1 )
);
// int_A_10
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_A_10 (
    .clk0       ( ACLK ),
    .address0   ( int_A_10_address0 ),
    .ce0        ( int_A_10_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_A_10_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_A_10_address1 ),
    .ce1        ( int_A_10_ce1 ),
    .we1        ( int_A_10_be1 ),
    .d1         ( int_A_10_d1 ),
    .q1         ( int_A_10_q1 )
);
// int_A_11
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_A_11 (
    .clk0       ( ACLK ),
    .address0   ( int_A_11_address0 ),
    .ce0        ( int_A_11_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_A_11_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_A_11_address1 ),
    .ce1        ( int_A_11_ce1 ),
    .we1        ( int_A_11_be1 ),
    .d1         ( int_A_11_d1 ),
    .q1         ( int_A_11_q1 )
);
// int_A_12
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_A_12 (
    .clk0       ( ACLK ),
    .address0   ( int_A_12_address0 ),
    .ce0        ( int_A_12_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_A_12_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_A_12_address1 ),
    .ce1        ( int_A_12_ce1 ),
    .we1        ( int_A_12_be1 ),
    .d1         ( int_A_12_d1 ),
    .q1         ( int_A_12_q1 )
);
// int_A_13
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_A_13 (
    .clk0       ( ACLK ),
    .address0   ( int_A_13_address0 ),
    .ce0        ( int_A_13_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_A_13_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_A_13_address1 ),
    .ce1        ( int_A_13_ce1 ),
    .we1        ( int_A_13_be1 ),
    .d1         ( int_A_13_d1 ),
    .q1         ( int_A_13_q1 )
);
// int_A_14
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_A_14 (
    .clk0       ( ACLK ),
    .address0   ( int_A_14_address0 ),
    .ce0        ( int_A_14_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_A_14_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_A_14_address1 ),
    .ce1        ( int_A_14_ce1 ),
    .we1        ( int_A_14_be1 ),
    .d1         ( int_A_14_d1 ),
    .q1         ( int_A_14_q1 )
);
// int_A_15
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_A_15 (
    .clk0       ( ACLK ),
    .address0   ( int_A_15_address0 ),
    .ce0        ( int_A_15_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_A_15_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_A_15_address1 ),
    .ce1        ( int_A_15_ce1 ),
    .we1        ( int_A_15_be1 ),
    .d1         ( int_A_15_d1 ),
    .q1         ( int_A_15_q1 )
);
// int_B_0
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_B_0 (
    .clk0       ( ACLK ),
    .address0   ( int_B_0_address0 ),
    .ce0        ( int_B_0_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_B_0_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_B_0_address1 ),
    .ce1        ( int_B_0_ce1 ),
    .we1        ( int_B_0_be1 ),
    .d1         ( int_B_0_d1 ),
    .q1         ( int_B_0_q1 )
);
// int_B_1
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_B_1 (
    .clk0       ( ACLK ),
    .address0   ( int_B_1_address0 ),
    .ce0        ( int_B_1_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_B_1_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_B_1_address1 ),
    .ce1        ( int_B_1_ce1 ),
    .we1        ( int_B_1_be1 ),
    .d1         ( int_B_1_d1 ),
    .q1         ( int_B_1_q1 )
);
// int_B_2
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_B_2 (
    .clk0       ( ACLK ),
    .address0   ( int_B_2_address0 ),
    .ce0        ( int_B_2_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_B_2_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_B_2_address1 ),
    .ce1        ( int_B_2_ce1 ),
    .we1        ( int_B_2_be1 ),
    .d1         ( int_B_2_d1 ),
    .q1         ( int_B_2_q1 )
);
// int_B_3
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_B_3 (
    .clk0       ( ACLK ),
    .address0   ( int_B_3_address0 ),
    .ce0        ( int_B_3_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_B_3_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_B_3_address1 ),
    .ce1        ( int_B_3_ce1 ),
    .we1        ( int_B_3_be1 ),
    .d1         ( int_B_3_d1 ),
    .q1         ( int_B_3_q1 )
);
// int_B_4
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_B_4 (
    .clk0       ( ACLK ),
    .address0   ( int_B_4_address0 ),
    .ce0        ( int_B_4_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_B_4_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_B_4_address1 ),
    .ce1        ( int_B_4_ce1 ),
    .we1        ( int_B_4_be1 ),
    .d1         ( int_B_4_d1 ),
    .q1         ( int_B_4_q1 )
);
// int_B_5
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_B_5 (
    .clk0       ( ACLK ),
    .address0   ( int_B_5_address0 ),
    .ce0        ( int_B_5_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_B_5_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_B_5_address1 ),
    .ce1        ( int_B_5_ce1 ),
    .we1        ( int_B_5_be1 ),
    .d1         ( int_B_5_d1 ),
    .q1         ( int_B_5_q1 )
);
// int_B_6
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_B_6 (
    .clk0       ( ACLK ),
    .address0   ( int_B_6_address0 ),
    .ce0        ( int_B_6_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_B_6_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_B_6_address1 ),
    .ce1        ( int_B_6_ce1 ),
    .we1        ( int_B_6_be1 ),
    .d1         ( int_B_6_d1 ),
    .q1         ( int_B_6_q1 )
);
// int_B_7
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_B_7 (
    .clk0       ( ACLK ),
    .address0   ( int_B_7_address0 ),
    .ce0        ( int_B_7_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_B_7_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_B_7_address1 ),
    .ce1        ( int_B_7_ce1 ),
    .we1        ( int_B_7_be1 ),
    .d1         ( int_B_7_d1 ),
    .q1         ( int_B_7_q1 )
);
// int_B_8
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_B_8 (
    .clk0       ( ACLK ),
    .address0   ( int_B_8_address0 ),
    .ce0        ( int_B_8_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_B_8_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_B_8_address1 ),
    .ce1        ( int_B_8_ce1 ),
    .we1        ( int_B_8_be1 ),
    .d1         ( int_B_8_d1 ),
    .q1         ( int_B_8_q1 )
);
// int_B_9
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_B_9 (
    .clk0       ( ACLK ),
    .address0   ( int_B_9_address0 ),
    .ce0        ( int_B_9_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_B_9_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_B_9_address1 ),
    .ce1        ( int_B_9_ce1 ),
    .we1        ( int_B_9_be1 ),
    .d1         ( int_B_9_d1 ),
    .q1         ( int_B_9_q1 )
);
// int_B_10
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_B_10 (
    .clk0       ( ACLK ),
    .address0   ( int_B_10_address0 ),
    .ce0        ( int_B_10_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_B_10_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_B_10_address1 ),
    .ce1        ( int_B_10_ce1 ),
    .we1        ( int_B_10_be1 ),
    .d1         ( int_B_10_d1 ),
    .q1         ( int_B_10_q1 )
);
// int_B_11
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_B_11 (
    .clk0       ( ACLK ),
    .address0   ( int_B_11_address0 ),
    .ce0        ( int_B_11_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_B_11_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_B_11_address1 ),
    .ce1        ( int_B_11_ce1 ),
    .we1        ( int_B_11_be1 ),
    .d1         ( int_B_11_d1 ),
    .q1         ( int_B_11_q1 )
);
// int_B_12
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_B_12 (
    .clk0       ( ACLK ),
    .address0   ( int_B_12_address0 ),
    .ce0        ( int_B_12_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_B_12_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_B_12_address1 ),
    .ce1        ( int_B_12_ce1 ),
    .we1        ( int_B_12_be1 ),
    .d1         ( int_B_12_d1 ),
    .q1         ( int_B_12_q1 )
);
// int_B_13
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_B_13 (
    .clk0       ( ACLK ),
    .address0   ( int_B_13_address0 ),
    .ce0        ( int_B_13_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_B_13_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_B_13_address1 ),
    .ce1        ( int_B_13_ce1 ),
    .we1        ( int_B_13_be1 ),
    .d1         ( int_B_13_d1 ),
    .q1         ( int_B_13_q1 )
);
// int_B_14
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_B_14 (
    .clk0       ( ACLK ),
    .address0   ( int_B_14_address0 ),
    .ce0        ( int_B_14_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_B_14_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_B_14_address1 ),
    .ce1        ( int_B_14_ce1 ),
    .we1        ( int_B_14_be1 ),
    .d1         ( int_B_14_d1 ),
    .q1         ( int_B_14_q1 )
);
// int_B_15
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 16 )
) int_B_15 (
    .clk0       ( ACLK ),
    .address0   ( int_B_15_address0 ),
    .ce0        ( int_B_15_ce0 ),
    .we0        ( {4{1'b0}} ),
    .d0         ( {32{1'b0}} ),
    .q0         ( int_B_15_q0 ),
    .clk1       ( ACLK ),
    .address1   ( int_B_15_address1 ),
    .ce1        ( int_B_15_ce1 ),
    .we1        ( int_B_15_be1 ),
    .d1         ( int_B_15_d1 ),
    .q1         ( int_B_15_q1 )
);
// int_C
matrix_mult_hw_control_s_axi_ram #(
    .MEM_STYLE  ( "auto" ),
    .MEM_TYPE   ( "S2P" ),
    .BYTE_WIDTH ( 8 ),
    .WIDTH      ( 32 ),
    .BYTES      ( 4 ),
    .DEPTH      ( 256 )
) int_C (
    .clk0       ( ACLK ),
    .address0   ( int_C_address0 ),
    .ce0        ( int_C_ce0 ),
    .we0        ( int_C_be0 ),
    .d0         ( int_C_d0 ),
    .q0         (  ),
    .clk1       ( ACLK ),
    .address1   ( int_C_address1 ),
    .ce1        ( int_C_ce1 ),
    .we1        ( {4{1'b0}} ),
    .d1         ( {32{1'b0}} ),
    .q1         ( int_C_q1 )
);


//------------------------AXI write fsm------------------
assign AWREADY = (wstate == WRIDLE);
assign WREADY  = (wstate == WRDATA) && (!ar_hs);
assign BVALID  = (wstate == WRRESP);
assign BRESP   = 2'b00;  // OKAY
assign wmask   = { {8{WSTRB[3]}}, {8{WSTRB[2]}}, {8{WSTRB[1]}}, {8{WSTRB[0]}} };
assign aw_hs   = AWVALID & AWREADY;
assign w_hs    = WVALID & WREADY;

// wstate
always @(posedge ACLK) begin
    if (ARESET)
        wstate <= WRRESET;
    else if (ACLK_EN)
        wstate <= wnext;
end

// wnext
always @(*) begin
    case (wstate)
        WRIDLE:
            if (AWVALID)
                wnext = WRDATA;
            else
                wnext = WRIDLE;
        WRDATA:
            if (w_hs)
                wnext = WRRESP;
            else
                wnext = WRDATA;
        WRRESP:
            if (BREADY & BVALID)
                wnext = WRIDLE;
            else
                wnext = WRRESP;
        default:
            wnext = WRIDLE;
    endcase
end

// waddr
always @(posedge ACLK) begin
    if (ACLK_EN) begin
        if (aw_hs)
            waddr <= {AWADDR[ADDR_BITS-1:2], {2{1'b0}}};
    end
end

//------------------------AXI read fsm-------------------
assign ARREADY = (rstate == RDIDLE);
assign RDATA   = rdata;
assign RRESP   = 2'b00;  // OKAY
assign RVALID  = (rstate == RDDATA) & !int_A_0_read & !int_A_1_read & !int_A_2_read & !int_A_3_read & !int_A_4_read & !int_A_5_read & !int_A_6_read & !int_A_7_read & !int_A_8_read & !int_A_9_read & !int_A_10_read & !int_A_11_read & !int_A_12_read & !int_A_13_read & !int_A_14_read & !int_A_15_read & !int_B_0_read & !int_B_1_read & !int_B_2_read & !int_B_3_read & !int_B_4_read & !int_B_5_read & !int_B_6_read & !int_B_7_read & !int_B_8_read & !int_B_9_read & !int_B_10_read & !int_B_11_read & !int_B_12_read & !int_B_13_read & !int_B_14_read & !int_B_15_read & !int_C_read;
assign ar_hs   = ARVALID & ARREADY;
assign raddr   = ARADDR[ADDR_BITS-1:0];

// rstate
always @(posedge ACLK) begin
    if (ARESET)
        rstate <= RDRESET;
    else if (ACLK_EN)
        rstate <= rnext;
end

// rnext
always @(*) begin
    case (rstate)
        RDIDLE:
            if (ARVALID)
                rnext = RDDATA;
            else
                rnext = RDIDLE;
        RDDATA:
            if (RREADY & RVALID)
                rnext = RDIDLE;
            else
                rnext = RDDATA;
        default:
            rnext = RDIDLE;
    endcase
end

// rdata
always @(posedge ACLK) begin
    if (ACLK_EN) begin
        if (ar_hs) begin
            rdata <= 'b0;
            case (raddr)
                ADDR_AP_CTRL: begin
                    rdata[0] <= int_ap_start;
                    rdata[1] <= int_task_ap_done;
                    rdata[2] <= int_ap_idle;
                    rdata[3] <= int_ap_ready;
                    rdata[7] <= int_auto_restart;
                    rdata[9] <= int_interrupt;
                end
                ADDR_GIE: begin
                    rdata <= int_gie;
                end
                ADDR_IER: begin
                    rdata <= int_ier;
                end
                ADDR_ISR: begin
                    rdata <= int_isr;
                end
            endcase
        end
        else if (int_A_0_read) begin
            rdata <= int_A_0_q1;
        end
        else if (int_A_1_read) begin
            rdata <= int_A_1_q1;
        end
        else if (int_A_2_read) begin
            rdata <= int_A_2_q1;
        end
        else if (int_A_3_read) begin
            rdata <= int_A_3_q1;
        end
        else if (int_A_4_read) begin
            rdata <= int_A_4_q1;
        end
        else if (int_A_5_read) begin
            rdata <= int_A_5_q1;
        end
        else if (int_A_6_read) begin
            rdata <= int_A_6_q1;
        end
        else if (int_A_7_read) begin
            rdata <= int_A_7_q1;
        end
        else if (int_A_8_read) begin
            rdata <= int_A_8_q1;
        end
        else if (int_A_9_read) begin
            rdata <= int_A_9_q1;
        end
        else if (int_A_10_read) begin
            rdata <= int_A_10_q1;
        end
        else if (int_A_11_read) begin
            rdata <= int_A_11_q1;
        end
        else if (int_A_12_read) begin
            rdata <= int_A_12_q1;
        end
        else if (int_A_13_read) begin
            rdata <= int_A_13_q1;
        end
        else if (int_A_14_read) begin
            rdata <= int_A_14_q1;
        end
        else if (int_A_15_read) begin
            rdata <= int_A_15_q1;
        end
        else if (int_B_0_read) begin
            rdata <= int_B_0_q1;
        end
        else if (int_B_1_read) begin
            rdata <= int_B_1_q1;
        end
        else if (int_B_2_read) begin
            rdata <= int_B_2_q1;
        end
        else if (int_B_3_read) begin
            rdata <= int_B_3_q1;
        end
        else if (int_B_4_read) begin
            rdata <= int_B_4_q1;
        end
        else if (int_B_5_read) begin
            rdata <= int_B_5_q1;
        end
        else if (int_B_6_read) begin
            rdata <= int_B_6_q1;
        end
        else if (int_B_7_read) begin
            rdata <= int_B_7_q1;
        end
        else if (int_B_8_read) begin
            rdata <= int_B_8_q1;
        end
        else if (int_B_9_read) begin
            rdata <= int_B_9_q1;
        end
        else if (int_B_10_read) begin
            rdata <= int_B_10_q1;
        end
        else if (int_B_11_read) begin
            rdata <= int_B_11_q1;
        end
        else if (int_B_12_read) begin
            rdata <= int_B_12_q1;
        end
        else if (int_B_13_read) begin
            rdata <= int_B_13_q1;
        end
        else if (int_B_14_read) begin
            rdata <= int_B_14_q1;
        end
        else if (int_B_15_read) begin
            rdata <= int_B_15_q1;
        end
        else if (int_C_read) begin
            rdata <= int_C_q1;
        end
    end
end


//------------------------Register logic-----------------
assign interrupt         = int_interrupt;
assign ap_start          = int_ap_start;
assign task_ap_done      = (ap_done && !auto_restart_status) || auto_restart_done;
assign task_ap_ready     = ap_ready && !int_auto_restart;
assign auto_restart_done = auto_restart_status && (ap_idle && !int_ap_idle);
// int_interrupt
always @(posedge ACLK) begin
    if (ARESET)
        int_interrupt <= 1'b0;
    else if (ACLK_EN) begin
        if (int_gie && (|int_isr))
            int_interrupt <= 1'b1;
        else
            int_interrupt <= 1'b0;
    end
end

// int_ap_start
always @(posedge ACLK) begin
    if (ARESET)
        int_ap_start <= 1'b0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_AP_CTRL && WSTRB[0] && WDATA[0])
            int_ap_start <= 1'b1;
        else if (ap_ready)
            int_ap_start <= int_auto_restart; // clear on handshake/auto restart
    end
end

// int_ap_done
always @(posedge ACLK) begin
    if (ARESET)
        int_ap_done <= 1'b0;
    else if (ACLK_EN) begin
            int_ap_done <= ap_done;
    end
end

// int_task_ap_done
always @(posedge ACLK) begin
    if (ARESET)
        int_task_ap_done <= 1'b0;
    else if (ACLK_EN) begin
        if (task_ap_done)
            int_task_ap_done <= 1'b1;
        else if (ar_hs && raddr == ADDR_AP_CTRL)
            int_task_ap_done <= 1'b0; // clear on read
    end
end

// int_ap_idle
always @(posedge ACLK) begin
    if (ARESET)
        int_ap_idle <= 1'b0;
    else if (ACLK_EN) begin
            int_ap_idle <= ap_idle;
    end
end

// int_ap_ready
always @(posedge ACLK) begin
    if (ARESET)
        int_ap_ready <= 1'b0;
    else if (ACLK_EN) begin
        if (task_ap_ready)
            int_ap_ready <= 1'b1;
        else if (ar_hs && raddr == ADDR_AP_CTRL)
            int_ap_ready <= 1'b0;
    end
end

// int_auto_restart
always @(posedge ACLK) begin
    if (ARESET)
        int_auto_restart <= 1'b0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_AP_CTRL && WSTRB[0])
            int_auto_restart <= WDATA[7];
    end
end

// auto_restart_status
always @(posedge ACLK) begin
    if (ARESET)
        auto_restart_status <= 1'b0;
    else if (ACLK_EN) begin
        if (int_auto_restart)
            auto_restart_status <= 1'b1;
        else if (ap_idle)
            auto_restart_status <= 1'b0;
    end
end

// int_gie
always @(posedge ACLK) begin
    if (ARESET)
        int_gie <= 1'b0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_GIE && WSTRB[0])
            int_gie <= WDATA[0];
    end
end

// int_ier
always @(posedge ACLK) begin
    if (ARESET)
        int_ier <= 1'b0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_IER && WSTRB[0])
            int_ier <= WDATA[1:0];
    end
end

// int_isr[0]
always @(posedge ACLK) begin
    if (ARESET)
        int_isr[0] <= 1'b0;
    else if (ACLK_EN) begin
        if (int_ier[0] & ap_done)
            int_isr[0] <= 1'b1;
        else if (w_hs && waddr == ADDR_ISR && WSTRB[0])
            int_isr[0] <= int_isr[0] ^ WDATA[0]; // toggle on write
    end
end

// int_isr[1]
always @(posedge ACLK) begin
    if (ARESET)
        int_isr[1] <= 1'b0;
    else if (ACLK_EN) begin
        if (int_ier[1] & ap_ready)
            int_isr[1] <= 1'b1;
        else if (w_hs && waddr == ADDR_ISR && WSTRB[0])
            int_isr[1] <= int_isr[1] ^ WDATA[1]; // toggle on write
    end
end

//synthesis translate_off
always @(posedge ACLK) begin
    if (ACLK_EN) begin
        if (int_gie & ~int_isr[0] & int_ier[0] & ap_done)
            $display ("// Interrupt Monitor : interrupt for ap_done detected @ \"%0t\"", $time);
        if (int_gie & ~int_isr[1] & int_ier[1] & ap_ready)
            $display ("// Interrupt Monitor : interrupt for ap_ready detected @ \"%0t\"", $time);
    end
end
//synthesis translate_on

//------------------------Memory logic-------------------
// A_0
assign int_A_0_address0  = A_0_address0;
assign int_A_0_ce0       = A_0_ce0;
assign A_0_q0            = int_A_0_q0;
assign int_A_0_address1  = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_A_0_ce1       = ar_hs | (int_A_0_write & WVALID);
assign int_A_0_we1       = int_A_0_write & w_hs;
assign int_A_0_be1       = int_A_0_we1 ? WSTRB : 4'd0;
assign int_A_0_d1        = WDATA;
// A_1
assign int_A_1_address0  = A_1_address0;
assign int_A_1_ce0       = A_1_ce0;
assign A_1_q0            = int_A_1_q0;
assign int_A_1_address1  = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_A_1_ce1       = ar_hs | (int_A_1_write & WVALID);
assign int_A_1_we1       = int_A_1_write & w_hs;
assign int_A_1_be1       = int_A_1_we1 ? WSTRB : 4'd0;
assign int_A_1_d1        = WDATA;
// A_2
assign int_A_2_address0  = A_2_address0;
assign int_A_2_ce0       = A_2_ce0;
assign A_2_q0            = int_A_2_q0;
assign int_A_2_address1  = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_A_2_ce1       = ar_hs | (int_A_2_write & WVALID);
assign int_A_2_we1       = int_A_2_write & w_hs;
assign int_A_2_be1       = int_A_2_we1 ? WSTRB : 4'd0;
assign int_A_2_d1        = WDATA;
// A_3
assign int_A_3_address0  = A_3_address0;
assign int_A_3_ce0       = A_3_ce0;
assign A_3_q0            = int_A_3_q0;
assign int_A_3_address1  = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_A_3_ce1       = ar_hs | (int_A_3_write & WVALID);
assign int_A_3_we1       = int_A_3_write & w_hs;
assign int_A_3_be1       = int_A_3_we1 ? WSTRB : 4'd0;
assign int_A_3_d1        = WDATA;
// A_4
assign int_A_4_address0  = A_4_address0;
assign int_A_4_ce0       = A_4_ce0;
assign A_4_q0            = int_A_4_q0;
assign int_A_4_address1  = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_A_4_ce1       = ar_hs | (int_A_4_write & WVALID);
assign int_A_4_we1       = int_A_4_write & w_hs;
assign int_A_4_be1       = int_A_4_we1 ? WSTRB : 4'd0;
assign int_A_4_d1        = WDATA;
// A_5
assign int_A_5_address0  = A_5_address0;
assign int_A_5_ce0       = A_5_ce0;
assign A_5_q0            = int_A_5_q0;
assign int_A_5_address1  = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_A_5_ce1       = ar_hs | (int_A_5_write & WVALID);
assign int_A_5_we1       = int_A_5_write & w_hs;
assign int_A_5_be1       = int_A_5_we1 ? WSTRB : 4'd0;
assign int_A_5_d1        = WDATA;
// A_6
assign int_A_6_address0  = A_6_address0;
assign int_A_6_ce0       = A_6_ce0;
assign A_6_q0            = int_A_6_q0;
assign int_A_6_address1  = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_A_6_ce1       = ar_hs | (int_A_6_write & WVALID);
assign int_A_6_we1       = int_A_6_write & w_hs;
assign int_A_6_be1       = int_A_6_we1 ? WSTRB : 4'd0;
assign int_A_6_d1        = WDATA;
// A_7
assign int_A_7_address0  = A_7_address0;
assign int_A_7_ce0       = A_7_ce0;
assign A_7_q0            = int_A_7_q0;
assign int_A_7_address1  = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_A_7_ce1       = ar_hs | (int_A_7_write & WVALID);
assign int_A_7_we1       = int_A_7_write & w_hs;
assign int_A_7_be1       = int_A_7_we1 ? WSTRB : 4'd0;
assign int_A_7_d1        = WDATA;
// A_8
assign int_A_8_address0  = A_8_address0;
assign int_A_8_ce0       = A_8_ce0;
assign A_8_q0            = int_A_8_q0;
assign int_A_8_address1  = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_A_8_ce1       = ar_hs | (int_A_8_write & WVALID);
assign int_A_8_we1       = int_A_8_write & w_hs;
assign int_A_8_be1       = int_A_8_we1 ? WSTRB : 4'd0;
assign int_A_8_d1        = WDATA;
// A_9
assign int_A_9_address0  = A_9_address0;
assign int_A_9_ce0       = A_9_ce0;
assign A_9_q0            = int_A_9_q0;
assign int_A_9_address1  = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_A_9_ce1       = ar_hs | (int_A_9_write & WVALID);
assign int_A_9_we1       = int_A_9_write & w_hs;
assign int_A_9_be1       = int_A_9_we1 ? WSTRB : 4'd0;
assign int_A_9_d1        = WDATA;
// A_10
assign int_A_10_address0 = A_10_address0;
assign int_A_10_ce0      = A_10_ce0;
assign A_10_q0           = int_A_10_q0;
assign int_A_10_address1 = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_A_10_ce1      = ar_hs | (int_A_10_write & WVALID);
assign int_A_10_we1      = int_A_10_write & w_hs;
assign int_A_10_be1      = int_A_10_we1 ? WSTRB : 4'd0;
assign int_A_10_d1       = WDATA;
// A_11
assign int_A_11_address0 = A_11_address0;
assign int_A_11_ce0      = A_11_ce0;
assign A_11_q0           = int_A_11_q0;
assign int_A_11_address1 = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_A_11_ce1      = ar_hs | (int_A_11_write & WVALID);
assign int_A_11_we1      = int_A_11_write & w_hs;
assign int_A_11_be1      = int_A_11_we1 ? WSTRB : 4'd0;
assign int_A_11_d1       = WDATA;
// A_12
assign int_A_12_address0 = A_12_address0;
assign int_A_12_ce0      = A_12_ce0;
assign A_12_q0           = int_A_12_q0;
assign int_A_12_address1 = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_A_12_ce1      = ar_hs | (int_A_12_write & WVALID);
assign int_A_12_we1      = int_A_12_write & w_hs;
assign int_A_12_be1      = int_A_12_we1 ? WSTRB : 4'd0;
assign int_A_12_d1       = WDATA;
// A_13
assign int_A_13_address0 = A_13_address0;
assign int_A_13_ce0      = A_13_ce0;
assign A_13_q0           = int_A_13_q0;
assign int_A_13_address1 = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_A_13_ce1      = ar_hs | (int_A_13_write & WVALID);
assign int_A_13_we1      = int_A_13_write & w_hs;
assign int_A_13_be1      = int_A_13_we1 ? WSTRB : 4'd0;
assign int_A_13_d1       = WDATA;
// A_14
assign int_A_14_address0 = A_14_address0;
assign int_A_14_ce0      = A_14_ce0;
assign A_14_q0           = int_A_14_q0;
assign int_A_14_address1 = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_A_14_ce1      = ar_hs | (int_A_14_write & WVALID);
assign int_A_14_we1      = int_A_14_write & w_hs;
assign int_A_14_be1      = int_A_14_we1 ? WSTRB : 4'd0;
assign int_A_14_d1       = WDATA;
// A_15
assign int_A_15_address0 = A_15_address0;
assign int_A_15_ce0      = A_15_ce0;
assign A_15_q0           = int_A_15_q0;
assign int_A_15_address1 = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_A_15_ce1      = ar_hs | (int_A_15_write & WVALID);
assign int_A_15_we1      = int_A_15_write & w_hs;
assign int_A_15_be1      = int_A_15_we1 ? WSTRB : 4'd0;
assign int_A_15_d1       = WDATA;
// B_0
assign int_B_0_address0  = B_0_address0;
assign int_B_0_ce0       = B_0_ce0;
assign B_0_q0            = int_B_0_q0;
assign int_B_0_address1  = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_B_0_ce1       = ar_hs | (int_B_0_write & WVALID);
assign int_B_0_we1       = int_B_0_write & w_hs;
assign int_B_0_be1       = int_B_0_we1 ? WSTRB : 4'd0;
assign int_B_0_d1        = WDATA;
// B_1
assign int_B_1_address0  = B_1_address0;
assign int_B_1_ce0       = B_1_ce0;
assign B_1_q0            = int_B_1_q0;
assign int_B_1_address1  = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_B_1_ce1       = ar_hs | (int_B_1_write & WVALID);
assign int_B_1_we1       = int_B_1_write & w_hs;
assign int_B_1_be1       = int_B_1_we1 ? WSTRB : 4'd0;
assign int_B_1_d1        = WDATA;
// B_2
assign int_B_2_address0  = B_2_address0;
assign int_B_2_ce0       = B_2_ce0;
assign B_2_q0            = int_B_2_q0;
assign int_B_2_address1  = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_B_2_ce1       = ar_hs | (int_B_2_write & WVALID);
assign int_B_2_we1       = int_B_2_write & w_hs;
assign int_B_2_be1       = int_B_2_we1 ? WSTRB : 4'd0;
assign int_B_2_d1        = WDATA;
// B_3
assign int_B_3_address0  = B_3_address0;
assign int_B_3_ce0       = B_3_ce0;
assign B_3_q0            = int_B_3_q0;
assign int_B_3_address1  = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_B_3_ce1       = ar_hs | (int_B_3_write & WVALID);
assign int_B_3_we1       = int_B_3_write & w_hs;
assign int_B_3_be1       = int_B_3_we1 ? WSTRB : 4'd0;
assign int_B_3_d1        = WDATA;
// B_4
assign int_B_4_address0  = B_4_address0;
assign int_B_4_ce0       = B_4_ce0;
assign B_4_q0            = int_B_4_q0;
assign int_B_4_address1  = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_B_4_ce1       = ar_hs | (int_B_4_write & WVALID);
assign int_B_4_we1       = int_B_4_write & w_hs;
assign int_B_4_be1       = int_B_4_we1 ? WSTRB : 4'd0;
assign int_B_4_d1        = WDATA;
// B_5
assign int_B_5_address0  = B_5_address0;
assign int_B_5_ce0       = B_5_ce0;
assign B_5_q0            = int_B_5_q0;
assign int_B_5_address1  = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_B_5_ce1       = ar_hs | (int_B_5_write & WVALID);
assign int_B_5_we1       = int_B_5_write & w_hs;
assign int_B_5_be1       = int_B_5_we1 ? WSTRB : 4'd0;
assign int_B_5_d1        = WDATA;
// B_6
assign int_B_6_address0  = B_6_address0;
assign int_B_6_ce0       = B_6_ce0;
assign B_6_q0            = int_B_6_q0;
assign int_B_6_address1  = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_B_6_ce1       = ar_hs | (int_B_6_write & WVALID);
assign int_B_6_we1       = int_B_6_write & w_hs;
assign int_B_6_be1       = int_B_6_we1 ? WSTRB : 4'd0;
assign int_B_6_d1        = WDATA;
// B_7
assign int_B_7_address0  = B_7_address0;
assign int_B_7_ce0       = B_7_ce0;
assign B_7_q0            = int_B_7_q0;
assign int_B_7_address1  = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_B_7_ce1       = ar_hs | (int_B_7_write & WVALID);
assign int_B_7_we1       = int_B_7_write & w_hs;
assign int_B_7_be1       = int_B_7_we1 ? WSTRB : 4'd0;
assign int_B_7_d1        = WDATA;
// B_8
assign int_B_8_address0  = B_8_address0;
assign int_B_8_ce0       = B_8_ce0;
assign B_8_q0            = int_B_8_q0;
assign int_B_8_address1  = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_B_8_ce1       = ar_hs | (int_B_8_write & WVALID);
assign int_B_8_we1       = int_B_8_write & w_hs;
assign int_B_8_be1       = int_B_8_we1 ? WSTRB : 4'd0;
assign int_B_8_d1        = WDATA;
// B_9
assign int_B_9_address0  = B_9_address0;
assign int_B_9_ce0       = B_9_ce0;
assign B_9_q0            = int_B_9_q0;
assign int_B_9_address1  = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_B_9_ce1       = ar_hs | (int_B_9_write & WVALID);
assign int_B_9_we1       = int_B_9_write & w_hs;
assign int_B_9_be1       = int_B_9_we1 ? WSTRB : 4'd0;
assign int_B_9_d1        = WDATA;
// B_10
assign int_B_10_address0 = B_10_address0;
assign int_B_10_ce0      = B_10_ce0;
assign B_10_q0           = int_B_10_q0;
assign int_B_10_address1 = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_B_10_ce1      = ar_hs | (int_B_10_write & WVALID);
assign int_B_10_we1      = int_B_10_write & w_hs;
assign int_B_10_be1      = int_B_10_we1 ? WSTRB : 4'd0;
assign int_B_10_d1       = WDATA;
// B_11
assign int_B_11_address0 = B_11_address0;
assign int_B_11_ce0      = B_11_ce0;
assign B_11_q0           = int_B_11_q0;
assign int_B_11_address1 = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_B_11_ce1      = ar_hs | (int_B_11_write & WVALID);
assign int_B_11_we1      = int_B_11_write & w_hs;
assign int_B_11_be1      = int_B_11_we1 ? WSTRB : 4'd0;
assign int_B_11_d1       = WDATA;
// B_12
assign int_B_12_address0 = B_12_address0;
assign int_B_12_ce0      = B_12_ce0;
assign B_12_q0           = int_B_12_q0;
assign int_B_12_address1 = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_B_12_ce1      = ar_hs | (int_B_12_write & WVALID);
assign int_B_12_we1      = int_B_12_write & w_hs;
assign int_B_12_be1      = int_B_12_we1 ? WSTRB : 4'd0;
assign int_B_12_d1       = WDATA;
// B_13
assign int_B_13_address0 = B_13_address0;
assign int_B_13_ce0      = B_13_ce0;
assign B_13_q0           = int_B_13_q0;
assign int_B_13_address1 = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_B_13_ce1      = ar_hs | (int_B_13_write & WVALID);
assign int_B_13_we1      = int_B_13_write & w_hs;
assign int_B_13_be1      = int_B_13_we1 ? WSTRB : 4'd0;
assign int_B_13_d1       = WDATA;
// B_14
assign int_B_14_address0 = B_14_address0;
assign int_B_14_ce0      = B_14_ce0;
assign B_14_q0           = int_B_14_q0;
assign int_B_14_address1 = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_B_14_ce1      = ar_hs | (int_B_14_write & WVALID);
assign int_B_14_we1      = int_B_14_write & w_hs;
assign int_B_14_be1      = int_B_14_we1 ? WSTRB : 4'd0;
assign int_B_14_d1       = WDATA;
// B_15
assign int_B_15_address0 = B_15_address0;
assign int_B_15_ce0      = B_15_ce0;
assign B_15_q0           = int_B_15_q0;
assign int_B_15_address1 = ar_hs ? raddr[5:2] : waddr[5:2];
assign int_B_15_ce1      = ar_hs | (int_B_15_write & WVALID);
assign int_B_15_we1      = int_B_15_write & w_hs;
assign int_B_15_be1      = int_B_15_we1 ? WSTRB : 4'd0;
assign int_B_15_d1       = WDATA;
// C
assign int_C_address0    = C_address0;
assign int_C_ce0         = C_ce0;
assign int_C_be0         = {4{C_we0}};
assign int_C_d0          = C_d0;
assign int_C_address1    = raddr[9 : 2];
assign int_C_ce1         = ar_hs;
// int_A_0_read
always @(posedge ACLK) begin
    if (ARESET)
        int_A_0_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_A_0_BASE && raddr <= ADDR_A_0_HIGH)
            int_A_0_read <= 1'b1;
        else
            int_A_0_read <= 1'b0;
    end
end

// int_A_0_write
always @(posedge ACLK) begin
    if (ARESET)
        int_A_0_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_A_0_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_A_0_HIGH)
            int_A_0_write <= 1'b1;
        else if (w_hs)
            int_A_0_write <= 1'b0;
    end
end

// int_A_1_read
always @(posedge ACLK) begin
    if (ARESET)
        int_A_1_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_A_1_BASE && raddr <= ADDR_A_1_HIGH)
            int_A_1_read <= 1'b1;
        else
            int_A_1_read <= 1'b0;
    end
end

// int_A_1_write
always @(posedge ACLK) begin
    if (ARESET)
        int_A_1_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_A_1_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_A_1_HIGH)
            int_A_1_write <= 1'b1;
        else if (w_hs)
            int_A_1_write <= 1'b0;
    end
end

// int_A_2_read
always @(posedge ACLK) begin
    if (ARESET)
        int_A_2_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_A_2_BASE && raddr <= ADDR_A_2_HIGH)
            int_A_2_read <= 1'b1;
        else
            int_A_2_read <= 1'b0;
    end
end

// int_A_2_write
always @(posedge ACLK) begin
    if (ARESET)
        int_A_2_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_A_2_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_A_2_HIGH)
            int_A_2_write <= 1'b1;
        else if (w_hs)
            int_A_2_write <= 1'b0;
    end
end

// int_A_3_read
always @(posedge ACLK) begin
    if (ARESET)
        int_A_3_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_A_3_BASE && raddr <= ADDR_A_3_HIGH)
            int_A_3_read <= 1'b1;
        else
            int_A_3_read <= 1'b0;
    end
end

// int_A_3_write
always @(posedge ACLK) begin
    if (ARESET)
        int_A_3_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_A_3_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_A_3_HIGH)
            int_A_3_write <= 1'b1;
        else if (w_hs)
            int_A_3_write <= 1'b0;
    end
end

// int_A_4_read
always @(posedge ACLK) begin
    if (ARESET)
        int_A_4_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_A_4_BASE && raddr <= ADDR_A_4_HIGH)
            int_A_4_read <= 1'b1;
        else
            int_A_4_read <= 1'b0;
    end
end

// int_A_4_write
always @(posedge ACLK) begin
    if (ARESET)
        int_A_4_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_A_4_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_A_4_HIGH)
            int_A_4_write <= 1'b1;
        else if (w_hs)
            int_A_4_write <= 1'b0;
    end
end

// int_A_5_read
always @(posedge ACLK) begin
    if (ARESET)
        int_A_5_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_A_5_BASE && raddr <= ADDR_A_5_HIGH)
            int_A_5_read <= 1'b1;
        else
            int_A_5_read <= 1'b0;
    end
end

// int_A_5_write
always @(posedge ACLK) begin
    if (ARESET)
        int_A_5_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_A_5_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_A_5_HIGH)
            int_A_5_write <= 1'b1;
        else if (w_hs)
            int_A_5_write <= 1'b0;
    end
end

// int_A_6_read
always @(posedge ACLK) begin
    if (ARESET)
        int_A_6_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_A_6_BASE && raddr <= ADDR_A_6_HIGH)
            int_A_6_read <= 1'b1;
        else
            int_A_6_read <= 1'b0;
    end
end

// int_A_6_write
always @(posedge ACLK) begin
    if (ARESET)
        int_A_6_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_A_6_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_A_6_HIGH)
            int_A_6_write <= 1'b1;
        else if (w_hs)
            int_A_6_write <= 1'b0;
    end
end

// int_A_7_read
always @(posedge ACLK) begin
    if (ARESET)
        int_A_7_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_A_7_BASE && raddr <= ADDR_A_7_HIGH)
            int_A_7_read <= 1'b1;
        else
            int_A_7_read <= 1'b0;
    end
end

// int_A_7_write
always @(posedge ACLK) begin
    if (ARESET)
        int_A_7_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_A_7_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_A_7_HIGH)
            int_A_7_write <= 1'b1;
        else if (w_hs)
            int_A_7_write <= 1'b0;
    end
end

// int_A_8_read
always @(posedge ACLK) begin
    if (ARESET)
        int_A_8_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_A_8_BASE && raddr <= ADDR_A_8_HIGH)
            int_A_8_read <= 1'b1;
        else
            int_A_8_read <= 1'b0;
    end
end

// int_A_8_write
always @(posedge ACLK) begin
    if (ARESET)
        int_A_8_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_A_8_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_A_8_HIGH)
            int_A_8_write <= 1'b1;
        else if (w_hs)
            int_A_8_write <= 1'b0;
    end
end

// int_A_9_read
always @(posedge ACLK) begin
    if (ARESET)
        int_A_9_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_A_9_BASE && raddr <= ADDR_A_9_HIGH)
            int_A_9_read <= 1'b1;
        else
            int_A_9_read <= 1'b0;
    end
end

// int_A_9_write
always @(posedge ACLK) begin
    if (ARESET)
        int_A_9_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_A_9_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_A_9_HIGH)
            int_A_9_write <= 1'b1;
        else if (w_hs)
            int_A_9_write <= 1'b0;
    end
end

// int_A_10_read
always @(posedge ACLK) begin
    if (ARESET)
        int_A_10_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_A_10_BASE && raddr <= ADDR_A_10_HIGH)
            int_A_10_read <= 1'b1;
        else
            int_A_10_read <= 1'b0;
    end
end

// int_A_10_write
always @(posedge ACLK) begin
    if (ARESET)
        int_A_10_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_A_10_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_A_10_HIGH)
            int_A_10_write <= 1'b1;
        else if (w_hs)
            int_A_10_write <= 1'b0;
    end
end

// int_A_11_read
always @(posedge ACLK) begin
    if (ARESET)
        int_A_11_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_A_11_BASE && raddr <= ADDR_A_11_HIGH)
            int_A_11_read <= 1'b1;
        else
            int_A_11_read <= 1'b0;
    end
end

// int_A_11_write
always @(posedge ACLK) begin
    if (ARESET)
        int_A_11_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_A_11_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_A_11_HIGH)
            int_A_11_write <= 1'b1;
        else if (w_hs)
            int_A_11_write <= 1'b0;
    end
end

// int_A_12_read
always @(posedge ACLK) begin
    if (ARESET)
        int_A_12_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_A_12_BASE && raddr <= ADDR_A_12_HIGH)
            int_A_12_read <= 1'b1;
        else
            int_A_12_read <= 1'b0;
    end
end

// int_A_12_write
always @(posedge ACLK) begin
    if (ARESET)
        int_A_12_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_A_12_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_A_12_HIGH)
            int_A_12_write <= 1'b1;
        else if (w_hs)
            int_A_12_write <= 1'b0;
    end
end

// int_A_13_read
always @(posedge ACLK) begin
    if (ARESET)
        int_A_13_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_A_13_BASE && raddr <= ADDR_A_13_HIGH)
            int_A_13_read <= 1'b1;
        else
            int_A_13_read <= 1'b0;
    end
end

// int_A_13_write
always @(posedge ACLK) begin
    if (ARESET)
        int_A_13_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_A_13_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_A_13_HIGH)
            int_A_13_write <= 1'b1;
        else if (w_hs)
            int_A_13_write <= 1'b0;
    end
end

// int_A_14_read
always @(posedge ACLK) begin
    if (ARESET)
        int_A_14_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_A_14_BASE && raddr <= ADDR_A_14_HIGH)
            int_A_14_read <= 1'b1;
        else
            int_A_14_read <= 1'b0;
    end
end

// int_A_14_write
always @(posedge ACLK) begin
    if (ARESET)
        int_A_14_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_A_14_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_A_14_HIGH)
            int_A_14_write <= 1'b1;
        else if (w_hs)
            int_A_14_write <= 1'b0;
    end
end

// int_A_15_read
always @(posedge ACLK) begin
    if (ARESET)
        int_A_15_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_A_15_BASE && raddr <= ADDR_A_15_HIGH)
            int_A_15_read <= 1'b1;
        else
            int_A_15_read <= 1'b0;
    end
end

// int_A_15_write
always @(posedge ACLK) begin
    if (ARESET)
        int_A_15_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_A_15_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_A_15_HIGH)
            int_A_15_write <= 1'b1;
        else if (w_hs)
            int_A_15_write <= 1'b0;
    end
end

// int_B_0_read
always @(posedge ACLK) begin
    if (ARESET)
        int_B_0_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_B_0_BASE && raddr <= ADDR_B_0_HIGH)
            int_B_0_read <= 1'b1;
        else
            int_B_0_read <= 1'b0;
    end
end

// int_B_0_write
always @(posedge ACLK) begin
    if (ARESET)
        int_B_0_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_B_0_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_B_0_HIGH)
            int_B_0_write <= 1'b1;
        else if (w_hs)
            int_B_0_write <= 1'b0;
    end
end

// int_B_1_read
always @(posedge ACLK) begin
    if (ARESET)
        int_B_1_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_B_1_BASE && raddr <= ADDR_B_1_HIGH)
            int_B_1_read <= 1'b1;
        else
            int_B_1_read <= 1'b0;
    end
end

// int_B_1_write
always @(posedge ACLK) begin
    if (ARESET)
        int_B_1_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_B_1_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_B_1_HIGH)
            int_B_1_write <= 1'b1;
        else if (w_hs)
            int_B_1_write <= 1'b0;
    end
end

// int_B_2_read
always @(posedge ACLK) begin
    if (ARESET)
        int_B_2_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_B_2_BASE && raddr <= ADDR_B_2_HIGH)
            int_B_2_read <= 1'b1;
        else
            int_B_2_read <= 1'b0;
    end
end

// int_B_2_write
always @(posedge ACLK) begin
    if (ARESET)
        int_B_2_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_B_2_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_B_2_HIGH)
            int_B_2_write <= 1'b1;
        else if (w_hs)
            int_B_2_write <= 1'b0;
    end
end

// int_B_3_read
always @(posedge ACLK) begin
    if (ARESET)
        int_B_3_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_B_3_BASE && raddr <= ADDR_B_3_HIGH)
            int_B_3_read <= 1'b1;
        else
            int_B_3_read <= 1'b0;
    end
end

// int_B_3_write
always @(posedge ACLK) begin
    if (ARESET)
        int_B_3_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_B_3_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_B_3_HIGH)
            int_B_3_write <= 1'b1;
        else if (w_hs)
            int_B_3_write <= 1'b0;
    end
end

// int_B_4_read
always @(posedge ACLK) begin
    if (ARESET)
        int_B_4_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_B_4_BASE && raddr <= ADDR_B_4_HIGH)
            int_B_4_read <= 1'b1;
        else
            int_B_4_read <= 1'b0;
    end
end

// int_B_4_write
always @(posedge ACLK) begin
    if (ARESET)
        int_B_4_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_B_4_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_B_4_HIGH)
            int_B_4_write <= 1'b1;
        else if (w_hs)
            int_B_4_write <= 1'b0;
    end
end

// int_B_5_read
always @(posedge ACLK) begin
    if (ARESET)
        int_B_5_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_B_5_BASE && raddr <= ADDR_B_5_HIGH)
            int_B_5_read <= 1'b1;
        else
            int_B_5_read <= 1'b0;
    end
end

// int_B_5_write
always @(posedge ACLK) begin
    if (ARESET)
        int_B_5_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_B_5_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_B_5_HIGH)
            int_B_5_write <= 1'b1;
        else if (w_hs)
            int_B_5_write <= 1'b0;
    end
end

// int_B_6_read
always @(posedge ACLK) begin
    if (ARESET)
        int_B_6_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_B_6_BASE && raddr <= ADDR_B_6_HIGH)
            int_B_6_read <= 1'b1;
        else
            int_B_6_read <= 1'b0;
    end
end

// int_B_6_write
always @(posedge ACLK) begin
    if (ARESET)
        int_B_6_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_B_6_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_B_6_HIGH)
            int_B_6_write <= 1'b1;
        else if (w_hs)
            int_B_6_write <= 1'b0;
    end
end

// int_B_7_read
always @(posedge ACLK) begin
    if (ARESET)
        int_B_7_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_B_7_BASE && raddr <= ADDR_B_7_HIGH)
            int_B_7_read <= 1'b1;
        else
            int_B_7_read <= 1'b0;
    end
end

// int_B_7_write
always @(posedge ACLK) begin
    if (ARESET)
        int_B_7_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_B_7_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_B_7_HIGH)
            int_B_7_write <= 1'b1;
        else if (w_hs)
            int_B_7_write <= 1'b0;
    end
end

// int_B_8_read
always @(posedge ACLK) begin
    if (ARESET)
        int_B_8_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_B_8_BASE && raddr <= ADDR_B_8_HIGH)
            int_B_8_read <= 1'b1;
        else
            int_B_8_read <= 1'b0;
    end
end

// int_B_8_write
always @(posedge ACLK) begin
    if (ARESET)
        int_B_8_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_B_8_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_B_8_HIGH)
            int_B_8_write <= 1'b1;
        else if (w_hs)
            int_B_8_write <= 1'b0;
    end
end

// int_B_9_read
always @(posedge ACLK) begin
    if (ARESET)
        int_B_9_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_B_9_BASE && raddr <= ADDR_B_9_HIGH)
            int_B_9_read <= 1'b1;
        else
            int_B_9_read <= 1'b0;
    end
end

// int_B_9_write
always @(posedge ACLK) begin
    if (ARESET)
        int_B_9_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_B_9_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_B_9_HIGH)
            int_B_9_write <= 1'b1;
        else if (w_hs)
            int_B_9_write <= 1'b0;
    end
end

// int_B_10_read
always @(posedge ACLK) begin
    if (ARESET)
        int_B_10_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_B_10_BASE && raddr <= ADDR_B_10_HIGH)
            int_B_10_read <= 1'b1;
        else
            int_B_10_read <= 1'b0;
    end
end

// int_B_10_write
always @(posedge ACLK) begin
    if (ARESET)
        int_B_10_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_B_10_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_B_10_HIGH)
            int_B_10_write <= 1'b1;
        else if (w_hs)
            int_B_10_write <= 1'b0;
    end
end

// int_B_11_read
always @(posedge ACLK) begin
    if (ARESET)
        int_B_11_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_B_11_BASE && raddr <= ADDR_B_11_HIGH)
            int_B_11_read <= 1'b1;
        else
            int_B_11_read <= 1'b0;
    end
end

// int_B_11_write
always @(posedge ACLK) begin
    if (ARESET)
        int_B_11_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_B_11_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_B_11_HIGH)
            int_B_11_write <= 1'b1;
        else if (w_hs)
            int_B_11_write <= 1'b0;
    end
end

// int_B_12_read
always @(posedge ACLK) begin
    if (ARESET)
        int_B_12_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_B_12_BASE && raddr <= ADDR_B_12_HIGH)
            int_B_12_read <= 1'b1;
        else
            int_B_12_read <= 1'b0;
    end
end

// int_B_12_write
always @(posedge ACLK) begin
    if (ARESET)
        int_B_12_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_B_12_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_B_12_HIGH)
            int_B_12_write <= 1'b1;
        else if (w_hs)
            int_B_12_write <= 1'b0;
    end
end

// int_B_13_read
always @(posedge ACLK) begin
    if (ARESET)
        int_B_13_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_B_13_BASE && raddr <= ADDR_B_13_HIGH)
            int_B_13_read <= 1'b1;
        else
            int_B_13_read <= 1'b0;
    end
end

// int_B_13_write
always @(posedge ACLK) begin
    if (ARESET)
        int_B_13_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_B_13_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_B_13_HIGH)
            int_B_13_write <= 1'b1;
        else if (w_hs)
            int_B_13_write <= 1'b0;
    end
end

// int_B_14_read
always @(posedge ACLK) begin
    if (ARESET)
        int_B_14_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_B_14_BASE && raddr <= ADDR_B_14_HIGH)
            int_B_14_read <= 1'b1;
        else
            int_B_14_read <= 1'b0;
    end
end

// int_B_14_write
always @(posedge ACLK) begin
    if (ARESET)
        int_B_14_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_B_14_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_B_14_HIGH)
            int_B_14_write <= 1'b1;
        else if (w_hs)
            int_B_14_write <= 1'b0;
    end
end

// int_B_15_read
always @(posedge ACLK) begin
    if (ARESET)
        int_B_15_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_B_15_BASE && raddr <= ADDR_B_15_HIGH)
            int_B_15_read <= 1'b1;
        else
            int_B_15_read <= 1'b0;
    end
end

// int_B_15_write
always @(posedge ACLK) begin
    if (ARESET)
        int_B_15_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_B_15_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_B_15_HIGH)
            int_B_15_write <= 1'b1;
        else if (w_hs)
            int_B_15_write <= 1'b0;
    end
end

// int_C_read
always @(posedge ACLK) begin
    if (ARESET)
        int_C_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_C_BASE && raddr <= ADDR_C_HIGH)
            int_C_read <= 1'b1;
        else
            int_C_read <= 1'b0;
    end
end


endmodule


`timescale 1ns/1ps

module matrix_mult_hw_control_s_axi_ram
#(parameter
    MEM_STYLE  = "auto",
    MEM_TYPE   = "S2P",
    BYTE_WIDTH = 8,
    WIDTH  = 32,
    DEPTH  = 256,
    BYTES  = 4,
    AWIDTH = log2(DEPTH)
) (
    input  wire              clk0,
    input  wire [AWIDTH-1:0] address0,
    input  wire              ce0,
    input  wire [BYTES-1:0]  we0,
    input  wire [WIDTH-1:0]  d0,
    output reg  [WIDTH-1:0]  q0,
    input  wire              clk1,
    input  wire [AWIDTH-1:0] address1,
    input  wire              ce1,
    input  wire [BYTES-1:0]  we1,
    input  wire [WIDTH-1:0]  d1,
    output reg  [WIDTH-1:0]  q1
);
//------------------------ Parameters -------------------
localparam
    PORT0 = (MEM_TYPE == "S2P") ? "WO" : ((MEM_TYPE == "2P") ? "RO" : "RW"),
    PORT1 = (MEM_TYPE == "S2P") ? "RO" : "RW";
//------------------------Local signal-------------------
(* ram_style = MEM_STYLE*)
reg  [WIDTH-1:0] mem[0:DEPTH-1];
wire re0, re1;
//------------------------Task and function--------------
function integer log2;
    input integer x;
    integer n, m;
begin
    n = 1;
    m = 2;
    while (m < x) begin
        n = n + 1;
        m = m * 2;
    end
    log2 = n;
end
endfunction
//------------------------Body---------------------------
generate
    if (MEM_STYLE == "hls_ultra" && PORT0 == "RW") begin
        assign re0 = ce0 & ~|we0;
    end else begin
        assign re0 = ce0;
    end
endgenerate

generate
    if (MEM_STYLE == "hls_ultra" && PORT1 == "RW") begin
        assign re1 = ce1 & ~|we1;
    end else begin
        assign re1 = ce1;
    end
endgenerate

// read port 0
generate if (PORT0 != "WO") begin
    always @(posedge clk0) begin
        if (re0) q0 <= mem[address0];
    end
end
endgenerate

// read port 1
generate if (PORT1 != "WO") begin
    always @(posedge clk1) begin
        if (re1) q1 <= mem[address1];
    end
end
endgenerate

integer i;
// write port 0
generate if (PORT0 != "RO") begin
    always @(posedge clk0) begin
        if (ce0)
        for (i = 0; i < BYTES; i = i + 1)
            if (we0[i])
                mem[address0][i*BYTE_WIDTH +: BYTE_WIDTH] <= d0[i*BYTE_WIDTH +: BYTE_WIDTH];
    end
end
endgenerate

// write port 1
generate if (PORT1 != "RO") begin
    always @(posedge clk1) begin
        if (ce1)
        for (i = 0; i < BYTES; i = i + 1)
            if (we1[i])
                mem[address1][i*BYTE_WIDTH +: BYTE_WIDTH] <= d1[i*BYTE_WIDTH +: BYTE_WIDTH];
    end
end
endgenerate

endmodule

