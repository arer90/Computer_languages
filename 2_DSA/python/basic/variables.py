print("hello world!\n")

var = ["a","b","c","d","e"]

for i in range(len(var)):
    print(f"{i} : {var[i]}")
    
dic = {'fruit1':'apple', 'fruit2':'orange', 'fruit3':'banana'}

for k,v in dic.items():
    print(f'{k} is {v}')
    

setNum = {1,2,3,4,5,5,5,6,7,7,8,9,9,9}

print(f'{setNum}')