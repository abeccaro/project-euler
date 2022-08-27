As we all know the equation $x^2 = -1$ has no solutions for real $x$.<br>
If we however introduce the imaginary number $i$ this equation has two solutions: $x=i$ and $x=-i$.<br>
If we go a step further the equation $(x-3)^2=-4$ has two complex solutions: $x=3+2i$ and $x=3-2i$.<br>
$x=3+2i$ and $x=3-2i$ are called each others' complex conjugate.<br>
Numbers of the form $a+bi$ are called complex numbers.<br>
In general $a+bi$ and $a−bi$ are each other's complex conjugate.<br><br>
A Gaussian Integer is a complex number $a+bi$ such that both $a$ and $b$ are integers.<br>
The regular integers are also Gaussian integers (with $b=0$).<br>
To distinguish them from Gaussian integers with $b\neq0$ we call such integers "rational integers."<br>
A Gaussian integer is called a divisor of a rational integer $n$ if the result is also a Gaussian integer.<br>
If for example we divide $5$ by $1+2i$ we can simplify $\dfrac{5}{1+2i}$ in the following manner:<br>
Multiply numerator and denominator by the complex conjugate of $1+2i$: $1−2i$.<br>
The result is $\displaystyle\frac{5}{1+2i} = \frac{5}{1+2i}\frac{1-2i}{1-2i} = \frac{5(1-2i)}{1-(2i)^2} = \frac{5(1-2i)}{1-(-4)} = \frac{5(1-2i)}{5} = 1-2i$.<br>
So $1+2i$ is a divisor of $5$.<br>
Note that $1+i$ is not a divisor of $5$ because $\displaystyle\frac{5}{1+i} = \frac{5}{2}-\frac{5}{2}i$.<br>
Note also that if the Gaussian Integer (<wbr>$a+bi$) is a divisor of a rational integer $n$, then its complex conjugate (<wbr>$a−bi$) is also a divisor of $n$.<br><br>
In fact, $5$ has six divisors such that the real part is positive: $\lbrace 1, 1 + 2i, 1 − 2i, 2 + i, 2 − i, 5\rbrace$.<br>
The following is a table of all of the divisors for the first five positive rational integers:<br>
<table align="center">
  <thead>
    <tr>
      <th>$n$</th>
      <th>Gaussian integer divisors <br>with positive real part</th>
      <th>Sum $s(n)$ of <br>these divisors</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>$1$</td>
      <td>$1$</td>
      <td>$1$</td>
    </tr>
    <tr>
      <td>$2$</td>
      <td>$1, 1+i, 1-i, 2$</td>
      <td>$5$</td>
    </tr>
    <tr>
      <td>$3$</td>
      <td>$1, 3$</td>
      <td>$4$</td>
    </tr>
    <tr>
      <td>$4$</td>
      <td>$1, 1+i, 1-i, 2, 2+2i, 2-2i, 4$</td>
      <td>$13$</td>
    </tr>
    <tr>
      <td>$5$</td>
      <td>$1, 1+2i, 1-2i, 2+i, 2-i, 5$</td>
      <td>$12$</td>
    </tr>
  </tbody>
</table>
For divisors with positive real parts, then, we have: $\displaystyle\sum_{1}^{5} s(n) = 35$.<br><br>
For $\displaystyle\sum_1^{10^5} s(n) = 17924657155$.<br><br>
What is $\displaystyle\sum_{1}^{10^8} s(n)$?
