#ifndef __TIO_H
#define __TIO_H

////////////////////////////////////////////////////////////////////////////
// Input/Output classes
// File tio.h
// Copyright © 1996, Asset Information Management
// Copyright © 1997, Asset Information Management
// Programmer: Dmitry Protopopov
////////////////////////////////////////////////////////////////////////////
class TInput 
{
public:
virtual UINT Read(char *buffer, UINT nCount) = 0;
virtual BOOL Scanf(char *format, void *pBuffer, UINT *pcbBuffer, UINT cbMaxBuffer, LPARAM *plChoice = NULL) = 0;
virtual void BeginRead() = 0;
virtual void EndRead(BOOL bCommit) = 0;
virtual BOOL Eof() = 0;
};

///////////////////////////////////////////////////////////////////////////////
class TOutput 
{
public:
virtual UINT Write(char * buffer, UINT nCount) = 0;
};

/////////////////////////////////////////////////////////////////////////
class TMemPipeline : public TInput , public TOutput
{
protected:
char * m_pBuffer;
UINT m_nLength;
UINT m_posInput;
UINT m_posOutput;
UINT m_stack[1000];
int m_size;

public:

TMemPipeline(char *pBuffer, UINT nLength);
~TMemPipeline();
virtual UINT Read(char *buffer, UINT nCount);
virtual BOOL Scanf(char *format, void *pBuffer, UINT *pcbBuffer, UINT cbMaxBuffer, LPARAM *plChoice = NULL);
virtual void BeginRead();
virtual void EndRead(BOOL bCommit);
virtual BOOL Eof();
virtual UINT Write(char * buffer, UINT nCount);
};

///////////////////////////////////////////////////////////////////////////////
class TFile : public TInput, public TOutput
{
protected:
FILE * m_pFile;
fpos_t m_eof;
fpos_t m_stack[1000];
int m_size;

public:
TFile(FILE *pFile);
~TFile();

// Overwrite TInput methods
public:
virtual UINT Read(char *buffer, UINT nCount);
virtual BOOL Scanf(char *format, void *pBuffer, UINT *pcbBuffer, UINT cbMaxBuffer, LPARAM *plChoice = NULL);
virtual void BeginRead();
virtual void EndRead(BOOL bCommit);
virtual BOOL Eof();

// Overwrite TOutput methods
public:
virtual UINT Write(char * buffer, UINT nCount);
};

///////////////////////////////////////////////////////////////////////////

#endif __TIO_H