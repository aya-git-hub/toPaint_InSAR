//---------------------------------------------------------------------------
//
// Name:        paintApp.h
// Author:      msi-pc
// Created:     2022/4/22 19:32:08
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __PAINTFRMApp_h__
#define __PAINTFRMApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class paintFrmApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
