# ==============================================================
# Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2025.1 (64-bit)
# Tool Version Limit: 2025.05
# Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
# Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
# 
# ==============================================================
#
# Settings for Vivado implementation flow
#
set top_module mult_hw_1000
set language verilog
set family spartan7
set device xc7s50
set package -csga324
set speed -1
set clock ap_clk
set fsm_ext "off"

# For customizing the implementation flow
set add_io_buffers false ;# true|false
