import csv
import random

num_points = input('Enter the number of points to generate data for: ')

# x and y values will lie between this range
range_min = -20
range_max = 20
labels = ["game", "movie"]
output_file_name = "datapoints.csv"

datapoints = []
for i in range(int(num_points)):
    x = random.random() * range_max - range_min
    y = random.random() * range_max - range_min

    random_label = random.choice(labels)
    datapoints.append([random_label, x, y])

# write the list to a csv
with open(output_file_name, 'w', newline='') as csvfile:
    writer = csv.writer(csvfile, delimiter=',')
    for row in datapoints:
        writer.writerow(row)

# read back the file to count number of rows written
with open(output_file_name, 'r', newline='') as csvfile:
    reader = csv.reader(csvfile, delimiter=',')
    counter = 0
    for row in reader:
        counter += 1

    if counter == num_points:
        print(f'Sucessfully read back {counter} datapoints from {output_file_name}')
    else:
        print(f'Warning, there are {counter} datapoints in {output_file_name}, expected {num_points} datapoints')

