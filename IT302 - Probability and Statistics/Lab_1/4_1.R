
P_W <- 1/6  
P_R <- 1/3  

multinomial_coeff <- choose(7, 4) * choose(3, 3)
probability <- multinomial_coeff * (P_W^4) * (P_R^3)

cat("The probability of drawing 4 white balls and 3 red balls is:", probability, "\n")
