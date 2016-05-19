#ifndef __SWIFTAPP_H
#define __SWIFTAPP_H

class TInput;
class TOutput;

BOOL SkipSwiftMessage(TInput * pInput, TOutput * pOutput);
FILE * OpenSourceStream(char *);
int RenameSourceStream(char *);
FILE * OpenDestStream(char *);

void SwiftExport(char *pszDSN, char *pszUID, char *pszAuthStr, char *pszExport, IDLEFUNC fnIdle);
void SwiftImport(char *pszDSN, char *pszUID, char *pszAuthStr, char *pszImport, char *pszClear, char *pszError, IDLEFUNC fnIdle);

#endif // __SWIFTAPP_H
