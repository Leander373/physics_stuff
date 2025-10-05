import numpy as np
import sys

rng = np.random.default_rng()

def generate_dataset() -> np.ndarray:
    times = np.arange(0, 500, 1, dtype=int)
    values = rng.normal(loc=80, scale=3, size=times.shape)
    event_length = 0
    adjusted_values = np.zeros_like(values)
    for index, value in enumerate(values):
        if event_length > 0:
            value += rng.normal(loc=10*min(duration, event_length), scale=1)
            event_length -= 1
            duration += 1
        else:
            if rng.uniform() > 0.99:
                event_length = rng.integers(low=2, high=3)
                duration = 0
        adjusted_values[index] = value
    return np.vstack([times, adjusted_values]).T


if __name__ == "__main__":

    if len(sys.argv) != 2:
        print(f"give the output filename as an argument: {sys.executable} {sys.argv[0]} <filename>")
        exit()
    file_name = sys.argv[1]
    data = generate_dataset()
    np.savetxt(file_name, data, delimiter=";")
