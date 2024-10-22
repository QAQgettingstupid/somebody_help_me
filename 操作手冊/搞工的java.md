## class

### instance : 由class型態所建立的object(物件)

### static

- 相同class下由不同instance共用
  
#### 函式

- 可由class或instance調用

- 由class調用不需先建立instance

- 不可調用沒有static的函式(即instance專用),因為調用static函式不一定會有instance(如由class調用)

****************************************

### 無static 

- 相同class下不同instance不共用各自獨立

#### 函式

- 只能由instance調用 **(需先new一個instance)**
- 
****************************************

### this

-   **用途 :** 在class中指出當前的instance

### 建構子互相調用



-    **this()和super()不可同時使用!!!!!!!!!**

-    **this()和super()使用時需放在第一行!!!!!!!!!**


-   **例子:**
  
    ```
    class CCircle {
      private double radius;
    
      public CCircle() {
          this(4.5); //不可寫成CCircle(4.5);
      }
    
      public CCircle(double r) {
        radius = r;
      }
    }
    ```

## 函式(不需建物件就可直接使用)

- **用法 :**

  ```
  public static 型態 名稱(參數){
  
        //內容
  
  }
  ```
    
-   **例子 :**

  ```
  public static void add(int a[]){
  
      for (int i = 0; i < a.length; i++)
        a[i] += 10;
  }
  ```
## 陣列

- **用法 :**
  
    ```
    型態[] 名稱;
    名稱 = new 型態[大小];
    
    或
    
    型態[] 名稱 = new 型態[大小]; 
    ```
-   **例子 :**

    ```
    int[] a;
    a = new int[4];
    
    int[] b = new int[4];
    ```

- **內部原理 :**
 
    ![阿我就沒白紙-1](https://github.com/user-attachments/assets/965b33e3-e155-43ce-9825-2d75611fc7a3)
  
-   **垃圾特點 :**

     不可移動陣列記憶體位置取值

     int[] b = new int[4]; //b+1取b[1]在java不可行 *(因為他們覺得指標很麻煩只用參考(reference)反而用起來變得更麻煩www)*

### 陣列初始化

-   **例子 :**

    ```
    int[] b = {0,1,2,3,4,5}; //不用加new,因為系統會自己分配適量的記憶體大小
    ```

### .length

-   **用途 :** 回傳陣列元素個數

-   **用法 :** 陣列名稱.length

### for each(陣列走訪)

-   **用法 :** for(型態 名稱 : 要走訪的陣列名稱)

    **(for each中負責遍歷的那個型態是複製品,對其改變不會影響原始樣本!!!!!!!!!!)**

-   **例子 :**

    一維

    ```
    int[] a = { 0, 1, 5, 4 };

    for (int temp : a)
        System.out.print(temp + " ");
        //輸出結果--> 0 1 5 4
    ```

   二維

   ```
   int[][] a = { { 32, 35, 26, 30 }, { 34, 30, 33, 31 } };

   for (int[] r : a)
       for (int c : r)
           System.out.print(c + " ");
           //輸出結果--> 32 35 26 30 34 30 33 31
   ```

## ? :

-   **用途 :** 更簡略的判斷式(c++也有)

-   **用法 :** 要放入結果的變數 = 判斷式 ? 結果1 : 結果2; **(當判斷式為true取結果1的值, false則取結果2的值)**

-   **例子 :**

    ```
    int b = (2*2 == 4) ? 35 : 53;
    
    System.out.print(b);
    //輸出結果--> 35
    ```  

## Scanner (java版的cin)

- **import java.util.Scanner;** 要先引入

- **用法 :**

  ```
  Scanner 名稱 = new Scanner(System.in);  // 宣告Scanner類別的物件

  型態別 name = Scanner物件的名稱.next(放入的資料型態)();  // 接收資料

  scn.close();   // 將scn關閉(建議,但沒做也不會發生什麼事www)
  ```

-   **例子 :**

    ```
    Scanner scn=new Scanner(System.in);  // 宣告Scanner類別的物件

    String name=scn.next();     // 輸入字串
    int age=scn.nextInt();      // 輸入整數

    scn.close();                 // 將scn關閉
    ```
![螢幕擷取畫面 2024-10-02 143808](https://github.com/user-attachments/assets/ff4ce987-cbea-44e3-88dc-0c73d85aaad3)

## 自動型別轉換

- **使用時機 :** 通常在數值運算時

- **規則 :** 僅可由較大的資料型態傳換到較小的資料型態 (**ex.** short可轉int ,但int不可轉short)

- **特殊 :** char(character)不可轉short **(char->0~65535)** **(short->-32768~32767)**

## L (long type)

-   **用途 :** 當資料型態大於int **(-2,147,483,648 ~ 2,147,483,647)** 需在數值尾端加上**L**

-   **原因 :** 小於等於int的型態java會自動用int大小存,超過int大小只好手動在數值尾端加上**L**強行轉換用long **(-9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807)** 存取

-   **例子 :**

    ```
    int num = 600L; //錯誤-->int型態不能儲存long(2的64次方)量的數值
    int num = 600; //正確
    
    long width = 12345678900;   //錯誤-->long大於int但沒在數值尾端加上手動變換
    long width = 12345678900L; //正確
    
    ```

## f (float type)

-   **用途 :** 當資料型態為float時需在數值尾端加上**f**

-   **原因 :** 小數點型態java會自動用double存,float精度小於double只好手動在數值尾端加上**f**強行轉換用float存取

-   **例子 :**

    ```
    float num = 6.123456;  //錯誤-->float型態用double儲存矛盾
    float num = 6.123456f; //正確
    ```

## printf() (格式碼控制)
![螢幕擷取畫面 2024-10-02 140317](https://github.com/user-attachments/assets/05fe05df-caf5-4c86-a25a-06632ec85697)
    
-   **型別字元 :**

    | 符號 | d | f | s | c |
    |-------|:-----:|:------:|:------:|:------:|
    | 意義 | 10進位整數 | 浮點數 | 字串 | 字元 |

    **"0" 和 "-" 會衝突,不可同時使用!!!!!!!!!!!**

    **除了 "%" 和型別字元其他均為選填!!!!**
    
-   **用法 :** System.out.printf("格式碼", 要控制的資料或來源);

-   **例子 :**

    ```
    byte bt=65;         
    float ft=3.14f;
    
    System.out.printf("oct=%o, hex=%x\n",bt, bt);  // 不同格式碼之間的 "," 非必要,若有打輸出時會出現
    //輸出結果--> oct=101, hex=41

    System.out.printf("%-5d %-5d %-5d %-5d %-5d %-5d %-5d\n",30,1,2,3,4,5,6); //沒加 ","
    //輸出結果--> 30    1     2     3     4     5     6
    ```
## 跟c++比更機車的差異

- **bool要打全名boolean**

- **while(1)無法執行**
  
    不能在while()或if()括弧內放入單純數字, java不會自行轉換成boolean ~~*(超廢www)*~~
  
## 理論篇

### java編譯->直譯過程
![視窗程式設計-1](https://github.com/user-attachments/assets/92dd5a6a-5750-4bc4-981f-12cdd185a44d)
