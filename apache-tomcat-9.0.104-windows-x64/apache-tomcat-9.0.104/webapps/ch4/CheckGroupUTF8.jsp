<%@ page contentType="text/html; charset=utf-8" %>
<HTML>
<HEAD>
<TITLE>群組核取方塊的使用</TITLE>
</HEAD>
<BODY>
<CENTER>
<FONT SIZE = 5 COLOR = blue>群組核取方塊的使用</FONT>
</CENTER>
<HR>

<H3>
您想到下面這些地方玩呀!<BR>
<UL>
<FONT COLOR = RED>

<%
//利用request物件的getParameterValues方法,
//取得群組核取方塊的傳出值,並設定給chkbx字串陣列
String chkbx[] = request.getParameterValues("chkbx");

//利用java.lang.reflect套件Array物件的getLength方法取得陣列長度
int len = java.lang.reflect.Array.getLength(chkbx);

//利用for迴圈輸出群組核取方塊傳出的值
for(int i = 0; i < len ; i++)
	out.println("<LI>" + chkbx[i] + "</LI>");	
%>

</FONT>
</UL>
</H3>
</FONT>

(表單的傳出值
<FONT COLOR = GREEN>
<!--輸出表單的傳出字串, 並利用java.net套件URLDecoder物件的
    decode方法, 解譯字串-->
<%= java.net.URLDecoder.decode(request.getQueryString(), "UTF-8") %>
</FONT>)

</BODY>
</HTML>
