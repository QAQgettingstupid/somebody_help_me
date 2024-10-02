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

## printf()
![螢幕擷取畫面 2024-10-02 140317](https://github.com/user-attachments/assets/05fe05df-caf5-4c86-a25a-06632ec85697)


## 理論篇

### java編譯->直譯過程
![視窗程式設計-1](https://github.com/user-attachments/assets/92dd5a6a-5750-4bc4-981f-12cdd185a44d)


-   **原因 :** 小數點型態java會自動用double存,float精度小於double只好手動在數值尾端加上**f**強行轉換用float存取

-   **例子 :**

    ```
    float num = 6.123456;  //錯誤-->float型態用double儲存矛盾
    float num = 6.123456f; //正確
    ```
