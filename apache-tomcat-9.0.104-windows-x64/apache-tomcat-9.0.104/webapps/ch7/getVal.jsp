<%@ page contentType="text/html; charset=Big5"
	import="java.util.Enumeration"%>

<FONT color=red>Radio button的值：<%= request.getParameter("radio") %></FONT>
<HR>

<%
Enumeration e = pageContext.getAttributeNamesInScope(PageContext.APPLICATION_SCOPE);
//從pageContext物件取得儲存在application物件內變數

String name = "";

//運用while迴圈與Enumeration物件的方法輸出application物件內的變數
while(e.hasMoreElements()){
	name = (String) e.nextElement();
	out.println("<DIV style='background=skyblue'><Font color=red>");
	out.println(name);
	out.println(" : </Font>");
	out.println(pageContext.getAttribute(name, PageContext.APPLICATION_SCOPE));
	out.println("</DIV><P></P>");
}
%>

