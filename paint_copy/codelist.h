/*
wxNullColour - һ���յġ���Ч����ɫ��
wxTransparentColour - ��Ч����ȫ͸������ɫ��2.9.1 �е�����ɫ����
wxBLACK
wxBLUE
wxCyan
wxGREEN
wxYELLOW
wxLIGHT_GREY
wxRED
wxWHITE

���ڸ�ʽ���wxString 
1)
wxString str;
str.Printf(wxT("%d %d %d"), 1, 2, 3);

2)
wxString a = wxString::Format(wxT("%d"),len);


����ת�� wxString->char*
1)
strcpy(filechar , filestr.c_str() ) 

����ת�� char*->wxString
const char * str = "abc";
wxString::FromUTF8("abc");//���� wxString ʵ����ֵΪ"abc"
wxString::FromUTF8(str);

*/
wxColour (unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha= wxALPHA_OPAQUE )
