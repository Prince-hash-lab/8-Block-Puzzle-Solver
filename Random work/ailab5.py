import numpy as np
arr1=np.array([1,2,3,4,5,6,7,8])
'''
arr2=arr1.view()
arr3=arr1.copy()
arr2[3]=90
arr3[4]=67
arr1[7]=55667
print(arr2)
print(arr3)
print(arr1)'''
'''
var=lambda x=0,y=100: print(np.linspace(x,y,20))
var()
arr1=np.array([1,2,3,'4',5,6,7,8.45])
# arr2=arr1.astype(int)
print(arr1.dtype)
print(arr1)
'''
'''
arr=np.array([1,2,3,4,5])
for i in arr:
    print(i)
arr1=np.sort([4,2,6,1,8])
print(arr1)
# '''
# a=np.random.randint(10,30,size=(2,6))
# print(a)
# arr2=np.random.choice([0,1,2,3,4],p=(0.4,0.2,0.2,0.1,0.1),size=(2,4))
# print(arr2)
# a=[1,2,3]
# c={"one":1,"two":2}
# d="hello"
# for i , j in c.items():
#     print(i,j)
# it=iter(a)
# print(next(it))
# for i in it:
#     print(i)

# arr2=np.random.choice([0,1],p=(0.5,0.5),size=(2,10))
# print(arr2)
# generators :- next two functions 
import snoop 
@snoop

def fac(x):
    if x==1:
        return 1
    else:
        return (x* fac(x-1))

if __name__=="__main__":
    num=5
    print("fact is ", fac(num))
