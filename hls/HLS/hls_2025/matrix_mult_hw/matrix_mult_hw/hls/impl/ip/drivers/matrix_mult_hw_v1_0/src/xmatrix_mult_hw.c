// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2025.1 (64-bit)
// Tool Version Limit: 2025.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
/***************************** Include Files *********************************/
#include "xmatrix_mult_hw.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XMatrix_mult_hw_CfgInitialize(XMatrix_mult_hw *InstancePtr, XMatrix_mult_hw_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XMatrix_mult_hw_Start(XMatrix_mult_hw *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMatrix_mult_hw_ReadReg(InstancePtr->Control_BaseAddress, XMATRIX_MULT_HW_CONTROL_ADDR_AP_CTRL) & 0x80;
    XMatrix_mult_hw_WriteReg(InstancePtr->Control_BaseAddress, XMATRIX_MULT_HW_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XMatrix_mult_hw_IsDone(XMatrix_mult_hw *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMatrix_mult_hw_ReadReg(InstancePtr->Control_BaseAddress, XMATRIX_MULT_HW_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XMatrix_mult_hw_IsIdle(XMatrix_mult_hw *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMatrix_mult_hw_ReadReg(InstancePtr->Control_BaseAddress, XMATRIX_MULT_HW_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XMatrix_mult_hw_IsReady(XMatrix_mult_hw *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMatrix_mult_hw_ReadReg(InstancePtr->Control_BaseAddress, XMATRIX_MULT_HW_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XMatrix_mult_hw_EnableAutoRestart(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatrix_mult_hw_WriteReg(InstancePtr->Control_BaseAddress, XMATRIX_MULT_HW_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XMatrix_mult_hw_DisableAutoRestart(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatrix_mult_hw_WriteReg(InstancePtr->Control_BaseAddress, XMATRIX_MULT_HW_CONTROL_ADDR_AP_CTRL, 0);
}

u32 XMatrix_mult_hw_Get_A_0_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_0_BASE);
}

u32 XMatrix_mult_hw_Get_A_0_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_0_HIGH);
}

u32 XMatrix_mult_hw_Get_A_0_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_A_0_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_0_BASE + 1);
}

u32 XMatrix_mult_hw_Get_A_0_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_A_0;
}

u32 XMatrix_mult_hw_Get_A_0_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_A_0;
}

u32 XMatrix_mult_hw_Write_A_0_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_0_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_0_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_0_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_0_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_0_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_A_0_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_0_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_0_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_0_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_0_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_0_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_A_1_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_1_BASE);
}

u32 XMatrix_mult_hw_Get_A_1_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_1_HIGH);
}

u32 XMatrix_mult_hw_Get_A_1_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_A_1_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_1_BASE + 1);
}

u32 XMatrix_mult_hw_Get_A_1_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_A_1;
}

u32 XMatrix_mult_hw_Get_A_1_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_A_1;
}

u32 XMatrix_mult_hw_Write_A_1_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_1_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_1_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_1_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_1_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_1_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_A_1_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_1_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_1_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_1_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_1_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_1_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_A_2_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_2_BASE);
}

u32 XMatrix_mult_hw_Get_A_2_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_2_HIGH);
}

u32 XMatrix_mult_hw_Get_A_2_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_A_2_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_2_BASE + 1);
}

u32 XMatrix_mult_hw_Get_A_2_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_A_2;
}

u32 XMatrix_mult_hw_Get_A_2_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_A_2;
}

u32 XMatrix_mult_hw_Write_A_2_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_2_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_2_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_2_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_2_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_2_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_A_2_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_2_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_2_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_2_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_2_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_2_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_A_3_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_3_BASE);
}

u32 XMatrix_mult_hw_Get_A_3_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_3_HIGH);
}

u32 XMatrix_mult_hw_Get_A_3_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_A_3_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_3_BASE + 1);
}

u32 XMatrix_mult_hw_Get_A_3_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_A_3;
}

u32 XMatrix_mult_hw_Get_A_3_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_A_3;
}

