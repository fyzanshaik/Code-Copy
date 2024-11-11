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
        "**Data Analysis with Python Week 4 Session**"
      ],
      "metadata": {
        "id": "JRp2-oSZugGK"
      }
    },
    {
      "cell_type": "code",
      "execution_count": null,
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "4exm6SWMKAd-",
        "outputId": "6bc2e97e-7dba-4483-c946-8b965ffe1959"
      },
      "outputs": [
        {
          "output_type": "execute_result",
          "data": {
            "text/plain": [
              "array([[1., 0., 0.],\n",
              "       [0., 1., 0.],\n",
              "       [0., 0., 1.]])"
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
        "# arrayname = alaisname.eye(value)\n",
        "# eye() --> Creating an Identity Matrix\n",
        "# Creating an Identiy Matrix Order 3\n",
        "a= np.eye(3)\n",
        "a"
      ]
    },
    {
      "cell_type": "code",
      "source": [
        "# Creating an Identiy Matrix Order 10\n",
        "b= np.eye(10)\n",
        "b"
      ],
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "gpKGykoDzyvz",
        "outputId": "2d165afe-11f8-4f79-d47c-29e1529c5d42"
      },
      "execution_count": null,
      "outputs": [
        {
          "output_type": "execute_result",
          "data": {
            "text/plain": [
              "array([[1., 0., 0., 0., 0., 0., 0., 0., 0., 0.],\n",
              "       [0., 1., 0., 0., 0., 0., 0., 0., 0., 0.],\n",
              "       [0., 0., 1., 0., 0., 0., 0., 0., 0., 0.],\n",
              "       [0., 0., 0., 1., 0., 0., 0., 0., 0., 0.],\n",
              "       [0., 0., 0., 0., 1., 0., 0., 0., 0., 0.],\n",
              "       [0., 0., 0., 0., 0., 1., 0., 0., 0., 0.],\n",
              "       [0., 0., 0., 0., 0., 0., 1., 0., 0., 0.],\n",
              "       [0., 0., 0., 0., 0., 0., 0., 1., 0., 0.],\n",
              "       [0., 0., 0., 0., 0., 0., 0., 0., 1., 0.],\n",
              "       [0., 0., 0., 0., 0., 0., 0., 0., 0., 1.]])"
            ]
          },
          "metadata": {},
          "execution_count": 3
        }
      ]
    },
    {
      "cell_type": "code",
      "source": [
        "# identity() --> Creating an Identity Matrix\n",
        "# arrayname = alaisname.identity(value)\n",
        "# Creating an Identiy Matrix Order 5\n",
        "c= np.identity(5)\n",
        "c"
      ],
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "_CIFjfu4zc0B",
        "outputId": "32d411f9-0b9b-4b9e-fd12-85e38e2c168d"
      },
      "execution_count": null,
      "outputs": [
        {
          "output_type": "execute_result",
          "data": {
            "text/plain": [
              "array([[1., 0., 0., 0., 0.],\n",
              "       [0., 1., 0., 0., 0.],\n",
              "       [0., 0., 1., 0., 0.],\n",
              "       [0., 0., 0., 1., 0.],\n",
              "       [0., 0., 0., 0., 1.]])"
            ]
          },
          "metadata": {},
          "execution_count": 4
        }
      ]
    },
    {
      "cell_type": "code",
      "source": [
        "# Creating an Identiy Matrix Order 8\n",
        "d= np.identity(8)\n",
        "d"
      ],
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "Yef1qA4W0iNL",
        "outputId": "47309ae5-daf6-4e13-b732-9775b8957678"
      },
      "execution_count": null,
      "outputs": [
        {
          "output_type": "execute_result",
          "data": {
            "text/plain": [
              "array([[1., 0., 0., 0., 0., 0., 0., 0.],\n",
              "       [0., 1., 0., 0., 0., 0., 0., 0.],\n",
              "       [0., 0., 1., 0., 0., 0., 0., 0.],\n",
              "       [0., 0., 0., 1., 0., 0., 0., 0.],\n",
              "       [0., 0., 0., 0., 1., 0., 0., 0.],\n",
              "       [0., 0., 0., 0., 0., 1., 0., 0.],\n",
              "       [0., 0., 0., 0., 0., 0., 1., 0.],\n",
              "       [0., 0., 0., 0., 0., 0., 0., 1.]])"
            ]
          },
          "metadata": {},
          "execution_count": 5
        }
      ]
    }
  ]
}