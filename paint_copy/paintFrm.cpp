///-----------------------------------------------------------------
///
/// @file      paintFrm.cpp
/// @author    aya
/// Created:   2022/4/22 19:32:09
/// @section   DESCRIPTION
///            paintFrm class implementation
///
///------------------------------------------------------------------

#include "paintFrm.h"
#include "wx_id.h"
//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
#include "wx/numdlg.h"
#include "wx/textdlg.h"
////Header Include End

//----------------------------------------------------------------------------
// paintFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(paintFrm,wxFrame)
	////Manual Code Start
	EVT_MOTION(paintFrm::OnMotion)
	EVT_BUTTON(wxID_OK, paintFrm::OnButtonOK)
	EVT_BUTTON(wxID_HELP, paintFrm::OnQuit)	
	EVT_BUTTON(WXID_CHECK, paintFrm::OnCheck)	
    EVT_MENU(wxID_NEW, paintFrm::OnFilename)
    EVT_MENU(WXID_ABOUT, paintFrm::OnAbout)
	////Manual Code End
	EVT_CLOSE(paintFrm::OnClose)
END_EVENT_TABLE()
////Event Table End

paintFrm::paintFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
    
    wxMenu *fileMenu = new wxMenu;   
    wxMenu *helpMenu = new wxMenu;
     
    fileMenu->Append( wxID_NEW ,wxT("&AddFile\tAlt-X"),wxT("Input the file name"));   
    helpMenu->Append( WXID_ABOUT ,wxT("&About\tAlt-A"),wxT("Input the file name"));  
    
    wxMenuBar *menuBar = new wxMenuBar();   
    menuBar->Append(fileMenu, wxT("&File")); 
    menuBar->Append(helpMenu, wxT("&Help")); 
    SetMenuBar(menuBar); 
    
   
    wxButton *button = new wxButton(this, wxID_OK, wxT("GO"),wxPoint(10,200),wxSize(100,60));//只用一个按钮会填充 
    wxButton *button2 = new wxButton(this, wxID_HELP, wxT("OFF"),wxPoint(200,200),wxSize(100,60));
    wxButton *button3 = new wxButton(this, WXID_CHECK, wxT("CHECK"),wxPoint(400,200),wxSize(100,60));

    CreateGUIControls();
    
   //while(str.IsNull());
   
   
}

paintFrm::~paintFrm()
{
}

void paintFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	SetTitle(_("paint"));
	SetIcon(wxNullIcon);
	SetSize(8,8,1200,940);
	Center();

	////GUI Items Creation End
}


void paintFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}

void paintFrm::OnQuit(wxCommandEvent& event)
{
    Close();
}

void paintFrm::OnCheck(wxCommandEvent& event)
{
    if    ( !(filestr.IsNull()))
    {
        wxMessageBox(filestr,wxT("Your file name"),wxOK,this);   
    }
    else
    {
        wxMessageBox(wxT("There isn't any exist file, please add. "),wxT("error"),wxOK,this);
    }
}

void paintFrm:: OnAbout(wxCommandEvent& event)
    {
     wxString introduce = wxString::Format(wxT("Version:1.0.0\nAuthor:aya\nEnjoy!\n"));
     wxMessageBox( introduce , wxT("About") , wxOK , this); 
    } 






