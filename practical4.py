def selection_sort(arr):
    # Selection sort algorithm
    n = len(arr)
    for i in range(n):
        # Find the minimum element in unsorted array
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        # Swap the found minimum element with the first element
        arr[i], arr[min_index] = arr[min_index], arr[i]


def bubble_sort(arr):
    # Bubble sort algorithm
    n = len(arr)
    for i in range(n):
        # Last i elements are already sorted
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                # Swap if the element found is greater than the next element
                arr[j], arr[j + 1] = arr[j + 1], arr[j]


def print_top_scores(arr, top_n=5):
    # Display the top N highest scores
    print(f"Top {top_n} scores:")
    for score in arr[-top_n:]:
        print(f"{score:.2f}")


def main():
    # Number of students
    N = int(input("Enter the number of students: "))

    # Input percentages
    percentages = []
    for i in range(N):
        score = float(input(f"Enter percentage for student {i + 1}: "))
        percentages.append(score)

    # Sort using Selection Sort and display top 5 scores
    selection_sort(percentages)
    print("\nSorted percentages (Selection Sort):")
    print(percentages)
    print_top_scores(percentages)

    # Sort using Bubble Sort and display top 5 scores
    # Re-enter the original unsorted list
    percentages = [float(input(f"Enter percentage for student {i + 1}: ")) for i in range(N)]
    bubble_sort(percentages)
    print("\nSorted percentages (Bubble Sort):")
    print(percentages)
    print_top_scores(percentages)


if __name__ == "__main__":
    main()
