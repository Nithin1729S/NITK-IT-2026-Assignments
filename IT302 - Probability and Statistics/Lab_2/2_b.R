avg<-1.5
prob<-ppois(2,lambda = avg,lower=FALSE)
cat("Some demand is refused = ",prob*100,"%")