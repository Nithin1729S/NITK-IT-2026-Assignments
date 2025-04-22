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
