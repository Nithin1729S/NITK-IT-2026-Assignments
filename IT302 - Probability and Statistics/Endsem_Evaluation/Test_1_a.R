# Create function to generate all possible combinations
get_dice_prob <- function() {
  p1 <- c(0.06, 0.19, 0.17, 0.20, 0.22, 0.16)
  outcomes <- 1:6
  total_prob <- 0
  for(i in 1:6) {
    for(j in 1:6) {
      for(k in 1:6) {
        for(l in 1:6) {
          for(m in 1:6) {
            for(n in 1:6) {
              sum_dice <- i + j + k + l + m + n
              if(sum_dice < 22) {
                prob <- p1[i] * p1[j] * p1[k] * p1[l] * p1[m] * p1[n]
                total_prob <- total_prob + prob
              }
            }
          }
        }
      }
    }
  }
  return(total_prob)
}

dice_probability <- get_dice_prob()
cat("\n(a) Probability that sum of dice rolls is less than 22:", dice_probability, "\n")