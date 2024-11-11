{
  "cells": [
    {
      "cell_type": "markdown",
      "source": [
        "**Data Analysis with Python Week 10 Session**"
      ],
      "metadata": {
        "id": "KF3vdXVtZJ_d"
      },
      "id": "KF3vdXVtZJ_d"
    },
    {
      "cell_type": "code",
      "execution_count": null,
      "id": "6d94bfa5",
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "6d94bfa5",
        "outputId": "fb9205cf-8df2-45a7-cb20-0801069de904"
      },
      "outputs": [
        {
          "output_type": "execute_result",
          "data": {
            "text/plain": [
              "array([[1, 2, 3],\n",
              "       [4, 5, 6],\n",
              "       [6, 7, 8]])"
            ]
          },
          "metadata": {},
          "execution_count": 1
        }
      ],
      "source": [
        "# Importing a package\n",
        "# Import package_name as alias name\n",
        "import numpy as np\n",
        "# Create an 2-D array\n",
        "# arrayname=aliasname.array([[d1][d2]])\n",
        "a=np.array([[1,2,3],[4,5,6],[6,7,8]])\n",
        "a"
      ]
    },
    {
      "cell_type": "code",
      "source": [
        "# Swapping the rows of a given array in reverse order\n",
        "# Syntax --> reversed_arrayname = arrayname[::-1,::]\n",
        "b=a[::-1,::]\n",
        "b"
      ],
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "ftY5hIG3b1ON",
        "outputId": "ed50640e-b16d-47dd-9a6c-ff66e48f35a3"
      },
      "id": "ftY5hIG3b1ON",
      "execution_count": null,
      "outputs": [
        {
          "output_type": "execute_result",
          "data": {
            "text/plain": [
              "array([[6, 7, 8],\n",
              "       [4, 5, 6],\n",
              "       [1, 2, 3]])"
            ]
          },
          "metadata": {},
          "execution_count": 6
        }
      ]
    },
    {
      "cell_type": "code",
      "source": [
        "# Swapping the coloumns of a given array in reverse order\n",
        "# Syntax --> reversed_arrayname = arrayname[:,::-1]\n",
        "c=a[:,::-1]\n",
        "c"
      ],
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "zvH0S4K5b22e",
        "outputId": "34dc85d7-81cb-4ab2-9d18-79f046cde4ef"
      },
      "id": "zvH0S4K5b22e",
      "execution_count": null,
      "outputs": [
        {
          "output_type": "execute_result",
          "data": {
            "text/plain": [
              "array([[3, 2, 1],\n",
              "       [6, 5, 4],\n",
              "       [8, 7, 6]])"
            ]
          },
          "metadata": {},
          "execution_count": 7
        }
      ]
    },
    {
      "cell_type": "code",
      "execution_count": null,
      "id": "89fcd0a9",
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "89fcd0a9",
        "outputId": "d80b6dfd-aaa4-4804-f568-f80982d32b43"
      },
      "outputs": [
        {
          "output_type": "execute_result",
          "data": {
            "text/plain": [
              "array([[8, 7, 6],\n",
              "       [6, 5, 4],\n",
              "       [3, 2, 1]])"
            ]
          },
          "metadata": {},
          "execution_count": 2
        }
      ],
      "source": [
        "# Swapping both rows and coloumns of a given array in reverse order\n",
        "# Syntax --> reversed_arrayname = arrayname[::-1,::-1]\n",
        "d=a[::-1,::-1]\n",
        "d"
      ]
    }
  ],
  "metadata": {
    "kernelspec": {
      "display_name": "Python 3 (ipykernel)",
      "language": "python",
      "name": "python3"
    },
    "language_info": {
      "codemirror_mode": {
        "name": "ipython",
        "version": 3
      },
      "file_extension": ".py",
      "mimetype": "text/x-python",
      "name": "python",
      "nbconvert_exporter": "python",
      "pygments_lexer": "ipython3",
      "version": "3.11.5"
    },
    "colab": {
      "provenance": []
    }
  },
  "nbformat": 4,
  "nbformat_minor": 5
}