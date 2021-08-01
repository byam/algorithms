# strings

- [strings](#strings)
  - [文字を数値に変換 (& その逆)](#文字を数値に変換--その逆)
  - [String に String あるかを判定する](#string-に-string-あるかを判定する)

## 文字を数値に変換 (& その逆)

* to Int
```cpp
string str = "1234";

cout << str[0] - '0' << endl; // 1

cout << stoi(str) << endl; // 1234
```

* to String
```cpp
int num = 1234;

cout << to_string(num) << endl; // "1234"
```

## String に String あるかを判定する

```cpp
string str ("There are two needles in this haystack.");
string str2 ("needle");

if (str.find(str2) != string::npos) {
//.. found.
}
```
