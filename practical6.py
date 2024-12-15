def quicksort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[len(arr) // 2]
        left = [x for x in arr if x < pivot]
        middle = [x for x in arr if x == pivot]
        right = [x for x in arr if x > pivot]
        return quicksort(left) + middle + quicksort(right)

def display_top_scores(scores, top_n=5):
    # Sort the scores
    sorted_scores = quicksort(scores)
    # Display the top N scores
    print("Top {} scores:".format(top_n))
    for score in sorted_scores[-top_n:]:
        print(score)

def main():
    student_scores = []

    # Get user input for student scores
    num_students = int(input("Enter the number of students: "))
    for i in range(num_students):
        score = float(input(f"Enter the percentage for student {i + 1}: "))
        student_scores.append(score)
    # Display top 5 scores
    display_top_scores(student_scores)
if __name__ == "__main__":
    main()
