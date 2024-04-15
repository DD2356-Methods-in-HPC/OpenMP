import numpy as np
import matplotlib.pyplot as plt

# input data
threads = [1, 32, 64, 128]

execution_times = {
    1: [14.694, 14.701, 14.698, 14.697, 14.696, 14.697, 14.690, 14.689, 14.697, 14.701],
    32: [0.617, 0.613, 0.618, 0.616, 0.618, 0.617, 0.615, 0.618, 0.618, 0.615],
    64: [0.387, 0.388, 0.391, 0.387, 0.393, 0.396, 0.389, 0.391, 0.393, 0.394],
    128: [0.296, 0.292, 0.294, 0.295, 0.295, 0.298, 0.303, 0.293, 0.301, 0.395]
}

# calculate average execution time for each number of threads
avg_execution_times = {threads: np.mean(execution_times[threads]) for threads in threads}

print(avg_execution_times)

# calculate speedup using formula
speedup = {threads: avg_execution_times[1] / avg_execution_times[threads] for threads in threads}

# plot the results
plt.figure(figsize=(10, 6))  # set figure size
plt.plot(threads, speedup.values(), marker='o', linestyle='dashed', markersize=2,
         markerfacecolor="tab:blue", markeredgecolor="tab:blue", markeredgewidth=10)

# customize spines
plt.gca().spines['top'].set_visible(False)
plt.gca().spines['right'].set_visible(False)
# plot lables
plt.xlabel('Number of Threads')
plt.ylabel('Speedup')
# plt.title('Speedup vs. Number of Threads') # hide title for latex
# remove bakground lines
plt.grid(False)
plt.show()
