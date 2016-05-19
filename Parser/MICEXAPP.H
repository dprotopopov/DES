#ifndef __MICEXAPP_H
#define __MICEXAPP_H

void MicexExport(char *pszDSN, char *pszUID, char *pszAuthStr, char *pszExport, IDLEFUNC fnIdle);
void MicexImport(char *pszDSN, char *pszUID, char *pszAuthStr, char *pszImport, char *pszClear, char *pszError, IDLEFUNC fnIdle);

#endif // __MICEXAPP_H
