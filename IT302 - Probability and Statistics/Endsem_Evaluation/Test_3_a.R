library(bnlearn)
data(marks)

stat_mean <- mean(marks$STAT)
stat_sd <- sd(marks$STAT)
stat_n <- length(marks$STAT)
stat_se <- stat_sd/sqrt(stat_n)
stat_z <- (stat_mean - 38)/stat_se
alpha<-0.05
z_critical <- qnorm(0.05)
stat_pvalue <- pnorm(stat_z)
cat("\nResults for Statistics Marks (Z-test):\n")
cat("Sample Size =", stat_n, "\n")
cat("Sample Mean =", stat_mean, "\n")
cat("Sample SD =", stat_sd, "\n")
cat("Standard Error =", stat_se, "\n")
cat("Z-statistic =", stat_z, "\n")
cat("Critical value =", z_critical, "\n")
cat("P-value =", stat_pvalue, "\n")
cat("Decision: ", ifelse(stat_pvalue < alpha, 
                         "Reject H0", 
                         "Fail to reject H0"), "\n")


