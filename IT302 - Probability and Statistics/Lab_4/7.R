data("babies")

dht_clean <- babies$dht[babies$dht != 99]

mu <- 68           
alpha <- 0.10      

sample_mean <- mean(dht_clean)    
sample_sd <- sd(dht_clean)         
n <- length(dht_clean)            

t_stat <- (sample_mean - mu) / (sample_sd / sqrt(n))
cat("Test Statistic (t):", t_stat, "\n")

df <- n - 1
p_value <- pt(t_stat, df, lower.tail = FALSE)
cat("p-value:", p_value, "\n")

if (p_value < alpha) {
  cat("Reject the null hypothesis\n")
} else {
  cat("Fail to reject the null hypothesis\n")
}