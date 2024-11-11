{
  "nbformat": 4,
  "nbformat_minor": 0,
  "metadata": {
    "colab": {
      "provenance": []
    },
    "kernelspec": {
      "name": "python3",
      "display_name": "Python 3"
    },
    "language_info": {
      "name": "python"
    }
  },
  "cells": [
    {
      "cell_type": "markdown",
      "source": [
        "**Data Analysis with Python Week 12 Session**"
      ],
      "metadata": {
        "id": "G7oSOjvLD09I"
      }
    },
    {
      "cell_type": "code",
      "execution_count": 17,
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "0Y3oyT_yDxPE",
        "outputId": "e2f04d45-61c3-44bd-a26c-07e27573537d"
      },
      "outputs": [
        {
          "output_type": "stream",
          "name": "stdout",
          "text": [
            "Student IDs: [101 102 103 104 105]\n",
            "Student's Heights [5.5 6.1 5.8 5.7 6. ]\n",
            "Combined Data:\n",
            " [[101.    5.5]\n",
            " [102.    6.1]\n",
            " [103.    5.8]\n",
            " [104.    5.7]\n",
            " [105.    6. ]]\n",
            "Sorted Indices (Based on Height): [0 3 2 4 1]\n",
            "Sorted Student IDs: [101. 104. 103. 105. 102.]\n",
            "Sorted Student's Heights: [5.5 5.7 5.8 6.  6.1]\n"
          ]
        }
      ],
      "source": [
        "'''Write a NumPy program to sort the Student ID with increasing Height of the\n",
        "   Students from given Students ID and Height. Print the integer indices that\n",
        "   describes the sort order by multiple columns and the sorted data.'''\n",
        "\n",
        "# Importing a package\n",
        "# Import package_name as alias name\n",
        "import numpy as np\n",
        "\n",
        "# Creating two array which contains Student IDs and there respective Heights\n",
        "# arrayname = alias.name.array([v1,v2,v3,..vn])\n",
        "# 1-D array\n",
        "student_ID = np.array([101,102,103,104,105])\n",
        "heights = np.array([5.5,6.1,5.8,5.7,6.0])\n",
        "\n",
        "# Print the two array which contains Student IDs and there respective Heights\n",
        "print(\"Student IDs:\",student_ID)\n",
        "print(\"Student's Heights\",heights)\n",
        "# Combine the data into a 2-D array\n",
        "# Syntax --> data = np.column_stack((array_1, array_2))\n",
        "data = np.column_stack((student_ID,heights))\n",
        "print(\"Combined Data:\\n\",data)\n",
        "\n",
        "# Sort the data by Height (Coloumn Index 1)\n",
        "# Syntax --> np.argsort(data[:,1])\n",
        "sorted_indices = np.argsort(data[:,1])\n",
        "sorted_data = data[sorted_indices]\n",
        "\n",
        "# Extract sorted student IDs and Heights\n",
        "# Syntax --> sorted_data[:,0]\n",
        "# Syntax --> sorted_data[:,1]\n",
        "sorted_student_ID = sorted_data[:,0]\n",
        "sorted_heights = sorted_data[:,1]\n",
        "\n",
        "# Print the results\n",
        "print(\"Sorted Indices (Based on Height):\",sorted_indices)\n",
        "print(\"Sorted Student IDs:\",sorted_student_ID)\n",
        "print(\"Sorted Student's Heights:\",sorted_heights)"
      ]
    },
    {
      "cell_type": "code",
      "source": [
        "'''Write a NumPy program to sort the Employee ID with increasing Wages of the\n",
        "    Employees from given Employee ID and Wages. Print the integer indices that\n",
        "   describes the sort order by multiple columns and the sorted data.'''\n",
        "\n",
        "# Importing a package\n",
        "# Import package_name as alias name\n",
        "import numpy as np\n",
        "\n",
        "# Creating two array which contains Employee IDs and there respective Wages\n",
        "# arrayname = alias.name.array([v1,v2,v3,..vn])\n",
        "# 1-D array\n",
        "employee_ID = np.array([201, 202, 203, 204, 205])\n",
        "wages = np.array([50000, 60000, 55000, 52000, 58000])\n",
        "\n",
        "# Printing the arrays which contains Employee IDs and there respective Wages\n",
        "print(\"Employee IDs:\", employee_ID)\n",
        "print(\"Employee Wages:\", wages)\n",
        "\n",
        "# Combine the data into a 2-D array\n",
        "data = np.column_stack((employee_ID, wages))\n",
        "print(\"Combined Data:\\n\",data)\n",
        "\n",
        "# Sort the data by Wages (Coloumn Index 1)\n",
        "sorted_indices = np.argsort(data[:,1])\n",
        "sorted_data = data[sorted_indices]\n",
        "\n",
        "# Extract sorted Employee IDs and Wages\n",
        "sorted_employee_ID = sorted_data[:,0]\n",
        "sorted_wages = sorted_data[:,1]\n",
        "\n",
        "# Print the results\n",
        "print(\"Sorted Indices (Based on Wages):\", sorted_indices)\n",
        "print(\"Sorted Employee IDs:\", sorted_employee_ID)\n",
        "print(\"Sorted Employee Wages:\", sorted_wages)"
      ],
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "X965k1MBJJWS",
        "outputId": "e14cac23-4d19-409e-e67d-1e425cd0ce2f"
      },
      "execution_count": 18,
      "outputs": [
        {
          "output_type": "stream",
          "name": "stdout",
          "text": [
            "Employee IDs: [201 202 203 204 205]\n",
            "Employee Wages: [50000 60000 55000 52000 58000]\n",
            "Combined Data:\n",
            " [[  201 50000]\n",
            " [  202 60000]\n",
            " [  203 55000]\n",
            " [  204 52000]\n",
            " [  205 58000]]\n",
            "Sorted Indices (Based on Wages): [0 3 2 4 1]\n",
            "Sorted Employee IDs: [201 204 203 205 202]\n",
            "Sorted Employee Wages: [50000 52000 55000 58000 60000]\n"
          ]
        }
      ]
    },
    {
      "cell_type": "code",
      "source": [
        "'''Write a NumPy program to sort the Book Names with increasing Prices of the\n",
        "   Books from given Book Names and Prices. Print the integer indices that\n",
        "   describes the sort order by multiple columns and the sorted data.'''\n",
        "\n",
        "# Importing a package\n",
        "# Import package_name as alias name\n",
        "import numpy as np\n",
        "\n",
        "# Creating two array which contains Book names and there respective Prices\n",
        "# arrayname = alias.name.array([v1,v2,v3,..vn])\n",
        "# 1-D array\n",
        "book_names = np.array([\"Book A\", \"Book B\", \"Book C\", \"Book D\", \"Book E\"])\n",
        "prices = np.array([250, 150, 300, 200, 180])\n",
        "\n",
        "# Printing the arrays which contains Book names and there respective Prices\n",
        "print(\"Book Names:\", book_names)\n",
        "print(\"Book Prices:\", prices)\n",
        "\n",
        "# Combine the data into a 2-D array\n",
        "data = np.column_stack((book_names, prices))\n",
        "print(\"Combined Data:\\n\", data)\n",
        "\n",
        "# Sort the data by Prices (Coloumn Index 1)\n",
        "sorted_indices = np.argsort(data[:, 1])\n",
        "sorted_data = data[sorted_indices]\n",
        "\n",
        "# Extract sorted Book Names and Prices\n",
        "sorted_book_names = sorted_data[:, 0]\n",
        "sorted_prices = sorted_data[:, 1]\n",
        "\n",
        "# Print the results\n",
        "print(\"Sorted Indices (Based on Prices):\", sorted_indices)\n",
        "print(\"Sorted Book Names:\", sorted_book_names)\n",
        "print(\"Sorted Book Prices:\", sorted_prices)"
      ],
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "oCYB7IjIJllK",
        "outputId": "506a703a-f964-4e6f-e608-fa3486999549"
      },
      "execution_count": 19,
      "outputs": [
        {
          "output_type": "stream",
          "name": "stdout",
          "text": [
            "Book Names: ['Book A' 'Book B' 'Book C' 'Book D' 'Book E']\n",
            "Book Prices: [250 150 300 200 180]\n",
            "Combined Data:\n",
            " [['Book A' '250']\n",
            " ['Book B' '150']\n",
            " ['Book C' '300']\n",
            " ['Book D' '200']\n",
            " ['Book E' '180']]\n",
            "Sorted Indices (Based on Prices): [1 4 3 0 2]\n",
            "Sorted Book Names: ['Book B' 'Book E' 'Book D' 'Book A' 'Book C']\n",
            "Sorted Book Prices: ['150' '180' '200' '250' '300']\n"
          ]
        }
      ]
    },
    {
      "cell_type": "code",
      "source": [
        "'''Write a NumPy program to sort the Product Names with increasing Prices of the\n",
        "   Products from given Product Names and Prices. Print the integer indices that\n",
        "   describes the sort order by multiple columns and the sorted data.'''\n",
        "\n",
        "# Importing a package\n",
        "# Import package_name as alias name\n",
        "import numpy as np\n",
        "\n",
        "# Creating two array which contains Product names and there respective Prices\n",
        "# arrayname = alias.name.array([v1,v2,v3,..vn])\n",
        "# 1-D array\n",
        "product_names = np.array([\"Product A\", \"Product B\", \"Product C\", \"Product D\"])\n",
        "prices = np.array([250, 150, 300, 200])\n",
        "\n",
        "# Printing the arrays which contains Product names and there respective Prices\n",
        "print(\"Product Names:\", product_names)\n",
        "print(\"Product Prices:\", prices)\n",
        "\n",
        "# Combine the data into a 2-D array\n",
        "data = np.column_stack((product_names, prices))\n",
        "print(\"Combined Data:\\n\", data)\n",
        "\n",
        "# Sort the data by Prices (Coloumn Index 1)\n",
        "sorted_indices = np.argsort(data[:, 1])  # Convert prices to float if needed\n",
        "sorted_data = data[sorted_indices]\n",
        "\n",
        "# Extract sorted Product Names and Prices\n",
        "sorted_product_names = sorted_data[:, 0]\n",
        "sorted_prices = sorted_data[:, 1]\n",
        "\n",
        "# Print the results\n",
        "print(\"Sorted Indices (Based on Prices):\", sorted_indices)\n",
        "print(\"Sorted Product Names:\", sorted_product_names)\n",
        "print(\"Sorted Product Prices:\", sorted_prices)"
      ],
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "FJauEqMvK1wQ",
        "outputId": "724a257e-3a9e-4a07-fc01-0171422b8480"
      },
      "execution_count": 15,
      "outputs": [
        {
          "output_type": "stream",
          "name": "stdout",
          "text": [
            "Product Names: ['Product A' 'Product B' 'Product C' 'Product D']\n",
            "Product Prices: [250 150 300 200]\n",
            "Combined Data:\n",
            " [['Product A' '250']\n",
            " ['Product B' '150']\n",
            " ['Product C' '300']\n",
            " ['Product D' '200']]\n",
            "Sorted Indices (Based on Prices): [1 3 0 2]\n",
            "Sorted Product Names: ['Product B' 'Product D' 'Product A' 'Product C']\n",
            "Sorted Product Prices: ['150' '200' '250' '300']\n"
          ]
        }
      ]
    }
  ]
}