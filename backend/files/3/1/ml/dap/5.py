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
        "**Data Analysis with Python Week 5 Session**"
      ],
      "metadata": {
        "id": "lz0fOrot4CMJ"
      }
    },
    {
      "cell_type": "code",
      "execution_count": null,
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "bnHTIPM32u1B",
        "outputId": "1961ab69-3eab-460a-97bc-742376586591"
      },
      "outputs": [
        {
          "output_type": "execute_result",
          "data": {
            "text/plain": [
              "array([ 1.  ,  3.25,  5.5 ,  7.75, 10.  ])"
            ]
          },
          "metadata": {},
          "execution_count": 2
        }
      ],
      "source": [
        "# Importing a package\n",
        "# Import package_name as alias name\n",
        "import numpy as np\n",
        "#arrayname = aliasname.linespace(start,stop,num=value)\n",
        "a = np.linspace(1,10,num=5)\n",
        "a"
      ]
    },
    {
      "cell_type": "code",
      "source": [
        "# Creating a vector of length 10 with values evenly distributed between 5 and 50\n",
        "b = np.linspace(5,50,num=10)\n",
        "b"
      ],
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/"
        },
        "id": "bxhOepTlX9yW",
        "outputId": "58983cb0-865f-4cea-ca3f-f2477d0a44fd"
      },
      "execution_count": null,
      "outputs": [
        {
          "output_type": "execute_result",
          "data": {
            "text/plain": [
              "array([ 5., 10., 15., 20., 25., 30., 35., 40., 45., 50.])"
            ]
          },
          "metadata": {},
          "execution_count": 9
        }
      ]
    }
  ]
}