x <- c(1, 2, 3, 4, 5)
mean(x)            # Mean
median(x)          # Median
sd(x)              # Standard Deviation
var(x)             # Variance
quantile(x, probs = c(0.25, 0.5, 0.75))  # Quartiles
summary(x)         # Summary statistics

##Mode
get_mode <- function(v) {
  uniqv <- unique(v)
  uniqv[which.max(tabulate(match(v, uniqv)))]
}

vec<-c(1,1,3,3,3,4)
get_mode(vec)
#########################################################################



####################################################################

# P(X <= k) in Poisson distribution
ppois(3, lambda = 2.5) 

# P(X = k) in Poisson distribution
dpois(3, lambda = 2.5)  
############################################################################

# P(X <= x) in exponential distribution
pexp(2, rate = 0.5)

# P(X = x) in exponential distribution
dexp(2, rate = 0.5)


##########################################################################
f<-function(x) 3*x^2
integrate(f,lower = 0.14,upper = 0.71)  # Integration

pbinom(6,size=10,p=1/2)   #P(X<=6) in binomial distribution

x<-c(1,2)
wt<-c(2,3)
expectation<-weighted.mean(x,wt)  # Expectation
cat(expectation)

var<-sum((x-expectation)^2*wt)   #Variance
var
#######################################################################
pnorm(2.2)   #P(Z<=2.2)

pnorm(2.2,mean=0,sd=1)    # Non standard 

p=0.1
q=0.9
P_X_4 <- choose(5, 4) * (p^4) * (q^(5 - 4))  #P(X=4) in binomial dist

P<-pbinom(3, size = 5, prob = p)  #P(X<=3)
##################################################################
## Z test
#find Z critical value for left tailed test with alpha 5%
qnorm(p=.05)

#Right tailed test alpha 5%
#find Z critical value
qnorm(p=.05, lower.tail=FALSE)

#find Z critical value for two tailed test with alpha 5%
qnorm(p=0.05/2, lower.tail=FALSE)

##################################################################
# T test
# One tailed (left) alpha=5% df=22
qt(p=0.05,df=22,lower.tail = TRUE)

# One tailed (right) alpha=5% df=22
qt(p=0.05,df=22,lower.tail = FALSE)

# Two tailed test alpha = 5% and df=22
qt(p=.05/2, df=22, lower.tail=FALSE)

#####################################################################

#P value with t known
#Left tailed hypo test t score = -0.77 and df=15
pt(q=-.77, df=15, lower.tail=TRUE)

#Right tailed hypo test t score = -0.77 and df=15
pt(q=-.77, df=15, lower.tail=FALSE)

# Two tailed with df =10 and t score=2.5 
p_value <- 2 * pt(q = abs(2.5), df = 10, lower.tail = FALSE)
p_value

############################################################################

# P value 
# Two tailed hypo mean =5  , sample sd=2, n=20, sample_mean=7
# Given values
a <- 5             # Hypothesized mean
s <- 2             # Standard deviation
n <- 20            # Sample size
xbar <- 7          # Sample mean

# Calculate Z-score
z <- (xbar - a) / (s / sqrt(n))
z

# Calculate two-tailed p-value
p_value_two_tailed <- 2 * pnorm(-abs(z))
p_value_two_tailed

# One tailed for same above
# Calculate right-tailed p-value
p_value_right_tailed <- 1 - pnorm(z)
p_value_right_tailed

# Calculate left-tailed p-value
p_value_left_tailed <- pnorm(z)
p_value_left_tailed

#######################################################################

#p value when z is 2.31 in a two tailed test
pnorm(-2.31) +pnorm(2.31,lower.tail = FALSE)

##############################################################################

#Chi test
df <- 10  # Degrees of freedom
alpha <- 0.05  # Significance level

# Two-tailed test critical values
critical_value_lower <- qchisq(alpha / 2, df)  # Lower tail
critical_value_upper <- qchisq(1 - alpha / 2, df)  # Upper tail

# One-tailed test critical values
critical_value_left <- qchisq(alpha, df)  # Left tail
critical_value_right <- qchisq(1 - alpha, df)  # Right tail

#chi test stats
#(dof*sample_sd^2)/(hypo_sd^2)

#p-value
#right tailed 
p_value <- 1 - pchisq(chi_square_statistic, df)
#left tailed
p_value <- pchisq(chi_square_statistic, df)
#two tailed
p_value <- 2 * min(pchisq(chi_square_statistic, df), 1 - pchisq(chi_square_statistic, df))


#####################################################################################


#plots
#plot for distribution poisson discrete
lambda<-1.5
values<-1:10
probs=dpois(values,lambda)
barplot(probs,names.arg = values)

#plot for distribution binomial discrete
n<-5
p<-0.8
s<-0:n
probs<-dbinom(0:n,n,p)
barplot(probs)

#plot cdf of given function 

pdf <- function(x) {
  ifelse(x > 0 & x < 2, (3 * x / 4) * (2 - x), 0)
}
integrate(pdf,1,2)
plot(seq(-1,3,by=0.01), cumsum(pdf(seq(-1,3,by=0.01))*0.01 ), type="l",main = "Cumulative Distribution Function (CDF)",
     xlab = "x", ylab = "F(x)" ) 

