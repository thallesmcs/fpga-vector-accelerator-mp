// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2025.1 (64-bit)
// Tool Version Limit: 2025.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef XMATRIX_MULT_HW_H
#define XMATRIX_MULT_HW_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xmatrix_mult_hw_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
#ifdef SDT
    char *Name;
#else
    u16 DeviceId;
#endif
    u64 Control_BaseAddress;
} XMatrix_mult_hw_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XMatrix_mult_hw;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XMatrix_mult_hw_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XMatrix_mult_hw_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XMatrix_mult_hw_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XMatrix_mult_hw_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
#ifdef SDT
int XMatrix_mult_hw_Initialize(XMatrix_mult_hw *InstancePtr, UINTPTR BaseAddress);
XMatrix_mult_hw_Config* XMatrix_mult_hw_LookupConfig(UINTPTR BaseAddress);
#else
int XMatrix_mult_hw_Initialize(XMatrix_mult_hw *InstancePtr, u16 DeviceId);
XMatrix_mult_hw_Config* XMatrix_mult_hw_LookupConfig(u16 DeviceId);
#endif
int XMatrix_mult_hw_CfgInitialize(XMatrix_mult_hw *InstancePtr, XMatrix_mult_hw_Config *ConfigPtr);
#else
int XMatrix_mult_hw_Initialize(XMatrix_mult_hw *InstancePtr, const char* InstanceName);
int XMatrix_mult_hw_Release(XMatrix_mult_hw *InstancePtr);
#endif

void XMatrix_mult_hw_Start(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_IsDone(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_IsIdle(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_IsReady(XMatrix_mult_hw *InstancePtr);
void XMatrix_mult_hw_EnableAutoRestart(XMatrix_mult_hw *InstancePtr);
void XMatrix_mult_hw_DisableAutoRestart(XMatrix_mult_hw *InstancePtr);

u32 XMatrix_mult_hw_Get_A_0_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_0_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_0_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_0_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_0_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_A_0_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_A_0_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_A_0_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_A_0_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_A_1_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_1_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_1_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_1_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_1_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_A_1_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_A_1_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_A_1_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_A_1_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_A_2_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_2_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_2_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_2_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_2_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_A_2_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_A_2_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_A_2_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_A_2_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_A_3_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_3_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_3_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_3_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_3_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_A_3_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_A_3_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_A_3_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_A_3_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_A_4_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_4_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_4_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_4_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_4_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_A_4_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_A_4_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_A_4_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_A_4_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_A_5_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_5_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_5_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_5_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_5_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_A_5_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_A_5_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_A_5_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_A_5_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_A_6_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_6_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_6_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_6_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_6_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_A_6_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_A_6_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_A_6_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_A_6_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_A_7_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_7_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_7_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_7_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_7_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_A_7_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_A_7_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_A_7_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_A_7_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_A_8_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_8_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_8_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_8_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_8_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_A_8_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_A_8_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_A_8_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_A_8_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_A_9_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_9_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_9_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_9_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_9_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_A_9_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_A_9_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_A_9_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_A_9_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_A_10_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_10_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_10_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_10_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_10_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_A_10_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_A_10_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_A_10_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_A_10_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_A_11_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_11_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_11_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_11_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_11_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_A_11_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_A_11_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_A_11_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_A_11_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_A_12_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_12_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_12_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_12_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_12_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_A_12_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_A_12_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_A_12_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_A_12_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_A_13_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_13_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_13_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_13_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_13_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_A_13_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_A_13_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_A_13_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_A_13_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_A_14_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_14_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_14_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_14_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_14_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_A_14_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_A_14_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_A_14_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_A_14_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_A_15_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_15_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_15_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_15_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_A_15_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_A_15_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_A_15_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_A_15_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_A_15_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_B_0_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_0_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_0_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_0_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_0_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_B_0_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_B_0_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_B_0_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_B_0_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_B_1_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_1_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_1_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_1_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_1_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_B_1_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_B_1_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_B_1_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_B_1_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_B_2_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_2_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_2_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_2_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_2_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_B_2_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_B_2_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_B_2_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_B_2_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_B_3_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_3_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_3_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_3_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_3_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_B_3_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_B_3_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_B_3_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_B_3_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_B_4_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_4_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_4_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_4_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_4_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_B_4_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_B_4_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_B_4_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_B_4_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_B_5_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_5_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_5_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_5_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_5_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_B_5_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_B_5_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_B_5_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_B_5_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_B_6_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_6_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_6_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_6_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_6_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_B_6_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_B_6_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_B_6_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_B_6_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_B_7_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_7_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_7_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_7_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_7_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_B_7_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_B_7_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_B_7_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_B_7_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_B_8_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_8_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_8_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_8_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_8_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_B_8_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_B_8_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_B_8_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_B_8_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_B_9_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_9_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_9_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_9_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_9_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_B_9_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_B_9_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_B_9_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_B_9_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_B_10_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_10_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_10_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_10_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_10_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_B_10_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_B_10_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_B_10_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_B_10_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_B_11_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_11_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_11_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_11_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_11_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_B_11_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_B_11_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_B_11_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_B_11_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_B_12_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_12_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_12_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_12_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_12_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_B_12_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_B_12_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_B_12_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_B_12_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_B_13_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_13_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_13_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_13_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_13_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_B_13_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_B_13_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_B_13_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_B_13_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_B_14_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_14_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_14_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_14_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_14_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_B_14_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_B_14_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_B_14_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_B_14_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_B_15_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_15_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_15_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_15_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_B_15_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_B_15_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_B_15_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_B_15_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_B_15_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Get_C_BaseAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_C_HighAddress(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_C_TotalBytes(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_C_BitWidth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Get_C_Depth(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_Write_C_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Read_C_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length);
u32 XMatrix_mult_hw_Write_C_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);
u32 XMatrix_mult_hw_Read_C_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length);

void XMatrix_mult_hw_InterruptGlobalEnable(XMatrix_mult_hw *InstancePtr);
void XMatrix_mult_hw_InterruptGlobalDisable(XMatrix_mult_hw *InstancePtr);
void XMatrix_mult_hw_InterruptEnable(XMatrix_mult_hw *InstancePtr, u32 Mask);
void XMatrix_mult_hw_InterruptDisable(XMatrix_mult_hw *InstancePtr, u32 Mask);
void XMatrix_mult_hw_InterruptClear(XMatrix_mult_hw *InstancePtr, u32 Mask);
u32 XMatrix_mult_hw_InterruptGetEnabled(XMatrix_mult_hw *InstancePtr);
u32 XMatrix_mult_hw_InterruptGetStatus(XMatrix_mult_hw *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
