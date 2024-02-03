#include "showframe.h"
#include "paintFrm.h"
#include "complex.h"
BEGIN_EVENT_TABLE(showFrame,wxFrame)
	////Manual Code Start
	EVT_PAINT(showFrame::OnPaint)
	////Manual Code End
END_EVENT_TABLE()



showFrame::showFrame(paintFrm *parents, wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
    {
        parent_ = parents;// parent_ 记录父窗口指针 
        openFile();
     CentreOnParent();
    }
    
void showFrame::openFile()
{
    strcpy(filechar , parent_ -> filestr.c_str() );//将 wxString 转换为 char* 
    parent_->f = fopen( filechar , "rb");
    
    if( parent_->f == NULL ) //make sure the file is exist 
	{
	 	wxMessageBox(wxT("open error "),wxT("error"),wxOK,this);
	}
    else
    {
        wxMessageBox(wxT("open successfully !!! "),wxT("yes"),wxOK,this);
        
    fseek(parent_->f, 0, SEEK_END); //计数 
	int len = ftell(parent_->f);
	fseek(parent_->f, 0, SEEK_SET);//
	
	wxString a = wxString::Format(wxT("%d"),len);
	wxMessageBox(a,wxT("error"),wxOK,this);
	
    picture= new Complex(len);
	len=len/4;
	while( (len) > 0 )
	{
	 fread( picture->preal++ , 4, 1, parent_->f);
	 fread (picture->pimag++ , 4, 1, parent_->f);
	 len -= 2;
	}
	picture->getPhase();
	fclose(parent_->f);
	
	//测试数据是否正确 
	/*FILE *g= fopen("user1.txt","w");
	int aya;
	int byb;
	for(aya=0;aya<1250;aya++)
	{
			for(byb=0;byb<1250;byb++)
		{
			fprintf(g,"%f ",picture->phase[aya][byb]);
			//fprintf(g,"%d ",byb);
		}
		fprintf(g,"\n");
	}
	fclose(g);*/
	
	
    }
    
    
    
	
}
