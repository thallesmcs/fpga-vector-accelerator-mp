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
#include "xadder_new.h"

extern XAdder_new_Config XAdder_new_ConfigTable[];

#ifdef SDT
XAdder_new_Config *XAdder_new_LookupConfig(UINTPTR BaseAddress) {
	XAdder_new_Config *ConfigPtr = NULL;

	int Index;

	for (Index = (u32)0x0; XAdder_new_ConfigTable[Index].Name != NULL; Index++) {
		if (!BaseAddress || XAdder_new_ConfigTable[Index].Bus_a_BaseAddress == BaseAddress) {
			ConfigPtr = &XAdder_new_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XAdder_new_Initialize(XAdder_new *InstancePtr, UINTPTR BaseAddress) {
	XAdder_new_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XAdder_new_LookupConfig(BaseAddress);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XAdder_new_CfgInitialize(InstancePtr, ConfigPtr);
}
#else
XAdder_new_Config *XAdder_new_LookupConfig(u16 DeviceId) {
	XAdder_new_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XADDER_NEW_NUM_INSTANCES; Index++) {
		if (XAdder_new_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XAdder_new_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XAdder_new_Initialize(XAdder_new *InstancePtr, u16 DeviceId) {
	XAdder_new_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XAdder_new_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XAdder_new_CfgInitialize(InstancePtr, ConfigPtr);
}
#endif

#endif

