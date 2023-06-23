def reverser(a_str):
   if len(a_str) == 1:	# base case
      return a_str

   else:				# recursive step
      new_str = reverser(a_str[1:])+ a_str[0]
      return new_str        

##def reverseAndRepeat(a_str, num):
##
##    
##
##
##def reverseAndOppositeCase(a_str):
##    
##
##
##
##
##def symmetricString(a_str):
##    


myStr = "ABC"
str0 = reverser(myStr)
print(str0)             # CBA


##str1 = reverseAndRepeat(myStr, 2)
##str2 = reverseAndRepeat(myStr, 3)
##print(str1)		# CCBBAA
##print(str2)		# CCCBBBAAA

##reversedOppCaseStr = reverseAndOppositeCase(myStr)
##print("reversed and opposite case: ", reversedOppCaseStr) #cba

##symmetricStr = symmetricString(myStr)
##print("symmetric string: ", symmetricStr)                 #ABCCBA



