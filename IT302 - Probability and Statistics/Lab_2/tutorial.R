library(probs)
X=tosscoin(4,makespace=TRUE)
X

pbinom(1,1,1)
dbinom(1,1,1)

x=c(7,8,9,10,11,12)
pbinom(x,16,0.5)   #output for each value of a

sum(pbinom(x,16,0.5))
# X follows B(n,p)
X=rbinom(100,16,p=0.2)
X
hist(X) #histogram of binomial dist

# X={0,1,2,3}
# P(X=0)=0.5
# P(X=1)=0.25
# P(x=2)=1/8
#P(X=3)=1/8
#Find the expectation and variance
x=c(0,1,2,3)
f=c(1/2,1/4,1/8,1/8)
m=sum(x*f)
m
v=sum(x**2*f)
v
 
#Population of India 80% Hindus , 20% christian, 25% HINDUS and 5% christian speak in English. A visitor to meet someone who spaeak in English. WHat is the prob that he is 1) hindu 2) christian
prob_hindus=0.8
prob_christian=0.2

prob_hindus_eng=0.25
prob_christian_eng=0.05

# Use bayes theorem

prob_eng_hind= (prob_hindus*prob_hindus_eng) /(prob_hindus*prob_hindus_eng + prob_christian* prob_christian_eng)
prob_eng_hind

prob_eng_chirs= (prob_christian*prob_christian_eng) /(prob_hindus*prob_hindus_eng + prob_christian* prob_christian_eng)
prob_eng_chirs

#emperical cdf  use ecdf function .....or pdf function plots ...use pbinom dbinom functions
plot(ecdf(x))

#Normal Dist



