import statistics

# input values for old and new values
old = [
    11.897, 11.919, 11.917, 11.901, 11.911,
    11.939, 11.893, 11.899, 11.897, 11.898
]

new = [
    1.075, 1.076, 1.071, 1.073, 1.063,
    1.069, 1.067, 1.079, 1.074, 1.064
]

# calculate average and standard deviation
avg_old = statistics.mean(old)
std_dev_old = statistics.stdev(old)

avg_new = statistics.mean(new)
std_dev_new = statistics.stdev(new)

# print the results
print("Old Values:")
print("Average:", avg_old)
print("Standard Deviation:", std_dev_old)
print()
print("New Values:")
print("Average:", avg_new)
print("Standard Deviation:", std_dev_new)
