#ifndef __TMEMORY_H
#define __TMEMORY_H

// Memory classes
// File tmemory.h
// Copyright © 1996
// Programmer: Dmitry Protopopov
////////////////////////////////////////////////////////////
class TMemory
{
public:
virtual BOOL Malloc(void **ppBuffer, UINT nSize) = 0;
virtual BOOL Free(void * pBuffer, UINT nSize) = 0;
virtual BOOL Create() = 0;
virtual BOOL Destroy() = 0;

};
//////////////////////////////////////////////////////////
class THeapMemory : public TMemory
{
public:
THeapMemory();
~THeapMemory();

public:
virtual BOOL Malloc(void **ppBuffer, UINT nSize);
virtual BOOL Free(void * pBuffer, UINT nSize);
virtual BOOL Create();
virtual BOOL Destroy();

};
///////////////////////////////////////////////////////
class TStackMemory : public TMemory
{
char *m_pStackMemory;
ULONG m_nStackSize;

public:
TStackMemory(ULONG nStackSize);
~TStackMemory();

public:
virtual BOOL Malloc(void **ppBuffer, UINT nSize);
virtual BOOL Free(void * pBuffer, UINT nSize);
virtual BOOL Create();
virtual BOOL Destroy();

};
///////////////////////////////////////////////////////
class TDebugMemory : public TMemory
{
protected:
TMemory * m_pMemory;
char * m_pszSegmentName;
ULONG m_nBlocks;

public:
TDebugMemory(TMemory *pMemory, char *pszSegmentName);
~TDebugMemory();

public:
virtual BOOL Malloc(void **ppBuffer, UINT nSize);
virtual BOOL Free(void * pBuffer, UINT nSize);
virtual BOOL Create();
virtual BOOL Destroy();

};
/////////////////////////////////////////////////////////

#endif // __TMEMORY_H