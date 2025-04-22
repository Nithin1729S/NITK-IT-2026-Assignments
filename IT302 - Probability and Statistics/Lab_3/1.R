prob_within_1_sd <- pnorm(1) - pnorm(-1)
prob_within_2_sd <- pnorm(2) - pnorm(-2)
prob_within_3_sd <- pnorm(3) - pnorm(-3)

cat("Probability within 1 standard deviation:", prob_within_1_sd, "\n")
cat("Probability within 2 standard deviations:", prob_within_2_sd, "\n")
cat("Probability within 3 standard deviations:", prob_within_3_sd, "\n")

