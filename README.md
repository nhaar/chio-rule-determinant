
# プログラムについて / About the Program

このC++プログラムはブラジルで言われる「Chiòの法則」を使って正方行列の行列式を計算する。Chiòの法則は簡単にいうと、「１」の要素を含む行列はある方法を使って次元を削減できる、つまりｎｘｎの
行列が（n-1)ｘ(n-1)の行列になる。その削減された行列は元の行列と同じな行列式を持つ。もし「１」が含まれていないなら、行列の列に操作を実行することで、「１」を含む別の行列ができ、法則を使って新しい
行列の行列式を見つけ、その新しい行列式がどのように変化したことを調べて調整して、元の行列式も計算できる。

This C++ program uses what's known in Brazil as "Chiò's Rule" to compute the determinant of a matrix. Put it short, Chiò's rule says that given a matrix that includes the element "1",
one can use an algorithm to find a smaller matrix that has the same determinant as the original one, for example, given a n x n matrix, you end up with a (n-1)x(n-1) matrix.
If the matrix doesn't have the element 1 in it, then you can carry out row operations to get a new matrix that has the element 1, and find that new matrix's determinant, applying corrections
depending on what we changed so that we can retrieve the determinant of the original matrix. The program is written using C++ with Japanese identifier names.
