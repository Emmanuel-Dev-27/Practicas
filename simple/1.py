#!/bin/python3

def solve(n): 
  par = n % 2
  if par == 1 and n < 20:
      print("Weird")
      return
  
  if n > 20:
      print("Not Weird")
      return

  if par == 0 :
      if 2 <= n < 5 :
          print("Not Weird")
          return
      
      if 6 <= n <= 20:
          print("Weird")
          return

if __name__ == '__main__':
    n = int(input().strip())
    solve(n)
    