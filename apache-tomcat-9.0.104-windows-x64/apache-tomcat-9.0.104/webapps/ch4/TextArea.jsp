<%@ page contentType="text/html; charset=Big5" %>
<HTML>
<HEAD>
<TITLE>文字區的使用範例</TITLE>
</HEAD>
<BODY>
<CENTER>
<FONT SIZE = 5 COLOR = blue>文字區的使用範例</FONT>
</CENTER>
<HR>
<P></P>

<H3>
<FONT COLOR = RED>
<!--取得tbxNsame文字方塊的輸入值-->
<%= request.getParameter("tbxName") %>
</FONT>
說...<BR>
<!--取得txtaMsg文字區的輸入值-->
<%= request.getParameter("txtaMsg") %>
</H3>

</BODY>
</HTML>
