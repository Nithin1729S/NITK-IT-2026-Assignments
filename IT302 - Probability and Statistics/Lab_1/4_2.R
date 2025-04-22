P_W <- 10/60  
P_R <- 20/60  
P_G <- 30/60  
probability_same_color <- (P_W^7) + (P_R^7) + (P_G^7)

cat("The probability that all 7 balls are the same color is:",probability_same_color, "\n")
