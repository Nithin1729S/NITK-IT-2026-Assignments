library(UsingR)
data(normtemp)
temperatures <- normtemp$temperature

n <- length(temperatures)
mean_temp <- mean(temperatures)
sd_temp <- sd(temperatures)
mu <- 98.6
t_stat <- (mean_temp - mu) / (sd_temp / sqrt(n))
df <- n - 1
alpha <- 0.05
critical_t <- qt(1 - alpha/2, df)
p_value <- 2 * (1 - pt(abs(t_stat), df))

cat("Sample Mean:", mean_temp, "\n")
cat("Sample Standard Deviation:", sd_temp, "\n")
cat("T-Statistic:", t_stat, "\n")
cat("Critical Value:", critical_t, "\n")
cat("P-Value:", p_value, "\n")

if (p_value < alpha) {
  cat("Reject the null hypothesis\n")
} else {
  cat("Fail to reject the null hypothesis\n")
}
