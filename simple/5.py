def is_leap(year):
    leap = False
    
    if not year % 4:
        leap = True
    
    if not year % 100:
        leap = False

    if not year % 400:
        leap = True
    
    return leap

year = int(input())
print(is_leap(year))
# years = [1800, 1900, 1990, 2000, 2100, 2200, 2300, 2400, 2500]

# for year in years:
#     print(year, "=", is_leap(year))

