# Function for Insertion Sort
def insertion_sort(arr):
    # Traverse through 1 to len(arr)
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        # Move elements of arr[0..i-1] that are greater than key, to one position ahead
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key


# Function for Shell Sort
def shell_sort(arr):
    n = len(arr)
    gap = n // 2
    # Start with a large gap, then reduce the gap
    while gap > 0:
        # Do a gapped insertion sort for this gap size
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2


# Function to display the top 5 scores
def display_top_scores(arr, top_n=5):
    print(f"\nTop {top_n} scores:")
    for score in arr[-top_n:]:
        print(f"{score:.2f}")


def main():
    # Number of students
    N = int(input("Enter the number of students: "))

    # Input percentages for second-year students
    percentages = []
    for i in range(N):
        score = float(input(f"Enter percentage for student {i + 1}: "))
        percentages.append(score)

    # Sorting using Insertion Sort
    insertion_sort(percentages)
    print("\nSorted Percentages using Insertion Sort:")
    display_top_scores(percentages)

    # Re-enter the original unsorted list
    percentages = [float(input(f"Enter percentage for student {i + 1}: ")) for i in range(N)]

    # Sorting using Shell Sort
    shell_sort(percentages)
    print("\nSorted Percentages using Shell Sort:")
    display_top_scores(percentages)


if __name__ == "__main__":
    main()
