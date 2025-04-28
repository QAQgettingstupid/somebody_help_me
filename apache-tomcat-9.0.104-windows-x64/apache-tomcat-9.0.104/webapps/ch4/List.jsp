<%@ page contentType="text/html; charset=Big5" %>
<HTML>
<HEAD>
<TITLE>清單方塊的使用範例</TITLE>
</HEAD>
<BODY>
<CENTER>
<FONT SIZE = 5 COLOR = blue>清單方塊的使用範例</FONT>
</CENTER>
<HR>
<P></P>

<H3>
<FONT COLOR = RED>
<!--取得tbxName文字方塊的輸入值-->
<%= request.getParameter("tbxName") %>
</FONT>
欲訂購
<FONT COLOR = BROWN>
<%
//取得lbxBook清單方塊的傳出值
String selVal = request.getParameter("lbxBook");

//利用if敘述比對selVal的值
if (selVal.equals("A9073"))
	out.println("Access 2003 徹底研究");
else if (selVal.equals("A9193"))
	out.println("Access 2003 程式設計");		
else if (selVal.equals("A0053"))
	out.println("Access 2003 網路應用");		
else if (selVal.equals("P3237"))
	out.println("Visual C++ .NET 入門進階");
else if (selVal.equals("P3207"))
	out.println("精通視窗程式設計");	
%>
</FONT>
(書號為
<FONT COLOR = GREEN>
<!--取得lbxBook清單方塊的傳出值-->
<%= request.getParameter("lbxBook") %>
</FONT>)

</H3>

</BODY>
</HTML>
