from bs4 import BeautifulSoup, NavigableString

# 讀取 HTML 檔案
input_path = r"C:\Users\好人\Desktop\入門到入墳\somebody_help_me\挖書好難\try.html"

output_path = r"C:\Users\好人\Desktop\入門到入墳\somebody_help_me\挖書好難\test_10.html"  # 處理後的檔案名稱

# 打開 HTML 檔案
with open(input_path, "r", encoding="utf-8") as file:
    html = file.read()

# 使用 BeautifulSoup 解析 HTML
soup = BeautifulSoup(html, 'html.parser')

# 將 body 的內容轉換成多個 <p>
soup_add = BeautifulSoup("<p></p>", 'html.parser')
tag = soup.body.content

new_contents = []
print(soup.body)

new_tag = soup.new_tag("p")
for contents in soup.body.contents:
    print(contents)
    print("yes")
    new_tag.append(contents)
    new_contents.append(new_tag)
    new_tag = soup.new_tag("p")

# 替換 body 的內容

soup.body.contents = new_contents
print("test")
print(soup.body)

# 寫入處理後的 HTML 檔案
with open(output_path, "w", encoding="utf-8") as file:
    file.write(str(soup))

print(f"處理完成！輸出檔案: {output_path}")
