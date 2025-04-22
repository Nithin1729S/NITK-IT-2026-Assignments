n_sim <- 1000000
results <- numeric(n_sim)
for (i in 1:n_sim) {
  results[i] <- sum(sample(1:6, 10, replace = TRUE))
}
probability <- mean(results > 25)
print(probability)
