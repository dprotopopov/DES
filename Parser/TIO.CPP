//////////////////////////////////
// System level dependencies

#include <windows.h>

//////////////////////////////////
// ANSI level dependencies

#include <stdio.h>

//////////////////////////////////
// Application level dependencies

#include "tio.h"
#include "tlog.h"

//////////////////////////////////

TFile::TFile(FILE *pFile)
{
	m_pFile = pFile;
	m_size = 0;
	fpos_t pos;
	fgetpos(pFile, &pos);
	fseek(pFile, 0, SEEK_END);
	fgetpos(pFile, &m_eof);
	fsetpos(pFile, &pos);
}

TFile::~TFile()
{
	fflush(m_pFile);
}

BOOL TFile::Eof()
{
	if (feof(m_pFile)) return TRUE;
	fpos_t pos;
	fgetpos(m_pFile, &pos);
	return (pos == m_eof);
}

UINT TFile::Read(char *buffer, UINT nCount)
{
	return (UINT)fread(buffer, 1, nCount, m_pFile);
}

BOOL TFile::Scanf(char *format, void *pBuffer, UINT *pcbBuffer, UINT cbMaxBuffer, LPARAM *plChoice)
{
	fpos_t pos;
	int count = -1;
	BOOL bStatus = FALSE;
	char *subformat = format;

	fgetpos(m_pFile, &pos);

	if (plChoice != NULL) *plChoice = 0;

	while ( *subformat )
	{
		fscanf(m_pFile, subformat, &count);
		bStatus = (count != -1);
		fsetpos(m_pFile, &pos);
		if (bStatus) break;
		while ( *subformat++ );
		if (plChoice != NULL) (*plChoice)++;
	}

	if (!bStatus) return FALSE;

	if ((UINT)count < cbMaxBuffer)
	{
		*pcbBuffer = (UINT)fread(pBuffer, 1, count, m_pFile);
		return TRUE;
	}
	else
	{
		*pcbBuffer = (UINT)fread(pBuffer, 1, cbMaxBuffer, m_pFile);
		fseek(m_pFile, count-cbMaxBuffer, SEEK_CUR);
		return TRUE;
	}
}

void TFile::BeginRead()
{
	fgetpos(m_pFile, &m_stack[m_size++]);
}

void TFile::EndRead(BOOL bCommit)
{
	m_size--;
	if (!bCommit) fsetpos(m_pFile, &m_stack[m_size]);
}

UINT TFile::Write(char * buffer, UINT nCount)
{
	return (UINT)fwrite(buffer, 1, nCount, m_pFile);
}


TMemPipeline::TMemPipeline(char * pBuffer, UINT nLength) :
	m_pBuffer(pBuffer),
	m_nLength(nLength),
	m_posInput(0),
	m_posOutput(0),
	m_size(0)
{
		pBuffer[0] = 0;
}

TMemPipeline::~TMemPipeline() 
{
}

void TMemPipeline::BeginRead()
{
	m_stack[m_size++] = m_posInput;
}

void TMemPipeline::EndRead(BOOL bCommit)
{
	m_size--;
	if (!bCommit) m_posInput = m_stack[m_size];
}

BOOL TMemPipeline::Scanf(char *format, void *pBuffer, UINT *pcbBuffer, UINT cbMaxBuffer, LPARAM *plChoice)
{
	int count = -1;
	BOOL bStatus = FALSE;
	char *subformat = format;

	if (plChoice != NULL) *plChoice = 0;

	while ( *subformat )
	{
		sscanf(&m_pBuffer[m_posInput], subformat, &count);
		bStatus = (count != -1);
		if (bStatus) break;
		while ( *subformat++ );
		if (plChoice != NULL) (*plChoice)++;
	}

	if (!bStatus) return FALSE;

	if ((UINT)count < cbMaxBuffer)
	{
		memmove(pBuffer, &m_pBuffer[m_posInput], count);
		*pcbBuffer = count;
	}
	else
	{
		memmove(pBuffer, &m_pBuffer[m_posInput], cbMaxBuffer);
		*pcbBuffer = cbMaxBuffer;
	}
	m_posInput += count;
	return TRUE;
}

BOOL TMemPipeline::Eof()
{
	return (m_posInput == m_posOutput);
}

UINT TMemPipeline::Read(char *buffer, UINT nCount)
{
	if ((m_posInput + nCount) > m_posOutput) nCount = m_posOutput - m_posInput;
	memmove(buffer, &m_pBuffer[m_posInput], nCount);
	m_posInput += nCount;
	return nCount;
}

UINT TMemPipeline::Write(char *buffer, UINT nCount)
{
	if ((m_posOutput + nCount) > m_nLength) nCount = m_nLength - m_posOutput;
	memmove(&m_pBuffer[m_posOutput], buffer, nCount);
	m_posOutput += nCount;
	return nCount;
}