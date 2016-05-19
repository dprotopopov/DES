#ifndef __THASH_H
#define __THASH_H

class THashArray
{
protected:
char *m_array[0x100];

public:
THashArray(char **ppItem);
~THashArray();

virtual BOOL InHashArray(char *);
virtual char * GetData(char *);

protected:
virtual UINT HashFunction(char *);
virtual UINT RehashFunction(UINT, char *);
};


#endif // __THASH_H