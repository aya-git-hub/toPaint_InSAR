#include "paintFrm.h"
#include "wx/msgdlg.h"
#include <string>
#include <cstring>
#include <time.h> 
#include <cmath> 
#include "showframe.h"
#include "complex.h"
 
void delay_ms(int ms)
{
	clock_t start = clock();
	while (clock() - start < ms);}

void paintFrm::OnButtonOK(wxCommandEvent& event)
{     
    
    if (  ( filestr.IsNull() ) )
    {
        wxMessageBox(wxT("Please input your file name! "),wxT("error"),wxOK,this);// make sure you have inputed the file name
    }
    else
    {         
     showFrame *frame_1=new showFrame(this, this);
     frame_1->Show();
    }
    
}

void showFrame::OnPaint(wxPaintEvent& event)
{

    if (  ( parent_ -> filestr.IsNull() ) )
    {
        wxMessageBox(wxT("please input your file name! "),wxT("error"),wxOK,this);//make sure you have inputed the file name and the file is exist
    }
    else
    {
        picture->toNormalize();
    //wxString str = wxString::Format(wxT("%d"),isbutton); 
    //wxMessageBox(str,wxT("123"),wxOK,this);用来测试messge 
    wxPaintDC s(this);
    //wxPaintDC s(this);
    s.SetDeviceOrigin (0, 0);
    wxBufferedDC dc(&s,wxSize(600,600));
    float Temperature;
    char Red,Green,Blue;
    //(new wxColour(i,j,i+j))
    for( int i = 0; i < 2; i+=1)
    {
        for( int j = 0; j < 2; j+=1)
        {   
            
            Temperature = ( picture->norm[i][j] ) * (40000-1000)+1000;
             wxString stt = wxString::Format(wxT("%f"),Temperature);      
     wxMessageBox(wxT("end"),stt,wxOK,this); 
// caculate red            
            if( Temperature <= 66)
            {
                Red = 255;
            }
            else
            {
                Red = Temperature - 60;
                Red = 329.698727446 * pow(Red, -0.1332047592);
                if ( Red < 0 )  Red = 0;
                if ( Red > 255 )Red = 255;
            }
 // caculate green
            if (Temperature <= 66) 
            {
             Green = Temperature;
             Green = 99.4708025861 * log(Green) - 161.1195681661;
             if (Green < 0)  Green = 0;
             if (Green > 255) Green = 255;
            }
            else
             {
               Green = Temperature - 60;
                Green = 288.1221695283 *pow (Green ,-0.0755148492);
                if ( Green < 0)  Green = 0;
                if ( Green > 255)  Green = 255;
              }
// caculate blue       
            if ( Temperature >= 66)
            {  
                Blue = 255;
             }
 
            else
            {
                 if ( Temperature <= 19 )
                  Blue = 0;
                 else
 	              {
            	    Blue = Temperature - 10;
            	    Blue = 138.5177312231 * log(Blue) - 305.0447927307;
            	    if (Blue < 0)  Blue = 0;
	               }
                }  
 //Red = (int) (Red+0.5);
 //Green = (int)(Green+0.5);
//Blue = (int) (Blue+0.5);     
        
            
            wxColour c0l0ur(Red,Green,Blue);
            wxPen pen(c0l0ur ,1); 
            dc.SetPen(pen);
            dc.DrawPoint( i, j);
            dc.SetPen(wxNullPen);             
        }
            
    }//isbutton
  }
  wxMessageBox(wxT("end"),wxT("end"),wxOK,this);
}




/*可以丢到onPaint 
// wxMessageBox(str,wxT("123"),wxOK,this);
  /* wxClientDC s(this);
    //wxPaintDC s(this);
    s.SetDeviceOrigin (00, 00);
    wxBufferedDC dc(&s,wxSize(200,200));
    wxPen pen1( *wxBLUE, 1);
    wxPen pen2( *wxRED, 1);
    wxPen pen3( *wxYELLOW, 1);
    wxPen pen4( *wxCYAN, 1);
    wxPen pen5( *wxBLACK, 1);
    
    
    //(new wxColour(i,j,i+j))
    for( int i = 1; i < 200; i+=2)
    {
        for( int j = 1; j < 200; j+=2)
        {   
            wxColour c0l0ur(i,j,i+j);//r g b
            wxPen pen(c0l0ur ,1); 
            dc.SetPen(pen);
            dc.DrawPoint( i, j);
            dc.SetPen(wxNullPen); 
            
            
        } 
    }*/

/*switch((i+j)%5)
            {
            case 0://wxPen pen( *wxBLUE, 1); 
            dc.SetPen( pen1);
            dc.DrawPoint( i, j);
            dc.SetPen(wxNullPen); break;
            
            case 1://wxPen pen( *wxRED, 1);
            dc.SetPen( pen2);
            dc.DrawPoint( i, j);
            dc.SetPen(wxNullPen); break;
            
            case 2://wxPen pen( *wxYELLOW, 1);
            dc.SetPen( pen3);
            dc.DrawPoint( i, j);
            dc.SetPen(wxNullPen); break;
            
            case 3:
            dc.SetPen( pen4);
            dc.DrawPoint( i, j);
            dc.SetPen(wxNullPen); break;
            
            case 4:
            dc.SetPen( pen5);
            dc.DrawPoint( i, j);
            dc.SetPen(wxNullPen); break;
           }*/







