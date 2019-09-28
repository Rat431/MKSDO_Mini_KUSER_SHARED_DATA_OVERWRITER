#include <ntdef.h>
#include <ntifs.h>
#include <ntdef.h>
#include <ntddk.h>
#include <wdm.h>

int byte = 0;
char Writeval[4] = { 0xCF, 0xCF, 0x1F, 0x0 };			// Declare overwriters buffers
char Writevaldue80[4] = { 0x01, 0x01, 0x01, 0x0 };
char Writevaldue74[4] = { 0x0, 0x0, 0x01, 0x01 };
char Writevaldue78[4] = { 0x0, 0x0, 0x01, 0x0 };
char Writevaldue7C[4] = { 0x01, 0x01, 0x01, 0x0 };
char Writevaldue84[4] = { 0x0, 0x01, 0x0, 0x0 };
char Writevaldue30[4] = { 0x43, 0x0, 0x3A, 0x0 };
char Writevaldue34[4] = { 0x5C, 0x0, 0x57, 0x0 };
char Writevaldue38[4] = { 0x49, 0x0, 0x4E, 0x0 };
char Writevaldue3C[4] = { 0x44, 0x0, 0x4F, 0x0 };
char Writevaldue40[4] = { 0x57, 0x0, 0x53, 0x0 };
char Writevaldue44[4] = { 0x0, 0x0, 0x0, 0x0 };
char Writevaldue48[4] = { 0x0, 0x0, 0x0, 0x0 };
char Writevaldue4C[4] = { 0x0, 0x0, 0x0, 0x0 };
char Writevaldue26C[4] = { 0x0A, 0x0, 0x0, 0x0 };
char Writevaldue70[4] = { 0x0, 0x0, 0x0, 0x0 };


char RestoreWriteval[4] = { 0 };        // Declare restore buffers
char RestoreWritevaldue80[4] = { 0 };
char RestoreWritevaldue74[4] = { 0 };
char RestoreWritevaldue78[4] = { 0 };
char RestoreWritevaldue7C[4] = { 0 };
char RestoreWritevaldue84[4] = { 0 };
char RestoreWritevaldue30[4] = { 0 };
char RestoreWritevaldue34[4] = { 0 };
char RestoreWritevaldue38[4] = { 0 };
char RestoreWritevaldue3C[4] = { 0 };
char RestoreWritevaldue40[4] = { 0 };
char RestoreWritevaldue44[4] = { 0 };
char RestoreWritevaldue48[4] = { 0 };
char RestoreWritevaldue4C[4] = { 0 };
char RestoreWritevaldue26C[4] = { 0 };
char RestoreWritevaldue70[4] = { 0 };

unsigned long bytesaddress[16] = { 0x7FFE0274, 0x7FFE0278, 0x7FFE027C, 0x7FFE0280, 0x7FFE0284, 0x7FFE0030, 0x7FFE0034, 0x7FFE0038, 0x7FFE003C,
	0x7FFE0040,  0x7FFE0044,  0x7FFE0048,  0x7FFE004C,  0x7FFE026C,  0x7FFE0270,  0x7FFE02E8 };    // Define our KuserAddresses matrix that we need to overwrites

/*
Set the EntryPoint in the linker settings DriverEntry directly.
*/
uintptr_t datamap = NULL;
uintptr_t KuserAddress = 0x7FFE0000;
NTSTATUS status;



