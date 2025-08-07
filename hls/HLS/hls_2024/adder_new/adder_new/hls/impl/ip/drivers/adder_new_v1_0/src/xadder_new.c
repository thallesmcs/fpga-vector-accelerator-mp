// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.2 (64-bit)
// Tool Version Limit: 2024.11
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
/***************************** Include Files *********************************/
#include "xadder_new.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XAdder_new_CfgInitialize(XAdder_new *InstancePtr, XAdder_new_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Bus_a_BaseAddress = ConfigPtr->Bus_a_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XAdder_new_Start(XAdder_new *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAdder_new_ReadReg(InstancePtr->Bus_a_BaseAddress, XADDER_NEW_BUS_A_ADDR_AP_CTRL) & 0x80;
    XAdder_new_WriteReg(InstancePtr->Bus_a_BaseAddress, XADDER_NEW_BUS_A_ADDR_AP_CTRL, Data | 0x01);
}

u32 XAdder_new_IsDone(XAdder_new *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAdder_new_ReadReg(InstancePtr->Bus_a_BaseAddress, XADDER_NEW_BUS_A_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XAdder_new_IsIdle(XAdder_new *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAdder_new_ReadReg(InstancePtr->Bus_a_BaseAddress, XADDER_NEW_BUS_A_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XAdder_new_IsReady(XAdder_new *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAdder_new_ReadReg(InstancePtr->Bus_a_BaseAddress, XADDER_NEW_BUS_A_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XAdder_new_EnableAutoRestart(XAdder_new *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAdder_new_WriteReg(InstancePtr->Bus_a_BaseAddress, XADDER_NEW_BUS_A_ADDR_AP_CTRL, 0x80);
}

void XAdder_new_DisableAutoRestart(XAdder_new *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAdder_new_WriteReg(InstancePtr->Bus_a_BaseAddress, XADDER_NEW_BUS_A_ADDR_AP_CTRL, 0);
}

void XAdder_new_Set_a(XAdder_new *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAdder_new_WriteReg(InstancePtr->Bus_a_BaseAddress, XADDER_NEW_BUS_A_ADDR_A_DATA, Data);
}

u32 XAdder_new_Get_a(XAdder_new *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAdder_new_ReadReg(InstancePtr->Bus_a_BaseAddress, XADDER_NEW_BUS_A_ADDR_A_DATA);
    return Data;
}

void XAdder_new_Set_b(XAdder_new *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAdder_new_WriteReg(InstancePtr->Bus_a_BaseAddress, XADDER_NEW_BUS_A_ADDR_B_DATA, Data);
}

u32 XAdder_new_Get_b(XAdder_new *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAdder_new_ReadReg(InstancePtr->Bus_a_BaseAddress, XADDER_NEW_BUS_A_ADDR_B_DATA);
    return Data;
}

void XAdder_new_Set_c_i(XAdder_new *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAdder_new_WriteReg(InstancePtr->Bus_a_BaseAddress, XADDER_NEW_BUS_A_ADDR_C_I_DATA, Data);
}

u32 XAdder_new_Get_c_i(XAdder_new *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAdder_new_ReadReg(InstancePtr->Bus_a_BaseAddress, XADDER_NEW_BUS_A_ADDR_C_I_DATA);
    return Data;
}

u32 XAdder_new_Get_c_o(XAdder_new *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAdder_new_ReadReg(InstancePtr->Bus_a_BaseAddress, XADDER_NEW_BUS_A_ADDR_C_O_DATA);
    return Data;
}

u32 XAdder_new_Get_c_o_vld(XAdder_new *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAdder_new_ReadReg(InstancePtr->Bus_a_BaseAddress, XADDER_NEW_BUS_A_ADDR_C_O_CTRL);
    return Data & 0x1;
}

void XAdder_new_InterruptGlobalEnable(XAdder_new *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAdder_new_WriteReg(InstancePtr->Bus_a_BaseAddress, XADDER_NEW_BUS_A_ADDR_GIE, 1);
}

void XAdder_new_InterruptGlobalDisable(XAdder_new *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAdder_new_WriteReg(InstancePtr->Bus_a_BaseAddress, XADDER_NEW_BUS_A_ADDR_GIE, 0);
}

void XAdder_new_InterruptEnable(XAdder_new *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XAdder_new_ReadReg(InstancePtr->Bus_a_BaseAddress, XADDER_NEW_BUS_A_ADDR_IER);
    XAdder_new_WriteReg(InstancePtr->Bus_a_BaseAddress, XADDER_NEW_BUS_A_ADDR_IER, Register | Mask);
}

void XAdder_new_InterruptDisable(XAdder_new *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XAdder_new_ReadReg(InstancePtr->Bus_a_BaseAddress, XADDER_NEW_BUS_A_ADDR_IER);
    XAdder_new_WriteReg(InstancePtr->Bus_a_BaseAddress, XADDER_NEW_BUS_A_ADDR_IER, Register & (~Mask));
}

void XAdder_new_InterruptClear(XAdder_new *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAdder_new_WriteReg(InstancePtr->Bus_a_BaseAddress, XADDER_NEW_BUS_A_ADDR_ISR, Mask);
}

u32 XAdder_new_InterruptGetEnabled(XAdder_new *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XAdder_new_ReadReg(InstancePtr->Bus_a_BaseAddress, XADDER_NEW_BUS_A_ADDR_IER);
}

u32 XAdder_new_InterruptGetStatus(XAdder_new *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XAdder_new_ReadReg(InstancePtr->Bus_a_BaseAddress, XADDER_NEW_BUS_A_ADDR_ISR);
}

