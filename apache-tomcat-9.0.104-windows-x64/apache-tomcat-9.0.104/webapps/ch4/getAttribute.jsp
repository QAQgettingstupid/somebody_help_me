<%@ page contentType="text/html; charset=Big5"%>
<HTML>
<HEAD>
<TITLE>request變數</TITLE>
</HEAD>
<BODY>
<CENTER>
<FONT SIZE = 5 COLOR = blue>request變數</FONT>
</CENTER>
<HR>
<P></P>
<%
//從request物件中取得資料
String var = request.getParameter("var");
String val = (String) request.getAttribute(var);

if(val == null)
{
	%>
	<Font color=red>無法</Font>從request物件取得變數資料
	<%
}
else
{
	%>
	<Font color=red>可以</Font>從request物件取得變數<Font color=red><%= var %></Font>的資料,<BR>
	其值為<Font color=red><%= val %></Font>
	<%
}
%>

</BODY>
</HTML>
