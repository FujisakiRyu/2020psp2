# 課題4 レポート

aa83988848 薗田光太郎

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明


## 入出力結果

例えば，ID 45313125のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313125
---
ID : 45313125
gender : Female
height : 152.4
```

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```

## 修正履歴

[comment0725宮下]
- 実装はOKです。ソースコードの説明を追加してください。

[comment #20200804 sonoda]
- 45313124の入力のとき，No dataと出力されません．

[comment #20200811 sonoda]
- 関数の中に数字はなるべく書きません．数字の代わりに，
  ```
  #define Num 14
  ```
  というのを main関数の前に書きます．意味としては14という文字列にNumという別名をつけることになります．これを使って，
  main関数のなかに出てくる，14や15を，NumやNum+1と書くようにします．
- 時間が無いので，この修正を前提に，この課題は完了とします．