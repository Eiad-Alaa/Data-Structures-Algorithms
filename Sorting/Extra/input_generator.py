import random


file = open("input.txt", "w")

def generate(n):
    file.write(f"{n}\n")
    for num in random.sample(range(n), n):
        file.write(f"{num} ")
    file.write("\n")


ranges = [1000, 25000, 50000, 75000, 100000, 250000, 500000, 750000, 1000000]

file.write(f"{len(ranges)}\n")
for num in ranges:
    generate(num)

file.close()
