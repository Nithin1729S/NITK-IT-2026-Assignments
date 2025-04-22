x<-c(-2,-1,0,1,2,3)
px<-c(0.08,0.15,0.23,0.3,0.19,0.05)
prob=sum(px[x<2 & x>-2])
cat("The probability that the stock price changes (increases or decreases) by
less than 2% = ",prob)

