<%@ page contentType="text/html; charset=Big5" buffer="16kb"%>
<HTML>
<HEAD>
<TITLE>緩衝區的操作</TITLE>
</HEAD>
<BODY>
<CENTER>
<FONT SIZE = 5 COLOR = blue>緩衝區的操作</FONT>
</CENTER>
<HR>
<P></P>

原緩衝區的大小為
<%= response.getBufferSize() %>
bytes<BR>
<%
response.setBufferSize(8*1024);
//更改緩衝區大小, 設定8 kb, 1 kb等於1024 bytes
%>
更改後為<%= response.getBufferSize() %> bytes<BR>
<%
//下面的迴圈，將輸出100000行字串於網頁中
for(int i = 0; i <= 100000; i++)
{
	out.println("[迴圈第" + i + "次執行]");
	//將字串輸出至緩衝區
	
	if (response.isCommitted())
	{
		out.println("<BR>資料從緩衝區中輸出<BR>");
		break;
	}
}
%>

</BODY>
</HTML>
