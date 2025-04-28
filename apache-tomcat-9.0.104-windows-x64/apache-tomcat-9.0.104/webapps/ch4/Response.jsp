<%@ page contentType="text/html; charset=Big5" %>
<HTML>
<HEAD>
<TITLE>從客戶端傳送資料至伺服端</TITLE>
</HEAD>
<BODY>
<CENTER>
<FONT SIZE = 5 COLOR = BLUE>回應表單動作的JSP檔</FONT>
</CENTER>
<HR>
<P></P>
<CENTER>
<H2>
<FONT COLOR = RED>
<!--取得tbxName控制項的傳出值-->
<%= request.getParameter("tbxName") %>
</FONT>
您好!
</H2>
</CENTER>
</BODY>
</HTML>
