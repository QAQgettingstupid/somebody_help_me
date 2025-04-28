<%@ page contentType="text/html; charset=Big5" %>
<HTML>
<HEAD>
<TITLE>核取方塊的使用</TITLE>
</HEAD>
<BODY>
<CENTER>
<FONT SIZE = 5 COLOR = blue>核取方塊的使用</FONT>
</CENTER>
<HR>

<H3>
您想到下面這些地方玩呀!<BR>
<UL>
<FONT COLOR = RED>
<%
//下面的if敘述將判斷chbx1核取方塊是否傳出值
//若有傳出值，則代表該核取方塊被選取
if (request.getParameter("chkbx1") != null)
	out.println("<LI>日本</LI>");	

if (request.getParameter("chkbx2") != null)
	out.println("<LI>美國</LI>");

if (request.getParameter("chkbx3") != null)
	out.println("<LI>加拿大</LI>");

if (request.getParameter("chkbx4") != null)
	out.println("<LI>韓國</LI>");

if (request.getParameter("chkbx5") != null)
	out.println("<LI>澳洲</LI>");
%>
</FONT>
</UL>
</H3>

(表單的傳出值
<FONT COLOR = GREEN>
<!--輸出lbxBook控制項的傳出值-->
<%= request.getQueryString() %>
</FONT>)

</BODY>
</HTML>