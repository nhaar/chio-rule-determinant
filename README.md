
# プログラムについて / About the Program

このC++プログラムはブラジルで言われる「Chiòの法則」を使って正方行列の行列式を計算する。Chiòの法則は簡単にいうと、「１」の要素を含む行列は「ある方法」を使って次元を削減できる、つまりｎｘｎの
行列が（n-1)ｘ(n-1)の行列になる。その削減された行列は元の行列と同じな行列式を持つ。もし「１」が含まれていないなら、行列の列に操作を実行することで、「１」を含む別の行列ができ、法則を使って新しい
行列の行列式を見つけ、その新しい行列式がどのように変化したことを調べて調整して、元の行列式も計算できる。

「Chiòの法則」はよく考えたら、ガウスの消去法と同じプロセスだ。つまりこのアルゴリズムはガウスの消去法とのちょっと違うアプローチ。正直、この法則はあまり役に立たないことで、ブラジルの教育以外で参照がすくない。ガウスの消去法はとても直感的なプロセスで、この法則はとてもミステリアスで行列式をさらに複雑させてしまう教え方だと思う。なんで「１」が必要か、その「削減方法」はなんで効くかわからずにメカニック的なアプローチで結局教育的に便利じゃない。だからそんな法則がブラジルに教えられるのも批判のところかもしれない。結局、このプログラムが面白いかと思ってアプロードしたかった！

This C++ program uses what's known in Brazil as "Chiò's Rule" to compute the determinant of a matrix. Put it short, Chiò's rule says that given a matrix that includes the element "1",
one can use an algorithm to find a smaller matrix that has the same determinant as the original one, for example, given a n x n matrix, you end up with a (n-1)x(n-1) matrix.
If the matrix doesn't have the element 1 in it, then you can carry out row operations to get a new matrix that has the element 1, and find that new matrix's determinant, applying corrections
depending on what we changed so that we can retrieve the determinant of the original matrix. The program is written using C++ with Japanese identifier names.

If you think about it, "Chiò's Rule" is really just the same as Gaussian Elimination, and this algorithm is just an alternative approach to that method. To be honest, I don't think this rule is very useful, and I couldn't find any references to it outside of Brazilian literature. Gaussian Elimination is a very intuitive process and this rule is very misterious and I think it just makes the topic of determinants more complicated than it needs to be. It is a mechanical approach where you don't get to think about why there needs to be a 1 or why the reduction method works, and it's not very useful useful didactically. So it's a possible point of criticism to Brazilian education as to why it's sometimes taught. Regardless, I thought this program was funny.
