mech_25 <- marks$MECH[1:25]
mech_25
mech_mean <- mean(mech_25)
mech_sd <- sd(mech_25)
mech_n <- length(mech_25)
mech_se <- mech_sd/sqrt(mech_n)
mech_t <- (mech_mean - 56)/mech_se
alpha<-0.10
mech_critical <- qt(0.90, df = mech_n - 1)
mech_pvalue <- 1 - pt(mech_t, df = mech_n - 1)
cat("\nResults for Mechanics Marks (t-test):\n")
cat("Sample Size =", mech_n, "\n")
cat("Sample Mean =", mech_mean, "\n")
cat("Sample SD =", mech_sd, "\n")
cat("Standard Error =", mech_se, "\n")
cat("t-statistic =", mech_t, "\n")
cat("Critical value =",mech_critical, "\n")
cat("P-value =", mech_pvalue, "\n")
cat("Decision: ", ifelse(mech_pvalue < alpha,
                         "Reject H0",
                         "Fail to reject H0"), "\n")

