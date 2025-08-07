// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2025.1 (64-bit)
// Tool Version Limit: 2025.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#ifdef SDT
#include "xparameters.h"
#endif
#include "xmult_hw_1600.h"

extern XMult_hw_1600_Config XMult_hw_1600_ConfigTable[];

#ifdef SDT
XMult_hw_1600_Config *XMult_hw_1600_LookupConfig(UINTPTR BaseAddress) {
	XMult_hw_1600_Config *ConfigPtr = NULL;

	int Index;

	for (Index = (u32)0x0; XMult_hw_1600_ConfigTable[Index].Name != NULL; Index++) {
		if (!BaseAddress || XMult_hw_1600_ConfigTable[Index].Control_BaseAddress == BaseAddress) {
			ConfigPtr = &XMult_hw_1600_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XMult_hw_1600_Initialize(XMult_hw_1600 *InstancePtr, UINTPTR BaseAddress) {
	XMult_hw_1600_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XMult_hw_1600_LookupConfig(BaseAddress);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XMult_hw_1600_CfgInitialize(InstancePtr, ConfigPtr);
}
#else
XMult_hw_1600_Config *XMult_hw_1600_LookupConfig(u16 DeviceId) {
	XMult_hw_1600_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XMULT_HW_1600_NUM_INSTANCES; Index++) {
		if (XMult_hw_1600_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XMult_hw_1600_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XMult_hw_1600_Initialize(XMult_hw_1600 *InstancePtr, u16 DeviceId) {
	XMult_hw_1600_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XMult_hw_1600_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XMult_hw_1600_CfgInitialize(InstancePtr, ConfigPtr);
}
#endif

#endif

