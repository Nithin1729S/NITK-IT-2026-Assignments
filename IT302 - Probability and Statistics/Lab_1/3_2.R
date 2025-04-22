n <- 16
k <- 8
p <- 0.5
probability <- choose(n, k) * p^k * (1 - p)^(n - k)
print(probability)
