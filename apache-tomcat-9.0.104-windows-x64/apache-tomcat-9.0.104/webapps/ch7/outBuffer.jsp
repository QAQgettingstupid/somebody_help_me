<%@ page contentType="text/html; charset=Big5" buffer="16kb"%>
<HTML>
<HEAD>
<TITLE>�w�İϪ��ާ@</TITLE>
</HEAD>
<BODY>
<CENTER>
<FONT SIZE = 5 COLOR = blue>�w�İϪ��ާ@</FONT>
</CENTER>
<HR>
<P></P>

��w�İϪ��j�p��
<%= response.getBufferSize() %>
bytes<BR>
<%
response.setBufferSize(8*1024);
//���w�İϤj�p, �]�w8 kb, 1 kb����1024 bytes
%>
���ᬰ<%= response.getBufferSize() %> bytes<BR>
<%
//�U�����j��A�N��X100000��r��������
for(int i = 0; i <= 100000; i++)
{
	out.println("[�j���" + i + "������]");
	//�N�r���X�ܽw�İ�
	
	if (response.isCommitted())
	{
		out.println("<BR>��Ʊq�w�İϤ���X<BR>");
		break;
	}
}
%>

</BODY>
</HTML>
