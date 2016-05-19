//////////////////////////////////
// System level dependencies

#include <windows.h>

//////////////////////////////////
// ANSI level dependencies

#include <string.h>

//////////////////////////////////
// Application level dependencies

#include "thash.h"

//////////////////////////////////

THashArray::THashArray(char **ppItem)
{
	UINT i;

	memset(m_array, 0, sizeof(m_array));

	while (ppItem[0] != NULL)
	{
		i = HashFunction(ppItem[0]);
		while(m_array[i] != NULL)
			i = RehashFunction(i, ppItem[0]);
		m_array[i] = ppItem[0];
		ppItem++;
	}
}

THashArray::~THashArray()
{
}

char * THashArray::GetData(char *pszBuffer)
{
	UINT i = HashFunction(pszBuffer);
	while (m_array[i] != NULL)
	{
		char *ptr1 = m_array[i];
		char *ptr2 = pszBuffer;
		BOOL bStatus = TRUE;
		while ((bStatus = (*ptr1 == *ptr2++)) && *ptr1++ != '\0');
		if ( bStatus ) return ptr1;
		i = RehashFunction(i, pszBuffer);
	}
	return NULL;
}

BOOL THashArray::InHashArray(char *pszBuffer)
{
	return (GetData(pszBuffer) != NULL) ;
}

UINT THashArray::HashFunction(char *pszBuffer)
{
	UINT i = 0;
	while (*pszBuffer != '\0') i += 0x7F & (*pszBuffer++);
	return ((i ^ (i<<2)) & 0x0FFF) % (sizeof(m_array)/sizeof(char *));
}

UINT THashArray::RehashFunction(UINT i, char *pszBuffer)
{
	return (i+13) %  (sizeof(m_array)/sizeof(char *));
}
