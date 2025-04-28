<%@ page contentType="text/html; charset=Big5" %>
<HTML>
<HEAD>
<TITLE>透過request物件取得表頭資訊</TITLE>
</HEAD>
<BODY>
<CENTER>
<FONT SIZE = 5 COLOR = BLUE>透過request物件取得表頭資訊</FONT>
</CENTER>
<HR>
<P></P>
<FONT COLOR = RED>
<%--運用request物件取得表頭資訊--%>
request.getContentType() :<%= request.getContentType() %><BR>

<%--運用request物件取得表頭資訊--%>
<% 
java.util.Enumeration headers; //宣告headers為Enumeration物件

//透過request物件的getHeadNames()方法，取得所有表頭資訊的名稱，
//該方法將傳回一個Enumeration物件，運用for迴圈配合nextElement()方法
//與hasMoreElements()方法輸出所有表頭資訊
for( headers = request.getHeaderNames(); headers.hasMoreElements(); ) {
	String name = headers.nextElement().toString();
	out.print("request.getHeader(\"");
	out.print(name);
	out.print("\") : ");
	out.print(request.getHeader(name));
	out.print("<BR>\n"); 
}
%>
request.getRemoteAddr() :<%= request.getRemoteAddr() %><BR>
request.getRemoteHost() :<%= request.getRemoteHost() %><BR>
request.getRemoteUser() :<%= request.getRemoteUser() %><BR>
request.getMethod() :<%= request.getMethod() %><BR>
request.getRequestURI() :<%= request.getRequestURI() %><BR>
request.getRequestURL() :<%= request.getRequestURL() %><BR>
request.getQueryString() :<%= request.getQueryString() %><BR>

</FONT>
</BODY>
</HTML>
