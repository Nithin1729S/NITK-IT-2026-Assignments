n <- 5 
p <- 0.8
successes <- 0:n
probabilities <- dbinom(successes, n, p)

barplot(probabilities, names.arg=successes, 
        main="Histogram of Binomial Distribution",
        xlab="Number of Successful Operations", ylab="Probability")

#A new surgical procedure is said to be successful 80% of the time. Suppose
#the operation is performed five times and the results are to be independent
#of one another. Write a R/Python code to find the probability that
#(a) All five operations are successful.
#(b) Exactly four are successful.
#(c) Less than two are successful.
#(d) Plot the histogram of the corresponding distribution

