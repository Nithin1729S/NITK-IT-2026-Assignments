import pandas as pd
import matplotlib.pyplot as plt


df = pd.read_csv('execution_times.csv')


serial_df = df[df['Schedule'] == 'serial']
static_df = df[df['Schedule'] == 'runtime']


thread_counts = sorted(static_df['ThreadCount'].unique())
plt.figure(figsize=(10, 6))
for tc in thread_counts:
    subset = static_df[static_df['ThreadCount'] == tc]
    plt.plot(subset['ArraySize'], subset['ExecutionTime'], marker='o', label=f'Thread Count={tc}')
plt.scatter(serial_df['ArraySize'], serial_df['ExecutionTime'], color='black', label='runtime', zorder=5)
plt.yscale('log')  
plt.xscale('log')  
plt.xlabel('Array Size')
plt.ylabel('Execution Time (seconds)')
plt.title('Execution Time vs Array Size for Runtime Schedule with Increasing Thread Counts')
plt.legend()
plt.grid(True, which="both", ls="--", linewidth=0.5)
plt.tight_layout()
plt.show()
plt.savefig("execution_times_plot.png")