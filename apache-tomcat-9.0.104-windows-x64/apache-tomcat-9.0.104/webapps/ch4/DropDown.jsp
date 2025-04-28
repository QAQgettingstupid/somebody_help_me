<%@ page contentType="text/html; charset=Big5" %>
<HTML>
<HEAD>
<TITLE>下拉清單的使用範例</TITLE>
</HEAD>
<BODY>
<CENTER>
<FONT SIZE = 5 COLOR = blue>下拉清單的使用範例</FONT>
</CENTER>
<HR>
<P></P>

<H3>
<FONT COLOR = RED>
<!--取得tbxName文字方塊的輸入值-->
<%= request.getParameter("tbxName") %>
</FONT>
您是一位
<FONT COLOR = BROWN>
<!--取得slbJob下拉清單方塊的傳出值-->
<%= request.getParameter("slbJob") %>
</FONT>
</H3>

</BODY>
</HTML>
