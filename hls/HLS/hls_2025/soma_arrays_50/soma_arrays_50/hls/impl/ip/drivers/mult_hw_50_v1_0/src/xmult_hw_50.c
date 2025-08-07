// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2025.1 (64-bit)
// Tool Version Limit: 2025.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
/***************************** Include Files *********************************/
#include "xmult_hw_50.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XMult_hw_50_CfgInitialize(XMult_hw_50 *InstancePtr, XMult_hw_50_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XMult_hw_50_Start(XMult_hw_50 *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMult_hw_50_ReadReg(InstancePtr->Control_BaseAddress, XMULT_HW_50_CONTROL_ADDR_AP_CTRL) & 0x80;
    XMult_hw_50_WriteReg(InstancePtr->Control_BaseAddress, XMULT_HW_50_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XMult_hw_50_IsDone(XMult_hw_50 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMult_hw_50_ReadReg(InstancePtr->Control_BaseAddress, XMULT_HW_50_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XMult_hw_50_IsIdle(XMult_hw_50 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMult_hw_50_ReadReg(InstancePtr->Control_BaseAddress, XMULT_HW_50_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XMult_hw_50_IsReady(XMult_hw_50 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMult_hw_50_ReadReg(InstancePtr->Control_BaseAddress, XMULT_HW_50_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XMult_hw_50_EnableAutoRestart(XMult_hw_50 *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMult_hw_50_WriteReg(InstancePtr->Control_BaseAddress, XMULT_HW_50_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XMult_hw_50_DisableAutoRestart(XMult_hw_50 *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMult_hw_50_WriteReg(InstancePtr->Control_BaseAddress, XMULT_HW_50_CONTROL_ADDR_AP_CTRL, 0);
}

u32 XMult_hw_50_Get_A_BaseAddress(XMult_hw_50 *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMULT_HW_50_CONTROL_ADDR_A_BASE);
}

u32 XMult_hw_50_Get_A_HighAddress(XMult_hw_50 *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMULT_HW_50_CONTROL_ADDR_A_HIGH);
}

u32 XMult_hw_50_Get_A_TotalBytes(XMult_hw_50 *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMULT_HW_50_CONTROL_ADDR_A_HIGH - XMULT_HW_50_CONTROL_ADDR_A_BASE + 1);
}

u32 XMult_hw_50_Get_A_BitWidth(XMult_hw_50 *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMULT_HW_50_CONTROL_WIDTH_A;
}

u32 XMult_hw_50_Get_A_Depth(XMult_hw_50 *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMULT_HW_50_CONTROL_DEPTH_A;
}

u32 XMult_hw_50_Write_A_Words(XMult_hw_50 *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMULT_HW_50_CONTROL_ADDR_A_HIGH - XMULT_HW_50_CONTROL_ADDR_A_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMULT_HW_50_CONTROL_ADDR_A_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMult_hw_50_Read_A_Words(XMult_hw_50 *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMULT_HW_50_CONTROL_ADDR_A_HIGH - XMULT_HW_50_CONTROL_ADDR_A_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMULT_HW_50_CONTROL_ADDR_A_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMult_hw_50_Write_A_Bytes(XMult_hw_50 *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMULT_HW_50_CONTROL_ADDR_A_HIGH - XMULT_HW_50_CONTROL_ADDR_A_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMULT_HW_50_CONTROL_ADDR_A_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMult_hw_50_Read_A_Bytes(XMult_hw_50 *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMULT_HW_50_CONTROL_ADDR_A_HIGH - XMULT_HW_50_CONTROL_ADDR_A_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMULT_HW_50_CONTROL_ADDR_A_BASE + offset + i);
    }
    return length;
}

u32 XMult_hw_50_Get_B_BaseAddress(XMult_hw_50 *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMULT_HW_50_CONTROL_ADDR_B_BASE);
}

u32 XMult_hw_50_Get_B_HighAddress(XMult_hw_50 *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMULT_HW_50_CONTROL_ADDR_B_HIGH);
}

u32 XMult_hw_50_Get_B_TotalBytes(XMult_hw_50 *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMULT_HW_50_CONTROL_ADDR_B_HIGH - XMULT_HW_50_CONTROL_ADDR_B_BASE + 1);
}

u32 XMult_hw_50_Get_B_BitWidth(XMult_hw_50 *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMULT_HW_50_CONTROL_WIDTH_B;
}

u32 XMult_hw_50_Get_B_Depth(XMult_hw_50 *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMULT_HW_50_CONTROL_DEPTH_B;
}

u32 XMult_hw_50_Write_B_Words(XMult_hw_50 *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMULT_HW_50_CONTROL_ADDR_B_HIGH - XMULT_HW_50_CONTROL_ADDR_B_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMULT_HW_50_CONTROL_ADDR_B_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMult_hw_50_Read_B_Words(XMult_hw_50 *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMULT_HW_50_CONTROL_ADDR_B_HIGH - XMULT_HW_50_CONTROL_ADDR_B_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMULT_HW_50_CONTROL_ADDR_B_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMult_hw_50_Write_B_Bytes(XMult_hw_50 *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMULT_HW_50_CONTROL_ADDR_B_HIGH - XMULT_HW_50_CONTROL_ADDR_B_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMULT_HW_50_CONTROL_ADDR_B_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMult_hw_50_Read_B_Bytes(XMult_hw_50 *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMULT_HW_50_CONTROL_ADDR_B_HIGH - XMULT_HW_50_CONTROL_ADDR_B_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMULT_HW_50_CONTROL_ADDR_B_BASE + offset + i);
    }
    return length;
}

u32 XMult_hw_50_Get_C_BaseAddress(XMult_hw_50 *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMULT_HW_50_CONTROL_ADDR_C_BASE);
}

u32 XMult_hw_50_Get_C_HighAddress(XMult_hw_50 *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMULT_HW_50_CONTROL_ADDR_C_HIGH);
}

u32 XMult_hw_50_Get_C_TotalBytes(XMult_hw_50 *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMULT_HW_50_CONTROL_ADDR_C_HIGH - XMULT_HW_50_CONTROL_ADDR_C_BASE + 1);
}

u32 XMult_hw_50_Get_C_BitWidth(XMult_hw_50 *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMULT_HW_50_CONTROL_WIDTH_C;
}

u32 XMult_hw_50_Get_C_Depth(XMult_hw_50 *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMULT_HW_50_CONTROL_DEPTH_C;
}

u32 XMult_hw_50_Write_C_Words(XMult_hw_50 *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMULT_HW_50_CONTROL_ADDR_C_HIGH - XMULT_HW_50_CONTROL_ADDR_C_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMULT_HW_50_CONTROL_ADDR_C_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMult_hw_50_Read_C_Words(XMult_hw_50 *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMULT_HW_50_CONTROL_ADDR_C_HIGH - XMULT_HW_50_CONTROL_ADDR_C_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMULT_HW_50_CONTROL_ADDR_C_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMult_hw_50_Write_C_Bytes(XMult_hw_50 *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMULT_HW_50_CONTROL_ADDR_C_HIGH - XMULT_HW_50_CONTROL_ADDR_C_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMULT_HW_50_CONTROL_ADDR_C_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMult_hw_50_Read_C_Bytes(XMult_hw_50 *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMULT_HW_50_CONTROL_ADDR_C_HIGH - XMULT_HW_50_CONTROL_ADDR_C_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMULT_HW_50_CONTROL_ADDR_C_BASE + offset + i);
    }
    return length;
}

void XMult_hw_50_InterruptGlobalEnable(XMult_hw_50 *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMult_hw_50_WriteReg(InstancePtr->Control_BaseAddress, XMULT_HW_50_CONTROL_ADDR_GIE, 1);
}

void XMult_hw_50_InterruptGlobalDisable(XMult_hw_50 *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMult_hw_50_WriteReg(InstancePtr->Control_BaseAddress, XMULT_HW_50_CONTROL_ADDR_GIE, 0);
}

void XMult_hw_50_InterruptEnable(XMult_hw_50 *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMult_hw_50_ReadReg(InstancePtr->Control_BaseAddress, XMULT_HW_50_CONTROL_ADDR_IER);
    XMult_hw_50_WriteReg(InstancePtr->Control_BaseAddress, XMULT_HW_50_CONTROL_ADDR_IER, Register | Mask);
}

void XMult_hw_50_InterruptDisable(XMult_hw_50 *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMult_hw_50_ReadReg(InstancePtr->Control_BaseAddress, XMULT_HW_50_CONTROL_ADDR_IER);
    XMult_hw_50_WriteReg(InstancePtr->Control_BaseAddress, XMULT_HW_50_CONTROL_ADDR_IER, Register & (~Mask));
}

void XMult_hw_50_InterruptClear(XMult_hw_50 *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMult_hw_50_WriteReg(InstancePtr->Control_BaseAddress, XMULT_HW_50_CONTROL_ADDR_ISR, Mask);
}

u32 XMult_hw_50_InterruptGetEnabled(XMult_hw_50 *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMult_hw_50_ReadReg(InstancePtr->Control_BaseAddress, XMULT_HW_50_CONTROL_ADDR_IER);
}

u32 XMult_hw_50_InterruptGetStatus(XMult_hw_50 *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMult_hw_50_ReadReg(InstancePtr->Control_BaseAddress, XMULT_HW_50_CONTROL_ADDR_ISR);
}

