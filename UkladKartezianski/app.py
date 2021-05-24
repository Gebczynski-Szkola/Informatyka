
def bubbleSort(pointsArr, ilosc):

    for i in range(ilosc):
        for j in range(0, ilosc-i-1):
            if pointsArr[j][2] > pointsArr[j+1][2]:
                pointsArr[j], pointsArr[j+1] = pointsArr[j+1], pointsArr[j]
    print('Wspolrzedne po sortowaniu: \n', pointsArr)


with open('punkty.txt', encoding='utf8') as tekst:
    ilosc = tekst.readline()
    ilosc = int(ilosc)
    lines = []
    pointsArr = []

    for x in range(ilosc):
        lines.append(tekst.readline().replace(
            "\t", "|").replace("\n", ""))
        pointsArr.append(lines[x].split("|"))

i = 0

for x in range(ilosc):
    for y in range(2):
        pointsArr[x][y] = int(pointsArr[x][y])

    pointsArr[x].append(float(round(pointsArr[x][i]/pointsArr[x][i+1], 4)))

print('Wspolrzedne przed sortowaniem: \n', pointsArr)
bubbleSort(pointsArr, ilosc)
