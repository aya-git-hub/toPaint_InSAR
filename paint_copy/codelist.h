/*
wxNullColour - 一个空的、无效的颜色。
wxTransparentColour - 有效但完全透明的颜色（2.9.1 中的新颜色）。
wxBLACK
wxBLUE
wxCyan
wxGREEN
wxYELLOW
wxLIGHT_GREY
wxRED
wxWHITE

用于格式输出wxString 
1)
wxString str;
str.Printf(wxT("%d %d %d"), 1, 2, 3);

2)
wxString a = wxString::Format(wxT("%d"),len);


用于转换 wxString->char*
1)
strcpy(filechar , filestr.c_str() ) 

用于转换 char*->wxString
const char * str = "abc";
wxString::FromUTF8("abc");//返回 wxString 实例，值为"abc"
wxString::FromUTF8(str);

*/
wxColour (unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha= wxALPHA_OPAQUE )