u32 XMatrix_mult_hw_Write_A_3_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_3_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_3_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_3_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_3_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_3_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_A_3_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_3_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_3_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_3_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_3_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_3_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_A_4_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_4_BASE);
}

u32 XMatrix_mult_hw_Get_A_4_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_4_HIGH);
}

u32 XMatrix_mult_hw_Get_A_4_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_A_4_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_4_BASE + 1);
}

u32 XMatrix_mult_hw_Get_A_4_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_A_4;
}

u32 XMatrix_mult_hw_Get_A_4_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_A_4;
}

u32 XMatrix_mult_hw_Write_A_4_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_4_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_4_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_4_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_4_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_4_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_4_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_4_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_A_4_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_4_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_4_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_4_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_4_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_4_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_4_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_4_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_A_5_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_5_BASE);
}

u32 XMatrix_mult_hw_Get_A_5_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_5_HIGH);
}

u32 XMatrix_mult_hw_Get_A_5_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_A_5_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_5_BASE + 1);
}

u32 XMatrix_mult_hw_Get_A_5_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_A_5;
}

u32 XMatrix_mult_hw_Get_A_5_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_A_5;
}

u32 XMatrix_mult_hw_Write_A_5_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_5_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_5_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_5_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_5_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_5_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_5_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_5_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_A_5_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_5_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_5_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_5_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_5_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_5_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_5_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_5_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_A_6_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_6_BASE);
}

u32 XMatrix_mult_hw_Get_A_6_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_6_HIGH);
}

u32 XMatrix_mult_hw_Get_A_6_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_A_6_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_6_BASE + 1);
}

u32 XMatrix_mult_hw_Get_A_6_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_A_6;
}

u32 XMatrix_mult_hw_Get_A_6_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_A_6;
}

u32 XMatrix_mult_hw_Write_A_6_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_6_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_6_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_6_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_6_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_6_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_6_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_6_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_A_6_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_6_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_6_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_6_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_6_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_6_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_6_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_6_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_A_7_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_7_BASE);
}

u32 XMatrix_mult_hw_Get_A_7_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_7_HIGH);
}

u32 XMatrix_mult_hw_Get_A_7_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_A_7_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_7_BASE + 1);
}

u32 XMatrix_mult_hw_Get_A_7_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_A_7;
}

u32 XMatrix_mult_hw_Get_A_7_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_A_7;
}

u32 XMatrix_mult_hw_Write_A_7_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_7_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_7_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_7_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_7_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_7_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_7_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_7_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_A_7_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_7_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_7_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_7_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_7_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_7_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_7_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_7_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_A_8_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_8_BASE);
}

u32 XMatrix_mult_hw_Get_A_8_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_8_HIGH);
}

u32 XMatrix_mult_hw_Get_A_8_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_A_8_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_8_BASE + 1);
}

u32 XMatrix_mult_hw_Get_A_8_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_A_8;
}

u32 XMatrix_mult_hw_Get_A_8_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_A_8;
}

u32 XMatrix_mult_hw_Write_A_8_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_8_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_8_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_8_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_8_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_8_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_8_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_8_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_A_8_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_8_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_8_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_8_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_8_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_8_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_8_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_8_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_A_9_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_9_BASE);
}

u32 XMatrix_mult_hw_Get_A_9_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_9_HIGH);
}

u32 XMatrix_mult_hw_Get_A_9_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_A_9_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_9_BASE + 1);
}

u32 XMatrix_mult_hw_Get_A_9_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_A_9;
}

u32 XMatrix_mult_hw_Get_A_9_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_A_9;
}

u32 XMatrix_mult_hw_Write_A_9_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_9_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_9_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_9_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_9_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_9_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_9_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_9_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_A_9_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_9_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_9_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_9_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_9_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_9_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_9_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_9_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_A_10_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_10_BASE);
}

u32 XMatrix_mult_hw_Get_A_10_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_10_HIGH);
}

u32 XMatrix_mult_hw_Get_A_10_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_A_10_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_10_BASE + 1);
}

u32 XMatrix_mult_hw_Get_A_10_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_A_10;
}

