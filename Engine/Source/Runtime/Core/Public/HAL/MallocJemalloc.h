#pragma once

#include "CoreTypes.h"
#include "HAL/MemoryBase.h"
#include "Logging/LogMacros.h"
#include "CoreGlobals.h"

// Only use for supported platforms
#if PLATFORM_SUPPORTS_JEMALLOC

#define MEM_TIME(st)


//
// Jason Evans' malloc (default in FreeBSD, NetBSD, used in Firefox, Facebook servers) 
// http://www.canonware.com/jemalloc/
//
class FMallocJemalloc
	: public YMalloc
{
public:

	/**
	* Default constructor.
	*/
	FMallocJemalloc()
		: MemTime(0.0)
	{ }

public:

	// YMalloc interface.

	virtual void* Malloc(SIZE_T Size, uint32 Alignment) override;
	virtual void* Realloc(void* Ptr, SIZE_T NewSize, uint32 Alignment) override;
	virtual void Free(void* Ptr) override;
	virtual void DumpAllocatorStats(YOutputDevice& Ar) override;
	virtual bool GetAllocationSize(void *Original, SIZE_T &SizeOut) override;
	virtual bool IsInternallyThreadSafe() const override { return true; }
	virtual const TCHAR* GetDescriptiveName() override { return TEXT("jemalloc"); }

protected:

	void OutOfMemory()
	{
		UE_LOG(LogHAL, Fatal, TEXT("%s"), TEXT("Ran out of virtual memory. To prevent this condition, you must free up more space on your primary hard disk."));
	}

private:

	/** Time spent on memory tasks, in seconds */
	double MemTime;
};


#endif // PLATFORM_SUPPORTS_JEMALLOC
