# ft_printf

C言語のprintf関数の再実装。以下のものに対応している。

※フォーマット指定子[%d %i]に関しては現在対応中

- フォーマット指定子 [%c %s %p %u %% %x %X]
- フラグ ['#' '0' '-' ' ' '+']
- 最小フィールド幅 (*にも対応)
- 精度 (*にも対応)

# 実行方法

printfを含めたアーカイブファイルlibftprintf.aの作成

```
make
```

テストの実行

```
cd tester
make
```

実行ファイルおよび中間ファイルの消去

```
make fclean
```

# フラグとフォーマット指定子

自作printf関数において受け付ける型は以下の通りである。

```
%[フラグ][最小フィールド幅].[精度][フォーマット指定子]
```

以下に対応したフラグとその説明について示す。

| フラグ | 説明 |
| :-: | :-: |
| "#" | フォーマット指定子が%x・%Xの時に、先頭に0x・0Xを付加する。 |
| "0" | 値の左側を空白ではなく0埋めする。 |
| "-" | 値を左揃えで出力する。 |
| " " | 正の数において+符号の代わりに空白を出力する。 |
| "+" | 正の数において+符号を出力する。 |

各フォーマット指定子について、得られる出力と型、対応しているフラグについてまとめたものを記す。

ここで、最小フィールド幅は最低限出力する文字数を示し、変換した結果がその長さ以下であった場合は、左側が空白で埋められる。また、精度は、整数型では最低表示桁数を示し、足りない場合は0埋めされる。

| 指定子 | 型 | 出力 | "#" | "0" | "-" | " " | "+" | 最小フィールド幅 | 精度 |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
| %c | char | 文字を出力 | × | × | ○ | × | × | ○ | × |
| %s | char * | 文字列を出力 | × | × | ○ | × | × | ○ | ○ |
| %p | uintptr_t | アドレスを出力 | × | × | ○ | × | × | ○ | × |
| %d | int | 整数を10進数で出力 | × | ○ | ○ | ○ | ○ | ○ | ○ |
| %i | int | 整数を10進数で出力 | × | ○ | ○ | ○ | ○ | ○ | ○ |
| %u | unsigned int | 整数を符号なし10進数で出力 | × | ○ | ○ | × | × | ○ | ○ |
| %% | char | アドレスを出力 | × | × | ○ | × | × | ○ | × |
| %x | unsigned int | 整数を符号なし16進数（小文字）で出力 | ○ | ○ | ○ | × | × | ○ | ○ |
| %X | unsigned int | 整数を符号なし16進数（大文字）で出力 | ○ | ○ | ○ | × | × | ○ | ○ |
