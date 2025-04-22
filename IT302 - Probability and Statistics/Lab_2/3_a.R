pdf <- function(x) {
  ifelse(x > 0 & x < 2, (3 * x / 4) * (2 - x), 0)
}
integrate(pdf,1,2)
plot(seq(-1,3,by=0.01), cumsum(pdf(seq(-1,3,by=0.01))*0.01 ), type="l",main = "Cumulative Distribution Function (CDF)",
     xlab = "x", ylab = "F(x)" ) 