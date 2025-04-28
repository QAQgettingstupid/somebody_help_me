<%@ page contentType="text/html; charset=Big5" %>
<HTML>
<HEAD>
<TITLE>多選型清單方塊的使用</TITLE>
</HEAD>
<BODY>
<CENTER>
<FONT SIZE = 5 COLOR = blue>多選型清單方塊的使用</FONT>
</CENTER>
<HR>
<P></P>

<H3>
<FONT COLOR = RED>
<!--取得tbxName文字方塊的輸入值-->
<%= request.getParameter("tbxName") %>
</FONT>
欲訂購<BR>

<%
//取得lbxBook控制項的傳出值, 傳出值為一字串陣列
String selAry[] = request.getParameterValues("lbxBook");

//取得陣列的長度
int selArylen = selAry.length;

//利用for迴圈將selAry陣列中的元素取出, 並利用if判斷敘述進行比對
for(int i = 0; i < selArylen; i++)
{
	%>
	<FONT COLOR = BROWN>
	<%
	//利用if敘述比對selAry字串陣列中的值
	if (selAry[i].equals("A9073"))
		out.println("Access 2003 徹底研究");
	else if (selAry[i].equals("A9193"))
		out.println("Access 2003 程式設計");		
	else if (selAry[i].equals("A0053"))
		out.println("Access 2003 網路應用");		
	else if (selAry[i].equals("P3237"))
		out.println("Visual C++ .NET 入門進階");
	else if (selAry[i].equals("P3207"))
		out.println("精通視窗程式設計");		
	%>
	</FONT>
	(書號:<FONT COLOR = GREEN>
	<!--輸出字串陣列中各元素的值-->
	<%= selAry[i] %>
	</FONT>)<BR>
	<%	
}
%>
</H3>
</FONT>

(表單的傳出值
<FONT COLOR = GREEN>
<!--輸出lbxBook控制項的傳出值-->
<%= request.getQueryString() %>
</FONT>)

</BODY>
</HTML>
