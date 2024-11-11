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
        "**Data Analysis with Python Week 2 Session**"
      ],
      "metadata": {
        "id": "8JIUlaCo4FId"
      }
    },
    {
      "cell_type": "code",
      "execution_count": null,
      "metadata": {
        "id": "YurfZQIf1MOQ",
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "outputId": "c222142d-95d8-4853-eed4-164f33cf6a8a"
      },
      "outputs": [
        {
          "output_type": "stream",
          "name": "stdout",
          "text": [
            "[1 2 3 4 5]\n",
            "[ True  True False False False]\n",
            "[ True  True False False False]\n",
            "[ True  True  True False False]\n",
            "[ True  True  True False False]\n",
            "[False False False False  True]\n",
            "[False False False False  True]\n",
            "[False False False  True  True]\n",
            "[False False False  True  True]\n",
            "[False False  True False False]\n",
            "[False False  True False False]\n",
            "[ True  True  True False  True]\n",
            "[ True  True  True False  True]\n"
          ]
        }
      ],
      "source": [
        "# Importing a package\n",
        "# Import package_name as alias name\n",
        "import numpy as np\n",
        "# Create an array\n",
        "# arrayname = alias.name.array([v1,v2,v3,..vn])\n",
        "# 1-D array\n",
        "a= np.array([1,2,3,4,5])\n",
        "print(a)\n",
        "# Comparisions --> <,<=,>,>=,==,!=\n",
        "# aliasname.comparision(array_1,array_2)\n",
        "# Less Than Operator\n",
        "print(np.less(a,3))\n",
        "print(a<3)\n",
        "# Less Than and Equal to Operator\n",
        "print(np.less_equal(a,3))\n",
        "print(a<=3)\n",
        "# Greater Than Operator\n",
        "print(np.greater(a,4))\n",
        "print(a>4)\n",
        "# Greater Than and Equal to Operator\n",
        "print(np.greater_equal(a,4))\n",
        "print(a>=4)\n",
        "# Equal To Operator\n",
        "print(np.equal(a,3))\n",
        "print(a==3)\n",
        "# Not Equal To Operator\n",
        "print(np.not_equal(a,4))\n",
        "print(a!=4)"
      ]
    },
    {
      "cell_type": "code",
      "source": [
        "# Boolean Logic Operators --> and(&),or(|),not(~)\n",
        "b= np.array([1,2,3,4,5])\n",
        "print(b)\n",
        "# Logical AND Operator\n",
        "print(np.logical_and(a,b))\n",
        "print(a & b)\n",
        "c= (a<b)&(a>b)\n",
        "c\n",
        "# Logical OR Operator\n",
        "print(np.logical_or(a,b))\n",
        "print(a | b)\n",
        "d= (a<b)|(a>b)\n",
        "d\n",
        "# Logical NOT Operator\n",
        "print(np.logical_not(a))\n",
        "print(~a)"
      ],
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "jfVmMqyD4Bfq",
        "outputId": "e3017712-e49e-4831-b1b3-b5cce7cf51eb"
      },
      "execution_count": null,
      "outputs": [
        {
          "output_type": "stream",
          "name": "stdout",
          "text": [
            "[1 2 3 4 5]\n",
            "[ True  True  True  True  True]\n",
            "[1 2 3 4 5]\n",
            "[ True  True  True  True  True]\n",
            "[1 2 3 4 5]\n",
            "[False False False False False]\n",
            "[-2 -3 -4 -5 -6]\n"
          ]
        }
      ]
    },
    {
      "cell_type": "code",
      "source": [
        "# Importing a package\n",
        "# Import package_name as alias name\n",
        "import numpy as np\n",
        "# Create an array\n",
        "# arrayname = alias.name.array([v1,v2,v3,..vn])\n",
        "# 1-D array\n",
        "a= np.array([1,2,3,4,5])\n",
        "# Masking --> Manipulation of the array to remove the unwanted array elements\n",
        "print(a[a<5])\n",
        "print(a+3)\n",
        "print(a*3)"
      ],
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "1s72IIMV2H51",
        "outputId": "aa6912a4-0232-41fb-e349-26e8fb3a09ce"
      },
      "execution_count": 1,
      "outputs": [
        {
          "output_type": "stream",
          "name": "stdout",
          "text": [
            "[1 2 3 4]\n",
            "[4 5 6 7 8]\n",
            "[ 3  6  9 12 15]\n"
          ]
        }
      ]
    },
    {
      "cell_type": "code",
      "source": [
        "import numpy as np\n",
        "import pandas as pd\n",
        "data = pd.read_csv(r\"/content/Student_Marks.csv\")\n",
        "Marks = np.array(data['Marks'])\n",
        "print(Marks)\n",
        "# Comparisons\n",
        "print(\"\\nMarks less than 50:\", np.less(marks, 50))\n",
        "print(\"Marks less than or equal to 50:\", np.less_equal(marks, 50))\n",
        "print(\"Marks greater than 70:\", np.greater(marks, 70))\n",
        "print(\"Marks greater than or equal to 75:\", np.greater_equal(marks, 75))\n",
        "print(\"Marks equal to 72:\", np.equal(marks, 72))\n",
        "print(\"Marks not equal to 51:\", np.not_equal(marks, 51))\n",
        "\n",
        "# Boolean Logic Operations\n",
        "pass_marks = np.array([50] * len(marks))\n",
        "print(\"\\nLogical AND (Marks and pass marks):\", np.logical_and(marks, pass_marks))\n",
        "print(\"Logical OR (Marks or pass marks):\", np.logical_or(marks, pass_marks))\n",
        "print(\"Logical NOT (Marks):\", np.logical_not(marks))\n",
        "\n",
        "# Masking\n",
        "print(\"\\nMarks less than 50 (masked):\", marks[marks < 50])\n",
        "print(\"Marks greater than 70 (masked):\", marks[marks > 70])\n",
        "\n",
        "# Operations on the dataset\n",
        "print(\"\\nMarks + 5:\", marks + 5)\n",
        "print(\"Marks * 2:\", marks * 2)"
      ],
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "TR9pKTcn2duD",
        "outputId": "00f59b0e-05dd-4478-f863-6d388b952030"
      },
      "execution_count": null,
      "outputs": [
        {
          "output_type": "stream",
          "name": "stdout",
          "text": [
            "[19.202  7.734 13.811 53.018 55.299 17.822 29.889 17.264 20.348 30.862\n",
            " 42.036 12.132 24.318 17.672 11.397 19.466 30.548 38.49  50.986 25.133\n",
            " 22.073 35.939 12.209 28.043 16.517  6.623 12.647 26.532  9.333  8.837\n",
            " 24.172  8.1   15.038 39.965 17.171 43.978 13.119 46.453 41.358 51.142\n",
            "  7.336 15.725 19.771 10.429  9.742  8.924 16.703 22.701 26.882 19.106\n",
            " 40.602 22.184  7.892 36.653 53.158 18.238 53.359 51.583 31.236 51.343\n",
            " 10.522 10.844 19.59  21.379 12.591 13.562 27.569  6.185  8.92  21.4\n",
            " 16.606 13.416 20.398  7.014 39.952  6.217 36.746 38.278 49.544  6.349\n",
            " 54.321 17.705 44.099 16.106 16.461 39.957 23.149  6.053 11.253 40.024\n",
            " 24.394 19.564 23.916 42.426 24.451 19.128  5.609 41.444 12.027 32.357]\n",
            "\n",
            "Marks less than 50: [ True False False False  True False False  True False False]\n",
            "Marks less than or equal to 50: [ True False False False  True False False  True False False]\n",
            "Marks greater than 70: [False  True  True False False False  True False  True  True]\n",
            "Marks greater than or equal to 75: [False False  True False False False  True False  True  True]\n",
            "Marks equal to 72: [False  True False False False False False False False False]\n",
            "Marks not equal to 51: [ True  True  True False  True  True  True  True  True  True]\n",
            "\n",
            "Logical AND (Marks and pass marks): [ True  True  True  True  True  True  True  True  True  True]\n",
            "Logical OR (Marks or pass marks): [ True  True  True  True  True  True  True  True  True  True]\n",
            "Logical NOT (Marks): [False False False False False False False False False False]\n",
            "\n",
            "Marks less than 50 (masked): [45 33 48]\n",
            "Marks greater than 70 (masked): [72 88 90 75 84]\n",
            "\n",
            "Marks + 5: [50 77 93 56 38 72 95 53 80 89]\n",
            "Marks * 2: [ 90 144 176 102  66 134 180  96 150 168]\n"
          ]
        }
      ]
    }
  ]
}