u32 XMatrix_mult_hw_Get_A_10_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_A_10;
}

u32 XMatrix_mult_hw_Write_A_10_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_10_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_10_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_10_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_10_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_10_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_10_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_10_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_A_10_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_10_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_10_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_10_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_10_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_10_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_10_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_10_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_A_11_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_11_BASE);
}

u32 XMatrix_mult_hw_Get_A_11_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_11_HIGH);
}

u32 XMatrix_mult_hw_Get_A_11_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_A_11_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_11_BASE + 1);
}

u32 XMatrix_mult_hw_Get_A_11_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_A_11;
}

u32 XMatrix_mult_hw_Get_A_11_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_A_11;
}

u32 XMatrix_mult_hw_Write_A_11_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_11_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_11_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_11_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_11_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_11_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_11_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_11_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_A_11_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_11_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_11_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_11_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_11_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_11_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_11_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_11_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_A_12_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_12_BASE);
}

u32 XMatrix_mult_hw_Get_A_12_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_12_HIGH);
}

u32 XMatrix_mult_hw_Get_A_12_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_A_12_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_12_BASE + 1);
}

u32 XMatrix_mult_hw_Get_A_12_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_A_12;
}

u32 XMatrix_mult_hw_Get_A_12_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_A_12;
}

u32 XMatrix_mult_hw_Write_A_12_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_12_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_12_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_12_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_12_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_12_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_12_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_12_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_A_12_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_12_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_12_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_12_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_12_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_12_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_12_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_12_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_A_13_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_13_BASE);
}

u32 XMatrix_mult_hw_Get_A_13_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_13_HIGH);
}

u32 XMatrix_mult_hw_Get_A_13_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_A_13_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_13_BASE + 1);
}

u32 XMatrix_mult_hw_Get_A_13_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_A_13;
}

u32 XMatrix_mult_hw_Get_A_13_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_A_13;
}

u32 XMatrix_mult_hw_Write_A_13_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_13_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_13_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_13_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_13_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_13_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_13_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_13_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_A_13_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_13_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_13_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_13_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_13_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_13_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_13_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_13_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_A_14_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_14_BASE);
}

u32 XMatrix_mult_hw_Get_A_14_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_14_HIGH);
}

u32 XMatrix_mult_hw_Get_A_14_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_A_14_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_14_BASE + 1);
}

u32 XMatrix_mult_hw_Get_A_14_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_A_14;
}

u32 XMatrix_mult_hw_Get_A_14_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_A_14;
}

u32 XMatrix_mult_hw_Write_A_14_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_14_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_14_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_14_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_14_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_14_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_14_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_14_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_A_14_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_14_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_14_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_14_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_14_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_14_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_14_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_14_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_A_15_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_15_BASE);
}

u32 XMatrix_mult_hw_Get_A_15_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_15_HIGH);
}

u32 XMatrix_mult_hw_Get_A_15_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_A_15_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_15_BASE + 1);
}

u32 XMatrix_mult_hw_Get_A_15_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_A_15;
}

u32 XMatrix_mult_hw_Get_A_15_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_A_15;
}

u32 XMatrix_mult_hw_Write_A_15_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_15_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_15_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_15_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_15_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_A_15_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_15_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_15_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_A_15_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_15_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_15_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_15_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_A_15_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_A_15_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_A_15_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_A_15_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_B_0_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_0_BASE);
}

u32 XMatrix_mult_hw_Get_B_0_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_0_HIGH);
}

u32 XMatrix_mult_hw_Get_B_0_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_B_0_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_0_BASE + 1);
}

u32 XMatrix_mult_hw_Get_B_0_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_B_0;
}

u32 XMatrix_mult_hw_Get_B_0_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_B_0;
}

u32 XMatrix_mult_hw_Write_B_0_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_0_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_0_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_0_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_0_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_0_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_B_0_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_0_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_0_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_0_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_0_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_0_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_0_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_B_1_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_1_BASE);
}

u32 XMatrix_mult_hw_Get_B_1_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_1_HIGH);
}

