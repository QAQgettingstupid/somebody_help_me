<%@ page contentType="text/html; charset=UTF-8" 
    import="java.util.HashMap,java.util.Map,java.util.Stack"%>

    <% 
        //所有page共用文字框
        String ans = request.getParameter("text");
        
        // 計算所需結構
        Map<Character, Integer> priority = new HashMap<>();
        priority.put('-', 1);
        priority.put('+', 1);
        priority.put('/', 2);
        priority.put('*', 2);
        Stack<Character> operator = new Stack<>();
        Stack<Double> operand = new Stack<>();
        Double temp_num;
        int index = 0, numfront = 0;
        boolean negative = false, changed = false;
        
        //初始化文字框
        if(ans == null) 
            ans="";

       //清除功能     
       if(request.getParameter("clear") !=null) 
            ans="";
    
       //判斷被觸發的按鍵
       String button=request.getParameter("bt"); 

       // 0~9, + - * / .
       if(button !=null && !button.equals("="))
            ans += button;
       
       // "="計算
       else if(ans != null && ans != ""){
        // 逐個讀取輸入字元
        while (index < ans.length()) {
            if (changed == false
                    && (ans.charAt(index) == '.' || (ans.charAt(index) <= '9' && ans.charAt(index) >= '0'))) {
                numfront = index;
                changed = true;
            } else if (ans.charAt(index) == '+' || ans.charAt(index) == '-' || ans.charAt(index) == '*'
                    || ans.charAt(index) == '/' || ans.charAt(index) == '(' || ans.charAt(index) == ')') {

                // 放入數字
                if (changed) {
                    temp_num = Double.parseDouble(ans.substring(numfront, index));
                    if (negative) {
                        operand.push(temp_num * (-1));
                        negative = false;
                    } else
                        operand.push(temp_num);
                    changed = false;
                }

                // 負號
                if (ans.charAt(index) == '-'
                        && (index == 0
                                || (index - 1 >= 0
                                        && (ans.charAt(index - 1) == '+' || ans.charAt(index - 1) == '('
                                                || ans.charAt(index - 1) == '*' || ans.charAt(index - 1) == '-'
                                                || ans.charAt(index - 1) == '/')))) {
                    negative = true;
                    index++;
                    continue;
                }

                else {

                    // 輸入優先權小於等於stack top,先pop進行運算
                    while (!operator.empty()
                            && priority.get(operator.peek()) >= priority.get(ans.charAt(index))) {

                        Character c = operator.peek();
                        Double result = 0.0;
                        Double back = operand.peek();
                        operand.pop();
                        Double front = operand.peek();
                        operand.pop();
        
                        switch (c) {
                            case '+':
                                result = front + back;
                                break;
                            case '-':
                                result = front - back;
                                break;
                            case '*':
                                result = front * back;
                                break;
                            case '/':
                                result = front / back;
                                break;
                        }
                        operand.push(result);
                        operator.pop();
                    }
                    operator.push(ans.charAt(index));
                }
            }
            index++;
        }
        if (changed) {
            temp_num = Double.parseDouble(ans.substring(numfront, index));
            if (negative) {
                operand.push(temp_num * (-1));
                negative = false;
            } else
                operand.push(temp_num);
        }

        // 檢查是否還有運算子尚未運算
        while (!operator.empty()) {
            Character c=operator.peek();
            Double result = 0.0;
            Double back = operand.peek();
            operand.pop();
            Double front = operand.peek();
            operand.pop();

            switch (c) {
                case '+':
                    result = front + back;
                    break;
                case '-':
                    result = front - back;
                    break;
                case '*':
                    result = front * back;
                    break;
                case '/':
                    result = front / back;
                    break;
                    }
            operand.push(result);
            operator.pop();
        }
        ans = Double.toString(operand.peek());
       }
       %>
        <HTML>

        <HEAD>
            <TITLE>小算盤</TITLE>
        </HEAD>

        <BODY>
            <form method="post" action="calculator.jsp">
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