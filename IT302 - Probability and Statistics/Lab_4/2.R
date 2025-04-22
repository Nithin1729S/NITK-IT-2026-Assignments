mu <- 0.7
x <- 0.5
s <- 3.77
n <- 7
t <- (x-mu)/(s/sqrt(n))
df<-n-1
p_value <- pt(t, df, lower.tail = FALSE)
cat("T value: ",t,"\n")
cat("P Value: ",p_value)
alpha<-0.1
if (p_value < alpha) {
  cat("Reject the null hypothesis\n")
} else {
  cat("Fail to reject the null hypothesis\n")
}