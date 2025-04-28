<%@ page contentType="text/html; charset=Big5"%>
<HTML>
<HEAD>
<TITLE>request變數</TITLE>
</HEAD>
<BODY>
<CENTER><FONT SIZE = 5 COLOR = blue>request變數</FONT></CENTER>
<HR>
<P>
<%
if(request.getParameter("var")==null || request.getParameter("val")==null) 
{ //若無法取得rdochc控制項值則顯示表單
%>
	<Form Action="Request.jsp" method=POST>
		輸入變數名稱:<INPUT type="text" name="var"><br>
		輸入變數值:<INPUT type="text" name="val"><br>
		<INPUT type="submit" value="送出">
		<INPUT type="reset" value="清除">
	</Form>
<%
}
else
{
    //設定request物件的Num變數的值
	request.setAttribute(request.getParameter("var"), request.getParameter("val"));	
%>
	<jsp:forward page="getAttribute.jsp"/>
<%  //將網頁forward至getAttribte.jsp網頁
}
%>
</BODY>
</HTML>
