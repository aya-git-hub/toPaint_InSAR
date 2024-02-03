#include "paintFrm.h"
#include "wx/numdlg.h"
#include "wx/textdlg.h"

void paintFrm::OnFilename(wxCommandEvent& event)
{
    wxTextEntryDialog dialog(this,
            
            wxT("Please input the filename that you want to open"),
            wxT("To open your file"),
            //wxT("Default value"),
            wxT("diff.itf"),
            wxOK | wxCANCEL);


    if (dialog.ShowModal() == wxID_OK)
    {
     //wxString 
      filestr=dialog.GetValue();
      
     //wxMessageBox(str,wxT("123"),wxOK,this);
    }
}
