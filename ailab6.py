# class abc:
#     _var=5   #var  is public for private use  __ double underscore 
#     def display(self):
#         print( self._var)
# obj1=abc()
# print(obj1._var)
# obj1.display()

# class abc:
#    
#     def input(self,var):
#         self.var1=var
#     def display(self):
#         print( self.var1)
# obj1=abc()
# obj1.input(10)
# obj1.display()


# class abc:
#     __var=5   #var here is private
#     def __update(self):
#         self.var=abc.__var
#         self.var+=5
#         print(" Var =",self.var)
#         self.display()  #calling within the function 
#         abc.display(self)  #same as above line 
#     def display(self):
#         self.var=abc.__var
#         print("var value: ",self.var)
# obj1=abc()
# obj1.display()
# # obj1.__update()  will not work 
# obj1._abc__update()

# obj1.display()


# init method 


# class abc:
#     __var=5   #var here is private
#     var2=2      #class variable  run only one time 
#     print('yes',var2)

#     def __init__(self,var3):
#         # to create new variable var 3 for object 
#         print(" automatic intialization ")
#         self.var2=var3
        
#         print(" the value2 is ",self.var2)

#     def __update(self):
#         self.var=abc.__var
#         self.var+=5
#         abc.var2+=50
#         print(" Var =",self.var)
#         print(" Var2 =",abc.var2)
#         self.display()  #calling within the function 
#         abc.display(self)  #same as above line 

#     def display(self):
#         self.var=abc.__var
#         print("var value: ",self.var)
#         print("var2 for object value: ",self.var2)
#     print("var2 for class :",var2)   # will run at class defination only one time

# obj1=abc(34)
# obj1.display()
# # obj1.__update()  will not work 
# obj1._abc__update()
# obj1.display()
# print(abc.var2)
# print(obj1.var2)



# class abc:
   
#     var2=5  #class variable  run only one time 
#     def __init__(self,var1):
#         # to create new variable var 3 for object 
#         print(" automatic intialization ")
#         abc.var2+=var1
#         self.var2+=var1
#         print(" class var2 is ",abc.var2)
#         print(" the value2 is ",self.var2)
#     def __del__(self):
#         abc.var2=5
#         print(' del called')
# obj=abc(10)
# obj1=abc(10)
# obj2=abc(10)
# # see how value is changing 
# '''  OUTPUT HERE
#  automatic intialization 
#  class var2 is  15
#  the value2 is  25
#  automatic intialization
#  class var2 is  25
#  the value2 is  35
#  automatic intialization
#  class var2 is  35
#  the value2 is  45
#  del called
#  del called
#  del called
# '''

# class display():
#     even=[]
#     odd=[]
#     def __init__(self,num):
#         self.num=num
#         if num%2==0:
#             display.even.append(num)   #same as self.even
#         else : 
#             self.odd.append(num)  #same as display.odd  can be any of these 
# obj1=display(5)
# obj2=display(20)
# obj3=display(3)
# obj4=display(22)
# print(display.even)
# print(display.odd)
# '''
# [20, 22]
# [5, 3]

# # '''

# class person:
#     def __init__(self,name,age):
#         self.name=name
#         self.age=age
#     def display(self):
#         print(' name = ',self.name)
#         print("age= ",self.age)
# class teacher:                          #teacher(student)  will also work but this is also correct
#     def __init__(self,name,age,expr,subj):
#         person.__init__(self,name,age)
#         self.expr=expr
#         self.subj=subj
#     def display(self):
#         person.display(self)
#         print(self.expr)
#         print(self.subj)
# class std(person):
#     def __init__(self,name,age,marks,branch):
#         # person.__init__(self,name,age)
#         # same as above line 
#         super().__init__(name,age)    
#         self.marks=marks
#         self.branch=branch
#     def displayd(self):
#         person.display(self)
#         print("marks ",self.marks)
#         print("marks ",self.branch)
# th=teacher("prince",45,45,"maths and scinece")
# th.display()
# st=std("prince",47,100,"CSE")
# st.displayd()




# class base1:
#     def __init__(self):
#         print("base1 ")

# class base2:
#     def __init__(self):
#         print("base2 ")
# class derived(base1,base2):
#     # def __init__(self):
#         print("derived ")
# d=derived()
# print(derived.__bases__) 
# after finding first init it will stop 

# '''  derived 
# base1  '''

class base1:
    def __init__(self):
        super().__init__()
        print("base1 ")

class base2:
    def __init__(self):
        super().__init__()
        print("base2 ")
class derived(base1,base2):
     def __init__(self):
        super().__init__()  #go to next base class every time you print
        print("derived ")
d=derived()