#Find mean 
pdf <- function(x) {
  ifelse(x > 0 & x < 2, (3 * x / 4) * (2 - x), 0)
}

mean <- integrate(function(x) x * pdf(x), lower = 0, upper = 2)$value
cat("Mean of X = ",mean)

#Variance 
pdf <- function(x) {
  ifelse(x > 0 & x < 2, (3 * x / 4) * (2 - x), 0)
}

mean <- integrate(function(x) x * pdf(x), lower = 0, upper = 2)$value
mean_square <- integrate(function(x) x^2 * pdf(x), lower = 0, upper = 2)$value
variance <- mean_square - mean^2
cat("Variance of X = ",variance)

#Plot pdf of continuous data
pdf <- function(x) {
  ifelse(x > 0 & x < 2, (3 * x / 4) * (2 - x), 0)
}

curve(pdf, from = 0, to = 2, lwd = 2, ylab = "Density", xlab = "x",
      main = "Probability Density Function")


###########################################################################
#Prime numbers
is_prime <- function(num) {
  if (num <= 1) return(FALSE)
  if(num==2) return(TRUE)
  for (i in 2:sqrt(num)) {
    if (num %% i == 0) return(FALSE)
  }
  return(TRUE)
}

# Fill an array with the first n prime numbers
n <- 10
prime_array <- c()
num <- 2
while (length(prime_array) < n) {
  if (is_prime(num)) {
    prime_array <- c(prime_array, num)
  }
  num <- num + 1
}

print(prime_array)



#Choose



arr<-1:100
arr
req<-arr[(arr%%4==0)& (arr%%6==0)]
req

###########################################################################
#Die roll
#Die roll
#Suppose a fair dice is rolled 10 times. Using R/Python find the probability
#that
#(a) sum of the number is less than 22
#(b) sum of the number is greater than 25.

# Define the probability mass function for a single die
die_prob <- rep(1/6, 6)

# Convolve the probability distribution for 10 dice rolls
total_rolls <- 10
sum_probs <- die_prob
for (i in 2:total_rolls) {
  sum_probs <- convolve(sum_probs, die_prob, type = "open")
}

# Calculate the probability that the sum is less than 22
sum_values <- 10:60  # Possible sums for 10 rolls of a 6-sided die
prob_less_than_22 <- sum(sum_probs[sum_values < 22])

# Print the result
cat("Probability that the sum of 10 rolls is less than 22:", prob_less_than_22, "\n")

# Load required package for convolution
install.packages("gmp")
library(gmp)

# Define the probability mass function for a single die
die_prob <- rep(1/6, 6)

# Convolve the probability distribution for 10 dice rolls
total_rolls <- 10
sum_probs <- die_prob
for (i in 2:total_rolls) {
  sum_probs <- convolve(sum_probs, die_prob, type = "open")
}

# Calculate the probability that the sum is greater than 25
sum_values <- 10:60  # Possible sums for 10 rolls of a 6-sided die
prob_greater_than_25 <- sum(sum_probs[sum_values > 25])

# Print the result
cat("Probability that the sum of 10 rolls is greater than 25:", prob_greater_than_25, "\n")

##################################################################################

##Monte Carlo
#Use Monte Carlo simulations in R/Python to simulate the following
#scenario. It’s my 28th birthday, and my friends bought me a cake with 28
#candles on it. I make a wish and try to blow them out. Every time, I blow
#out a random number of candles between 1 and the number that remains,
#including one and that other number. How many times, on average, do I
#blow before all the candles are extinguished?
num_simulations <- 100000
initial_candles <- 28

blow_out_candles <- function() {
  candles_left <- initial_candles
  blows <- 0
  
  while (candles_left > 0) {
    blow <- sample(1:candles_left, 1)
    candles_left <- candles_left - blow
    blows <- blows + 1
  }
  
  return(blows)
}

results <- replicate(num_simulations, blow_out_candles())
average_blows <- mean(results)
cat("On average, it takes", average_blows, "blows to extinguish all the candles.\n")

#Q4. Use Monte Carlo simulations in R/Python to simulate the following
#scenario. Two teams, say Cavs and Warriors, are playing a seven-game
#championship series. The first to win four games, therefore, win the series.
#The teams are equally good, so they each have a 50-50 chance of winning
#each game. If the Cavs lose the first game, what is the probability that they
#win the series?
simulate_series <- function() {
  cavs_wins <- 0
  warriors_wins <- 1  
  while (cavs_wins < 4 && warriors_wins < 4) {
    if (runif(1) < 0.5) { 
      cavs_wins <- cavs_wins + 1
    } else {
      warriors_wins <- warriors_wins + 1
    }
  }
  return(cavs_wins == 4)
}

# Monte Carlo Simulation
num_simulations <- 1000000
cavs_win_count <- sum(replicate(num_simulations, simulate_series()))
probability_cavs_win <- cavs_win_count / num_simulations

cat("Probability that the Cavs win the series after losing the first game:", probability_cavs_win, "\n")

