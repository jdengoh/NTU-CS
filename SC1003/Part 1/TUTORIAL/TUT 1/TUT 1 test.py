boys = (int)(input("number of boys:"))
girls = (int)(input("Number of girls:"))

total = boys + girls

percentage_boys = (boys/total)*100
percentage_girls = (girls/total)

print("Boys:{:2.0f}".format(percentage_boys))
print("Girls:{:10.0%}".format(percentage_girls))

input("Press enter to exit")
