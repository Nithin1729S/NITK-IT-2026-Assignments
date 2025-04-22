lambda_value <- 1.5 
values <- 0:10  
probabilities <- dpois(values, lambda_value)
barplot(probabilities, names.arg=values,
        xlab="Number of Demands", ylab="Probability",
        main="Poisson Distribution (λ=1.5)")
