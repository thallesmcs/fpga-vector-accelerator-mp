// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2024.2 (64-bit)
// Tool Version Limit: 2024.11
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#ifdef SDT
#include "xparameters.h"
#endif
#include "xadder.h"

extern XAdder_Config XAdder_ConfigTable[];

#ifdef SDT
XAdder_Config *XAdder_LookupConfig(UINTPTR BaseAddress) {
	XAdder_Config *ConfigPtr = NULL;

	int Index;

	for (Index = (u32)0x0; XAdder_ConfigTable[Index].Name != NULL; Index++) {
		if (!BaseAddress || XAdder_ConfigTable[Index].Control_BaseAddress == BaseAddress) {
			ConfigPtr = &XAdder_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XAdder_Initialize(XAdder *InstancePtr, UINTPTR BaseAddress) {
	XAdder_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XAdder_LookupConfig(BaseAddress);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XAdder_CfgInitialize(InstancePtr, ConfigPtr);
}
#else
XAdder_Config *XAdder_LookupConfig(u16 DeviceId) {
	XAdder_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XADDER_NUM_INSTANCES; Index++) {
		if (XAdder_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XAdder_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XAdder_Initialize(XAdder *InstancePtr, u16 DeviceId) {
	XAdder_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XAdder_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XAdder_CfgInitialize(InstancePtr, ConfigPtr);
}
#endif

#endif

