import pandas as pd
import matplotlib.pyplot as plt


df = pd.read_csv('execution_times.csv')

# Filter for ThreadCount == 8
df_8_threads = df[df['ThreadCount'] == 8]

# Pivot the data for plotting
pivot_df = df_8_threads.pivot(index='ArraySize', columns='Schedule', values='ExecutionTime')

# Plotting
plt.figure(figsize=(12, 6))
for schedule in pivot_df.columns:
    plt.plot(pivot_df.index, pivot_df[schedule], marker='o', label=schedule)

plt.xscale('log')
plt.yscale('log')
plt.xlabel('Array Size')
plt.ylabel('Execution Time (seconds)')
plt.title('Execution Time vs Array Size for Different OpenMP Schedules (8 Threads)')
plt.legend()
plt.grid()
plt.savefig("execution_times_plot.png")