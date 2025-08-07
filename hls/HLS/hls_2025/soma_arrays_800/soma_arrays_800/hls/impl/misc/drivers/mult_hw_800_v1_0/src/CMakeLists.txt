# ==============================================================
# Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2025.1 (64-bit)
# Tool Version Limit: 2025.05
# Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
# Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
# 
# ==============================================================
cmake_minimum_required(VERSION 3.15)
project(mult_hw_800)
find_package(common)
collector_create (PROJECT_LIB_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}")
collect (PROJECT_LIB_SOURCES xmult_hw_800.c)
collect (PROJECT_LIB_SOURCES xmult_hw_800_sinit.c)
collect (PROJECT_LIB_SOURCES xmult_hw_800_linux.c)
collect (PROJECT_LIB_SOURCES xmult_hw_800_g.c)
collector_list (_sources PROJECT_LIB_SOURCES)
collector_create (PROJECT_LIB_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}")
collect (PROJECT_LIB_HEADERS xmult_hw_800.h)
collect (PROJECT_LIB_HEADERS xmult_hw_800_hw.h)
collector_list (_headers PROJECT_LIB_HEADERS)
file(COPY ${_headers} DESTINATION ${CMAKE_BINARY_DIR}/include)
include_directories(${CMAKE_BINARY_DIR}/include)
add_library(mult_hw_800 STATIC ${_sources})
set_target_properties(mult_hw_800 PROPERTIES LINKER_LANGUAGE C)

