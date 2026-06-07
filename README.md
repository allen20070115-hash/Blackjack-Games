# 文化大學 物件導向程式設計期末專題

## 小組資訊:

- 組別:第八組
- 系級班級:資工1A
- 組員:陳亮錡，鄭鈞成，吳任凱


## 小專題題目 : 二十一點

## 功能說明:

### 下注:
- 開始遊戲前點擊按鈕選擇下注金額
- 點擊下注前不能發牌

### 發牌停牌:
- 按H發牌，S停牌
- 玩家點數大於莊家點數贏得小局，玩家增加注金、莊家扣除注金
- 玩家點數超過21點或小於莊家點數則輸掉小局，玩家扣除注金、莊家增加注金
- 兩者相等則平局，持有金額不變動

### 勝負判斷:
- 若玩家或莊家其一身上無籌碼則該方為敗者，另一為勝者，按下ESC鍵退出遊戲


## 程式介紹:

### 物件:
- 將程式分裝成各個檔案

### 封裝:
- 將大部分變數設為private，避免外部程式直接修改到變數

### 多載:
- 將coin設為Coin()和Coin(int v)提升程式的靈活度


## 程式使用方式:

### 下載程式碼解壓縮後打開main.exe即可運行


## 程式編譯

### 安裝VSCode及擴充套件
- 點開左側的擴充套件欄
- 搜尋並安裝C/C++ Extension Pack套件

### 前往MSYS2官網下載並安裝

### 將 MinGW 加入 Windows 環境變數
- 在搜尋列搜尋環境變數，並開啟「編輯系統環境變數」
- 點擊下方的「環境變數」按鈕
- 在「系統變數」區塊中找到 Path並雙擊打開
- 點擊「新增」，輸入 MSYS2 MinGW 64-bit 的路徑(預設是C:\msys64\mingw64\bin)
- 點擊「確定」關閉所有視窗

### 安裝SFML
- 打開MSYS2終端機
- 輸入「pacman -S mingw-w64-x86_64-sfml」
- 輸入y按下Enter

### 修改task.json
- 打開專案資料夾下的 .vscode/tasks.json
- 找到 "args" 陣列，並在 "${file}" 後方加入"-lsfml-graphics","-lsfml-window","-lsfml-system"三組參數
- Ctrl+S儲存


## 運行畫面截圖

<img width="1598" height="1079" alt="21" src="https://github.com/user-attachments/assets/5d1fd21b-220d-4bb1-a517-cb101f336632" />

## UML

<img width="1493" height="840" alt="655635643154637" src="https://github.com/user-attachments/assets/b43f60ef-854f-4c92-ab74-ca4ca79130e2" />




## 小組分工

### 陳亮錡:程式主架構撰寫，簡報製作
### 鄭鈞成:UML圖，程式測試，button撰寫
### 吳任凱:README撰寫，程式測試，coin撰寫
