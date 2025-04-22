data(cars)

mean_speed <- mean(cars$speed)
var_speed <- var(cars$speed)
sd_speed <- sd(cars$speed)
median_speed <- median(cars$speed)

get_mode <- function(v) {
  uniqv <- unique(v)
  uniqv[which.max(tabulate(match(v, uniqv)))]
}
mode_speed <- get_mode(cars$speed)
se_speed <- sd_speed/sqrt(length(cars$speed))

hist(cars$speed, 
     main="Histogram of Car Speeds",
     xlab="Speed (mph)",
     ylab="Frequency",
     col="lightblue",
     breaks=10)

summary_stats <- data.frame(
  Statistic = c("Mean", "Variance", "Standard Deviation", "Median", "Mode", "Standard Error"),
  Value = c(mean_speed, var_speed, sd_speed, median_speed, mode_speed, se_speed)
)
print("Summary Statistics:")
print(summary_stats)