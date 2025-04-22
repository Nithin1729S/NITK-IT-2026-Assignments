mean_call <- 20  
std_dev_call <- 5 
sample_size <- 60 

prob_between_16_18 <- pnorm(18, mean = mean_call, sd = std_dev_call) - pnorm(16, mean = mean_call, sd = std_dev_call)
calls_between_16_18 <- prob_between_16_18 * sample_size

lower_bound_3sd <- mean_call - 3 * std_dev_call
upper_bound_3sd <- mean_call + 3 * std_dev_call

z_score_12_min <- (12 - mean_call) / std_dev_call

cat(" (a) Estimated number of calls between 16 and 18 minutes:", calls_between_16_18, "\n")
cat(" (b) Minutes range within 3 standard deviations:", lower_bound_3sd, " mins to", upper_bound_3sd, 
    " mins i.e., it includes", (upper_bound_3sd - lower_bound_3sd), "minutes.\n")

cat(" (c) A 12-minute call is", abs(z_score_12_min), "standard deviations below the mean.\n")
