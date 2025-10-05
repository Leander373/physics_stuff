import numpy as np

def main():
    rand_num = np.random.rand(10)
    result = filter_rand(rand_num)
    print(result)


def filter_rand(array):
    new = []
    for i in range(len(array)):
        if array[i] > 0.5:
            new.append(array[i])

    return np.array(new)


main()