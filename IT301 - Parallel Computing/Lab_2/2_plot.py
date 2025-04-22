import pandas as pd
import matplotlib.pyplot as plt


data = pd.read_csv('speedup_data.csv')


sizes = data['MatrixSize'].unique()
for size in sizes:
    subset = data[data['MatrixSize'] == size]
    plt.plot(subset['NumThreads'], subset['Speedup'], marker='o', label=f'Size: {size}')


plt.title('Speedup vs. Number of Threads')
plt.xlabel('Number of Threads')
plt.ylabel('Speedup')
plt.legend()
plt.grid(True)


plt.savefig('speedup_vs_threads.png')
