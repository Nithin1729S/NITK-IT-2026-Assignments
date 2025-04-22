n <- 16
p <- 0.5
prob_6_boys <- dbinom(6, n, p)
prob_7_boys <- dbinom(7, n, p)
total_probability <- prob_6_boys + prob_7_boys
total_probability
