print("hello world!\n")

###

var = ["a","b","c","d","e"]

for i in range(len(var)):
    print(f"{i} : {var[i]}")
print('\n')  

###

dic = {'fruit1':'apple', 'fruit2':'orange', 'fruit3':'banana'}

for k,v in dic.items():
    print(f'{k} is {v}')
print('\n')
    
###

setNum = {"ai","ai","ai","ai","ai","ml","ml","ml","ml","dl","dl","dl","md"}
# print(len(setNum))

for i,k in enumerate(setNum):
    print(f'{i} = {k}!')
print('\n')

def print_version(v):
    return print(f'{v} is a printing test for version!')

print_version(1.1)
