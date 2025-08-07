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
#include "xarray_summer.h"

extern XArray_summer_Config XArray_summer_ConfigTable[];

#ifdef SDT
XArray_summer_Config *XArray_summer_LookupConfig(UINTPTR BaseAddress) {
	XArray_summer_Config *ConfigPtr = NULL;

	int Index;

	for (Index = (u32)0x0; XArray_summer_ConfigTable[Index].Name != NULL; Index++) {
		if (!BaseAddress || XArray_summer_ConfigTable[Index].Control_BaseAddress == BaseAddress) {
			ConfigPtr = &XArray_summer_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XArray_summer_Initialize(XArray_summer *InstancePtr, UINTPTR BaseAddress) {
	XArray_summer_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XArray_summer_LookupConfig(BaseAddress);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XArray_summer_CfgInitialize(InstancePtr, ConfigPtr);
}
#else
XArray_summer_Config *XArray_summer_LookupConfig(u16 DeviceId) {
	XArray_summer_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XARRAY_SUMMER_NUM_INSTANCES; Index++) {
		if (XArray_summer_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XArray_summer_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XArray_summer_Initialize(XArray_summer *InstancePtr, u16 DeviceId) {
	XArray_summer_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XArray_summer_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XArray_summer_CfgInitialize(InstancePtr, ConfigPtr);
}
#endif

#endif

