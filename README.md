parsepath(パス文字列からディレクトリ名やファイル名を取得)
========================================================
Linuxでパス文字列からディレクトリ名やファイル名を分割取得するのに、各要素を解析取得するC言語の関数を作ってみたので紹介する。

概要
----
Linuxではディレクトリ名やファイル名を取得する `dirname()` や `basename()` 関数が使えるが、どうも所望の結果が得られなかったり、引数のパス領域が書き換えられたりする。そこで、文字列からファイル名要素を抽出するC言語の関数を作成。

本関数の特徴は、入力した文字列を解析して、各要素の開始ポインタ位置を戻す。又、戻り値でどの要素が存在してるかを知ることができる。入力した文字列は参照のみで非破壊なので、不要なコピー領域をmallocなどで確保しておかなくても必要な要素のみを抽出できる。

下記URLのブログ記事で紹介してしている内容のファイル。

* <https://www.yokoweb.net/dokuwiki/programing/linux-programing/file-splitpath-parse>

コンパイル方法
--------------------
コンパイルする。実行ファイル「`sample`」が作られる。
```
$ make
```

生成したファイルを削除する。

```
$ make clean
```

実行方法
--------
生成した実行ファイルを実行。

```
$ ./sample /testdir/test.tst
dir=/testdir/, base=test.tst
```

* 引数で与えた文字列を、ディレクトリ名とベース名に分割して表示。
* カレントディレクトリのファイルを実行するには、「./」を付ける必要がある。

Doxygenによるドキュメント生成
-----------------------------
ドキュメント生成。

```
$ doxygen
```

結果は「html/」フォルダに出力されてるので、その中の `index.html` をブラウザで開く。

### Doxygenに関する記事
下記URLのブログ記事でDoxygenについて紹介している。

* <https://www.yokoweb.net/2020/06/29/ubuntu-linux-doxygen-install/>
* <https://www.yokoweb.net/2020/02/18/macos-doxygen-install/>
* <https://www.yokoweb.net/2020/02/21/msys2-doxygen-install/>
* <https://www.yokoweb.net/2020/03/01/windows-doxygen-install/>

梱包ファイル
-----------------

* `README.md`   ・・・本説明ファイル
* `_parsepath.c`・・・関数本体
* `_parsepath.h`・・・関数のヘッダ
* `sample1.c`   ・・・関数を使ったサンプルC言語ソース
* `Makefile`    ・・・サンプルmakeファイル
* `Doxyfile`    ・・・Doxygenの設定ファイル

来歴
----

* 2020/06/28 新規作成(By T.Yokobayashi)

