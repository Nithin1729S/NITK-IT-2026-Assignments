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
