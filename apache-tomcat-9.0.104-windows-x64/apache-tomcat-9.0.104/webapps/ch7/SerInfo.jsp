<%@ page contentType="text/html; charset=Big5"%>
<HTML>
<HEAD>
<TITLE>���o���A���P�귽�����</TITLE>
</HEAD>
<BODY>
<CENTER>
<FONT SIZE = 5 COLOR = blue>���o���A���P�귽�����</FONT>
</CENTER>
<HR>
<P></P>
<%-- �H�U�N�z�L--%>
Servlet�e�������� : <%= application.getServerInfo() %><BR>
Servlet�e�����D�n���� : 
<%= application.getMajorVersion() %><BR>
Servlet�e�������n���� :
 <%= application.getMinorVersion() %><BR><BR>
<%
JspFactory factory = JspFactory.getDefaultFactory();
%>
JSP�e�������� : 
<%= factory.getEngineInfo().getSpecificationVersion() %>
<BR><BR>
</BODY>
</HTML>
