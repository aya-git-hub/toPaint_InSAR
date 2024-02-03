#ifndef __SHOWFRAME_H__
#define __SHOWFRAME_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include "wx/treectrl.h"
#include "wx/listctrl.h"
////Header Include End

////Dialog Style Start
#undef MyFrame_STYLE
#define MyFrame_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX


#include "paintFrm.h"
class Complex;
class showFrame : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		showFrame(paintFrm *parents, wxWindow *parent, wxWindowID id = 2, const wxString &title = wxT("show"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(1200, 800), long style = paintFrm_STYLE);
		virtual ~showFrame() {delete picture;} 
		void MyFrameActivate(wxActivateEvent& event);
		void openFile();
		

	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
            void OnPaint(wxPaintEvent& event);
            paintFrm *parent_;
            char filechar[100];//用char*储存的文件名 
            Complex *picture;//图片保存数据 
		
};

#endif
