x<-c(-2,-1,0,1,2,3)
px<-c(0.08,0.15,0.23,0.3,0.19,0.05)
prob_oneper=sum(px[x>=1])
cat("probability that the stock price increases by at least 1% = ",prob_oneper)

