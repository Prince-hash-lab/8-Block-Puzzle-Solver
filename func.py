# # ans 8 (a)
# class restaurant():
#     def __init__(self,rest_name,cuis_type):
#         self.rest_name=rest_name
#         self.cuis_type=cuis_type
#     def des_rest(self):
#         print(" restaurant name is ",self.rest_name)
#         print(" cuisine type  is ",self.cuis_type)
#     def open_rest(self):
#         print("restaurant is open ")
# rest=restaurant('motel 5 star ','Dal Makani')

# rest.des_rest()
# rest.open_rest()
# print(rest.rest_name)
# def fun(pa,itr,time):
#     return pa*(1+(itr*time))

class Solution:
    def getMinDiff(self, arr, n, k):
        # code here
        if n==1:
            return 0
        arr.sort()
        small=arr[0]+k
        big=arr[n-1]-k
        if small>big:
            small,big=big,small
        i=1
        while i<n-1:
            sub=arr[i]-k
            add=arr[i]+k
            if sub>=small or add<=big:
                continue
            if big-sub<=add-small:
                small=sub
            else:
                big=add
        return big-small
    
if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        k = int(input())
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.getMinDiff(arr, n, k)
        print(ans)
        tc -= 1