<%@ page contentType="text/html; charset=Big5" %>
<HTML>
<HEAD>
<TITLE>隱藏欄位的使用</TITLE>
</HEAD>
<BODY>
<CENTER>
<FONT SIZE = 5 COLOR = blue>隱藏欄位的使用</FONT>
</CENTER>
<HR>
<P></P>

<%
//利用Time控制項是否有傳出值判斷該顯示題目還是該計算答案
//若Time控制項有傳出值時, request.getParameter("Time")將不會為null
if (request.getParameter("Time") == null)
{
%>
	<!--下面的表單將以Post方法, 將資料傳遞給Hidden.asp檔 -->
	<FORM action="Hidden.jsp" method=post name=FORM1>
	<!--此為隱藏欄位, 其預設值為系統時間, 並轉換為毫秒數-->
	<INPUT type=hidden name=Time 
			value="<%= new java.util.Date().getTime() %>">	
	<!--第一題-->
	<P>巴拿馬運河連接的是那兩大洋?</P>
	<P>
	<INPUT type="radio" name=rdoQ1 value=1>太平洋與大西洋
	<INPUT type="radio" name=rdoQ1 value=2>大西洋與印度洋
	<INPUT type="radio" name=rdoQ1 value=3>印度洋與太平洋
	</P>
	
	<!--第二題-->
	<P>馬雅文明位於那一洲?</P>
	<P>
	<INPUT type="radio" name=rdoQ2 value=1>北美洲
	<INPUT type="radio" name=rdoQ2 value=2>南美洲
	<INPUT type="radio" name=rdoQ2 value=3>歐洲
	<INPUT type="radio" name=rdoQ2 value=4>亞洲
	<INPUT type="radio" name=rdoQ2 value=5>非洲
	</P>
	
	<!--第三題-->
	<P>美國的首都是那一個城市?</P>
	<P>
	<INPUT type="radio" name=rdoQ3 value=1>紐約
	<INPUT type="radio" name=rdoQ3 value=2>舊金山
	<INPUT type="radio" name=rdoQ3 value=3>西雅圖
	<INPUT type="radio" name=rdoQ3 value=4>華盛頓
	</P>
	
	<!--第四題-->
	<P>位於臺灣與菲律賓間的海峽是?</P>
	<P>
	<INPUT type="radio" name=rdoQ4 value=1>臺灣海峽
	<INPUT type="radio" name=rdoQ4 value=2>直布羅陀海峽
	<INPUT type="radio" name=rdoQ4 value=3>麻六甲海峽
	<INPUT type="radio" name=rdoQ4 value=4>巴士海峽
	</P>
	
	<!--第五題-->
	<P>阿里山位於臺灣的那個縣?</P>
	<P>
	<INPUT type="radio" name=rdoQ5 value=1>嘉義縣
	<INPUT type="radio" name=rdoQ5 value=2>台北縣
	<INPUT type="radio" name=rdoQ5 value=3>雲林縣
	<INPUT type="radio" name=rdoQ5 value=4>屏東縣
	</P>

	<INPUT type="submit" value="我答完了" name=submit1>
	</FORM>
<%
}
//若Time控制項有傳出值表示應進行答案的計算
else
{
	int RightAns = 0; //計算答對的題數
	int aryAns[] = {1,2,4,4,1}; //建立儲存正確答案的陣列

	//下面的for迴圈中, 將利用if判斷式進行答案的比對
	for(int i = 0;  i < 5 ; ++i)
	{
		//建立控制項名稱的字串
		String conname = "rdoQ" + (i+1);	
		
		//判斷是否可取得控制項傳出的資料, 無法取得將傳出null
		if(request.getParameter(conname) == null)
		{
			%>
			第<%= i + 1%>題您<FONT COLOR = GREEN>未做答</Font><BR>
			<%
		}
		else
		{
			%>
			第<%= i + 1%>題您答
			<%
			//取得使用者所做答的答案			
			int Ans = Integer.parseInt(request.getParameter(conname));

			//比對控制項回傳值與陣列中的正確答案, 相同表答對反之答錯
			if( Ans == aryAns[i])
			{			
				RightAns = RightAns + 1; //答對題數加 1
				%>
				<FONT COLOR = GREEN>對</FONT>了<BR>
				<%
			}
			else
			{
				%>
				<FONT COLOR = RED>錯</FONT>了<BR>
				<%
			}
		}
	}
	%>
	<H3>
	五題中您共答對了
	<FONT COLOR = RED>
	<!--輸出答對的題數-->
	<%= RightAns %>
	</FONT>
	題, 花了
	<FONT COLOR = RED>
	<!--輸出計算所得的答題所花時間-->
	<%= 
	((new java.util.Date()).getTime() - Long.parseLong(request.getParameter("Time")))/1000
	%>
	</FONT>
	秒
	</H3>
<%
}
%>

</BODY>
</HTML>
