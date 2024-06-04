import random    



teile = ["1", "2", "3"]
for i in range(0, int(input("Wie Viele Teile? > "))):
    teil = random.choice(teile)
    print(teil)
    teile.remove(teil)