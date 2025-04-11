from bs4 import BeautifulSoup, NavigableString, Tag

# 讀取 HTML 檔案
input_path = r"C:\Users\好人\Desktop\入門到入墳\somebody_help_me\挖書好難\try.html"
output_path = r"C:\Users\好人\Desktop\入門到入墳\somebody_help_me\挖書好難\test_10.html"  # 處理後的檔案名稱

# 打開 HTML 檔案
with open(input_path, "r", encoding="utf-8") as file:
    html = file.read()

# 使用 BeautifulSoup 解析 HTML
soup = BeautifulSoup(html, 'html.parser')

# 將 body 的內容轉換成多個 <p>
new_contents = []

# 創建新的 <p> 標籤來包裝內容
new_tag = soup.new_tag("p")

for contents in soup.body.contents:
    if isinstance(contents, NavigableString):  # 如果是純文字
        # 去除文字兩邊的空白並加入新 <p> 標籤中
        text = contents.strip()
        if text:  # 只有非空的文字才會被加入
            new_tag.string = text
            new_contents.append(new_tag)
            new_tag = soup.new_tag("p")  # 為下一段創建新的 <p> 標籤
    elif isinstance(contents, Tag):  # 如果是標籤，直接附加
        new_contents.append(contents)

# 替換 body 的內容
soup.body.contents = new_contents

# 寫入處理後的 HTML 檔案
with open(output_path, "w", encoding="utf-8") as file:
    file.write(str(soup))

print(f"處理完成！輸出檔案: {output_path}")
