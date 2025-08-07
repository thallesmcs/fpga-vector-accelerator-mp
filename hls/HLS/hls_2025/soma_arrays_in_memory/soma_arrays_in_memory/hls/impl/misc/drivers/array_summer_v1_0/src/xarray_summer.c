// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2025.1 (64-bit)
// Tool Version Limit: 2025.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
/***************************** Include Files *********************************/
#include "xarray_summer.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XArray_summer_CfgInitialize(XArray_summer *InstancePtr, XArray_summer_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XArray_summer_Start(XArray_summer *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XArray_summer_ReadReg(InstancePtr->Control_BaseAddress, XARRAY_SUMMER_CONTROL_ADDR_AP_CTRL) & 0x80;
    XArray_summer_WriteReg(InstancePtr->Control_BaseAddress, XARRAY_SUMMER_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XArray_summer_IsDone(XArray_summer *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XArray_summer_ReadReg(InstancePtr->Control_BaseAddress, XARRAY_SUMMER_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XArray_summer_IsIdle(XArray_summer *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XArray_summer_ReadReg(InstancePtr->Control_BaseAddress, XARRAY_SUMMER_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XArray_summer_IsReady(XArray_summer *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XArray_summer_ReadReg(InstancePtr->Control_BaseAddress, XARRAY_SUMMER_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XArray_summer_EnableAutoRestart(XArray_summer *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XArray_summer_WriteReg(InstancePtr->Control_BaseAddress, XARRAY_SUMMER_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XArray_summer_DisableAutoRestart(XArray_summer *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XArray_summer_WriteReg(InstancePtr->Control_BaseAddress, XARRAY_SUMMER_CONTROL_ADDR_AP_CTRL, 0);
}

void XArray_summer_Set_input_array(XArray_summer *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XArray_summer_WriteReg(InstancePtr->Control_BaseAddress, XARRAY_SUMMER_CONTROL_ADDR_INPUT_ARRAY_DATA, (u32)(Data));
    XArray_summer_WriteReg(InstancePtr->Control_BaseAddress, XARRAY_SUMMER_CONTROL_ADDR_INPUT_ARRAY_DATA + 4, (u32)(Data >> 32));
}

u64 XArray_summer_Get_input_array(XArray_summer *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XArray_summer_ReadReg(InstancePtr->Control_BaseAddress, XARRAY_SUMMER_CONTROL_ADDR_INPUT_ARRAY_DATA);
    Data += (u64)XArray_summer_ReadReg(InstancePtr->Control_BaseAddress, XARRAY_SUMMER_CONTROL_ADDR_INPUT_ARRAY_DATA + 4) << 32;
    return Data;
}

void XArray_summer_Set_size(XArray_summer *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XArray_summer_WriteReg(InstancePtr->Control_BaseAddress, XARRAY_SUMMER_CONTROL_ADDR_SIZE_DATA, Data);
}

u32 XArray_summer_Get_size(XArray_summer *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XArray_summer_ReadReg(InstancePtr->Control_BaseAddress, XARRAY_SUMMER_CONTROL_ADDR_SIZE_DATA);
    return Data;
}

u32 XArray_summer_Get_sum_result(XArray_summer *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XArray_summer_ReadReg(InstancePtr->Control_BaseAddress, XARRAY_SUMMER_CONTROL_ADDR_SUM_RESULT_DATA);
    return Data;
}

u32 XArray_summer_Get_sum_result_vld(XArray_summer *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XArray_summer_ReadReg(InstancePtr->Control_BaseAddress, XARRAY_SUMMER_CONTROL_ADDR_SUM_RESULT_CTRL);
    return Data & 0x1;
}

void XArray_summer_InterruptGlobalEnable(XArray_summer *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XArray_summer_WriteReg(InstancePtr->Control_BaseAddress, XARRAY_SUMMER_CONTROL_ADDR_GIE, 1);
}

void XArray_summer_InterruptGlobalDisable(XArray_summer *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XArray_summer_WriteReg(InstancePtr->Control_BaseAddress, XARRAY_SUMMER_CONTROL_ADDR_GIE, 0);
}

void XArray_summer_InterruptEnable(XArray_summer *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XArray_summer_ReadReg(InstancePtr->Control_BaseAddress, XARRAY_SUMMER_CONTROL_ADDR_IER);
    XArray_summer_WriteReg(InstancePtr->Control_BaseAddress, XARRAY_SUMMER_CONTROL_ADDR_IER, Register | Mask);
}

void XArray_summer_InterruptDisable(XArray_summer *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XArray_summer_ReadReg(InstancePtr->Control_BaseAddress, XARRAY_SUMMER_CONTROL_ADDR_IER);
    XArray_summer_WriteReg(InstancePtr->Control_BaseAddress, XARRAY_SUMMER_CONTROL_ADDR_IER, Register & (~Mask));
}

void XArray_summer_InterruptClear(XArray_summer *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XArray_summer_WriteReg(InstancePtr->Control_BaseAddress, XARRAY_SUMMER_CONTROL_ADDR_ISR, Mask);
}

u32 XArray_summer_InterruptGetEnabled(XArray_summer *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XArray_summer_ReadReg(InstancePtr->Control_BaseAddress, XARRAY_SUMMER_CONTROL_ADDR_IER);
}

u32 XArray_summer_InterruptGetStatus(XArray_summer *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XArray_summer_ReadReg(InstancePtr->Control_BaseAddress, XARRAY_SUMMER_CONTROL_ADDR_ISR);
}