u32 XMatrix_mult_hw_Get_B_1_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_B_1_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_1_BASE + 1);
}

u32 XMatrix_mult_hw_Get_B_1_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_B_1;
}

u32 XMatrix_mult_hw_Get_B_1_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_B_1;
}

u32 XMatrix_mult_hw_Write_B_1_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_1_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_1_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_1_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_1_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_1_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_B_1_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_1_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_1_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_1_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_1_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_1_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_1_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_B_2_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_2_BASE);
}

u32 XMatrix_mult_hw_Get_B_2_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_2_HIGH);
}

u32 XMatrix_mult_hw_Get_B_2_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_B_2_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_2_BASE + 1);
}

u32 XMatrix_mult_hw_Get_B_2_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_B_2;
}

u32 XMatrix_mult_hw_Get_B_2_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_B_2;
}

u32 XMatrix_mult_hw_Write_B_2_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_2_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_2_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_2_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_2_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_2_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_B_2_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_2_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_2_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_2_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_2_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_2_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_2_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_B_3_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_3_BASE);
}

u32 XMatrix_mult_hw_Get_B_3_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_3_HIGH);
}

u32 XMatrix_mult_hw_Get_B_3_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_B_3_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_3_BASE + 1);
}

u32 XMatrix_mult_hw_Get_B_3_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_B_3;
}

u32 XMatrix_mult_hw_Get_B_3_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_B_3;
}

u32 XMatrix_mult_hw_Write_B_3_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_3_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_3_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_3_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_3_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_3_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_B_3_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_3_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_3_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_3_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_3_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_3_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_3_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_B_4_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_4_BASE);
}

u32 XMatrix_mult_hw_Get_B_4_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_4_HIGH);
}

u32 XMatrix_mult_hw_Get_B_4_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_B_4_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_4_BASE + 1);
}

u32 XMatrix_mult_hw_Get_B_4_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_B_4;
}

u32 XMatrix_mult_hw_Get_B_4_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_B_4;
}

u32 XMatrix_mult_hw_Write_B_4_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_4_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_4_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_4_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_4_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_4_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_4_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_4_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_B_4_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_4_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_4_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_4_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_4_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_4_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_4_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_4_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_B_5_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_5_BASE);
}

u32 XMatrix_mult_hw_Get_B_5_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_5_HIGH);
}

u32 XMatrix_mult_hw_Get_B_5_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_B_5_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_5_BASE + 1);
}

u32 XMatrix_mult_hw_Get_B_5_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_B_5;
}

u32 XMatrix_mult_hw_Get_B_5_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_B_5;
}

u32 XMatrix_mult_hw_Write_B_5_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_5_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_5_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_5_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_5_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_5_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_5_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_5_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_B_5_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_5_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_5_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_5_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_5_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_5_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_5_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_5_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_B_6_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_6_BASE);
}

u32 XMatrix_mult_hw_Get_B_6_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_6_HIGH);
}

u32 XMatrix_mult_hw_Get_B_6_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_B_6_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_6_BASE + 1);
}

u32 XMatrix_mult_hw_Get_B_6_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_B_6;
}

u32 XMatrix_mult_hw_Get_B_6_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_B_6;
}

u32 XMatrix_mult_hw_Write_B_6_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_6_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_6_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_6_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_6_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_6_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_6_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_6_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_B_6_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_6_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_6_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_6_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_6_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_6_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_6_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_6_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_B_7_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_7_BASE);
}

u32 XMatrix_mult_hw_Get_B_7_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_7_HIGH);
}

u32 XMatrix_mult_hw_Get_B_7_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_B_7_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_7_BASE + 1);
}

u32 XMatrix_mult_hw_Get_B_7_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_B_7;
}

u32 XMatrix_mult_hw_Get_B_7_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_B_7;
}

u32 XMatrix_mult_hw_Write_B_7_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_7_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_7_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_7_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_7_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_7_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_7_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_7_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_B_7_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_7_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_7_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_7_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_7_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_7_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_7_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_7_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_B_8_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_8_BASE);
}

