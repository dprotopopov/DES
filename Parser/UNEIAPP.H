#ifndef __UNEIAPP_H
#define __UNEIAPP_H

FILE * UneiOpenDestStream(char *pszFileName, char *pszExtension);
void UneiExport(char *pszDSN, char *pszUID, char *pszAuthStr, char *pszExport, char *pszUnei, IDLEFUNC fnIdle);

#endif // __UNEIAPP_H