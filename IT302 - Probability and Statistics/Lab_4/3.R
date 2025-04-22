emissions <- c(20.5, 15.6, 16.2, 22.5, 17.9, 16.4, 12.7, 19.4, 13.9, 16.6)
n<-10
mu<-20
alpha<-0.01
x_bar=sum(emissions)/n
cat("X_bar is:", x_bar, "\n")
sd <- sqrt(sum((emissions - x_bar)^2) / (n - 1))
cat("SD is: ",sd,"\n")
t=(x_bar-mu)/(sd/(sqrt(n)))
cat("t = ",t,"\n")
df<-n-1
critical_value <- qt(alpha, df, lower.tail = TRUE)
cat("Critical Value: ",critical_value,"\n")


if (t < critical_value) {
  cat("Reject the null hypothesis\n")
} else {
  cat("Fail to reject the null hypothesis\n")
}