import numpy as np
import matplotlib.pyplot as plt

# Parameters for the Poisson distribution
lambda_value = 1.5  # average number of demands per day
n_simulations = 10000  # number of simulations

# Simulate the Poisson distribution
poisson_data = np.random.poisson(lambda_value, n_simulations)

# Plot the histogram
plt.hist(poisson_data, bins=range(0, max(poisson_data)+2), density=True, alpha=0.6, color='b', edgecolor='black')

# Add labels and title
plt.xlabel('Number of Demands')
plt.ylabel('Probability')
plt.title('Histogram of Poisson Distribution (λ=1.5)')

# Show the plot
plt.show()

