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
        "**Data Analysis with Python Week 3 Session**"
      ],
      "metadata": {
        "id": "DRt96dYGrCOf"
      }
    },
    {
      "cell_type": "code",
      "execution_count": 6,
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "mQFELFdjq_wr",
        "outputId": "8c8cebc9-0b09-42e2-b674-c4bf5148c115"
      },
      "outputs": [
        {
          "output_type": "stream",
          "name": "stdout",
          "text": [
            "[51 92 14 71 60 20 82 86 74 74]\n"
          ]
        }
      ],
      "source": [
        "# Importing a package\n",
        "# Import package_name as alias name\n",
        "import numpy as np\n",
        "import matplotlib.pyplot as plt\n",
        "# Creating a random number generator\n",
        "# Syntax --> np.random.randomstate(seed_number)\n",
        "rand = np.random.RandomState(42)\n",
        "# Creating a random array of size 10 consisting of numbers between 0 and 100\n",
        "x = rand.randint(100, size=10)\n",
        "print(x)"
      ]
    },
    {
      "cell_type": "code",
      "source": [
        "# Entering the index numbers to print the elements of that particular index\n",
        "# Syntax --> ind = [i1,i2,i3,..in]\n",
        "ind = [3, 7, 2]\n",
        "# Printing the elements of the entered index numbers\n",
        "# Syntax 1 --> arrayname[ind]\n",
        "x[ind]"
      ],
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "SvohZs-B4cBl",
        "outputId": "9d653a93-2ea9-419c-d64b-5529092a734c"
      },
      "execution_count": 9,
      "outputs": [
        {
          "output_type": "stream",
          "name": "stdout",
          "text": [
            "[71, 86, 14]\n"
          ]
        }
      ]
    },
    {
      "cell_type": "code",
      "source": [
        "# Syntax 2 --> print([arrayname[i1],arrayname[i2], ..arrayname[in]])\n",
        "print([x[3], x[7], x[2]])"
      ],
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "kh3cVkS37dRk",
        "outputId": "03797656-d201-4405-cb78-9d11749b62e5"
      },
      "execution_count": 10,
      "outputs": [
        {
          "output_type": "stream",
          "name": "stdout",
          "text": [
            "[71, 86, 14]\n"
          ]
        }
      ]
    },
    {
      "cell_type": "code",
      "source": [
        "# Entering the index numbers in 2-D array format\n",
        "# Syntax --> ind = np.array([[i1, i2], [i3, i4], ..[in-1,in]])\n",
        "ind = np.array([[3, 7], [4, 5]])\n",
        "x[ind]"
      ],
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "nSrNxKbA9QxU",
        "outputId": "4af4a99f-a300-4554-f473-0bde1ca41e7c"
      },
      "execution_count": 13,
      "outputs": [
        {
          "output_type": "execute_result",
          "data": {
            "text/plain": [
              "array([[71, 86],\n",
              "       [60, 20]])"
            ]
          },
          "metadata": {},
          "execution_count": 13
        }
      ]
    },
    {
      "cell_type": "code",
      "source": [
        "'''Creating an array with n random elements between 0 and n-1, and then reshape\n",
        "   it into a matrix with r rows and c columns where n= r*c'''\n",
        "# Syntax --> x = np.arange(n).reshape((r, c))\n",
        "x = np.arange(12).reshape((3, 4))\n",
        "x"
      ],
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "AnL9Fwig_8e9",
        "outputId": "1fd3e154-63f1-4ac0-b1af-2538ad3b3361"
      },
      "execution_count": 19,
      "outputs": [
        {
          "output_type": "execute_result",
          "data": {
            "text/plain": [
              "array([[ 0,  1,  2,  3],\n",
              "       [ 4,  5,  6,  7],\n",
              "       [ 8,  9, 10, 11]])"
            ]
          },
          "metadata": {},
          "execution_count": 19
        }
      ]
    },
    {
      "cell_type": "code",
      "source": [
        "''' Creating a array using fancy indexing i.e first create a row array and a\n",
        "    column array, then use them to index into another array such that each\n",
        "    element corresponds to the matching indices in the row and column array'''\n",
        "row = np.array([0, 1, 2])\n",
        "col = np.array([2, 1, 3])\n",
        "X[row, col]"
      ],
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "l7Mhx_J1JDdj",
        "outputId": "e6f24d2f-5ee5-44ee-8f15-5c5b0b3a9116"
      },
      "execution_count": 21,
      "outputs": [
        {
          "output_type": "execute_result",
          "data": {
            "text/plain": [
              "array([ 2,  5, 11])"
            ]
          },
          "metadata": {},
          "execution_count": 21
        }
      ]
    },
    {
      "cell_type": "code",
      "source": [
        "'''Creating an array using advanced indexing i.e reshapes the row indices into a\n",
        "   column and pairs them with the column indices to access specific elements\n",
        "   from the array, creating a grid-like retrieval pattern'''\n",
        "# Syntax --> arrayname[row_arrayname[:, np.newaxis], coloumn_arrayname]\n",
        "X[row[:, np.newaxis], col]"
      ],
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "Nnr5JTWXNw2-",
        "outputId": "da1acf6c-7b83-4d0b-e5b8-8e9bca910b1c"
      },
      "execution_count": 22,
      "outputs": [
        {
          "output_type": "execute_result",
          "data": {
            "text/plain": [
              "array([[ 2,  1,  3],\n",
              "       [ 6,  5,  7],\n",
              "       [10,  9, 11]])"
            ]
          },
          "metadata": {},
          "execution_count": 22
        }
      ]
    },
    {
      "cell_type": "code",
      "source": [
        "'''Creating an array by indexing one specific row number with entered\n",
        "   coloumn numbers'''\n",
        "# Syntax --> arrayname[row_number, [c1, c2, ...cn]]\n",
        "X[2, [2, 0, 1]]"
      ],
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "NBsT7DdKT7_6",
        "outputId": "69bfc71d-5052-4f93-d0e8-0eb2ccc2b7a2"
      },
      "execution_count": 23,
      "outputs": [
        {
          "output_type": "execute_result",
          "data": {
            "text/plain": [
              "array([10,  8,  9])"
            ]
          },
          "metadata": {},
          "execution_count": 23
        }
      ]
    },
    {
      "cell_type": "code",
      "source": [
        "'''Creating an array by indexing from specific row number till the last row\n",
        "   number with entered coloumn numbers'''\n",
        "# Syntax --> arrayname[row_number:, [c1, c2, ...cn]]\n",
        "X[1:, [2, 0, 1]]"
      ],
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "1DuVANNTVKg2",
        "outputId": "63aaaef5-7998-46b5-d241-4046851ab069"
      },
      "execution_count": 26,
      "outputs": [
        {
          "output_type": "execute_result",
          "data": {
            "text/plain": [
              "array([[ 6,  4,  5],\n",
              "       [10,  8,  9]])"
            ]
          },
          "metadata": {},
          "execution_count": 26
        }
      ]
    },
    {
      "cell_type": "code",
      "source": [
        "# Importing a package\n",
        "# Import package_name as alias name\n",
        "import numpy as np\n",
        "# Creating a random number generator\n",
        "# Syntax --> np.random.randomstate(seed_number)\n",
        "rand = np.random.RandomState(42)\n",
        "print(rand)\n",
        "#  Setting the mean vector of the distribution\n",
        "mean = [0, 0]\n",
        "# Defining a covariance 2-D array\n",
        "cov = [[1, 2],\n",
        "       [2, 5]]\n",
        "'''Generating n number of samples from a multivariate normal distribution with\n",
        "   the specified mean and covariance'''\n",
        "# Syntax --> X = rand.multivariate_normal(mean, covariance, n)\n",
        "X = rand.multivariate_normal(mean, cov, 100)\n",
        "# Printing the shape of the multivariate normal distribution array\n",
        "print(X.shape)"
      ],
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "vpzWGmtpVzGf",
        "outputId": "30dcb6e9-2aa0-4051-afb4-13629077a1d7"
      },
      "execution_count": 30,
      "outputs": [
        {
          "output_type": "stream",
          "name": "stdout",
          "text": [
            "RandomState(MT19937)\n",
            "(100, 2)\n"
          ]
        }
      ]
    },
    {
      "cell_type": "code",
      "source": [
        "'''Randomly selecting n number of unique indices from the range of X's first\n",
        "   dimension without repetition'''\n",
        "# Syntax --> indices = np.random.choice(X.shape[0], n, replace=False)\n",
        "indices = np.random.choice(X.shape[0], 20, replace=False)\n",
        "print(indices)\n",
        "'''Creating a array using fancy indexing i.e selecting the rows of X\n",
        "   corresponding to the chosen indices'''\n",
        "selection = X[indices]\n",
        "# Printing the shape of the resulting selection array\n",
        "print(selection.shape)"
      ],
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "eHWtDPcHauo4",
        "outputId": "65a98dab-f9e1-4195-abfd-67714cac38c3"
      },
      "execution_count": 35,
      "outputs": [
        {
          "output_type": "stream",
          "name": "stdout",
          "text": [
            "[39 34  4 81 77  5 69 41 93 15 71 96 36 49 98  3 87 31 67 59]\n",
            "(20, 2)\n"
          ]
        }
      ]
    },
    {
      "cell_type": "code",
      "source": [
        "'''From the multivariate normal distribution array scatter plotting where all\n",
        "   data points are plotted with semi-transparency'''\n",
        "# Syntax --> plt.scatter(x, y, alpha=0.5)\n",
        "'''Where:\n",
        "   x: Data for the x-axis. X[:, 0] means \"all rows, first column\" of array X\n",
        "   y: Data for the y-axis. X[:, 1] means \"all rows, second column\" of array X\n",
        "   alpha=0.5: Sets the transparency of the points to 50%'''\n",
        "plt.scatter(X[:, 0], X[:, 1], alpha=0.5)\n",
        "'''From the multivariate normal distribution array scatter plotting the selected\n",
        "   20 points are highlighted in larger, red markers'''\n",
        "# Syntax --> plt.scatter(x, y, facecolor='r', s=150);\n",
        "'''Where:\n",
        "   x: Data for the x-axis\n",
        "   selection[:, 0] means \"all rows, first column\" of selection\n",
        "   y: Data for the y-axis\n",
        "   selection[:, 1] means \"all rows, second column\" of selection\n",
        "   facecolor='r': Sets the face color of the points to red\n",
        "   s=150: Sets the size of the points'''\n",
        "plt.scatter(selection[:, 0], selection[:, 1], facecolor='r', s=150);"
      ],
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/",
          "height": 430
        },
        "id": "X9qm1CxWc4pb",
        "outputId": "a391e25f-b7b0-4225-b6c4-848c30d25305"
      },
      "execution_count": 45,
      "outputs": [
        {
          "output_type": "display_data",
          "data": {
            "text/plain": [
              "<Figure size 640x480 with 1 Axes>"
            ],
            "image/png": "iVBORw0KGgoAAAANSUhEUgAAAiIAAAGdCAYAAAAvwBgXAAAAOXRFWHRTb2Z0d2FyZQBNYXRwbG90bGliIHZlcnNpb24zLjcuMSwgaHR0cHM6Ly9tYXRwbG90bGliLm9yZy/bCgiHAAAACXBIWXMAAA9hAAAPYQGoP6dpAABRHklEQVR4nO3deXxb5Zk3/N85Wm1LluPETpzEJotdaEkgrHkCM0l4oEmGlkIXugxtSdoJhQmdQjAtmXkfllmaFhLo004/bPM06bzThdK3QJNpgDQ0ztsMUNZpHEiwA8bGju0kjiVZstZzP38c5HiRZC3n6BxJv+/nY7AtHek+lp1z6b6v+7okIYQAERERkQFkowdARERE5YuBCBERERmGgQgREREZhoEIERERGYaBCBERERmGgQgREREZhoEIERERGYaBCBERERnGavQA0lEUBX19fXC73ZAkyejhEBERUQaEEPD7/Zg7dy5kOf2ch6kDkb6+PjQ2Nho9DCIiIspBT08P5s+fn/Y+pg5E3G43APVEqqurDR4NERERZcLn86GxsXHsOp6OqQORxHJMdXU1AxEiIqIik0laBZNViYiIyDAMRIiIiMgwDESIiIjIMAxEiIiIyDAMRIiIiMgwDESIiIjIMAxEiIiIyDAMRIiIiMgwugYivb29+PKXv4yZM2eioqICS5cuxauvvqrnUxIREVEGFEWgZyiII/0+9AwFoSjCkHHoVln19OnTuPzyy3HFFVdgz549qKurQ0dHB2bMmKHXUxIREVEGOgf9eK59AMdOjCAUi8NptWBxnQtrl8xGc/30Zdm1pFsg8v3vfx+NjY3YsWPH2PcWLlyo19MRERFRBjoH/dhxsAtDgQgaPE5U2isQjMTQ3udFn3cUGy5fUNBgRLelmd/+9re4+OKLcf3116O+vh4XXHABHn/8cb2ejoiIiKahKALPtQ9gKBBBS70LbqcNFlmC22lDS70LQ4EInj88UNBlGt0CkXfffRcPP/wwWlpa8Nxzz+GWW27B3/3d3+GnP/1pymPC4TB8Pt+EDyIiItJG7/Aojp0YQYPHOaUhnSRJaPA40Tk4gt7h0YKNSbdARFEUXHjhhfjud7+LCy64ADfddBM2btyIRx55JOUxW7duhcfjGftobGzUa3hERERlJxCJIRSLo9KePDOjwm5BOBZHIBIr2Jh0C0QaGhrwsY99bML3PvrRj6K7uzvlMVu2bIHX6x376Onp0Wt4REREZafKboXTakEwRaAxGonDYbWgKkWgogfdnunyyy/H0aNHJ3zvnXfewVlnnZXyGIfDAYfDodeQiIiIytq8mgosrnOhvc8Ll8M6YXlGCIHj3hCWzvNgXk1Fwcak24zI7bffjpdeegnf/e530dnZiZ///Od47LHHsGnTJr2ekoiIiNKQZQlrl8xGbZUdHYMj8IeiiCkK/KEoOgZHUFtlx5pzZ0OWpekfTCOSEEK31Njdu3djy5Yt6OjowMKFC7F582Zs3Lgx4+N9Ph88Hg+8Xi+qq6v1GiYREVFZGV9HJBxTl2Oa611Yc642dUSyuX7rGojki4EIERGRPhRFoHd4FIFIDFV2K+bVVGg2E5LN9btw2ShERERkGrIsobG20uhhsOkdERERGYeBCBERERmGgQgREREZhoEIERERGYaBCBERERmGgQgREREZhoEIERERGYaBCBERERmGgQgREREZhoEIERERGYaBCBERERmGgQgREREZhoEIERERGYaBCBERERmGgQgREREZhoEIERERGYaBCBERERmGgQgREREZhoEIERERGYaBCBERERmGgQgREREZhoEIERERGYaBCBERERmGgQgREREZhoEIERERGYaBCBERERmGgQgREREZhoEIERERGYaBCBERERmGgQgREREZhoEIERERGYaBCBERERmGgQgREREZhoEIERERGYaBCBERERmGgQgREREZhoEIERERGYaBCBERERmGgQgREREZhoEIERERGYaBCBERERmGgQgREREZhoEIERERGYaBCBERERmGgQgREREZxmr0AIiIiEqdogj0Do8iEImhym7FvJoKyLJk9LBMgYEIERGRjjoH/XiufQDHTowgFIvDabVgcZ0La5fMRnO92+jhGY6BCBERkU46B/3YcbALQ4EIGjxOVNorEIzE0N7nRZ93FBsuX1D2wQhzRIiIiHSgKALPtQ9gKBBBS70LbqcNFlmC22lDS70LQ4EInj88AEURRg/VUAxEiIiIdNA7PIpjJ0bQ4HFCkibmg0iShAaPE52DI+gdHjVohObAQISIiEgHgUgMoVgclfbkWRAVdgvCsTgCkViBR2YuDESIiIh0UGW3wmm1IJgi0BiNxOGwWlCVIlApFwxEiIiIdDCvpgKL61w47g1BiIl5IEII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l3/5F1x22WWorKxETU1NRsesX78ekiRN+Fi3bp2+A81RLucnhMDdd9+NhoYGVFRU4KqrrkJHR4e+A83R0NAQbrjhBlRXV6OmpgZf//rXMTIykvaY1atXT3n9br755gKNeHo//vGPsWDBAjidTixfvhx/+tOf0t7/ySefxDnnnAOn04mlS5fid7/7XYFGmptszm/nzp1TXiun01nA0WbnwIEDuOaaazB37lxIkoSnn3562mP279+PCy+8EA6HA83Nzdi5c6fu48xVtue3f//+Ka+fJEno7+8vzICztHXrVlxyySVwu92or6/Hddddh6NHj057nNn/Bos6EDly5AgURcGjjz6Kw4cP46GHHsIjjzyCv//7v0973O23345du3bhySefRFtbG/r6+vCZz3ymQKPOTiQSwfXXX49bbrklq+PWrVuH48ePj3384he/0GmE+cnl/O6//3788Ic/xCOPPIKXX34ZVVVVWLt2LUKhkI4jzc0NN9yAw4cPY+/evdi9ezcOHDiAm266adrjNm7cOOH1u//++wsw2uk98cQT2Lx5M+655x68/vrrOP/887F27VoMDg4mvf9//dd/4Utf+hK+/vWv44033sB1112H6667Du3t7QUeeWayPT9ArWA5/rV6//33Czji7AQCAZx//vn48Y9/nNH933vvPXziE5/AFVdcgTfffBO33XYb/uZv/gbPPfecziPNTbbnl3D06NEJr2F9fb1OI8xPW1sbNm3ahJdeegl79+5FNBrFmjVrEAgEUh5TFH+DosTcf//9YuHChSlvHx4eFjabTTz55JNj33v77bcFAPHiiy8WYog52bFjh/B4PBnd98YbbxTXXnutruPRWqbnpyiKmDNnjnjggQfGvjc8PCwcDof4xS9+oeMIs/fWW28JAOKVV14Z+96ePXuEJEmit7c35XGrVq0S3/rWtwowwuxdeumlYtOmTWNfx+NxMXfuXLF169ak9//85z8vPvGJT0z43vLly8U3vvENXceZq2zPL5u/S7MBIJ566qm09/n2t78tzj333Anf+8IXviDWrl2r48i0kcn5/eEPfxAAxOnTpwsyJq0NDg4KAKKtrS3lfYrhb7CoZ0SS8Xq9qK2tTXn7a6+9hmg0iquuumrse+eccw6amprw4osvFmKIBbF//37U19fj7LPPxi233IJTp04ZPSRNvPfee+jv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\n"
          },
          "metadata": {}
        }
      ]
    }
  ]
}