<%@ page contentType="text/html; charset=Big5"%>
<HTML>
<BODY>
<CENTER>
<FONT SIZE = 5 COLOR = blue>
以pageContext object取得位於application object的資料</FONT>
</CENTER>
<HR>
<P>
<%
String radio = request.getParameter("radio");

if(radio == null)
{
%>
<FORM name="form1" method="get" action="pageContext.jsp">
  <INPUT Type=radio name="radio" value="Include">pageContext.include()<p>
  <INPUT Type=radio name="radio" value="Forward">pageContext.forward()<p>
  <INPUT Type=submit name="s1" value="確定"><p>
</FORM>
<%
}
else
{
  if(radio.equals("Include"))
  {
    pageContext.include("getVal.jsp"); //引入getVal.jsp執行結果
  }
  else
  {
    pageContext.forward("getVal.jsp"); //getVal.jsp執行結果取代pageContext.jsp
  }
}
%>
</BODY>
</HTML>
