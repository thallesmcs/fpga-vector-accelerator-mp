// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2025.1 (64-bit)
// Tool Version Limit: 2025.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef XARRAY_SUMMER_H
#define XARRAY_SUMMER_H

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
#include "xarray_summer_hw.h"

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
} XArray_summer_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XArray_summer;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XArray_summer_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XArray_summer_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XArray_summer_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XArray_summer_ReadReg(BaseAddress, RegOffset) \
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
int XArray_summer_Initialize(XArray_summer *InstancePtr, UINTPTR BaseAddress);
XArray_summer_Config* XArray_summer_LookupConfig(UINTPTR BaseAddress);
#else
int XArray_summer_Initialize(XArray_summer *InstancePtr, u16 DeviceId);
XArray_summer_Config* XArray_summer_LookupConfig(u16 DeviceId);
#endif
int XArray_summer_CfgInitialize(XArray_summer *InstancePtr, XArray_summer_Config *ConfigPtr);
#else
int XArray_summer_Initialize(XArray_summer *InstancePtr, const char* InstanceName);
int XArray_summer_Release(XArray_summer *InstancePtr);
#endif

void XArray_summer_Start(XArray_summer *InstancePtr);
u32 XArray_summer_IsDone(XArray_summer *InstancePtr);
u32 XArray_summer_IsIdle(XArray_summer *InstancePtr);
u32 XArray_summer_IsReady(XArray_summer *InstancePtr);
void XArray_summer_EnableAutoRestart(XArray_summer *InstancePtr);
void XArray_summer_DisableAutoRestart(XArray_summer *InstancePtr);

void XArray_summer_Set_input_array(XArray_summer *InstancePtr, u64 Data);
u64 XArray_summer_Get_input_array(XArray_summer *InstancePtr);
void XArray_summer_Set_size(XArray_summer *InstancePtr, u32 Data);
u32 XArray_summer_Get_size(XArray_summer *InstancePtr);
u32 XArray_summer_Get_sum_result(XArray_summer *InstancePtr);
u32 XArray_summer_Get_sum_result_vld(XArray_summer *InstancePtr);

void XArray_summer_InterruptGlobalEnable(XArray_summer *InstancePtr);
void XArray_summer_InterruptGlobalDisable(XArray_summer *InstancePtr);
void XArray_summer_InterruptEnable(XArray_summer *InstancePtr, u32 Mask);
void XArray_summer_InterruptDisable(XArray_summer *InstancePtr, u32 Mask);
void XArray_summer_InterruptClear(XArray_summer *InstancePtr, u32 Mask);
u32 XArray_summer_InterruptGetEnabled(XArray_summer *InstancePtr);
u32 XArray_summer_InterruptGetStatus(XArray_summer *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
