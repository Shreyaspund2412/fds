


def add_matrices(matrix1, matrix2):
    # Add corresponding elements of the two matrices
    rows = len(matrix1)
    cols = len(matrix1[0])
    result = [[0 for _ in range(cols)] for _ in range(rows)]

    for i in range(rows):
        for j in range(cols):
            result[i][j] = matrix1[i][j] + matrix2[i][j]

    return result


def subtract_matrices(matrix1, matrix2):
    # Subtract corresponding elements of the two matrices
    rows = len(matrix1)
    cols = len(matrix1[0])
    result = [[0 for _ in range(cols)] for _ in range(rows)]

    for i in range(rows):
        for j in range(cols):
            result[i][j] = matrix1[i][j] - matrix2[i][j]

    return result


def multiply_matrices(matrix1, matrix2):
    # Multiply two matrices
    rows1 = len(matrix1)
    cols1 = len(matrix1[0])
    rows2 = len(matrix2)
    cols2 = len(matrix2[0])

    # Matrix multiplication is only possible if the number of columns in matrix1
    # is equal to the number of rows in matrix2
    if cols1 != rows2:
        raise ValueError(
            "Matrix multiplication not possible. Number of columns of first matrix must equal number of rows of second matrix.")

    # Resulting matrix dimensions will be (rows1 x cols2)
    result = [[0 for _ in range(cols2)] for _ in range(rows1)]

    for i in range(rows1):
        for j in range(cols2):
            for k in range(cols1):
                result[i][j] += matrix1[i][k] * matrix2[k][j]

    return result


def transpose_matrix(matrix):
    # Transpose of a matrix (swap rows and columns)
    rows = len(matrix)
    cols = len(matrix[0])
    result = [[matrix[j][i] for j in range(rows)] for i in range(cols)]
    return result


def print_matrix(matrix):
    for row in matrix:
        print(row)


def main():
    # Input matrices
    rows = int(input("Enter the number of rows: "))
    cols = int(input("Enter the number of columns: "))

    print("Enter the elements of the first matrix:")
    matrix1 = []
    for i in range(rows):
        row = list(map(int, input(f"Enter row {i + 1}: ").split()))
        matrix1.append(row)

    print("Enter the elements of the second matrix:")
    matrix2 = []
    for i in range(rows):
        row = list(map(int, input(f"Enter row {i + 1}: ").split()))
        matrix2.append(row)

    print("\nMatrix 1:")
    print_matrix(matrix1)

    print("\nMatrix 2:")
    print_matrix(matrix2)

    # Addition of matrices
    print("\nAddition of matrices:")
    result_add = add_matrices(matrix1, matrix2)
    print_matrix(result_add)

    # Subtraction of matrices
    print("\nSubtraction of matrices:")
    result_subtract = subtract_matrices(matrix1, matrix2)
    print_matrix(result_subtract)

    # Multiplication of matrices
    try:
        print("\nMultiplication of matrices:")
        result_multiply = multiply_matrices(matrix1, matrix2)
        print_matrix(result_multiply)
    except ValueError as e:
        print(e)

    # Transpose of matrix 1
    print("\nTranspose of Matrix 1:")
    result_transpose = transpose_matrix(matrix1)
    print_matrix(result_transpose)


if __name__ == "__main__":
    main()