A composite number can be factored many different ways. For instance, not including multiplication by one, $24$ can be factored in $7$ distinct ways:

$\qquad\qquad\qquad24 = 2\times2\times2\times3$<br>
$\qquad\qquad\qquad24 = 2\times3\times4$<br>
$\qquad\qquad\qquad24 = 2\times2\times6$<br>
$\qquad\qquad\qquad24 = 4\times6$<br>
$\qquad\qquad\qquad24 = 3\times8$<br>
$\qquad\qquad\qquad24 = 2\times12$<br>
$\qquad\qquad\qquad24 = 24$<br>

Recall that the digital root of a number, in base $10$, is found by adding together the digits of that number, and repeating that process until a number is arrived at that is less than $10$. Thus the digital root of $467$ is $8$.<br>

We shall call a Digital Root Sum (DRS) the sum of the digital roots of the individual factors of our number.<br>
The chart below demonstrates all of the DRS values for $24$.

<table align="center">
  <thead>
    <tr>
      <th>Factorisation</th>
      <th>Digital Root Sum</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td align="center">$2\times2\times2\times3$</td>
      <td align="center">$9$</td>
    </tr>
    <tr>
      <td align="center">$2\times3\times4$</td>
      <td align="center">$9$</td>
    </tr>
    <tr>
      <td align="center">$2\times2\times6$</td>
      <td align="center">$10$</td>
    </tr>
    <tr>
      <td align="center">$4\times6$</td>
      <td align="center">$10$</td>
    </tr>
    <tr>
      <td align="center">$3\times8$</td>
      <td align="center">$11$</td>
    </tr>
    <tr>
      <td align="center">$2\times12$</td>
      <td align="center">$5$</td>
    </tr>
    <tr>
      <td align="center">$24$</td>
      <td align="center">$6$</td>
    </tr>
  </tbody>
</table>

The maximum Digital Root Sum of $24$ is $11$.<br>
The function $mdrs(n)$ gives the maximum Digital Root Sum of $n$. So $mdrs(24) = 11$.<br>
Find $\sum mdrs(n)$ for $1 < n < 1,000,000$.