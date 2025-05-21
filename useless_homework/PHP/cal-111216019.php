<!--作者:蔡芳宇 -->
<!--學號:111216019 -->
<!--自評:80%+20% 會動,但幾乎沒有例外處理_(:3 」∠ )_ -->
<!--話說這副檔名上傳後會自己改phps不知道為什麼,明明我傳的是php? -->
<html>

<head>
    <title>小算盤</title>
</head>

<body>
    <?php
        //所有page共用文字框內容
        if(!isset($_POST['text']))
            $ans = "";
        else
            $ans = $_POST['text'];

        //清除功能     
        if(isset($_POST['clear']) && $_POST['clear'] !==null) 
            $ans = "";
            
        //判斷被觸發的按鍵
        if(isset($_POST['bt']) && $_POST['bt'] !==null){
            $button = $_POST['bt'];     

            // 計算所需結構
            $priority = [
                '-' => 1,
                '+' => 1,
                '/' => 2,
                '*' => 2,
            ];

            $operator = [];
            $operand = [];
            $temp_num = 0;
            $index = 0;
            $numfront = 0;
            $negative = false;
            $changed = false;

            // 四則運算
            function calculate(&$operand, $c){
            $result = 0.0;
            $back = end($operand);
            array_pop($operand);
            $front = end($operand);
            array_pop($operand);

            switch ($c) {
                case '+':
                    $result = $front + $back;
                    break;
                case '-':
                    $result = $front - $back;
                    break;
                case '*':
                    $result = $front * $back;
                    break;
                case '/':
                    if($back == 0){
                        echo "除數不能為0\n";
                        $result = "error";
                        break;
                    }
                    else{
                        $result = $front / $back;
                        break;
                    }
            }
            return $result;
            }

            // 0~9, + - * / .
            if(($button || $button === "0") && $button !== "=")
                $ans .= $button; 
            
            // "="計算
            else if($ans !== null && $ans !== ""){
                // 逐個讀取輸入字元
                while ($index < strlen($ans)) {
                    if ($changed == false
                            && ($ans[$index] == '.' || ($ans[$index] <= '9' && $ans[$index] >= '0'))) {
                        $numfront = $index;
                        $changed = true;
                    } else if ($ans[$index] == '+' || $ans[$index] == '-' || $ans[$index] == '*'
                            || $ans[$index] == '/' || $ans[$index] == '(' || $ans[$index] == ')') {
                    
                    // 放入數字
                    if ($changed) {
                        $temp_num = substr($ans, $numfront, $index - $numfront);
                        if ($negative) {
                            array_push($operand, $temp_num * (-1));
                            $negative = false;
                        } else
                            array_push($operand, $temp_num);
                        $changed = false;
                    }

                    // 負號
                    if ($ans[$index] == '-' && ($index == 0 || 
                    ($index - 1 >= 0 && ($ans[$index - 1] == '+' || $ans[$index - 1] == '(' 
                    || $ans[$index - 1] == '*' || $ans[$index - 1] == '-' 
                    || $ans[$index - 1] == '/')))) {
                        $negative = true;
                        $index++;
                        continue;
                    }

                    else {
                    // 輸入優先權小於等於stack top,先pop進行運算
                        while ($operator 
                        && $priority[end($operator)] >= $priority[$ans[$index]]) {
                            $count_num = calculate($operand, end($operator));
                            if($count_num == "error"){
                                $ans = "";
                                $operand = [];
                                $operator = [];
                                break;
                            }
                            array_push($operand,$count_num);
                            array_pop($operator);
                        }
                        array_push($operator,$ans[$index]);
                    }
                    }
                    $index++;
                }
                if ($changed) {
                    $temp_num = substr($ans, $numfront, $index - $numfront);
                    if ($negative) {
                        array_push($operand, $temp_num * (-1));
                        $negative = false;
                    } else
                        array_push($operand, $temp_num);
                }

                // 檢查是否還有運算子尚未運算
                while ($operator) {
                    $count_num = calculate($operand, end($operator));
                    if($count_num == "error"){
                        $ans = "";
                        $operand = [];
                        $operator = [];
                        break;
                        }
                    array_push($operand,$count_num);
                    array_pop($operator);
                }
                $ans = end($operand);
            }
        }
    ?>
    <form method="POST" action="cal-111216019.php">
        <!-- 介面 -->
        <p><input type="text" value="<?= $ans ?>" name="text"></p>

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
</body>

</html>