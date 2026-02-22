def solve(n):
    for num in range(1,n+1):
        print(num, end="")
        
if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())
    solve(n)