u32 XMatrix_mult_hw_Get_B_8_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_8_HIGH);
}

u32 XMatrix_mult_hw_Get_B_8_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_B_8_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_8_BASE + 1);
}

u32 XMatrix_mult_hw_Get_B_8_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_B_8;
}

u32 XMatrix_mult_hw_Get_B_8_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_B_8;
}

u32 XMatrix_mult_hw_Write_B_8_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_8_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_8_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_8_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_8_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_8_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_8_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_8_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_B_8_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_8_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_8_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_8_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_8_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_8_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_8_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_8_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_B_9_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_9_BASE);
}

u32 XMatrix_mult_hw_Get_B_9_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_9_HIGH);
}

u32 XMatrix_mult_hw_Get_B_9_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_B_9_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_9_BASE + 1);
}

u32 XMatrix_mult_hw_Get_B_9_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_B_9;
}

u32 XMatrix_mult_hw_Get_B_9_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_B_9;
}

u32 XMatrix_mult_hw_Write_B_9_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_9_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_9_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_9_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_9_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_9_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_9_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_9_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_B_9_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_9_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_9_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_9_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_9_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_9_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_9_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_9_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_B_10_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_10_BASE);
}

u32 XMatrix_mult_hw_Get_B_10_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_10_HIGH);
}

u32 XMatrix_mult_hw_Get_B_10_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_B_10_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_10_BASE + 1);
}

u32 XMatrix_mult_hw_Get_B_10_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_B_10;
}

u32 XMatrix_mult_hw_Get_B_10_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_B_10;
}

u32 XMatrix_mult_hw_Write_B_10_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_10_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_10_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_10_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_10_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_10_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_10_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_10_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_B_10_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_10_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_10_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_10_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_10_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_10_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_10_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_10_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_B_11_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_11_BASE);
}

u32 XMatrix_mult_hw_Get_B_11_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_11_HIGH);
}

u32 XMatrix_mult_hw_Get_B_11_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_B_11_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_11_BASE + 1);
}

u32 XMatrix_mult_hw_Get_B_11_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_B_11;
}

u32 XMatrix_mult_hw_Get_B_11_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_B_11;
}

u32 XMatrix_mult_hw_Write_B_11_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_11_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_11_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_11_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_11_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_11_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_11_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_11_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_B_11_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_11_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_11_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_11_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_11_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_11_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_11_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_11_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_B_12_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_12_BASE);
}

u32 XMatrix_mult_hw_Get_B_12_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_12_HIGH);
}

u32 XMatrix_mult_hw_Get_B_12_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_B_12_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_12_BASE + 1);
}

u32 XMatrix_mult_hw_Get_B_12_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_B_12;
}

u32 XMatrix_mult_hw_Get_B_12_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_B_12;
}

u32 XMatrix_mult_hw_Write_B_12_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_12_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_12_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_12_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_12_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_12_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_12_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_12_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_B_12_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_12_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_12_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_12_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_12_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_12_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_12_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_12_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_B_13_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_13_BASE);
}

u32 XMatrix_mult_hw_Get_B_13_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_13_HIGH);
}

u32 XMatrix_mult_hw_Get_B_13_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_B_13_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_13_BASE + 1);
}

u32 XMatrix_mult_hw_Get_B_13_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_B_13;
}

u32 XMatrix_mult_hw_Get_B_13_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_B_13;
}

u32 XMatrix_mult_hw_Write_B_13_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_13_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_13_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_13_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_13_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_13_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_13_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_13_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_B_13_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_13_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_13_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_13_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_13_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_13_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_13_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_13_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_B_14_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_14_BASE);
}

u32 XMatrix_mult_hw_Get_B_14_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_14_HIGH);
}

u32 XMatrix_mult_hw_Get_B_14_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_B_14_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_14_BASE + 1);
}

u32 XMatrix_mult_hw_Get_B_14_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_B_14;
}

u32 XMatrix_mult_hw_Get_B_14_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_B_14;
}

