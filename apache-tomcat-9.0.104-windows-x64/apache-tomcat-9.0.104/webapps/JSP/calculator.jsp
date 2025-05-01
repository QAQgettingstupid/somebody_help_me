<%@ page contentType="text/html; charset=UTF-8" 
    import="java.util.HashMap,java.util.Map,java.util.Stack"%>

    <% String ans=request.getParameter("text"); if(ans==null) ans="" ; 
       if(request.getParameter("clear") !=null) ans="" ;
       String button=request.getParameter("bt"); if(button !=null) ans +=button;%>
        <HTML>

        <HEAD>
            <TITLE>小算盤</TITLE>
        </HEAD>

        <BODY>
            <form method="post" action="calculator.jsp">

                bt= <%= button %>
                    text= <%= ans %>
                        <%--介面--%>
                            <p><input type="text" value="<%=ans %>" name="text"></p>

                            <p><input type="submit" value="1" name="bt">
                                <input type="submit" value="2" name="bt">
                                <input type="submit" value="3" name="bt">
                                <input type="submit" value="+" name="bt">
                            </p>

                            <p>
                                <input type="submit" value="4" name="bt">
                                <input type="submit" value="5" name="bt">
                                <input type="submit" value="6" name="bt">
                                <input type="submit" value="-" name="bt">
                            </p>

                            <p>
                                <input type="submit" value="7" name="bt">
                                <input type="submit" value="8" name="bt">
                                <input type="submit" value="9" name="bt">
                                <input type="submit" value="*" name="bt">
                            </p>

                            <p>
                                <input type="submit" value="." name="bt">
                                <input type="submit" value="0" name="bt">
                                <input type="submit" value="/" name="bt">
                                <input type="submit" value="=" name=bt>
                            </p>

                            <p><input type="submit" value="清除" name=clear></p>
            </form>
        </BODY>

        </HTML>