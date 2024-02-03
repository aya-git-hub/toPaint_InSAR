#include <string.h>
#include "paintFrm.h"
void conwxStrToCharp(wxString wxStr, char *&p)
 {
    const char* ps = (const char*)wxStr.mb_str(wxConvUTF8);	
    int len = strlen(ps);	
    p = new char[len + 1];	
    strcpy(p, ps);
 }
