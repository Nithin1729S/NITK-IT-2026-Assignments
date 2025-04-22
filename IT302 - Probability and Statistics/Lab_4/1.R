mean <- 5
sd <- 0.25
n <- 45
sample_mean <- 3.5
SE <- sd / sqrt(n)
z <- (sample_mean - mean) / SE
probability <- pnorm(z)
probability
