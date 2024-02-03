//---------------------------------------------------------------------------
//
// Name:        paintApp.cpp
// Author:      msi-pc
// Created:     2022/4/22 19:32:08
// Description: 
//
//---------------------------------------------------------------------------

#include "paintApp.h"
#include "paintFrm.h"
#include "wx/numdlg.h"

IMPLEMENT_APP(paintFrmApp)
DECLARE_APP(paintFrmApp) 
 short isbutton = 0;
bool paintFrmApp::OnInit()
{
    //std::cout<<"hellow"<<std::endl; 
    paintFrm* frame = new paintFrm(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int paintFrmApp::OnExit()
{
	return 0;
}

