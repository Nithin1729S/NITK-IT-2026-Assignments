data <- c(140, 125, 150, 124, 143, 170, 125, 94, 127, 53)
mu <- 101.75
alpha <- 0.05
x_bar <- mean(data)
n <- length(data)
sd <- sqrt(sum((data - x_bar)^2) / (n - 1))

t <- (x_bar - mu) / (sd / sqrt(n))
cat("T value: ",t)

df <- n - 1

p_value <- 1 - pt(t, df)
cat("P-value:", p_value, "\n")


if (p_value < alpha) {
  cat("Reject the null hypothesis\n")
} else {
  cat("Fail to reject the null hypothesis\n")
}