void DetachKernel(uintptr_t Address)			// ; Restore kernel
{
	switch (Address)
	{
	case 0x7FFE0274:
		RtlCopyMemory(datamap, (void*)RestoreWritevaldue74, 4);
		break;
	case 0x7FFE0278:
		RtlCopyMemory(datamap, (void*)RestoreWritevaldue78, 4);
		break;
	case 0x7FFE027C:
		RtlCopyMemory(datamap, (void*)RestoreWritevaldue7C, 4);
		break;
	case 0x7FFE0280:
		RtlCopyMemory(datamap, (void*)RestoreWritevaldue80, 4);
		break;
	case 0x7FFE0284:
		RtlCopyMemory(datamap, (void*)RestoreWritevaldue84, 4);
		break;
	case 0x7FFE0030:
		RtlCopyMemory(datamap, (void*)RestoreWritevaldue30, 4);
		break;
	case 0x7FFE0034:
		RtlCopyMemory(datamap, (void*)RestoreWritevaldue34, 4);
		break;
	case 0x7FFE0038:
		RtlCopyMemory(datamap, (void*)RestoreWritevaldue38, 4);
		break;
	case 0x7FFE003C:
		RtlCopyMemory(datamap, (void*)RestoreWritevaldue3C, 4);
		break;
	case 0x7FFE0040:
		RtlCopyMemory(datamap, (void*)RestoreWritevaldue40, 4);
		break;
	case 0x7FFE0044:
		RtlCopyMemory(datamap, (void*)RestoreWritevaldue44, 4);
		break;
	case 0x7FFE0048:
		RtlCopyMemory(datamap, (void*)RestoreWritevaldue48, 4);
		break;
	case 0x7FFE004C:
		RtlCopyMemory(datamap, (void*)RestoreWritevaldue4C, 4);
		break;
	case 0x7FFE026C:
		RtlCopyMemory(datamap, (void*)RestoreWritevaldue26C, 4);
		break;
	case 0x7FFE0270:
		RtlCopyMemory(datamap, (void*)RestoreWritevaldue70, 4);
		break;
	case 0x7FFE02E8:
		RtlCopyMemory(datamap, (void*)RestoreWriteval, 4);
		break;

	default:
		break;
	}
}


