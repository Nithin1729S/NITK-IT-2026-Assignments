pdf <- function(x) {
  ifelse(x > 0 & x < 2, (3 * x / 4) * (2 - x), 0)
}

mean <- integrate(function(x) x * pdf(x), lower = 0, upper = 2)$value
cat("Mean of X = ",mean)
