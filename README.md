# SolarLetters
ローマ字とかなの変換をします。

かなローマ字テーブルの、順序がメチャクチャなのは、テーブル参照の時の優先順位を付けているからです。順番を変えると動かなくなったりします。  
母音の前の「n」には、「'」を付ける記法です。値渡しをする時は、シェルで解釈されるので、バックスラッシュでエスケープして下さい。  

Compile: cc sl.c -o sl  

Usage (1):　かなからローマ字に変換  
./sl じゅんあい  
実行結果：　jun'ai  

Usage(2):　ローマ字からかなに変換  
./sl jun\'ai  
実行結果：　じゅんあい  

最初の文字がアルファベットだったら、ローマ字からかなに変換する関数を呼び出し、  
違っていれば、かなからローマ字に変換する関数を呼び出すので、名前は同じです。