void AttchKernel(uintptr_t Address)			// ; OverWrites kernel
{
	switch (Address)
	{
	case 0x7FFE0274:
		RtlCopyMemory((void*)RestoreWritevaldue74, datamap, 4);
		RtlCopyMemory(datamap, (void*)Writevaldue74, 4);
		break;
	case 0x7FFE0278:
		RtlCopyMemory((void*)RestoreWritevaldue78, datamap, 4);
		RtlCopyMemory(datamap, (void*)Writevaldue78, 4);
		break;
	case 0x7FFE027C:
		RtlCopyMemory((void*)RestoreWritevaldue7C, datamap, 4);
		RtlCopyMemory(datamap, (void*)Writevaldue7C, 4);
		break;
	case 0x7FFE0280:
		RtlCopyMemory((void*)RestoreWritevaldue80, datamap, 4);
		RtlCopyMemory(datamap, (void*)Writevaldue80, 4);
		break;
	case 0x7FFE0284:
		RtlCopyMemory((void*)RestoreWritevaldue84, datamap, 4);
		RtlCopyMemory(datamap, (void*)Writevaldue84, 4);
		break;
	case 0x7FFE0030:
		RtlCopyMemory((void*)RestoreWritevaldue30, datamap, 4);
		RtlCopyMemory(datamap, (void*)Writevaldue30, 4);
		break;
	case 0x7FFE0034:
		RtlCopyMemory((void*)RestoreWritevaldue34, datamap, 4);
		RtlCopyMemory(datamap, (void*)Writevaldue34, 4);
		break;
	case 0x7FFE0038:
		RtlCopyMemory((void*)RestoreWritevaldue38, datamap, 4);
		RtlCopyMemory(datamap, (void*)Writevaldue38, 4);
		break;
	case 0x7FFE003C:
		RtlCopyMemory((void*)RestoreWritevaldue3C, datamap, 4);
		RtlCopyMemory(datamap, (void*)Writevaldue3C, 4);
		break;
	case 0x7FFE0040:
		RtlCopyMemory((void*)RestoreWritevaldue40, datamap, 4);
		RtlCopyMemory(datamap, (void*)Writevaldue40, 4);
		break;
	case 0x7FFE0044:
		RtlCopyMemory((void*)RestoreWritevaldue44, datamap, 4);
		RtlCopyMemory(datamap, (void*)Writevaldue44, 4);
		break;
	case 0x7FFE0048:
		RtlCopyMemory((void*)RestoreWritevaldue48, datamap, 4);
		RtlCopyMemory(datamap, (void*)Writevaldue48, 4);
		break;
	case 0x7FFE004C:
		RtlCopyMemory((void*)RestoreWritevaldue4C, datamap, 4);
		RtlCopyMemory(datamap, (void*)Writevaldue4C, 4);
		break;
	case 0x7FFE026C:
		RtlCopyMemory((void*)RestoreWritevaldue26C, datamap, 4);
		RtlCopyMemory(datamap, (void*)Writevaldue26C, 4);
		break;
	case 0x7FFE0270:
		RtlCopyMemory((void*)RestoreWritevaldue70, datamap, 4);
		RtlCopyMemory(datamap, (void*)Writevaldue70, 4);
		break;
	case 0x7FFE02E8:
		RtlCopyMemory((void*)RestoreWriteval, datamap, 4);
		RtlCopyMemory(datamap, (void*)Writeval, 4);
		break;

	default:
		break;
	}
}
NTSTATUS DriverUnloader()
{
	__try
	{

		for (int kusersize = 0; kusersize < 0x1000; kusersize++)
		{
			for (int m = 0; m < 16; m++)
			{
				if (bytesaddress[m] == KuserAddress)
				{

					PMDL descriptor = IoAllocateMdl((PVOID)KuserAddress, 4, 0, 0, 0);
					if (descriptor)
					{
						MmProbeAndLockPages(descriptor, KernelMode, IoReadAccess);
						MmProtectMdlSystemAddress(descriptor, PAGE_READWRITE);
						datamap = MmMapLockedPagesSpecifyCache(descriptor, KernelMode, MmCached, NULL, 0, NormalPagePriority);
						DetachKernel(KuserAddress);
						MmProtectMdlSystemAddress(descriptor, PAGE_READONLY);
						MmUnmapLockedPages((PVOID)KuserAddress, descriptor);
						MmUnlockPages(descriptor);
						IoFreeMdl(descriptor);
						descriptor = NULL;
						datamap = NULL;
						break;
					}


				}
			}
			KuserAddress++;
		}

		byte = 1;
		return STATUS_SUCCESS;

	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return STATUS_ACCESS_DENIED;
	}

}
NTSTATUS StartDriverAndKuserHook()
{

	if (byte == 0)
	{
		__try
		{

			for (int kusersize = 0; kusersize < 0x1000; kusersize++)
			{
				for (int m = 0; m < 16; m++)
				{
					if (bytesaddress[m] == KuserAddress)
					{

						PMDL descriptor = IoAllocateMdl((PVOID)KuserAddress, 4, 0, 0, 0);
						if (descriptor)
						{
							MmProbeAndLockPages(descriptor, KernelMode, IoReadAccess);
							MmProtectMdlSystemAddress(descriptor, PAGE_READWRITE);
							datamap = MmMapLockedPagesSpecifyCache(descriptor, KernelMode, MmCached, NULL, 0, NormalPagePriority);
							AttchKernel(KuserAddress);
							MmProtectMdlSystemAddress(descriptor, PAGE_READONLY);
							MmUnmapLockedPages((PVOID)KuserAddress, descriptor);
							MmUnlockPages(descriptor);
							IoFreeMdl(descriptor);
							descriptor = NULL;
							datamap = NULL;
							break;
						}


					}
				}
				KuserAddress++;
			}

			byte = 1;
			KuserAddress = 0x7FFE0000;
			return STATUS_SUCCESS;

		}
		__except (EXCEPTION_EXECUTE_HANDLER)
		{
			return STATUS_ACCESS_DENIED;
		}


	}
	else
	{
		return STATUS_SUCCESS;

	}

	return STATUS_ACCESS_DENIED;
}

VOID Unload(_In_  struct _DRIVER_OBJECT* DriverObject)
{
	NTSTATUS MyStatus = STATUS_SUCCESS;
	MyStatus = DriverUnloader();
	if (NT_SUCCESS(MyStatus))
		return STATUS_SUCCESS;
	else
		return MyStatus;

}
NTSTATUS DriverEntry(_In_  struct _DRIVER_OBJECT* DriverObject, _In_  PUNICODE_STRING RegistryPath) // Driver Entry
{
	DbgPrint("DriverEntry called!");
	DriverObject->DriverUnload = Unload;
	NTSTATUS MyStatus = STATUS_SUCCESS;
	MyStatus = StartDriverAndKuserHook();
	if (NT_SUCCESS(MyStatus))
		return STATUS_SUCCESS;
	else
		return MyStatus;
}
