//////////////////////////////////
// System level dependencies

#include <windows.h>

//////////////////////////////////
// ANSI level dependencies

#include <stdio.h>

//////////////////////////////////
// Application level dependencies

#include "tmemory.h"

/////////////////////////////////
THeapMemory::THeapMemory() {}
THeapMemory::~THeapMemory() {}
BOOL THeapMemory::Create() { return TRUE; }
BOOL THeapMemory::Destroy() { return TRUE; }
BOOL THeapMemory::Malloc(void **ppBuffer, UINT nSize) 
{ 
	if (nSize) *ppBuffer = new char[nSize]; 
	return TRUE;
}

BOOL THeapMemory::Free(void *pBuffer, UINT nSize) 
{ 
	if (nSize) delete pBuffer; 
	return TRUE;
}

/////////////////////////////////////////

TStackMemory::TStackMemory(ULONG nStackSize)  : m_nStackSize(nStackSize) {} 
TStackMemory::~TStackMemory() {}
BOOL TStackMemory::Create() { m_pStackMemory = new char[m_nStackSize]; return TRUE; }
BOOL TStackMemory::Destroy() { delete m_pStackMemory; return TRUE; }

BOOL TStackMemory::Malloc(void **ppBuffer, UINT nSize)
{
	*ppBuffer = m_pStackMemory;
	m_pStackMemory = &m_pStackMemory[nSize];
	return TRUE;
}

BOOL TStackMemory::Free(void *pBuffer, UINT nSize)
{
	m_pStackMemory = (char *)pBuffer;
	return TRUE;
}

/////////////////////////////////////////////////////////

TDebugMemory::TDebugMemory(TMemory *pMemory, char *pszSegmentName) :
	m_pMemory(pMemory) ,
	m_pszSegmentName(pszSegmentName)
{
}

TDebugMemory::~TDebugMemory() 
{
}

BOOL TDebugMemory::Create() 
{ 
	m_nBlocks = 0;
	return TRUE; 
}

BOOL TDebugMemory::Destroy()
{
	if (m_nBlocks) 
	{
		printf("Memory error: Segment %s unfree %lu blocks\n", m_pszSegmentName, m_nBlocks);
		fflush(stdout);
	}
	return TRUE;
}

BOOL TDebugMemory::Malloc(void **ppBuffer, UINT nSize)
{
	m_nBlocks++;
	return m_pMemory->Malloc(ppBuffer, nSize);
}

BOOL TDebugMemory::Free(void *pBuffer, UINT nSize)
{
	m_nBlocks--;
	return m_pMemory->Free(pBuffer, nSize);
}
