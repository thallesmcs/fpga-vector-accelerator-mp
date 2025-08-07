// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2025.1 (64-bit)
// Tool Version Limit: 2025.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef XMULT_HW_200_H
#define XMULT_HW_200_H

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
#include "xmult_hw_200_hw.h"

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
} XMult_hw_200_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XMult_hw_200;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XMult_hw_200_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XMult_hw_200_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XMult_hw_200_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XMult_hw_200_ReadReg(BaseAddress, RegOffset) \
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
int XMult_hw_200_Initialize(XMult_hw_200 *InstancePtr, UINTPTR BaseAddress);
XMult_hw_200_Config* XMult_hw_200_LookupConfig(UINTPTR BaseAddress);
#else
int XMult_hw_200_Initialize(XMult_hw_200 *InstancePtr, u16 DeviceId);
XMult_hw_200_Config* XMult_hw_200_LookupConfig(u16 DeviceId);
#endif
int XMult_hw_200_CfgInitialize(XMult_hw_200 *InstancePtr, XMult_hw_200_Config *ConfigPtr);
#else
int XMult_hw_200_Initialize(XMult_hw_200 *InstancePtr, const char* InstanceName);
int XMult_hw_200_Release(XMult_hw_200 *InstancePtr);
#endif

void XMult_hw_200_Start(XMult_hw_200 *InstancePtr);
u32 XMult_hw_200_IsDone(XMult_hw_200 *InstancePtr);
u32 XMult_hw_200_IsIdle(XMult_hw_200 *InstancePtr);
u32 XMult_hw_200_IsReady(XMult_hw_200 *InstancePtr);
void XMult_hw_200_EnableAutoRestart(XMult_hw_200 *InstancePtr);
void XMult_hw_200_DisableAutoRestart(XMult_hw_200 *InstancePtr);

u32 XMult_hw_200_Get_A_BaseAddress(XMult_hw_200 *InstancePtr);
u32 XMult_hw_200_Get_A_HighAddress(XMult_hw_200 *InstancePtr);
u32 XMult_hw_200_Get_A_TotalBytes(XMult_hw_200 *InstancePtr);
u32 XMult_hw_200_Get_A_BitWidth(XMult_hw_200 *InstancePtr);
u32 XMult_hw_200_Get_A_Depth(XMult_hw_200 *InstancePtr);
u32 XMult_hw_200_Write_A_Words(XMult_hw_200 *InstancePtr, int offset, word_type *data, int length);
u32 XMult_hw_200_Read_A_Words(XMult_hw_200 *InstancePtr, int offset, word_type *data, int length);
u32 XMult_hw_200_Write_A_Bytes(XMult_hw_200 *InstancePtr, int offset, char *data, int length);
u32 XMult_hw_200_Read_A_Bytes(XMult_hw_200 *InstancePtr, int offset, char *data, int length);
u32 XMult_hw_200_Get_B_BaseAddress(XMult_hw_200 *InstancePtr);
u32 XMult_hw_200_Get_B_HighAddress(XMult_hw_200 *InstancePtr);
u32 XMult_hw_200_Get_B_TotalBytes(XMult_hw_200 *InstancePtr);
u32 XMult_hw_200_Get_B_BitWidth(XMult_hw_200 *InstancePtr);
u32 XMult_hw_200_Get_B_Depth(XMult_hw_200 *InstancePtr);
u32 XMult_hw_200_Write_B_Words(XMult_hw_200 *InstancePtr, int offset, word_type *data, int length);
u32 XMult_hw_200_Read_B_Words(XMult_hw_200 *InstancePtr, int offset, word_type *data, int length);
u32 XMult_hw_200_Write_B_Bytes(XMult_hw_200 *InstancePtr, int offset, char *data, int length);
u32 XMult_hw_200_Read_B_Bytes(XMult_hw_200 *InstancePtr, int offset, char *data, int length);
u32 XMult_hw_200_Get_C_BaseAddress(XMult_hw_200 *InstancePtr);
u32 XMult_hw_200_Get_C_HighAddress(XMult_hw_200 *InstancePtr);
u32 XMult_hw_200_Get_C_TotalBytes(XMult_hw_200 *InstancePtr);
u32 XMult_hw_200_Get_C_BitWidth(XMult_hw_200 *InstancePtr);
u32 XMult_hw_200_Get_C_Depth(XMult_hw_200 *InstancePtr);
u32 XMult_hw_200_Write_C_Words(XMult_hw_200 *InstancePtr, int offset, word_type *data, int length);
u32 XMult_hw_200_Read_C_Words(XMult_hw_200 *InstancePtr, int offset, word_type *data, int length);
u32 XMult_hw_200_Write_C_Bytes(XMult_hw_200 *InstancePtr, int offset, char *data, int length);
u32 XMult_hw_200_Read_C_Bytes(XMult_hw_200 *InstancePtr, int offset, char *data, int length);

void XMult_hw_200_InterruptGlobalEnable(XMult_hw_200 *InstancePtr);
void XMult_hw_200_InterruptGlobalDisable(XMult_hw_200 *InstancePtr);
void XMult_hw_200_InterruptEnable(XMult_hw_200 *InstancePtr, u32 Mask);
void XMult_hw_200_InterruptDisable(XMult_hw_200 *InstancePtr, u32 Mask);
void XMult_hw_200_InterruptClear(XMult_hw_200 *InstancePtr, u32 Mask);
u32 XMult_hw_200_InterruptGetEnabled(XMult_hw_200 *InstancePtr);
u32 XMult_hw_200_InterruptGetStatus(XMult_hw_200 *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
