machines<-c(12.3, 12.1, 12.02, 11.98, 12.00, 12.05, 11.97, 11.99)
n <- length(machines) 
alpha<-0.05
mu<-0.03
sample_sd <- sd(machines)
print(sample_sd)
df<-n-1
print(df)
chi_square_statistic <- (df * (sample_sd^2))/mu^2
cat("Chi Square: ",chi_square_statistic,"\n")
critical_value <- qchisq(1 - alpha, df)
cat("Critical value: ",critical_value)
if (critical_value < chi_square_statistic) {
  cat("Reject the null hypothesis\n")
} else {
  cat("Fail to reject the null hypothesis\n")
}