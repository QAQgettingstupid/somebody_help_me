<%@ page contentType="text/html; charset=Big5"%>
<HTML>
<HEAD>
<TITLE>取得伺服器與資源的資料</TITLE>
</HEAD>
<BODY>
<CENTER>
<FONT SIZE = 5 COLOR = blue>取得伺服器與資源的資料</FONT>
</CENTER>
<HR>
<P></P>
<%-- 以下將透過--%>
Servlet容器的版本 : <%= application.getServerInfo() %><BR>
Servlet容器的主要版本 : 
<%= application.getMajorVersion() %><BR>
Servlet容器的次要版本 :
 <%= application.getMinorVersion() %><BR><BR>
<%
JspFactory factory = JspFactory.getDefaultFactory();
%>
JSP容器的版本 : 
<%= factory.getEngineInfo().getSpecificationVersion() %>
<BR><BR>
</BODY>
</HTML>
