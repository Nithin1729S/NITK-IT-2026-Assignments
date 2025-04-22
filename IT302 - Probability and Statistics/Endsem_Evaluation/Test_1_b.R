p_girl<-0.5
p_boy<-0.5
p_blue_eyed<-0.25
p_black_eyed<-0.75
p_girl_blue <- p_girl* p_blue_eyed 
p_girl_blue
p_boy_black <- p_boy * p_black_eyed
p_boy_black
prob_3_blue_girls <- dbinom(3, size = 5, prob = p_girl_blue)
prob_2_black_boys <- dbinom(2, size = 5, prob = p_boy_black)
combined_probability <- prob_3_blue_girls * prob_2_black_boys
cat("The probability of having exactly 3 blue-eyed girls and exactly 2 black-eyed boys among 5 newborns is:", combined_probability, "\n")