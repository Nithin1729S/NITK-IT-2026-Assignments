pdf <- function(x) {
  ifelse(x > 0 & x < 2, (3 * x / 4) * (2 - x), 0)
}

curve(pdf, from = 0, to = 2, lwd = 2, ylab = "Density", xlab = "x",
      main = "Probability Density Function")
