// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.2 (64-bit)
// Tool Version Limit: 2024.11
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef XADDER_NEW_H
#define XADDER_NEW_H

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
#include "xadder_new_hw.h"

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
    u64 Bus_a_BaseAddress;
} XAdder_new_Config;
#endif

typedef struct {
    u64 Bus_a_BaseAddress;
    u32 IsReady;
} XAdder_new;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XAdder_new_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XAdder_new_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XAdder_new_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XAdder_new_ReadReg(BaseAddress, RegOffset) \
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
int XAdder_new_Initialize(XAdder_new *InstancePtr, UINTPTR BaseAddress);
XAdder_new_Config* XAdder_new_LookupConfig(UINTPTR BaseAddress);
#else
int XAdder_new_Initialize(XAdder_new *InstancePtr, u16 DeviceId);
XAdder_new_Config* XAdder_new_LookupConfig(u16 DeviceId);
#endif
int XAdder_new_CfgInitialize(XAdder_new *InstancePtr, XAdder_new_Config *ConfigPtr);
#else
int XAdder_new_Initialize(XAdder_new *InstancePtr, const char* InstanceName);
int XAdder_new_Release(XAdder_new *InstancePtr);
#endif

void XAdder_new_Start(XAdder_new *InstancePtr);
u32 XAdder_new_IsDone(XAdder_new *InstancePtr);
u32 XAdder_new_IsIdle(XAdder_new *InstancePtr);
u32 XAdder_new_IsReady(XAdder_new *InstancePtr);
void XAdder_new_EnableAutoRestart(XAdder_new *InstancePtr);
void XAdder_new_DisableAutoRestart(XAdder_new *InstancePtr);

void XAdder_new_Set_a(XAdder_new *InstancePtr, u32 Data);
u32 XAdder_new_Get_a(XAdder_new *InstancePtr);
void XAdder_new_Set_b(XAdder_new *InstancePtr, u32 Data);
u32 XAdder_new_Get_b(XAdder_new *InstancePtr);
void XAdder_new_Set_c_i(XAdder_new *InstancePtr, u32 Data);
u32 XAdder_new_Get_c_i(XAdder_new *InstancePtr);
u32 XAdder_new_Get_c_o(XAdder_new *InstancePtr);
u32 XAdder_new_Get_c_o_vld(XAdder_new *InstancePtr);

void XAdder_new_InterruptGlobalEnable(XAdder_new *InstancePtr);
void XAdder_new_InterruptGlobalDisable(XAdder_new *InstancePtr);
void XAdder_new_InterruptEnable(XAdder_new *InstancePtr, u32 Mask);
void XAdder_new_InterruptDisable(XAdder_new *InstancePtr, u32 Mask);
void XAdder_new_InterruptClear(XAdder_new *InstancePtr, u32 Mask);
u32 XAdder_new_InterruptGetEnabled(XAdder_new *InstancePtr);
u32 XAdder_new_InterruptGetStatus(XAdder_new *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
