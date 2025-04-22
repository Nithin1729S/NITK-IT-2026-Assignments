mean <- 1.5
variance <- 0.75
beta <- variance / mean  
alpha <- mean / beta     

# a) P(X > 1.2)
prob_exceeds_1.2 <- 1 - pgamma(1.2, shape = alpha, rate = 1 / beta)
cat("a) Probability that repair time exceeds 1.2 hours:", prob_exceeds_1.2, "\n")

# b) P(X > 4 | X > 1.2)
prob_exceeds_4 <- 1 - pgamma(4, shape = alpha, rate = 1 / beta)
prob_at_least_4_given_exceeds_1.2 <- prob_exceeds_4 / prob_exceeds_1.2
cat("b) Probability that repair time is at least 4 hours given it exceeds 1.2 hours:", prob_at_least_4_given_exceeds_1.2, "\n")

# (c) Plot the p.d.f. of the gamma distribution
x_values <- seq(0, 10, by = 0.1)
pdf_values <- dgamma(x_values, shape = alpha, rate = 1 / beta)

plot(x_values, pdf_values, type = "l", col = "blue", lwd = 2,
     main = "Probability Density Function of Gamma Distribution",
     xlab = "Repair Time (hours)", ylab = "Density")

# (d) Plot the c.d.f. of the gamma distribution
cdf_values <- pgamma(x_values, shape = alpha, rate = 1 / beta)

plot(x_values, cdf_values, type = "l", col = "red", lwd = 2,
     main = "Cumulative Distribution Function of Gamma Distribution",
     xlab = "Repair Time (hours)", ylab = "Cumulative Probability")
