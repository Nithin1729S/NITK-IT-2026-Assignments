x<-c(-2,-1,0,1,2,3)
px<-c(0.08,0.15,0.23,0.3,0.19,0.05)
expectation=weighted.mean(x, px)
variance<-sum((x-expectation)^2 * px)
cat("Variance of X = ",variance)
standard_deviation=sqrt(variance)
cat("\nStandard Deviation of X = ",standard_deviation)

