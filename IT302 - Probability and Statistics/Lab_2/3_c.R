pdf <- function(x) {
  ifelse(x > 0 & x < 2, (3 * x / 4) * (2 - x), 0)
}

mean <- integrate(function(x) x * pdf(x), lower = 0, upper = 2)$value
mean_square <- integrate(function(x) x^2 * pdf(x), lower = 0, upper = 2)$value
variance <- mean_square - mean^2
cat("Variance of X = ",variance)
