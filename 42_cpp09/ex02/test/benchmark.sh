#!/bin/bash

# 実行ファイル名
EXEC=./PmergeMe

# データ数（必要に応じて変更可）
N=3000

# ランダムな整数を生成（1〜10000の間）
args=$(jot -r $N 1 10000 | tr '\n' ' ')

# 実行
echo "Benchmarking with $N random numbers... 🚀"
$EXEC $args