u32 XMatrix_mult_hw_Write_B_14_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_14_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_14_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_14_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_14_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_14_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_14_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_14_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_B_14_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_14_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_14_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_14_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_14_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_14_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_14_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_14_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_B_15_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_15_BASE);
}

u32 XMatrix_mult_hw_Get_B_15_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_15_HIGH);
}

u32 XMatrix_mult_hw_Get_B_15_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_B_15_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_15_BASE + 1);
}

u32 XMatrix_mult_hw_Get_B_15_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_B_15;
}

u32 XMatrix_mult_hw_Get_B_15_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_B_15;
}

u32 XMatrix_mult_hw_Write_B_15_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_15_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_15_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_15_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_15_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_B_15_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_15_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_15_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_B_15_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_15_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_15_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_15_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_B_15_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_B_15_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_B_15_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_B_15_BASE + offset + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Get_C_BaseAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_C_BASE);
}

u32 XMatrix_mult_hw_Get_C_HighAddress(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_C_HIGH);
}

u32 XMatrix_mult_hw_Get_C_TotalBytes(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMATRIX_MULT_HW_CONTROL_ADDR_C_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_C_BASE + 1);
}

u32 XMatrix_mult_hw_Get_C_BitWidth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_WIDTH_C;
}

u32 XMatrix_mult_hw_Get_C_Depth(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMATRIX_MULT_HW_CONTROL_DEPTH_C;
}

u32 XMatrix_mult_hw_Write_C_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_C_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_C_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_C_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_C_Words(XMatrix_mult_hw *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMATRIX_MULT_HW_CONTROL_ADDR_C_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_C_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_C_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMatrix_mult_hw_Write_C_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_C_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_C_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_C_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMatrix_mult_hw_Read_C_Bytes(XMatrix_mult_hw *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMATRIX_MULT_HW_CONTROL_ADDR_C_HIGH - XMATRIX_MULT_HW_CONTROL_ADDR_C_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Control_BaseAddress + XMATRIX_MULT_HW_CONTROL_ADDR_C_BASE + offset + i);
    }
    return length;
}

void XMatrix_mult_hw_InterruptGlobalEnable(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatrix_mult_hw_WriteReg(InstancePtr->Control_BaseAddress, XMATRIX_MULT_HW_CONTROL_ADDR_GIE, 1);
}

void XMatrix_mult_hw_InterruptGlobalDisable(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatrix_mult_hw_WriteReg(InstancePtr->Control_BaseAddress, XMATRIX_MULT_HW_CONTROL_ADDR_GIE, 0);
}

void XMatrix_mult_hw_InterruptEnable(XMatrix_mult_hw *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMatrix_mult_hw_ReadReg(InstancePtr->Control_BaseAddress, XMATRIX_MULT_HW_CONTROL_ADDR_IER);
    XMatrix_mult_hw_WriteReg(InstancePtr->Control_BaseAddress, XMATRIX_MULT_HW_CONTROL_ADDR_IER, Register | Mask);
}

void XMatrix_mult_hw_InterruptDisable(XMatrix_mult_hw *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMatrix_mult_hw_ReadReg(InstancePtr->Control_BaseAddress, XMATRIX_MULT_HW_CONTROL_ADDR_IER);
    XMatrix_mult_hw_WriteReg(InstancePtr->Control_BaseAddress, XMATRIX_MULT_HW_CONTROL_ADDR_IER, Register & (~Mask));
}

void XMatrix_mult_hw_InterruptClear(XMatrix_mult_hw *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMatrix_mult_hw_WriteReg(InstancePtr->Control_BaseAddress, XMATRIX_MULT_HW_CONTROL_ADDR_ISR, Mask);
}

u32 XMatrix_mult_hw_InterruptGetEnabled(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMatrix_mult_hw_ReadReg(InstancePtr->Control_BaseAddress, XMATRIX_MULT_HW_CONTROL_ADDR_IER);
}

u32 XMatrix_mult_hw_InterruptGetStatus(XMatrix_mult_hw *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMatrix_mult_hw_ReadReg(InstancePtr->Control_BaseAddress, XMATRIX_MULT_HW_CONTROL_ADDR_ISR);
}

