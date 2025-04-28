<%@ page contentType="text/html; charset=Big5" %>
<HTML>
<HEAD>
<TITLE>選擇鈕的使用</TITLE>
</HEAD>
<BODY>
<CENTER>
<FONT SIZE = 5 COLOR = blue>選擇鈕的使用</FONT>
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
<!--取得rdoJob選擇鈕的傳出值-->
<%= request.getParameter("rdoJob") %>
</FONT>
</H3>

</BODY>
</HTML>
