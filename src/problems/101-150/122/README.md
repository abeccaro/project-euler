The most naive way of computing n<sup>15</sup> requires fourteen multiplications:

n × n × ... × n = n<sup>15</sup>

But using a "binary" method you can compute it in six multiplications:

n × n = n<sup>2</sup><br />
n<sup>2</sup> × n<sup>2</sup> = n<sup>4</sup><br />
n<sup>4</sup> × n<sup>4</sup> = n<sup>8</sup><br />
n<sup>8</sup> × n<sup>4</sup> = n<sup>12</sup><br />
n<sup>12</sup> × n<sup>2</sup> = n<sup>14</sup><br />
n<sup>14</sup> × n = n<sup>15</sup>

However it is yet possible to compute it in only five multiplications:

n × n = n<sup>2</sup><br />
n<sup>2</sup> × n = n<sup>3</sup><br />
n<sup>3</sup> × n<sup>3</sup> = n<sup>6</sup><br />
n<sup>6</sup> × n<sup>6</sup> = n<sup>12</sup><br />
n<sup>12</sup> × n<sup>3</sup> = n<sup>15</sup>

We shall define m(k) to be the minimum number of multiplications to compute n<sup>k</sup>; for example m(15) = 5.

For 1 ≤ k ≤ 200, find ∑ m(k).